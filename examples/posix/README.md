# Trampoline examples for Posix Targets

This directory shows some examples for the POSIX target. The Posix target run Trampoline inside a Unix process. 

To simulate the environment, another process runs ViPER (Virtual Processor EmulatoR). Viper can emulate a timer and send periodically a signal to the Trampoline process. This way, Trampoline get a SystemCounter.

More information is available on this (not really up-to-date) [publication](http://trampoline.rts-software.org/IMG/pdf/trampoline.pdf) at 11th International Conference on Emerging Technologies and Factory Automation (ETFA'06) (in particular, see section 6.2 and figure 4)

## Building ViPER
on UNIX shell:

    $ cd viper
    $ make
    $ export VIPER_PATH=`pwd`

It is recommended to get the path to ViPER in the environment variables, and define in the ~/.bashrc or ~/.profile the command:

    $ export VIPER_PATH=PATH_TO_TRAMPOLINE/viper

## Run example
Examples are easy to run:
The first time, goil should be called directly. It will generate the appropriate Makefile:

    $ cd examples/posix/periodic
    $ goil --target=posix/linux  --templates=../../../goil/templates/ periodic.oil

Or if you run the example on OSX Intel instead of Linux, 

    $ cd examples/posix/periodic
    $ goil --target=posix/darwin  --templates=../../../goil/templates/ periodic.oil

Or if you run the example on OSX Apple Silicon

    $ cd examples/posix/periodic
    $ goil --target=posix/darwin/arm64  --templates=../../../goil/templates/ periodic.oil

Then, the makefile is generated, and it will call goil again when the .oil file is updated

    $ ./make.py -s

Then, run the trampoline binary. This program will start another process to run ViPER silently.

    $ ./periodic_exe

If the trace tools are enabled in OIL file, the execution will create a trace file named "trace.json" and a python script to check the log generated.

    $ ./readtrace.py

