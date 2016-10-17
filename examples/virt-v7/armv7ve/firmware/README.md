|=-----=[ Tracking example ]=-----=|

This application is a light tracking system built with an Arduino Duo.
It communicates with an UART line with the Arduino board.

This application must be launched inside a XVisor guest.

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
cp firmware.elf.bin <custom directory for building XVisor image>/firmware.bin
```
```
arm-none-eabi-objdump -x firmware.elf > firmware.elf.hd
```
```
arm-none-eabi-objdump -dS firmware.elf > firmware.elf.dump
```
