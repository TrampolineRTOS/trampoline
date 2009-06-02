###############################################################################
# IMPORTS
###############################################################################
import time, threading

###############################################################################
# EVENT CLASS
###############################################################################
class Event(object):
  def __init__(self, device, delay):
    self.__time   = delay
    self.__device = device

  def getTime(self):
    return self.__time

  def setTime(self, time_):
    self.__time = time_

  def getDevice(self):
    return self.__device

###############################################################################
# SCHEDULER CLASS
###############################################################################
class Scheduler(object):
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
        event.getDevice().event()

  def kill(self):
    """
    Stop scheduler
    """
    self.__run = False
