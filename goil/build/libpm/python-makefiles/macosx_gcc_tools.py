#! /usr/bin/python3
# -*- coding: UTF-8 -*-

#-----------------------------------------------------------------------------------------

import sys, time, os, json
import makefile, default_build_options
import generic_galgas_makefile

#-----------------------------------------------------------------------------------------

def buildForMacOSintel (dictionary, jsonFilePath, EXECUTABLE, BUILD_DIR_NAME, GOAL, maxParallelJobs, displayCommands) :
  gmf = generic_galgas_makefile.GenericGalgasMakefile ()
  gmf.mJSONfilePath = jsonFilePath
  gmf.mDictionary = dictionary
  gmf.mExecutable = EXECUTABLE
  gmf.mExecutableDirectory = "x86_64/"
  gmf.mDeleteExecutableDirectoryOnClean = True
  gmf.mGoal = GOAL
  gmf.mMaxParallelJobs = maxParallelJobs
  gmf.mDisplayCommands = displayCommands
  gmf.mTargetName = "macosx-x86_64"
  gmf.mBuildDirName = BUILD_DIR_NAME
#---
  gmf.mCompilerTool = ["gcc", "-arch", "x86_64"]
  gmf.mLinkerTool   = ["g++", "-arch", "x86_64"]
  gmf.mStripTool    = ["strip"]
  gmf.mSudoTool     = ["sudo"]

  gmf.mCompilationMessage = "Compiling for MacOS x86_64"
  gmf.mLinkingMessage = "Linking for MacOS x86_64"
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

def buildForMacOSarm64 (dictionary, jsonFilePath, EXECUTABLE, BUILD_DIR_NAME, GOAL, maxParallelJobs, displayCommands) :
  gmf = generic_galgas_makefile.GenericGalgasMakefile ()
  gmf.mJSONfilePath = jsonFilePath
  gmf.mDictionary = dictionary
  gmf.mExecutable = EXECUTABLE
  gmf.mExecutableDirectory = "arm64/"
  gmf.mDeleteExecutableDirectoryOnClean = True
  gmf.mGoal = GOAL
  gmf.mMaxParallelJobs = maxParallelJobs
  gmf.mDisplayCommands = displayCommands
  gmf.mTargetName = "macosx-arm64"
  gmf.mBuildDirName = BUILD_DIR_NAME
#---
  gmf.mCompilerTool = ["gcc", "-arch", "arm64"]
  gmf.mLinkerTool   = ["g++", "-arch", "arm64"]
  gmf.mStripTool    = ["strip"]
  gmf.mSudoTool     = ["sudo"]

  gmf.mCompilationMessage = "Compiling for MacOS ARM64"
  gmf.mLinkingMessage = "Linking for MacOS ARM64"
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

def buildForMacOSFat (dictionary, jsonFilePath, EXECUTABLE, BUILD_DIR_NAME, GOAL, maxParallelJobs, displayCommands) :
#--- Make object
  make = makefile.Make (GOAL, maxParallelJobs == 1) # Display command utility tool path if sequential build
#---
  rule = makefile.Rule (["universal/" + EXECUTABLE], "Build Universal")
  rule.mDependences.append ("x86_64/" + EXECUTABLE)
  rule.mDependences.append ("arm64/" + EXECUTABLE)
  rule.mCommand += ["lipo"]
  rule.mCommand += ["x86_64/" + EXECUTABLE, "arm64/" + EXECUTABLE]
  rule.mCommand += ["-create", "-output", "universal/" + EXECUTABLE]
  rule.deleteTargetDirectoryOnClean ()
  make.addRule (rule) ;
#---
  rule = makefile.Rule (["universal/" + EXECUTABLE + "-debug"], "Build Universal (debug)")
  rule.mDependences.append ("x86_64/" + EXECUTABLE + "-debug")
  rule.mDependences.append ("arm64/" + EXECUTABLE + "-debug")
  rule.mCommand += ["lipo"]
  rule.mCommand += ["x86_64/" + EXECUTABLE + "-debug", "arm64/" + EXECUTABLE + "-debug"]
  rule.mCommand += ["-create", "-output", "universal/" + EXECUTABLE + "-debug"]
  rule.deleteTargetDirectoryOnClean ()
  make.addRule (rule) ;
#---
  rule = makefile.Rule (["universal/" + EXECUTABLE + "-lto"], "Build LTO Universal")
  rule.mDependences.append ("x86_64/" + EXECUTABLE + "-lto")
  rule.mDependences.append ("arm64/" + EXECUTABLE + "-lto")
  rule.mCommand += ["lipo"]
  rule.mCommand += ["x86_64/" + EXECUTABLE + "-lto", "arm64/" + EXECUTABLE + "-lto"]
  rule.mCommand += ["-create", "-output", "universal/" + EXECUTABLE + "-lto"]
  rule.deleteTargetDirectoryOnClean ()
  make.addRule (rule) ;
#--- Build
  make.addGoal ("all", ["universal/" + EXECUTABLE, "universal/" + EXECUTABLE + "-debug"], "Build")
  make.addGoal ("release", ["universal/" + EXECUTABLE], "Build Universal Release")
  make.addGoal ("debug", ["universal/" + EXECUTABLE + "-debug"], "Build Universal Debug")
  make.addGoal ("lto", ["universal/" + EXECUTABLE + "-lto"], "Build LTO Universal")
#--- Run jobs
  make.runGoal (maxParallelJobs, displayCommands)

#-----------------------------------------------------------------------------------------

def buildForMacOS (dictionary, jsonFilePath, EXECUTABLE, BUILD_DIR_NAME, GOAL, maxParallelJobs, displayCommands) :
  buildForMacOSarm64 (dictionary, jsonFilePath, EXECUTABLE, BUILD_DIR_NAME, GOAL, maxParallelJobs, displayCommands)
  buildForMacOSintel (dictionary, jsonFilePath, EXECUTABLE, BUILD_DIR_NAME, GOAL, maxParallelJobs, displayCommands)
  buildForMacOSFat   (dictionary, jsonFilePath, EXECUTABLE, BUILD_DIR_NAME, GOAL, maxParallelJobs, displayCommands)

#-----------------------------------------------------------------------------------------
