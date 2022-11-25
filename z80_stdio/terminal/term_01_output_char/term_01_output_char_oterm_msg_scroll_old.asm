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

;ld a, c
;or c
;jp Z, scroll_end
;ld bc, 0x0020
;ld de, _mybuffer ;
;ld hl, _mybuffer
;add hl, bc
;ld bc, 0x01e0
;ldir
;ld hl, _mybuffer
;ld bc, 0x0020
;ld de, 0x01e0
;add hl, de
;fill_space:
;ld a, 0x20
;ld (hl),a
;inc hl
;dec bc
;ld a, b
;or c
;jp NZ, fill_space
;ld a, 0x4d ; shift mode for display 4c = right, 4d = left
;out (0x21), a
;ld a, 0x46 ; command that Character data address is being sent
;out (0x21), a
;ld a, 0x00
;out (0x20), a
;out (0x20), a
;ld a, 0x42 ; command that Character data is being sent
;out (0x21), a
;ld bc, 0x0020
;ld hl, _mybuffer ;
;otir
;otir

;scroll_end:

