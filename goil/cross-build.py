#! /usr/bin/env python3

#-----------------------------------------------------------------------------*
# Build goil for mac os x, linux 32, linux 64 and windows
# zip the files
#-----------------------------------------------------------------------------*

import sys, os, argparse, subprocess

target_dir = "/Users/jlb/Documents/Clouds/cloud-univ-nantes/goil-distrib"

parser = argparse.ArgumentParser(
  prog = "crossbuild.py",
  description = "Build goil for all platform"
)

parser.add_argument('-n', '--no-upload', action = 'store_true')
args = parser.parse_args()
md5s = ""

#-----------------------------------------------------------------------------*
print("*** building goil for Mac OS X")
os.chdir("makefile-macosx")
os.system("./build.py")
#--- Pack the universal binary
os.chdir("universal")
if os.access("goil-mac-os-x-universal.zip", os.W_OK):
  os.remove("goil-mac-os-x-universal.zip")
print("*** packing goil for Mac OS X Universal")
os.system("zip goil-mac-os-x-universal.zip goil goil-debug")
md5s = md5s + "* " + str(subprocess.check_output(["md5", "goil-mac-os-x-universal.zip"]).decode('utf-8'))
if not args.no_upload:
  print("*** uploading goil for Mac OS X Universal to the cloud")
  os.system(f"cp goil-mac-os-x-universal.zip {target_dir}")
#--- Pack the arm64
os.chdir("../arm64")
if os.access("goil-mac-os-x-silicon.zip", os.W_OK):
  os.remove("goil-mac-os-x-silicon.zip")
print("*** packing goil for Mac OS X Apple Silicon")
os.system("zip goil-mac-os-x-silicon.zip goil goil-debug")
md5s = md5s + "* " + str(subprocess.check_output(["md5", "goil-mac-os-x-silicon.zip"]).decode('utf-8'))
if not args.no_upload:
  print("*** uploading goil for Mac OS X Apple Silicon to the cloud")
  os.system(f"cp goil-mac-os-x-silicon.zip {target_dir}")
#--- Pack the x86_64
os.chdir("../x86_64")
if os.access("goil-mac-os-x.zip", os.W_OK):
  os.remove("goil-mac-os-x.zip")
print("*** packing goil for Mac OS X x86_64")
os.system("zip goil-mac-os-x.zip goil goil-debug")
md5s = md5s + "* " + str(subprocess.check_output(["md5", "goil-mac-os-x.zip"]).decode('utf-8'))
if not args.no_upload:
  print("*** uploading goil for Mac OS X x86_64 to the cloud")
  os.system(f"cp goil-mac-os-x.zip {target_dir}")
#-----------------------------------------------------------------------------*
print("*** building goil for Linux 32 bits")
os.chdir("../../makefile-x86linux32-on-macosx")
os.system("./build.py")
if os.access("goil-linux-32.zip", os.W_OK):
  os.remove("goil-linux-32.zip")
print("*** packing goil for Linux 32 bits")
os.system("zip goil-linux-32.zip goil goil-debug")
md5s = md5s + "* " + str(subprocess.check_output(["md5", "goil-linux-32.zip"]).decode('utf-8'))
if not args.no_upload:
  print("*** uploading goil for Linux 32 bits to the cloud")
  os.system(f"cp goil-linux-32.zip  {target_dir}")
#-----------------------------------------------------------------------------*
print("*** building goil for Linux 64 bits")
os.chdir("../makefile-x86linux64-on-macosx")
os.system("./build.py")
if os.access("goil-linux-64.zip", os.W_OK):
  os.remove("goil-linux-64.zip")
print("*** packing goil for Linux 64 bits")
os.system("zip goil-linux-64.zip goil goil-debug")
md5s = md5s + "* " + str(subprocess.check_output(["md5", "goil-linux-64.zip"]).decode('utf-8'))
if not args.no_upload:
  print("*** uploading goil for Linux 64 bits to the cloud")
  os.system(f"cp goil-linux-64.zip  {target_dir}")
#-----------------------------------------------------------------------------*
print("*** building goil for Win 32")
os.chdir("../makefile-win32-on-macosx")
os.system("./build.py")
if os.access("goil-windows.zip", os.W_OK):
  os.remove("goil-windows.zip")
print("*** packing goil for Win 32")
os.system("zip goil-windows.zip goil.exe goil-debug.exe")
md5s = md5s + "* " + str(subprocess.check_output(["md5", "goil-windows.zip"]).decode('utf-8'))
if not args.no_upload:
  print("*** uploading goil for Win 32 to the cloud")
  os.system(f"cp goil-windows.zip  {target_dir}")
os.chdir("../..")
#-----------------------------------------------------------------------------*
print(md5s)