/*  Z80 PIO  RTC ds1302 clock module  HP display                          */

#include "hp_dis_in_brd.h"
#include "ds1303_rtc_z80pio.h"
#include "z80_pio.h"
#include <z80.h>
#include <stdlib.h>
#include <stdio.h>

void int2ascii(unsigned int cx, char *ptr );
void set_time( void );
void system_init(void);
void Say_time(void);
void speak( int w );

int test = 0;

int main()
{
int t, button, b_up[9], b_down[9], t_check, clock_mode, i;

char data[30];    
    
system_init();

HP_display_write(0x07 ); // 16 digits
HP_display_write(0x0f ); // Dimmer
HP_display_write(0xf1 ); // Display Normal mode on
HP_display_write(0xf7 ); // Display freq
HP_display_write(0xe0 ); // digit position
HP_write_str( "                \0" );

i=0;
t_check = 0;
b_down[0] = 0;
b_down[1] = 0;

clock_mode = 0;
t=1;
while( t != 0)
{    
button = HP_read_buttons();

if (button == 8) Say_time();

if (button == 1)
    {
    speak(34);    
    speak(35);
    }

if (button == 130)
   {
   if (b_down[1] == 0)
   {
   rtc_date_short( data );
   HP_display_write(0xe0 ); // digit position
   HP_write_str( data );
   }
  b_down[1] = 1;

   }else{
   
  b_down[1] = 0;
  
if ( t_check > 50 )
{
 rtc_read_time_short( data );
 HP_display_write(0xe0 ); // digit position
 HP_write_str( data );
 t_check = 0;
 }else {
     t_check++;
 }

if (button != 0)
 {
     
 if (button == 64)
   {
    b_down[0]++;
   }else{
    b_down[0] = 0;
    }   

    if (b_down[0] > 100) 
     {
     set_time( );   
     b_down[0] = 0;
     }
 }
}

}


return 0;
}


void Say_time(void)
{

int t, tc, tf;
char data[25], sec_10,sec_1, min_10, min_1, hour_10, hour_1, am_pm, m12_24, day, date_1, date_10, month_1, month_10, year_1, year_10;    
char timeformat[3][3] = { {'M','T','\0'},{'A','M','\0'}, {'P','M','\0'} };    
char *t_data;
am_pm = 0;
m12_24 = 0;


min_10 = rtc_read(READ_MINUTES);
min_1 = min_10 & 0x0f;
min_10 = min_10>>4;


hour_10 = rtc_read(READ_HOUR);

m12_24 = hour_10 & 0x80;

if (m12_24 == 0x80)
   {
    m12_24 = 1;
    
   am_pm =  hour_10 & 0x20;
   if ( am_pm == 0x20)
      {
      am_pm = 1;
      }else{
      am_pm = 0;
      }    
   }else{ 
    m12_24 = 0;
   }

tf = am_pm + m12_24;

hour_1 = hour_10 & 0x0f;
hour_10 = (hour_10>>4) & 0x01;
hour_10 = hour_1 + hour_10 * 10;

speak(24);

speak( hour_10 );


if ( min_10 < 2)
{

t = min_1 + min_10 * 10;    
if ( t > 9) speak( t );
if ( (t < 10) & (t != 0) )
{
speak( 0 );    
speak( t );
}

}    
    
if ( min_10 >= 2)
{
    
speak( 18 + min_10);    
if (min_1 != 0) speak( min_1 );

}

speak( 25 + am_pm );

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

void set_time( void )
{
char t_data[25], d_data[25], sec_10,sec_1, min_10, min_1, hour_10, hour_1, am_pm, m12_24, day, date_1, date_10, month_1, month_10, year_1, year_10; 

int ts_exit, button,  b_down[9], td;

ts_exit = 0;
td = 0;

rtc_read_time_short( t_data );




rtc_date_short( d_data );

b_down[0] = 0;


while(ts_exit == 0)
{
    
button = HP_read_buttons();

if (button == 64)
  {
  b_down[0]++;
  }else{
  b_down[0] = 0;
  }

if (b_down[0] > 50) ts_exit = 1;

if ( button == 130 )
   {
    b_down[1]++;
   }else{
   b_down[1] = 0;
   }
   
if (b_down[1] > 50)
   {
    td = abs( td - 1);
   b_down[1] = 0;
   }
    
if ( td == 0 )
   {  
   HP_display_write(0xe0 ); // digit position
   HP_write_str( t_data );
   }else{
   HP_display_write(0xe0 ); // digit position
   HP_write_str( d_data );
   }
   
}

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

