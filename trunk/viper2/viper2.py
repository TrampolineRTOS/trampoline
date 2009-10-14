###############################################################################
# Add directories to the list of strings that specifies the search path for modules
###############################################################################
import sys
sys.path.append('module')
sys.path.append('device')
sys.path.append('ipc')
sys.path.append('widget')

##############################################################################
# Check that viper2 ipc lib is compiled. Otherwise, compile it and set python paths 
###############################################################################
import os
import commands
try:
  import ipc
except:
  """ Set python paths (lib and include)
      in Makefile according to python used  
  """
  vers = sys.version_info
  vers_1 = commands.getoutput("echo '" + str(vers) + "' | awk -F',' '{print $1}' | awk -F'(' '{print $2}'")
  vers_2 = commands.getoutput("echo '" + str(vers) + "' | awk '{print $2}' | awk -F',' '{print $1}'")
  #vers_python = "python" + vers_1 + "." + vers_2
  vers_python = commands.getoutput("echo python" + vers_1 + "." + vers_2)

  #get python (bin) path
  wich_python = commands.getoutput("which " + vers_python)
  path_python_bin = commands.getoutput("echo " + wich_python + " | sed 's_n/" + vers_python + "_n_g'")

  #get python include path 
  path_python_include = commands.getoutput("echo " + path_python_bin + " | sed 's/bin/include/g'")
  #get python lib path
  path_python_lib = commands.getoutput("echo " + path_python_bin + " | sed 's/bin/lib/g'")

  #change path in Makefile
  commands.getoutput("sed 's:PATH_PYTHON_INCLUDE:" + path_python_include + ":g' Makefile > TMPFILE && mv TMPFILE Makefile")
  commands.getoutput("sed 's:PATH_PYTHON_LIB:" + path_python_lib + ":g' Makefile > TMPFILE && mv TMPFILE Makefile")
  commands.getoutput("sed 's:VERS_PYTHON:" + vers_python + ":g' Makefile > TMPFILE && mv TMPFILE Makefile")

  """ Make libraries """
  os.system("make all")
  
###############################################################################
# IMPORT
###############################################################################
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
  print "\t-m : Clean dependencies (before a commit)"
  print "\t--nodep : Use with -c, compile with NODEP=1 option"

#Clean
elif "-m" in sys.argv or "--mrproper" in sys.argv:
  """ Clean dependencies """
  os.system("make mrproper")
  for ecu in config.allEcus:
    os.system("cd " + ecu._dir + "; rm -rf build; rm -rf defaultAppWorkstation; rm -rf Make-rules; rm -rf Makefile; rm -rf trampoline; rm -rf target.cfg; rm -rf vp_ipc_devices.h")
  
  """ ReSet python paths (lib and include)
      in Makefile according to python used
  """
  vers = sys.version_info
  vers_1 = commands.getoutput("echo '" + str(vers) + "' | awk -F',' '{print $1}' | awk -F'(' '{print $2}'")
  vers_2 = commands.getoutput("echo '" + str(vers) + "' | awk '{print $2}' | awk -F',' '{print $1}'")
  #vers_python = "python" + vers_1 + "." + vers_2
  vers_python = commands.getoutput("echo python" + vers_1 + "." + vers_2)

  #get python (bin) path
  wich_python = commands.getoutput("which " + vers_python)
  path_python_bin = commands.getoutput("echo " + wich_python + " | sed 's_n/" + vers_python + "_n_g'")

  #get python include path 
  path_python_include = commands.getoutput("echo " + path_python_bin + " | sed 's/bin/include/g'")
  #get python lib path
  path_python_lib = commands.getoutput("echo " + path_python_bin + " | sed 's/bin/lib/g'")

  #change path in Makefile
  commands.getoutput("sed 's:" + path_python_include + ":PATH_PYTHON_INCLUDE:g' Makefile > TMPFILE && mv TMPFILE Makefile")
  commands.getoutput("sed 's:" + path_python_lib + ":PATH_PYTHON_LIB:g' Makefile > TMPFILE && mv TMPFILE Makefile")
  commands.getoutput("sed 's:" + vers_python + ":VERS_PYTHON:g' Makefile > TMPFILE && mv TMPFILE Makefile")
  
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
