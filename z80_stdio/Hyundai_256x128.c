/* Hyundai_256x128.c
  256 X 128 LCD Grapics display Hyundai #HG25504  
  sold by All Electronics.
  By Eric Stringer 2017
*/


#include "Hyundai_256x128.h"
#include "Z80_IO.h"
#include <z80.h>
#include <stdlib.h>


void LCD_write_cmd( unsigned char a )
{
// Code is for Z80 LCD at address 0x20
// This is where you would change code to write a command  
// to LCD via your interface configuration 
// 

//delay(20);

z80_outp( 0x61, a); //LCD address ;

}

void LCD_write( unsigned char a ) 
{
// Code is for Z80 LCD at address 0x20
// This is where you would change code to write  
// to LCD via your interface configuration 
// 
 
//delay(10);

z80_outp( 0x60, a );   //  LCD address;

}

unsigned char LCD_read_data( void ) 
{
unsigned char a;    
// Code is for Z80 LCD at address 0x20
// This is where you would change code to write  
// to LCD via your interface configuration 
// 
 
LCD_write_cmd( 0x43 );
a = z80_inp(0x61);  // LCD address ;


return a;
}

unsigned char LCD_read_flag( void ) 
{
unsigned char a;    
// Code is for Z80 LCD at address 0x20
// This is where you would change code to write  
// to LCD via your interface configuration 
// 
 

a = z80_inp(0x60);  // LCD address ;

return a;
}



void LCD_clear(void)
{
int i; 

LCD_write_cmd(0x46); // set the cursor addr
LCD_write(0x00);
LCD_write(0x00);
LCD_write_cmd(0x4c);
LCD_write_cmd(0x42);
 
for (i=0; i<1024; i++)
{
LCD_write(0x20); // write blank spaces
}
 
LCD_write_cmd(0x46);
LCD_write(0x00);
LCD_write(0x00);
}

void LCD_graphics_clear(void)
{
int i; 

LCD_write_cmd(0x46); // set the cursor addr
LCD_write(0xb0);
LCD_write(0x04);
LCD_write_cmd(0x4c);
LCD_write_cmd(0x42);
 
for (i=0; i<0x1000; i++)
{
LCD_write(0x00); // write blank spaces
}
 
LCD_write_cmd(0x46);
LCD_write(0x00);
LCD_write(0x00);
}

void LCD_print_char( char a ) 
{
 
LCD_write_cmd(0x42);  
LCD_write( a );

}



void LCD_print( char *ptr ) 
{
 
LCD_write_cmd(0x42);  
while ( *ptr != '\0' )
{
LCD_write( *ptr++ );
}

}

void LCD_set_cursor(char col, char row)
{
char lowadd, hiadd; 
int t_add;

// our display 32 X 24
// text display starts at 0x0000

t_add = row * 32 + col;
lowadd = t_add & 0x00ff;
hiadd = t_add >> 8;

LCD_write_cmd(0x46); // Set cursor address
LCD_write(lowadd);
LCD_write(hiadd);
    
}

void LCD_set_graphics_cursor(char col, char row)
{
char lowadd, hiadd; 
int t_add;

// our display 32 X 24
// text display starts at 0x0000

t_add = (row * 32 + col) + 0x04b0;
lowadd = t_add & 0x00ff;
hiadd = t_add >> 8;

LCD_write_cmd(0x46); // Set cursor address
LCD_write(lowadd);
LCD_write(hiadd);
    
}


void LCD_pixel(int x, int y, char bit)
{
int row, col, data, t;

col = x >> 3;
row = y;
LCD_set_graphics_cursor( col, row);
t = LCD_read_data( );

if (bit == 0) 
    {
                 //   mask     ^   data
        data = ~(0x80 >> (x%8)) & t;
    }
    else
    {   
                 //   mask     |   data
        data = (0x80 >> (x%8)) | t;
    }
    
LCD_set_graphics_cursor( col, row);
LCD_write_cmd(0x42);
LCD_write( data );
}

void LCD_draw_line(int x0, int y0, int x1, int y1, char bit)
{
int sx, sy, dx, dy, err, e2;    
    
dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
err = (dx>dy ? dx : -dy)/2, e2;
 
  for(;;){
    LCD_pixel(x0,y0, bit);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}
