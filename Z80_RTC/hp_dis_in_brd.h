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

#include "z80_pio.h" 
#include <z80.h>
#include <stdlib.h>
#include <stdio.h>

/* Display Controll register
Display digit length 
0x00  9 digits
0x01 10 digits
0x02 11 digits
0x03 12 digits
0x04 13 digits
0x05 14 digits
0x06 15 digits
0x07 16 digits
Display Dimmer value setting
0x08  1/16
0x09  2/16
0x0a  4/16
0x0b  6/16
0x0c  8/16
0x0d  10/16
0x0e  12/16
0x0f  14/16
One-digit display frequency setting
0xf6 128/fosc
0xf7 256/fosc
Display digit position 
0xf? ?=0-f 
Display auto increment 
0xf4 off
0xf5 on
Display ON/OFF
0xf0  display off
0xf1  display on
0xf3  all segments on. 
Cursor off
0x8?  0-f
Cursor on
0x1?  0-f

*/

void HP_display_write(char cmd );

void HP_write_str( char *ptr );

int HP_read_buttons( void );
