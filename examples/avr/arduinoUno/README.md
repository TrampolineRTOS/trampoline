AVR sample projects Arduino Uno boards (ATMega328P)
see the README.md in the parent folder for general information.


#first run
In the first run, the `goil` compiler generates:

* a `Makefile` (to build everything)
* C data structures related to the `.oil` description.

Build oil related generated .c and .h files and the Makefile. If `file.oil` is the main `oil` file, and `TRAMPOLINE_ROOT` is the path to the root of trampoline:

`$goil --target=avr/arduino --templates=$TRAMPOLINE_ROOT/goil/templates/ file.oil`

(The generated file .aps is an AVR Studio 4 project for Windows users).

#Build
The commands builds the binary file (both the `.elf` and `.hex` files).

`$make -s`

`goil` will now be called directly from the Makefile if the .oil file is updated, it should not be called directly again.

#flash
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
