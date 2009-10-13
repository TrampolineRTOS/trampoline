###############################################################################
# IMPORTS
###############################################################################
import time, threading
import sys
import device
import config
from const import *
import pygame

###############################################################################
# EVENT CLASS
###############################################################################
class Event(object):
  """
  Event class is a structure with accessors.
  This class is used to add new event to the Scheduler.
  """

  def __init__(self, device, delay, periodic, modifiedRegisters = None):
    """
    Constructor.
    @param device device to call when time is elapsed
    @param delay time to wait (seconds, float)
    @param modifiedRegisters list of modifiedRegisters to give to device (use by Ecu only)
    """
    self.__time   = delay
    self.__delay  = delay
    self.__device = device
    self.__modifiedRegisters = modifiedRegisters
    self._periodic = periodic
    if (self._periodic == true):
      self.__time = time.time()

  def getTime(self):
    """
    @return date the event will be launched
    """
    return self.__time
  
  def getDelay(self):
    """
    @return time to wait in seconds (float)
    """
    return self.__delay
    
  def setTime(self, time_):
    """
    Set time. This function is used by scheduler to speed up
    the time by instance.
    @param time_ new time to set.
    """
    self.__time = time_

  def getDevice(self):
    """
    @return device id
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
  """
  Logical scheduler
  All events are handle by this class.
  There may have one instance of this class.
  """
  
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
    Time is calculated by the function.
    So you have to give time to wait from present.
    @param event the Event to add
    """
    # if event periodic, delay event from timeperiodic otherwise, from time.time()
    if (event._periodic == true):
      newtime = (event.getDelay() / self.__speedCoeff) + event.getTime()
    else:
      newtime = (event.getDelay() / self.__speedCoeff) + time.time()
    event.setTime(newtime)

    self.__sem.acquire()
    # find the right place to insert the new event
    length = len(self.__events)
    print "length" + str(length)
    i = 0
    if (length > 0):
      for ev in range(length):
       oldtime = self.__events[ev].getTime()
       if (oldtime > newtime):
        break
       i = i + 1

    #insert the new event at the right place
    self.__events.insert(i,event)
    self.__sem.release()
    
  def start(self, widg):
    """    TODO:
      Sleep scheduler the min time to wait.
    Start scheduler : Get Event whose time is passed, call event()
      Device'method and remove the event from the list.
    """   
                 
    while self.__run:
     
     """Waiting for events from the keyboard/mouse"""
     for event in pygame.event.get():
      if event.type == pygame.QUIT: sys.exit()
      else:
          # TODO : here or in widg.event() ?
          if (event.type == MOUSEBUTTONUP) or (event.type == MOUSEBUTTONDOWN) or (event.type == KEYDOWN):
           """ Find widgets selected and send focus/key """
           for id in widg._widget_box:
            if (event.pos[0] > widg._widget_box[id][0][0]):
              if (event.pos[0] < widg._widget_box[id][1][0]):
                if (event.pos[1] > widg._widget_box[id][0][1]):
                  if (event.pos[1] < widg._widget_box[id][1][1]):
                    #launch event
                    widg._widgets[id].event(event)

     #TODO : Check if better to use an other thread for event management
     """Event sorting..."""
     previousTime=0
     events	  = [] # List
     currentTime = time.time()
     for event in self.__events:
      if event.getTime() < currentTime:
       if event.getTime() != previousTime:
        events.append(event)
        previousTime=event.getTime()

     """...and lauching"""
     for event in events:
      self.__sem.acquire()
      if (event._periodic == true):
        index = self.__events.index(event)
        self.__events[index].setTime(self.__events[index].getTime()+(self.__events[index].getDelay()/self.__speedCoeff))
      else:
        self.__events.remove(event)
      self.__sem.release()
      event.getDevice().event(event, event.getModifiedRegisters())    
        
     self.__sem.acquire()
     ttw = self.__events[0].getTime()
     self.__sem.release()
     
     """Sleep until next event"""
     threading.Event().wait(ttw-time.time())

        
  def kill(self):
    """
    Stop scheduler
    """
    pygame.quit()
    self.__run = False

  def start_pygame(self, widget):
    """
     Start pygame
    """
    