###############################################################################
# IMPORTS
###############################################################################
import pygame
from const import *

###############################################################################
# WIDGET CLASS
###############################################################################
class Widget(object):
  """
  Container of all the widgets
  """
  ecu_number = 0
  ecu = 0
  
  def __init__(self):
    self._widget_box	    = {}
    self._widgets			= {}
    self._actual_widget 	= None
    
    """Initialise Screen"""
    pygame.init()
    screen = pygame.display.set_mode((screen_width, screen_height))
    pygame.display.set_caption('Viper2')
    background = background_color
    screen.fill(background)
    pygame.display.flip()
        
  def event(self, loc):
    """ Search if loc is in the widget 
        box and "launch" event if OK
    """ 
    #if mouse click, find the focused widget, otherwise, send event to the "actual" widget
  
  def add(self, widg, device, id, box):
    #print "widget.add() - ecu:" + str(self.ecu) + " device._ecu:" + str(device._ecu)
    if (self.ecu != device._ecu):
      self.ecu = device._ecu
      self.ecu_number = self.ecu_number + 1
    
    #print "self.ecu_number:" + str(self.ecu_number)
    
    self._widget_box[id+32*(self.ecu_number-1)] = box
    self._widgets[id+32*(self.ecu_number-1)] 	 = widg
    
    #print "self._widgets:" + str(self._widgets) + "self._widget_box:" + str(self._widget_box)
  
  def start(self):
    pass
    