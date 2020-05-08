# Trampoline examples for AVR8 Targets

This directory shows some examples for 8 bits AVR targets, including some Arduino boards.
For all these examples, the Gcc cross-compiler is required.

# Installation 
## avr-gcc cross-compiler
**Linux** (Debian/Ubuntu) -> `sudo apt-get install avr-libc gcc-avr avrdude`

**MacOSX**  -> [AVR CrossPack](http://www.obdev.at/products/crosspack/download.html)

**Windows** -> Winavr (integrated in Atmel Studio, or [here](http://winavr.sourceforge.net)).

## Arduino libraries installation

Arduino libraries should be installed separately as a git submodule.

in the trampoline installation path:

```sh
git submodule init
git submodule update machines/avr/arduino
```

It gets the trampoline patched version of ArduinoCore-avr from [GitHub](https://github.com/TrampolineRTOS/ArduinoCore-avr.git).

## Compilation
The build script is written in Python (2.7 and 3.x) and works for Windows, Mac and Linux. The build script (make.py) is generated from goil the first time goil is called.

See examples, for the correct first call to goil (in runGoil.bat for Windows).

## flash
The avrdude port should be set as en environmemnt variable. Then, the build script can call avrdude to flash the Arduino:

example (`/dev/tty.usbmodem1421` for Mac, but may be `/dev/ttyUSB0` with Linux…).

```sh
export AVRDUDE_PORT="/dev/tty.usbmodem1421"
./make.py flash
```

# Arduino Libraries

## Installed libraries

The avr arduino installation is set in `machines/avr/arduino`. 
Default Libraries are:

* advancedIO : tone, noTone, pulseIn, …
* serial : Serial object
* spi
* i2c (refered as Wire in Arduino…).
* eeprom
* softwareSerial

To insert a library in your project, add in your .oil file (in section `CPU->OS->BUILD`):

```
      LIBRARY = serial;
```
You have an example in the `serial/` example (both Arduino Uno and Mega).

The definition is in file `goil/templates/config/avr/arduino/config.oil`


## adding your own libraries
You may need to add your own libraries, it can be added in the file `goil/templates/config/avr/arduino/config.oil`. For the SPI library for instance:

```
  LIBRARY spi {
    PATH = "avr/arduino/libraries/SPI/src"; //path from machine/
    CPPFILE = "SPI.cpp";	//list of files (CPPFILE, CFILE, ASFILE)
  };
```

There may have dependencies between libraries. For instance, adding the `LiquidCrystal_I2C` depends on Wire (i2c). You can add this information directly in the `.oil` file, or the constraint in the `config.oil` file:

```
  LIBRARY lcd_i2c {
    NEEDS   = i2c;
    PATH    = "/avr/arduino/libraries/LiquidCrystal_I2C-1.1.2";
    CPPFILE = "LiquidCrystal_I2C.cpp";
  };
```
# Using Atmel Studio
The Atmel Studio project allows to insert breakpoints and interactive debug. The generation of a project is not automatic, and should be based on the source files that are compiled in the classic `Makefile` based approach…

* create a new C++ project (ATMega328P device for Arduino Uno)
* add all the files compiled using the `./make.py -j 1` command line.
* update project properties (`projet->toolchain->C compiler->directories`) with the directories defined in the compilation rules of the 'make' command line (directories starting with -I...)
* copy and paste these directories in `C++ compiler-> directories` and `assembler/General`
* add the symbols used in the 'make' command line (starting with `-D`...) in the `symbols` part (without the `-D`)
* That's all!
