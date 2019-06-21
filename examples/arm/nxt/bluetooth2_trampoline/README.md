# Building TrampolineRTOS for NXT
## Compile goil with a native compiler
See folder `goil`

## Compile your NXT application
A cross compiler able to target ARM7TDMI processors is required, like `ppa:team-gcc-arm-embedded/ppa` for example.
First, run `goil -t=arm/nxt --templates=path_to_trampoline/goil/templates myfile.oil`
Then run `make`.

A `myfile_exe.rxe` file is created that you have to upload to the NXT brick before running it. 

## First NXT program on the NXT brick : enhancing the firmware
The firmware must be enhanced, like with [lms_arm_nbcnxc_xxx.rfw](http://bricxcc.sourceforge.net/test_releases/). First turn on the brick, and find the push button at the back behind the brick (bottom of a deep LEGO hole), push it during 5 seconds until you hear the brick tick. Then link the brick to your computer with the USB cable. Note that if you are using Windows, you may have the wrong driver associated to the NXT brick in flash mode (if the NXT brick is not recognized, open the Device Manager and make sure the NXT device is handled by the correct driver).
Then flash the firmware, for example with `NeXTTool /COM=usb -firmware=lms_arm_nbcnxc_xxx.rfw`

## Upload your RXE program
For this several tools exist like [Talk to NXT (t2n)](http://www-verimag.imag.fr/~raymond/edu/lego/t2n/) or NeXTTool included in [BricxCC](http://bricxcc.sourceforge.net). With t2n, the command will be like `./t2n -put myfile.nxt`, while with NeXTTool, it will be a command like `./NeXTTool /COM=usb -download=foo.rxe`
Run the program from the brick buttons and interface, quit by pressing the bottom gray button. 

