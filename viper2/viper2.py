#!/usr/bin/python
###############################################################################
# IMPORT
###############################################################################
import sys

sys.path.append('module')
from ecu       import Ecu
from device    import Device
from register  import Register
from scheduler import Scheduler

sys.path.append('device')
import timer
from timer     import Timer

###############################################################################
# MAIN
###############################################################################
# Scheduler
scheduler = Scheduler(speedCoeff = 3)

#Registers
 # Example : regYY = Register("YY")

#Ecu 1
# You should always add registers in same order. Else there is an overlap.
 # Exemple : ecu = Ecu(
 #    "./path/to/trampoline",
 #    scheduler,
 #    [
 #      Device("CAN0",    2, [regYY, regTX]),
 #    ]
 # )
ecu = Ecu(
    "../App-vp2/trampoline",
    scheduler,
    [
      Timer("IRQ7", 7, type = timer.AUTO, delay = 2)
    ]
)

#Generate
if "-g" in sys.argv or "--generate" in sys.argv:
  ecu.generate()
# TODO : If viper have an interruption be sure to kill trampoline instance
#Run & kill
else:
  ecu.run()
  scheduler.start()
  scheduler.kill()
  ecu.kill()
