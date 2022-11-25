/* Genric LCD Display Library for Hitachi HD44780  by Eric Stringer  */
/* eric.stringer@gmail.com  version 1.5 April 2017 */
/* using new i/o library   */

/* Bit settings for LCD Command Functions  */
#include "LCD_HD44780_LIB.h"
#include "Z80_IO.h"
#include <z80.h>
void LCD_write( unsigned char a ) 
{
// Code is for Z80 PIO driving the LCD
// This is where you would change code to write  
// to LCD via your interface configuration 
// 
LCD_busy();     
delay(10);
z80_outp( 0x02, 0x0f); // Z80PIOA_REG = 0x0f; // set mode 0 byte output
//z80_io_write( 0x01, 0x05); // Z80PIOB = 0x05;
z80_pio_write_bit(0x01, 0, 1);
z80_pio_write_bit(0x01, 1, 0);
z80_pio_write_bit(0x01, 2, 1);
z80_outp( 0x00, a );   //  Z80PIOA = a;
delay(1);
//z80_io_write( 0x01, 0x04); // Z80PIOB = 0X84;
z80_pio_write_bit(0x01, 0, 0);
z80_pio_write_bit(0x01, 1, 0);
z80_pio_write_bit(0x01, 2, 1);
LCD_busy();     
delay(20);
}

void LCD_write_cmd( unsigned char a )
{
// Code is for Z80 PIO driving the LCD
// This is where you would change code to write a command  
// to LCD via your interface configuration 
// 

LCD_busy();
delay(20);
z80_outp( 0x02, 0x0f); //Z80PIOA_REG = 0x0f; // set mode 0 byte output
z80_pio_write_bit(0x01, 0, 1); //Z80PIOB = 0x01;
z80_pio_write_bit(0x01, 1, 0);
z80_pio_write_bit(0x01, 2, 0);
z80_outp( 0x00, a);//Z80PIOA = a;
delay(1);
z80_pio_write_bit(0x01, 0, 0); //Z80PIOB = 0X00;
z80_pio_write_bit(0x01, 1, 0);
z80_pio_write_bit(0x01, 2, 0);
}

unsigned char LCD_read( void )
{
// Code is for Z80 PIO driving the LCD
// This is where you would change code to write a command  
// to LCD via your interface configuration 
//
unsigned char a;
z80_outp( 0x02, 0x4f);//Z80PIOA_REG = 0x4f; // set mode 1 byte input
//Z80PIOB = 0x06;
z80_pio_write_bit(0x01, 0, 0);
z80_pio_write_bit(0x01, 1, 1);
z80_pio_write_bit(0x01, 2, 1);
delay(20);
//Z80PIOB = 0X07;
z80_pio_write_bit(0x01, 0, 1);
z80_pio_write_bit(0x01, 1, 1);
z80_pio_write_bit(0x01, 2, 1);
delay(10);
a = z80_inp( 0x00);//Z80PIOA;
delay(10);
//Z80PIOB = 0x00;
z80_pio_write_bit(0x01, 0, 0);
z80_pio_write_bit(0x01, 1, 0);
z80_pio_write_bit(0x01, 2, 0);
return a;
}

unsigned char LCD_read_cmd( void )
{
// Code is for Z80 PIO driving the LCD
// This is where you would change code to write a command  
// to LCD via your interface configuration 
//
unsigned char a;
z80_outp( 0x02, 0x4f); //Z80PIOA_REG = 0x4f; // set mode 1 byte input
z80_pio_write_bit( 0x01, 0, 0); //Z80PIOB = 0x02;
z80_pio_write_bit( 0x01, 1, 1);
z80_pio_write_bit( 0x01, 2, 0);
delay(10);
z80_pio_write_bit(0x01, 0, 1); //Z80PIOB = 0X03;
z80_pio_write_bit(0x01, 1, 1);
delay(10);
a = z80_inp(0x00); //Z80PIOA;
delay(10);
//Z80PIOB = 0x00;
z80_pio_write_bit(0x01, 0, 0);
z80_pio_write_bit(0x01, 1, 0);
z80_pio_write_bit(0x01, 2, 0);
return a;
}
  

void LCD_busy( void )
{
unsigned char a;

a = 0x80;

while( (0x80 & a) != 0 )
  {
  a = LCD_read_cmd();
  }
//Z80PIOB = 0x00;  
}  

/* Usage start address of character on display, Character(s) to be display */
void LCD_print( unsigned char address, char *ptr ) 
{
 
LCD_write_cmd( LCD_DDRAM_ADDRESS | address);

while ( *ptr != '\0' )
{
LCD_write( *ptr++ );
}

}

char LCD_load_char( char address, unsigned char *ptr)
{
int i;

if (address > 7 ) return -1;


LCD_write_cmd( LCD_CGRAM_ADDRESS + address * 8);

for(i = 0; i < 8; i++)
{
LCD_write( *ptr++ );
}

return 1;
}



void LCD_init(void)
{

LCD_write_cmd( LCD_FUNCTION_SET | LCD_FUNCTION_SET_DATA_8BIT | LCD_FUNCTION_SET_LINES_2 | LCD_FUNCTION_SET_FONT5X7);
LCD_write_cmd( LCD_DISPLAY | LCD_DISPLAY_ON | LCD_DISPLAY_CURSOR_ON | LCD_DISPLAY_CURSOR_BLINK_OFF );
LCD_write_cmd( LCD_MODE | LCD_CUR_INC );
LCD_write_cmd( LCD_DISPLAY_CURSOR | LCD_DISPLAY_CURSOR_SHIFT );
LCD_write_cmd( LCD_CLEAR );

} 

  
