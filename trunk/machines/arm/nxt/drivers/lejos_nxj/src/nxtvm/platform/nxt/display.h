#ifndef __DISPLAY_H__
#  define __DISPLAY_H__

#  include "mytypes.h"

void display_init(void);

void display_update(void);

void display_force_update(void);

void display_clear(U32 updateToo);

void display_goto_xy(int x, int y);

void display_char(int c);

void display_string(const char *str);

void display_int(int val, U32 places);
void display_hex(U32 val, U32 places);

void display_unsigned(U32 val, U32 places);

void display_bitmap_copy(const U8 *data, U32 width, U32 depth, U32 x, U32 y);

void display_test(void);

U8 *display_get_buffer(void);

void display_set_auto_update(int);

extern int display_tick;
extern int display_auto_update;

#endif
