0) What is needed
libusb (with homebrew) : http://brew.sh
stlink : https://github.com/texane/stlink
gcc : arm-none-eabi-gcc (GNU Tools for ARM Embedded Processors) 4.8.4 20140526 (release) [ARM/embedded-4_8-branch revision 211358]

1) Generates the files with :
> goil --target=thumb2/cortex-m4/STM32F4-Discovery -v --templates=../../../../../goilv2/templates/ periodic4.oil

2) Compile and link with
> make clean
> make

3) Builds different binary formats with
> make img

4) Connect a STM32F4-DISCOVERY from ST with a USB cable

5) Flash the binary with
> make burn

6) Debug 
6.1) Launch st-link
In a terminal launch the server st-link
6.2) Launch gdb
In another terminal launch gdb with
> arm-none-eabi-gdb periodic4_exe

Then type the following command inside gdb
(gdb) source init.gdb

You are ready to debug
