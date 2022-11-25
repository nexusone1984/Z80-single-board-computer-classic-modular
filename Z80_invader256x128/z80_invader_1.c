
/*  Demo PIO                                  */

#include "spritdata.h"
#include "Z80_IO.h"
#include <z80.h>
#include "Hyundai_256x128.h"
#include <stdlib.h>


void system_init(void);
void int2ascii(unsigned int cx, char *ptr );

unsigned char name[2][9] = { " SPACE  ", "INVADERS" };


int main()
{
int a,s,i,k, d;
char data[20];

system_init();

LCD_set_cursor(3 , 0);
LCD_print("SCORE<1> HI-SCORE SCORE<2>\0");

LCD_set_cursor(3 , 1);
LCD_print("00000    00000\0");

LCD_set_cursor(10 , 6);
LCD_print("GAME OVER\0");


k = 1;
a = 4;
i = 0;
d = 0;

while( i != 3000)
{

for(s = 0; s < 11; s++)
   {    
   for(i = 0; i < 16; i=i+2)
     {
     
     if ((d == 0) && (s == 0))
        {
         LCD_set_graphics_cursor((a+s*2)-1, i/2+24);
         LCD_write_cmd(0x42);   
         LCD_write(sprit_data[0][i]);
        }else{
        LCD_set_graphics_cursor(a+s*2, i/2+24);
        LCD_write_cmd(0x42);
        } 
              
     LCD_write(sprit_data[k][i]);
     LCD_write(sprit_data[k][i+1]);
     if ((d == 1) && (s == 10)) LCD_write(sprit_data[0][i]);
     }
    }

for(s = 0; s < 11; s++)
   {    
   for(i = 0; i < 16; i=i+2)
     {
     
     if ((d == 0) && (s == 0))
        {
         LCD_set_graphics_cursor((a+s*2)-1, i/2+36);
         LCD_write_cmd(0x42);   
         LCD_write(sprit_data[0][i]);
        }else{
        LCD_set_graphics_cursor(a+s*2, i/2+36);
        LCD_write_cmd(0x42);
        } 
              
     LCD_write(sprit_data[k+6][i]);
     LCD_write(sprit_data[k+6][i+1]);
     if ((d == 1) && (s == 10)) LCD_write(sprit_data[0][i]);
     }
    }    

for(s = 0; s < 11; s++)
   {    
   for(i = 0; i < 16; i=i+2)
     {
     
     if ((d == 0) && (s == 0))
        {
         LCD_set_graphics_cursor((a+s*2)-1, i/2+48);
         LCD_write_cmd(0x42);   
         LCD_write(sprit_data[0][i]);
        }else{
        LCD_set_graphics_cursor(a+s*2, i/2+48);
        LCD_write_cmd(0x42);
        } 
              
     LCD_write(sprit_data[k+6][i]);
     LCD_write(sprit_data[k+6][i+1]);
     if ((d == 1) && (s == 10)) LCD_write(sprit_data[0][i]);
     }
    }        

for(s = 0; s < 11; s++)
   {    
   for(i = 0; i < 16; i=i+2)
     {
     
     if ((d == 0) && (s == 0))
        {
         LCD_set_graphics_cursor((a+s*2)-1, i/2+62);
         LCD_write_cmd(0x42);   
         LCD_write(sprit_data[0][i]);
        }else{
        LCD_set_graphics_cursor(a+s*2, i/2+62);
        LCD_write_cmd(0x42);
        } 
              
     LCD_write(sprit_data[k+12][i]);
     LCD_write(sprit_data[k+12][i+1]);
     if ((d == 1) && (s == 10)) LCD_write(sprit_data[0][i]);
     }
    }     
    
for(s = 0; s < 11; s++)
   {    
   for(i = 0; i < 16; i=i+2)
     {
     
     if ((d == 0) && (s == 0))
        {
         LCD_set_graphics_cursor((a+s*2)-1, i/2+76);
         LCD_write_cmd(0x42);   
         LCD_write(sprit_data[0][i]);
        }else{
        LCD_set_graphics_cursor(a+s*2, i/2+76);
        LCD_write_cmd(0x42);
        } 
              
     LCD_write(sprit_data[k+12][i]);
     LCD_write(sprit_data[k+12][i+1]);
     if ((d == 1) && (s == 10)) LCD_write(sprit_data[0][i]);
     }
    }    
    
    
if (d == 0 )
   {
   k++; 
   if (k > 6) 
      {
      a++;
      k = 1;
      } 
   }
    
if (d == 1 )
   {
   k--;
   if (k < 1)   
      {
      a--;
      k = 6;
      }
   }  
   
if (a > 8) d = 1;
if (a < 2) d = 0;

    
z80_delay_ms(400);


}

LCD_set_cursor(0 , 0);
LCD_print("Exit\0");
z80_delay_ms(60000);

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




