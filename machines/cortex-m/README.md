# Port for thumb2 instruction set

This port has been tested on a STM32F4-DISCOVERY board equipped with a STM32F407VGT6 microcontroller featuring 1 MB of Flash memory and 192 KB of RAM.


## What is implemented in this port

This port supports switch context, call of all exceptions, ISR1 and ISR2, nested exceptions calls.

## Know bugs

There may be a problem with start of the board after a reset once in a while. We don't know if this is due to the board or the software, 
this will be hopefully tested soon.

## Todo list

* Memory protection
* Trusted functions

## Future port

We will soon update this port for a cortex-m0.

