###############################################################################
# IMPORTS
###############################################################################
import device
from buttonminus import ButtonMinus
from const import *

###############################################################################
# BUTTON CLASS
###############################################################################
class BPMinus(device.Device):
  """
  """

  def __init__(self, name, id, signal = device.SIGUSR2, registers = None):
    """
    Constructor.
    @see Device.__init__()
    @param delay time (second) between two shots (This is a float)
    """
    device.Device.__init__(self, name, id, signal, registers)
    device.Device.location(self, button_width, button_height)
   
  def start(self):
    """
    Nothing to be done for starting device because
    it waits for command from the user.
    """

  def draw(self, widget_list):
    ButtonMinus(widget_list, self, self.callbackIndex, [self._localisation[0], self._localisation[1]])
    