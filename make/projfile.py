#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#----------------------------------------------------------------------------*

#import subprocess, sys, os, copy
#import urllib, shutil, subprocess
#import platform, json, operator
#import threading
#
#if sys.version_info >= (2, 6) :
#  import multiprocessing

#----------------------------------------------------------------------------*
#   class SourceFile                                                         *
#----------------------------------------------------------------------------*

class ProjectFile:
  mPrefix = ""
  mSrcFile = ""

  #--------------------------------------------------------------------------*

  def __init__ (self, srcFile, prefix = ""):
    self.mSrcFile = srcFile
    self.mPrefix = prefix

  def src (self):
    return self.mPrefix + self.mSrcFile

  def obj (self, targetDir):
    return targetDir + "/" + self.mSrcFile + ".o"

  def dep (self, targetDir):
    return targetDir + "/" + self.mSrcFile + ".o.dep"

#----------------------------------------------------------------------------*
