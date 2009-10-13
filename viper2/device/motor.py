###############################################################################
# IMPORTS
###############################################################################
import random
import device
from scheduler import Event
from register import Register
import time
from const import *

###############################################################################
# MOTOR CLASS
###############################################################################
class Motor(device.Device):
  """
    Viper -> Trampoline :
      * Read "control" register. (Absolute speed to apply)
      * Apply transfertfunction(random)
      * Write to "sensor" register the actual speed.

    Speed is transfertfunctiond each Motor.__delay seconds !
  """
  def __init__(self, name, id, frequency = None, max_pwm = 100, tickperrotation = 100, max_rpm = 300, delay = 0.5, transfertfunction = None, signal = device.SIGUSR2):
    """
    Constructor.
    @see Device.__init__()
    """

    """ Create Motor registers"""
    controlReg = Register(name + "_CONTROL")
    sensorReg = Register(name + "_SENSOR")
    self.__sensor   = sensorReg.name
    self.__control  = controlReg.name

    device.Device.__init__(self, name, id, signal, [sensorReg, controlReg])
    self.__type     = type
    self.__delay    = float(delay)
    # TODO : make a better period with delay. use directly time+delay and add delay to previous time each time.
    self.__transfertfunction    = transfertfunction # Not used
    self.__fequency = frequency                     # Not used
    self.__tickperrotation = tickperrotation
    self.__max_rpm  = max_rpm
    self.__max_pwm  = max_pwm
    self.__secondsperminute = 60
    self.__pwm      = 0                             # Max is 1024 (10-bits resoulution)
    self.__speed    = 0                             
    self.__tickperdelay = 0
    
  def event(self, ev, modifiedRegisters = None):
    """
    Call from Scheduler
    """
    """ If event doesn't come from Trampoline : Motor Sensor """
    if not modifiedRegisters:
      
      """ Motor simulation """
      self.motor() # -> consigne
      self.transfertfunction() # -> speed
      self.sensor() # -> tickperdelay
      self.sendIt()

      """ If event come from Trampoline """
      """ Get command """
    elif self._registers[self.__control].id in modifiedRegisters:
        self.__pwm = self._registers[self.__control].read()
        
        print "[VPR] " + str(self.name) + ":" + str(self.__pwm)        
        
    else:
      print "[VPR](DEBUG) Some registers are not handle :", modifiedRegisters

  def motor(self):
    """ find consigne from pwm, max_pwm and max_rpm """
    self.__consigne = (self.__pwm*self.__max_rpm)/(self.__max_pwm)

  def sensor(self):
    """ find tickperdelay from speed, delay, tickperrotations"""
    self.__tickperdelay = self.__speed*(self.__delay/(self.__secondsperminute))*self.__tickperrotation
    
    """ Write tick per delay in registers """
    self._registers[self.__sensor].write(int(self.__tickperdelay))
      
  def transfertfunction(self):
     """ Filter """
     self.__speed = self.__consigne
      
  def start(self):
    """
    Call from ecu, at the beginin
    Here the first call is written to the scheduler
    """
    self._registers[self.__control].write(0)
    self._scheduler.addEvent(Event(self, self.__delay, true))

  def start_pygame(self, widget):
	""" """
	print "motor.start_pygame()"
 
  def draw(self, widget):
    """ """

###############################################################################
# MOTOR_PAP CLASS
###############################################################################
SPR = 360 #(step per rotation) #TODO : this parameter should be given by the user at the initialisation of the MotorPap

class MotorPap(device.Device):
  """
    Viper -> Trampoline :
      * Read "control" register. (Absolute speed to apply)
      * Apply transfertfunction(random)
      * Write to "sensor" register the actual speed.

    Speed is transfertfunctiond each Motor.__delay seconds !
  """
  def __init__(self, name, id, transfertfunction = 0, delay = 0.2, signal = device.SIGUSR2):
    """
    Constructor.
    @see Device.__init__()
    """
        
    """ Create Motor registers"""
    controlReg = Register(name + "_CONTROL")
    sensorReg = Register(name + "_SENSOR")
    self.__sensor   = sensorReg.name
    self.__control  = controlReg.name
    
    device.Device.__init__(self, name, id, signal, [sensorReg, controlReg])
    self.__type     = type
    self.__delay    = float(delay)
    self.__transfertfunction    = transfertfunction
    self.__step    = 0

  def event(self, ev, modifiedRegisters = None):
    """
    Call from Scheduler
    """

    """ If event doesn't come from Trampoline """
    if not modifiedRegisters:
      """ Noise """
      self.transfertfunction()

      """ Add new event (motor sensor) """
      self._scheduler.addEvent(Event(self, self.__delay))

      """ If event come from Trampoline """
      """ Get command """
    elif self._registers[self.__control].id in modifiedRegisters:
        self.__step = self._registers[self.__control].read()
        
        """ With a step motor, it's possible to turn in both directions"""
        if (self.__step > 90):
          self.__step = self.__step - 256
        
        print "[VPR] (MOTOR_PAP) " + str(self.__step)
        
        """ Apply transfertfunction and write sensor speed """
        self.transfertfunction()
    else:
      print "[VPR](DEBUG) Some registers are not handle :", modifiedRegisters

  def transfertfunction(self):
      """ Noise """
      #self.__step += random.randint(-self.__transfertfunction, self.__transfertfunction)
      #if self.__step < 0:
      #  self.__step = 0

      """ Write to registers """
      # TODO : convert speed into "top" from 'coded wheel'. It needs to know if speed is RPM and the motor's SPR
      self._registers[self.__sensor].write(self.__step)

  def start(self):
    """
    Call from ecu, at the beginin
    Here the first call is written to the scheduler
    """
    self._registers[self.__control].write(0)
    self._scheduler.addEvent(Event(self, 0))

  def start_pygame(self, widget):
	""" """
	print "motor.start_pygame()"
  
  def draw(self, widget):
    """ """  