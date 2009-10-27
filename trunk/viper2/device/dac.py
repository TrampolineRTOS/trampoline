###############################################################################
# IMPORTS
###############################################################################
import device
import time
from const import *
from register import Register

###############################################################################
# DAC CLASS
###############################################################################
class DAC(device.Device):
  """
    Digital to Analog Converter
    Viper -> Trampoline :
      * Read "reg" register.
  """
  
  def __init__(self, name, id, signal = device.SIGUSR2, position = None):
    """
    Constructor.
    @see Device.__init__()
    """

    """ Create DAC registers"""
    Reg = Register(name + "_REG")
    self.__reg     = Reg.name

    # TODO : put that somewhere else ? (in a part of pygame display ?)
    self._width = dac_width
    self._height = dac_height
    self._position = position
    
    device.Device.__init__(self, name, id, signal, [Reg])
    self.__value    = 0
    
  def event(self, modifiedRegisters = None):
    """
    Call from Scheduler
    """
    """ If event doesn't come from Trampoline """
    self.__new_time = time.time()
           
    if not modifiedRegisters:
      """ Add new event (speed change) """
      print "[VPR] (" + str(self.__name) + ") Event doesn't come from Trampoline !!! "
      
      """ If event comes from Trampoline """
      """ Get command """
    elif self._registers[self.__reg].id in modifiedRegisters:
      self.__value = self._registers[self.__reg].read()
      self._display()
      
    else:
      print "[VPR](DEBUG) Some registers are not handle :", modifiedRegisters

  def start(self):
    """
    Nothing to be done for start DAC because
    it waits for command from Trampoline.
    """
  
  ################################################################    
  # Display on Consol
  ################################################################
  
  def display_on_consol(self):
    print "[VPR] (" + str(self.name) + ") " + str(self.__value)

  ################################################################    
  # Display on Pygame
  ################################################################
  
  def display_on_pygame_adding_widgets(self, widget_list):
    """Initialise device's display"""
    self.display_on_pygame_init()
    #TODO : insert "Input Text" widget to change time division and "voltage" division
      
  def display_on_pygame_init(self):
    """ Attributes for Pygame """
    self.__oscillo_x_start = 0
    self.__oscillo_x_start_bool = 0
    self.__volt_div 	= 1
    self.__sec_div 		= 0.5
    self.__points_list 	= []
    self.__time 		= 0
    self.__adjust_pixel = 0

    self.__legend = self._font.render(str(self.__sec_div) + "s/div    ;    " + str(self.__volt_div) + "V/div    ;    " + self._ecu.getDir() + self.name, 1, (0, 0, 0))
    self.__legendrect = self.__legend.get_rect()
    temp_size = self._font.size(str(self.__sec_div) + "s/div    ;    " + str(self.__volt_div) + "V/div    ;    " + str(self._ecu.getDir()) + str(self.name))
    self.__legendrect = self.__legendrect.move([self._position[0] + dac_width - temp_size[0] - border_line, self._position[1] + dac_height - temp_size[1]])  
      
    self.display_on_pygame_reset()
     
    screen = pygame.display.get_surface()
    screen.blit(self.__background, self.__backgroundrect)
    screen.blit(self.__legend, self.__legendrect)
    pygame.display.flip()

  def display_on_pygame(self):
    oscillo_y_end = max_volt - self.__value*max_dac*max_volt/(4*self.__volt_div*255)      
    delta_time = self.__new_time - self.__time
    self.__time = self.__new_time
    delta_time_pixel = (delta_time*max_time/(10*self.__sec_div))
    if ((self.__oscillo_x_start + delta_time_pixel) > max_time) or (self.__oscillo_x_start_bool == 0):
      self.__oscillo_x_start_bool = 1
      delta_time_pixel = 0
      self.display_on_pygame_reset()
      self.__oscillo_x_start = 0
      self.__points_list = [(0, oscillo_y_end)]
    oscillo_x_end = self.__oscillo_x_start + delta_time_pixel
    
    self.__points_list.append((oscillo_x_end, oscillo_y_end))
    pygame.draw.lines(self.__background, (249, 255, 35), 0, self.__points_list, 1)
    self.__oscillo_x_start = oscillo_x_end
      
  def display_on_pygame_reset(self):          
      self.__background = pygame.image.load("pictures/oscilloscope_background.jpg")
      self.__backgroundrect = self.__background.get_rect()
      self.__backgroundrect = self.__backgroundrect.move([self._position[0] + border_line , self._position[1] + border_line])
       
  def refresh_display(self):
    """ Update screen """
    screen = pygame.display.get_surface()
    screen.blit(self.__background, self.__backgroundrect)
    