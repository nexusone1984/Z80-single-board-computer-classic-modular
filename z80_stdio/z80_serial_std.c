/* 256X128 LCD Graphics display Hyundai #HG25504 */
/* Display Demo                                  */


#include "Hyundai_256x128.h"
#include "Z80_IO.h"
#include <z80.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void int2ascii(unsigned int cx, char *ptr );
void system_init(void);
void delay(int j);
int token_str( void );

extern char mybuffer[];

char lcd_char_x, lcd_char_y;

int cmd_ptr;
char cmd_buff[32];

void delay(int j)
{
int i;
for(i=0; i<j; i++);
}


int main()
{
int x, q ,z, cmd_ptr ;
char c, s, serror;



system_init();
printf("Serial Test\n");
printf(":>");

x = 1;
q = 0;
z = 1;
cmd_ptr = 0;

while( x != 0)
{

    
if ((z == 0) && ( q == 1)) 
{
 z80_outp( 0x42, 0x05);
 z80_outp( 0x42, 0x6A);
 q = 0;
}

if ((z == 0x08) && ( q == 0))
{   
 z80_outp( 0x42, 0x05);
 z80_outp( 0x42, 0x68);  
 q = 1;
}
 

s = z80_inp(0x42) & 0x01;
//printf("status =  %x\n", s);

if (s == 1)
  {
  c = z80_inp(0x40);
  
  z80_outp(0x42, 0x01);
  serror = z80_inp(0x42);
  serror = serror & 0x70;
  if(serror ==  0)
  {
  if (c < 32) 
    {
    if ( c == 0x0d)
      { 
      z80_outp(0x40, 0x0a); 
      z80_outp(0x40, 0x0d);
      z80_outp(0x40, ':');
      z80_outp(0x40, '>');
      cmd_buff[cmd_ptr] = 0;
      printf(" \n");
      token_str();
      printf("\n:>");

      cmd_ptr = 0;
      }
      if ( c == 0x08)
      { 
      z80_outp(0x40, 0x08); 
      putchar('\b');
      cmd_ptr--;
      if (cmd_ptr < 0) cmd_ptr = 0;
      }
     
    }else{
    putchar(c);
    z80_outp(0x40, c);
    cmd_buff[cmd_ptr] = c;
    cmd_ptr++;
    if (cmd_ptr > 31) 
      {
      token_str();
      cmd_ptr = 0;
      }
    } 
  
  } else {
      printf("Error =  %x\n", serror);
      z80_outp(0x41, 0x30);
      }
}



}


printf("End");




return( 0 );
}    


int token_str( void )
{
char *found;

    printf("Original string: '%s'\n",cmd_buff);

    found = strtok(cmd_buff," ");
    if( found==NULL)
    {
        printf("\t'%s'\n",cmd_buff);
        puts("\tNo separators found");
        return(1);
    }
    while(found)
    {
        printf("\t'%s'\n",found);
        found = strtok(NULL," ");
    }

    return(0);
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

