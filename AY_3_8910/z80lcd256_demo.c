/* 256X128 LCD Graphics display Hyundai #HG25504 */
/* Display Demo                                  */


#include "Hyundai_256x128.h"
#include "Z80_IO.h"
#include <z80.h>
#include <stdlib.h>

void int2ascii(unsigned int cx, char *ptr );
void Button_press(void);
void system_init(void);
void demo_intro(void);
void demo_character_set(void);
void LCD_load_Char(void);
void demo_graphics( void );
void demo_graphics_1( void );

int SYS_terminal_pos;
char SYS_terminal_buf[16][32];


void delay(int j)
{
int i;
for(i=0; i<j; i++);
}


int main()
{

system_init();

//LCD_load_Char();



demo_intro();

Button_press();

demo_character_set();

delay(100);
Button_press();

demo_graphics();

Button_press();

demo_graphics_1( );

delay(100);



return 0;
}

void demo_intro(void)
{
 
LCD_set_cursor(8, 6);
LCD_print( "Hyundai HG25504\n" );

LCD_set_cursor(3, 7);
LCD_print( "256 X 128 Graphics Display\n" );
LCD_set_cursor(6, 8);
LCD_print( "From All Electronics\n");
LCD_set_cursor(0, 15);
LCD_print( ">Press Button to continue!\n");
}

void demo_character_set(void)
{
int i;
LCD_clear();
LCD_graphics_clear();
LCD_set_cursor(0, 0);
LCD_print( "Character Set (ASCII ):\n");
for(i = 0; i < 96; i++)
  {
    LCD_print_char(0x20+i);
  }

LCD_set_cursor(0, 7);
LCD_print( "Character Set (Chinese) :\n");  
for(i = 0; i < 64; i++)
  {
    LCD_print_char(0xA0+i);
  }  
  
LCD_set_cursor(0, 15);
LCD_print( ">Press Button to continue!\n");  
  
}

void demo_graphics_1( void )
{
LCD_clear();
LCD_graphics_clear();
LCD_set_cursor(1, 1);
LCD_print( "Text and Graphics Demo 1\n");  

LCD_draw_line(0, 0, 255, 0, 1);
LCD_draw_line(255, 0, 255, 127, 1);
LCD_draw_line(255, 127, 0, 127, 1);
LCD_draw_line(0, 127, 0, 0, 1);

}



void demo_graphics( void )
{
 
char LCD_buf[8], a;
int port_b, button_state, ff, x1[9], y1[9], x2[9], y2[9];
int x1_dir, x2_dir, y1_dir, y2_dir;
unsigned int count, count_alt, count_delay;
    
button_state = 1;
ff = 0;
count = 1;
count_alt = 0;
x1[0] = 10;
y1[0] = 10;
x1[1] = 9;
y1[1] = 9;
x2[0] = 40;
y2[0] = 40;
x2[1] = 19;
y2[1] = 19;

x1_dir = 1;
x2_dir = -1;
y1_dir = -1;
y2_dir = 1;

count_delay = 0;

LCD_clear();
LCD_graphics_clear();

// z80_io_read
while( z80_inp(0x00) != 0xcc)
{
port_b = z80_inp( 0x01 ); //Z80PIOB;
  
if ((port_b & 0b00001000) == 0) 
   {
   button_state = 0;
   } else {
   button_state = 1;
   }

if ((port_b & 0b00010000) == 0) count++;
    
if ((port_b & 0b00100000) == 0) count--;      
   
   
   
 if (ff == button_state) 
 {
  LCD_set_cursor(0 , 14);
  LCD_print("Button Pressed!\0");
  ff = 1;
  LCD_graphics_clear();
  }

if (ff == button_state)
  {
  LCD_set_cursor(0 , 14);
  LCD_print( "Button Released!\0");
  ff = 0;
  }     

if (count != count_alt) 
{
int2ascii(count, LCD_buf);
LCD_set_cursor(0 , 15);
LCD_print( LCD_buf );
count_alt = count;
}
    
count_delay++;

if (count_delay > 100)
 { 

LCD_draw_line(x1[3], y1[3], x2[3], y2[3], 0);
for(a = 3; a > 0; a--)
{
x1[a] = x1[a-1];
x2[a] = x2[a-1];
y1[a] = y1[a-1];
y2[a] = y2[a-1];
}

 x1[0] = x1[0] + x1_dir; 
 x2[0] = x2[0] + x2_dir;
 y1[0] = y1[0] + y1_dir;
 y2[0] = y2[0] + y2_dir;
 LCD_draw_line(x1[0], y1[0], x2[0], y2[0], 1);
 count_delay = 0;
 int2ascii(x1[0], LCD_buf);
LCD_set_cursor(0 , 12);
LCD_print( "x1:\0");
LCD_print( LCD_buf );
int2ascii(x2[0], LCD_buf);
LCD_set_cursor(0 , 13);
LCD_print( "x2:\0");
LCD_print( LCD_buf );
 
 }

if ( x1[0] >= 254 )  x1_dir = -1;

if ( x1[0] <= 0 ) x1_dir = 1;

if ( x2[0] >= 255 ) x2_dir = -1;

if ( x2[0] <= 0 ) x2_dir = 1;

if ( y1[0] >= 127 ) y1_dir = -1;

if ( y1[0] <= 0 ) y1_dir = 1;

if ( y2[0] >= 127 ) y2_dir = -1;

if ( y2[0] <= 0 ) y2_dir = 1;



}

}


void LCD_load_Char(void)
{
unsigned char chardata[6][8] = {{ 0x11,0xa,0x4,0xe,0x15,0x15,0xe,0x0}, {0x0,0x4,0xe,0x1f,0x15,0x1f,0xe,0xe}, {0x4,0x3,0xd,0x1f,0x17,0x14,0x2}, {0x4,0x18,0x14,0x1f,0x1d,0x5,0x8},{0x4,0x13,0x15,0x1f,0x7,0x4,0x8},{0x4,0x19,0x15,0x1f,0x1c,0x4,0x2}};

int x,y;

LCD_write_cmd(0x5c);
LCD_write(0x00);
LCD_write(0x40);
LCD_write_cmd(0x4c);
LCD_write_cmd( 0x46); // Set cursor address
LCD_write(0x00);
LCD_write(0x48);
LCD_write_cmd( 0x42 );
for(y = 0; y < 6; y++)
  { 
  for(x = 0; x < 8; x++)
    {
    LCD_write( chardata[y][x] );
    }
  }
    
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

