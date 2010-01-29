#ifndef __NXT_LCD_H__
#  define __NXT_LCD_H__

#  include "mytypes.h"

#  define NXT_LCD_WIDTH 100
#  define NXT_LCD_DEPTH 8

void nxt_lcd_init(const U8 *disp);
void nxt_lcd_power_up(void);
void nxt_lcd_power_down(void);
void nxt_lcd_update();
void nxt_lcd_force_update();


#endif
