###############################################################################
# IMPORTS
###############################################################################
import device
from scheduler import Event
from register import Register
import time
from const import *

###############################################################################
# TIMER CLASS
###############################################################################
class Power(device.Device):
  """
  ISR class is here just to create the isr symbol in the target.cfg
  """

  def __init__(self, name, id, signal = device.SIGUSR2, position = None, registers = None):
    """
    Constructor.
    @see Device.__init__()
    """
    self._width = 0
    self._height = 0
    self._position = position
    
    powerReg = Register(name + "_REG")
    self.__powerReg  = powerReg.name

    device.Device.__init__(self, name, id, signal, [powerReg])

  def event(self, time, modifiedRegisters = None):
    """
    Call from Scheduler
    """
    """ If event doesn't come from Trampoline : ISR """
    if not modifiedRegisters:
      print "Power received a periodic event --> Check what is the problem !! "
      
      """ If event come from Trampoline """
      """ Get command """
    elif self._registers[self.__powerReg].id in modifiedRegisters:
      if (self._registers[self.__powerReg].read() == 1):
        self._scheduler.kill()
      
  def start(self):
    """
    Call from ecu, at the begining.
    Start periodic timer if selected by the user.
    """
    self._registers[self.__powerReg].write(0)
  
  ################################################################    
  # Display on Consol
  ################################################################
  
  def display_on_console(self):
    pass
  
  ################################################################    
  # Display on Pygame
  ################################################################
  
  def display_on_pygame_adding_widgets(self, widget):
    pass

  def display_on_pygame(self):
    pass
    
  def refresh_display(self):
    pass