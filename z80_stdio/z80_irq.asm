;; Genaric Z-80 Interupt handler 
 
	GLOBAL  _z80pio_a_irq_set
	GLOBAL  _irq_ei
	GLOBAL  _irq_di
	GLOBAL  _irq_im0
	GLOBAL  _irq_im1
	GLOBAL _irq_im2
	;;GLOBAL _isr_Z80_IO_A
	;;GLOBAL _isr_Z80_IO_B
	GLOBAL _isr_trap

	
	



SECTION code_vector

EXTERN _isr_Z80_IO_A
defw _isr_Z80_IO_A
EXTERN _isr_Z80_IO_B
defw _isr_Z80_IO_B
defs 128-4
 

 
SECTION code_compiler

_irq_ei:
ei
ret

SECTION code_compiler
_irq_di:
di
ret

SECTION code_compiler
_irq_im0:
im 0
ret

SECTION code_compiler
_irq_im1:
im 1
ret

SECTION code_compiler
_irq_im2:
im 2
call _z80pio_a_irq_set
ret



;
