# MSP430X examples

To build these examples you will need a toolchain (msp430-gcc and other tools), DSLite, a program to flash the board and a mspdebug, a debugger / debug server for gdb.

The easiest way is to download Energia from [https://energia.nu/download/](https://energia.nu/download/). Energia is an Arduino like environment for MSP430 launchpad boards. It comes with gcc 4.6.3 and DSLite 8.2.0.1400 (version 1.8.7E21)

## Mac OS X

Put Energia application in your Applications folder. The path is

```sh
/Applications/Energia.app
```

### Toolchain

Starting from the path above, the toolchain binaries are located in ```Contents/Java/hardware/tools/msp430/bin```. Edit your ```~/.profile``` file and add this line:

```sh
export PATH=$PATH:/Applications/Energia.app/Contents/Java/hardware/tools/msp430/bin
```

### DSLite

DSLite is located in ```Contents/Java/hardware/tools/DSLite/DebugServer/bin```. Add this line in your ```~/.profile``` file:

```sh
export PATH=$PATH:/Applications/Energia.app/Contents/Java/hardware/tools/DSLite/DebugServer/bin
```

### mspdebug 0.25

mspdebug 0.25 is available through [homebrew](https://brew.sh) or [MacPorts](https://www.macports.org)

## Linux
(tested on Ubuntu 18.04 - 64 bits)

Extract the archive to your installation path (`/opt` for instance) and [set the udev rules](https://energia.nu/guide/install/linux/).

### Toolchain

Starting from the path above (`/opt`), the toolchain binaries are located in `/opt/energia/hardware/tools/msp430/bin/. Edit your ~/.bashrc` file and add these lines:

```sh
export LD_LIBRARY_PATH=/opt/energia/hardware/tools/DSLite/DebugServer/drivers:$LD_LIBRARY_PATH
export PATH=/opt/energia/hardware/tools/msp430/bin:$PATH
```
### DSLite

DSLite is located in `/opt/energia/hardware/tools/DSLite/DebugServer/bin/DSLite`. Add this line in your `~/.bashrc` file:

```sh
export PATH=/opt/energia/hardware/tools/DSLite/DebugServer/bin:$PATH
```
### mspdebug 0.25
The mspdebug version provided with Energia does not work correctly with GDB at this time (10/2019). The best way is to compile it again [from sources on GitHub](https://github.com/dlbeer/mspdebug):

```sh
git clone https://github.com/dlbeer/mspdebug.git
cd mspdebug/
make
sudo make install
```
