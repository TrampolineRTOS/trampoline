#include "Adafruit_ST77xx.h"
#include "Adafruit_ST7789.h"

// Rather than a bazillion writecommand() and writedata() calls, screen
// initialization commands and arguments are organized in these tables
// stored in PROGMEM.  The table may look bulky, but that's mostly the
// formatting -- storage-wise this is hundreds of bytes more compact
// than the equivalent code.  Companion function follows.

#define ST7789_240x240_XSTART 0
#define ST7789_240x240_YSTART 80

static const uint8_t PROGMEM
  cmd_240x240[] =  {         // Initialization commands for 7789 screens
    9,                       // 9 commands in list:
    ST77XX_SWRESET,   ST_CMD_DELAY,  //  1: Software reset, no args, w/delay
      150,                     //    150 ms delay
    ST77XX_SLPOUT ,   ST_CMD_DELAY,  //  2: Out of sleep mode, no args, w/delay
      255,                    //     255 = 500 ms delay
    ST77XX_COLMOD , 1+ST_CMD_DELAY,  //  3: Set color mode, 1 arg + delay:
      0x55,                   //     16-bit color
      10,                     //     10 ms delay
    ST77XX_MADCTL , 1      ,  //  5: Memory access ctrl (directions), 1 arg:
      0x08,                   //     Row addr/col addr, bottom to top refresh
    ST77XX_CASET  , 4      ,  // 15: Column addr set, 4 args, no delay:
      0x00, ST7789_240x240_XSTART,             //     XSTART = 0
    (240+ST7789_240x240_XSTART) >> 8, (240+ST7789_240x240_XSTART) & 0xFF,             //      XEND = 240
    ST77XX_RASET  , 4      ,  // 16: Row addr set, 4 args, no delay:
      0x00, ST7789_240x240_YSTART,             //     YSTART = 0
      (240+ST7789_240x240_YSTART) >> 8, (240+ST7789_240x240_YSTART) & 0xFF,             //      YEND = 240
    ST77XX_INVON ,   ST_CMD_DELAY,  // hack
      10,
    ST77XX_NORON  ,   ST_CMD_DELAY,  // 17: Normal display on, no args, w/delay
      10,                     //     10 ms delay
    ST77XX_DISPON ,   ST_CMD_DELAY,  // 18: Main screen turn on, no args, w/delay
    255 };                  //     255 = 500 ms delay



/**************************************************************************/
/*!
    @brief   Initialization code common to all ST7789 displays
    @param   width Display width
    @param   height Display height
*/
/**************************************************************************/
void Adafruit_ST7789::init(uint16_t width, uint16_t height) {
  commonInit(NULL);

  _colstart = ST7789_240x240_XSTART;
  _rowstart = ST7789_240x240_YSTART;
  _height = 240;
  _width = 240;

  displayInit(cmd_240x240);

  setRotation(0);
}


/**************************************************************************/
/*!
    @brief   Set origin of (0,0) and orientation of TFT display
    @param   m  The index for rotation, from 0-3 inclusive
*/
/**************************************************************************/
void Adafruit_ST7789::setRotation(uint8_t m) {
  uint8_t madctl = 0;

  rotation = m % 4; // can't be higher than 3

  switch (rotation) {
   case 0:
     madctl = ST77XX_MADCTL_MX | ST77XX_MADCTL_MY | ST77XX_MADCTL_RGB;

     _xstart = _colstart;
     _ystart = _rowstart;
     break;
   case 1:
     madctl = ST77XX_MADCTL_MY | ST77XX_MADCTL_MV | ST77XX_MADCTL_RGB;

     _xstart = _rowstart;
     _ystart = _colstart;
     break;
  case 2:
     madctl = ST77XX_MADCTL_RGB;
 
     _xstart = 0;
     _ystart = 0;
     break;

   case 3:
     madctl = ST77XX_MADCTL_MX | ST77XX_MADCTL_MV | ST77XX_MADCTL_RGB;

     _xstart = 0;
     _ystart = 0;
     break;
  }

  startWrite();
  writeCommand(ST77XX_MADCTL);
  spiWrite(madctl);
  endWrite();
}
