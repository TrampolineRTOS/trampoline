AVR sample projects Arduino Mega 2560 boards (ATMega2560)
see the README.md in the parent folder for general information.

The main difference with the core of ATMega328p (Arduino Uno) is that the program counter uses 3 bytes (2 only on the ATMega328p).

#first run
In the first run, the `goil` compiler will generate:

* a python build script `make.py` (to build everything)
* C data structures related to the `.oil` description.

If `file.oil` is the main `oil` file, and `TRAMPOLINE_ROOT` is the path to the root of trampoline:

`$goil --target=avr/arduino/mega --templates=$TRAMPOLINE_ROOT/goil/templates/ file.oil`

#Build
The commands builds the binary file (both the `.elf` and `.hex` files).

`$./make.py`

`goil` will now be called directly from the python build script if the .oil file is updated, it should not be called directly again.

#flash

***DEPRECATED***

The serial device name should be defined in the oil file (`CPU -> OS -> ARDUINO section`). For example:

`      PORT = "/dev/tty.usbmodem1411";`

$make -s flash

or using `avrdude` directly:

`$avrdude -c arduino -p m328p -P /dev/tty.usbmodem1421 -U flash:w:AVRTrampolineBin.hex`

In this example:
  * `-p m328p` is for the ATMega328p
  * `-c avrispmkII` is the (ISP programmer on the Arduino Uno) on the USB interface. 
    Type 'avrdude -c toto' to get the full programer list
  * `-P` the device name used in the Arduino User Interface.
