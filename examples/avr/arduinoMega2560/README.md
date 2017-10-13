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

Use the `avrdude` utility, that comes with Arduino.

```sh
avrdude -c wiring -p m2560 -D -P /dev/ttyACM0 -U flash:w:trampuinoSerial.hex
```

where:

  * `-p m2560 ` is for the ATMega2560p
  * `-c wiring ` is the (ISP programmer on the Arduino Mega) on the USB interface. 
    Type 'avrdude -c toto' to get the full programer list
  * `-P` the device name used in the Arduino User Interface (COMmunication port)
