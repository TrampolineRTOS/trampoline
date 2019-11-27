# MSP430X examples
---

To build these examples you will need a toolchain (msp430-gcc and other tools), DSLite, a program to flash the board and a mspdebug, a debugger / debug server for gdb.

The easiest way is to download Energia from [https://energia.nu/download/](https://energia.nu/download/). Energia is an Arduino like environment for MSP430 launchpad boards. It comes with gcc 4.6.3 and DSLite 8.2.0.1400 (version 1.8.7E21)

Following sections are:
* Tools for Mac OS X
* Tools for Linux
* Build an application (MAC and Linux)
* Starting with GDB (MAC and Linux)



# Tools for Mac OS X

Put Energia application in your Applications folder. The path is

```sh
/Applications/Energia.app
```

## Toolchain

Starting from the path above, the toolchain binaries are located in ```Contents/Java/hardware/tools/msp430/bin```. Edit your ```~/.profile``` file and add this line:

```sh
export PATH=$PATH:/Applications/Energia.app/Contents/Java/hardware/tools/msp430/bin
```

## DSLite

DSLite is located in ```Contents/Java/hardware/tools/DSLite/DebugServer/bin```. Add this line in your ```~/.profile``` file:

```sh
export PATH=$PATH:/Applications/Energia.app/Contents/Java/hardware/tools/DSLite/DebugServer/bin
```

## mspdebug 0.25

mspdebug 0.25 is available through [homebrew](https://brew.sh) or [MacPorts](https://www.macports.org)

# Tools for Linux
(tested on Ubuntu 18.04 - 64 bits)

Extract the archive to your installation path (`/opt` for instance) and [set the udev rules](https://energia.nu/guide/install/linux/).

## Toolchain

Starting from the path above (`/opt`), the toolchain binaries are located in `/opt/energia/hardware/tools/msp430/bin/. Edit your ~/.bashrc` file and add these lines:

```sh
export LD_LIBRARY_PATH=/opt/energia/hardware/tools/DSLite/DebugServer/drivers:$LD_LIBRARY_PATH
export PATH=/opt/energia/hardware/tools/msp430/bin:$PATH
```
## DSLite

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

# Build an application (MAC and Linux)
Go to an example directory (for instance with launchpad for MSP430FR5994):
```sh
cd small/msp430fr5994/launchpad/blink/
```
The first time, the goil compiler should be called directly. Goil will generate application related files, depending on the .oil configuration:
* os data structures (optimized for the application)
* application data structures (descriptors for tasks, alarms, …)
* build scripts

The goil command is always given in the README.md file of the example. For instance with the blink example:
```sh
goil --target=msp430x/small/msp430fr5994/launchpad --templates=../../../../../../goil/templates/ blink.oil
```
Then, a python build script is generated, and it will call goil again if the .oil file is updated. So there is no need to call directly goil again. We now need to compile and flash the board:
```sh
./make.py
./make.py flash
```
And blink!

# Starting with GDB (MAC and Linux)

in a first terminal, make the connection between board and gdb using mspdebug (that acts as a gdb server)

```sh
mspdebug tilib gdb
```
If it works fine annd the board is correctly recognized, it should print something like
```
MSPDebug version 0.25 - debugging tool for MSP430 MCUs
[]...]
Bound to port 2000. Now waiting for connection...
```

Then, in a second terminal, use the msp430 version of the gdb client (application should have been uploaded)

```sh
msp430-gdb -tui ./blink_exe
```
Then, in the gdb console, we just connect to mspdebug on port 2000:
```
Reading symbols from [...]examples/msp430x/small/msp430fr5994/launchpad/blink/blink_exe...done.
(gdb) target remote localhost:2000
(gdb)
```
