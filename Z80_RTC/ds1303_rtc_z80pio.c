/* DS1303 RTC Z80 PIO interface version  */

#include "ds1303_rtc_z80pio.h"
#include "z80_pio.h" 
#include <z80.h>
#include <stdlib.h>
#include <stdio.h>

/* PIO bit 0 = CLK, BIT 1 = DATA, BIT 2 = RESET/CE */

void rtc_read_time( char *ptr )
{

int t, tc, tf;
char data[25], sec_10,sec_1, min_10, min_1, hour_10, hour_1, am_pm, m12_24, day, date_1, date_10, month_1, month_10, year_1, year_10;    
char timeformat[3][3] = { {'M','T','\0'},{'A','M','\0'}, {'P','M','\0'} };    
char *t_data;
am_pm = 0;
m12_24 = 0;


day = rtc_read(READ_DAY) - 1;
month_10 = rtc_read(READ_MONTH);
month_1 = month_10 & 0x0f;
month_10 = month_10>>4;
month_10 = (month_1 + month_10 * 10) - 1;

date_10 = rtc_read(READ_DATE);
date_1 = date_10 & 0x0f;
date_10 = date_10>>4;

year_10 = rtc_read(READ_YEAR);
year_1 = year_10 & 0x0f;
year_10 = year_10>>4;


sec_10 = rtc_read(READ_SECONDS);
sec_1 = sec_10 & 0x0f;
sec_10 = sec_10>>4;
//sec_10 = sec_1 + sec_10 * 10;

min_10 = rtc_read(READ_MINUTES);
min_1 = min_10 & 0x0f;
min_10 = min_10>>4;
//min_10 = min_1 + min_10 * 10;

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
//hour_10 = hour_1 + hour_10 * 10;

t_data = ptr;

t_data[0] = ds_day[day][0];
t_data[1] = ds_day[day][1];
t_data[2] = ds_day[day][2];
t_data[3] = ' ';
t_data[4] = ds_month[month_10][0];
t_data[5] = ds_month[month_10][1];
t_data[6] = ds_month[month_10][2];
t_data[7] = ' ';
t_data[8] = date_10 + 48;
t_data[9] = date_1 + 48;
t_data[10] = ' ';
t_data[11] = '2';
t_data[12] = '0';
t_data[13] = year_10 + 48;
t_data[14] = year_1 + 48;
t_data[15] = ' ';
t_data[16] = hour_10 + 48;
t_data[17] = hour_1 + 48;
t_data[18] = ':';
t_data[19] = min_10 + 48;
t_data[20] = min_1 + 48;
t_data[21] = ':';
t_data[22] = sec_10 + 48;
t_data[23] = sec_1 + 48;
t_data[24] = ' ';
t_data[25] = timeformat[tf][0];
t_data[26] = timeformat[tf][1];
t_data[27] = '\0';
t_data[28] = 0;


}

void rtc_date_short( char *ptr )
{

int t, tc, tf;
char data[25], sec_10,sec_1, min_10, min_1, hour_10, hour_1, am_pm, m12_24, day, date_1, date_10, month_1, month_10, year_1, year_10;    
char *t_data;


day = rtc_read(READ_DAY) - 1;
month_10 = rtc_read(READ_MONTH);
month_1 = month_10 & 0x0f;
month_10 = month_10>>4;
month_10 = (month_1 + month_10 * 10) -1;

date_10 = rtc_read(READ_DATE);
date_1 = date_10 & 0x0f;
date_10 = date_10>>4;

year_10 = rtc_read(READ_YEAR);
year_1 = year_10 & 0x0f;
year_10 = year_10>>4;



t_data = ptr;

t_data[0] = ds_day[day][0];
t_data[1] = ds_day[day][1];
t_data[2] = ds_day[day][2];
t_data[3] = ' ';
t_data[4] = ds_month[month_10][0];
t_data[5] = ds_month[month_10][1];
t_data[6] = ds_month[month_10][2];
t_data[7] = ' ';
t_data[8] = date_10 + 48;
t_data[9] = date_1 + 48;
t_data[10] = ' ';
t_data[11] = '2';
t_data[12] = '0';
t_data[13] = year_10 + 48;
t_data[14] = year_1 + 48;
t_data[15] = '\0';
t_data[16] = 0;


}



void rtc_read_time_short( char *ptr )
{

int t, tc, tf;
char data[25], sec_10,sec_1, min_10, min_1, hour_10, hour_1, am_pm, m12_24, day, date_1, date_10, month_1, month_10, year_1, year_10;    
char timeformat[3][3] = { {'M','T','\0'},{'A','M','\0'}, {'P','M','\0'} };    
char *t_data;
am_pm = 0;
m12_24 = 0;


sec_10 = rtc_read(READ_SECONDS);
sec_1 = sec_10 & 0x0f;
sec_10 = sec_10>>4;
//sec_10 = sec_1 + sec_10 * 10;

min_10 = rtc_read(READ_MINUTES);
min_1 = min_10 & 0x0f;
min_10 = min_10>>4;
//min_10 = min_1 + min_10 * 10;

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
//hour_10 = hour_1 + hour_10 * 10;

t_data = ptr;

t_data[0] = ' ';
t_data[1] = ' ';
t_data[2] = hour_10 + 48;
t_data[3] = hour_1 + 48;
t_data[4] = ':';
t_data[5] = min_10 + 48;
t_data[6] = min_1 + 48;
t_data[7] = ':';
t_data[8] = sec_10 + 48;
t_data[9] = sec_1 + 48;
t_data[10] = ' ';
t_data[11] = timeformat[tf][0];
t_data[12] = timeformat[tf][1];
t_data[13] = ' ';
t_data[14] = ' ';
t_data[15] = '\0';
t_data[16] = 0;


}    

    

void rtc_write(char address, char data )
{
char i, j;
// make sure out PIO is set correct
z80_outp( Z80_PIO_A_CTL, Z80_PIO_M3);  // set mode 3 Port Bit set per mask
z80_outp( Z80_PIO_A_CTL, 0xf8);  // First Three bits set to output.

j = address;
z80_pio_write_bit(Z80_PIO_A, 0, 0);
z80_pio_write_bit(Z80_PIO_A, 2, 1);
// Shift bit's out right, LSB-MSB
for(i=0; i < 8; i++)
   {    
   z80_pio_write_bit(Z80_PIO_A, 0, 0);
   z80_pio_write_bit(Z80_PIO_A, 1, j & 0x01 );
   z80_pio_write_bit(Z80_PIO_A, 0, 1);
   j = j>>1;
   }
j = data;

// Shift bit's out right, LSB-MSB
for(i=0; i < 8; i++)
   {    
   z80_pio_write_bit(Z80_PIO_A, 0, 0);
   z80_pio_write_bit(Z80_PIO_A, 1, j & 0x01 );
   z80_pio_write_bit(Z80_PIO_A, 0, 1);
   j = j>>1;
   }   

z80_pio_write_bit(Z80_PIO_A, 0, 0);   
z80_pio_write_bit(Z80_PIO_A, 2, 0);

}  


char rtc_read(char k )
{
char i, j, t;
// make sure out PIO is set correct
z80_outp( Z80_PIO_A_CTL, Z80_PIO_M3);  // set mode 3 Port Bit set per mask
z80_outp( Z80_PIO_A_CTL, 0xf8);  // First Three bits set to output.
j = k;
z80_pio_write_bit(Z80_PIO_A, 0, 0);
z80_pio_write_bit(Z80_PIO_A, 2, 1);
// Shift bit's out left, LSB-MSB
// Write address to read
for(i=0; i < 8; i++)
   {    
   z80_pio_write_bit(Z80_PIO_A, 0, 0);
   z80_pio_write_bit(Z80_PIO_A, 1, j & 0x01 ); 
   z80_pio_write_bit(Z80_PIO_A, 0, 1);
   j = j>>1;
   }
   

z80_outp( Z80_PIO_A_CTL, Z80_PIO_M3);  // set mode 3 Port Bit set per mask
z80_outp( Z80_PIO_A_CTL, 0xfa);  // First and Thrid bits set to output, now bit two is input
j=0;

for(i=0; i < 8; i++)
   {    
   j = j>>1;
   z80_pio_write_bit(Z80_PIO_A, 0, 0);
   j= j | (0x80 * (0x01 & z80_pio_read_bit(Z80_PIO_A, 1)));
   z80_pio_write_bit(Z80_PIO_A, 0, 1);
   
   }
z80_pio_write_bit(Z80_PIO_A, 0, 0);  
z80_pio_write_bit(Z80_PIO_A, 2, 0);
 
return j;
}
