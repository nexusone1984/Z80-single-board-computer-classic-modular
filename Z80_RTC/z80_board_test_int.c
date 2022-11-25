
/*  New board demo                             */

#include "Z80_IO.h"
#include <z80.h>
#include "Hyundai_256x128.h"
#include <stdlib.h>


extern void isr_pio_0_a(void); // we set this up externally 
extern void isr_pio_0_b(void); // in out assembly area.
extern void isr_ctc_0(void);
extern void isr_ctc_1(void);
extern void isr_ctc_2(void);
extern void isr_ctc_3(void);

extern int vid_pio_0_a;
extern int vid_pio_0_b;
extern int vid_ctc_0;
extern int vid_ctc_1;
extern int vid_ctc_2;
extern int vid_ctc_3;


int pio_int_a, pio_int_b, ctc_3;

void system_init(void);

void delay(int j)
{
int i;
for(i=0; i<j; i++);
}


int main()
{
     
system_init();


__asm
     di
     ld hl, _vid_pio_0_a
     ld a, l
     out (0x02), a
     ld hl, _vid_pio_0_b
     ld a, l
     out (0x03), a
     ld hl, _vid_ctc_0
     
     im 2
     ei
__endasm;




LCD_set_cursor(0 , 0);
LCD_print("System test\0");

z80_outp( Z80_PIO_A, 0x05);

z80_outp( 0x20, 0x07);
z80_outp( 0x20, 0xd5);
z80_outp( 0x21, 0x07);
z80_outp( 0x21, 0x2e);
z80_outp( 0x22, 0x07);
z80_outp( 0x22, 0x36);
// Clock divided to 2Megahertz 
// Prescale 256 
//  C4 = 1e, D4 = 1b, E4 = 0x18, F4 0x16, G4 = 0x14, A4 = 0x12
// Prescale 16 
// C5 = 0xef, D5 = 0xd5
// C6 = 0x77, D6 = 0x6a,E6 = 0x5e, F6 = 0x59, G6 = 0x4f, A6 = 0x45
// C7 = 3c, D7 = 36, E7 = 0x30, F7 0x2e, G7 = 0x28, A7 = 0x23,


return 0;
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
      ld hl, (_pio_b_counter)
      inc hl
      ld (_pio_b_counter), hl
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






