#! /usr/bin/python3
# -*- coding: UTF-8 -*-

#-----------------------------------------------------------------------------------------

import sys, time, os
import makefile, default_build_options

#-----------------------------------------------------------------------------------------
#   displayDurationFromStartTime
#-----------------------------------------------------------------------------------------

def displayDurationFromStartTime (startTime) :
  totalDurationInSeconds = int (time.time () - startTime)
  durationInSecondes = totalDurationInSeconds % 60
  durationInMinutes = (totalDurationInSeconds // 60) % 60
  durationInHours = totalDurationInSeconds // 3600
  s = ""
  if durationInHours > 0:
    s += str (durationInHours) + "h"
  if durationInMinutes > 0:
    s += str (durationInMinutes) + "min"
  s += str (durationInSecondes) + "s"
  print ("Done at +" + s)

#-----------------------------------------------------------------------------------------

class GenericGalgasMakefile :
  mJSONfilePath = ""
  mDictionary = {}
  mExecutable = ""
  mGoal = ""
  mMaxParallelJobs = 0
  mDisplayCommands = False
  mCompilerTool = []
  mLinkerTool = []
  mStripTool = []
  mSudoTool = ""
  mCompilationMessage = ""
  mLinkingMessage = ""
  mInstallationgMessage = ""
  mStripMessage = ""
  mAllCompilerOptions = []
  mCompilerReleaseOptions = []
  mCompilerDebugOptions = []
  m_C_CompilerOptions = []
  m_Cpp_CompilerOptions = []
  m_ObjectiveC_CompilerOptions = []
  m_ObjectiveCpp_CompilerOptions = []
  mTargetName = ""
  mBuildDirName = ""
  mLinkerOptions = []
  mExecutableSuffix = ""
  mCrossCompilation = ""

  def run (self) :
    startTime = time.time ()
  #--- Source file list
    SOURCES = self.mDictionary ["SOURCES"]
  #--- Linker options
    self.mLinkerOptions += self.mDictionary ["USER_LINK_OPTIONS"]
  #--- LIBPM
    LIBPM_DIRECTORY_PATH = self.mDictionary ["LIBPM_DIRECTORY_PATH"]
  #--------------------------------------------------------------------------- System
    if self.mCrossCompilation == "":
      (SYSTEM_NAME, MODE_NAME, SYSTEM_RELEASE, SYSTEM_VERSION, MACHINE) = os.uname ()
      if SYSTEM_NAME == "Darwin":
        MACHINE = "Intel"
      SYSTEM_MACHINE = SYSTEM_NAME + "-" + MACHINE
    else:
      SYSTEM_MACHINE = self.mCrossCompilation
  #--- GMP
    GMP_DIRECTORY_PATH = LIBPM_DIRECTORY_PATH + "/gmp"
  #--- Source directory list
    SOURCES_DIR = self.mDictionary ["SOURCES_DIR"]
  #--------------------------------------------------------------------------- Include dirs
    SOURCES_DIR.append (LIBPM_DIRECTORY_PATH + "/bdd")
    SOURCES_DIR.append (LIBPM_DIRECTORY_PATH + "/command_line_interface")
    SOURCES_DIR.append (LIBPM_DIRECTORY_PATH + "/files")
    SOURCES_DIR.append (LIBPM_DIRECTORY_PATH + "/galgas")
    SOURCES_DIR.append (LIBPM_DIRECTORY_PATH + "/galgas2")
    SOURCES_DIR.append (LIBPM_DIRECTORY_PATH + "/gmp")
    SOURCES_DIR.append (LIBPM_DIRECTORY_PATH + "/streams")
    SOURCES_DIR.append (LIBPM_DIRECTORY_PATH + "/time")
    SOURCES_DIR.append (LIBPM_DIRECTORY_PATH + "/strings")
    SOURCES_DIR.append (LIBPM_DIRECTORY_PATH + "/utilities")
    includeDirs = ["-I" + GMP_DIRECTORY_PATH]
    for d in SOURCES_DIR:
      includeDirs.append ("-I" + d)
  #--- Make object
    make = makefile.Make (self.mGoal, self.mMaxParallelJobs == 1) # Display command utility tool path if sequential build
  #--------------------------------------------------------------------------- Add Compile rule for sources (release)
  #--- Object file directory
    objectDirectory = "../" + self.mBuildDirName + "/cli-objects/makefile-" + self.mTargetName + "-objects"
  #---
    objectFileList = []
    for source in SOURCES:
      objectFile = objectDirectory + "/" + source + ".o"
      objectFileList.append (objectFile)
      sourcePath = make.searchFileInDirectories (source, SOURCES_DIR)
      if sourcePath != "" :
        extension = os.path.splitext (source) [1]
        rule = makefile.Rule ([objectFile], self.mCompilationMessage + ": " + source)
        rule.deleteTargetDirectoryOnClean ()
        rule.mDependences.append (sourcePath)
        rule.enterSecondaryDependanceFile (objectFile + ".dep", make)
        rule.mCommand += self.mCompilerTool
        rule.mCommand += self.mCompilerReleaseOptions
        rule.mCommand += self.mAllCompilerOptions
        if extension == ".c":
          rule.mCommand += self.m_C_CompilerOptions
        elif extension == ".cpp":
          rule.mCommand += self.m_Cpp_CompilerOptions
        rule.mCommand += ["-c", sourcePath]
        rule.mCommand += ["-o", objectFile]
        rule.mCommand += includeDirs
        rule.mCommand += ["-MD", "-MP", "-MF", objectFile + ".dep"]
        make.addRule (rule) ;
  #--------------------------------------------------------------------------- Add EXECUTABLE link rule
    EXECUTABLE = self.mExecutable + self.mExecutableSuffix
    rule = makefile.Rule ([EXECUTABLE], self.mLinkingMessage + ": " + EXECUTABLE)
    rule.mOnErrorDeleteTarget = True
    rule.deleteTargetFileOnClean ()
    rule.mDependences += objectFileList
    rule.mDependences.append (self.mJSONfilePath)
    rule.mCommand += self.mLinkerTool
    rule.mCommand += objectFileList
    rule.mCommand += ["-o", EXECUTABLE]
    rule.mCommand += self.mLinkerOptions
    postCommand = makefile.PostCommand (self.mStripMessage + " " + EXECUTABLE)
    postCommand.mCommand += self.mStripTool
    postCommand.mCommand.append (EXECUTABLE)
    rule.mPostCommands.append (postCommand)
    rule.mPriority = 1
    make.addRule (rule) ;
  #--------------------------------------------------------------------------- Add Compile rule for sources (debug)
  #--- Object file directory
    debugObjectDirectory = "../" + self.mBuildDirName + "/cli-objects/makefile-" + self.mTargetName + "-debug-objects"
  #---
    debugObjectFileList = []
    for source in SOURCES:
      objectFile = debugObjectDirectory + "/" + source + ".o"
      debugObjectFileList.append (objectFile)
      sourcePath = make.searchFileInDirectories (source, SOURCES_DIR)
      if sourcePath != "" :
        extension = os.path.splitext (source) [1]
        rule = makefile.Rule ([objectFile], self.mCompilationMessage + " (debug): " + source)
        rule.deleteTargetDirectoryOnClean ()
        rule.mDependences.append (sourcePath)
        rule.enterSecondaryDependanceFile (objectFile + ".dep", make)
        rule.mCommand += self.mCompilerTool
        rule.mCommand += self.mCompilerDebugOptions
        rule.mCommand += self.mAllCompilerOptions
        if extension == ".c":
          rule.mCommand += self.m_C_CompilerOptions
        elif extension == ".cpp":
          rule.mCommand += self.m_Cpp_CompilerOptions
        rule.mCommand += ["-c", sourcePath]
        rule.mCommand += ["-o", objectFile]
        rule.mCommand += includeDirs
        rule.mCommand += ["-MD", "-MP", "-MF", objectFile + ".dep"]
        make.addRule (rule) ;
  #--------------------------------------------------------------------------- Add EXECUTABLE_DEBUG link rule
    EXECUTABLE_DEBUG = self.mExecutable + "-debug" + self.mExecutableSuffix
    rule = makefile.Rule ([EXECUTABLE_DEBUG], self.mLinkingMessage + " (debug): " + EXECUTABLE_DEBUG)
    rule.mOnErrorDeleteTarget = True
    rule.deleteTargetFileOnClean ()
    rule.mDependences += debugObjectFileList
    rule.mDependences.append (self.mJSONfilePath)
    rule.mCommand += self.mLinkerTool
    rule.mCommand += debugObjectFileList
    rule.mCommand += ["-o", EXECUTABLE_DEBUG]
    rule.mCommand += self.mLinkerOptions
    make.addRule (rule) ;
  #--------------------------------------------------------------------------- Add Compile rule for sources (lto)
  #--- Object file directory
    objectLTODirectory = "../" + self.mBuildDirName + "/cli-objects/makefile-" + self.mTargetName + "-objects-lto"
  #---
    ltoObjectFileList = []
    for source in SOURCES:
      objectFile = objectLTODirectory + "/" + source + ".o"
      ltoObjectFileList.append (objectFile)
      sourcePath = make.searchFileInDirectories (source, SOURCES_DIR)
      if sourcePath != "" :
        extension = os.path.splitext (source) [1]
        rule = makefile.Rule ([objectFile], self.mCompilationMessage + " (lto): " + source)
        rule.deleteTargetDirectoryOnClean ()
        rule.mDependences.append (sourcePath)
        rule.enterSecondaryDependanceFile (objectFile + ".dep", make)
        rule.mCommand += self.mCompilerTool
        rule.mCommand += self.mCompilerReleaseOptions
        rule.mCommand += self.mAllCompilerOptions
        rule.mCommand += ["-flto"]
        if extension == ".c":
          rule.mCommand += self.m_C_CompilerOptions
        elif extension == ".cpp":
          rule.mCommand += self.m_Cpp_CompilerOptions
        rule.mCommand += ["-c", sourcePath]
        rule.mCommand += ["-o", objectFile]
        rule.mCommand += includeDirs
        rule.mCommand += ["-MD", "-MP", "-MF", objectFile + ".dep"]
        make.addRule (rule) ;
  #--------------------------------------------------------------------------- Add EXECUTABLE link rule
    EXECUTABLE_LTO = self.mExecutable + "-lto" + self.mExecutableSuffix
    rule = makefile.Rule ([EXECUTABLE_LTO], self.mLinkingMessage + ": " + EXECUTABLE_LTO)
    rule.mOnErrorDeleteTarget = True
    rule.deleteTargetFileOnClean ()
    rule.mDependences += ltoObjectFileList
    rule.mDependences.append (self.mJSONfilePath)
    rule.mCommand += self.mLinkerTool
    rule.mCommand += ltoObjectFileList
    rule.mCommand += ["-o", EXECUTABLE_LTO]
    rule.mCommand += self.mLinkerOptions
    rule.mCommand += ["-flto"]
    postCommand = makefile.PostCommand (self.mStripMessage + " " + EXECUTABLE_LTO)
    postCommand.mCommand += self.mStripTool
    postCommand.mCommand.append (EXECUTABLE_LTO)
    rule.mPostCommands.append (postCommand)
    rule.mPriority = 1
    make.addRule (rule) ;
  #--------------------------------------------------------------------------- Add install EXECUTABLE file rule
    if len (self.mSudoTool) > 0:
      INSTALL_EXECUTABLE = "/usr/local/bin/" + EXECUTABLE
      rule = makefile.Rule ([INSTALL_EXECUTABLE], self.mInstallationgMessage + ": " + INSTALL_EXECUTABLE)
      rule.mDependences.append (EXECUTABLE)
      rule.mCommand += self.mSudoTool
      rule.mCommand += ["cp", EXECUTABLE, INSTALL_EXECUTABLE]
      make.addRule (rule) ;
  #--------------------------------------------------------------------------- Add install EXECUTABLE-lto file rule
    if len (self.mSudoTool) > 0:
      INSTALL_EXECUTABLE_LTO = "/usr/local/bin/" + EXECUTABLE_LTO
      rule = makefile.Rule ([INSTALL_EXECUTABLE_LTO], self.mInstallationgMessage + ": " + INSTALL_EXECUTABLE_LTO)
      rule.mDependences.append (EXECUTABLE)
      rule.mCommand += self.mSudoTool
      rule.mCommand += ["cp", EXECUTABLE_LTO, INSTALL_EXECUTABLE_LTO]
      make.addRule (rule) ;
  #--------------------------------------------------------------------------- Add install EXECUTABLE-debug file rule
    if len (self.mSudoTool) > 0:
      INSTALL_EXECUTABLE_DEBUG = "/usr/local/bin/" + EXECUTABLE_DEBUG
      rule = makefile.Rule ([INSTALL_EXECUTABLE_DEBUG], self.mInstallationgMessage + " (debug): " + INSTALL_EXECUTABLE_DEBUG)
      rule.mDependences.append (INSTALL_EXECUTABLE_DEBUG)
      rule.mCommand += self.mSudoTool
      rule.mCommand += ["cp", EXECUTABLE_DEBUG, INSTALL_EXECUTABLE_DEBUG]
      make.addRule (rule) ;
  #--------------------------------------------------------------------------- Compute jobs
    # make.printRules ()
    make.addGoal ("all", [EXECUTABLE, EXECUTABLE_DEBUG], "Build " + EXECUTABLE + " and " + EXECUTABLE_DEBUG)
    make.addGoal ("debug", [EXECUTABLE_DEBUG], "Build " + EXECUTABLE_DEBUG)
    make.addGoal ("release", [EXECUTABLE], "Build " + EXECUTABLE)
    make.addGoal ("lto", [EXECUTABLE_LTO], "Build " + EXECUTABLE_LTO)
    if len (self.mSudoTool) > 0:
      make.addGoal ("install-lto", [INSTALL_EXECUTABLE_LTO], "Build and install " + INSTALL_EXECUTABLE_LTO)
      make.addGoal ("install-release", [INSTALL_EXECUTABLE], "Build and install " + INSTALL_EXECUTABLE)
      make.addGoal ("install-debug", [INSTALL_EXECUTABLE_DEBUG], "Build and install " + INSTALL_EXECUTABLE_DEBUG)
  #--------------------------------------------------------------------------- Run jobs
    # make.printGoals ()
    make.runGoal (self.mMaxParallelJobs, self.mDisplayCommands)
  #--------------------------------------------------------------------------- Ok ?
    make.printErrorCountAndExitOnError ()
    displayDurationFromStartTime (startTime)

#-----------------------------------------------------------------------------------------
