#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

import sys, os, subprocess, atexit

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

def cleanup():
  if childProcess.poll () == None :
    childProcess.kill ()

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#--- Register a function for killing subprocess
atexit.register (cleanup)
#--- Get script absolute path
scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))
#---
childProcess = subprocess.Popen (["python", "build.py", "install-release"], cwd=scriptDir)
#--- Wait for subprocess termination
if childProcess.poll () == None :
  childProcess.wait ()
if childProcess.returncode != 0 :
  sys.exit (childProcess.returncode)

#———————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
