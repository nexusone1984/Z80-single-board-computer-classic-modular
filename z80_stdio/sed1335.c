
#include "Z80_IO.h"
#include <z80.h>
#include "sed1335.h"


#define SYSTEM_SET		0x40
#define DISPLAY_OFF		0x58
#define DISPLAY_ON		0x59
#define SCROLL			0x44
#define CSRFORM			0x5D
#define HDOT_SCR		0x5A
#define OVLAY			0x5B
#define CSRW			0x46
#define MWRITE			0x42
#define MREAD			0x43

#define CSRDIR_RIGHT	0x4C
#define CSRDIR_LEFT     0x4D
#define CSRDIR_UP       0x4E
#define CSRDIR_DOWN     0x4F

// toggle pixels instead of on
unsigned char toggle;

// internal delay function
#define my_delay	delay(1)

/***** Send Functions *****/

void SED1335_send (char byte)
{
	// Code is for Z80 PIO driving the LCD
// This is where you would change code to write a command  
// to LCD via your interface configuration 
// 

//delay(20);

z80_outp( 0x20, a);//Z80PIOA = a;
delay(1);
}


void SED1335_send_command( char command)
{
    
	z80_outp( 0x21, command);
    delay(1);					
}


void SED1335_send_data(char data)
{
	
z80_outp( 0x20, command);
delay(1);
}


/***** Read Functions *****/

unsigned char SED1335_read ()
{
unsigned char val;


val = z80_inp( 0x21);

delay(1);

return val;
}

unsigned char SED1335_read_char_at (unsigned short row, unsigned short col)
{
	SED1335_set_text_cursor(row, col);
	SED1335_send_command(MREAD);
	return SED1335_read();
}

unsigned char SED1335_read_graphics_at (unsigned short row, unsigned short col)
{
	SED1335_set_graphics_cursor(row, col);
	SED1335_send_command(MREAD);
	return SED1335_read();
}

/***** Utility Functions *****/

void SED1335_init ()
{
    LCD_CTRL_DIR = OUTPUT;
    SED1335_CTRL_RESET_OFF;                             // turn off reset
    
	LCD_CTRL_init();

	SED1335_send_command(SYSTEM_SET);
	SED1335_send_data(0x30);			// P1
	SED1335_send_data(0x87);			// P2
	SED1335_send_data(0x07);			// P3
	SED1335_send_data(0x27);			// P4 [C/R]
	SED1335_send_data(0x2B);			// P5 [TC/R]  0x48
	SED1335_send_data(0xEF);			// P6
	SED1335_send_data(0x28);			// P7
	SED1335_send_data(0x00);			// P8

	SED1335_send_command(SCROLL);
	SED1335_send_data(0x00);			// SAD 1L
	SED1335_send_data(0x00);			// SAD 1H
	SED1335_send_data(0xF0);			// SL1
	SED1335_send_data(0xB0);			// SAD 2L
	SED1335_send_data(0x04);			// SAD 2H
	SED1335_send_data(0xF0);			// SL2

	SED1335_send_command(HDOT_SCR);
	SED1335_send_data(0x00);

	SED1335_send_command(OVLAY);
	SED1335_send_data(0x00);			// OV, DM, MX

	SED1335_send_command(DISPLAY_OFF);

	SED1335_send_command(CSRW);
	SED1335_send_data(0x00);			// CSR L
	SED1335_send_data(0x00);			// CSR H

	SED1335_send_command(CSRFORM);
	SED1335_send_data(0x07);			// CRX
	SED1335_send_data(0x87);			// CM, CRY

	SED1335_send_command(DISPLAY_ON);
	//SED1335_send_data(0x17);			// cursor 1Hz
	SED1335_send_data(0x14);			// no cursor

   	toggle = 0;             	        // do not toggle pixels
}

void SED1335_display_on()
{
    SED1335_send_command(DISPLAY_ON);
}

void SED1335_display_off()
{
    SED1335_send_command(DISPLAY_OFF);
}

void SED1335_clear_text_layer()
{
	unsigned short i;

	SED1335_send_command(CSRW);
	SED1335_send_data(0x00);
	SED1335_send_data(0x00);

	SED1335_send_command(CSRDIR_RIGHT);

	SED1335_send_command(MWRITE);

	for (i=0; i<1200; i++)
	{
		SED1335_send_data(' ');	// space
	}
}

void SED1335_clear_graphics_layer()
{
	unsigned short i;

	SED1335_send_command(CSRW);
	SED1335_send_data(0xb0);
	SED1335_send_data(0x04);

	SED1335_send_command(CSRDIR_RIGHT);

	SED1335_send_command(MWRITE);

	for (i=0; i<9600; i++)
	{
		SED1335_send_data(0x55);	// space
	}
}

void SED1335_set_text_cursor(unsigned short row, unsigned short col)
{
		unsigned short addr;
		addr = 40 * row + col;
		
		SED1335_send_command(CSRW);
		SED1335_send_data(addr & 0x00FF);
		SED1335_send_data(addr >> 8);
}

void SED1335_set_graphics_cursor(unsigned short row, unsigned short col)
{
	unsigned addr;
	addr = 1200 + col + 40 * row;
	
	SED1335_send_command(CSRW);
	SED1335_send_data(addr & 0x00FF);
	SED1335_send_data(addr >> 8);
}


/***** Text Fucntions *****/

void SED1335_write_char (unsigned char c)
{
	SED1335_send_command(MWRITE);
	SED1335_send_data(c);
}

void SED1335_write_char_at (unsigned char c, unsigned short row, unsigned short col)
{	
	SED1335_set_text_cursor(row, col);

	SED1335_send_command(MWRITE);
	SED1335_send_data(c);
}

void SED1335_write_str (const char* string)
{
	SED1335_send_command(MWRITE);

	while (*string != 0)
	{
		SED1335_send_data(*string);
		string++;
	}
}

void SED1335_write_str_at (const char* string, unsigned short row, unsigned short col)
{
	SED1335_set_text_cursor(row, col);
	SED1335_write_str(string);
} 

void SED1335_write_dec (unsigned short num)
{
	if ( (num / 100) > 0 )		// hundreds
	{
		SED1335_write_char((num/100)+'0');
	}
	if ( ((num / 10) > 0) || ((num / 100) > 0) )		// tens
	{
		SED1335_write_char((num%100)/10+'0');
	}

	// ones
	SED1335_write_char(num%10+'0');
}

void SED1335_write_hex (unsigned char c)
{
	unsigned char tmp;
	tmp = c;

	SED1335_write_char('h');

	// high 
	tmp = c >> 4;	
	if (tmp >= 10)
	{
		SED1335_write_char(tmp + 55);
	}
	else
	{
		SED1335_write_char(tmp + '0');
	}

	// low
	tmp = c & 0x0F;
	if (tmp >= 10)
	{
		SED1335_write_char(tmp + 55);
	}
	else
	{
		SED1335_write_char(tmp + '0');
	}	
}


/***** Graphics Functions *****/

#define SED1335_write_graphics(data)		\
    SED1335_send_command(MWRITE);			\
    SED1335_send_data(data)


#define SED1335_write_graphics_at(data,row,col)		\
    SED1335_set_graphics_cursor(row, col);			\
    SED1335_write_graphics(data)


void SED1335_pixel_on (unsigned short x, unsigned short y)
{
    unsigned short row;
    unsigned short col;
	unsigned short data, graphics;
	
	row = y;
    col = x >> 3;   // div by 8
    
	//graphics = SED1335_read_graphics_at(row, col);
	// replaced with inline due to stack limit
	SED1335_set_graphics_cursor(row, col);
	SED1335_send_command(MREAD);
	graphics = SED1335_read();
	
	
    if (toggle)
    {
                 //   mask     ^   data
        data = (0x80 >> (x%8)) ^ graphics;
    }
    else
    {   
                 //   mask     |   data
        data = (0x80 >> (x%8)) | graphics;
    }

    SED1335_write_graphics_at(data, row, col);
}


void SED1335_pixel_off (unsigned short x, unsigned short y)
{
    unsigned short row;
    unsigned short col;
	unsigned short data, graphics;
	
	row = y;
	col = x >> 3;       // div by 8

	graphics = SED1335_read_graphics_at(row, col);

             //   mask     |   data

    data = ((0x80 >> (x&0x07)) ^ 0xFF) & graphics;
	
    SED1335_write_graphics_at(data, row, col);
}

void SED1335_bitmap (flash unsigned char* map, unsigned short top_left_y, unsigned short top_left_x)
{
    unsigned short i, j;
    unsigned short height, width;
    
    width  = (((unsigned short)(map[0]))<<8) + map[1];      // in pixel
    width  = width >> 3;                                    // in bytes
    
    height = (((unsigned short)(map[2]))<<8) + map[3];
    
    
    for (i=0; i<height; i++)
    {                               
        unsigned short row, col;
        row = top_left_y + i;
        col = top_left_x >> 3;      // div by 8
        
        SED1335_set_graphics_cursor(row, col); 
        
        for (j=0; j<width; j++)
        {
            SED1335_write_graphics(map[i*width+j+4]);
        }
     }
} // end SED1335_bitmap





void SED1335_bitmap2 (flash unsigned char* map, unsigned short x, unsigned short y, unsigned short w, unsigned short h)
{
    unsigned short i, j;
    unsigned short height, width;
    
    width  = w;      // in pixel
    width  = width / 8;                                    // in bytes
    
    height = h;

    for (i=0; i<height; i++)
    {
                                  
        unsigned short row, col;
        row = y + i;
        col = x / 8;
        
        SED1335_set_graphics_cursor(row, col); 
        
        for (j=0; j<width; j++)
        {
            SED1335_write_graphics(map[i*width+j+4]);
        }
     }
} // end SED1335_bitmap2








void SED1335_invert_rows (unsigned char from, unsigned char to)
{
    unsigned short row, col;
	unsigned char data;
    
    // invert row1 through row2
	for (row = from; row <= to; row++)
	{	    
	    for (col=0; col<320; col=col+8)
	    {
	        data = SED1335_read_graphics_at(row,col>>3);        // read
	        data = ~data;                                       // invert
	        
	        SED1335_write_graphics_at(data, row, col>>3);       // write
	    }
	} // end for       
}

void SED1335_toggle_on()
{
	toggle = 1;
}

void SED1335_toggle_off()
{
	toggle = 0;
}
