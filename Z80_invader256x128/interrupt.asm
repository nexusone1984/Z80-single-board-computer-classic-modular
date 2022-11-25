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

; device vector id 3
PUBLIC _vid_ctc_0
EXTERN _isr_ctc_0
_vid_ctc_3:
defw   _isr_ctc_0

; device vector id 4
PUBLIC _vid_ctc_1
EXTERN _isr_ctc_1
_vid_ctc_1:
defw   _isr_ctc_1


; device vector id 5
PUBLIC _vid_ctc_2
EXTERN _isr_ctc_2
_vid_ctc_2:
defw   _isr_ctc_2


; device vector id 6
PUBLIC _vid_ctc_3
EXTERN _isr_ctc_3
_vid_ctc_3:
defw   _isr_ctc_3

; skip vectors 4 through 126
defs   128
