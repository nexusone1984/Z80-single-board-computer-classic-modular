;	fputc_cons
;

	PUBLIC  fputc_cons_native

.fputc_cons_native

	ld      a,(hl)
	out     (0x60),a
	ret
