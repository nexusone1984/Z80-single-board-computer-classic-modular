PUBLIC _lcd_scroll
EXTERN _mybuffer

SECTION code_compiler

_lcd_scroll:
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
ld a, 0x4c ; shift mode for display 4c = right, 4d = left
out (0x61), a
ld a, 0x46 ; command that Character data address is being sent
out (0x61), a
ld a, 0x00
out (0x60), a
out (0x60), a
ld a, 0x42 ; command that Character data is being sent
out (0x61), a
ld bc, 0x0020
ld hl, _mybuffer ;
otir
otir
