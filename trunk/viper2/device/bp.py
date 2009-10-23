###############################################################################
# IMPORTS
###############################################################################
import device
from button import Button
from const import *

###############################################################################
# BUTTON CLASS
###############################################################################
class BP(device.Device):
  """
  """

  def __init__(self, name, id, signal = device.SIGUSR2, registers = None):
    """
    Constructor.
    @see Device.__init__()
    @param delay time (second) between two shots (This is a float)
    """
    
    self._width = button_width
    self._height = button_height
    
    device.Device.__init__(self, name, id, signal, registers)
    
  def start(self):
    """
    Nothing to be done for starting device because
    it waits for command from the user.
    """

  ################################################################    
  # Display on Consol - Impossible ??
  ################################################################
 
  def display_on_consol(self):
    pass

  ################################################################    
  # Display on Pygame
  ################################################################
  
  def display_on_pygame_adding_widgets(self, widget_list):
    Button(widget_list, self, [self._localisation[0], self._localisation[1]])
    
  def display_on_pygame(self):
    pass
    
  def refresh_display(self):
    pass