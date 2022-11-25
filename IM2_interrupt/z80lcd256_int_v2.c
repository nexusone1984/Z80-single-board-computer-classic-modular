/* 256X128 LCD Graphics display Hyundai #HG25504 */
/* Display Demo                                  */


#include "Hyundai_256x128.h"
#include "Z80_IO.h"
#include <z80.h>
#include <stdlib.h>

extern void isr_ctc_0(void);
extern void isr_ctc_1(void);
extern void isr_ctc_2(void);
extern void isr_ctc_3(void);

extern void isr_pio_0_a(void);
extern void isr_pio_0_b(void);


void int2ascii(unsigned int cx, char *ptr );
void system_init(void);
void Button_press(void);


int pio_int_a = 0, pio_int_b = 0, int_38 = 0, add_isr = 0; 

int ctc0_int_0 = 0, ctc0_int_1 = 0, ctc0_int_2 = 0, ctc0_int_3 = 0;



void delay(int j)
{
int i;
for(i=0; i<j; i++);
}


int main()
{

char a, data[10];    
int int_38_count = 0, port_b = 0, couter_1 = 0, ctc0_couter0 = 0,ctc0_couter1 = 0,ctc0_couter2 = 0,ctc0_couter3 = 0, pio_a_couter = 0, pio_b_couter = 0;     
system_init();

LCD_set_cursor(0 , 0);
LCD_print("Interrupt test\0");
z80_outp( Z80_PIO_A_CTL, Z80_PIO_DI);
z80_outp( Z80_PIO_B_CTL, Z80_PIO_DI);


__asm
     ld	hl, (0x100)
	 ld	(_add_isr),hl
	 ld a, 0x01
     ld i, a
     im 2
     ei

__endasm;

z80_outp( 0x20, 0x00);
z80_outp( 0x20, 0xc7);
z80_outp( 0x20, 0xff);

z80_outp( 0x21, 0x00);
z80_outp( 0x21, 0xc7);
z80_outp( 0x21, 0xff);

z80_outp( 0x22, 0x00);
z80_outp( 0x22, 0xc7);
z80_outp( 0x22, 0xff);

z80_outp( 0x23, 0x00);
z80_outp( 0x23, 0xc7);
z80_outp( 0x23, 0x02);

LCD_set_cursor(0 , 10);   
LCD_print( "isr_ctc_0 = \0");
int2ascii( add_isr, data);
LCD_print( data ); 



while( port_b != 0b00001000 )
{
    
port_b = z80_inp( Z80_PIO_B ); //Z80 PIO port B;
   

   
if (int_38 == 1)
   {
    LCD_set_cursor(0 , 4);   
    LCD_print( "38 interrupt = \0");
    int2ascii( int_38_count, data);
    LCD_print( data );    
    int_38 = 0;
    int_38_count++;
    a = z80_inp( Z80_PIO_B ); 
   }   
   
    
/*

__asm
     di
     ld hl, _isr_pio_0_a
     ld (0x2000), hl
     ld a, 0x00
     out (0x02), a
     ld hl, _isr_pio_0_b
     ld (0x2002), hl
     ld a, 0x02
     out (0x03), a
     ld a, 0x20
     ld i, a
     im 2
     ei
__endasm;

*/


if (ctc0_int_0 == 1)
  {
    LCD_set_cursor(0 , 2);  
    LCD_print( "CTC 0 interrupt =\0");
    ctc0_couter0++;
    int2ascii( ctc0_couter0, data);
    LCD_print( data );
    ctc0_int_0 = 0;
    }

if (ctc0_int_1 == 1)
  {
    LCD_set_cursor(0 , 3);  
    LCD_print( "CTC 1 interrupt =\0");
    ctc0_couter1++;
    int2ascii( ctc0_couter1, data);
    LCD_print( data );
    ctc0_int_1 = 0;
    }

if (ctc0_int_2 == 1)
  {
    LCD_set_cursor(0 , 4);  
    LCD_print( "CTC 2 interrupt =\0");
    ctc0_couter2++;
    int2ascii( ctc0_couter2, data);
    LCD_print( data );
    ctc0_int_2 = 0;
    }    
    
if (ctc0_int_3 == 1)
  {
    LCD_set_cursor(0 , 5);  
    LCD_print( "CTC 3 interrupt =\0");
    ctc0_couter3++;
    int2ascii( ctc0_couter3, data);
    LCD_print( data );
    ctc0_int_3 = 0;
    }    
    
    


    
if (pio_int_a == 1)
  {
    LCD_set_cursor(0 , 7);  
    LCD_print( "PIO A interrupt =\0");
    pio_a_couter++;
    int2ascii( pio_a_couter, data);
    LCD_print( data );
    pio_int_a = 0;
    a = z80_inp( Z80_PIO_A );
  }


if (pio_int_b == 1)
   {
    LCD_set_cursor(0 , 8);   
    LCD_print( "PIO B interrupt =\0");
    pio_b_couter++;
    int2ascii( pio_b_couter, data);
    LCD_print( data );
    pio_int_b = 0;
    a = z80_inp( Z80_PIO_B );
   }
   
}    



return 0;
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


void isr_ctc_0(void)
{
__asm

      push ix
      push hl
      di
      ld	hl,0x0001
	  ld	(_ctc0_int_0),hl
	  pop hl
      pop ix
      ei
      reti

 __endasm;    
    
}   

void isr_ctc_1(void)
{
__asm

      push ix
      push hl
      di
      ld	hl,0x0001
	  ld	(_ctc0_int_1),hl
	  pop hl
      pop ix
      ei
      reti

 __endasm;    
    
}   


void isr_ctc_2(void)
{
__asm

      push ix
      push hl
      di
      ld	hl,0x0001
	  ld	(_ctc0_int_2),hl
	  pop hl
      pop ix
      ei
      reti

 __endasm;    
    
}   

void isr_ctc_3(void)
{
__asm

      push ix
      push hl
      di
      ld	hl,0x0001
	  ld	(_ctc0_int_3),hl
	  pop hl
      pop ix
      ei
      reti

 __endasm;    
    
}   


void isr_pio_0_a(void) __naked
{
__asm

      push ix
      push hl
      di
      ld	hl,0x0001
	  ld	(_pio_int_a),hl
	  pop hl
      pop ix
      ei
      reti

 __endasm;    
    
    
}


void isr_pio_0_b(void) __naked
{

 
 __asm
     push ix
     push hl
      di
      ld	hl,0x0001
	  ld	(_pio_int_b),hl
	 pop hl
     pop ix
     ei
     reti

 __endasm;
    
    
}








void system_init(void)
{

// initialize PIO ports

z80_outp( Z80_PIO_A_CTL, Z80_PIO_M0);  // set mode 1 byte output
z80_outp( Z80_PIO_B_CTL, Z80_PIO_M0);  // set mode 3 bit in/out mode mask select



//z80_outp( Z80_PIO_A_CTL, 0); // set interupt vector A
//z80_outp( Z80_PIO_B_CTL, 2); // set interupt vecotr B



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

