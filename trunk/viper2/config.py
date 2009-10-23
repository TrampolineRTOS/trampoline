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
from bp import BP
from server import LCDServer
from server import Server
from can import CAN_Network
from can import CAN
from motor import Motor

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
# CAN NETWORK
##########
# Add Can Network if needed
###############################################################################
can_net1 = CAN_Network()
can_net2 = CAN_Network()

###############################################################################
# PYGAME WIDGETS
##########
# Add Pygame widgets if needed (for example, a screen which displays several
# information coming from several application
###############################################################################
display_server = Server("LCDSERVER") # uses pygame

###############################################################################
# ECUS 
##########
# You should always add registers in same order. Else there is an overlap.
###############################################################################
allEcus = [
  Ecu(
    "../App-RobotPC/trampoline",
    scheduler,
    [
      # TODO : offset between delay and "real" delay. Is 0.01 too fast ???
      # TODO : LCD doesn't send signal to Trampoline but uses an id.
      #        --> Try to find how to do to keep this id free.
      CAN(can_net1, "CAN0", 0),
      Timer("TIMER0", 1, type = timer.AUTO, delay = 1),
      BP("BPFaster", 5),
      BP("BPSlower", 6),
      BP("BPLeft", 7),
      BP("BPRight", 8),
    ]
  ),
  Ecu(
    "../App-Robot1/trampoline",
    scheduler,
    [
      # TODO : offset between delay and "real" delay. Is 0.01 too fast ???
      # TODO : LCD doesn't send signal to Trampoline but uses an id.
      #        --> Try to find how to do to keep this id free.
      CAN(can_net1, "CAN1_1", 0),
      Timer("TIMER0", 1, type = timer.AUTO, delay = 0.1),
      LCDServer("LCD1", 2, display_server),      
      Motor("MOTOR1_1",3),
      Motor("MOTOR1_2",4),
      CAN(can_net2, "CAN1_2", 5),
    ]
  ),
  Ecu(
    "../App-Robot2/trampoline",
    scheduler,
    [
      CAN(can_net2, "CAN2", 0),
      Timer("TIMER0", 1, type = timer.AUTO, delay = 0.1),
      LCDServer("LCD2", 2, display_server),      
      Motor("MOTOR2_1",3),
      Motor("MOTOR2_2",4),
    ]
  ),
  Ecu(
    "../App-Robot3/trampoline",
    scheduler,
    [
      CAN(can_net2, "CAN3", 0),
      Timer("TIMER0", 1, type = timer.AUTO, delay = 0.1),
      #LCD("LCD3", 2),
      #Motor("MOTOR_SPEED3",3),
      #MotorPap("MOTOR_PAP3",4),
    ]
  )
]

