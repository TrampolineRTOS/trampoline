#! /usr/bin/env python3

#-----------------------------------------------------------------------------*
# Build goil for mac os x, linux 32, linux 64 and windows
# zip the files
#-----------------------------------------------------------------------------*

import sys, os

target_dir = "/Users/jlb/Documents/Clouds/cloud-univ-nantes/goil-distrib"

#-----------------------------------------------------------------------------*
print("*** building goil for Mac OS X")
os.chdir("makefile-unix")
os.system("./build.py")
if os.access("goil-mac-os-x.zip", os.W_OK):
  os.remove("goil-mac-os-x.zip")
os.system("zip goil-mac-os-x.zip goil goil-debug")
os.system(f"cp goil-mac-os-x.zip {target_dir}")
#-----------------------------------------------------------------------------*
print("*** building goil for Linux 32 bits")
os.chdir("../makefile-x86linux32-on-macosx")
os.system("./build.py")
if os.access("goil-linux-32.zip", os.W_OK):
  os.remove("goil-linux-32.zip")
os.system("zip goil-linux-32.zip goil goil-debug")
os.system(f"cp goil-linux-32.zip  {target_dir}")
#-----------------------------------------------------------------------------*
print("*** building goil for Linux 64 bits")
os.chdir("../makefile-x86linux64-on-macosx")
os.system("./build.py")
if os.access("goil-linux-64.zip", os.W_OK):
  os.remove("goil-linux-64.zip")
os.system("zip goil-linux-64.zip goil goil-debug")
os.system(f"cp goil-linux-64.zip  {target_dir}")
#-----------------------------------------------------------------------------*
print("*** building goil for Win 32")
os.chdir("../makefile-win32-on-macosx")
os.system("./build.py")
if os.access("goil-windows.zip", os.W_OK):
  os.remove("goil-windows.zip")
os.system("zip goil-windows.zip goil.exe goil-debug.exe")
os.system(f"cp goil-windows.zip  {target_dir}")
os.chdir("..")
#-----------------------------------------------------------------------------*
