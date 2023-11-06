# Various examples for the Teensy 3.1/3.2 board from [PJRC](https://www.pjrc.com). 

In the README.md of each example, the goil command is given to compile the OIL file.

Cortex examples use the python build system of Trampoline. Check [the documentation about this build system](https://github.com/TrampolineRTOS/trampoline/wiki/Application-Build-system).

To upload the binary to the Teensy board, you may use the graphical tool which is part of [Teensyduino](https://www.pjrc.com/teensy/td_download.html) but requires the installation of the Arduino environment and the Teensyduino add-on.

Alternatively you may use the [command line tool](https://www.pjrc.com/teensy/loader_cli.html) that is available in source code. Teensy loader is directly used by the build system with the `burn` target provided it is in the `PATH`. You may find below precompiled binaries of this tool:
* [teensy-loader-cli](https://www.dropbox.com/s/579hpikxmmswmxv/teensy-loader-cli.zip?dl=1) for Mac OS X
* [teensy-loader-cli](https://dl.dropboxusercontent.com/u/67740546/tools/teensy-loader-cli-linux.zip) for Linux 64 bits and the udev rules to access USB in userland in a separate text file (courtesy of PJRC)
