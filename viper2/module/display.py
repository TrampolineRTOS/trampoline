###############################################################################
# IMPORTS
###############################################################################
from widget import Widget
from errors import IPCError

###############################################################################
# DISPLAY CLASS
###############################################################################
class Display(object):
  """
  Display class. According to the user (pygame or console mode), this class dispatchs 
  devices display in the right support. It also locates (or check if location has been
  set by the user) the device on the screen.
  """
  pygame_bool = False
  
  def __init__(self, pygame = True, screen = [800, 600]):
    """
    Constructor : Check if pygame is installed and if the user want to use pygame or not
    @param pygame boolean to display information on pygame or on console
    @param screen screen dimensions (set to [800, 600] by default)
    """
    self.pygame_bool = pygame
    self._init_display = True
    self._screen = screen
    
    #if (self.pygame_bool == True):
    #  try:
    #    import pygame
    #  except:
    #    self.pygame_bool = False
    #    raise IPCError, "You're trying to use Pygame but it is not installed. Select pygame = False in Display parameters or go to http://www.pygame.org/ to insall a Pygame version according to a Python version (http://www.python.org/)" 
 
  def device(self, device):
    """
    Set variable to the right function to call to display device information : pygame or console (from device.__init__())
    Locate "pygame" device if needed
    @param device device to modify
    """
    
    if (self.pygame_bool == False):
      device._display = device.display_on_console    
    else:
      device._display = device.display_on_pygame
      """ Locate device on the screen 
      """
      # TODO : check if position != None that the position doesn't belong to another device ?
      if (device._position == None):
        if (device.pygamepointer[2] < device._height):
          if ((device.pygamepointer[0] + device._width) < self._screen[0]):
            device.pygamepointer[2] = device._height
        if ((device.pygamepointer[0] + device._width) > self._screen[0]):
          device.pygamepointer[1] += device.pygamepointer[2]
          device.pygamepointer[0] = device._width
          device.pygamepointer[2] = device._height
          device._position = [0, device.pygamepointer[1]] 
        else:
          device._position = [device.pygamepointer[0], device.pygamepointer[1]]     
          device.pygamepointer[0] = device.pygamepointer[0] + device._width
      
      if ((device._position[1] + device._height) > self._screen[1]) or ((device._position[0] + device._width) > self._screen[0]) :
        raise IPCError, "The screen dimensions are too small for the devices (or widgets). Change them in Display() parameters in config.py"
      device._box = [device._width, device._height]
      
  def ecu(self, ecu):
    """
    Depending on pygame/console, display information to the user (from ecu.start())
    @param ecu ecu to modify
    """ 
    if (self.pygame_bool == True):
      import pygame
      for name, device in ecu._devices.iteritems():
        device._font = pygame.font.Font(None, 20) #TODO : insert font in const.py
        device.display_on_pygame_adding_widgets(self._widget_list)
    
  def scheduler(self, sched):
    """
    Set variable as right function to call to display from the device : pygame or console
    @param sched sched to modify
    """
    if (self.pygame_bool == False):
      sched._pygameOrNotPygame = sched.withoutPygame
    else:
      sched._pygameOrNotPygame = sched.withPygame
                  
  def start(self, verbosemode):
    """
    Initialize widget list and store it in scheduler
    Display on the console the display mode used (to the user)
    """
    if (self.pygame_bool == True):
      try:
        import pygame
      except:
        self.pygame_bool = False
        raise IPCError, "You're trying to use Pygame but it is not installed. Select pygame = False in Display parameters or go to http://www.pygame.org/ to insall a Pygame version according to a Python version (http://www.python.org/)"

      self._widget_list = Widget()
      from config import scheduler
      scheduler._widg = self._widget_list
      print "Display mode : Pygame"
    else:
      if(verbosemode == True):
        print "Display mode : Consol"
      
  def end(self):
    """
    Quit pygame
    """
    if (self.pygame_bool == True):
      self._widget_list.quit_pygame()
  
  
    
