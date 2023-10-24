#! /usr/bin/python3
# -*- coding: UTF-8 -*-

#-----------------------------------------------------------------------------------------------------------------------

import sys, os, json

#-----------------------------------------------------------------------------------------------------------------------

#----------------------------------------------------------------- Get script absolute path
scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))
os.chdir (scriptDir)
#----------------------------------------------------------------- Get goal as first argument
goal = "all" # Default goal
if len (sys.argv) > 1 :
  goal = sys.argv [1]
#----------------------------------------------------------------- Get max parallel jobs as second argument
maxParallelJobs = 0 # 0 means use host processor count
if len (sys.argv) > 2 :
  maxParallelJobs = int (sys.argv [2])
#----------------------------------------------------------------- Get json description dictionary
jsonFilePath = os.path.normpath (scriptDir + "/../build/output/file-list.json")
with open (jsonFilePath) as f:
  dictionary = json.loads (f.read ())
LIBPM_DIRECTORY_PATH = dictionary ["LIBPM_DIRECTORY_PATH"]
#----------------------------------------------------------------- Import builder
sys.path.append (os.path.abspath (LIBPM_DIRECTORY_PATH + "/python-makefiles"))
from x86linux_on_macosx_gcc_tools_64 import buildForLinux64OnMacOSX
#----------------------------------------------------------------- Build
buildForLinux64OnMacOSX (dictionary, jsonFilePath, "goil", "build", goal, maxParallelJobs, maxParallelJobs == 1)

#-----------------------------------------------------------------------------------------------------------------------
