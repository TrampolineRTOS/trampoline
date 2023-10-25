#ifndef _ADAFRUIT_ST7789H_
#define _ADAFRUIT_ST7789H_

#include "Adafruit_ST77xx.h"

/// Subclass of ST77XX type display for ST7789 TFT Driver
class Adafruit_ST7789 : public Adafruit_ST77xx {

 public:
/**************************************************************************/
/*!
    @brief  Instantiate Adafruit ST7789 driver with software SPI
    @param    cs    Chip select pin #
    @param    dc    Data/Command pin #
    @param    mosi  SPI MOSI pin #
    @param    sclk  SPI Clock pin #
    @param    rst   Reset pin # (optional, pass -1 if unused)
*/
/**************************************************************************/
 Adafruit_ST7789(int8_t cs, int8_t dc, int8_t mosi, int8_t sclk, int8_t rst) : 
  Adafruit_ST77xx(cs, dc, mosi, sclk, rst) {}
  
/**************************************************************************/
/*!
    @brief  Instantiate Adafruit ST7789 driver with hardware SPI
    @param    cs    Chip select pin #
    @param    dc    Data/Command pin #
    @param    rst   Reset pin # (optional, pass -1 if unused)
*/
/**************************************************************************/
 Adafruit_ST7789(int8_t cs, int8_t dc, int8_t rst) : 
  Adafruit_ST77xx(cs, dc, rst) {}
  
  // the tab types are so weird we need to do this 'by hand'
  void  setRotation(uint8_t m);

  void  init(uint16_t width, uint16_t height);

 private:

};

#endif // _ADAFRUIT_ST7789H_
