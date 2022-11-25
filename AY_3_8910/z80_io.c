/* Z80 PIO Library    by Eric Stringer  */
/* eric.stringer@gmail.com  version 1.0 March 2017 */

#include "Z80_IO.h"
#include <z80.h>

unsigned char Bit_mask[8] = {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000};


void z80_pio_write_bit(unsigned char port, unsigned char bit, unsigned bit_state)
{
unsigned char data; 
    
if (bit > 7) bit = 7;
    
if (bit_state == 0)
   {
       data = z80_inp(port) & ~Bit_mask[bit];
    z80_outp(port, data);    
    }else{
        data = z80_inp(port) | Bit_mask[bit];
    z80_outp(port, data);  
    }   
}    
    
unsigned char z80_pio_read_bit(unsigned char port, unsigned char bit)
{
unsigned char data;

if (bit > 7 ) bit = 7;    
data = z80_inp(port) & Bit_mask[bit];
if (data != 0) data = 1;
return(data);
}
    
    
