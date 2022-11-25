
/*  Serial Test                                  */

#include "Z80_IO.h"
#include <z80.h>
#include "Hyundai_256x128.h"
#include <stdlib.h>


int pio_int_a, pio_int_b;

void system_init(void);


int main()
{
     
system_init();

LCD_set_cursor(0 , 0);
LCD_print("System test\0");

z80_delay_ms(100);

z80_outp( Z80_PIO_A, 0x05);

z80_outp( 0x20, 0x07);
z80_outp( 0x20, 0x1a);
LCD_set_cursor(0 , 1);
LCD_print("CTC0 Clock set\0");

z80_outp( 0x42, 0x00);
z80_outp( 0x42, 0x18);  // reset SIO Channel A
z80_outp( 0x42, 0x04);  // WR4
z80_outp( 0x42, 0x04);  // 
z80_outp( 0x42, 0x03);
z80_outp( 0x42, 0xc1);
z80_outp( 0x42, 0x05);
z80_outp( 0x42, 0x68);







return 0;
}








void system_init(void)
{

// initialize PIO ports

z80_outp( Z80_PIO_A_CTL, Z80_PIO_M0);  // set mode 0 byte output
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






