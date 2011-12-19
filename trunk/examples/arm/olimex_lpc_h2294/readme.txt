Simple example with the Olimex LPC-H2294 board (ARM7TDMI) that just blinks the LED using an alarm (1s).

To compile the example:
$ goil -g --target=arm/olimex_lpc_h2294 --templates=../../../goil/templates/ -i  lonely.oil

It will generate the Makefile.
Then, just type:
$ make
