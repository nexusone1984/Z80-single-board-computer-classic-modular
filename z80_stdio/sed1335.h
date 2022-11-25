// sed1335.h
#ifndef _SED1335_
#define _SED1335_


// send functions
void SED1335_send         (char byte);

// read functions
unsigned char SED1335_read ();
unsigned char SED1335_read_char_at     (unsigned short row, unsigned short col);
unsigned char SED1335_read_graphics_at (unsigned short row, unsigned short col);

// init functions
void SED1335_init ();
void SED1335_display_on();
void SED1335_display_off();

void SED1335_clear_text_layer();
void SED1335_clear_graphics_layer();

// cursor functions
void SED1335_set_text_cursor     (unsigned short row, unsigned short col);
void SED1335_set_graphics_cursor (unsigned short row, unsigned short col);

// text functions
void SED1335_write_char    (unsigned char c);
void SED1335_write_char_at (unsigned char c, unsigned short row, unsigned short col);
void SED1335_write_str     (const char* string);
void SED1335_write_str_at  (const char* string, unsigned short row, unsigned short col);
void SED1335_write_dec	   (unsigned short num);
void SED1335_write_hex	   (unsigned char c);

// graphics functions
void SED1335_pixel_on       (unsigned short x, unsigned short y);
void SED1335_pixel_off 	    (unsigned short x, unsigned short y);
void SED1335_bitmap         (flash unsigned char* map, unsigned short top_left_x, unsigned short top_left_y);
void SED1335_bitmap2 (flash unsigned char* map, unsigned short x, unsigned short y, unsigned short w, unsigned short h);
void SED1335_invert_rows    (unsigned char from, unsigned char to);
void SED1335_toggle_on();
void SED1335_toggle_off();

#endif
