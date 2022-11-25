SECTION code_driver
SECTION code_driver_terminal_output

PUBLIC term_01_output_char_oterm_msg_scroll
EXTERN _mybuffer
term_01_output_char_oterm_msg_scroll:

;   * OTERM_MSG_SCROLL
;
;     enter  :   c = number of rows to scroll
;     can use:  af, bc, de, hl
;
;     Scroll the window upward 'c' character rows.
;
; A pointer to a rectangle covering the terminal screen
; can be retrieved with this code:
;
;   ld hl,16
;   call l_offset_ix_de         ; hl = window.rect *
;
; hl+0 = & window.x
; hl+1 = & window.width
; hl+2 = & window.y
; hl+3 = & window.height

ld hl, _scroll_count
ld (hl),c
scroll_start:
ld bc, 0x0020
ld de, _mybuffer ;
ld hl, _mybuffer
add hl, bc
ld bc, 0x01e0
ldir
ld hl, _mybuffer
ld bc, 0x0020
ld de, 0x01e0
add hl, de
fill_space:
ld a, 0x20
ld (hl),a
inc hl
dec bc
ld a, b
or c
jp NZ, fill_space
ld de, 0x0000
ld bc, 0x0200
ld hl,_mybuffer
send_buffer:
ld a, 0x46 ; command that Character data address is being sent
out (0x61), a
ld a,e
out (0x60), a
ld a,d
out (0x60), a
ld a, 0x42 ; command that Character data is being sent
out (0x61), a
ld a, (hl)
out (0x60), a
inc hl
inc de
dec bc
ld a, b
or c
jp NZ, send_buffer
ld hl, _scroll_count
dec (HL)
jp NZ, scroll_start
ret
;scroll_end:
SECTION bss_user
 
_scroll_count:  defs 1

