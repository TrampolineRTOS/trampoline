# Blink example

This application is a simple periodic example which toggles the Arduino M0 builtin led (pin 13).

Have a look into "blink.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

The task "blink" toggles the yellow (PA.17) led when executed.

This is not scheduled when the program starts.

This task is activated by the alarm `blink_blink`. The alarm:

 * starts 250ms (`ALARMTIME`) after "StartOS".
 * has a 250ms (`CYCLETIME`) period.

## Build prerequiste

Currently we use a SEGGER J-Link EDU to flash the Arduino M0. Launch the GDB server with the command:

```
JLinkGDBServer -device ATSAMD21J18 -if SWD

```

## Build for GNU/Linux, Mac and Windows (cli)
The option `CPU->OS->BUILD->SYSTEM` should be set to `PYTHON`.

Configure the application with: 

```
goil --target=cortex-m/armv6m/samd21/ArduinoM0 --templates=../../../../../../goil/templates blink.oil
```

The `goil` compiler generates the `make.py` [python build script](https://github.com/TrampolineRTOS/trampoline/wiki/Application-Build-system). Then run the script:

```
./make.py
```

The `blink_exe` should be generated.

## Clean

Use the `clean` target of the make.py:

```
./make.py clean
```