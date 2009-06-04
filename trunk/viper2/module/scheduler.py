###############################################################################
# IMPORTS
###############################################################################
import time, threading

###############################################################################
# EVENT CLASS
###############################################################################
class Event(object):
  """
  Event class is a structure with accessors.
  This class is used to add new event to the Scheduler.
  """
  def __init__(self, device, delay, modifiedRegisters = None):
    self.__time   = delay
    self.__device = device
    self.__modifiedRegisters = modifiedRegisters

  def getTime(self):
    """
    @return time to wait in seconds (float)
    """
    return self.__time

  def setTime(self, time_):
    """
    Set time. This function is used by scheduler to speed up
    the time by instance.
    @param time_ new time to set.
    """
    self.__time = time_

  def getDevice(self):
    """
    @return device id (tiny one [withou '<<'])
    """
    return self.__device

  def getModifiedRegisters(self):
    """
    @return modified registers mask
    """
    return self.__modifiedRegisters

###############################################################################
# SCHEDULER CLASS
###############################################################################
class Scheduler(object):
#TODO doc
  def __init__(self, speedCoeff):
    """
    Constructor.
    @param speedCoeff (floating variable) is the coeff to apply to the time. 
	    3 means three times speeder
    """
    self.__speedCoeff = float(speedCoeff)
    self.__events     = [] # List
    self.__run        = True
    self.__sem        = threading.Semaphore()

  def addEvent(self, event):  
    """
    Add event to the scheduler.
    Time is calculate by the function. 
      So you have to give time to wait from present.
    @param event the Event to add
    """
    event.setTime((event.getTime() / self.__speedCoeff) + time.time())
    self.__sem.acquire()
    self.__events.append(event)
    self.__sem.release()

  def start(self):
#TODO
    """
    TODO:
      Sleep scheduler the min time to wait.
    Start scheduler : Get Event whose time is passed, call event() 
      Device'method and remove the event from the list.
    """

    while self.__run:
      events	  = [] # List
      currentTime = time.time() 

      for event in self.__events:
	if event.getTime() < currentTime:
	  events.append(event)

      for event in events:
	self.__sem.acquire()
	self.__events.remove(event)
	self.__sem.release()
        event.getDevice().event(event.getModifiedRegisters())

  def kill(self):
    """
    Stop scheduler
    """
    self.__run = False
