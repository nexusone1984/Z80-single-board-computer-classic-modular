/* DS1303 RTC Z80 PIO interface version  */
/* header file                           */

#include "z80_pio.h" 
#include <z80.h>
#include <stdlib.h>
#include <stdio.h>

// Define DS1303 commands
// Command specifies if a read or write operation
// the registers store time in BCD format, conversion from binary must be done to write or read data
// Note Datasheet states the Clock oscilator and Write protect are in a unknown state at intial powerup, unless battery backup is being used.  You must set both to zero before the chip will operate. 


#define READ_SECONDS 0x81  // Bit 7 is used for Clock oscilator enable, Bits 6-4 10's Place and Bit's 3-0 are one's place.  

#define WRITE_SECONDS 0x80  // Bit 7 is used for Clock oscilator enable, Bits 6-4 10's Place and Bit's 3-0 are one's place.  

#define READ_MINUTES 0x83  // Bits 6-4 10's Place and Bit's 3-0 are one's place.    

#define WRITE_MINUTES 0x82  // Bits 6-4 10's Place and Bit's 3-0 are one's place.  

#define READ_HOUR 0x85  // Bit 7 is 12/24 hour mode select, Bit 6 unused Bits 5-4 10's Place and Bit's 3-0 are one's place.  Note bit 5 in 12 hour mode indicated AM low, PM high  

#define WRITE_HOUR 0x84  // Bit 7 is 12/24 hour mode select, Bit 6 unused Bits 5-4 10's Place and Bit's 3-0 are one's place. Note bit 5 in 12 hour mode indicated AM low, PM high  

#define READ_DATE 0x87  // Bit's 7 & 6 are unused, Bits 5 & 4 ten's Place, Bits 3-0 one's places (1-31)

#define WRITE_DATE 0x86  // Bit's 7 & 6 are unused, Bits 5 & 4 ten's Place, Bits 3-0 one's places (1-31)

#define READ_MONTH 0x89  // Bit's 7 & 6 are unused, Bits 5 & 4 ten's Place, Bits 3-0 one's places (1-12)

#define WRITE_MONTH 0x88  // Bit's 7 & 6 are unused, Bits 5 & 4 ten's Place, Bits 3-0 one's places (1-12)

#define READ_DAY 0x8b  // Bit's 7 - 3 are unused, Bits 2-0 one's places (1-7)

#define WRITE_DAY 0x8a  // Bit's 7 - 3 are unused, Bits 2-0 one's places (1-7)

#define READ_YEAR 0x8d  // Bit's 7 - 3 are unused, Bits 2-0 one's places (0-99)

#define WRITE_YEAR 0x8c  // Bit's 7 - 3 are unused, Bits 2-0 one's places (0-99)

#define READ_WP 0x8f  // Bit 7 only 1 = Write protect

#define WRITE_WP 0x8e  // Bit 7 only 1 = Write protect

#define READ_TCS 0x91  // Trickle Charge settings, see datasheet.

#define WRITE_TCS 0x90  // Trickle Charge settings 

#define READ_CB 0xbf  // Clock Burst read

#define WRITE_CB 0xbe  // Clock Burst write 

static const char *ds_day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

static const char *ds_month[] = {"January", "Febuary", "March", "April", "May", "June", "July", "Augest", "September", "October", "November", "December" };


void rtc_read_time( char *ptr );
void rtc_read_time_short( char *ptr );
void rtc_date_short( char *ptr );
void rtc_write(char address, char data );
char rtc_read(char k );
