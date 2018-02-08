#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#----------------------------------------------------------------------------------------------------------------------*

import sys, time, os, json
import makefile, default_build_options
import generic_galgas_makefile
import tool_chain_installation_path
import cross_compiler_download

#----------------------------------------------------------------------------------------------------------------------*

def buildForLinux32OnMacOSX (dictionary, jsonFilePath, EXECUTABLE, GOAL, maxParallelJobs, displayCommands) :
#--- Too chain installation
  GCC_VERSION = "7.2.0"
  BINUTILS_VERSION = "2.28"
  TOOL_CHAIN_NAME = "binutils-" + BINUTILS_VERSION + "-gcc-" + GCC_VERSION + "-for-linux32"
  installDir = tool_chain_installation_path.toolChainInstallationPath ()
  TOOL_CHAIN_INSTALL_PATH = installDir + "/" + TOOL_CHAIN_NAME
  if not os.path.exists (TOOL_CHAIN_INSTALL_PATH):
    cross_compiler_download.downloadToolChain (TOOL_CHAIN_NAME)
#---
  gmf = generic_galgas_makefile.GenericGalgasMakefile ()
  gmf.mJSONfilePath = jsonFilePath
  gmf.mDictionary = dictionary
  gmf.mExecutable = EXECUTABLE
  gmf.mGoal = GOAL
  gmf.mMaxParallelJobs = maxParallelJobs
  gmf.mDisplayCommands = displayCommands
  gmf.mTargetName = "x86linux32"
#---
  UNIX_TOOL_PREFIX = TOOL_CHAIN_INSTALL_PATH + "/bin/i586-pc-linux"
  gmf.mCompilerTool = [UNIX_TOOL_PREFIX + "-gcc"]
  gmf.mLinkerTool = [UNIX_TOOL_PREFIX + "-g++", "-static-libgcc", "-Wl,--gc-sections"]
  gmf.mStripTool = [UNIX_TOOL_PREFIX + "-strip", "--strip-all"]
  gmf.mCompilationMessage = "Compiling for Linux32"
  gmf.mLinkingMessage = "Linking for Linux32"
  gmf.mStripMessage = "Stripping"
  gmf.mCrossCompilation = "Linux-i686"
#--- Options for all compilers
  gmf.mAllCompilerOptions = default_build_options.allCompilerOptions (["-Wconversion"])
#--- Options for release mode
  gmf.mCompilerReleaseOptions = default_build_options.compilerReleaseOptions (["-O2"])
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

#----------------------------------------------------------------------------------------------------------------------*
