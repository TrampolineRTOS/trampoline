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

###############################################################################
# DISPLAY
##########
# You shall modify pygame to True or False if you want or not to use pygame (True by default)
# You shall modify screen if you want to change screen dimensions ([800, 600] by default)
###############################################################################
dispatch_display = Display(pygame = True, screen = [560, 320])

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
    "../examples/viper2/App-GBF/trampoline",
    scheduler,
    [
      Timer("TIMER0", 1, type = timer.AUTO, delay = 10),
	  DAC("DAC0", 2, position = [0, 0] ),
	  LCD("LCD1", 3, position = [360, 0] ),
      LCD("LCD2", 4, position = [360, 120] ),
      BP("BPPlus", 10, position = [360, 240], picture="pictures/BPPlus"),
      BP("BPMinus", 11, position = [460, 240], picture="pictures/BPMinus" ),
    ]
  )
]

