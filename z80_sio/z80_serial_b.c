/* 256X128 LCD Graphics display Hyundai #HG25504 */
/* Display Demo                                  */


#include "Hyundai_256x128.h"
#include "Z80_IO.h"
#include <z80.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void int2ascii(unsigned int cx, char *ptr );
void int2hex( int n, char *outbuf);
void system_init(void);
void delay(int j);


int lcd_char_x, lcd_char_y;

int cmd_ptr;


void delay(int j)
{
int i;
for(i=0; i<j; i++);
}


int main()
{
int x, s, c;
char data[20];



system_init();
LCD_set_cursor(0, 0);
LCD_print("Serial Test B\n\0");


while( x != 0)
{



s = z80_inp(0x43) & 0x01;
//printf("status =  %x\n", s);

if (s == 1)
  {
  c = z80_inp(0x41);
  int2hex( c, data);
  LCD_print(data);
  LCD_print(",");
  }

}


LCD_print("End\0");




return( 0 );
}    




void system_init(void)
{

// initialize PIO ports

z80_outp( Z80_PIO_A_CTL, Z80_PIO_M0);  // set mode 1 byte output
z80_outp( Z80_PIO_B_CTL, Z80_PIO_M0);  // set mode 3 bit in/out mode mask select


// initialize SIO port A CLK 1X 8N1
z80_outp( 0x42, 0x00);
z80_outp( 0x42, 0x18);  // reset SIO Channel A
z80_outp( 0x42, 0x01);
z80_outp( 0x42, 0x00);
z80_outp( 0x42, 0x04);  // WR4
z80_outp( 0x42, 0xC4);  // X64 clock
z80_outp( 0x42, 0x03);
z80_outp( 0x42, 0xc1);
z80_outp( 0x42, 0x05);
z80_outp( 0x42, 0x68);

// initialize SIO port B CLK 1X 8O1
z80_outp( 0x43, 0x00);
z80_outp( 0x43, 0x18);  // reset SIO Channel A
z80_outp( 0x43, 0x01);
z80_outp( 0x43, 0x00);
z80_outp( 0x43, 0x04);  // WR4
z80_outp( 0x43, 0x05);  // X1 clock
z80_outp( 0x43, 0x03);
z80_outp( 0x43, 0xc1);
z80_outp( 0x43, 0x05);
z80_outp( 0x43, 0x68);


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
char_pos_x = 0;
char_pos_y = 0;


}

void int2hex( int num, char *ptr)
{
char hex[16]= {"0123456789ABCDEF"};
int temp;

ptr = ptr + 4;
*ptr-- = '\0';
temp = num & 0x0f;
*ptr-- = hex[temp];
temp = num >> 4;
*ptr-- = hex[temp];
*ptr-- = 'x';
*ptr-- = '0';
    
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

