#include "tpl_os.h"
#include "stm32f30x.h"
#include "stm32f30x_rcc.h"
#include "stm32f30x_gpio.h"
#include "mcp23s17.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ST7735.h"
#define PROGMEM
#define FONT_WIDTH 7
#define FONT_HEIGHT 14
#include "tft/Adafruit-GFX-Library/fontconvert/veraMono6.h"
#define FONT_NAME VeraMono6pt7b

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

Adafruit_ST7735 tft = Adafruit_ST7735();

void setupDisplay() 
{
	tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
	tft.setFont(&FONT_NAME);
	tft.fillScreen(ST7735_BLACK);
	tft.setTextColor(ST7735_GREEN);
	tft.setCursor(0, FONT_HEIGHT);
	tft.println("Hello World! ");
	tft.println("you can use this tft ");
	tft.println("to debug your app...");
}

#ifdef __cplusplus
}
#endif /* __cplusplus */
