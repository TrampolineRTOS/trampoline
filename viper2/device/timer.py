###############################################################################
# IMPORTS
###############################################################################
import device
from device import Device
from scheduler import Event

###############################################################################
# CONSTANTES
###############################################################################
ONE_SHOT = 0
AUTO     = 1

###############################################################################
# TIMER CLASS
###############################################################################
class Timer(Device):
  """
  Timer device. This timer can run with a one shot and you could specify a delay
  """

  def __init__(self, name, id, signal = device.SIGUSR2, registers = None, type = ONE_SHOT, delay = 1):
    """
    Constructor.
    @see Device.__init__()
    @param type ONE_SHOT or AUTO
    @param delay time (second) between two shots (This is a float)
    """
    Device.__init__(self, name, id, signal, registers)
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

    if self.__type != ONE_SHOT:
      self._scheduler.addEvent(Event(self, self.__delay))

  def start(self):
    """
    Call from ecu, at the beginin
    Here the first call is written to the scheduler
    """
    self._scheduler.addEvent(Event(self, self.__delay))
