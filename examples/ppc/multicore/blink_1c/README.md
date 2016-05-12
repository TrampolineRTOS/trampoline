#Trampoline examples for PowerPC target

This is a simple blink example, tested and working for MPC5643L target using
Cosmic Software compiler. An alarm wakes up a task which will turn on/off the
led.

##Compile example
To compile the example, you will need to install the VLE evaluation tools Cosmic
Software through wine and set the COSMIC_PATH environment variable accordingly
to the install path of Cosmic Software's executables. The path must not contain
spaces. In that case, please create a soft symlink using 'ln -s' command.
Example : Cosmic executables are installed by default by wine in
          ~/.wine/drive_c/Program\ Files/COSMIC/CXVLE_16K/
        $ ln -s ~/.wine/drive_c/Program\ Files/COSMIC/CXVLE_16K/ ~/cosmic
        $ export COSMIC_PATH=~/cosmic
        $ ./run.sh -a

