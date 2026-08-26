# Blink example

## Example
This application is a simple periodic example which toggles the green LED of the Raspberry Pi Pico board (pin 25).

Have a look into the `blink.oil` file.

The system is scheduled with a 1ms SysTick "SystemCounter".

The task `blink` toggles the green LED when executed. It is not scheduled immediately when the program starts.

This task is activated by the alarm `blink_blink`. The alarm:
 * starts 100ms (`ALARMTIME`) after `StartOS`.
 * has a 100ms (`CYCLETIME`) period.

## Build Prerequisites

To compile this project, you will need:
 * A cross-compiler suite: `arm-none-eabi-gcc`
 * CMake and Make
 * The Raspberry Pi Pico SDK (handled by Trampoline)

## Build for GNU/Linux, Mac and Windows (CLI)
The option `CPU -> OS -> BUILD -> SYSTEM` in the `.oil` file is set to `CMAKE`.

**1. Configure the application with :

```
goil --target=cortex-m/armv6m/rp2040/pico --templates=../../../../../../goil/templates/ blink.oil
```

**2. Generate the build files and compile:**
The `goil` compiler generates the necessary CMake toolchain files. You can now build the executable:

```
mkdir _build
cd build
cmake -D CMAKE_TOOLCHAIN_FILE=../blink/compiler.cmake ..
make uf2
```

**3. Flash the board:**
The `blink_exe.uf2` file should be generated in your `build` directory. 
To flash the board, plug it into your computer via USB while holding down the white **BOOTSEL** button (it will mount as a USB mass storage device). Then, simply drag and drop or copy the `.uf2` file onto the drive.

## Clean

To clean the generated files, simply remove the build directory and the Goil-generated folders:

```
rm -rf build/ blink/
```