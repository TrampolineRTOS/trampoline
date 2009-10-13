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
from bp import BP
from lcd import LCD
from motor import Motor
from can import CAN
from can import CAN_Network
from dac import DAC

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

###########
# CAN NETWORK
######
can_net = CAN_Network()

###############################################################################
# ECUS 
##########
# You should always add registers in same order. Else there is an overlap.
# TODO I want to find out how to add registers with no order constraint
###############################################################################
allEcus = [
  Ecu(
    "../App-Ecu1/trampoline",
    scheduler,
    [
      Timer("TIMER0", 0, type = timer.AUTO, delay = 0.1),
      Timer("TIMER1", 1, type = timer.AUTO, delay = 0.2),
      Timer("TIMER2", 2, type = timer.AUTO, delay = 1),
	  LCD("LCD1", 3),
	  LCD("LCD2", 4),  
	  LCD("LCD3", 5),   
      Motor("MOTOR1",6),
      Motor("MOTOR2",7),
	  DAC("DAC1", 10),
	  DAC("DAC2", 11),
	  DAC("DAC3", 12),
	  DAC("DAC4", 23),
	  DAC("DAC5", 24),
      BP("BP1", 13),
      BP("BP2", 14),
      BP("BP3", 15),
      BP("BP4", 16),
      BP("CAN", 17),
      BP("MTR1_PLUS", 18),
      BP("MTR1_MINUS", 19),
      BP("MTR2_PLUS", 20),
      BP("MTR2_MINUS", 21),
      CAN(can_net, "CAN1", 22, 1),
    ]
  ),
  Ecu(
    "../App-Ecu2/trampoline",
    scheduler,
    [
      Timer("TIMER2", 1, type = timer.AUTO, delay = 0.1),
      LCD("LCD2", 2),
      BP("BP2", 3),
    ]
  )
]

