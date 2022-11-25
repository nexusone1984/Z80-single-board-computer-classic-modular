/* LCD_HD44780_LIB.h                                                 */
/* Genric LCD Display Library for Hitachi HD44780  by Eric Stringer  */
/* eric.stringer@gmail.com  version 1.0 Dec 2016 */


/* Bit settings for LCD Command Functions  */

#define LCD_CLEAR  0b00000001  // Clear display and return cursor home
#define LCD_HOME   0b00000010  // Cursor home
// These functions are writen as a group OR together 
// Entry mode set
#define LCD_MODE  0b00000100 // indicate mode to be set. 
#define LCD_SHIFT_OFF  0b00000000
#define LCD_SHIFT_ON   0b00000001
#define LCD_CUR_DEC   0b00000000 
#define LCD_CUR_INC   0b00000010 
// Display control
#define LCD_DISPLAY   0b00001000 // indicate Display control
#define LCD_DISPLAY_OFF   0b00000000 
#define LCD_DISPLAY_ON   0b00000100 
#define LCD_DISPLAY_CURSOR_OFF   0b00000000
#define LCD_DISPLAY_CURSOR_ON   0b00000010
#define LCD_DISPLAY_CURSOR_BLINK_OFF    0b00000000
#define LCD_DISPLAY_CURSOR_BLINK_ON    0b00000001
// Cursor display shift 
#define LCD_DISPLAY_CURSOR   0b00010000
#define LCD_DISPLAY_CURSOR_MOVE   0b00000000
#define LCD_DISPLAY_CURSOR_SHIFT  0b00001000
#define LCD_DISPLAY_CURSOR_SHIFT_LEFT  0b00000000
#define LCD_DISPLAY_CURSOR_SHIFT_RIGHT  0b00000100
// Function set
#define LCD_FUNCTION_SET  0b00100000 // Function set 
#define LCD_FUNCTION_SET_DATA_4BIT   0b00000000 // 
#define LCD_FUNCTION_SET_DATA_8BIT  0b00010000 // 
#define LCD_FUNCTION_SET_LINES_1  0b00000000 // 
#define LCD_FUNCTION_SET_LINES_2  0b00001000 // 
#define LCD_FUNCTION_SET_FONT5X7  0b00000000 // 
#define LCD_FUNCTION_SET_FONT5X10  0b00000100 // 
// Set CGRAM address 
#define LCD_CGRAM_ADDRESS  0b01000000 //
// Set DDRAM address
#define LCD_DDRAM_ADDRESS  0b10000000 //

extern void delay(int j);


void LCD_busy( void );
void LCD_write( unsigned char a );
void LCD_write_cmd( unsigned char a );
unsigned char LCD_read( void );
unsigned char LCD_read_cmd( void );

void LCD_print( unsigned char address, char *ptr );
char LCD_load_char( char address, unsigned char *ptr);
void LCD_init(void);
