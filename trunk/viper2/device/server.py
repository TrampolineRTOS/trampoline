###############################################################################
# IMPORTS
###############################################################################
import device
from register import Register
from const import *

###############################################################################
# LCDSERVER CLASS
###############################################################################
class DisplayServer(device.Device):
  """
    Liquid Crystal Displays for a Server.
    The server collects serveral LCDServer value and display them.
    Viper -> Trampoline :
      * Read "regX" registers.
    
  """
  def __init__(self, name, id, serv, position = None, signal = device.SIGUSR2):
    """
    Constructor.
    @see Device.__init__()
    """
    """ Create LCD registers"""
    Reg0 = Register(name + "_REG0")
    Reg1 = Register(name + "_REG1")
    self.__reg0     = Reg0.name
    self.__reg1     = Reg1.name

    self._width = 0
    self._height = 0
    self._position = position

    device.Device.__init__(self, name, id, signal, [Reg0, Reg1])
    self._reg0_val  = None
    self._reg1_val  = None
    self._serv      = serv
    #add DisplayServer into Server
    self._serv.add_lcd(self)
  
  def event(self, modifiedRegisters = None):
    """
    Call from Scheduler
    """
    """ If event doesn't come from Trampoline """
    if not modifiedRegisters:
      print "[VPR] (" + str(self.name) + ") Event doesn't come from Trampoline !!! "
      
      """ If event come from Trampoline """
      """ Get command """
    elif self._registers[self.__reg0].id in modifiedRegisters:
      self._reg0_val = self._registers[self.__reg0].read()
      self._reg1_val = self._registers[self.__reg1].read()
      self._serv.update(self, self._reg0_val, self._reg1_val)
    
    else:
      print "[VPR](DEBUG) Some registers are not handle :", modifiedRegisters
  
  def start(self):
    """
    Store 32 (ASCII caracter "space") in all the registers of the LCD device
    """
    if ( self._registers[self.__reg1].read() == 0 ):
      self._registers[self.__reg1].write(32)
    if ( self._registers[self.__reg0].read() == 0 ):
      self._registers[self.__reg0].write(32)
      
  ################################################################    
  # Display on Consol
  ################################################################
  
  def display_on_consol(self):
    pass
  
  ################################################################    
  # Display on Pygame
  ################################################################
  
  def display_on_pygame_adding_widgets(self, widget_list):
    self._serv.display_on_pygame_adding_widgets(self)
    
  def display_on_pygame(self):
    pass    
    
  def refresh_display(self):
    self._serv.refresh_display()
    
###############################################################################
# SERVER CLASS
###############################################################################
class Server(device.Device):
  """
  Container of all the widgets
  """
  def __init__(self, name, position = None):
    self._robots_position   = {}
    self._robots_lcdserver  = {}
    self._lcdserver_number = 0
    self.name              = name

    self._width = lcdserver_width
    self._height = lcdserver_height
    self._position = position
            
    from config import dispatch_display
    dispatch_display.device(self)
    
  def add_lcd(self, lcdserv):
    """ Add lcdserver in the list """
    self._robots_lcdserver[self._lcdserver_number] = lcdserv
    self._robots_position[self._lcdserver_number] = None
    self._lcdserver_number = self._lcdserver_number + 1         
                         
  def update(self, lcdserv, posx, posy):
    for i, serv in self._robots_lcdserver.iteritems():
      if (serv == lcdserv):
        self._robots_position[i] = (posx, posy)
    
    self._display()
    
  ################################################################    
  # Display on Consol
  ################################################################
  
  def display_on_consol(self):
    print "[VPR] " + str(self.name) + ": " + str(self._robots_position)  
      
  ################################################################    
  # Display on Pygame
  ################################################################
  
  def display_on_pygame_adding_widgets(self, lcdserv):
    """ Initialize variables """
    self._robots_color      = {}
    self._robots_color[0]   = red # declared in const.py
    self._robots_color[1]   = orange
    self._robots_color[2]   = blue
    self._robots_color[3]   = black
    self.__robot            = {}
    self.__robotrect        = {}

    self.display_on_pygame_init()
  
  def display_on_pygame_init(self):
    """ Fill background """
    self.__lcdserver_height_screen = 30
    self.__background = pygame.Surface((lcdserver_width - 2*border_line, lcdserver_height - self.__lcdserver_height_screen))
    self.__backgroundrect = self.__background.fill(white) 
    self.__backgroundrect = self.__backgroundrect.move([self._position[0]+border_line, self._position[1]+border_line])
          
    """ Update screen """ 
    screen = pygame.display.get_surface()
    screen.blit(self.__background, self.__backgroundrect)
    pygame.display.flip()    
    
  def display_on_pygame(self):
    """ Update pygame """
    for i, serv in self._robots_lcdserver.iteritems():
      #if first value not "None", draw the robot
      if (self._robots_position[i] != None):
        x=self._position[0] + border_line + (self._robots_position[i][0] % (lcdserver_width - 2*border_line)) - robot_size/2
        y=self._position[1] + border_line + lcdserver_height - self.__lcdserver_height_screen - (self._robots_position[i][1] % ( lcdserver_height - self.__lcdserver_height_screen)) - robot_size/2
        
        self.__robot[i] = pygame.Surface((robot_size, robot_size))
        self.__robotrect[i] = self.__robot[i].fill(self._robots_color[i]) 
        self.__robotrect[i] = self.__robotrect[i].move([x ,y ])
        
  def refresh_display(self):
    screen = pygame.display.get_surface()
    for i, serv in self._robots_lcdserver.iteritems():
      if (self._robots_position[i] != None):
        screen.blit(self.__robot[i], self.__robotrect[i])
    pygame.display.flip()    
  
  