###############################################################################
# IMPORTS
###############################################################################
import random
import device
from scheduler import Event

###############################################################################
# MOTOR CLASS
###############################################################################
class Motor(device.Device):
  """
    Viper -> Trampoline :
      * Read "control" register. (Absolute speed to apply)
      * Apply noise(random)
      * Write to "sensor" register the actual speed.

    Speed is noised each Motor.__delay seconds !
  """
  def __init__(self, name, id, sensorReg, controlReg, noise, delay = 0.2, signal = device.SIGUSR2):
    """
    Constructor.
    @see Device.__init__()
    """
    device.Device.__init__(self, name, id, signal, [sensorReg, controlReg])
    self.__type     = type
    self.__delay    = float(delay)
    self.__sensor   = sensorReg.name
    self.__control  = controlReg.name
    self.__noise    = noise
    self.__speed    = 0

  def event(self, modifiedRegisters = None):
    """
    Call from Scheduler
    """

    """ If event doesn't come from Trampoline """
    if not modifiedRegisters:
      """ Noise """
      self.noise()

      """ Add new event (speed change) """
      self._scheduler.addEvent(Event(self, self.__delay))

      """ If event come from Trampoline """
      """ Get command """
    elif self._registers[self.__control].id in modifiedRegisters:
        self.__speed = self._registers[self.__control].read()

	print "[VPR] (MOTOR) " + str(self.__speed)

        """ Apply noise and write sensor speed """
        self.noise()
    else:
      print "[VPR](DEBUG) Some registers are not handle :", modifiedRegisters

  def noise(self):
      """ Noise """
      self.__speed += random.randint(-self.__noise, self.__noise)
      if self.__speed < 0:
	self.__speed = 0

      """ Write to registers """
      self._registers[self.__sensor].write(self.__speed)

  def start(self):
    """
    Call from ecu, at the beginin
    Here the first call is written to the scheduler
    """
    self._scheduler.addEvent(Event(self, 0))
