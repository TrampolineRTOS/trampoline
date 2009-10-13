###############################################################################
# IMPORTS
###############################################################################
import device
import pygame
from const import *
from register import Register

###############################################################################
# LCD CLASS
###############################################################################
class LCD(device.Device):
  """
    Liquid Crystal Display
    Viper -> Trampoline :
      * Read "regX" registers.
    
  """
  def __init__(self, name, id, delay = 0, signal = device.SIGUSR2):
    """
    Constructor.
    @see Device.__init__()
    """
    
    """ Create LCD registers"""
    Reg0 = Register(name + "_REG0")
    Reg1 = Register(name + "_REG1")
    Reg2 = Register(name + "_REG2")
    Reg3 = Register(name + "_REG3")
    Reg4 = Register(name + "_REG4")
    Reg5 = Register(name + "_REG5")
    Reg6 = Register(name + "_REG6")
    Reg7 = Register(name + "_REG7")
    Reg8 = Register(name + "_REG8")
    Reg9 = Register(name + "_REG9")
    self.__reg0     = Reg0.name
    self.__reg1     = Reg1.name
    self.__reg2     = Reg2.name
    self.__reg3     = Reg3.name
    self.__reg4     = Reg4.name
    self.__reg5     = Reg5.name
    self.__reg6     = Reg6.name
    self.__reg7     = Reg7.name
    self.__reg8     = Reg8.name
    self.__reg9     = Reg9.name
    
    device.Device.__init__(self, name, id, signal, [Reg0, Reg1, Reg2, Reg3, Reg4, Reg5, Reg6, Reg7, Reg8, Reg9])
    self.__name       = name

    """Attributes for Pygame"""
    device.Device.location(self, lcd_width, lcd_height)
    #self.__pygame_localisation()
    self.__background 	  = None
    self.__backgroundrect = None
    self.__legend		  = None
    self.__legendrect     = None
    
#  def __pygame_localisation(self):
#    if (self.pygamepointer[2] < lcd_height):
#     if ((self.pygamepointer[0] + lcd_width) < screen_width):
#      self.pygamepointer[2] = lcd_height
#     
#    if ((self.pygamepointer[0] + lcd_width) > screen_width):
#     self.pygamepointer[1] = self.pygamepointer[2]
#     self.pygamepointer[0] = 0
#     self.pygamepointer[2] = lcd_height
#     self._localisation = [self.pygamepointer[0], self.pygamepointer[1]]
#    else:
#     self._localisation = [self.pygamepointer[0], self.pygamepointer[1]]
#     self.pygamepointer[0] = self.pygamepointer[0] + lcd_width
       
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
      print "[VPR] (" + str(self.__name) + ") : " + chr(self._registers[self.__reg9].read()) + chr(self._registers[self.__reg8].read())  + chr(self._registers[self.__reg7].read()) + chr(self._registers[self.__reg6].read()) + chr(self._registers[self.__reg5].read()) + chr(self._registers[self.__reg4].read()) + chr(self._registers[self.__reg3].read()) + chr(self._registers[self.__reg2].read()) + chr(self._registers[self.__reg1].read()) + chr(self._registers[self.__reg0].read()) 
      #print "[VPR] (" + str(self.__name) + ") : " + str(self._registers[self.__reg1].read()) + "-" + str(self._registers[self.__reg0].read()) 
      #update widget
      self.draw_update()
          
    else:
      print "[VPR](DEBUG) Some registers are not handle :", modifiedRegisters

  def draw(self, widget_list):
    """Initialise pygame screen"""
    self.draw_init()

  def draw_init(self):
      """ Fill background """
      self.__background = pygame.Surface((lcd_width - 2*border_line, lcd_height - 30))
      self.__backgroundrect = self.__background.fill((255, 255, 239)) 
      self.__backgroundrect = self.__backgroundrect.move([self._localisation[0]+border_line, self._localisation[1]+border_line])
      
      self.__legend = self._font.render(self._ecu.getDir() + self.name, 1, (0, 0, 0))
      self.__legendrect = self.__legend.get_rect()
      temp_size = self._font.size(str(self._ecu.getDir()) + str(self.name))
      self.__legendrect = self.__legendrect.move([self._localisation[0] + lcd_width -temp_size[0] -border_line, self._localisation[1] + lcd_height - 30 + 2*border_line])  
      
      screen = pygame.display.get_surface()
      screen.blit(self.__background, self.__backgroundrect)
      screen.blit(self.__legend, self.__legendrect)
      pygame.display.flip()  

  def draw_update(self):
      """ Update draw """
      text = self._font.render(chr(self._registers[self.__reg9].read()) + chr(self._registers[self.__reg8].read())  + chr(self._registers[self.__reg7].read()) + chr(self._registers[self.__reg6].read()) + chr(self._registers[self.__reg5].read()) + chr(self._registers[self.__reg4].read()) + chr(self._registers[self.__reg3].read()) + chr(self._registers[self.__reg2].read()) + chr(self._registers[self.__reg1].read()) + chr(self._registers[self.__reg0].read()), 1, (0, 0, 0))
      #text = self._font.render(str(self._registers[self.__reg1].read()) + "-" + str(self._registers[self.__reg0].read()), 1, (0, 0, 0))
      textrect = text.get_rect()
      textrect = textrect.move([self._localisation[0]+ 15, self._localisation[1]+ 15])
      
      """ Update screen """
      screen = pygame.display.get_surface()
      screen.blit(self.__background, self.__backgroundrect)
      screen.blit(text, textrect)
      pygame.display.flip()  

  def start(self):
    """
    Store 32 (ASCII caracter "space") in all the registers of the LCD device
    """
    if ( self._registers[self.__reg9].read() == 0 ):
      self._registers[self.__reg9].write(32)
    if ( self._registers[self.__reg8].read() == 0 ):
      self._registers[self.__reg8].write(32)
    if ( self._registers[self.__reg7].read() == 0 ):
      self._registers[self.__reg7].write(32)
    if ( self._registers[self.__reg6].read() == 0 ):
      self._registers[self.__reg6].write(32)
    if ( self._registers[self.__reg5].read() == 0 ):
      self._registers[self.__reg5].write(32)
    if ( self._registers[self.__reg4].read() == 0 ):
      self._registers[self.__reg4].write(32)
    if ( self._registers[self.__reg3].read() == 0 ):
      self._registers[self.__reg3].write(32)
    if ( self._registers[self.__reg2].read() == 0 ):
      self._registers[self.__reg2].write(32)
    if ( self._registers[self.__reg1].read() == 0 ):
      self._registers[self.__reg1].write(32)
    if ( self._registers[self.__reg0].read() == 0 ):
      self._registers[self.__reg0].write(32)
      
