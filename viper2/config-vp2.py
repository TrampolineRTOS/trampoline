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

##
# Devices
##
import timer
from timer import Timer
from motor import Motor

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
sensor = Register("SENSOR")
control = Register("CONTROL")

###############################################################################
# ECUS 
##########
# You should always add registers in same order. Else there is an overlap.
# TODO I want to find out how to add registers with no order constraint
###############################################################################
allEcus = [
  Ecu(
    "../App-vp2/trampoline",
    scheduler,
    [
      Timer("TIMER0", 7, type = timer.AUTO, delay = 0.5),
      Motor("MOTOR0", 2, sensor, control, noise = 5),
    ]
  )
]

