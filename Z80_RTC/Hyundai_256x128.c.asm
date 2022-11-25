;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.5 #9840 (Linux)
;--------------------------------------------------------
; Processed by Z88DK
;--------------------------------------------------------
	
	EXTERN __divschar
	EXTERN __divschar_callee
	EXTERN __divsint
	EXTERN __divsint_callee
	EXTERN __divslong
	EXTERN __divslong_callee
	EXTERN __divslonglong
	EXTERN __divslonglong_callee
	EXTERN __divsuchar
	EXTERN __divsuchar_callee
	EXTERN __divuchar
	EXTERN __divuchar_callee
	EXTERN __divuint
	EXTERN __divuint_callee
	EXTERN __divulong
	EXTERN __divulong_callee
	EXTERN __divulonglong
	EXTERN __divulonglong_callee
	EXTERN __divuschar
	EXTERN __divuschar_callee
	EXTERN __modschar
	EXTERN __modschar_callee
	EXTERN __modsint
	EXTERN __modsint_callee
	EXTERN __modslong
	EXTERN __modslong_callee
	EXTERN __modslonglong
	EXTERN __modslonglong_callee
	EXTERN __modsuchar
	EXTERN __modsuchar_callee
	EXTERN __moduchar
	EXTERN __moduchar_callee
	EXTERN __moduint
	EXTERN __moduint_callee
	EXTERN __modulong
	EXTERN __modulong_callee
	EXTERN __modulonglong
	EXTERN __modulonglong_callee
	EXTERN __moduschar
	EXTERN __moduschar_callee
	EXTERN __mulint
	EXTERN __mulint_callee
	EXTERN __mullong
	EXTERN __mullong_callee
	EXTERN __mullonglong
	EXTERN __mullonglong_callee
	EXTERN __mulschar
	EXTERN __mulschar_callee
	EXTERN __mulsuchar
	EXTERN __mulsuchar_callee
	EXTERN __muluschar
	EXTERN __muluschar_callee
	EXTERN __rlslonglong
	EXTERN __rlslonglong_callee
	EXTERN __rlulonglong
	EXTERN __rlulonglong_callee
	EXTERN __rrslonglong
	EXTERN __rrslonglong_callee
	EXTERN __rrulonglong
	EXTERN __rrulonglong_callee
	EXTERN ___sdcc_call_hl
	EXTERN ___sdcc_call_iy
	EXTERN ___sdcc_enter_ix
	EXTERN _banked_call
	EXTERN _banked_ret
	EXTERN ___fs2schar
	EXTERN ___fs2schar_callee
	EXTERN ___fs2sint
	EXTERN ___fs2sint_callee
	EXTERN ___fs2slong
	EXTERN ___fs2slong_callee
	EXTERN ___fs2slonglong
	EXTERN ___fs2slonglong_callee
	EXTERN ___fs2uchar
	EXTERN ___fs2uchar_callee
	EXTERN ___fs2uint
	EXTERN ___fs2uint_callee
	EXTERN ___fs2ulong
	EXTERN ___fs2ulong_callee
	EXTERN ___fs2ulonglong
	EXTERN ___fs2ulonglong_callee
	EXTERN ___fsadd
	EXTERN ___fsadd_callee
	EXTERN ___fsdiv
	EXTERN ___fsdiv_callee
	EXTERN ___fseq
	EXTERN ___fseq_callee
	EXTERN ___fsgt
	EXTERN ___fsgt_callee
	EXTERN ___fslt
	EXTERN ___fslt_callee
	EXTERN ___fsmul
	EXTERN ___fsmul_callee
	EXTERN ___fsneq
	EXTERN ___fsneq_callee
	EXTERN ___fssub
	EXTERN ___fssub_callee
	EXTERN ___schar2fs
	EXTERN ___schar2fs_callee
	EXTERN ___sint2fs
	EXTERN ___sint2fs_callee
	EXTERN ___slong2fs
	EXTERN ___slong2fs_callee
	EXTERN ___slonglong2fs
	EXTERN ___slonglong2fs_callee
	EXTERN ___uchar2fs
	EXTERN ___uchar2fs_callee
	EXTERN ___uint2fs
	EXTERN ___uint2fs_callee
	EXTERN ___ulong2fs
	EXTERN ___ulong2fs_callee
	EXTERN ___ulonglong2fs
	EXTERN ___ulonglong2fs_callee
	EXTERN ____sdcc_2_copy_src_mhl_dst_deix
	EXTERN ____sdcc_2_copy_src_mhl_dst_bcix
	EXTERN ____sdcc_4_copy_src_mhl_dst_deix
	EXTERN ____sdcc_4_copy_src_mhl_dst_bcix
	EXTERN ____sdcc_4_copy_src_mhl_dst_mbc
	EXTERN ____sdcc_4_ldi_nosave_bc
	EXTERN ____sdcc_4_ldi_save_bc
	EXTERN ____sdcc_4_push_hlix
	EXTERN ____sdcc_4_push_mhl
	EXTERN ____sdcc_lib_setmem_hl
	EXTERN ____sdcc_ll_add_de_bc_hl
	EXTERN ____sdcc_ll_add_de_bc_hlix
	EXTERN ____sdcc_ll_add_de_hlix_bc
	EXTERN ____sdcc_ll_add_de_hlix_bcix
	EXTERN ____sdcc_ll_add_deix_bc_hl
	EXTERN ____sdcc_ll_add_deix_hlix
	EXTERN ____sdcc_ll_add_hlix_bc_deix
	EXTERN ____sdcc_ll_add_hlix_deix_bc
	EXTERN ____sdcc_ll_add_hlix_deix_bcix
	EXTERN ____sdcc_ll_asr_hlix_a
	EXTERN ____sdcc_ll_asr_mbc_a
	EXTERN ____sdcc_ll_copy_src_de_dst_hlix
	EXTERN ____sdcc_ll_copy_src_de_dst_hlsp
	EXTERN ____sdcc_ll_copy_src_deix_dst_hl
	EXTERN ____sdcc_ll_copy_src_deix_dst_hlix
	EXTERN ____sdcc_ll_copy_src_deixm_dst_hlsp
	EXTERN ____sdcc_ll_copy_src_desp_dst_hlsp
	EXTERN ____sdcc_ll_copy_src_hl_dst_de
	EXTERN ____sdcc_ll_copy_src_hlsp_dst_de
	EXTERN ____sdcc_ll_copy_src_hlsp_dst_deixm
	EXTERN ____sdcc_ll_lsl_hlix_a
	EXTERN ____sdcc_ll_lsl_mbc_a
	EXTERN ____sdcc_ll_lsr_hlix_a
	EXTERN ____sdcc_ll_lsr_mbc_a
	EXTERN ____sdcc_ll_push_hlix
	EXTERN ____sdcc_ll_push_mhl
	EXTERN ____sdcc_ll_sub_de_bc_hl
	EXTERN ____sdcc_ll_sub_de_bc_hlix
	EXTERN ____sdcc_ll_sub_de_hlix_bc
	EXTERN ____sdcc_ll_sub_de_hlix_bcix
	EXTERN ____sdcc_ll_sub_deix_bc_hl
	EXTERN ____sdcc_ll_sub_deix_hlix
	EXTERN ____sdcc_ll_sub_hlix_bc_deix
	EXTERN ____sdcc_ll_sub_hlix_deix_bc
	EXTERN ____sdcc_ll_sub_hlix_deix_bcix
	EXTERN ____sdcc_load_debc_deix
	EXTERN ____sdcc_load_dehl_deix
	EXTERN ____sdcc_load_debc_mhl
	EXTERN ____sdcc_load_hlde_mhl
	EXTERN ____sdcc_store_dehl_bcix
	EXTERN ____sdcc_store_debc_hlix
	EXTERN ____sdcc_store_debc_mhl
	EXTERN ____sdcc_cpu_pop_ei
	EXTERN ____sdcc_cpu_pop_ei_jp
	EXTERN ____sdcc_cpu_push_di
	EXTERN ____sdcc_outi
	EXTERN ____sdcc_outi_128
	EXTERN ____sdcc_outi_256
	EXTERN ____sdcc_ldi
	EXTERN ____sdcc_ldi_128
	EXTERN ____sdcc_ldi_256
	EXTERN ____sdcc_4_copy_srcd_hlix_dst_deix
	EXTERN ____sdcc_4_and_src_mbc_mhl_dst_deix
	EXTERN ____sdcc_4_or_src_mbc_mhl_dst_deix
	EXTERN ____sdcc_4_xor_src_mbc_mhl_dst_deix
	EXTERN ____sdcc_4_or_src_dehl_dst_bcix
	EXTERN ____sdcc_4_xor_src_dehl_dst_bcix
	EXTERN ____sdcc_4_and_src_dehl_dst_bcix
	EXTERN ____sdcc_4_xor_src_mbc_mhl_dst_debc
	EXTERN ____sdcc_4_or_src_mbc_mhl_dst_debc
	EXTERN ____sdcc_4_and_src_mbc_mhl_dst_debc
	EXTERN ____sdcc_4_cpl_src_mhl_dst_debc
	EXTERN ____sdcc_4_xor_src_debc_mhl_dst_debc
	EXTERN ____sdcc_4_or_src_debc_mhl_dst_debc
	EXTERN ____sdcc_4_and_src_debc_mhl_dst_debc
	EXTERN ____sdcc_4_and_src_debc_hlix_dst_debc
	EXTERN ____sdcc_4_or_src_debc_hlix_dst_debc
	EXTERN ____sdcc_4_xor_src_debc_hlix_dst_debc
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	GLOBAL _LCD_write_cmd
	GLOBAL _LCD_write
	GLOBAL _LCD_read_data
	GLOBAL _LCD_read_flag
	GLOBAL _LCD_clear
	GLOBAL _LCD_graphics_clear
	GLOBAL _LCD_print_char
	GLOBAL _LCD_print
	GLOBAL _LCD_set_cursor
	GLOBAL _LCD_set_graphics_cursor
	GLOBAL _LCD_pixel
	GLOBAL _LCD_draw_line
;--------------------------------------------------------
; Externals used
;--------------------------------------------------------
	GLOBAL _ulltoa_callee
	GLOBAL _ulltoa
	GLOBAL _strtoull_callee
	GLOBAL _strtoull
	GLOBAL _strtoll_callee
	GLOBAL _strtoll
	GLOBAL _lltoa_callee
	GLOBAL _lltoa
	GLOBAL _llabs_callee
	GLOBAL _llabs
	GLOBAL __lldivu__callee
	GLOBAL __lldivu_
	GLOBAL __lldiv__callee
	GLOBAL __lldiv_
	GLOBAL _atoll_callee
	GLOBAL _atoll
	GLOBAL _realloc_unlocked_callee
	GLOBAL _realloc_unlocked
	GLOBAL _malloc_unlocked_fastcall
	GLOBAL _malloc_unlocked
	GLOBAL _free_unlocked_fastcall
	GLOBAL _free_unlocked
	GLOBAL _calloc_unlocked_callee
	GLOBAL _calloc_unlocked
	GLOBAL _aligned_alloc_unlocked_callee
	GLOBAL _aligned_alloc_unlocked
	GLOBAL _realloc_callee
	GLOBAL _realloc
	GLOBAL _malloc_fastcall
	GLOBAL _malloc
	GLOBAL _free_fastcall
	GLOBAL _free
	GLOBAL _calloc_callee
	GLOBAL _calloc
	GLOBAL _aligned_alloc_callee
	GLOBAL _aligned_alloc
	GLOBAL _utoa_callee
	GLOBAL _utoa
	GLOBAL _ultoa_callee
	GLOBAL _ultoa
	GLOBAL _system_fastcall
	GLOBAL _system
	GLOBAL _strtoul_callee
	GLOBAL _strtoul
	GLOBAL _strtol_callee
	GLOBAL _strtol
	GLOBAL _strtof_callee
	GLOBAL _strtof
	GLOBAL _strtod_callee
	GLOBAL _strtod
	GLOBAL _srand_fastcall
	GLOBAL _srand
	GLOBAL _rand
	GLOBAL _quick_exit_fastcall
	GLOBAL _quick_exit
	GLOBAL _qsort_callee
	GLOBAL _qsort
	GLOBAL _ltoa_callee
	GLOBAL _ltoa
	GLOBAL _labs_fastcall
	GLOBAL _labs
	GLOBAL _itoa_callee
	GLOBAL _itoa
	GLOBAL _ftoh_callee
	GLOBAL _ftoh
	GLOBAL _ftog_callee
	GLOBAL _ftog
	GLOBAL _ftoe_callee
	GLOBAL _ftoe
	GLOBAL _ftoa_callee
	GLOBAL _ftoa
	GLOBAL _exit_fastcall
	GLOBAL _exit
	GLOBAL _dtoh_callee
	GLOBAL _dtoh
	GLOBAL _dtog_callee
	GLOBAL _dtog
	GLOBAL _dtoe_callee
	GLOBAL _dtoe
	GLOBAL _dtoa_callee
	GLOBAL _dtoa
	GLOBAL _bsearch_callee
	GLOBAL _bsearch
	GLOBAL _atol_fastcall
	GLOBAL _atol
	GLOBAL _atoi_fastcall
	GLOBAL _atoi
	GLOBAL _atof_fastcall
	GLOBAL _atof
	GLOBAL _atexit_fastcall
	GLOBAL _atexit
	GLOBAL _at_quick_exit_fastcall
	GLOBAL _at_quick_exit
	GLOBAL _abs_fastcall
	GLOBAL _abs
	GLOBAL _abort
	GLOBAL __strtou__callee
	GLOBAL __strtou_
	GLOBAL __strtoi__callee
	GLOBAL __strtoi_
	GLOBAL __random_uniform_xor_8__fastcall
	GLOBAL __random_uniform_xor_8_
	GLOBAL __random_uniform_xor_32__fastcall
	GLOBAL __random_uniform_xor_32_
	GLOBAL __random_uniform_cmwc_8__fastcall
	GLOBAL __random_uniform_cmwc_8_
	GLOBAL __shellsort__callee
	GLOBAL __shellsort_
	GLOBAL __quicksort__callee
	GLOBAL __quicksort_
	GLOBAL __insertion_sort__callee
	GLOBAL __insertion_sort_
	GLOBAL __ldivu__callee
	GLOBAL __ldivu_
	GLOBAL __ldiv__callee
	GLOBAL __ldiv_
	GLOBAL __divu__callee
	GLOBAL __divu_
	GLOBAL __div__callee
	GLOBAL __div_
	GLOBAL _z80_otdr_callee
	GLOBAL _z80_otdr
	GLOBAL _z80_otir_callee
	GLOBAL _z80_otir
	GLOBAL _z80_outp_callee
	GLOBAL _z80_outp
	GLOBAL _z80_indr_callee
	GLOBAL _z80_indr
	GLOBAL _z80_inir_callee
	GLOBAL _z80_inir
	GLOBAL _z80_inp_fastcall
	GLOBAL _z80_inp
	GLOBAL _z80_set_int_state_fastcall
	GLOBAL _z80_set_int_state
	GLOBAL _z80_get_int_state
	GLOBAL _z80_delay_tstate_fastcall
	GLOBAL _z80_delay_tstate
	GLOBAL _z80_delay_ms_fastcall
	GLOBAL _z80_delay_ms
	GLOBAL _im2_remove_generic_callback_callee
	GLOBAL _im2_remove_generic_callback
	GLOBAL _im2_prepend_generic_callback_callee
	GLOBAL _im2_prepend_generic_callback
	GLOBAL _im2_append_generic_callback_callee
	GLOBAL _im2_append_generic_callback
	GLOBAL _im2_create_generic_isr_8080_callee
	GLOBAL _im2_create_generic_isr_8080
	GLOBAL _im2_create_generic_isr_callee
	GLOBAL _im2_create_generic_isr
	GLOBAL _im2_install_isr_callee
	GLOBAL _im2_install_isr
	GLOBAL _im2_init_fastcall
	GLOBAL _im2_init
	GLOBAL _z80_pio_read_bit
	GLOBAL _z80_pio_write_bit
	GLOBAL _z80_io_read
	GLOBAL _z80_io_write
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
defc _Z80PIOA	=	0x0000
defc _Z80PIOB	=	0x0001
defc _Z80PIOA_REG	=	0x0002
defc _Z80PIOB_REG	=	0x0003
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	SECTION bss_compiler
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	
IF 0
	
; .area _INITIALIZED removed by z88dk
	
	
ENDIF
	
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	SECTION IGNORE
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	SECTION code_crt_init
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	SECTION IGNORE
;--------------------------------------------------------
; code
;--------------------------------------------------------
	SECTION code_compiler
;Hyundai_256x128.c:14: void LCD_write_cmd( unsigned char a )
;	---------------------------------
; Function LCD_write_cmd
; ---------------------------------
_LCD_write_cmd:
	push	ix
	ld	ix,0
	add	ix,sp
;Hyundai_256x128.c:23: z80_outp( 0x61, a); //LCD address ;
	ld	a,(ix+4)
	push	af
	inc	sp
	ld	hl,0x0061
	push	hl
	call	_z80_outp_callee
	pop	ix
	ret
	SECTION code_compiler
;Hyundai_256x128.c:27: void LCD_write( unsigned char a ) 
;	---------------------------------
; Function LCD_write
; ---------------------------------
_LCD_write:
	push	ix
	ld	ix,0
	add	ix,sp
;Hyundai_256x128.c:36: z80_outp( 0x60, a );   //  LCD address;
	ld	a,(ix+4)
	push	af
	inc	sp
	ld	hl,0x0060
	push	hl
	call	_z80_outp_callee
	pop	ix
	ret
	SECTION code_compiler
;Hyundai_256x128.c:40: unsigned char LCD_read_data( void ) 
;	---------------------------------
; Function LCD_read_data
; ---------------------------------
_LCD_read_data:
;Hyundai_256x128.c:48: LCD_write_cmd( 0x43 );
	ld	a,0x43
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
;Hyundai_256x128.c:49: a = z80_inp(0x61);  // LCD address ;
	ld	hl,0x0061
;Hyundai_256x128.c:52: return a;
	jp  _z80_inp_fastcall
	SECTION code_compiler
;Hyundai_256x128.c:55: unsigned char LCD_read_flag( void ) 
;	---------------------------------
; Function LCD_read_flag
; ---------------------------------
_LCD_read_flag:
;Hyundai_256x128.c:64: a = z80_inp(0x60);  // LCD address ;
	ld	hl,0x0060
;Hyundai_256x128.c:66: return a;
	jp  _z80_inp_fastcall
	SECTION code_compiler
;Hyundai_256x128.c:71: void LCD_clear(void)
;	---------------------------------
; Function LCD_clear
; ---------------------------------
_LCD_clear:
;Hyundai_256x128.c:75: LCD_write_cmd(0x46); // set the cursor addr
	ld	a,0x46
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
;Hyundai_256x128.c:76: LCD_write(0x00);
	xor	a, a
	push	af
	inc	sp
	call	_LCD_write
	inc	sp
;Hyundai_256x128.c:77: LCD_write(0x00);
	xor	a, a
	push	af
	inc	sp
	call	_LCD_write
	inc	sp
;Hyundai_256x128.c:78: LCD_write_cmd(0x4c);
	ld	a,0x4c
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
;Hyundai_256x128.c:79: LCD_write_cmd(0x42);
	ld	a,0x42
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
;Hyundai_256x128.c:81: for (i=0; i<1024; i++)
	ld	bc,0x0000
l_LCD_clear_00102:
;Hyundai_256x128.c:83: LCD_write(0x20); // write blank spaces
	push	bc
	ld	a,0x20
	push	af
	inc	sp
	call	_LCD_write
	inc	sp
	pop	bc
;Hyundai_256x128.c:81: for (i=0; i<1024; i++)
	inc	bc
	ld	a,b
	xor	a,0x80
	sub	a,0x84
	jr	C,l_LCD_clear_00102
;Hyundai_256x128.c:86: LCD_write_cmd(0x46);
	ld	a,0x46
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
;Hyundai_256x128.c:87: LCD_write(0x00);
	xor	a, a
	push	af
	inc	sp
	call	_LCD_write
	inc	sp
;Hyundai_256x128.c:88: LCD_write(0x00);
	xor	a, a
	push	af
	inc	sp
	call	_LCD_write
	inc	sp
	ret
	SECTION code_compiler
;Hyundai_256x128.c:91: void LCD_graphics_clear(void)
;	---------------------------------
; Function LCD_graphics_clear
; ---------------------------------
_LCD_graphics_clear:
;Hyundai_256x128.c:95: LCD_write_cmd(0x46); // set the cursor addr
	ld	a,0x46
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
;Hyundai_256x128.c:96: LCD_write(0xb0);
	ld	a,0xb0
	push	af
	inc	sp
	call	_LCD_write
	inc	sp
;Hyundai_256x128.c:97: LCD_write(0x04);
	ld	a,0x04
	push	af
	inc	sp
	call	_LCD_write
	inc	sp
;Hyundai_256x128.c:98: LCD_write_cmd(0x4c);
	ld	a,0x4c
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
;Hyundai_256x128.c:99: LCD_write_cmd(0x42);
	ld	a,0x42
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
;Hyundai_256x128.c:101: for (i=0; i<0x1000; i++)
	ld	bc,0x0000
l_LCD_graphics_clear_00102:
;Hyundai_256x128.c:103: LCD_write(0x00); // write blank spaces
	push	bc
	xor	a, a
	push	af
	inc	sp
	call	_LCD_write
	inc	sp
	pop	bc
;Hyundai_256x128.c:101: for (i=0; i<0x1000; i++)
	inc	bc
	ld	a,b
	xor	a,0x80
	sub	a,0x90
	jr	C,l_LCD_graphics_clear_00102
;Hyundai_256x128.c:106: LCD_write_cmd(0x46);
	ld	a,0x46
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
;Hyundai_256x128.c:107: LCD_write(0x00);
	xor	a, a
	push	af
	inc	sp
	call	_LCD_write
	inc	sp
;Hyundai_256x128.c:108: LCD_write(0x00);
	xor	a, a
	push	af
	inc	sp
	call	_LCD_write
	inc	sp
	ret
	SECTION code_compiler
;Hyundai_256x128.c:111: void LCD_print_char( char a ) 
;	---------------------------------
; Function LCD_print_char
; ---------------------------------
_LCD_print_char:
	push	ix
	ld	ix,0
	add	ix,sp
;Hyundai_256x128.c:114: LCD_write_cmd(0x42);  
	ld	a,0x42
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
;Hyundai_256x128.c:115: LCD_write( a );
	ld	a,(ix+4)
	push	af
	inc	sp
	call	_LCD_write
	inc	sp
	pop	ix
	ret
	SECTION code_compiler
;Hyundai_256x128.c:121: void LCD_print( char *ptr ) 
;	---------------------------------
; Function LCD_print
; ---------------------------------
_LCD_print:
	push	ix
	ld	ix,0
	add	ix,sp
;Hyundai_256x128.c:124: LCD_write_cmd(0x42);  
	ld	a,0x42
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
;Hyundai_256x128.c:125: while ( *ptr != '\0' )
	ld	c,(ix+4)
	ld	b,(ix+5)
l_LCD_print_00101:
	ld	a,(bc)
	or	a, a
	jr	Z,l_LCD_print_00104
;Hyundai_256x128.c:127: LCD_write( *ptr++ );
	ld	d,a
	inc	bc
	push	bc
	push	de
	inc	sp
	call	_LCD_write
	inc	sp
	pop	bc
	jr	l_LCD_print_00101
l_LCD_print_00104:
	pop	ix
	ret
	SECTION code_compiler
;Hyundai_256x128.c:132: void LCD_set_cursor(char col, char row)
;	---------------------------------
; Function LCD_set_cursor
; ---------------------------------
_LCD_set_cursor:
	push	ix
	ld	ix,0
	add	ix,sp
;Hyundai_256x128.c:140: t_add = row * 32 + col;
	ld	l,(ix+5)
	ld	h,0x00
	add	hl,hl
	add	hl,hl
	add	hl,hl
	add	hl,hl
	add	hl,hl
	ld	e,(ix+4)
	ld	d,0x00
	add	hl,de
;Hyundai_256x128.c:141: lowadd = t_add & 0x00ff;
	ld	c,l
;Hyundai_256x128.c:142: hiadd = t_add >> 8;
	ld	e, h
	ld	a,e
	rlc	a
	sbc	a, a
	ld	b,e
;Hyundai_256x128.c:144: LCD_write_cmd(0x46); // Set cursor address
	push	bc
	ld	a,0x46
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
	pop	bc
;Hyundai_256x128.c:145: LCD_write(lowadd);
	push	bc
	ld	a,c
	push	af
	inc	sp
	call	_LCD_write
	pop	bc
	call	_LCD_write
	inc	sp
	pop	ix
	ret
	SECTION code_compiler
;Hyundai_256x128.c:150: void LCD_set_graphics_cursor(char col, char row)
;	---------------------------------
; Function LCD_set_graphics_cursor
; ---------------------------------
_LCD_set_graphics_cursor:
	push	ix
	ld	ix,0
	add	ix,sp
;Hyundai_256x128.c:158: t_add = (row * 32 + col) + 0x04b0;
	ld	l,(ix+5)
	ld	h,0x00
	add	hl,hl
	add	hl,hl
	add	hl,hl
	add	hl,hl
	add	hl,hl
	ld	e,(ix+4)
	ld	d,0x00
	add	hl,de
	ld	bc,0x04b0
	add	hl,bc
;Hyundai_256x128.c:159: lowadd = t_add & 0x00ff;
	ld	c,l
;Hyundai_256x128.c:160: hiadd = t_add >> 8;
	ld	e, h
	ld	a,e
	rlc	a
	sbc	a, a
	ld	b,e
;Hyundai_256x128.c:162: LCD_write_cmd(0x46); // Set cursor address
	push	bc
	ld	a,0x46
	push	af
	inc	sp
	call	_LCD_write_cmd
	inc	sp
	pop	bc
;Hyundai_256x128.c:163: LCD_write(lowadd);
	push	bc
	ld	a,c
	push	af
	inc	sp
	call	_LCD_write
	pop	bc
	call	_LCD_write
	inc	sp
	pop	ix
	ret
	SECTION code_compiler
;Hyundai_256x128.c:169: void LCD_pixel(int x, int y, char bit)
;	---------------------------------
; Function LCD_pixel
; ---------------------------------
_LCD_pixel:
	push	ix
	ld	ix,0
	add	ix,sp
	push	af
;Hyundai_256x128.c:173: col = x >> 3;
	ld	c,(ix+5)
	ld	a,(ix+4)
	sra	c
	rra
	sra	c
	rra
	sra	c
	rra
	ld	d,a
;Hyundai_256x128.c:174: row = y;
	ld	e,(ix+6)
;Hyundai_256x128.c:175: LCD_set_graphics_cursor( col, row);
	push	de
	ld	a,e
	ld	e,d
	ld	d,a
	push	de
	call	_LCD_set_graphics_cursor
	pop	af
	call	_LCD_read_data
	pop	de
	ld	(ix-2),l
	ld	(ix-1),0x00
;Hyundai_256x128.c:181: data = ~(0x80 >> (x%8)) & t;
	push	de
	ld	hl,0x0008
	push	hl
	ld	l,(ix+4)
	ld	h,(ix+5)
	push	hl
	call	__modsint_callee
	pop	de
	ld	b, l
	ld	c,0x80
	inc	b
	jr	l_LCD_pixel_00111
l_LCD_pixel_00110:
	srl	c
l_LCD_pixel_00111:
	djnz	l_LCD_pixel_00110
	ld	b,0x00
;Hyundai_256x128.c:178: if (bit == 0) 
	ld	a,(ix+8)
	or	a, a
	jr	NZ,l_LCD_pixel_00102
;Hyundai_256x128.c:181: data = ~(0x80 >> (x%8)) & t;
	ld	a,c
	cpl
	ld	c,a
	ld	a,b
	cpl
	ld	b,a
	ld	a,c
	and	a,(ix-2)
	ld	c,a
	ld	a,b
	and	a,(ix-1)
	ld	b,a
	jr	l_LCD_pixel_00103
l_LCD_pixel_00102:
;Hyundai_256x128.c:186: data = (0x80 >> (x%8)) | t;
	ld	a,c
	or	a,(ix-2)
	ld	c,a
	ld	a,b
	or	a,(ix-1)
	ld	b,a
l_LCD_pixel_00103:
;Hyundai_256x128.c:189: LCD_set_graphics_cursor( col, row);
	push	bc
	ld	a,e
	ld	e,d
	ld	d,a
	push	de
	call	_LCD_set_graphics_cursor
	ld	h,0x42
	ex	(sp),hl
	inc	sp
	call	_LCD_write_cmd
	inc	sp
	pop	bc
;Hyundai_256x128.c:191: LCD_write( data );
	ld	b,c
	push	bc
	inc	sp
	call	_LCD_write
	ld	sp,ix
	pop	ix
	ret
	SECTION code_compiler
;Hyundai_256x128.c:194: void LCD_draw_line(int x0, int y0, int x1, int y1, char bit)
;	---------------------------------
; Function LCD_draw_line
; ---------------------------------
_LCD_draw_line:
	push	ix
	ld	ix,0
	add	ix,sp
	ld	hl,-10
	add	hl,sp
	ld	sp,hl
;Hyundai_256x128.c:198: dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	ld	a,(ix+8)
	sub	a,(ix+4)
	ld	c,a
	ld	a,(ix+9)
	sbc	a,(ix+5)
	ld	l,c
	ld	h,a
	call	_abs_fastcall
	ld	a,(ix+4)
	sub	a,(ix+8)
	ld	a,(ix+5)
	sbc	a,(ix+9)
	ld	c,l
	ld	b,h
	jp	PO, l_LCD_draw_line_00152
	xor	a,0x80
l_LCD_draw_line_00152:
	jp	P,l_LCD_draw_line_00113
	ld	a,0x01
	jr	l_LCD_draw_line_00114
l_LCD_draw_line_00113:
	ld	a,0xff
l_LCD_draw_line_00114:
	ld	(ix-4),a
	rla
	sbc	a, a
	ld	(ix-3),a
;Hyundai_256x128.c:199: dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	ld	a,(ix+10)
	sub	a,(ix+6)
	ld	e,a
	ld	a,(ix+11)
	sbc	a,(ix+7)
	ld	d,a
	ex	de,hl
	call	_abs_fastcall
	ex	de,hl
	pop	hl
	push	de
	ld	a,(ix+6)
	sub	a,(ix+10)
	ld	a,(ix+7)
	sbc	a,(ix+11)
	jp	PO, l_LCD_draw_line_00153
	xor	a,0x80
l_LCD_draw_line_00153:
	jp	P,l_LCD_draw_line_00115
	ld	a,0x01
	jr	l_LCD_draw_line_00116
l_LCD_draw_line_00115:
	ld	a,0xff
l_LCD_draw_line_00116:
	ld	(ix-6),a
	rla
	sbc	a, a
	ld	(ix-5),a
;Hyundai_256x128.c:200: err = (dx>dy ? dx : -dy)/2, e2;
	ld	a,(ix-10)
	sub	a, c
	ld	a,(ix-9)
	sbc	a, b
	jp	PO, l_LCD_draw_line_00154
	xor	a,0x80
l_LCD_draw_line_00154:
	jp	P,l_LCD_draw_line_00117
	ld	l, c
	ld	h, b
	jr	l_LCD_draw_line_00118
l_LCD_draw_line_00117:
	xor	a, a
	sub	a,(ix-10)
	ld	l,a
	ld	a,0x00
	sbc	a,(ix-9)
	ld	h,a
l_LCD_draw_line_00118:
	ld	e, l
	ld	d, h
	bit	7, h
	jr	Z,l_LCD_draw_line_00119
	ex	de,hl
	inc	de
l_LCD_draw_line_00119:
	sra	d
	rr	e
	xor	a, a
	sub	a, c
	ld	(ix-2),a
	ld	a,0x00
	sbc	a, b
	ld	(ix-1),a
l_LCD_draw_line_00109:
;Hyundai_256x128.c:203: LCD_pixel(x0,y0, bit);
	push	bc
	push	de
	ld	a,(ix+12)
	push	af
	inc	sp
	ld	l,(ix+6)
	ld	h,(ix+7)
	push	hl
	ld	l,(ix+4)
	ld	h,(ix+5)
	push	hl
	call	_LCD_pixel
	pop	af
	pop	af
	inc	sp
	pop	de
	pop	bc
;Hyundai_256x128.c:204: if (x0==x1 && y0==y1) break;
	ld	a,(ix+4)
	sub	a,(ix+8)
	jr	NZ,l_LCD_draw_line_00102
	ld	a,(ix+5)
	sub	a,(ix+9)
	jr	NZ,l_LCD_draw_line_00102
	ld	a,(ix+6)
	sub	a,(ix+10)
	jr	NZ,l_LCD_draw_line_00157
	ld	a,(ix+7)
	sub	a,(ix+11)
	jr	Z,l_LCD_draw_line_00111
l_LCD_draw_line_00157:
l_LCD_draw_line_00102:
;Hyundai_256x128.c:205: e2 = err;
	ld	(ix-8),e
	ld	(ix-7),d
;Hyundai_256x128.c:206: if (e2 >-dx) { err -= dy; x0 += sx; }
	ld	a,(ix-2)
	sub	a, e
	ld	a,(ix-1)
	sbc	a, d
	jp	PO, l_LCD_draw_line_00158
	xor	a,0x80
l_LCD_draw_line_00158:
	jp	P,l_LCD_draw_line_00105
	ld	a,e
	sub	a,(ix-10)
	ld	e,a
	ld	a,d
	sbc	a,(ix-9)
	ld	d,a
	ld	a,(ix+4)
	add	a,(ix-4)
	ld	(ix+4),a
	ld	a,(ix+5)
	adc	a,(ix-3)
	ld	(ix+5),a
l_LCD_draw_line_00105:
;Hyundai_256x128.c:207: if (e2 < dy) { err += dx; y0 += sy; }
	ld	a,(ix-8)
	sub	a,(ix-10)
	ld	a,(ix-7)
	sbc	a,(ix-9)
	jp	PO, l_LCD_draw_line_00159
	xor	a,0x80
l_LCD_draw_line_00159:
	jp	P,l_LCD_draw_line_00109
	ld	a,e
	add	a, c
	ld	e,a
	ld	a,d
	adc	a, b
	ld	d,a
	ld	a,(ix+6)
	add	a,(ix-6)
	ld	(ix+6),a
	ld	a,(ix+7)
	adc	a,(ix-5)
	ld	(ix+7),a
	jp	l_LCD_draw_line_00109
l_LCD_draw_line_00111:
	ld	sp, ix
	pop	ix
	ret
	SECTION IGNORE
