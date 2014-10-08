#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#------------------------------------------------------------------------------*
# https://docs.python.org/2/library/subprocess.html#module-subprocess

import subprocess
import sys
import os
import atexit
if sys.version_info >= (2, 6) :
  import multiprocessing

#------------------------------------------------------------------------------*

def cleanup():
  if childProcess.poll () == None :
    childProcess.kill ()

#------------------------------------------------------------------------------*

#--- Register a function for killing subprocess
atexit.register (cleanup)
#--- Get script absolute path
scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))
#--- Getting core count
if sys.version_info >= (2, 6) :
  coreCount = multiprocessing.cpu_count ()
else:
  coreCount = 1
#print coreCount
#---
childProcess = subprocess.Popen (["make", "all", "-j" + str (coreCount), "--warn-undefined-variables"], cwd=scriptDir)
#--- Wait for subprocess termination
if childProcess.poll () == None :
  childProcess.wait ()
if childProcess.returncode != 0 :
  sys.exit (childProcess.returncode)

#------------------------------------------------------------------------------*
