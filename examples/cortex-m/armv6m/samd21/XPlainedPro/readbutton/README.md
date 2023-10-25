# readbutton example

## Example
This application deals with alarms.
There are two tasks : `blink` and `read_button`.

The task `blink` is activated by the alarm "blink_alarm".
The task `blink` toggles the ORANGE led whenever it is executed.

The task `read_button` is activated by the alarm `read_button_alarm`.
This task `read_button` makes polling onto the state of the push button (SW0) on the board and toggles the alarm `blink_alarm`.

The system is based scheduled with a 1ms SysTick "SystemCounter".

At the beginning of the execution, the alarm `read_button_alarm` is started, and that's all.

## Build prerequiste

You should have: 

 * A cross-compiler suite: `arm-none-eabi-gcc`
 * [openocd](http://openocd.org/) to flash the board with **` CMSIS-DAP` support**.


## Build

Configure the application with: 

```
goil --target=cortex-m/armv6m/samd21/XPlainedPro --templates=../../../../../../goil/templates/ readbutton.oil
```

The `goil` compiler generates the `make.py` [python build script](https://github.com/TrampolineRTOS/trampoline/wiki/Application-Build-system). Then run the script:

```
./make.py all
```

The `blink_exe` should be generated. Then flash the board:

```
openocd -f board/atmel_samd21_xplained_pro.cfg -c "program readbutton_exe verify reset exit"
```

Note: There is no `make.py flash` at this date, because goil cannot escape the `"` (ticket #20).

## Clean

Use the `clean` target of the make.py:

```
./make.py clean
```

