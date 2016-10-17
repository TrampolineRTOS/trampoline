#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#----------------------------------------------------------------------------------------------------------------------*

import sys, time, os, json
import makefile, default_build_options
import generic_galgas_makefile
import tool_chain_installation_path 
import cross_compiler_download

#----------------------------------------------------------------------------------------------------------------------*

def buildForWin32OnMacOSX (dictionary, EXECUTABLE, GOAL, maxParallelJobs, displayCommands) :
#--- Too chain installation
  GCC_VERSION = "6.2.0"
  BINUTILS_VERSION = "2.27"
  TOOL_CHAIN_NAME = "binutils-" + BINUTILS_VERSION + "-gcc-" + GCC_VERSION + "-for-mingw32"
  installDir = tool_chain_installation_path.toolChainInstallationPath ()
  TOOL_CHAIN_INSTALL_PATH = installDir + "/" + TOOL_CHAIN_NAME
  if not os.path.exists (TOOL_CHAIN_INSTALL_PATH):
    cross_compiler_download.downloadToolChain (TOOL_CHAIN_NAME)
#---
  gmf = generic_galgas_makefile.GenericGalgasMakefile ()
  gmf.mDictionary = dictionary
  gmf.mExecutable = EXECUTABLE
  gmf.mGoal = GOAL
  gmf.mMaxParallelJobs = maxParallelJobs
  gmf.mDisplayCommands = displayCommands
  gmf.mTargetName = "win32"
  gmf.mLinkerOptions = ["-lws2_32", "-lComdlg32"]
  gmf.mExecutableSuffix = ".exe"
#---
  gmf.mCompilerTool = [TOOL_CHAIN_INSTALL_PATH + "/bin/i586-mingw32-gcc", "-m32", "-D_WIN32_WINNT=0x501"]
  gmf.mLinkerTool = [TOOL_CHAIN_INSTALL_PATH + "/bin/i586-mingw32-g++", "-m32", "--enable-auto-import", "-Wl,--gc-sections"]
  gmf.mStripTool = [TOOL_CHAIN_INSTALL_PATH + "/bin/i586-mingw32-strip", "--strip-all"]
  gmf.mCompilationMessage = "Compiling for Win32"
  gmf.mLinkingMessage = "Linking for Win32"
  gmf.mStripMessage = "Stripping"
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
#--- Library to use for gmp
  gmf.mCrossCompilation = "win32"
#--- Run makefile
  gmf.run ()

#----------------------------------------------------------------------------------------------------------------------*
