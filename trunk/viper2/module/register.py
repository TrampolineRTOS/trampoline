###############################################################################
# IMPORTS
###############################################################################
import ipc

###############################################################################
# REGISTER CLASS
###############################################################################
class Register(object):
  """
  Register Class.
  Registers are memories shared between trampoline executable and devices.
  """

  def __init__(self, name):
    """
    Constructor.
    @param name is the name used to generate header file. It's also used to
    access the register from device.
    """
    self.name      = name
    self.id        = -1
    self.generated = False
    self.__ipc     = None
    self.__device  = None

  def setID(self, id):
    """
    Setter
    """
    self.id = id

  def generate(self, file):
    """
    Generate the header file use to compile trampolin with
	the same identifiers than viper 2
    @param file file descriptor where register have to write its generation
    """
    if not self.generated:
      self.generated = True
      file.write("const reg_id_t " + self.name + " = " + hex(self.id) + ";\n")

  def setDevice(self, device):
    """
    Setter, used by Device only
    """
    self.__device = device

  def setIPC(self, ipc):
    """
    Setter, used by Device only
    """
    self.__ipc = ipc

  def write(self, info):
    """
    Write an information to the register
    @param info info to write (must be a 32bits integer)
    """
    ipc.tpl_ipc_write_reg(self.__ipc, self.__device.longID | self.id, info)

  def read(self):
    """
    Read an information from the register
    @return info (32bits integer)
    """
    return ipc.tpl_ipc_read_reg(self.__ipc, self.device.longID | self.id)
