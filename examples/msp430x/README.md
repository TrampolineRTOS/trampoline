# MSP430X examples

To build these examples you will need a toolchain (msp430-gcc and other tools), DSLite, a program to flash the board and a mspdebug, a debugger / debug server for gdb.

The easiest way is to download Energia from [https://energia.nu/download/](https://energia.nu/download/). Energia is an Arduino like environment for MSP430 launchpad boards. It comes with gcc 4.6.3 and DSLite 8.2.0.1400 (version 1.8.7E21)

## Mac OS X

Put Energia application in your Applications folder. The path is 

```
/Applications/Energia.app
```

### Toolchain

Starting from the path above, the toolchain binaries are located in ```Contents/Java/hardware/tools/msp430/bin```. Edit your ```~/.profile``` file and add this line:

```
export PATH=$PATH:/Applications/Energia.app/Contents/Java/hardware/tools/msp430/bin
```

### DSLite

DSLite is located in ```Contents/Java/hardware/tools/DSLite/DebugServer/bin```. Add this line in your ```~/.profile``` file:

```
export PATH=$PATH:/Applications/Energia.app/Contents/Java/hardware/tools/DSLite/DebugServer/bin
```

### mspdebug 0.25

mspdebug 0.25 is available through [homebrew](https://brew.sh) or [MacPorts](https://www.macports.org)

## Linux
