###############################################################################
# IMPORTS
###############################################################################

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
    self.name = name
    self.id = -1
    self.generated = False

  def setID(self, id):
    """
    Setter
    """
    self.id = id

  def generate(self, file):
    """
    Generate the header file use to compile trampolin with the same identifiers
    than viper 2
    @param file file descriptor where register have to write its generation
    """
    if not self.generated:
      self.generated = True
      file.write("const reg_id_t " + self.name + " = " + hex(self.id) + ";\n")
