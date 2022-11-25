/* z80_ctc.h       */
/* Z80 CTC library Eric Stringer     */



// User system Define Z80 PIO location
#define Z80_CTC_0  0x20   // Timer-Counter 0
#define Z80_CTC_1  0x21   // Timer-Counter 1
#define Z80_CTC_2  0x22   // Timer-Counter 2
#define Z80_CTC_3  0x23   // Timer-Counter 3


// CTC Channel Control Bit definitions. 
//

#define Z80_CTC_CHANNEL_CONTROL           0b00000001 // Control Word
#define Z80_CTC_INTERRUPT_ENABLE          0b10000000 // Interrupt Enable
#define Z80_CTC_INTERRUPT_DISABLE         0b00000000 // Interrupt Disable
#define Z80_CTC_MODE_COUNTER              0b01000000 // Counter mode
#define Z80_CTC_MODE_TIMER                0b00000000 // Timer mode
#define Z80_CTC_TIMER_MODE_PRESCALE_256   0b00100000 // Prescale divide by 256 
#define Z80_CTC_TIMER_MODE_PRESCALE_16    0b00000000 // Prescale divide by 16 
#define Z80_CTC_TRIGGER_EDGE_POSITIVE     0b00010000 // Positive Trigger Edge 
#define Z80_CTC_TRIGGER_EDGE_NEGATIVE     0b00000000 // Negative Trigger Edge
#define Z80_CTC_EXTERNAL_TRIGGER          0b00001000 // External Trigger
#define Z80_CTC_INTERNAL_TRIGGER          0b00001000 // Internal Trigger
#define Z80_CTC_TIME_CONSTANT_FOLLOWS     0b00000100 // Next byte is Time Constant 
#define Z80_CTC_CHANNEL_RESET             0b00000010 // Channel Reset 

