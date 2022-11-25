/* 256X128 LCD Graphics display Hyundai #HG25504 */
/* Display Demo                                  */


#include "Hyundai_256x128.h"
#include "Z80_IO.h"
#include "ps2_keyboard.h"
#include <z80.h>
#include <stdlib.h>
#include <ctype.h>

extern void isr_pio_0_a(void);
extern void isr_pio_0_b(void);
extern int vid_pio_0_a;
extern int vid_pio_0_b;

void int2ascii(unsigned int cx, char *ptr );
void system_init(void);
void Button_press(void);
char kbd_char_bf(void);

int pio_int_a = 0, pio_int_b = 0, int_38 = 0, add_isr = 0 , kbd_tmp = 0;
char  kbd_bit=0; 

char kbd_buffer[16], kbd_char, kbd_up = 0, kbd_clt = 0, kbd_last_char = 0, kbd_ptr = 0 , kbd = 0;

char shift_r = 0, shift_l = 0, shift_active = 0;

void delay(int j)
{
int i;
for(i=0; i<j; i++);
}


int main()
{

char a, data[10], data2[11];    
int x, int_38_count = 0, port_a = 0, port_b = 0, couter_1 = 0, pio_a_couter = 0, pio_b_couter = 0, alt, k[4] ;

data2[10] = 0;

system_init();

LCD_set_cursor(0 , 0);
LCD_print("Interrupt test\0");
z80_outp( Z80_PIO_A_CTL, Z80_PIO_DI);
z80_outp( Z80_PIO_B_CTL, Z80_PIO_DI);

/*
__asm
     ld	hl, _vid_pio_0_a
	 ld	(_add_isr),hl
     im 1
     ei

__endasm;

*/
//z80_outp( Z80_PIO_A_CTL, Z80_PIO_EI);


// set up Z80 PIO vector interrupts 

__asm
     di
     ld hl, _vid_pio_0_a
     ld a, l
     out (0x02), a
     ld hl, _vid_pio_0_b
     ld a, l
     out (0x03), a
     //ld a, h
     //ld i, a
     im 2
     ei
__endasm;

for(x=0;x<76;x++)
{
ps2_keyboard_state[x] = 0;
}

LCD_clear();
LCD_set_cursor(0 , 0);
LCD_print("PS/2 Keyboard test\0");
kbd_tmp = 0;
pio_int_b = 0;
kbd_bit = 0;
alt = 0;
port_b = z80_inp( Z80_PIO_B ); //Z80 PIO port B;
z80_outp( Z80_PIO_B, 0x1f);
__asm
    di
__endasm;
z80_outp( Z80_PIO_B_CTL, Z80_PIO_EI | Z80_PIO_EI_MF | Z80_PIO_EI_LOW |Z80_PIO_EI_AND ); // interrupt with mask 0x97
z80_outp( Z80_PIO_B_CTL, 0x7f); // monitor port bit 2 0x3f
__asm
    ei
__endasm;

delay(100);

z80_outp( Z80_PIO_B, 0x3f);



while( port_b != 0xcc)
{

    

    
a = kbd_char_bf(); 

if( a != 0 )
{ 
    LCD_set_cursor(0 , 1);   
    LCD_print( "Keyboard =\0");
    int2ascii( kbd_last_char, data);
    LCD_print( data );
    int2ascii( kbd, data);
    LCD_print( data );
    LCD_set_cursor(0 , 2);   
    LCD_print( "Keyboard buffer =\0");
    int2ascii( kbd_ptr, data);
    LCD_print( data );
kbd_last_char = kbd;
   LCD_set_cursor(0 , 3);   
   LCD_print( "Keyboard buffer to ascii =\0");  
   LCD_print_char(a);   
   LCD_set_cursor(0 , 5);
   
   LCD_print("`1234567890-=BS \0");
   LCD_set_cursor(0 , 6);
   for(x=1; x<15; x++)
      {
      if(ps2_keyboard_state[x] == 1)
        {
        LCD_print_char('^');
       }else{
       LCD_print_char(' ');
       }
      }
   
   LCD_set_cursor(0 , 7);
   LCD_print("qwertyuiop[] \0");
   LCD_set_cursor(0 , 8);
   for(x=15; x<30; x++)
      {
      if(ps2_keyboard_state[x] == 1)
      {
      LCD_print_char('^');
      }else{
      LCD_print_char(' ');
      }
      }
      
   LCD_set_cursor(0 , 9);
   LCD_print("asdfghjkl;'ENT\0");
   LCD_set_cursor(0 , 10);
   for(x=30; x<45; x++)
      {
      if(ps2_keyboard_state[x] == 1)
        {
        LCD_print_char('^');
        }else{
        LCD_print_char(' ');
      }
      }
      
   LCD_set_cursor(0 , 11);
   LCD_print(" zxcvbnm,./ \0");
   LCD_set_cursor(0 , 12);
   for(x=44; x<59; x++)
      {
      if(ps2_keyboard_state[x] == 1)
       {
       LCD_print_char('^');
       }else{
       LCD_print_char(' ');
       }
      }
     
data2[9]= a;   
LCD_set_cursor(0 , 13);
LCD_print( data2 );
 
 for(x = 0; x < 9; x++)
  {
  data2[x] = data2[x+1];
  } 
   

      
 alt = a;
}
 
 
}

  


z80_outp( Z80_PIO_B, 0x3f);

return 0;
}


char kbd_char_bf(void)
{
int x;
char a, b;
__asm
di
__endasm;

a = kbd_buffer[0];
b = a;
x = 0;


if( kbd_buffer[0] == 0) goto kbd_buff_exit;  // Nothing in buffer to print.

if (a == 0xf0)
{
    kbd_up = 1; // Next data is which key released. 
    goto kbd_buff_exit;
}

if (a == 0xe0)
{
     goto kbd_buff_exit;
}

// Controll keys

// Shift active?

if ( b == 0x12 )
{
    if (kbd_up == 1)
    {
     shift_l = 0;  
    }else{
     shift_l = 1;    
    }
}


if ( b == 0x59 )
{
    if (kbd_up == 1)
    {
     shift_r = 0;  
    }else{
     shift_r = 1;    
    }
}


shift_active = shift_l || shift_r;




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
        goto kbd_buff_exit;
    }else{
    ps2_keyboard_state[x] = 1;
    }
    
}else{
    b = 0;
}


if (isascii(b) != 1) b = '*';

kbd_buff_exit:

for(x = 0; x < kbd_ptr; x++)
  {
  kbd_buffer[x] = kbd_buffer[x+1];
  }
if (kbd_ptr == 0) kbd_buffer[0] = 0;
  
if (kbd_ptr != 0)  kbd_ptr-- ;



__asm
ei
__endasm;
   
return b;    
}



void z80_rst_38h(void) __naked
{
   __asm

      push ix
      push hl
      di
      ld	hl,0x0001
	  ld	(_int_38),hl
	  //ld	hl,_int_38 + 1
	  pop hl
      pop ix
      ei
      reti

   __endasm;
}


void isr_pio_0_a(void) __naked
{
__asm  
   ld	hl, 0x0001 ;(ix + 1)
   ld	(_pio_int_a),hl
   ei
   reti
__endasm;   
    
   
    
}


void isr_pio_0_b(void) __naked
{
   
__asm
     di
     ; reset keyboard to restart send of last data sent
     ; Z80 PIO port B is set to bit 6 and 7 inputs and 4 and 5 out.
     ; Bit 5  turns on Transistor pulling Clock line low. 
   	  
     push ix
     push hl
     push af
     push bc
     push de
     ld a, 0x1f  ; 
     out (0x01), a ; bring Clock line low      
     ld	hl,0x0064
	 call	_delay ; Delay 100 ms to initiate resend
     ld a, 0x3f ; release keyboard bring Clock line high 
     out (0x01), a        
     
     ld a, 0x01 ;debug line turn on LED on port A
     out (0x00), a
     ld bc, 0x0000 ; initialize keyboard data
     ld e, 0x00 ; initialize clock count 
start_byte:     ; Not to confuse by name, but we return here for each bit. 
     ld a, e  ; 
     cp 0x0b ; have we processed 11 bits. 
     jp Z, exit_kbd
check_input: 
     in a, (0x01)
     bit 7, a
     jp NZ, check_input ; looking for clock low. 
     bit 6, a  ; data one or zero check
     jp Z, bit_zero
     set 3, b
     srl b
     rr c
     jp bit_end
bit_zero:
     res 3, b
     srl b
     rr c
bit_end:  
     inc e ; increase bit count
check_input_1: ;here wait for clock state to change. 
     in a, (0x01)
     bit 7, a
     jp Z, check_input_1
     jp start_byte
exit_kbd: ;process byte
     ld (_kbd_tmp), bc ; RAW input data from keyboard
     srl b ; remove start bit and create a 8 bit keyboard data.
     rr c
     ld a, c
     ld (_kbd), a 
     ld hl, _kbd_ptr ; this is for our keyboard buffer if program
                     ; has not read the keyboard data
     ld e, (hl)  ; Where are we in buffer.
     ld a, e
     cp 0x0f ; have we reached end check
     jp Z, buffer_full
     ld d, 0x00   
     ld hl, _kbd_buffer 
     add hl, de
     ld a, c
     ld (hl), a
     ld hl, _kbd_ptr
     inc e
     ld	(hl), e
buffer_full: 
     ld a, 0x00 ; Turn off Debug LED
     out (0x00), a
     pop de
     pop bc
	 pop af
	 pop hl
     pop ix
     ei
     reti 


     
     
 __endasm;
 
/* 
__asm  
   ld	hl, 0x0001 ;(ix + 1)
   ld	(_pio_int_b),hl
   ei
   reti
__endasm;
*/    

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

z80_outp( Z80_PIO_A_CTL, Z80_PIO_M0);  // set mode 0 byte out
z80_outp( Z80_PIO_B_CTL, Z80_PIO_M3);  // set mode 3 bit in/out mode mask select
z80_outp( Z80_PIO_B_CTL, 0xcf);  // bit's 0-3 and 6&7 inputs, 4&5 outputs. 





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

