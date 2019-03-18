#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h> // Hardware-specific library
#include "Adafruit_miniTFTWing.h"

Adafruit_miniTFTWing ss;
#define TFT_RST    -1    // we use the seesaw for resetting to save a pin

#ifdef ESP8266
   #define TFT_CS   2
   #define TFT_DC   16
#endif
#ifdef ESP32
   #define TFT_CS   14
   #define TFT_DC   32
#endif
#ifdef TEENSYDUINO
   #define TFT_CS   8
   #define TFT_DC   3
#endif
#ifdef ARDUINO_STM32_FEATHER
   #define TFT_CS   PC5
   #define TFT_DC   PC7
#endif
#ifdef ARDUINO_NRF52_FEATHER /* BSP 0.6.5 and higher! */
   #define TFT_CS   27
   #define TFT_DC   30
#endif

// Anything else!
#if defined (__AVR_ATmega32U4__) || defined(ARDUINO_SAMD_FEATHER_M0) || defined (__AVR_ATmega328P__) || defined(ARDUINO_SAMD_ZERO) || defined(__SAMD51__) || defined(__SAM3X8E__)
   #define TFT_CS   5
   #define TFT_DC   6
#endif


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

void setup()   {
  Serial.begin(115200);

  /*
  while (!Serial)  delay(10);  // Wait until serial console is opened
  */

  if (!ss.begin()) {
    Serial.println("seesaw couldn't be found!");
    while(1);
  }

  Serial.print("seesaw started!\tVersion: ");
  Serial.println(ss.getVersion(), HEX);

  ss.tftReset();   // reset the display
  ss.setBacklight(TFTWING_BACKLIGHT_ON);  // turn off the backlight

  tft.initR(INITR_MINI160x80);   // initialize a ST7735S chip, mini display
  Serial.println("TFT initialized");

  tft.setRotation(1);

  tft.fillScreen(ST77XX_RED);
  delay(100);
  tft.fillScreen(ST77XX_GREEN);
  delay(100);
  tft.fillScreen(ST77XX_BLUE);
  delay(100);
  tft.fillScreen(ST77XX_BLACK);
}

void loop() {
  delay(10);
  uint32_t buttons = ss.readButtons();
  //Serial.println(buttons, BIN);

  uint16_t color;

  color = ST77XX_BLACK;
  if (! (buttons & TFTWING_BUTTON_LEFT)) {
    Serial.println("LEFT");
    color = ST77XX_WHITE;
  }
  tft.fillTriangle(150, 30, 150, 50, 160, 40, color);
 
  color = ST77XX_BLACK;
  if (! (buttons & TFTWING_BUTTON_RIGHT)) {
    Serial.println("RIGHT");
    color = ST77XX_WHITE;
  }
  tft.fillTriangle(120, 30, 120, 50, 110, 40, color);

  color = ST77XX_BLACK;
  if (! (buttons & TFTWING_BUTTON_DOWN)) {
    Serial.println("DOWN");
    color = ST77XX_WHITE;
  }
  tft.fillTriangle(125, 26, 145, 26, 135, 16, color);

  color = ST77XX_BLACK;
  if (! (buttons & TFTWING_BUTTON_UP)) {
    Serial.println("UP");
    color = ST77XX_WHITE;
  }
  tft.fillTriangle(125, 53, 145, 53, 135, 63, color);

  color = ST77XX_BLACK;
  if (! (buttons & TFTWING_BUTTON_A)) {
    Serial.println("A");
    color = ST7735_GREEN;
  }
  tft.fillCircle(30, 57, 10, color);

  color = ST77XX_BLACK;
  if (! (buttons & TFTWING_BUTTON_B)) {
    Serial.println("B");
    color = ST77XX_YELLOW;
  }
  tft.fillCircle(30, 18, 10, color);

  color = ST77XX_BLACK;
  if (! (buttons & TFTWING_BUTTON_SELECT)) {
    Serial.println("SELECT");
    color = ST77XX_WHITE;
  }
  tft.fillCircle(80, 40, 7, color);
}
