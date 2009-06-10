#!/usr/bin/python
###############################################################################
# IMPORT
###############################################################################
import sys
sys.path.append('module')
sys.path.append('device')
sys.path.append('ipc')

import signal
import traceback
import subprocess
import config

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
  print "\t--nodep : Use with -c, compile with NODEP=1 option"

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

    """ Start logical scheduler """
    config.scheduler.start()

  except Exception:
    traceback.print_exc()

  finally:
    """ Kill logical scheduler """
    config.scheduler.kill()

    """ Kill all ecus """
    for ecu in config.allEcus:
      ecu.kill()

    print "\nBye,"
