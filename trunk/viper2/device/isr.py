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
class ISR(device.Device):
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
    
    ISRReg = Register(name + "_REG")
    self.__ISRReg  = ISRReg.name

    device.Device.__init__(self, name, id, signal, [ISRReg])

  def event(self, time, modifiedRegisters = None):
    """
    Call from Scheduler
    """
    """ If event doesn't come from Trampoline : ISR """
    if not modifiedRegisters:
      print "ISR received a periodic event --> Check what is the problem !! "
      
      """ If event come from Trampoline """
      """ Get command """
    elif self._registers[self.__ISRReg].id in modifiedRegisters:
      print "ISR has registers changed --> Check what is the problem !!"
      
  def start(self):
    """
    Call from ecu, at the begining.
    Start periodic timer if selected by the user.
    """
  
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