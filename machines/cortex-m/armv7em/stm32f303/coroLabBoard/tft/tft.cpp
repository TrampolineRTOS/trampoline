#include "tft.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ST7735.h"
#define PROGMEM

//#define BIG_FONT
#ifdef BIG_FONT
	#define FONT_WIDTH    11
	#define FONT_HEIGHT   21
	#define FONT_H_OFFSET  5
	#include "tft/Adafruit-GFX-Library/fontconvert/veraMono9.h"
	#define FONT_NAME VeraMono9pt7b
# else	//default font
	#define FONT_WIDTH     7
	#define FONT_HEIGHT   14
	#define FONT_H_OFFSET  3
	#include "tft/Adafruit-GFX-Library/fontconvert/veraMono6.h"
	#define FONT_NAME VeraMono6pt7b
#endif

void tft::erase()
{
	fillScreen(ST7735_BLACK);
	setCursor(0, FONT_HEIGHT);
}

void tft::setup()
{
	initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
	setFont(&FONT_NAME);
	setTextColor(ST7735_GREEN);
	erase();
}

void tft::setTextCursor(const unsigned int col, const unsigned int line)
{
	const unsigned x = (col % getTextWidth()) * FONT_WIDTH;
	const unsigned y = ((line % getTextHeight())+1) * FONT_HEIGHT;
	setCursor(x,y);
}

unsigned int tft::getTextWidth()
{
	return width() / FONT_WIDTH;
}

unsigned int tft::getTextHeight()
{
	return height() / FONT_HEIGHT;
}

//we can use getTextBounds() to get the bounds
//of a text part. This is a simpler function for
//fixed-space fonts.
void tft::eraseText(const unsigned int n)
{
	int x = getCursorX();
	int y = getCursorY();
	for(unsigned int i=0;i<n;i++)
	{
		if((x+FONT_WIDTH)>width())
		{
			//the write function will go to the next line
			x=0;
			y+=FONT_HEIGHT;
		}
		//clear only one char
		fillRect(x,y+FONT_H_OFFSET-FONT_HEIGHT,
				 FONT_WIDTH,FONT_HEIGHT,ST77XX_BLACK);
		//update x for the next char
		x+=FONT_WIDTH;
	}
}

tft Tft;
