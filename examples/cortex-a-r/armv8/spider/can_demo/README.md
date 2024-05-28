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

On Linux :
```
cd examples/cortex-a-r/armv8/spider/can_demo
goil --target=cortex-a-r/armv8/spider --templates=../../../../../goil/templates/ can_demo.oil
./make.py
```

## Running

### Using Kvaser CanKing

Before starting the CAN demo application, connect the hardware setup and configure the Kvaser CanKing application as described in the above paragraphs.
Then, click the CanKing `Go On Bus` button.
Now, you can run the CAN demo application.

The CAN demo application starts by sending a CAN frame with the CAN ID `0x123` and the string payload `Ready!`.
After that, it waits for a CAN frame to be received. When a frame is received, it increments the CAN ID and all the payload bytes, then it sends the frame back.

### Using canfdtest on Linux

For this test we used `Ubuntu 23.10` as it is the first Ubuntu version containing a recent enough version of the `can-utils` package (the minimal required version of the `can-utils` package is `v2023.03`).

* Install the required package :
  ```
  sudo apt install can-utils
  ```
  Note : it is also possible to build the `can-utils` package from sources to run it on older Linux versions (see [https://github.com/linux-can/can-utils/releases/tag/v2023.03](https://github.com/linux-can/can-utils/releases/tag/v2023.03)).
* Start the CAN demo application on the board.
* Then, execute the following commands on the Linux PC :
  ```
  # Configure the CAN interface for CAN-FD operations without bit rate switch
  sudo ip link set can0 type can bitrate 1000000 dbitrate 1000000 fd on
  sudo ip link set up can0

  # Run the test (the PC generates the frames and the board sends the answers)
  # Generate CAN-FD frames without bit rate switch
  canfdtest -d -g -v can0
  ```
* When frames are correctly transmitted and received, the output of the program looks like :
  ```
  baylibre@baylibre:~$ canfdtest -d -g -v can0
  interface = can0, family = 29, type = 3, proto = 1
  .................................................................
  ```
* On another terminal on the PC, you can display the CAN bus load, showing that frames are being transmitted :  
  Run the command : `canbusload -b can0@1000000`.  
  The output of the program looks like :
  ```
  baylibre@baylibre:~$ canbusload -b can0@1000000
  can0@1000000   963  131931  61632      0  13% |XX..................|

  can0@1000000  1061  145357  67904      0  14% |XX..................|

  can0@1000000  1012  138644  64768      0  13% |XX..................|
  ```
