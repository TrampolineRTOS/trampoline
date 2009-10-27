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
  def __init__(self, name, id, frequency = None, max_pwm = 100, tickperrotation = 100, max_rpm = 300, delay = 0.2, transfertfunction = None, signal = device.SIGUSR2, position = None):
    """
    Constructor.
    @see Device.__init__()
    """

    """ Create Motor registers"""
    controlReg = Register(name + "_CONTROL")
    sensorReg = Register(name + "_SENSOR")
    self.__sensor   = sensorReg.name
    self.__control  = controlReg.name

    self._width = 0
    self._height = 0
    self._position = position

    device.Device.__init__(self, name, id, signal, [sensorReg, controlReg])
    self.__type     = type
    self.__delay    = float(delay)
    self.__transfertfunction    = transfertfunction # Not used
    self.__fequency = frequency                     # Not used
    self.__tickperrotation = tickperrotation
    self.__max_rpm  = max_rpm
    self.__max_pwm  = max_pwm
    self.__secondsperminute = 60
    self.__pwm      = 0                             # In microcontroler, Max is usually 1024 (10-bits resoulution)
    self.__speed    = 0                             
    self.__tickperdelay = 0
    self.__ticks    = 0
    
  def event(self, modifiedRegisters = None):
    """
    Call from Scheduler
    """
    """ If event doesn't come from Trampoline : Motor Sensor """
    if not modifiedRegisters:

      """ Motor simulation """
      self.motor() # -> consigne
      self.transfertfunction() # -> speed
      self.sensor() # -> tickperdelay

      """ If event come from Trampoline """
      """ Get command """
    elif self._registers[self.__control].id in modifiedRegisters:
        self.__pwm = self._registers[self.__control].read()
        self._display()               
        
    else:
      print "[VPR](DEBUG) Some registers are not handle :", modifiedRegisters

  def motor(self):
    """ find consigne from pwm, max_pwm and max_rpm """
    self.__consigne = (self.__pwm*self.__max_rpm)/(self.__max_pwm)
   
  def sensor(self):
    """ find tickperdelay from speed, delay, tickperrotations"""
    self.__tickperdelay = self.__speed*(self.__delay/(self.__secondsperminute))*self.__tickperrotation
    self.__ticks = self.__ticks + self.__tickperdelay
    
    """ Write tick per delay in registers """
    self._registers[self.__sensor].write(int(self.__ticks))
      
  def transfertfunction(self):
     """ Filter """
     self.__speed = self.__consigne
      
  def start(self):
    """
    Call from ecu, at the beginin
    Here the first call is written to the scheduler
    """
    self._registers[self.__control].write(0)
    self._scheduler.addEvent(Event(self, self.__delay, True))
    
  ###############################################################    
  # Display on Consol
  ################################################################
  
  def display_on_consol(self):
    print "[VPR] " + str(self.name) + ":" + str(self.__pwm) 
  
  ################################################################    
  # Display on Pygame
  ################################################################
  
  def display_on_pygame_adding_widgets(self, widget_list):
    pass
    
  def display_on_pygame(self):
    print "[VPR] " + str(self.name) + ":" + str(self.__pwm) 
      
  def refresh_display(self):
    pass
          