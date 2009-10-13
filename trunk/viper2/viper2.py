#!/usr/local/bin/python

###############################################################################
# check that viper2 ipc lib is compiled.
###############################################################################
import os
try:
  import ipc
except:
  os.system("make all")
    
###############################################################################
# IMPORT
###############################################################################
import sys
sys.path.append('module')
sys.path.append('device')
sys.path.append('ipc')
sys.path.append('widget')

import signal
import traceback
import subprocess
import config
from widget import Widget

###############################################################################
# SIGNAL HANDLER
###############################################################################
def signalHandler(signum, stackFrame):
  print "\nSignal catch, stop Viper 2..."
  config.scheduler.kill()

###############################################################################
# MAIN
###############################################################################
#Help
if "-h" in sys.argv or "--help" in sys.argv:
  print "USAGE: ./viper2.py [-g [-c [--nodep]]]"
  print ""
  print "\tWith no option viper2.py runs trampolines and emulates devices"
  print ""
  print "\t-g : Generate vp_ipc_devices.h and target.cfg"
  print "\t-c : Use with -g, compile trampolines"
  print "\t-m : Use with -m, clean dependencies"
  print "\t--nodep : Use with -c, compile with NODEP=1 option"

#Clean
elif "-m" in sys.argv or "--mrproper" in sys.argv:
  os.system("make mrproper")
  for ecu in config.allEcus:
    os.system("cd " + ecu._dir + "; rm -rf build; rm -rf defaultAppWorkstation; rm -rf Make-rules; rm -rf Makefile; rm -rf trampoline; rm -rf target.cfg; rm -rf vp_ipc_devices.h")

#Generate
elif "-g" in sys.argv or "--generate" in sys.argv:
  for ecu in config.allEcus:
    error = False
    ecu.generate()

    #Compile
    if "-c" in sys.argv or "--compile" in sys.argv:
      command = ["sh", "./genTpl.sh", ecu.getDir()]
      if "-nodep" in sys.argv or "--nodep" in sys.argv:
        command.append("NODEP")

      make = subprocess.Popen(command,
	  stdin=subprocess.PIPE, 
	  stdout=subprocess.PIPE, 
	  stderr=subprocess.PIPE)

      print "Compiling trampoline :", ecu.getDir()

      make.wait()
      for line in make.stderr:
        error = True
        print line

      if error:
        print "Error while generating trampoline :", ecu.getDir(),"quit viper2."
        break

#Run & kill
else:
  try:
    """ Signal handler """
    # CTRL+C
    signal.signal(signal.SIGINT, signalHandler)
    
    """ Start all ecus """
    for ecu in config.allEcus:
      ecu.start()

    """ Start Pygame - Init 'widg' as widgets container """
    widget_list = Widget()
    """ Draw ECUs' Devices - Insert Widgets in 'widg' if needed """
    for ecu in config.allEcus:
      ecu.draw(widget_list)

    """ Start logical scheduler """
    config.scheduler.start(widget_list)
    
  except Exception:
    traceback.print_exc()

  finally:
    """ Logical scheduler already killed """

    """ Kill all ecus """
    for ecu in config.allEcus:
     ecu.kill()

    print "\nBye,"
