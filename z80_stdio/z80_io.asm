; Z80 low level I/O write routines 
; sdcc compiler ix

SECTION code_user

PUBLIC _z80_io_write
PUBLIC _z80_io_read

; write to Z80 IO port
; c call z80_io_write( unsigned char port, unsigned char data)

_z80_io_write:
	push	ix
	ld	ix,0
	add	ix,sp
	ld	c,(ix+4)
	ld	a,(ix+5)
	out (c) ,a
	pop	ix
	ret
	
; read from Z80 IO port
; c call z80_io_read( unsigned char port)
_z80_io_read:
	push	ix
	ld	ix,0
	add	ix,sp
	ld	c,(ix+4)
	in a, (c)
	ld l, a
	pop	ix
	ret 

	
