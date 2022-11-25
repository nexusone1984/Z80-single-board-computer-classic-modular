/* 256X128 LCD Graphics display Hyundai #HG25504 */
/* Display Demo                                  */


#include "Hyundai_256x128.h"
#include "z80_pio.h"
#include "ps2_keyboard.h"
#include <z80.h>
#include <stdlib.h>
#include <ctype.h>


void int2ascii(unsigned int cx, char *ptr );
void int2hex( int n, char *outbuf);
void system_init(void);
void Button_press(void);
char kbd_char_bf(void);

int pio_int_a = 0, pio_int_b = 0, int_38 = 0, add_isr = 0 , kbd_tmp = 0;
char  kbd_bit=0; 

char kbd_buffer[16], kbd_char, kbd_up = 0, kbd_clt = 0, kbd_last_char[4], kbd_ptr = 0 , kbd = 0;

char shift_r = 0, shift_l = 0, shift_active = 0;

void delay(int j)
{
int i;
for(i=0; i<j; i++);
}


int main()
{

char a, b, data[10], data2[11];    
int x, s, int_38_count = 0, port_a = 0, port_b = 0, couter_1 = 0, pio_a_couter = 0, pio_b_couter = 0, alt, k[4] ;

data2[10] = 0;

system_init();

LCD_set_cursor(0 , 0);


for(x=0;x<76;x++)
{
ps2_keyboard_state[x] = 0;
}

LCD_clear();
LCD_set_cursor(0 , 0);
LCD_print("PS/2 Keyboard test\0");
kbd_tmp = 0;

while( port_b != 0xcc)
{
s = 0;

while(s == 0)
  {
  s = z80_inp(0x43) & 0x01;
  };


a = z80_inp(0x41); 
x = 0;
b = 0;

while( (a != ps2_table[x]) && (x < 76)) x++;

if (x <= 76) 
{

    if (shift_active == 0) 
    {
    b =  ps2_ascii_lower[x];
    }else{
    b =  ps2_ascii_upper[x];    
    }    
    
    if( ( kbd_up == 1 ) && (ps2_keyboard_state[x] == 1))
    {
        ps2_keyboard_state[x] = 0;
        kbd_up = 0;
        b = 0;
        }else{
    ps2_keyboard_state[x] = 1;
    }
    
}else{
    b = 0;
}


LCD_set_cursor(0 , 3);   
LCD_print( "Keyboard buffer to ascii =\0");  
LCD_print_char(b);   

 
}

  
LCD_print("END \0");

z80_outp( Z80_PIO_B, 0x3f);

return 0;
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

//z80_outp( Z80_PIO_A_CTL, Z80_PIO_M0);  // set mode 0 byte out
//z80_outp( Z80_PIO_B_CTL, Z80_PIO_M3);  // set mode 3 bit in/out mode mask select
//z80_outp( Z80_PIO_B_CTL, 0xcf);  // bit's 0-3 and 6&7 inputs, 4&5 outputs. 


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

