###############################################################################
# IMPORTS
##########
# You shall modify devices section only
###############################################################################
import device # device.SIGUSR1, device.SIGUSR2 and device.SIGALRM
from ecu import Ecu
from device import Device
from register import Register
from scheduler import Scheduler
from display import Display

##
# Devices
##
import timer
from timer import Timer
from isr import ISR
from server import DisplayServer
from power import Power

###############################################################################
# DISPLAY
##########
# You shall modify pygame to True or False if you want or not to use pygame (True by default)
# You shall modify screen if you want to change screen dimensions ([800, 600] by default)
###############################################################################
dispatch_display = Display(pygame = False, screen = [400, 560])

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
# CAN NETWORK
##########
# Add Can Network if needed
###############################################################################

###############################################################################
# PYGAME WIDGETS
##########
# Add Pygame widgets if needed (for example, a screen which displays several
# information coming from several application
###############################################################################

###############################################################################
# ECUS 
##########
# You should always add registers in same order. Else there is an overlap.
###############################################################################
allEcus = [
  Ecu(
    "../check/functional/SEQUENCE/SEQUENCE_exe",
    scheduler,
    [
      Timer("TIMER0", 0, type = timer.AUTO, delay = 10),
      ISR("ISR1", 1),
      ISR("ISR2", 2),
      ISR("ISR3", 3),
      Power("POWER",4),
    ]
  )
]

