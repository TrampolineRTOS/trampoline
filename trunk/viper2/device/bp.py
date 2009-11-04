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
  BP class, is useful in pygame mode only because it creates a widget on the
  screen which can received event from the user and send an interrupt to
  Trampoline.
  """

  def __init__(self, name, id, text = None, picture = None, position = None, registers = None, signal = device.SIGUSR2):
    """
    Constructor.
    @see Device.__init__()
    @param text text to display on the button
    @param picture button's picture
    @param position device position can be set from the User
    """
    
    self._width = button_width
    self._height = button_height
    self._position = position
    self._text = text
    self._picture = picture
    
    device.Device.__init__(self, name, id, signal, registers)
    
  def start(self):
    """
    Nothing to be done for starting device because
    it waits for command from the user.
    """

  ################################################################    
  # Display on Consol - Impossible ??
  ################################################################
 
  def display_on_console(self):
    pass

  ################################################################    
  # Display on Pygame
  ################################################################
  
  def display_on_pygame_adding_widgets(self, widget_list):
    """
    Create a widget "Button"
    @see Button class
    """
    Button(widget_list, self, [self._position[0], self._position[1]])
    
  def display_on_pygame(self):
    pass
    
  def refresh_display(self):
    pass