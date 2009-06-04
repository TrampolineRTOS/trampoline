#!/usr/bin/python
###############################################################################
# IMPORT
###############################################################################
import sys, signal

sys.path.append('module')
from ecu       import Ecu
from device    import Device
from register  import Register
from scheduler import Scheduler

##
# Devices
##
sys.path.append('device')
import timer
from timer     import Timer

###############################################################################
# GLOBALS VARIABLES
###############################################################################
scheduler = None

###############################################################################
# SIGNAL HANDLER
###############################################################################
def signalHandler(signum, stackFrame):
  print "\nSignal catch, stop Viper 2..."
  scheduler.kill()

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
 #    "./path/to/trampoline_executable",
 #    scheduler,
 #    [
 #      Device("CAN0",    2, [regYY, regTX]),
 #    ]
 # )
allEcus = [
  Ecu(
    "../App-vp2/trampoline",
    scheduler,
    [
      Timer("IRQ7", 7, type = timer.AUTO, delay = 2)
    ]
  )
]

#Generate
if "-g" in sys.argv or "--generate" in sys.argv:
  for ecu in allEcus:
    ecu.generate()

#Run & kill
else:
  try:
    """ Signal handler """
    # CTRL+C
    signal.signal(signal.SIGINT, signalHandler)

    """ Start all ecus """
    for ecu in allEcus:
      ecu.start()

    """ Start logical scheduler """
    scheduler.start()

  except Exception, e:
    print str(e)

  finally:
    """ Kill logical scheduler """
    scheduler.kill()

    """ Kill all ecus """
    for ecu in allEcus:
      ecu.kill()

    print "\nBye,"
