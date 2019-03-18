/***************************************************
  This is an example sketch for the Adafruit 1.8" TFT shield with joystick
  This example is for the Seesaw version
  ----> http://www.adafruit.com/products/802

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 pins are required to
  interface
  One pin is also needed for the joystick, we use analog 3
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
// Be sure to install Adafruit seesaw library!
#include <Adafruit_seesaw.h>
#include <Adafruit_TFTShield18.h>

Adafruit_TFTShield18 ss;


// TFT display and SD card will share the hardware SPI interface.
// Hardware SPI pins are specific to the Arduino board type and
// cannot be remapped to alternate pins.  For Arduino Uno,
// Duemilanove, etc., pin 11 = MOSI, pin 12 = MISO, pin 13 = SCK.
#define SD_CS    4  // Chip select line for SD card on Shield
#define TFT_CS  10  // Chip select line for TFT display on Shield
#define TFT_DC   8  // Data/command line for TFT on Shield
#define TFT_RST  -1  // Reset line for TFT is handled by seesaw!

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup(void) {
  Serial.begin(9600);
  while (!Serial);
  
  // start by disabling both SD and TFT
  pinMode(TFT_CS, OUTPUT);
  digitalWrite(TFT_CS, HIGH);
  pinMode(SD_CS, OUTPUT);
  digitalWrite(SD_CS, HIGH);

  // Start seesaw helper chip
  if (!ss.begin()){
    Serial.println("seesaw could not be initialized!");
    while(1);
  }
  Serial.println("seesaw started");
  Serial.print("Version: "); Serial.println(ss.getVersion(), HEX);

  // Start set the backlight off
  ss.setBacklight(TFTSHIELD_BACKLIGHT_OFF);
  // Reset the TFT
  ss.tftReset();

  // Initialize 1.8" TFT
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab

  Serial.println("TFT OK!");
  tft.fillScreen(ST77XX_CYAN);

  Serial.print("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println("failed!");
  } else {
    Serial.println("OK!");
    File root = SD.open("/");
    printDirectory(root, 0);
    root.close();
    bmpDraw("/parrot.bmp", 0, 0);
  }

  // Set backlight on fully
  // ss.setBacklight(TFTSHIELD_BACKLIGHT_ON);
  // Or you can set the backlight one third on
  // ss.setBacklight(TFTSHIELD_BACKLIGHT_ON / 3);
  // Or dim it up
  for (int32_t i=TFTSHIELD_BACKLIGHT_OFF; i<TFTSHIELD_BACKLIGHT_ON; i+=100) {
    ss.setBacklight(i);
    delay(1);
  }
  delay(100);
  tft.fillScreen(ST77XX_RED);
  delay(100);
  tft.fillScreen(ST77XX_GREEN);
  delay(100);
  tft.fillScreen(ST77XX_BLUE);
  delay(100);
  tft.fillScreen(ST77XX_BLACK);
 
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(0, 0);
  tft.print("Press all the buttons");
}


uint8_t buttonhistory = 0;

void loop() {
  uint32_t buttons = ss.readButtons();
  tft.setTextSize(3);
  if(! (buttons & TFTSHIELD_BUTTON_DOWN)){
    tft.setTextColor(ST77XX_RED);
    tft.setCursor(0, 10);
    tft.print("Down ");
    buttonhistory |= 1;
  }
  if(! (buttons & TFTSHIELD_BUTTON_LEFT)){
    tft.setTextColor(ST77XX_YELLOW);
    tft.setCursor(0, 35);
     tft.print("Left ");
    buttonhistory |= 2;
  }
  if(! (buttons & TFTSHIELD_BUTTON_UP)){
    tft.setTextColor(ST77XX_GREEN);
    tft.setCursor(0, 60);
    tft.print("Up"); 
    buttonhistory |= 4;
  }
  if(! (buttons & TFTSHIELD_BUTTON_RIGHT)){
    tft.setTextColor(ST77XX_BLUE);
    tft.setCursor(0, 85);
    tft.print("Right");
    buttonhistory |= 8;
  }
  if(! (buttons & TFTSHIELD_BUTTON_1)){
    tft.setTextColor(ST77XX_BLUE);
    tft.setCursor(0, 140);
    tft.print("1");
    buttonhistory |= 16;
  }
  if(! (buttons & TFTSHIELD_BUTTON_2)){
    tft.setTextColor(ST77XX_GREEN);
    tft.setCursor(50, 140);
    tft.print("2");
    buttonhistory |= 32;
  }
  if(! (buttons & TFTSHIELD_BUTTON_3)){
    tft.setTextColor(ST77XX_YELLOW);
    tft.setCursor(100, 140);
    tft.print("3");
    buttonhistory |= 64;
  }
  if (! (buttons & TFTSHIELD_BUTTON_IN)) {
    tft.setTextColor(ST77XX_MAGENTA);
    tft.setCursor(0, 110);
    tft.print("SELECT");
  }
  if (buttonhistory == 0x7F) {
    bmpDraw("/parrot.bmp", 0, 0);
    while (1) {
      tft.invertDisplay(true);
      delay(500);
      tft.invertDisplay(false);
      delay(500);
    }
  }
  delay(100);
}

// This function opens a Windows Bitmap (BMP) file and
// displays it at the given coordinates.  It's sped up
// by reading many pixels worth of data at a time
// (rather than pixel by pixel).  Increasing the buffer
// size takes more of the Arduino's precious RAM but
// makes loading a little faster.  20 pixels seems a
// good balance.

#define BUFFPIXEL 20

void bmpDraw(char *filename, uint8_t x, uint16_t y) {

  File     bmpFile;
  int      bmpWidth, bmpHeight;   // W+H in pixels
  uint8_t  bmpDepth;              // Bit depth (currently must be 24)
  uint32_t bmpImageoffset;        // Start of image data in file
  uint32_t rowSize;               // Not always = bmpWidth; may have padding
  uint8_t  sdbuffer[3*BUFFPIXEL]; // pixel buffer (R+G+B per pixel)
  uint8_t  buffidx = sizeof(sdbuffer); // Current position in sdbuffer
  boolean  goodBmp = false;       // Set to true on valid header parse
  boolean  flip    = true;        // BMP is stored bottom-to-top
  int      w, h, row, col;
  uint8_t  r, g, b;
  uint32_t pos = 0, startTime = millis();

  if((x >= tft.width()) || (y >= tft.height())) return;

  Serial.println();
  Serial.print(F("Loading image '"));
  Serial.print(filename);
  Serial.println('\'');

  // Open requested file on SD card
  if ((bmpFile = SD.open(filename)) == NULL) {
    Serial.print(F("File not found"));
    return;
  }

  // Parse BMP header
  if(read16(bmpFile) == 0x4D42) { // BMP signature
    Serial.print(F("File size: ")); Serial.println(read32(bmpFile));
    (void)read32(bmpFile); // Read & ignore creator bytes
    bmpImageoffset = read32(bmpFile); // Start of image data
    Serial.print(F("Image Offset: ")); Serial.println(bmpImageoffset, DEC);
    // Read DIB header
    Serial.print(F("Header size: ")); Serial.println(read32(bmpFile));
    bmpWidth  = read32(bmpFile);
    bmpHeight = read32(bmpFile);
    if(read16(bmpFile) == 1) { // # planes -- must be '1'
      bmpDepth = read16(bmpFile); // bits per pixel
      Serial.print(F("Bit Depth: ")); Serial.println(bmpDepth);
      if((bmpDepth == 24) && (read32(bmpFile) == 0)) { // 0 = uncompressed

        goodBmp = true; // Supported BMP format -- proceed!
        Serial.print(F("Image size: "));
        Serial.print(bmpWidth);
        Serial.print('x');
        Serial.println(bmpHeight);

        // BMP rows are padded (if needed) to 4-byte boundary
        rowSize = (bmpWidth * 3 + 3) & ~3;

        // If bmpHeight is negative, image is in top-down order.
        // This is not canon but has been observed in the wild.
        if(bmpHeight < 0) {
          bmpHeight = -bmpHeight;
          flip      = false;
        }

        // Crop area to be loaded
        w = bmpWidth;
        h = bmpHeight;
        if((x+w-1) >= tft.width())  w = tft.width()  - x;
        if((y+h-1) >= tft.height()) h = tft.height() - y;

        // Set TFT address window to clipped image bounds
        tft.startWrite();
        tft.setAddrWindow(x, y, w, h);
        tft.endWrite();

        for (row=0; row<h; row++) { // For each scanline...

          // Seek to start of scan line.  It might seem labor-
          // intensive to be doing this on every line, but this
          // method covers a lot of gritty details like cropping
          // and scanline padding.  Also, the seek only takes
          // place if the file position actually needs to change
          // (avoids a lot of cluster math in SD library).
          if(flip) // Bitmap is stored bottom-to-top order (normal BMP)
            pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
          else     // Bitmap is stored top-to-bottom
            pos = bmpImageoffset + row * rowSize;
          if(bmpFile.position() != pos) { // Need seek?
            bmpFile.seek(pos);
            buffidx = sizeof(sdbuffer); // Force buffer reload
          }

          for (col=0; col<w; col++) { // For each pixel...
            // Time to read more pixel data?
            if (buffidx >= sizeof(sdbuffer)) { // Indeed
              bmpFile.read(sdbuffer, sizeof(sdbuffer));
              buffidx = 0; // Set index to beginning
            }

            // Convert pixel from BMP to TFT format, push to display
            b = sdbuffer[buffidx++];
            g = sdbuffer[buffidx++];
            r = sdbuffer[buffidx++];
            tft.pushColor(tft.color565(r,g,b));
          } // end pixel
        } // end scanline
        tft.endWrite();
        Serial.print(F("Loaded in "));
        Serial.print(millis() - startTime);
        Serial.println(" ms");
      } // end goodBmp
    }
  }

  bmpFile.close();
  if(!goodBmp) Serial.println(F("BMP format not recognized."));
}


// These read 16- and 32-bit types from the SD card file.
// BMP data is stored little-endian, Arduino is little-endian too.
// May need to reverse subscript order if porting elsewhere.

uint16_t read16(File f) {
  uint16_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read(); // MSB
  return result;
}

uint32_t read32(File f) {
  uint32_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read();
  ((uint8_t *)&result)[2] = f.read();
  ((uint8_t *)&result)[3] = f.read(); // MSB
  return result;
}


void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}

