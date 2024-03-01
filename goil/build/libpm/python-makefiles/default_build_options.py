#! /usr/bin/python3
# -*- coding: utf-8 -*-

#-----------------------------------------------------------------------------------------
#
#     Options for all compilers
#
#-----------------------------------------------------------------------------------------

def allCompilerOptions (platformOptions):
  result = platformOptions
  result.append ("-Wall")
  result.append ("-Werror")
  result.append ("-Wno-trigraphs")
  result.append ("-Wreturn-type")
  result.append ("-Wformat")
  result.append ("-Wsign-compare")
  result.append ("-Wpointer-arith")
#--- Options added for GALGAS 1.9.0
  result.append ("-ansi")
  result.append ("-W")
  result.append ("-Wshadow")
#  result.append ("-Wcast-qual")
  result.append ("-Wwrite-strings")
  result.append ("-ffunction-sections")
  result.append ("-fdata-sections")
  return result

#-----------------------------------------------------------------------------------------
#
#     Release options
#
#-----------------------------------------------------------------------------------------

def compilerReleaseOptions (platformOptions):
  result = platformOptions
  result.append ("-DDO_NOT_GENERATE_CHECKINGS")
  result.append ("-Wunused-variable")
  return result

#-----------------------------------------------------------------------------------------
#
#     Debug options
#
#-----------------------------------------------------------------------------------------

def compilerDebugOptions (platformOptions):
  result = platformOptions
  result.append ("-g")
  return result

#-----------------------------------------------------------------------------------------
#
#     C compiler options
#
#-----------------------------------------------------------------------------------------

def C_CompilerOptions (platformOptions):
  result = platformOptions
  result.append ("-std=c99")
  return result

#-----------------------------------------------------------------------------------------
#
#     C++ compiler options
#
#-----------------------------------------------------------------------------------------

def Cpp_CompilerOptions (platformOptions):
  result = platformOptions
  result.append ("-std=c++14")
  result.append ("-Woverloaded-virtual")
  return result

#-----------------------------------------------------------------------------------------
#
#     Objective C compiler options
#
#-----------------------------------------------------------------------------------------

def ObjectiveC_CompilerOptions (platformOptions):
  result = platformOptions
  return result

#-----------------------------------------------------------------------------------------
#
#     Objective C++ compiler options
#
#-----------------------------------------------------------------------------------------

def ObjectiveCpp_CompilerOptions (platformOptions):
  result = platformOptions
  return result

#-----------------------------------------------------------------------------------------
