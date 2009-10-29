###############################################################################
# IMPORTS
###############################################################################
import device
from scheduler import Event
import time
from const import *

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

  def __init__(self, name, id, signal = device.SIGUSR2, position = None, registers = None, type = ONE_SHOT, delay = 1):
    """
    Constructor.
    @see Device.__init__()
    @param type ONE_SHOT or AUTO
    @param delay time (second) between two shots (This is a float)
    """
    self._width = 0
    self._height = 0
    self._position = position
    
    device.Device.__init__(self, name, id, signal, registers)
    self.__type  = type
    self.__delay = float(delay)
    
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

  def event(self, modifiedRegisters = None):
    """
    Call from Scheduler
    """
    self.sendIt() 

  def start(self):
    """
    Call from ecu, at the begining.
    Start periodic timer if selected by the user.
    """
    if self.__type != ONE_SHOT:
      self._scheduler.addEvent(Event(self, self.__delay, periodic = True))
    else:
      self._scheduler.addEvent(Event(self, self.__delay))
  
  ################################################################    
  # Display on Consol
  ################################################################
  
  def display_on_consol(self):
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