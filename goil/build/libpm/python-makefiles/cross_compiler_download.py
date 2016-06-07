#!/usr/bin/python
# -*- coding: utf-8 -*-

#----------------------------------------------------------------------------------------------------------------------*
 
from __future__ import print_function
import os, sys, subprocess
import tool_chain_installation_path
if sys.version_info < (3, 0):
  import urllib
else:
  import urllib.request

#----------------------------------------------------------------------------------------------------------------------*
#   runCommand                                                                                                         *
#----------------------------------------------------------------------------------------------------------------------*

def runCommand (cmd) :
  str = "+"
  for s in cmd:
    str += " " + s
  print (str)
  childProcess = subprocess.Popen (cmd)
  childProcess.wait ()
  if childProcess.returncode != 0 :
    sys.exit (childProcess.returncode)

#----------------------------------------------------------------------------------------------------------------------*
#   ARCHIVE DOWNLOAD                                                                                                   *
#----------------------------------------------------------------------------------------------------------------------*

gPerCentLoaded = 0

def downloadReportHook (a,b,fileSize): 
  if fileSize < (1 << 10):
    sizeString = str (fileSize)
  else:
    if fileSize < (1 << 20):
      sizeString = str (fileSize >> 10) + "Ki"
    else:
      sizeString = str (fileSize >> 20) + "Mi"
  perCentLoaded = int (min(100.0, float(a * b) / fileSize * 100.0))
  global gPerCentLoaded
  if gPerCentLoaded != perCentLoaded:
    gPerCentLoaded = perCentLoaded
    print (" {0}% of {1}B".format (perCentLoaded, sizeString), end="\r")
    sys.stdout.flush ()

#----------------------------------------------------------------------------------------------------------------------*

def downloadArchive (archiveURL, archivePath):
  print ("Downloading " + os.path.basename (archivePath + ".downloading"))
  global gPerCentLoaded
  gPerCentLoaded = -1
  if sys.version_info < (3, 0):
    urllib.urlretrieve (archiveURL,  archivePath + ".downloading", downloadReportHook)
  else:
    urllib.request.urlretrieve (archiveURL,  archivePath + ".downloading", downloadReportHook)
  print ("")
  fileSize = os.path.getsize (archivePath + ".downloading")
  ok = fileSize > 1000000
  if ok:
    runCommand (["mv", archivePath + ".downloading", archivePath])
  else:
    print ("Error: cannot download file")
    sys.exit (1)

#----------------------------------------------------------------------------------------------------------------------*
#  MAIN                                                                                                                *
#----------------------------------------------------------------------------------------------------------------------*

def downloadToolChain (TOOL_CHAIN):
  #--------------------------------------------------------------------------- Get URL
  url = "http://crossgcc.rts-software.org/downloads/galgas-tools-for-cross-compilation/" + TOOL_CHAIN + ".tar.bz2"
  print ("*** TOOL CHAIN IS NOT INSTALLED")
  print ("Tool chain URL: " + url)
  #--------------------------------------------------------------------------- Get installation directory
  installDir = tool_chain_installation_path.toolChainInstallationPath ()
  print ("Intallation directory: " + installDir)
  LOCAL_ARCHIVE = installDir + "/" + TOOL_CHAIN + ".tar.bz2"
  runCommand (["mkdir", "-p", installDir])
  #--------------------------------------------------------------------------- Save current dir and change it
  currentDir = os.getcwd ()
  os.chdir (installDir)
  print ("+ cd " + installDir)
  #--------------------------------------------------------------------------- Download
  runCommand (["rm", "-f", TOOL_CHAIN + ".tar.bz2.downloading"])
  runCommand (["rm", "-f", TOOL_CHAIN + ".tar.bz2"])
  runCommand (["rm", "-f", TOOL_CHAIN + ".tar"])
  downloadArchive (url, LOCAL_ARCHIVE)
  #--------------------------------------------------------------------------- Unzip
  runCommand (["bunzip2", TOOL_CHAIN + ".tar.bz2"])
  runCommand (["tar", "xf", TOOL_CHAIN + ".tar"])
  runCommand (["rm", TOOL_CHAIN + ".tar"])
  #--------------------------------------------------------------------------- Restore current dir
  os.chdir (currentDir)
  print ("+ cd " + currentDir)
  #--------------------------------------------------------------------------- Done
  print ("*** DONE.")

#----------------------------------------------------------------------------------------------------------------------*
