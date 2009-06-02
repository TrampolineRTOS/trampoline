###############################################################################
# IMPORTS
###############################################################################
import signal
from register import Register

###############################################################################
# CONSTANTES
###############################################################################
SIGALRM = signal.SIGALRM 
SIGUSR1 = signal.SIGUSR1
SIGUSR2 = signal.SIGUSR2

###############################################################################
# DEVICE CLASS
###############################################################################
class Device(object):
  """
  Device class, represent the comportement of a device for the Ecu
  """

  def __init__(self, name, callbackIndex, signal, registers = None):
    """
    Constructor.
    @param name the device's name. This name is used to generate header
	    and to access the device from the Ecu class
    @param callbackIndex index of the callbacks' table use by trampoline
	    interruption handler
    @param signal signal to use (SIGALARM, SIGUSR or SIGUSR2)
    @param registers registers list used by the device. (class Register)
    """

    """ Copy """
    if callbackIndex > 31 or callbackIndex < 0:
      raise ValueError, "Callback index must be between 0 and 31 !"
    self.callbackIndex = callbackIndex
    self.name	       = name
    self._signal       = signal

    """ Attributes """
    self.id	    = 1 << callbackIndex
    self.__offset   = 0
    self._registers = {} # Dict
    self._scheduler = None
    self._ecu       = None

    """ Add registers """
    if registers:
      self.add(registers)

  def add(self, registers):
    """
    Add registers to the device
    @param registers registers list to add (class Register)
    """
    for register in registers:
      if register.id != -1 and self.__offset < register.id:
	self.__offset = register.id
      if register.id == - 1:
	register.setID(1 << (self.__offset + len(self.registers)))
      self.registers[register.name] = register

  def generate(self, header):
    """
    Generate the header file use to compile trampoline with the same identifiers
    than viper 2
    @param header file descriptor where device have to write its generation
    """

    """ Generate trampoline header """
    for name, register in self._registers.iteritems():
      header.write("const reg_id_t " + self.name + "_" + register.name + " = " + self.name + " | " + register.name + ";\n")

  def generateRegisters(self, header):
    """
    Generate the header file use to compile trampolin with the same identifiers
    than viper 2
    @param header file descriptor where device have to write its generation
    """
    for name, register in self._registers.iteritems():
      register.generate(header)


  def setEcu(self, ecu):
    """
    Set ecu to use
    """
    self._ecu = ecu

  def setScheduler(self, scheduler):
    """
    Set logical scheduler to use
    """
    self._scheduler = scheduler

  def sendIt(self):
    """
    Send interruption ID
    """
    self._ecu.sendIt(self._signal, self.id)

  def event(self, modifiedRegisters = None):
    pass # TODO How to do abstract method with Python ?

  def start(self):
    pass
