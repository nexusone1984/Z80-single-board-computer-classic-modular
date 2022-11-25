/*  Z80 PIO  RTC ds1302 clock module  HP display                          */

#include "hp_dis_in_brd.h"
#include "ds1303_rtc_z80pio.h"
#include "z80_pio.h"
#include <z80.h>
#include <stdlib.h>
#include <stdio.h>


void system_init(void);
void speak( int w );

int main()
{
int  i, t, button;

    
system_init();

t=1;

i=0;

while( t != 0)
{    
button = HP_read_buttons();

if (button == 8)
    {
    speak(i);
    i++;
    if (i > 35) i = 0;
    }
 
}




return 0;
}




    
void speak( int w )
{
int tc;

while( z80_pio_read_bit(Z80_PIO_B, 7) == 0);
z80_pio_write_bit(Z80_PIO_B, 6, 1);
z80_outp( Z80_PIO_B, w );
tc = 0;
while( tc < 10 ) tc++;
z80_pio_write_bit(Z80_PIO_B, 6, 1);
tc = 0;
while( tc < 10000 ) tc++;


}



void system_init(void)
{

// initialize PIO ports

z80_outp( Z80_PIO_A_CTL, Z80_PIO_M3);  // set mode 3 Port Bit set per mask
z80_outp( Z80_PIO_A_CTL, 0xf8);  // First Three bits set to output. 


z80_outp( Z80_PIO_B_CTL, Z80_PIO_M3);  // set mode 1 byte input 
z80_outp( Z80_PIO_B_CTL, 0x80);  // First Three bits set to output. 
z80_pio_write_bit(Z80_PIO_B, 6, 1);



}



