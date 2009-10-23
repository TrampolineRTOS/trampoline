###############################################################################
# IMPORTS
###############################################################################
import widget
import pygame
from const import *

###############################################################################
# BUTTON CLASS
###############################################################################
class Button(widget.Widget):
  """
  Button Plus
  """
  def __init__(self, widg, device, pos):
     """
     Constructor : Initialize button appearance (button unpressed), the legend and ad the widget to the widget list.
     @param widg widgets list
     @param device widget's device
     @param pos widget position
     """
     self.__device = device
     self._pos = pos
     
     self.button_unpressed()
     
     self.__legend = device._font.render(device.name, 1, (0, 0, 0))
     self.__legendrect = self.__legend.get_rect()
     temp_size = device._font.size(str(device.name))
     self.__legendrect = self.__legendrect.move([pos[0] + button_width - temp_size[0], pos[1] + button_height - temp_size[1]])  
     
     screen = pygame.display.get_surface()
     screen.blit(self.__background, self.__backgroundrect)
     screen.blit(self.__legend, self.__legendrect)
     pygame.display.flip()
     
     widg.add(self, device, device.callbackIndex, [[pos[0],pos[1]],[pos[0]+button_width,pos[1]+button_height]])     
  
  def button_pressed(self):
     """
     * Change picture when button is pressed
     """
     self.__background = pygame.image.load("pictures/BPPlus_pressed.jpg")
     self.__backgroundrect = self.__background.get_rect()
     self.__backgroundrect = self.__backgroundrect.move([self._pos[0] + border_line, self._pos[1] + border_line])
     
     screen = pygame.display.get_surface()
     screen.blit(self.__background, self.__backgroundrect)
     pygame.display.flip()
     
  def button_unpressed(self):
     """
     * Change picture when button is unpressed
     """
     self.__background = pygame.image.load("pictures/BPPlus.jpg")
     self.__backgroundrect = self.__background.get_rect()
     self.__backgroundrect = self.__backgroundrect.move([self._pos[0] + border_line, self._pos[1] + border_line])
    
     screen = pygame.display.get_surface()
     screen.blit(self.__background, self.__backgroundrect)
     pygame.display.flip()
     
  def event(self, event):
    """
    * Launch appropriate methode depending on the event received (MouseDown or MouseUp)
    @param event event received
    """
    if event.type == MOUSEBUTTONDOWN:
      self.button_pressed()
      self.__device.sendIt()
    elif event.type == MOUSEBUTTONUP:
      self.button_unpressed()
    