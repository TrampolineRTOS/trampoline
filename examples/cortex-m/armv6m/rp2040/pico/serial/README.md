# Serial example

Simple example using the serial uart (using SDK).
** It does not work yet with interrupts **
** printf not yet supported **

The uart is on pin 0 (tx) and 1 (rx) (default). You can use the picoprobe as a uart-to-usb converter.
 
Configure the application with: 

```
goil --target=cortex/armv6m/rp2040/pico --templates=../../../../../../goil/templates/ serial.oil
```

then use the CMake compilation steps and build the .uf2 tarfet file.
```
mkdir _build
cd _build
cmake -D CMAKE_TOOLCHAIN_FILE=../serial/compiler.cmake ..
make
make uf2
```

The flash.uf2 binary file should be generated. To flash the board, plug it while pressing the reset button (it should be understood as a USB key). Then just copy the .uf2 file on the USB key.

