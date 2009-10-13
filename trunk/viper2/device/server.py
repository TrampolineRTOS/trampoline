###############################################################################
# IMPORTS
###############################################################################
import pygame
import device
from register import Register
from const import *

###############################################################################
# LCDSERVER CLASS
###############################################################################
class LCDServer(device.Device):
  """
    Liquid Crystal Displays for a Server.
    The server collects serveral LCDServer value and display them.
    Viper -> Trampoline :
      * Read "regX" registers.
    
  """
  def __init__(self, name, id, serv, delay = 0, signal = device.SIGUSR2):
    """
    Constructor.
    @see Device.__init__()
    """
    
    """ Create LCD registers"""
    Reg0 = Register(name + "_REG0")
    Reg1 = Register(name + "_REG1")
    self.__reg0     = Reg0.name
    self.__reg1     = Reg1.name
    
    device.Device.__init__(self, name, id, signal, [Reg0, Reg1])
    self.__name     = name
    self._reg0_val  = None
    self._reg1_val  = None
    self._serv      = serv
             
  def event(self, ev, modifiedRegisters = None):
    """
    Call from Scheduler
    """
    
    """ If event doesn't come from Trampoline """
    if not modifiedRegisters:
      print "[VPR] (" + str(self.__name) + ") Event doesn't come from Trampoline !!! "

      """ If event come from Trampoline """
      """ Get command """
    elif self._registers[self.__reg0].id in modifiedRegisters:
      print "[VPR] (" + str(self.__name) + ") : " + str(self._registers[self.__reg0].read()) + "-" + str(self._registers[self.__reg1].read()) 
      
      self._reg0_val = self._registers[self.__reg0].read()
      self._reg1_val = self._registers[self.__reg1].read()
      
      self._serv.update(self, self._reg0_val, self._reg1_val)
          
    else:
      print "[VPR](DEBUG) Some registers are not handle :", modifiedRegisters

  def draw(self, widget_list):
    """Initialise screen display """
    self._serv.draw(self)

  def start(self):
    """
    Store 32 (ASCII caracter "space") in all the registers of the LCD device
    """
    if ( self._registers[self.__reg1].read() == 0 ):
      self._registers[self.__reg1].write(32)
    if ( self._registers[self.__reg0].read() == 0 ):
      self._registers[self.__reg0].write(32)
      


###############################################################################
# SERVER CLASS
###############################################################################
class Server(device.Device):
  """
  Container of all the widgets
  """
  def __init__(self, name):
    self._robots_position   = {}
    self._robots_color      = {}
    self._robots_color[0]   = red
    self._robots_color[1]   = green
    self._robots_color[2]   = yellow
    self._robots_color[3]   = black
    self._robots_lcdserver  = {}
    self._lcdserver_number = 0
    self._name              = name
    
    #self._widgets			= {}
    #self._actual_widget 	= None

    # TODO : Add Pygame device
    device.Device.location(self, lcdserver_width, lcdserver_height)
    self.__background 	  = None
    self.__backgroundrect = None
    self.__robot          = None
    self.__robotrect      = None
    
    
  def event(self, loc):
    """ Search if loc is in the widget 
        box and "launch" event if OK
    """ 
    #if mouse click, find the focused widget, otherwise, send event to the "actual" widget
  
  def update(self, lcdserv, posx, posy):
    
    #update before saving values for updating lcdserver one by one on the screen. TODO ?
    #self.draw_update(lcdserv, posx, posy)

    for i, serv in self._robots_lcdserver.iteritems():
      if (serv == lcdserv):
        self._robots_position[i] = (posx, posy)
    
    print "[VPR] " + str(self._name) + ": " + str(self._robots_position)
    
    self.draw_update(lcdserv, posx, posy)
    
  def draw(self, lcdserv):
    """ Add lcdserver in the list """
    self._robots_lcdserver[self._lcdserver_number] = lcdserv
    self._robots_position[self._lcdserver_number] = None
    self._lcdserver_number = self._lcdserver_number + 1
    self.draw_init()
  
  def draw_init(self):
    """ Fill background """
    self.__background = pygame.Surface((lcdserver_width - 2*border_line, lcdserver_height - 30))
    self.__backgroundrect = self.__background.fill(white) 
    self.__backgroundrect = self.__backgroundrect.move([self._localisation[0]+border_line, self._localisation[1]+border_line])
          
    """ Update screen """ 
    screen = pygame.display.get_surface()
    screen.blit(self.__background, self.__backgroundrect)
    pygame.display.flip()    
    
  def draw_update(self, lcdserv, posx, posy):
    """ Update screen """
    self.__background = pygame.Surface((lcdserver_width - 2*border_line, lcdserver_height - 30))
    self.__backgroundrect = self.__background.fill(white) 
    self.__backgroundrect = self.__backgroundrect.move([self._localisation[0]+border_line, self._localisation[1]+border_line])
    
    screen = pygame.display.get_surface()
    screen.blit(self.__background, self.__backgroundrect)

    for i, serv in self._robots_lcdserver.iteritems():
      #if first value not "None", draw the robot
      if (self._robots_position[i] != None):
        x=self._localisation[0]+border_line+self._robots_position[i][0]-robot_size/2
        y=self._localisation[1]+lcdserver_height+border_line-self._robots_position[i][1]-robot_size/2
        
        self.__robot = pygame.Surface((robot_size, robot_size))
        self.__robotrect = self.__robot.fill(self._robots_color[i]) 
        self.__robotrect = self.__robotrect.move([x ,y ])
        screen.blit(self.__robot, self.__robotrect)
        
        """ Drawing a car: """
        #self.__robot = pygame.Surface((robot_light, robot_light/2))
        #self.__robotrect = self.__robot.fill(yellow) 
        #self.__robotrect = self.__robotrect.move([x ,y])
        #screen.blit(self.__robot, self.__robotrect)
        
        #self.__robot = pygame.Surface((robot_light, robot_light/2))
        #self.__robotrect = self.__robot.fill(yellow) 
        #self.__robotrect = self.__robotrect.move([robot_size-robot_light ,0])
        #screen.blit(self.__robot, self.__robotrect)
        
          
    pygame.display.flip()        
        
  def start(self):
    pass
    