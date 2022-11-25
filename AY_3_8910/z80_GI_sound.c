/* AY-3-8910 Sound Generator */
/* 2020                                 */


#include "Hyundai_256x128.h"
#include "Z80_IO.h"
#include <z80.h>
#include <stdlib.h>

void int2ascii(unsigned int cx, char *ptr );
void LCD_load_Char(void);
void system_init(void);

void PSG_write(unsigned char address, unsigned char data);
unsigned char PSG_read(unsigned char address);


void delay(int j)
{
int i;
for(i=0; i<j; i++);
}


int main()
{
char data[20];    
int i;
system_init();
i = 0;
LCD_set_cursor(0, 0);
LCD_print( "AY-3-8910 \n" );
LCD_set_cursor(0, 1);
LCD_print( "Sound effect Gunshot \n" );



// Reset PSG
z80_outp( Z80_PIO_B, 0x00);
delay(100);
z80_outp( Z80_PIO_B, 0x08);



while (i != 10)
{
i = z80_inp(Z80_PIO_A);    

PSG_write(6, 0x0f);
PSG_write(7, 0x07);


PSG_write(0x08, 0x10);
PSG_write(0x09, 0x10);
PSG_write(0x0a, 0x10);
PSG_write(0x0c, 0x10);
PSG_write(0x0d, 0x00);


delay(30000);
delay(30000);
delay(30000);

PSG_write(0x06, 0x0f);
PSG_write(0x08, 0x10);
PSG_write(0x09, 0x10);
PSG_write(0x0a, 0x10);
PSG_write(0x0c, 0x38);
PSG_write(0x0d, 0x00);
delay(30000);
delay(30000);
delay(30000);

}


LCD_set_cursor(0, 10);
LCD_print( "Exit program \n" );
return 0;
}


void PSG_write(unsigned char address, unsigned char data)

{
// setup Z80_PIO_A_CLT to output
z80_outp( Z80_PIO_A_CTL, Z80_PIO_M0);
z80_outp( Z80_PIO_A, address & 0x0f );
// Latch address
z80_outp( Z80_PIO_B, 0x0f);
// Setup to write data
z80_outp( Z80_PIO_B, 0x08);
z80_outp( Z80_PIO_A, data);
// Write Data
z80_outp( Z80_PIO_B, 0x0e);
z80_outp( Z80_PIO_B, 0x08);
// setup Z80_PIO_A_CLT back to input just to be safe
z80_outp( Z80_PIO_A_CTL, Z80_PIO_M1);
   
} 

unsigned char PSG_read(unsigned char address)
{
unsigned char data;
// setup Z80_PIO_A_CLT to output
z80_outp( Z80_PIO_A_CTL, Z80_PIO_M0);
z80_outp( Z80_PIO_A, address & 0x0f );
// Latch address
z80_outp( Z80_PIO_B, 0x0f);
// Setup to read data
z80_outp( Z80_PIO_B, 0x08);
// Z80 PIO as input
z80_outp( Z80_PIO_A_CTL, Z80_PIO_M1);

z80_outp( Z80_PIO_B, 0x0b);
data = z80_inp(Z80_PIO_A);

// Setup to read data
z80_outp( Z80_PIO_B, 0x08);
// Z80 PIO as input
z80_outp( Z80_PIO_A_CTL, Z80_PIO_M1);

    
return data;     
}    




void system_init(void)
{

// initialize PIO ports

z80_outp( Z80_PIO_A_CTL, Z80_PIO_M1);  // set mode 1 byte output
z80_outp( Z80_PIO_B_CTL, Z80_PIO_M0);  // set mode 0 output mode 
z80_outp( Z80_PIO_B, 0x00);

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

