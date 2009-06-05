###############################################################################
# IMPORTS
###############################################################################
import random
import device
from device import Device
from scheduler import Event

###############################################################################
# MOTOR CLASS
###############################################################################
class Motor(Device):
  """
    Init:
      * Send speed we want to Trampoline 

    LOOP:
      Trampoline -> Viper:
	* Read "captor" register to get the motor speed
	* Calculate delta with speed asked 
	* Write this delta to "commande" register.
	* signal_update() (Push fifo)
       
      Viper -> Trampoline :
	* Read "commande" register.
	* Apply noise(random)
	* Write to "captor" register the actual speed.


    Speed is noised each Motor.__delay seconds !
  """
  def __init__(self, name, id, captorReg, commandeReg, noise, delay = 0.2, signal = device.SIGUSR2):
    """
    Constructor.
    @see Device.__init__()
    """
    Device.__init__(self, name, id, signal, [captorReg, commandeReg])
    self.__type     = type
    self.__delay    = float(delay)
    self.__captor   = captorReg.name
    self.__commande = commandeReg.name
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
    elif self._registers[self.__commande].id in modifiedRegisters:
        self.__speed += self._registers[self.__commande].read()

        """ Apply noise and write captor speed """
        self.noise()

  def noise(self):
      """ Noise """
      self.__speed += random.randint(-self.__noise, self.__noise)

      """ Write to registers """
      self._registers[self.__captor].write(self.__speed)

  def start(self):
    """
    Call from ecu, at the beginin
    Here the first call is written to the scheduler
    """
    self._scheduler.addEvent(Event(self, 0))
