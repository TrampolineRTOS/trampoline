#! /usr/bin/python3
# -*- coding: UTF-8 -*-

#-----------------------------------------------------------------------------------------

import sys, time, os, json
import platform
import makefile, default_build_options
import generic_galgas_makefile

#-----------------------------------------------------------------------------------------

def buildForMacOSX (dictionary, jsonFilePath, EXECUTABLE, GOAL, maxParallelJobs, showCommands) :
  machine = platform.machine ()
  gmf = generic_galgas_makefile.GenericGalgasMakefile ()
  gmf.mJSONfilePath = jsonFilePath
  gmf.mDictionary = dictionary
  gmf.mExecutable = EXECUTABLE
  gmf.mGoal = GOAL
  gmf.mMaxParallelJobs = maxParallelJobs
  gmf.mDisplayCommands = showCommands
  gmf.mTargetName = "macosx"
#---
  gmf.mCompilerTool = ["gcc", "-arch", machine]
  gmf.mLinkerTool   = ["g++", "-arch", machine]
  gmf.mStripTool    = ["strip"]
  gmf.mSudoTool     = ["sudo"]
  gmf.mCompilationMessage = "Native Compiling for OS X"
  gmf.mLinkingMessage = "Native Linking for OS X"
  gmf.mInstallationgMessage = "Installing"
  gmf.mStripMessage = "Stripping"
#--- Options for all compilers
  gmf.mAllCompilerOptions = default_build_options.allCompilerOptions (["-Wconversion"])
#--- Options for release mode
  gmf.mCompilerReleaseOptions = default_build_options.compilerReleaseOptions (["-O1"])
#--- Options for debug mode
  gmf.mCompilerDebugOptions = default_build_options.compilerDebugOptions ([])
#--- Options for C compiling (.c extension)
  gmf.m_C_CompilerOptions = default_build_options.C_CompilerOptions ([])
#--- Options for C++ compiling (.cpp extension)
  gmf.m_Cpp_CompilerOptions = default_build_options.Cpp_CompilerOptions (["-Weffc++", "-Wsign-promo"])
#--- Options for Objective-C compiling (.m extension)
  gmf.m_ObjectiveC_CompilerOptions = default_build_options.ObjectiveC_CompilerOptions ([])
#--- Options for Objective-C++ compiling (.mm extension)
  gmf.m_ObjectiveCpp_CompilerOptions = default_build_options.ObjectiveCpp_CompilerOptions ([])
#--- Run makefile
  gmf.run ()

#-----------------------------------------------------------------------------------------
