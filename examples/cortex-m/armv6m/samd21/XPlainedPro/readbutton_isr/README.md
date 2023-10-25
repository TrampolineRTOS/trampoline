# readbutton example

## Example
This application deals with alarms and ISR2.
There are two tasks "blink" and "read_button" and one ISR2 "isr_button".

At start the program does nothing.
Something happens when pushing the button on the board.
A push on the button (isr_button) starts the alarm "blink_alarm".

This alarm "blink_alarm" will activate the task "blink" on expiration and start again (each 100ms).

Have a look into "readbutton_isr.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

## EIC external interrupt handling

On the SAMD21, there is only one interrupt entry for all external interrupts: `EIC`. A second level is required and is generated in the `tpl_app_config.c` file. 

Parameters for the configurations of an EIC entry is defined using the `PIN` (`PA15`, `PB0`, …). From the pin name, the EIC entry is deducted. A pin has the following sub-parameters:

 * the `TRIGGER`: which may be `FALLING`, `RISING` or `BOTH`;
 * the PULL that may be `UP`, `DOWN` or `NONE`
 * the FILTERING (either `TRUE`or `FALSE`).

see the `.oil` file for a complete example.

**NOTE** The `EIC` peripheral **should** be initialised (both clock and power). See the `.c` file for example.

## Build prerequiste

You should have: 

 * A cross-compiler suite: `arm-none-eabi-gcc`
 * [openocd](http://openocd.org/) to flash the board with **` CMSIS-DAP` support**.


## Build

Configure the application with: 

```
goil --target=cortex-m/armv6m/samd21/XPlainedPro --templates=../../../../../../goil/templates/ readbutton_isr.oil
```

The `goil` compiler generates the `make.py` [python build script](https://github.com/TrampolineRTOS/trampoline/wiki/Application-Build-system). Then run the script:

```
./make.py all
```

The `blink_exe` should be generated. Then flash the board:

```
openocd -f board/atmel_samd21_xplained_pro.cfg -c "program readbutton_isr_exe verify reset exit"
```

Note: There is no `make.py flash` at this date, because goil cannot escape the `"` (ticket #20).

## Clean

Use the `clean` target of the make.py:

```
./make.py clean
```
