/* AY-3-8910 Sound Generator             */
/* 2020     Music Note player                        */

#include "music_notes.h"
#include "Hyundai_256x128.h"
#include "Z80_IO.h"
#include <z80.h>
#include <stdlib.h>
#include <string.h>

void int2ascii(unsigned int cx, char *ptr );
void LCD_load_Char(void);
void system_init(void);
void gen_notes( void );

void PSG_write(unsigned char address, unsigned char data);
unsigned char PSG_read(unsigned char address);

unsigned char note_table[108][2];
float AY_CLK = 2000000.0; // Define AY clock frequency

extern void isr_ctc_0(void);
extern void isr_ctc_1(void);
extern void isr_ctc_2(void);
extern void isr_ctc_3(void);

extern void isr_pio_0_a(void);
extern void isr_pio_0_b(void);
extern void z80_rst_38h(void);

int ctc0_int_0 = 0, ctc0_int_1 = 0, ctc0_int_2 = 0, ctc0_int_3 = 0, pio_int_a, pio_int_b, int_38;



int main()
{
char data[20];
char song[32][4] = {"E5","D5","C5","D5","E5","E5","E5","RES","D5","D5","D5","RES","E5","G5","G5","RES","E5","D5","C5","D5","E5","E5","E5","E5","D5","D5","E5","D5","C5","RES","RES","RES"};

int i, k, j;
int ctc0_couter0 = 0,ctc0_couter1 = 0,ctc0_couter2 = 0,ctc0_couter3 = 0;



system_init();
gen_notes( );

__asm
     ld a, 0x01
     ld i, a
     im 2
     ei

__endasm;


i = 0;
k = 0;
j = 0;
LCD_set_cursor(0, 0);
LCD_print( "AY-3-8910 \n" );
LCD_set_cursor(0, 1);
LCD_print( "Music Notes \n" );

z80_outp( 0x20, 0x00);
z80_outp( 0x20, 0xc7);
z80_outp( 0x20, 0x0f);

//z80_outp( 0x21, 0x00);
z80_outp( 0x21, 0xc7);
z80_outp( 0x21, 0xff);

//z80_outp( 0x22, 0x00);
z80_outp( 0x22, 0xc7);
z80_outp( 0x22, 0xff);

//z80_outp( 0x23, 0x00);
z80_outp( 0x23, 0xc7);
z80_outp( 0x23, 0x02);

// Reset PSG
z80_outp( Z80_PIO_B, 0x00);
//delay(100);
z80_outp( Z80_PIO_B, 0x08);


while (i != 10)
{
i = z80_inp(Z80_PIO_A);    


if (ctc0_int_0 == 1 )
{  

PSG_write(7, 0xfe);
k = 0;
while( strcmp( music_notes[k], song[j]) != 0  ) k++;



LCD_set_cursor(0, 4);
LCD_print( "Note =  \n" );

LCD_print( music_notes[k] );
LCD_set_cursor(0, 5);
LCD_print( "FT =  \n" );
int2ascii( note_table[k][0], data);
LCD_print( data );

LCD_set_cursor(0, 6);
LCD_print( "CT =  \n" );
int2ascii( note_table[k][1], data);
LCD_print( data );


LCD_set_cursor(0, 8);
LCD_print( "K =  \n" );
int2ascii( k, data);
LCD_print( data );

if (k != 108 )
{
PSG_write(0, note_table[k][0]);
PSG_write(1, note_table[k][1]);

PSG_write(0x08, 0x10);
PSG_write(0x09, 0x00);
PSG_write(0x0a, 0x00);
PSG_write(0x0b, 0xff);
PSG_write(0x0c, 0x0f);
PSG_write(0x0d, 0x00);
}

j++;
if (j > 31) j = 0;
ctc0_int_0 = 0;

}




}


LCD_set_cursor(0, 10);
LCD_print( "Exit program \n" );
return 0;
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

void gen_notes( void )
{
int i;
long a, b, c;

for( i = 0; i < 108; i++)
  {
    
  a = (long) AY_CLK / (16.0 * music_feq[i]);

  b = a / 256;
  c = a - b * 256;
  
note_table[i][0] = (unsigned char) c;
note_table[i][1] = (unsigned char) b;
  }
  
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

