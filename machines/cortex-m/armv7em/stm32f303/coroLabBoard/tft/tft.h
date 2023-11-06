#ifndef __TFT_H__
#define __TFT_H__
#include "Adafruit_ST7735.h"

/* This is the main object for the tft display.
 * It adds a few functions to the original Adafruit
 * driver to ease the text hendling.
 **/
class tft : public Adafruit_ST7735 {
	public:
	tft() : Adafruit_ST7735() {}

	/* erase the tft (black), and set cursor at top left */
    void erase();

	/* init the hardware */
    void setup();

	/* set text cursor position
	 * line 0 is at top
	 * col 0 is at left
	 * */
	void setTextCursor(const unsigned int col, const unsigned int line);

	/* return the width of the LCD as a number of chars
	 */
	unsigned int getTextWidth();

	/* return the width of the LCD as a number of chars
	 */
	unsigned int getTextHeight();

	/* erase n characters from current cursor position */
	void eraseText(const unsigned int n);
};

extern tft Tft;
#endif //__TFT_H__
