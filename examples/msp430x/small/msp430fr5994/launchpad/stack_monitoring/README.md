#readbutton isr2 example

The task ```blink``` is activated by the alarm ```blink_alarm```.
The task ```blink``` check if the stack overflow and a led is turn on accordingly.


Have a look into ```stack_monitoring.oil``` file.

The system is based scheduled with a 1ms SysTick ```SystemCounter```.
 
Configure the application with:

```sh
goil --target=msp430x/small/msp430fr5994/launchpad --templates=../../../../../../goil/templates/ stack_monitoring.oil
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
