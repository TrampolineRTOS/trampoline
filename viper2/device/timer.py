###############################################################################
# IMPORTS
###############################################################################
import device
from scheduler import Event
import time
from const import *
from register import Register

###############################################################################
# CONSTANTS
###############################################################################
ONE_SHOT = 0
AUTO     = 1

###############################################################################
# TIMER CLASS
###############################################################################
class Timer(device.Device):
  """
  Timer class is a timer which can be one shot (ONE_SHOT) or periodic (AUTO).
  """

  def __init__(self, name, id, signal = device.SIGUSR1, position = None, registers = None, type = ONE_SHOT, delay = 1000):
    """
    Constructor.
    @see Device.__init__()
    @param type ONE_SHOT or AUTO
    @param delay time (second) between two shots (This is a float)
    """
    self._width = 0
    self._height = 0
    self._position = position
    
    enableReg = Register(name + "_ENABLE")
    self.__enableReg   = enableReg.name
    
    device.Device.__init__(self, name, id, signal, [enableReg])
    self.__type  = type
    self.__delay = delay
        
  def setType(self, type):
    """
    Change type of timer (ONE_SHOT or AUTO)
    """
    self.__type = type

  def setDelay(self, delay):
    """
    Change delay (second), this delay is a floating variable
    """
    self.__delay = delay

  def event(self, time, modifiedRegisters = None):
    """
    Call from Scheduler
    """
    """ If event doesn't come from Trampoline : Motor Sensor """
    if not modifiedRegisters:
      if (self.__enable == 1):
        self.sendIt() 

      """ If event come from Trampoline """
      """ Get command """
    elif self._registers[self.__enableReg].id in modifiedRegisters:
      self.__enable = self._registers[self.__enableReg].read()     

  def start(self):
    """
    Call from ecu, at the begining.
    Start periodic timer if selected by the user.
    """
    self._registers[self.__enableReg].write(0)
    self.__enable = 0
    if self.__type != ONE_SHOT:
      self._scheduler.addEvent(Event(self, 0, self.__delay))
    else:
      self._scheduler.addEvent(Event(self, 0, 0))
  
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