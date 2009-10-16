###############################################################################
# IMPORTS
##########
# You shall modify devices section only
###############################################################################
import device # device.SIGUSR1, device.SIGUSR2 and device.SIGALRM
from ecu import Ecu
from device import Device
from scheduler import Scheduler
from display import Display

##
# Devices
##
import timer
from timer import Timer
from dac import DAC
from lcd import LCD
from bp import BP

dispatch_display = Display(pygame = True)

###############################################################################
# SCHEDULER
##########
# You shall modify speedCoeff only
###############################################################################
scheduler = Scheduler(speedCoeff = 1)

###############################################################################
# REGISTERS
##########
# Add registers like that : reg = Register("NAME")
###############################################################################

###############################################################################
# ECUS 
##########
# You should always add registers in same order. Else there is an overlap.
# TODO I want to find out how to add registers with no order constraint
###############################################################################
allEcus = [
  Ecu(
    "../App-GBF/trampoline",
    scheduler,
    [
      # TODO : offset between delay and "real" delay. Is 0.01 too fast ???
      Timer("TIMER0", 1, type = timer.AUTO, delay = 0.01),
	  DAC("DAC0", 2),
	  LCD("LCD1", 3),
      LCD("LCD2", 4),
      BP("BPPlus", 10),
      BP("BPMinus", 11),
    ]
  )
]

