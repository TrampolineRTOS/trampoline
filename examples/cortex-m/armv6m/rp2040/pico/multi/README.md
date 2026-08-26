# Dual-core Blink example

## Example
This application is a multicore example which toggles two GPIOs (pin 0 and pin 1) of the Raspberry Pi Pico board using Inter-Core Communication (IOC).

Have a look into the `blink.oil` file.

The system is scheduled with a SysTick "SystemCounter2" and runs across 2 cores.

The task `t1_app1` (running on Core 0) toggles the state of GPIO 0 and sends this new state to Core 1 using the IOC `test_multicore`.
This task is activated by the alarm `alarm_t1_app1`. The alarm:
 * starts 100 ticks (`ALARMTIME`) after "StartOS".
 * has a 75 ticks (`CYCLETIME`) period.

The task `t1_app2` (running on Core 1) reads the state sent through the IOC and applies it to GPIO 1.
This task is activated by the alarm `alarm_t1_app2`. The alarm:
 * starts 200 ticks (`ALARMTIME`) after "StartOS".
 * has a 200 ticks (`CYCLETIME`) period.

## Expected Behavior
If you connect an LED to **GPIO 0** and another to **GPIO 1** :

* **LED on GPIO 0 (Core 0):** This LED will toggle every 75 ticks. You will observe a fast, continuous blink.
* **LED on GPIO 1 (Core 1):** This LED updates its state every 200 ticks by reading the last state sent by Core 0 over the IOC. Because it "samples" a fast-changing signal (changing every 75 ticks) at a slower rate (every 200 ticks), you will see this LED blink at a slower, staggered rate (aliasing effect). 

This visual difference perfectly demonstrates that the two cores are running concurrently on independent schedules, successfully sharing data through the RTOS Inter-Core Communication.

## Build prerequisite

You should have: 
 * A cross-compiler suite: `arm-none-eabi-gcc`
 * CMake (as the OIL file is currently configured for it)

## Build for GNU/Linux, Mac and Windows (cli)
The option `CPU->OS->BUILD->SYSTEM` in the provided configuration is set to `CMAKE`.

Configure the application with: 

'''
goil --target=cortex/armv6m/rp2040/pico --templates=../../../../../../goil/templates/ blink.oil
mkdir _build
cd build
cmake ..
make
'''

(Note: If you prefer the Trampoline Python build system mentioned in the standard template, you must change SYSTEM = CMAKE {VSCODE=TRUE;}; to SYSTEM = PYTHON; in the OIL file, then run ./make.py uf2 instead of the CMake commands).

The multi_exe.uf2 binary should be generated. To flash the board, plug it while pressing the BOOTSEL button (it should mount as a USB mass storage device). Then just copy the .uf2 file onto the USB drive.

## Clean

If you kept the CMake build system, clean the project by removing the build directory:

'''
rm -rf build/
'''

If you switched to the Python build system, use the clean target:
Bash

'''
./make.py clean
'''
