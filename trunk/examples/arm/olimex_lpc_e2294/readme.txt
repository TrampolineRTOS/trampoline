
- Here is a description of the application :
	* This application starts by checking the real-time scheduling by activating task1 wich will activate and launch task3 before terminating itself (this will print 123 (for the 3 steps) on the lcd).
	* task2 is activated by an autostart alarm (with a period of 1s) and blink the lcd light.
	* If you press B1 "B1 pressed" is displayed on the lcd.
	* If you press B2 "B2 pressed" is displayed on the lcd.
  
- This tests the drivers for the timers (timer0 to initialize lcd and timer1 with IRQ for systemcounter) and the lcd in the same time. It also checks the externals interrupts on the two push buttons.

- To get it works, you'll need :
	* Get libpm from http://galgas.rts-software.org/download/ and copy it to trunk/
	* Compile GOIL (on MAC OS for example) -> cd ../../../goil/makefile_macosx/; make -j2 goil; cp goil /usr/local/bin/
	* Install openOCD and the D2XX drivers (OR libusb AND libftdi as you want) to communicate to the JTAG
	* Compile the application -> goil -t=arm/olimex_lpc_e2294 --templates=../../../goil/templates/ -g -i lonely.oil; make
	* Upload your program into the board :
		- by opening the OPENOCD communication --> click on 2-run-openocd.command
		- and launch your program --> click on2a-debug-external-ram.command for example

The manual is beeing made in documentation/olimex/olimex_manual.pdf
