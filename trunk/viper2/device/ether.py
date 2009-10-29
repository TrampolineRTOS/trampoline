###############################################################################
# IMPORTS
###############################################################################
import device

###############################################################################
# ETHERDEVICE CLASS
###############################################################################
class EtherDevice(device.Device):
  """
  EtherDevice class, represent an device instance, which is connected to an ether.
  """

  def __init__(self, ether):
    """
    Constructor.
    @param ether ether which belongs to the etherDevice
    """

    """ Add EtherDevice instance into the Ether list """
    self._ether = ether
    ether.add(self)
    
###############################################################################
# ETHER CLASS
###############################################################################
class Ether(object):
  """
  Ether class, represent a list of all devices (etherDevices) it can send messages
  """

  def __init__(self):
    """
    Constructor.
    """
    self._etherDeviceList = {}
    self._lastEtherDeviceId = 0
  
  def add(self, device):
    """
    * Add EtherDevice instance into the Ether list
    @param device etherdevice to add into the list
    """
    self._etherDeviceList[self._lastEtherDeviceId] = device
    self._lastEtherDeviceId = self._lastEtherDeviceId + 1
            
