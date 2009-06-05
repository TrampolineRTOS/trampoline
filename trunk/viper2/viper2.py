#!/usr/bin/python
###############################################################################
# IMPORT
###############################################################################
import sys, signal, traceback, subprocess

sys.path.append('module')
from ecu       import Ecu
from device    import Device
from register  import Register
from scheduler import Scheduler

##
# Devices
##
import device # device.SIGUSR1, device.SIGUSR2 and device.SIGALRM
sys.path.append('device')
import timer
from timer     import Timer
from motor     import Motor

###############################################################################
# GLOBALS VARIABLES
###############################################################################
scheduler = None

###############################################################################
# SIGNAL HANDLER
###############################################################################
def signalHandler(signum, stackFrame):
  print "\nSignal catch, stop Viper 2..."
  scheduler.kill()

###############################################################################
# MAIN
###############################################################################
# Scheduler
scheduler = Scheduler(speedCoeff = 1)

#Registers
 # Example : regYY = Register("YY")
captor   = Register("CAPTOR")
commande = Register("COMMANDE")

#Ecu 1
# You should always add registers in same order. Else there is an overlap.
# TODO I want to find out how to add registers with no order constraint
 # Exemple : ecu = Ecu(
 #    "./path/to/trampoline_executable",
 #    scheduler,
 #    [
 #      Device("CAN0",    2, device.SIGUSR1, [regYY, regTX]),
 #    ]
 # )
allEcus = [
  Ecu(
    "../App-vp2/trampoline",
    scheduler,
    [
      Timer("TIMER0", 7, type = timer.AUTO, delay = 0.5),
      Motor("MOTOR0", 2, captor, commande, noise = 5)   
    ]
  )
]

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
  for ecu in allEcus:
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
    for ecu in allEcus:
      ecu.start()

    """ Start logical scheduler """
    scheduler.start()

  except Exception:
    traceback.print_exc()

  finally:
    """ Kill logical scheduler """
    scheduler.kill()

    """ Kill all ecus """
    for ecu in allEcus:
      ecu.kill()

    print "\nBye,"
