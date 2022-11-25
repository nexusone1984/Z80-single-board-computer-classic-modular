SECTION code_driver
SECTION code_driver_terminal_output

PUBLIC term_01_output_char_oterm_msg_printc
EXTERN _mybuffer
term_01_output_char_oterm_msg_printc:

;   * OTERM_MSG_PRINTC
;
;     enter  :  c = ascii code
;               b = 255 if not supplied by iterm (safely ignore)
;               l = absolute x coordinate
;               h = absolute y coordinate
;     can use:  af, bc, de, hl, af'
;
;     Print the char to screen at given character coordinate.

ld a,h
ld b,l
ld hl, 0x0000
ld de, 0x0020
and a,a 
jp Z, no_mult
mult_y:
add hl, de
dec a
jp NZ, mult_y
no_mult:
ld e, b
add hl, de
ld a, 0x46 ; command that Character data is being sent
out (0x61), a
ld a, l
out (0x60), a
ld a, h
out (0x60), a
ld a, 0x42 ; command that Character data is being sent
out (0x61), a
ld a, c
out (0x60), a
ex de, hl
ld  hl, _mybuffer  ; load base address
add hl, de ; add Character address offset.
ld (hl), c ;  write Character to buffer 
ret

