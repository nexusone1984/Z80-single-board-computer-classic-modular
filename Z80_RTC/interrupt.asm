

SECTION interrupt_vectors

; device vector id 0
PUBLIC _vid_pio_0_a
EXTERN _isr_pio_0_a
_vid_pio_0_a:
defw   _isr_pio_0_a


; device vector id 2
PUBLIC _vid_pio_0_b
EXTERN _isr_pio_0_b
_vid_pio_0_b:
defw   _isr_pio_0_b

; skip vectors 4 through 126
defs   128
