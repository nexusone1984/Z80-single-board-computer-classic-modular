
/*  Z80 PIO  RTC ds1302 clock module                                */

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
int t, tc, tf, temp, n1, n10;
char data[30];    
    
system_init();
/*
rtc_write(WRITE_WP, 0x00); // RTC write protect off
rtc_write(WRITE_SECONDS, 0x00); // Seconds/Oscilator enable
rtc_write(WRITE_HOUR, 0xb0);
rtc_write(WRITE_MINUTES, 0x09); 
rtc_write(WRITE_YEAR, 0x19);
rtc_write(WRITE_DAY, 0x05);
rtc_write(WRITE_DATE, 0x14); 
rtc_write(WRITE_MONTH, 0x11); 
*/

LCD_set_cursor(0 , 0);
LCD_print("RTC DS1302 test\0");
t=1;
while( t != 0)
{    
rtc_read_time( data );
LCD_set_cursor(0 , 3);
LCD_print(data);

LCD_set_cursor(0 , 4);
temp = rtc_read(READ_DAY) - 1;
LCD_print("Day = ");
data[0] = ds_day[temp][0];
data[1] = ds_day[temp][1];
data[2] = ds_day[temp][2];
data[3] = '\0';
LCD_print(data);

LCD_set_cursor(0 , 5);
n10 = rtc_read(READ_MONTH);
n1 = n10 & 0x0f;
n10 = n10>>4;
n10 = (n1 + n10 * 10) - 1;

LCD_print("Month = ");
data[0] = ds_month[n10][0];
data[1] = ds_month[n10][1];
data[2] = ds_month[n10][2];
data[3] = '\0';
LCD_print(data);


rtc_date_short( data );
LCD_set_cursor(0 , 7);
LCD_print(data);


z80_delay_ms(500);
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




