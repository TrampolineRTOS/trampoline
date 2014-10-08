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
#--- Directories to clean
dir1 = scriptDir + "/../build/cli-objects/makefile-unix-debug-objects"
dir2 = scriptDir + "/../build/cli-objects/makefile-unix-objects"
#--- Files to clean
file1 = scriptDir + "/goil"
file2 = scriptDir + "/goil-debug"
#---
childProcess = subprocess.Popen (["rm", "-fr", dir1, dir2, file1, file2], cwd=scriptDir)
#--- Wait for subprocess termination
if childProcess.poll () == None :
  childProcess.wait ()
if childProcess.returncode != 0 :
  sys.exit (childProcess.returncode)

#------------------------------------------------------------------------------*
