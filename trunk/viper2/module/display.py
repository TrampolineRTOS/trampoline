###############################################################################
# IMPORTS
###############################################################################
from widget import Widget

###############################################################################
# WIDGET CLASS
###############################################################################
class Display(object):
  """
  Container of all the widgets
  """
  pygame_bool = False
  
  def __init__(self, pygame = True, screen = None):
    """
    Constructor : Check if pygame is installed and if the user want to use pygame or not
    @param pygame boolean to display information on pygame or on consol
    """
    self.pygame_bool = pygame
    self._init_display = True
    
    global screen_width
    global screen_height
    if (screen != None):
      screen_width = screen[0]
      screen_height = screen[1]
    else:
      screen_width = 800
      screen_height = 600
    
      
    if (self.pygame_bool == True):
      try:
        import pygame
      except:
        self.pygame_bool = False
        print "Pygame not installed. Please go to http://www.pygame.org/ to insall a Pygame version according to a Python version (http://www.python.org/)" 
          
  def device(self, device):
    """
    * Set variable to the right function to call to display device information : pygame or consol (from device.__init__())
    * Locate "pygame" device if needed
    @param device device to modify
    """
    
    if (self.pygame_bool == False):
      device._display = device.display_on_consol      
    else:
      device._display = device.display_on_pygame
      """ Locate device on the screen 
      """
      # TODO : check if position != None that the position doesn't belong to another device ?
      if (device._position == None):
        if (device.pygamepointer[2] < device._height):
          if ((device.pygamepointer[0] + device._width) < screen_width):
            device.pygamepointer[2] = device._height
        if ((device.pygamepointer[0] + device._width) > screen_width):
          device.pygamepointer[1] += device.pygamepointer[2]
          device.pygamepointer[0] = device._width
          device.pygamepointer[2] = device._height
          device._position = [0, device.pygamepointer[1]] 
        else:
          device._position = [device.pygamepointer[0], device.pygamepointer[1]]     
          device.pygamepointer[0] = device.pygamepointer[0] + device._width
      
      if ((device._position[1] + device._height) > screen_height) or ((device._position[0] + device._width) > screen_width) :
        print "The screen dimensions are too little for the devices (or widgets). Change them in Display() parameters in config.py"
        exit(1) 
      device._box = [device._width, device._height]
      
  def ecu(self, ecu):
    """
    * Depending on pygame/consol, display information to the user (from ecu.start())
    @param ecu ecu to modify
    """ 
    if (self.pygame_bool == True):
      import pygame
      for name, device in ecu._devices.iteritems():
        device._font = pygame.font.Font(None, 20) #TODO : insert font in const.py
        device.display_on_pygame_adding_widgets(self._widget_list)
    
  def scheduler(self, sched):
    """
    * Set variable as right function to call to display from the device : pygame or consol
    @ param sched sched to modify
    """
    if (self.pygame_bool == False):
      sched._pygameOrNotPygame = sched.withoutPygame
    else:
      sched._pygameOrNotPygame = sched.withPygame
                  
  def start(self):
    """
    * Initialize widget list and store it in scheduler
    * Display on the consol the display mode used (to the user)
    """
    if (self.pygame_bool == True):
      self._widget_list = Widget()
      from config import scheduler
      scheduler._widg = self._widget_list
      print "Display mode : Pygame"
    else:
      print "Display mode : Consol"
      
  def end(self):
    """
    * Quit pygame
    """
    if (self.pygame_bool == True):
      self._widget_list.quit_pygame()
  
  
    