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
* Bus speed : 125 Kbit/s.
* Sample point : 75% (Tseg1 = 11, TSeg2 = 4).
* SWJ (Synchronization Jump Width) : 4.

No configuration is needed on the CAN demo application side.

## Building

On Linux :
```
cd examples/cortex-a-r/armv8/spider/can_demo
goil --target=cortex-a-r/armv8/spider --templates=../../../../../goil/templates/ can_demo.oil
./make.py
```

## Running

Before starting the CAN demo application, connect the hardware setup and configure the Kvaser CanKing application as described in the above paragraphs.
Then, click the CanKing `Go On Bus` button.
Now, you can run the CAN demo application.

The CAN demo application starts by sending a CAN frame with the CAN ID `0x123` and the string payload `Ready!`.
After that, it waits for a CAN frame to be received. When a frame is received, it increments the CAN ID and all the payload bytes, then it sends the frame back.
