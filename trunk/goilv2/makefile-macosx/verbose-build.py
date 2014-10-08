#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#------------------------------------------------------------------------------*
# https://docs.python.org/2/library/subprocess.html#module-subprocess

import subprocess
import sys
import os
import atexit

#------------------------------------------------------------------------------*

def cleanup():
  if childProcess.poll () == None :
    childProcess.kill ()

#------------------------------------------------------------------------------*

#--- Register a function for killing subprocess
atexit.register (cleanup)
#--- Get script absolute path
scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))
#---
childProcess = subprocess.Popen (["make", "all", "--warn-undefined-variables", "VERBOSE=1"], cwd=scriptDir)
#--- Wait for subprocess termination
if childProcess.poll () == None :
  childProcess.wait ()
if childProcess.returncode != 0 :
  sys.exit (childProcess.returncode)

#------------------------------------------------------------------------------*
