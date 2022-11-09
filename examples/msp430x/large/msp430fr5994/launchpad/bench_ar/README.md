# AR benchmark for msp430fr5994

This benchmark is adapted from https://github.com/tinysystems/ImmortalThreads/tree/main/runtime/test/benchmarks/ar


## To configure the application
```sh
goil --target=msp430x/large/msp430fr5994/launchpad --templates=PATH_TO_TRAMPOLINE/goil/templates main.oil 
```

## To compile
```sh
./make.py
```

## To flash
```sh
./make.py flash
```