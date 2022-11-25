/* HP LaserJet 4P display/input board routine            */
/* 16 character VFD display chip M66004FP                */
/* 9 buttons input chip 74HC165 paralell in serial out */
/* Pinout of board connector I calling pin 1 nearest 1 one of display chip  */
/* 1 & 2 VCC                                      */
/* 3 Serial Data in                               */ 
/* 4 Shift Clock/Display Clock                     */
/* 5 Display CS                                   */
/* 6 Shif-register (CP) Load                      */
/* 7 Shift-register out, 8 & 9 ground              */

#include "hp_dis_in_brd.h"


int HP_read_buttons( void )
{
int i, k, j;

// make sure out PIO is set correct
j=0;
z80_outp( Z80_PIO_A_CTL, Z80_PIO_M3);  // set mode 3 Port Bit set per mask
z80_outp( Z80_PIO_A_CTL, 0x87);  // 
z80_pio_write_bit(Z80_PIO_A, 6, 1);
z80_pio_write_bit(Z80_PIO_A, 4, 1);
// Shift bit's out left, LSB-MSB
// Write address to read

z80_pio_write_bit(Z80_PIO_A, 6, 0);
z80_pio_write_bit(Z80_PIO_A, 6, 1);
for(i=0; i < 8; i++)
   { 
   j = j<<1;    
   j= j | (0x01 & z80_pio_read_bit(Z80_PIO_A, 7));
   z80_pio_write_bit(Z80_PIO_A, 4, 0);
   z80_pio_write_bit(Z80_PIO_A, 4, 1);
   }
k = j;   
return k;
}

void HP_write_str( char *ptr )
{
HP_display_write(0xf5 ); // auto increase on    
while ( *ptr != '\0' )
{
HP_display_write( *ptr++ );
}

HP_display_write(0xf4 ); // auto increase off 
}


    

void HP_display_write(char cmd )
{
char i, j;
// make sure out PIO is set correct
z80_outp( Z80_PIO_A_CTL, Z80_PIO_M3);  // set mode 3 Port Bit set per mask
z80_outp( Z80_PIO_A_CTL, 0x87);  // D0-D2 reserved set inputs, D3-D6 set output, D7 set to input.

j = cmd;
z80_pio_write_bit(Z80_PIO_A, 5, 1);
z80_pio_write_bit(Z80_PIO_A, 4, 1);
z80_pio_write_bit(Z80_PIO_A, 5, 0);
// Shift bit's out right, MSB-LSB
for(i=0; i < 8; i++)
   {    
   z80_pio_write_bit(Z80_PIO_A, 4, 0);
   z80_pio_write_bit(Z80_PIO_A, 3, j & 0x80 );
   z80_pio_write_bit(Z80_PIO_A, 4, 1);
   j = j<<1;
   }
z80_pio_write_bit(Z80_PIO_A, 5, 1);
}   
   
