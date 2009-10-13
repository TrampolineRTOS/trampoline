###############################################################################
# IMPORTS
###############################################################################
import device
import pygame
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
  
  def __init__(self, name, id, delay = 0, signal = device.SIGUSR2):
    """
    Constructor.
    @see Device.__init__()
    """
    Reg = Register(name + "_REG")
    self.__reg     = Reg.name

    device.Device.__init__(self, name, id, signal, [Reg])
    device.Device.location(self, dac_width, dac_height)
    self.__name     = name
    self.__value    = 0
    
    """ Attributes for Pygame """
    self.__oscillo_x_start = 0
    self.__oscillo_x_start_bool = 0
    self.__volt_div 	= 1
    self.__sec_div 		= 1
    self.__points_list 	= []
    self.__delay_from_last = float(delay)
    self.__time 		= 0
    self.__adjust_pixel = 0
    
    self.__background 	  = None
    self.__backgroundrect = None
    self.__legend		  = None
    self.__legendrect     = None
  
  def event(self, ev, modifiedRegisters = None):
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
      print "[VPR] (" + str(self.__name) + ") " + str(self.__value)
      #update widget
      self.draw_update()
      
    else:
      print "[VPR](DEBUG) Some registers are not handle :", modifiedRegisters

  def draw(self, widget_list):
    """Initialise device's display"""
    self.draw_init()
    #TODO : insert "Input Text" widget to change time division and "voltage" division
      
  def draw_init(self):
      self.__legend = self._font.render(self._ecu.getDir() + self.name, 1, (0, 0, 0))
      self.__legendrect = self.__legend.get_rect()
      temp_size = self._font.size(str(self._ecu.getDir()) + str(self.name))
      self.__legendrect = self.__legendrect.move([self._localisation[0] + dac_width - temp_size[0] - border_line, self._localisation[1] + dac_height - temp_size[1]])  
      
      self.draw_reset()
      
      screen = pygame.display.get_surface()
      screen.blit(self.__background, self.__backgroundrect)
      screen.blit(self.__legend, self.__legendrect)
      pygame.display.flip()

  def draw_update(self):
      oscillo_y_end = max_volt - self.__value*max_dac*max_volt/(4*self.__volt_div*255)      
      delta_time = self.__new_time - self.__time
      self.__time = self.__new_time
      delta_time_pixel = (delta_time*max_time/(10*self.__sec_div))
      if ((self.__oscillo_x_start + delta_time_pixel) > max_time) or (self.__oscillo_x_start_bool == 0):
        self.__oscillo_x_start_bool = 1
        delta_time_pixel = 0
        self.draw_reset()
        self.__oscillo_x_start = 0
        self.__points_list = [(0, oscillo_y_end)]
      oscillo_x_end = self.__oscillo_x_start + delta_time_pixel

      self.__points_list.append((oscillo_x_end, oscillo_y_end))
      pygame.draw.lines(self.__background, (249, 255, 35), 0, self.__points_list, 1)
      self.__oscillo_x_start = oscillo_x_end
                 
      """ Update screen """
      screen = pygame.display.get_surface()
      screen.blit(self.__background, self.__backgroundrect)
      pygame.display.flip()
      
  def draw_reset(self):          
      #TODO : find where to put that because it's useless to call it everytime an event is received
      self.__background = pygame.image.load("pictures/oscilloscope_background.jpg")
      self.__backgroundrect = self.__background.get_rect()
      self.__backgroundrect = self.__backgroundrect.move([self._localisation[0] + border_line , self._localisation[1] + border_line])
       
  def start(self):
    """
    Nothing to be done for start DAC because
    it waits for command from Trampoline.
    """
    
