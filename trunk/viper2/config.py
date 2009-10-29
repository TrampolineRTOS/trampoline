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
from server import DisplayServer
from server import Server
from ether import Ether
from network import Network
from motor import Motor

###############################################################################
# DISPLAY
##########
# You shall modify pygame to True or False if you want or not to use pygame (True by default)
# You shall modify screen if you want to change screen dimensions ([800, 600] by default)
###############################################################################
dispatch_display = Display(pygame = True, screen = [400, 560])

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
network_master = Ether()
network_slave = Ether()

###############################################################################
# PYGAME WIDGETS
##########
# Add Pygame widgets if needed (for example, a screen which displays several
# information coming from several application
###############################################################################
display_server = Server("SERVER") # uses pygame

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
      Network(network_master, "NET0", 0),
      Timer("TIMER0", 1, type = timer.AUTO, delay = 1),
      BP("BPFaster", 5, position = [100, 400], text="/\\" ),
      BP("BPSlower", 6, position = [100, 480], text="\\/"),
      BP("BPLeft", 7, position = [0, 480], text="<" ),
      BP("BPRight", 8, position = [200, 480], text=">" ),
    ]
  ),
  Ecu(
    "../App-Robot1/trampoline",
    scheduler,
    [
      Network(network_master, "NET1_1", 0),
      Timer("TIMER1", 1, type = timer.AUTO, delay = 0.1),
      DisplayServer("LCD1", 2, display_server),      
      Motor("MOTOR1_1",3),
      Motor("MOTOR1_2",4),
      Network(network_slave, "NET1_2", 5),
    ]
  ),
  Ecu(
    "../App-Robot2/trampoline",
    scheduler,
    [
      Network(network_slave, "NET2", 0),
      Timer("TIMER2", 1, type = timer.AUTO, delay = 0.1),
      DisplayServer("LCD2", 2, display_server),      
      Motor("MOTOR2_1",3),
      Motor("MOTOR2_2",4),
    ]
  ),
  Ecu(
    "../App-Robot3/trampoline",
    scheduler,
    [
      Network(network_slave, "NET3", 0),
      Timer("TIMER3", 1, type = timer.AUTO, delay = 0.1),
      DisplayServer("LCD3", 2, display_server),      
      Motor("MOTOR3_1",3),
      Motor("MOTOR3_2",4),
    ]
  )
]

