# Blink example

This application is a simple periodic example which toggles between two tasks in PULPino.

Have a look into "blink.oil" file.

The system is based scheduled with a 1ms SysTick "TA_CMP".

## Build prerequiste

This build requires that `spiload` is installed at the ZedBoard. The procedure is exposed [here](https://github.com/pulp-platform/pulpino/tree/master/fpga).

Currently we use a SSH connection to flash PULPino. After connecting the ZedBoard Ethernet interface and retrieving its IP address, export the variable `FPGA_HOSTNAME` so it has the form

```
export FPGA_HOSTNAME="root@ZEDBOARD_IP"
```

Now you should be able to connect through ssh to the board. It might be useful to install your public key (with `ssh-copy-id`) so the board password is not asked at each interaction.

You should also export the `PULPINO_PATH` variable, that points to the root of your PULPino installation.

## Build for GNU/Linux
The option `CPU->OS->BUILD->SYSTEM` should be set to `PYTHON`.

Configure the application with: 

```
goil --target=riscv/pulpino --templates=../../../../goil/templates blink.oil
```

The `goil` compiler generates the `make.py` [python build script](https://github.com/TrampolineRTOS/trampoline/wiki/Application-Build-system). Then run the script:

```
./make.py
```

The `blink_exe` should be generated.

To copy the executable to the board and flash it on PULPino memories, the following commands are used.

```
scp slm_files/spi_stim.txt $FPGA_HOSTNAME:/root/blink.spi
ssh -t $FPGA_HOSTNAME /root/spiload --timeout=-1 /root/blink.spi
```

## Clean

Use the `clean` target of the make.py:

```
./make.py clean
```
