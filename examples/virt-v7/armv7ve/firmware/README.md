|=-----=[ Blink example ]=-----=|

This application is a simple periodic example which prints a periodic message on an UART console.
This application can be launched with a bootloader that will be soon pushed on the GitHub.

For the moment the application must be copied on the Raspberry Pi 2 sdcard.
It can be launched

How to build the example:
Generates the code:
```
goil --target=virt-v7/armv7ve --templates=../../../../goil/templates/ firmware.oil
```

Build:
```
./make.py
```
```
cp firmware.elf.bin ~/vboxshare/freenivi/firmware.bin
```
