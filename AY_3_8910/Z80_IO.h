/* Z80_IO.h       */
/* Z80 IO DEF     */


/* define logic mask */

#define Bit_mask0  0b00000001
#define Bit_mask1  0b00000010
#define Bit_mask2  0b00000100
#define Bit_mask3  0b00001000
#define Bit_mask4  0b00010000
#define Bit_mask5  0b00100000
#define Bit_mask6  0b01000000
#define Bit_mask7  0b10000000


// User system Define Z80 PIO location
#define Z80_PIO_A 0x00   // Port A
#define Z80_PIO_B 0x01   // Port B
#define Z80_PIO_A_CTL 0x02  // Port Control A
#define Z80_PIO_B_CTL 0x03  // Port Control B

// Z80 PIO Mode define
#define Z80_PIO_M0 0x0f  // Mode 0 Port is output only
#define Z80_PIO_M1 0x4f  // Mode 1 Port is input only
#define Z80_PIO_M2 0x8f  // Mode 2 Port is Bidirectonal operation
#define Z80_PIO_M3 0xCf  // Mode 3 Port is port direction can be 
                         // set per bit via direction mask.
                         // this command expects a mask byte to follow
                         //  0 bit = output and 1 bit = input
                         // 

                         
                         
// Z80 PIO interruot setup                         

#define Z80_PIO_EI 0x87  // Enable PIO interrupts
// The following bit wise OR with above

// Mode 3 interrupt options
// Bit D5 Look for port to be High or low state.
// where set to 0 for low, 1 for high
// Bit D6 AND/OR state, AND all ports must be in
// active state, or only one need be in active state 
// for interrupt.  Bit D4 is mask byte to follow,
// Bit set to 1 that port bit is ignored, 0 watch port bit. 


#define Z80_PIO_EI_MF  0b00010000 // Mask follows command
#define Z80_PIO_EI_AND 0b01000000 // AND Bits 
#define Z80_PIO_EI_OR  0b00000000 // OR Bits 
#define Z80_PIO_EI_HIGH 0b00100000 // HIGH Transistion triggers
#define Z80_PIO_EI_LOW 0b00000000 // LOW Transistion triggers



#define Z80_PIO_DI 0x07  // Disable PIO interrupts

// Z80 PIO 0 address
__sfr __at 0x00 Z80PIOA;
__sfr __at 0x01 Z80PIOB;
__sfr __at 0x02 Z80PIOA_REG;
__sfr __at 0x03 Z80PIOB_REG;

extern void z80_io_write( unsigned char port, unsigned char data);
extern unsigned char z80_io_read( unsigned char port);

void z80_pio_write_bit(unsigned char port, unsigned char bit, unsigned bit_state);
unsigned char z80_pio_read_bit(unsigned char port, unsigned char bit);
