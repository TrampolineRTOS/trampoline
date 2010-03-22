###############################################################################
# IMPORTS
###############################################################################
import time, threading, thread
import sys
import device
import config
import ipc
from const import *
from errors import IPCError

###############################################################################
# EVENT CLASS
###############################################################################
class Event(object):
  """
  Event class is a structure with accessors.
  This class is used to add new event to the Scheduler.
  """

  def __init__(self, device, time, delay, modifiedRegisters = None):
    """
    Constructor.
    @param device device to call when time is elapsed
    @param delay time to wait (seconds, float)
    @param modifiedRegisters list of modifiedRegisters to give to device (use by Ecu only)
    """
    self.__time = time # divided by 10 because time is multiplied by 10 before saving in the global memory
    self.__delay  = delay
    self.__device = device
    self.__modifiedRegisters = modifiedRegisters
    
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
# SORTING THREAD CLASS
###############################################################################
class SortingThread(threading.Thread):
  """
  Sorting thread schedules the events after inserted in the event list by
  Reading thread (see Scheduler())
  """

  def __init__(self, sched):
    """
    Constructor.
    @param sched scheduler where is the event list
    """
    threading.Thread.__init__(self)
    self.__sched = sched
    self.__run = True

  def run(self):
    """
    see Scheduler.sortEvent()
    """
    
    while self.__run:
      """ Sort Events """
      self.__sched.sortEvent()
      
  def kill(self):
    """
    Call to stop the main loop of the sorting thread (by the scheduler when ending).
    """
    self.__run = False
       
###############################################################################
# SCHEDULER CLASS
###############################################################################
class Scheduler(object):
  """
  Logical scheduler
  Contain list of events to schedule (used by the "SortingThread" instance and
  'ReadingThread" instance). Depending on pygame or console mode, catch events
  from the user and send it to the concern widget (see Widget()).
  Update the screen at a certain frequency.
  """
  
  def __init__(self, speedCoeff):
    """
    Constructor.
    @param speedCoeff (floating variable) is the coeff to apply to the time.
	    3 means three times speeder
    """
    self.__speedCoeff = speedCoeff # convert to float ?
    self.__events     = [] # List
    self.__fps        = time.time()
    self.__run        = True
    self.__sem        = threading.Semaphore()
    #self._semtime     = threading.Semaphore()
    self._time        = 0
    self._verbose     = False
    
    """ Dispatch display on pygame or console """
    try:
      from config import dispatch_display
      dispatch_display.scheduler(self)
    except:
      raise IPCError, "Dispaly instance not created in config file. Go to the readme file."
              
  def addEvent(self, event):  
    """
    Add event to the scheduler.
    If periodic event, this is never called
    If initialisation of periodic event, init to getTime + delay
    If one shot event, increment delay to getTime
    Insert event in the right place
    @param event the Event to add
    """    
    newtime = event.getTime()
    event.setTime(newtime)
    
    self.__sem.acquire()
    # TODO : Don't start the searching from the beginning of the list but by the
    #        middle (worst case in log(n) instead of n)
    length = len(self.__events)
    i = 0
    if (length > 0):
      for ev in range(length): 
       if (self.__events[ev].getTime() > newtime):
        break
       i = i + 1
    self.__events.insert(i,event)
    self.__sem.release()
  
  def createGlobalMemory(self):
    self.__global_mem = ipc.tpl_ipc_create_global_memory()        
        
  def destroyGlobalMemory(self):
    ipc.tpl_ipc_destroy_global_memory(self.__global_mem)        
                                                              
  def start(self):
    """
    If pygame selected in the config file, update display at 10fps (see Scheduler.withPygame())
    When terminating (self.__run = false), kill the sorting thread.
    """
    
    """ Init and start sorting thread """
    self.__sortingThread = SortingThread(self)
    self.__sortingThread.setDaemon(True) # Can stop script even if thread is running
    self.__sortingThread.start()
    self.__fps        = time.time()
            
    while self.__run:
     """
     If pygame : wait for event
       Otherwise : Do nothing
     """
     self._pygameOrNotPygame()
     
    """ Kill the sortingThread """ 
    self.killsortingThread()
         
  def withoutPygame(self):
    """ Do noting but wait 1s no to consume CPU """
    threading.Event().wait(1)
    
  def withPygame(self):
     """
     Waiting for events from the keyboard/mouse
     Refresh screen (every 100ms for example), instead of updating the screen each
     received event by the device (which can have an updating time longer than the
     delay between two events).
     """     
     for event in pygame.event.get():
      if (event.type == pygame.QUIT):
        self.kill()
      else:
          self._widg.event(event)  
      
     """ Display devices """
     for ecu in config.allEcus:
       for name, device in ecu._devices.iteritems():
         device.refresh_display()
     pygame.display.flip()
     self.__fps += 0.1 # 10fps
       
     threading.Event().wait(self.__fps-time.time())
       
  def kill(self):
    """
    Stop scheduler (the loop in scheduler.start())
    """
    self.__run = False

  def killsortingThread(self):  
    """Stop reading thread"""
    if self.__sortingThread:
      self.__sortingThread.kill()
      # TODO : isAlive useful ???
      if self.__sortingThread.isAlive():
        if (self._verbose == True):
          print "Waiting sorting thread 0.1 seconde (it's may be waiting for next event)..."
          threading.Event().wait(0.1)
        if self.__sortingThread.isAlive():
          if (self._verbose == True):
            print "Sorting thread stop not clearly."
      
  def sortEvent(self):
     """
     Copie event whose time is passed (event.getTime() < time.time()).
     Remove event (except if periodic event, thus change time and move it to the right
      place in the events list).
     Launch event device action.
     Thus, event sorting...
     """
     events	  = [] # List
     self.__sem.acquire()
     for event in self.__events:
      if event.getTime() <= self._time:
        events.append(event)
     self.__sem.release()
     
     """..., lauching..."""
     for event in events:
      self.__sem.acquire()
      if (event.getDelay() != 0):
        index = self.__events.index(event)
        self.__events[index].setTime(self.__events[index].getTime()+(self.__events[index].getDelay()*self.__speedCoeff))
        eventtomove = self.__events.pop(index)
        length = len(self.__events)
        i = 0
        for ev in range(length): 
         if (self.__events[ev].getTime() > eventtomove.getTime()):
           break
         i = i + 1
        self.__events.insert(i,eventtomove)
      else:
        self.__events.remove(event)
      self.__sem.release()
      event.getDevice().event(event.getTime(), event.getModifiedRegisters())    
     
     """...and send it if needed"""
     if(self.__run == True): #test
      for ecu in config.allEcus:
       ecu.launchIt()
                 
     self.__sem.acquire()
     # TODO : Detect if there is at least one event in the list ? otherwise, set ttw to zero ?
     self._ttw = self.__events[0].getTime() - self._time
     self.__sem.release()
          
     """ Sleep until next event (better for cpu time consuming) """
     # TODO : it's even may be not useful to wait ttw, we can wait as long as we want because we are already unsynchronised !
     threading.Event().wait(float(self._ttw)/1000)
       
     self._time += self._ttw
     ipc.write_global_time(self.__global_mem , self._time)
     