#readbutton example

This application deals with alarms.
There are two tasks : "blink" and ""read_button".

The task "blink" is activated by the alarm "blink_alarm".
The task "blink" toggles the GREEN led whenever it is executed.

The task "read_button" is activated by the alarm "read_button_alarm".
This task "read_button" makes polling onto the state of the push button on the board and toggles the alarm "blink_alarm" and the BLUE led.

Have a look into "alarm.oil" file.

The system is based scheduled with a 1ms SysTick "SystemCounter".

At the beginning of the execution, the alarm "read_button_alarm" is started, and that's all.
 
Configure the application with:

```sh
goil --target=msp430x/small/msp430fr5994/launchpad --templates=../../../../../../goil/templates/ readbutton.oil
```

then

```sh
./make.py
```

to compile the application

```sh
./make.py flash
```

To upload it to the board.