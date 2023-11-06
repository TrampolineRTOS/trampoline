# Basic example demonstrating module of trace for the Coro Lab board (based on Nucleo-32 STM32F303 with TFT display and O/I Expander)

`
goil --target=cortex-m/armv7em/stm32f303/coroLabBoard --templates=../../../../../../goil/templates/ trace.oil
`

# Script for saving, reading and processing trace is available.
`
./readTrace.py --help
`
# To show the CPU usage, after getting the 'trace.json' file.
`
./traceCPU.py --help
`
