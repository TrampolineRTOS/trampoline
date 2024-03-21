# Fault Injection application example

The system is based scheduled with a 1ms SysTick "SystemCounter".

Configure the application with

This  application is designed to call system calls that have no temporal impact in 2 situations: with or without context switching.
In nominal operation, the application must pass through 21 checkpoints in a defined order. 

During fault injection, any deviation in the order in which these checkpoints are passed, or the absence of any checkpoint, corresponds to an undetected fault (SDC).
This application is used to determine the instrumentation tradeoff required within the trampoline kernel with the Harvest framework.

``
goil --target=cortex/armv7m/SmartFusion2/starterKit --templates=../../../../../../goil/templates/ FI_appli.oil
``

Then make with:

``
./make.py
``

The executable should be flashed using SoftConsole from Microsemi on Windows.