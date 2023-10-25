# Trampoline CAN demo example

This example allows to test the Trampoline CAN stack on the Spider board.

## Hardware setup

Connect a CAN probe to the Spider board CAN0 SUB-D 9 connector (CN13A).

For the test, we used a Kvaser USBcan Pro 2xHS v2 connected to a Windows 10 PC running the Kvaser CanKing software.
As the Kvaser probe does not provide CAN bus terminating resistors, we made a little adaptation PCB with terminating resistors.
For that, we cut in half two DB-9 cables and kept the two female parts.
On the PCB, we wired the DB-9 pins 7 together (the CAN high signal), the DB-9 pins 2 together (the CAN low signal) and the DB-9 pins 3 together (the CAN ground).
Between the DB-9 pin 7 and pin 3 we soldered a 60 ohms resistors, we also added a second 60 ohms resistors between the DB-9 pin 2 and pin 3.

## Software setup

The Kvaser CanKing CAN bus configuration is as follow :
* CAN Mode : CAN FD
* Both Arbitration Phase and Data Phase parameters set to :
  * Bus speed : 1000 Kbit/s, 80%.
  * SJW : 8
  * Bit timing : Tseg1=31, Tseg2=8.

No configuration is needed on the CAN demo application side.

## Building

### Prerequisites

A PC running Windows 10 or above is needed.
* First, install the free version of the [RH850 Compiler CC-RH for CS+](https://www.renesas.com/us/en/document/ucm/rh850-compiler-cc-rh-v20500-cs?r=1169506) to the default location. The version 2.05.00 was used at the time of writing.
* Install [Cygwin](https://www.cygwin.com/setup-x86_64.exe). Select the `cmake` and `make` packages during installation. The CMake version used at the time of writing is 3.24.2.

### Building

Open a Cygwin terminal and go to the Trampoline directory.
Then, run the following commands :

```
# Tell the build system where the compiler is located
export HLNK_DIR='C:\Program Files (x86)\Renesas Electronics\CS+\CC\CC-RH\V2.05.00'

cd examples/rh850/can_demo
./build.sh
```

If you want to generate a `.srec` file to directly flash on the board, look at the `memory_unlocker` example `build.sh` script in the same directory than the `can_demo`.

## Running

Before starting the CAN demo application, connect the hardware setup and configure the Kvaser CanKing application as described in the above paragraphs.
Then, click the CanKing `Go On Bus` button.
Now, you can run the CAN demo application.

The CAN demo application starts by sending a CAN frame with the CAN ID `0x123` and the string payload `Ready!`.
After that, it waits for a CAN frame to be received. When a frame is received, it increments the CAN ID and all the payload bytes, then it sends the frame back.
