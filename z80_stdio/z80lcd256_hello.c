/* 256X128 LCD Graphics display Hyundai #HG25504 */
/* Display Demo                                  */


#include "Hyundai_256x128.h"
#include "Z80_IO.h"
#include <z80.h>
#include <stdlib.h>
#include <stdio.h>

void int2ascii(unsigned int cx, char *ptr );
void system_init(void);
void Button_press(void);
void delay(int j);

extern char mybuffer[];

char lcd_char_x, lcd_char_y;

void delay(int j)
{
int i;
for(i=0; i<j; i++);
}


int main()
{
int x;
system_init();
for(x=0; x < 512; x++) mybuffer[x] = 0x20;


printf("Printf test\n");

x = 0xcc;
printf("Decimal x = %d\n", x);
printf("Hex x = %x\n", x);
printf("Press Button\n");
Button_press();



for(x=0;x < 16; x++)
{
printf("x = %d\n", x);
delay(500);
}
printf("End");


Button_press();
/*
__asm
call _lcd_scroll
__endasm;
*/

LCD_clear();
LCD_write_cmd(0x4c); // Set direction of cursor movement
LCD_set_cursor(0, 0);
for(x=0;x<512;x++)
{
LCD_print_char(mybuffer[x]);
}

Button_press();


return( 0 );
}    



void Button_press(void)
{

char button_state = 1;

while( button_state == 1 )
{
if ((z80_inp( Z80_PIO_B)  & 0b00001000) == 0) 
   {
   button_state = 0;
   } else {
   button_state = 1;
   }
}

}


void system_init(void)
{

// initialize PIO ports

z80_outp( Z80_PIO_A_CTL, Z80_PIO_M0);  // set mode 1 byte output
z80_outp( Z80_PIO_B_CTL, Z80_PIO_M3);  // set mode 3 bit in/out mode mask select
z80_outp( Z80_PIO_B_CTL, 0x78);  // set first three pins as outputs, the rest as inputs





// intialize display
LCD_write_cmd( 0x40 );  // System set command
LCD_write(0x30); // P1 use internal 8px char w/ no top line correction
LCD_write(0x87); // P2 8px width char
LCD_write(0x07); // P3 8px height char
LCD_write(0x1f); // P4 32 char per line 1f
LCD_write(0x23); // P5 previous value + 4
LCD_write(0x7f); // P6 128 pixel screen height
LCD_write(0x20); // P7 32 char per line
LCD_write(0x00); // P8


LCD_write_cmd(0x5d); // Set cursor type
LCD_write(0x04);
LCD_write(0x86);
LCD_write_cmd(0x4d); // Set direction of cursor movement
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

