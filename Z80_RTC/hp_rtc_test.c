/*  Z80 PIO  RTC ds1302 clock module  HP display                          */

#include "hp_dis_in_brd.h"
#include "ds1303_rtc_z80pio.h"
#include "z80_pio.h"
#include <z80.h>
#include "Hyundai_256x128.h"
#include <stdlib.h>
#include <stdio.h>

void int2ascii(unsigned int cx, char *ptr );

int pio_int_a, pio_int_b;

void system_init(void);


int main()
{
int t, button, b_up[9], b_down[9], t_check, clock_mode, i;

int t_hour, t_minute, t_second, t_tm;


char data[30];    
    
system_init();

HP_display_write(0x07 ); // 16 digits
HP_display_write(0x0f ); // Dimmer
HP_display_write(0xf1 ); // Display Normal mode on
HP_display_write(0xf7 ); // Display freq
HP_display_write(0xe0 ); // digit position
HP_display_write(0x1f );
HP_write_str( "                \0" );

i=0;
t_check = 0;
b_down[0] = 0;
clock_mode = 0;

LCD_set_cursor(0 , 0);
LCD_print("RTC DS1302 test\0");
t=1;
while( t != 0)
{    
button = HP_read_buttons();
    
if ( t_check > 100 )
{
LCD_set_cursor(0 , 5);
int2ascii( button, data );
LCD_print(data);
    
    
 rtc_read_time_short( data );
 HP_display_write(0x80 + i );
 i++;
 if (i > 15 ) i = 0;
 HP_display_write(0x10 + i );
 
 HP_display_write(0xe2 ); // digit position
 HP_write_str( data );
 t_check = 0;
 }else {
     t_check++;
 }
 
 

if (button == 64)
  {
   b_down[0]++;
  }else{
   b_down[0] = 0;
  }   



if (b_down[0] > 400) 
{  
clock_mode = 1;
LCD_set_cursor(0 , 6);
int2ascii( clock_mode, data );
LCD_print(data);





}



}




return 0;
}


void system_init(void)
{

// initialize PIO ports

z80_outp( Z80_PIO_A_CTL, Z80_PIO_M3);  // set mode 3 Port Bit set per mask
z80_outp( Z80_PIO_A_CTL, 0xf8);  // First Three bits set to output. 


z80_outp( Z80_PIO_B_CTL, Z80_PIO_M1);  // set mode 1 byte input 


// intialize display
LCD_write_cmd( 0x40 );  // System set command
LCD_write(0x30); // P1 use internal 8px char w/ no top line correction
LCD_write(0x87); // P2 8px width char
LCD_write(0x07); // P3 8px height char
LCD_write(0x1f); // P4 32 char per line
LCD_write(0x23); // P5 previous value + 4
LCD_write(0x7f); // P6 128 pixel screen height
LCD_write(0x20); // P7 32 char per line
LCD_write(0x00); // P8


LCD_write_cmd(0x5d); // Set cursor type
LCD_write(0x04);
LCD_write(0x86);
LCD_write_cmd(0x4c); // Set direction of cursor movement
LCD_write_cmd(0x5B); // Set display overlay
LCD_write(0x08);  //3  



LCD_write_cmd(0x44); //Scroll - Set display start address and display regions
LCD_write(0x00);
LCD_write(0x00);
LCD_write(0x80);
LCD_write(0xb0);
LCD_write(0x04);
LCD_write(0x80);
LCD_write(0x00);
LCD_write(0x00);
LCD_write(0x80);
LCD_write(0xb0);


LCD_write_cmd(0x5A); // Set horizontal scroll 
LCD_write(0x00); 


LCD_write_cmd(0x59); // Display on
LCD_write(0x16);  // 06

LCD_clear();
LCD_graphics_clear();
LCD_set_cursor(0, 0);


}

void int2ascii(unsigned int cx, char *ptr )
{
  
int i;
ptr = ptr + 5;

*ptr-- = '\0';

for( i = 0; i < 5; i++)
{
*ptr-- = '0' + cx % 10 ;
cx = cx / 10;
}
 
}

