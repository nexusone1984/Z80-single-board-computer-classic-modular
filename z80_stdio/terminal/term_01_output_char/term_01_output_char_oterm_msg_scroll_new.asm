SECTION code_driver
SECTION code_driver_terminal_output

PUBLIC term_01_output_char_oterm_msg_scroll

EXTERN _mybuffer
EXTERN term_01_output_char_oterm_msg_cls

term_01_output_char_oterm_msg_scroll:

;   * OTERM_MSG_SCROLL
;
;     enter  :   c = number of rows to scroll
;     can use:  af, bc, de, hl
;
;     Scroll the window upward 'c' character rows.

; At this point:
;
; ix+16 = window.x
; ix+17 = window.width
; ix+18 = window.y
; ix+19 = window.height
;
; Note that for an SDCC_IY compile, ix and iy have been swapped.

   ld a,c                      ; a = scroll_amount

IF __SDCC_IY
   cp (iy+19)
ELSE
   cp (ix+19)                  ; compare with max height of terminal
ENDIF
   jp nc, term_01_output_char_oterm_msg_cls

   add a,a
   add a,a
   add a,a
   add a,a                     ; max 16*(lcd_height-1=15) = 240
   ld l,a
   ld h,0
   add hl,hl
   ex de,hl                    ; de = 32 * scroll_amount

IF __SDCC_IY
   ld a,(iy+18)
   add a,(iy+19)
ELSE
   ld a,(ix+18)                ; window.y
   add a,(ix+19)               ; + window.height
ENDIF
   sub c                       ; - scroll_amount
   add a,a
   add a,a
   add a,a
   add a,a                     ; max 16*(lcd_height-1=15) = 240
   ld b,a
   ld hl,_mybuffer
   add a,l
   ld l,a
   adc a,h
   sub l
   ld h,a
   ld a,b
IF __SDCC_IY
   add a,(iy+16)
ELSE
   add a,(ix+16)               ; + window.x
ENDIF
   add a,l
   ld l,a
   adc a,h
   sub l
   ld h,a                      ; hl = mybuffer + (window.y + window.height
                               ;          - scroll_amount)*32 + window.x

   push hl
   
   xor a
   sbc hl,de
   ex de,hl
   
   pop hl
   
   ld a,32
IF __SDCC_IY
   sub (iy+17)
ELSE
   sub (ix+17)                 ; - window.width
ENDIF
   ld b,a
   ld a,c                      ; a = scroll_amount
   ld c,b
   ld b,0                      ; bc = 32 - window.width
   
   ;  a = scroll_amount
   ; bc = 32 - window.width
   ; hl = mybuffer + (window.y + window.height - scroll_amount)*32 + window.x  (source)
   ; de = hl - scroll_amount*32  (destination)
   
loop_y:

   push bc
IF __SDCC_IY
   ld c,(iy+17)
ELSE
   ld c,(ix+17)                ; bc = window.width
ENDIF

loop_x:

   ldi                         ; copy one byte
   dec hl
   ld (hl),32                  ; print space at source byte
   inc hl
   jp pe, loop_x
   
   pop bc                      ; bc = 32 - window.width
   
   ex de,hl
   add hl,bc                   ; adjust downward one row
   
   ex de,hl
   add hl,bc                   ; adjust downward one row
   
   dec a                       ; scroll_amount--
   jr nz, loop_y
   
   ; now output buffer to the lcd
ld bc, 0x0200
ld de, 0x0000
ld hl,_mybuffer
send_buffer:
ld a, 0x46 ; command that Character data address is being sent
out (0x21), a
ld a,e
out (0x20), a
ld a,d
out (0x20), a
ld a, 0x42 ; command that Character data is being sent
out (0x21), a
ld a, (hl)
out (0x20), a
inc hl
inc de
dec bc
ld a, b
or c
jp NZ, send_buffer
ret
