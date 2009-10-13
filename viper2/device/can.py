###############################################################################
# IMPORTS
###############################################################################
import device
from register import Register

###############################################################################
# CAN CLASS
###############################################################################
class CAN(device.Device):
  """
  Timer device. This timer can run with a one shot and you could specify a delay
  """

  def __init__(self, network, name, id, id2, signal = device.SIGUSR2):
    """
    Constructor.
    @see Device.__init__()
    """
    #add can to the network
    self.__network = network
    network.add(self, id2)
    
    """ Create CAN Registers """
    Reg1 = Register("SEND_FRAME_REG1")
    Reg2 = Register("SEND_FRAME_REG2")
    Reg3 = Register("SEND_FRAME_REG3")
    Reg4 = Register("SEND_FRAME_REG4")
    Reg5 = Register("SEND_FRAME_REG5")
    Reg6 = Register("SEND_FRAME_REG6")
    Reg7 = Register("RECEIVE_FRAME_REG1")
    Reg8 = Register("RECEIVE_FRAME_REG2")
    Reg9 = Register("RECEIVE_FRAME_REG3")
    Reg10 = Register("RECEIVE_FRAME_REG4")
    Reg11 = Register("RECEIVE_FRAME_REG5")
    Reg12 = Register("RECEIVE_FRAME_REG6")
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
    
    device.Device.__init__(self, name, id, signal, [Reg1, Reg2, Reg3, Reg4, Reg5, Reg6, Reg7, Reg8, Reg9, Reg10, Reg11, Reg12])
    self.__name       = name
    self.__id2        = id2
    
  def event(self, ev, modifiedRegisters = None):
    """
    Call from Scheduler
    """
    
    """ If event doesn't come from Trampoline """
    if not modifiedRegisters:
      print "[VPR] (" + str(self.__name) + ") Event doesn't come from Trampoline !!! "

      """ If event come from Trampoline """
      """ Get command """
    elif self._registers[self._reg1].id in modifiedRegisters:
      print "[VPR] (" + str(self.__name) + ") : [filters + transmission]" # + str(self._registers[self._reg1].read())  + " ; " + str(self._registers[self._reg2].read())  + " ; " + str(self._registers[self._reg3].read())  + " ; " + str(self._registers[self._reg4].read())  + " ; " + str(self._registers[self._reg5].read())  + " ; " + str(self._registers[self._reg6].read()) 
      #update widget
      #self.draw_update()
      
      self.__network.event(self)
    
    else:
      print "[VPR](DEBUG) Some registers are not handle :", modifiedRegisters

  def send(self):
    print "can.send() name:" + str(self.__name)
    print "[VPR] (" + str(self.__name) + ") : " + str(self._registers[self._reg1].read())  + " ; " + str(self._registers[self._reg2].read())  + " ; " + str(self._registers[self._reg3].read())  + " ; " + str(self._registers[self._reg4].read())  + " ; " + str(self._registers[self._reg5].read())  + " ; " + str(self._registers[self._reg6].read()) 

  def start(self):
    """
    Call from ecu, at the beginin
    Here the first call is written to the scheduler
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
          
  def draw(self, widget):
    """ """

###############################################################################
# CAN_Network CLASS
###############################################################################
class CAN_Network(device.Device):
  """
  Timer device. This timer can run with a one shot and you could specify a delay
  """

  def __init__(self):
    """
    Constructor.
    @see Device.__init__()
    """
    self._can_list = {}
    self._can_id = 0
  
  def add(self, device, id):
    """ Add CAN node into the network """
    self._can_list[self._can_id] = device
    self._can_id = self._can_id + 1
            
  def event(self, device):
    """
    Call from CAN :
     - Dispatch received frame to all CAN devices
    """
    #TODO : check filter and dispatch to "interested" CAN
    for id_can in self._can_list:
      if (self._can_list[id_can] != device):
        #print "reg1:" + str(device._registers[device._reg1].read())
        #rg = device._registers[device._reg1].read()
        self._can_list[id_can]._registers[self._can_list[id_can]._reg7].write(device._registers[device._reg1].read())
        self._can_list[id_can]._registers[self._can_list[id_can]._reg8].write(device._registers[device._reg2].read())
        self._can_list[id_can]._registers[self._can_list[id_can]._reg9].write(device._registers[device._reg3].read())
        self._can_list[id_can]._registers[self._can_list[id_can]._reg10].write(device._registers[device._reg4].read())
        self._can_list[id_can]._registers[self._can_list[id_can]._reg11].write(device._registers[device._reg5].read())
        self._can_list[id_can]._registers[self._can_list[id_can]._reg12].write(device._registers[device._reg6].read())
        self._can_list[id_can].sendIt() 
          
  def start(self):
    """
    Call from ecu, at the beginin
    Here the first call is written to the scheduler
    """
    
  def draw(self, widget):
    """ """
