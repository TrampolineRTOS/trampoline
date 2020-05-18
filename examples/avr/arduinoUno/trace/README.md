Example using the trace toolkit.

The trace toolkit allows to get back kernel events for analysis (see the related chapter in documentation/manual/main.pdf).
The trace is enabled in the .oil file and usr the serial line to get back events (binary mode).

First compile your application:

```sh
goil --target=avr/arduino/uno --templates=../../../../goil/templates/ trace.oil
./make.py
```

Then upload the example (simple blink task):
```sh
export AVRDUDE_PORT="/dev/ttyACM0"
./make.py flash
```

Then get back the trace:
```sh
./readTrace.py -s /dev/ttyACM0,115200
```

(see ./readTrace -h for other options).
