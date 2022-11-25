/* Z80 CTC Library    by Eric Stringer  */
/* eric.stringer@gmail.com  version 1.0  */

#include "z80_ctc.h"
#include <z80.h>



void z80_ctc_write_(unsigned char port, unsigned char byte)
{
unsigned char data; 
    
z80_outp(port, data);    
   
}    
    
unsigned char z80_ctc_read(unsigned char port)
{
unsigned char data;
   
data = z80_inp(port); 

return(data);
}
    
    
