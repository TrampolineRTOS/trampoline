AVR sample projects Arduino Uno boards (ATMega328P)

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
$avrdude -c arduino -p m328p -P /dev/tty.usbmodem1421 -U flash:w:AVRTrampolineBin.hex
```

In this example:

  * `-p m328p` is for the ATMega328p
  * `-c avrispmkII` is the (ISP programmer on the Arduino Uno) on the USB interface. 
    Type 'avrdude -c toto' to get the full programer list
  * `-P` the device name used in the Arduino User Interface.
