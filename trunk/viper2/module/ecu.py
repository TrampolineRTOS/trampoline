###############################################################################
# IMPORTS
###############################################################################
import os, re, sys

sys.path.append('ipc')
import ipc
from device import Device

###############################################################################
# ECU CLASS
###############################################################################
class Ecu(object):
  """
  Ecu class.
  Ecu (Engine control unit) represent devices and an operating system.
  """
  
  def __init__(self, osPath, scheduler, devices = None):
    """
    Constructor.
    @osPath trampoline os executable to use with this Ecu.
    @param devices (optionnal) devices list to use in Ecu.
    """
    """ Copy """
    self.__osPath = osPath
    self.__scheduler = scheduler
    self.__dir = re.match(r'.*/+', osPath).group() #get dir from osPath
    
    """ Init """
    self.__devices = {} # Dict
    self.__offset  = 32 # 32 last bits are used by registers
    self.__ipc     = None

    """ Add devices """
    if devices != None:
      self.add(devices)

  def add(self, devices):
    """
    Add devices to the ecu.
    @param devices the devices list used by the Ecu (class Device)
    """
    for device in devices:
      self.__devices[device.name] = device

  def run(self):
    """
    Run trampoline process, run reading thread and devices.
    """
    
    """ IPC """
    self.__ipc = ipc.tpl_ipc_create_instance(self.__osPath)

    """ Init and begin """ 
    for name, device in self.__devices.iteritems():
      device.setEcu(self)
      device.setScheduler(self.__scheduler)
      device.start()

  def generate(self):
    """
    Generate the header file use to compile trampolin with the same identifiers
    than viper 2
    """

    """ Open header """
    try:
      header = open(self.__dir + "vp_ipc_devices.h", "w")
      oilFile = open(self.__dir + "target.cfg", "w")
    except IOError:
      print "Can't access to " + self.__dir + "vp_ipc_devices.h"
      print " or " + self.__dir + "target.cfg"
      raise IOError, "You should verify dir \""+ self.__dir + "\" exists and it can be writable"

    """ Generate header """
    header.write("#ifndef __VP_DEVICES_H__\n#define __VP_DEVICES_H__\n")
    header.write('\n#include "ipc/com.h" /* reg_id_t, dev_id_t */\n')
    oilFile.write("interrupts{\n")

    """ Generate device identifier """
    index = 0
    header.write("\n/* Devices */\n")
    for name, device in self.__devices.iteritems(): 
      index += 1
      header.write("const reg_id_t " + device.name + " = " + hex(device.id << self.__offset) + ";\n")
      oilFile.write("  " + device.name + " = " + str(device.callbackIndex) + ";\n")

    """ Generate register identifier """
    header.write("\n/* Registers */\n")
    for name, device in self.__devices.iteritems():
      device.generateRegisters(header)

    """ Generate matchless registers identifiers """
    header.write("\n/* Completes registers */\n")
    for name, device in self.__devices.iteritems():
      device.generate(header)

    """ Generate footer """
    header.write("\n#endif /* __VP_DEVICES_H__ */\n")
    oilFile.write("};\n")

    header.close()
    oilFile.close()

  def sendIt(self, signum, id):
    ipc.tpl_ipc_send_it(self.__ipc, signum, id)

  def kill(self):
    ipc.tpl_ipc_destroy_instance(self.__ipc)
