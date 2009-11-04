###############################################################################
# IMPORTS
###############################################################################
import device
from ether import EtherDevice
from register import Register

###############################################################################
# CAN CLASS
###############################################################################
class CAN(device.Device):
  """
  CAN class is a class which herits of an EtherDevice class, linked to
  the ether in parameters
  """

  def __init__(self, ether, name, id, position = None, signal = device.SIGUSR2):
    """
    Constructor.
    @see Device.__init__()
    @param ether ether which belongs the Network instance
    @param position device position can be set from the User
    """

    """ Add Ether Device to the ether """
    EtherDevice.__init__(self, ether)
    
    """ Create CAN Registers """
    Reg1 = Register(name + "_SEND_FRAME_REG1")
    Reg2 = Register(name + "_SEND_FRAME_REG2")
    Reg3 = Register(name + "_SEND_FRAME_REG3")
    Reg4 = Register(name + "_SEND_FRAME_REG4")
    Reg5 = Register(name + "_SEND_FRAME_REG5")
    Reg6 = Register(name + "_SEND_FRAME_REG6")
    Reg7 = Register(name + "_RECEIVE_FRAME_REG1")
    Reg8 = Register(name + "_RECEIVE_FRAME_REG2")
    Reg9 = Register(name + "_RECEIVE_FRAME_REG3")
    Reg10 = Register(name + "_RECEIVE_FRAME_REG4")
    Reg11 = Register(name + "_RECEIVE_FRAME_REG5")
    Reg12 = Register(name + "_RECEIVE_FRAME_REG6")
    self._reg1     = Reg1.name
    self._reg2     = Reg2.name
    self._reg3     = Reg3.name
    self._reg4     = Reg4.name
    self._reg5     = Reg5.name
    self._reg6     = Reg6.name
    self._reg7     = Reg7.name
    self._reg8     = Reg8.name
    self._reg9     = Reg9.name
    self._reg10     = Reg10.name
    self._reg11     = Reg11.name
    self._reg12     = Reg12.name
    
    self._width = 0
    self._height = 0
    self._position = position
        
    device.Device.__init__(self, name, id, signal, [Reg1, Reg2, Reg3, Reg4, Reg5, Reg6, Reg7, Reg8, Reg9, Reg10, Reg11, Reg12])
    
  def event(self, modifiedRegisters = None):
    """
    Call from Scheduler
    """
    
    """ If event doesn't come from Trampoline """
    if not modifiedRegisters:
      print "[VPR] (" + str(self.name) + ") Event doesn't come from Trampoline !!! "

      """ If event come from Trampoline """
      """ Get command """
    elif self._registers[self._reg1].id in modifiedRegisters:
      self._display()
      self.__network.event(self)
    
    else:
      print "[VPR](DEBUG) Some registers are not handle :", modifiedRegisters
  
  def sendToNetwork(self):
    """
    Dispatch received frame to all devices in the same ether
    """
    #TODO : check filter and dispatch to "interested" CAN ?
    for etherDeviceId in self._ether._etherDeviceList:
      if (self._ether._etherDeviceList[etherDeviceId] != self):
        self._ether._etherDeviceList[etherDeviceId]._registers[self._ether._etherDeviceList[etherDeviceId]._reg7].write(self._registers[self._reg1].read())
        self._ether._etherDeviceList[etherDeviceId]._registers[self._ether._etherDeviceList[etherDeviceId]._reg8].write(self._registers[self._reg2].read())
        self._ether._etherDeviceList[etherDeviceId]._registers[self._ether._etherDeviceList[etherDeviceId]._reg9].write(self._registers[self._reg3].read())
        self._ether._etherDeviceList[etherDeviceId]._registers[self._ether._etherDeviceList[etherDeviceId]._reg10].write(self._registers[self._reg4].read())
        self._ether._etherDeviceList[etherDeviceId]._registers[self._ether._etherDeviceList[etherDeviceId]._reg11].write(self._registers[self._reg5].read())
        self._ether._etherDeviceList[etherDeviceId]._registers[self._ether._etherDeviceList[etherDeviceId]._reg12].write(self._registers[self._reg6].read())
        self._ether._etherDeviceList[etherDeviceId].sendIt() 

  def start(self):
    """
    Call from ecu, at the begining.
    Initialize registers.
    """
    if ( self._registers[self._reg12].read() == 0 ):
      self._registers[self._reg12].write(32)
    if ( self._registers[self._reg11].read() == 0 ):
      self._registers[self._reg11].write(32)
    if ( self._registers[self._reg10].read() == 0 ):
      self._registers[self._reg10].write(32)
    if ( self._registers[self._reg9].read() == 0 ):
      self._registers[self._reg9].write(32)
    if ( self._registers[self._reg8].read() == 0 ):
      self._registers[self._reg8].write(32)
    if ( self._registers[self._reg7].read() == 0 ):
      self._registers[self._reg7].write(32)
    if ( self._registers[self._reg6].read() == 0 ):
      self._registers[self._reg6].write(32)
    if ( self._registers[self._reg5].read() == 0 ):
      self._registers[self._reg5].write(32)
    if ( self._registers[self._reg4].read() == 0 ):
      self._registers[self._reg4].write(32)
    if ( self._registers[self._reg3].read() == 0 ):
      self._registers[self._reg3].write(32)
    if ( self._registers[self._reg2].read() == 0 ):
      self._registers[self._reg2].write(32)
    if ( self._registers[self._reg1].read() == 0 ):
      self._registers[self._reg1].write(32)

  ################################################################    
  # Display on Consol
  ################################################################
  
  def display_on_console(self):
      print "[VPR] (" + str(self.name) + ") : " + str(self._registers[self._reg1].read())  + " ; " + str(self._registers[self._reg2].read())  + " ; " + str(self._registers[self._reg3].read())  + " ; " + str(self._registers[self._reg4].read())  + " ; " + str(self._registers[self._reg5].read())  + " ; " + str(self._registers[self._reg6].read()) 
  
  ################################################################    
  # Display on Pygame
  ################################################################

  def display_on_pygame_adding_widgets(self, widget_list):
    pass
    
  def display_on_pygame(self):
    print "[VPR] (" + str(self.name) + ") : " + str(self._registers[self._reg1].read())  + " ; " + str(self._registers[self._reg2].read())  + " ; " + str(self._registers[self._reg3].read())  + " ; " + str(self._registers[self._reg4].read())  + " ; " + str(self._registers[self._reg5].read())  + " ; " + str(self._registers[self._reg6].read()) 
    
  def refresh_display(self):
    pass
