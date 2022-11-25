/* Hyundai_256x128.h
  256 X 128 LCD Grapics display Hyundai #HG25504  
  sold by All Electronics.
  By Eric Stringer 2017
*/


#define SCREEN_SIZE_X  256
#define SCREEN_SIZE_Y  128
#define GRAPHICS_MEMORY_LSB  0xb0
#define GRAPHICS_MEMORY_MSB  0x04


void LCD_write_cmd( unsigned char a );
void LCD_write( unsigned char a );
unsigned char LCD_read_flag( void );
unsigned char LCD_read_data( void ); 
void LCD_clear(void);
void LCD_graphics_clear(void);
void LCD_print( char *ptr ); 
void LCD_print_char( char a );
void LCD_set_cursor(char x, char y);
void LCD_set_graphics_cursor(char col, char row);
void LCD_pixel(int x, int y, char bit);
void LCD_draw_line(int x0, int y0, int x1, int y1, char bit);


