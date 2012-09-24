Simple example with the Olimex LPC-H2294 board (ARM7TDMI) that just blinks the LED using an alarm (1s).

To compile the example:
$ goil --target=arm/olimex_lpc_h2294 --templates=../../../goilv2/templates/   lonely.oil

It will generate the Makefile.
Then, just type:
$ make
