#! /usr/bin/python3
# -*- coding: UTF-8 -*-

#-----------------------------------------------------------------------------------------

import sys, time, os, json
import makefile, default_build_options
import generic_galgas_makefile

#-----------------------------------------------------------------------------------------

def buildForLinux64OnMacOSX (dictionary, jsonFilePath, EXECUTABLE, BUILD_DIR_NAME, GOAL, maxParallelJobs, displayCommands) :
  executable = makefile.find_executable ("x86_64-linux-gnu-gcc")
  if executable == None:
    print (makefile.BOLD_RED () + "*** Cannot find 'x86_64-linux-gnu-gcc' executable ***" + makefile.ENDC ())
    print ("The x86_64 Linux cross compiler can be installed under howebrew:")
    print ("  brew tap messense/macos-cross-toolchains")
    print ("  brew install x86_64-unknown-linux-gnu")
    print ("See: https://github.com/messense/homebrew-macos-cross-toolchains")
    sys.exit (1)
#---
  gmf = generic_galgas_makefile.GenericGalgasMakefile ()
  gmf.mJSONfilePath = jsonFilePath
  gmf.mDictionary = dictionary
  gmf.mExecutable = EXECUTABLE
  gmf.mGoal = GOAL
  gmf.mMaxParallelJobs = maxParallelJobs
  gmf.mDisplayCommands = displayCommands
  gmf.mTargetName = "x86_64-linux"
  gmf.mBuildDirName = BUILD_DIR_NAME
#---
  gmf.mCompilerTool = ["x86_64-linux-gnu-gcc"]
  gmf.mLinkerTool = ["x86_64-linux-gnu-g++"] # , "-static-libgcc", "-Wl,--gc-sections"]
  gmf.mStripTool = ["x86_64-linux-gnu-strip", "--strip-all"]
  gmf.mCompilationMessage = "Compiling for x86_64 Linux"
  gmf.mLinkingMessage = "Linking for x86_64 Linux"
  gmf.mStripMessage = "Stripping"
  gmf.mCrossCompilation = "x86_64 Linux"
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

#-----------------------------------------------------------------------------------------
