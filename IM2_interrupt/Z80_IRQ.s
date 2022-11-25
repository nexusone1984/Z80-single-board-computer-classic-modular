;; Genaric Z-80 Interupt handler 
 .module z80_irq
 
 .globl  _z80pio_a_irq_set
 .globl _irq_ei
 .globl _irq_di
 .globl _irq_im0
 .globl _irq_im1
 .globl _irq_im2
 
 
.area _CODE

_irq_ei::
ei
ret

_irq_di::
di
ret

_irq_im0::
im 0
ret

_irq_im1::
im 1
ret

_irq_im2::
LD a, #0x02
LD i, a
im 2
ret

_isr_08::
call _z80pio_a_irq_set
reti



_isr_10::
reti


_isr_18::
reti


_isr_20::
reti


_isr_28::
reti


_isr_30::
reti


_isr_38::
call _z80pio_a_irq_set
reti

;; NMI 
_isr_66:: 
retn
