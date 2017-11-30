AVR sample projects Arduino Mega 2560 boards (ATMega2560)
see the README.md in the parent folder for general information.
The main difference with the core of ATMega328p (Arduino Uno) is that the program counter uses 3 bytes (2 only on the ATMega328p).

***Be sure that Arduino related libraries are installed: see [README.md](../README.md) in parent folder***

# first run
In the first run, the `goil` compiler will generate:

* a python build script `make.py` (to build everything)
* C data structures related to the `.oil` description (in directory with the name of the .oil file, but with no extension)

If `file.oil` is the main `oil` file, and `TRAMPOLINE_ROOT` is the path to the root of trampoline:

`$goil --target=avr/arduino/uno --templates=$TRAMPOLINE_ROOT/goil/templates/ file.oil`

# Build
The commands builds the binary file (both the `.elf` and `.hex` files).

`$./make.py`

`goil` will now be called directly from the python build script if the .oil file is updated, it should not be called directly again.

in case of problem, you may need to run `./make.py -j 1` to have the full compilation line.

# flash

The avrdude port should be set as en environmemnt variable. Then, the build script can call avrdude to flash the Arduino:

example (`/dev/tty.usbmodem1421` for Mac, but may be `/dev/ttyUSB0` with Linux…).

```sh
export AVRDUDE_PORT="/dev/tty.usbmodem1421"
./make.py flash
```

or using `avrdude` directly:

```sh
$avrdude -c arduino -p m2560 -P /dev/tty.usbmodem1421 -U flash:w:AVRTrampolineBin.hex
```

In this example:

  * `-p m2560` is for the ATMega2560
  * `-c wiring` is the (ISP programmer on the Arduino Mega) on the USB interface. 
    Type 'avrdude -c toto' to get the full programer list
  * `-P` the device name used in the Arduino User Interface (COMmunication port)
