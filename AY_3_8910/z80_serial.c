/* 256X128 LCD Graphics display Hyundai #HG25504 */
/* Display Demo                                  */


#include "Hyundai_256x128.h"
#include "Z80_IO.h"
#include <z80.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void PSG_write(unsigned char address, unsigned char data);
unsigned char PSG_read(unsigned char address);
void int2ascii(unsigned int cx, char *ptr );
void system_init(void);
void delay(int j);
int token_str( void );


extern char mybuffer[];

int lcd_char_x, lcd_char_y;

int cmd_ptr;
char cmd_buff[64];

char cmd_list[4][6] = {"play","stop", "start", "set"};

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
LCD_set_cursor(0, 0);
LCD_print("Serial Test\n\0");
LCD_print(":>\0");

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
      z80_outp(0x40, 0x0d);
      //z80_outp(0x40, 0x0a);
      z80_outp(0x40, ' ');
      z80_outp(0x40, ':');
      z80_outp(0x40, '>');
      cmd_buff[cmd_ptr] = 0;
      token_str();
      LCD_print(":>\0");

      cmd_ptr = 0;
      }
      if ( c == 0x08)
      { 
      z80_outp(0x40, 0x08); 
      LCD_print_char(0x08);
      cmd_ptr--;
      cmd_buff[cmd_ptr] = ' ';
      if (cmd_ptr < 0) cmd_ptr = 0;
      }
     
    }else{
    LCD_print_char(c);
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
      LCD_print( "SIO error\n\0");
      z80_outp(0x41, 0x30);
      }
}



}


LCD_print("End\0");




return( 0 );
}    


int token_str( void )
{
char *found;
int i, n, r;
   
    found = strtok(cmd_buff," ");
    if( found==NULL)
    {
        LCD_print(cmd_buff);
        LCD_print("ERROR no input\n");
        return(1);
    }

i = 0;    
while (strcmp(found, cmd_list[i]) != 0)   
  {  
  i++;    
  if ( i > 3) break;
  }  

if ( i > 3)
    {
    LCD_print("ERROR UNKNOWN COMMAND\n");   
    return(0);
    }else{ 

LCD_print(cmd_list[i]);    
LCD_print(" \n");      
    }

if ( i == 0) 
   {        
   PSG_write(13, 0);
   return(0);
   }
    
    
    
if ( i == 3) 
   {    
   found = strtok(NULL," ");
   if( found == NULL )
    {
        LCD_print(cmd_buff);
        LCD_print("ERROR no set value\n");
        return(1);
    }
    
   r = atoi( found );
     
   found = strtok(NULL," ");
   if( found == NULL )
    {
        LCD_print(cmd_buff);
        LCD_print("ERROR no set value\n");
        return(1);
    }
    
   n = atoi( found );
          
   PSG_write(r, n);    
   }  
    
return(0);
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
char_pos_x = 0;
char_pos_y = 0;


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

