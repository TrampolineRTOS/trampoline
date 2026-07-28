# Blink example

## Example
This application is a simple periodic example which toggles the green led of the board (pin 25)

Have a look into "blink.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

The task "blink" toggles the green led when executed.
This is not scheduled when the program starts.

This task is activated by the alarm `blink\_blink`. The alarm:

 * starts 250ms (`ALARMTIME`) after "StartOS".
 * has a 250ms (`CYCLETIME`) period.

## Build prerequiste

You should have either: 

 * A cross-compiler suite: `arm-none-eabi-gcc`

## Build for GNU/Linux, Mac and Windows (cli)
The option `CPU->OS->BUILD->SYSTEM` should be set to `PYTHON`.

Configure the application with: 

```
goil --target=cortex/armv6m/rp2040/pico --templates=../../../../../../goil/templates/ blink.oil
```

The `goil` compiler generates the `make.py` [python build script](https://github.com/TrampolineRTOS/trampoline/wiki/Application-Build-system). Then run the script:

```
./make.py uf2
```

The `blink_exe` should be generated. To flash the board, plug it while pressing the reset button (it should be understood as a USB key). Then just copy the .uf2 file on the USB key.

## Clean

Use the `clean` target of the make.py:

```
./make.py clean
```
