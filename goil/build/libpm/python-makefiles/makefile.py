#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   Releases                                                                                     
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
# 1.0: march 18th, 2015
#        first release
# 2.0: october 2th, 2015
#        added several target definition for rules
# 2.1: october 5th, 2015
#        added checking routine formal argument run-time types
# 2.2: october 24th, 2015
#        changed subprocess.Popen to subprocess.call in runCommand
#        added command tool checking using 'find_executable' function
#        added optional argument to Make class initializer to log command utility tool path
# 2.3: april 16th, 2016
#        added advance percentage
# 3.0: may 30th, 2016
#        compatibility with Python 3:
#             print xyz ---> print (xyz)
#             change isinstance function arguments ---> function argumentIsString
#             subprocess.call: add "universal_newlines=True" argument
#             added test (job.mReturnCode != None) lines 727 and 739
# 3.1: may 26th, 2018
#        Added tolerance in secondary dependency file syntax:
# 3.2: december 16th, 2019
#             added test (job.mReturnCode != None) lines 771 and 779
#             post command displayed is aligned
#
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
# http://www.diveintopython3.net/porting-code-to-python-3-with-2to3.html

import subprocess, sys, os, copy
import urllib, shutil, subprocess
import platform, json, operator
import threading, types, traceback

if sys.version_info >= (2, 6) :
  import multiprocessing

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   find_executable                                                                              
# From:                                                                                          
# https://gist.github.com/4368898                                                                
# Public domain code by anatoly techtonik <techtonik@gmail.com>                                  
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def find_executable(executable, path=None):
    """Try to find 'executable' in the directories listed in 'path' (a
    string listing directories separated by 'os.pathsep'; defaults to
    os.environ['PATH']).  Returns the complete filename or None if not
    found
    """
    if path is None:
        path = os.environ['PATH']
    paths = path.split(os.pathsep)
    extlist = ['']
    if os.name == 'os2':
        (base, ext) = os.path.splitext(executable)
        # executable files on OS/2 can have an arbitrary extension, but
        # .exe is automatically appended if no dot is present in the name
        if not ext:
            executable = executable + ".exe"
    elif sys.platform == 'win32':
        pathext = os.environ['PATHEXT'].lower().split(os.pathsep)
        (base, ext) = os.path.splitext(executable)
        if ext.lower() not in pathext:
            extlist = pathext
    for ext in extlist:
        execname = executable + ext
        if os.path.isfile(execname):
            return execname
        else:
            for p in paths:
                f = os.path.join(p, execname)
                if os.path.isfile(f):
                    return f
    else:
        return None

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   processorCount                                                                               
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def processorCount () :
  if sys.version_info >= (2, 6) :
    coreCount = multiprocessing.cpu_count ()
  else:
    coreCount = 1
  return coreCount

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   argumentIsString                                                                             
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def argumentIsString (argument) :
  if sys.version_info < (3,0):
    return isinstance (argument, types.StringTypes)
  else:
    return type (argument) is str

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   FOR PRINTING IN COLOR                                                                        
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def BLACK () :
  return '\033[90m'

#······················································································································*

def RED () :
  return '\033[91m'

#······················································································································*

def GREEN () :
  return '\033[92m'

#······················································································································*

def YELLOW () :
  return '\033[93m'

#······················································································································*

def BLUE () :
  return '\033[94m'

#······················································································································*

def MAGENTA () :
  return '\033[95m'

#······················································································································*

def CYAN () :
  return '\033[96m'

#······················································································································*

def WHITE () :
  return '\033[97m'

#······················································································································*

def ENDC () :
  return '\033[0m'

#······················································································································*

def BOLD () :
  return '\033[1m'

#······················································································································*

def UNDERLINE () :
  return '\033[4m'

#······················································································································*

def BLINK () :
  return '\033[5m'

#······················································································································*

def BOLD_BLUE () :
  return BOLD () + BLUE ()

#······················································································································*

def BOLD_GREEN () :
  return BOLD () + GREEN ()

#······················································································································*

def BOLD_RED () :
  return BOLD () + RED ()

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   runHiddenCommand                                                                             
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def runHiddenCommand (cmd, logUtilityTool=False) :
  executable = find_executable (cmd [0])
  if executable == None:
    print (BOLD_RED () + "*** Cannot find '" + cmd[0] + "' executable ***" + ENDC ())
    sys.exit (1)
  if logUtilityTool:
    print ("Utility tool is '" + executable + "'")
  result = ""
  childProcess = subprocess.Popen (cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, universal_newlines=True)
  while True:
    line = childProcess.stdout.readline ()
    if line != "":
      result += line
    else:
      childProcess.wait ()
      if childProcess.returncode != 0 :
        sys.exit (childProcess.returncode)
      return result

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   runCommand                                                                                   
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def runCommand (cmd, title, showCommand, logUtilityTool) :
  if title != "":
    print (BOLD_BLUE () + title + ENDC ())
  if (title == "") or showCommand :
    cmdAsString = ""
    for s in cmd:
      if (s == "") or (s.find (" ") >= 0):
        cmdAsString += '"' + s + '" '
      else:
        cmdAsString += s + ' '
    print (cmdAsString)
  executable = find_executable (cmd [0])
  if executable == None:
    print (BOLD_RED () + "*** Cannot find '" + cmd[0] + "' executable ***" + ENDC ())
    sys.exit (1)
  if logUtilityTool:
    print ("Utility tool is '" + executable + "'")
  returncode = subprocess.call (cmd)
  if returncode != 0 :
    sys.exit (returncode)

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   runInThread                                                                                  
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def runInThread (job, displayLock, terminationSemaphore):
  executable = find_executable (job.mCommand [0])
  if executable == None:
    print (BOLD_RED () + "*** Cannot find '" + job.mCommand[0] + "' executable ***" + ENDC ())
    job.mReturnCode = 1
    terminationSemaphore.release ()
  else:
    if job.mLogUtilityTool :
      print ("Utility tool is '" + executable + "'")
    childProcess = subprocess.Popen (job.mCommand, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, universal_newlines=True)
    while True:
      line = childProcess.stdout.readline ()
      if line != "":
        job.mOutputLines.append (line)
        displayLock.acquire ()
        sys.stdout.write (line) # Print without newline
        displayLock.release ()
      else:
        childProcess.wait ()
        job.mReturnCode = childProcess.returncode
        terminationSemaphore.release ()
        break

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   modificationDateForFile                                                                      
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

def modificationDateForFile (dateCacheDictionary, file):
  absFilePath = os.path.abspath (file)
  if absFilePath in dateCacheDictionary :
    return dateCacheDictionary [absFilePath]
  elif not os.path.exists (absFilePath):
    date = sys.float_info.max # Very far in future
    dateCacheDictionary [absFilePath] = date
    return date
  else:
    date = os.path.getmtime (absFilePath)
    dateCacheDictionary [absFilePath] = date
    return date

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   class PostCommand                                                                            
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class PostCommand:
  mCommand = []
  mTitle = ""

  #····················································································································*

  def __init__ (self, title = ""):
    self.mCommand = []
    self.mTitle = title

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   class Job                                                                                    
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class Job:
  mTargets = []
  mCommand = []
  mTitle = ""
  mRequiredFiles = []
  mPostCommands = []
  mReturnCode = None
  mPriority = 0
  mState = 0 # 0: waiting for execution
  mOutputLines = []
  mOpenSourceOnError = False # Do not try to open source file on error
  mLogUtilityTool = False

  #····················································································································*

  def __init__ (self, targets, requiredFiles, command, postCommands, priority, title, openSourceOnError, logUtilityTool):
    self.mTargets = copy.deepcopy (targets)
    self.mCommand = copy.deepcopy (command)
    self.mRequiredFiles = copy.deepcopy (requiredFiles)
    self.mTitle = copy.deepcopy (title)
    self.mPostCommands = copy.deepcopy (postCommands)
    self.mPriority = priority
    self.mOutputLines = []
    self.mOpenSourceOnError = openSourceOnError
    self.mLogUtilityTool = logUtilityTool

  #····················································································································*

  def run (self, displayLock, terminationSemaphore, showCommand, progressString):
    displayLock.acquire ()
    if self.mTitle != "":
      print (progressString + BOLD_BLUE () + self.mTitle + ENDC ())
    if (self.mTitle == "") or showCommand :
      cmdAsString = ""
      for s in self.mCommand:
        if (s == "") or (s.find (" ") >= 0):
          cmdAsString += '"' + s + '" '
        else:
          cmdAsString += s + ' '
      print (progressString + cmdAsString)
    displayLock.release ()
    thread = threading.Thread (target=runInThread, args=(self, displayLock, terminationSemaphore))
    thread.start()

  #····················································································································*

  def runPostCommand (self, displayLock, terminationSemaphore, showCommand):
    postCommand = self.mPostCommands [0]
    self.mCommand = postCommand.mCommand
    displayLock.acquire ()
    print (BOLD_BLUE () + "       " + postCommand.mTitle + ENDC ())
    if showCommand:
      cmdAsString = ""
      for s in self.mCommand:
        if (s == "") or (s.find (" ") >= 0):
          cmdAsString += '"' + s + '" '
        else:
          cmdAsString += s + ' '
      print (cmdAsString)
    displayLock.release ()
    thread = threading.Thread (target=runInThread, args=(self, displayLock, terminationSemaphore))
    thread.start()

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   class Rule                                                                                   
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class Rule:
  mTargets = []
  mDependences = []
  mCommand = []
  mSecondaryMostRecentModificationDate = 0.0 # Far in the past
  mTitle = ""
  mPostCommands = []
  mPriority = 0
  mDeleteTargetOnError = False # No operation on error
  mCleanOperation = 0 # No operation on clean
  mOpenSourceOnError = False # Do not try to open source file on error

  #····················································································································*

  def __init__ (self, targets, title = ""):
    # print ("Rule '" + title + "'")
    if not type (targets) is list:
      print (BOLD_RED () + "*** Rule type instanciation: first argument 'targets' is not a list ***" + ENDC ())
      traceback.print_stack ()
      sys.exit (1)
    else:
      for aTarget in targets:
        # print ("  Target '" + aTarget + "'")
        if not argumentIsString (aTarget):
          print (BOLD_RED () + "*** Rule type instanciation: an element of first argument 'targets' is not a string ***" + ENDC ())
          traceback.print_stack ()
          sys.exit (1)
    if not argumentIsString (title):
      print (BOLD_RED () + "*** Rule type instanciation: second argument 'title' is not a string ***" + ENDC ())
      traceback.print_stack ()
      sys.exit (1)
    self.mTargets = copy.deepcopy (targets)
    self.mDependences = []
    self.mCommand = []
    self.mSecondaryMostRecentModificationDate = 0.0
    self.mPostCommands = []
    self.mPriority = 0
    self.mDeleteTargetOnError = False # No operation on error
    self.mOpenSourceOnError = False # Do not try to open source file on error
    self.mCleanOperation = 0 # No operation on clean
    if title == "":
      self.mTitle = "Building"
      for s in targets:
        self.mTitle += " " + s
    else:
      self.mTitle = copy.deepcopy (title)

  #····················································································································*

  def deleteTargetFileOnClean (self):
    self.mCleanOperation = 1

  #····················································································································*

  def deleteTargetDirectoryOnClean (self):
    self.mCleanOperation = 2

  #····················································································································*

  def enterSecondaryDependanceFile (self, secondaryDependanceFile, make):
    if not argumentIsString (secondaryDependanceFile):
      print (BOLD_RED () + "*** Rule.enterSecondaryDependanceFile: 'secondaryDependanceFile' argument is not a string ***" + ENDC ())
      traceback.print_stack ()
      sys.exit (1)
    if make.mSelectedGoal != "clean":
      filePath = os.path.abspath (secondaryDependanceFile)
      if not os.path.exists (filePath):
        self.mSecondaryMostRecentModificationDate = sys.float_info.max # Very far in future
      else:
        f = open (filePath, "r")
        s = f.read ()
        f.close ()
        s = s.replace ("\\ ", "\x01") # Replace escaped spaces by \0x01
        s = s.replace ("\\\n", "") # Suppress \ at the end of lines
        liste = s.split ("\n\n")
        # print ("DEP " + secondaryDependanceFile)
        for s in liste:
          # print ("S " + s)
          components = s.split (':')
          # print (str (len (components)))
          #target = components [0].replace ("\x01", " ")
          #print ("------- Optional dependency rules for target '" + target + "'")
          #print ("Secondary target '" + target + "'")
          if len (components) > 1 :
            for src in components [1].split ():
              secondarySource = src.replace ("\x01", " ")
              # print ("  SECONDARY SOURCE  '" + secondarySource + "'")
              modifDate = modificationDateForFile (make.mModificationDateDictionary, secondarySource)
              if self.mSecondaryMostRecentModificationDate < modifDate :
                self.mSecondaryMostRecentModificationDate = modifDate
                #print (BOLD_BLUE () + str (modifDate) + ENDC ())

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
#   class Make                                                                                   
#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class Make:
  mRuleList = []
  mJobList = []
  mErrorCount = 0
  mModificationDateDictionary = {}
  mGoals = {}
  mSelectedGoal = ""
  mLinuxTextEditor = ""
  mMacTextEditor = ""
  mSimulateClean = False
  mLogUtilityTool = True
  mShowProgressString = True

  #····················································································································*

  def __init__ (self, goal, logUtilityTool=False):
    if not argumentIsString (goal):
      print (BOLD_RED () + "*** Make instanciation: 'goal' argument is not a string ***" + ENDC ())
      traceback.print_stack ()
      sys.exit (1)
    self.mRuleList = []
    self.mJobList = []
    self.mErrorCount = 0
    self.mModificationDateDictionary = {}
    self.mGoals = {}
    self.mSelectedGoal = goal
    self.mLinuxTextEditor = "gEdit"
    self.mMacTextEditor = "TextEdit"
    self.mLogUtilityTool = logUtilityTool

  #····················································································································*

  def doNotShowProgressString (self) :
     self.mShowProgressString = False

  #····················································································································*

  def addRule (self, rule):
    if not isinstance (rule, Rule):
      print (BOLD_RED () + "*** Make.addRule: 'rule' argument is not an instance of Rule type ***" + ENDC ())
      traceback.print_stack ()
      sys.exit (1)
    self.mRuleList.append (copy.deepcopy (rule))

  #····················································································································*

  def printRules (self):
    print (BOLD_BLUE () + "--- Print " + str (len (self.mRuleList)) + " rule" + ("s" if len (self.mRuleList) > 1 else "") + " ---" + ENDC ())
    for rule in self.mRuleList:
      message = ""
      for s in rule.mTargets:
        message += " \"" + s + "\""
      print (BOLD_GREEN () + "Target:" + message +  ENDC ())
      for dep in rule.mDependences:
        print ("  Dependence: \"" + dep + "\"")
      s = "  Command: "
      for cmd in rule.mCommand:
        s += " \"" + cmd + "\""
      print (s)
      print ("  Title: \"" + rule.mTitle + "\"")
      print ("  Delete target on error: " + ("yes" if rule.mDeleteTargetOnError else "no"))
      cleanOp = "none"
      if rule.mCleanOperation == 1:
        cleanOp = "delete target file(s)"
      elif rule.mCleanOperation == 2:
        dirSet = set ()
        for s in rule.mTargets:
          path = os.path.dirname (s)
          if path != "":
            dirSet.add (path)
        cleanOp = "delete target directory:"
        for s in dirSet:
          cleanOp += " \"" + s + "\""
      print ("  Clean operation: " + cleanOp)
      index = 0
      for postCommand in rule.mPostCommands:
         index = index + 1
         s = "  Post command " + str (index) + ": "
         for cmd in postCommand.mCommand:
           s += " \"" + cmd + "\""
         print (s)
         print ("    Title: \"" + postCommand.mTitle + "\"")

    print (BOLD_BLUE () + "--- End of print rule ---" + ENDC ())

  #····················································································································*

  def writeRuleDependancesInDotFile (self, dotFileName):
    s = "digraph G {\n"
    s += "  node [fontname=courier]\n"
    arrowSet = set ()
    for rule in self.mRuleList:
      for target in rule.mTargets:
        s += '  "' + target + '" [shape=rectangle]\n'
        for dep in rule.mDependences:
          arrowSet.add ('  "' + target + '" -> "' + dep + '"\n')
    for arrow in arrowSet:
      s += arrow
    s += "}\n"
    f = open (dotFileName, "w")
    f.write (s)
    f.close ()

  #····················································································································*

  def checkRules (self):
    if self.mErrorCount == 0:
      ruleList = copy.deepcopy (self.mRuleList)
      index = 0
      looping = True
    #--- loop on rules
      while looping:
        looping = False
        while index < len (ruleList):
          aRule = ruleList [index]
          index = index + 1
        #--- Check dependance files have rule for building, or does exist
          depIdx = 0
          while depIdx < len (aRule.mDependences):
            dep = aRule.mDependences [depIdx]
            depIdx = depIdx + 1
            hasBuildRule = False
            for r in ruleList:
              for target in r.mTargets:
                if dep == target:
                  hasBuildRule = True
                  break
            if not hasBuildRule:
              looping = True
              if not os.path.exists (os.path.abspath (dep)):
                self.mErrorCount = self.mErrorCount + 1
                print (BOLD_RED () + "Check rules error: '" + dep + "' does not exist, and there is no rule for building it." + ENDC ())
              depIdx = depIdx - 1
              aRule.mDependences.pop (depIdx)
        #--- Rule with no dependances
          if len (aRule.mDependences) == 0 :
            looping = True
            index = index - 1
            ruleList.pop (index)
            idx = 0
            while idx < len (ruleList):
              r = ruleList [idx]
              idx = idx + 1
              for target in aRule.mTargets:
                while r.mDependences.count (target) > 0 :
                  r.mDependences.remove (target)
    #--- Error if rules remain
      if len (ruleList) > 0:
        self.mErrorCount = self.mErrorCount + 1
        print (BOLD_RED () + "Check rules error; circulary dependances between:" + ENDC ())
        for aRule in ruleList:
          targetList = ""
          for target in aRule.mTargets:
            targetList += " '" + aRule.mTarget + "'"
          print (BOLD_RED () + "  - " + targetList + ", depends from:" + ENDC ())
          for dep in aRule.mDependences:
            print (BOLD_RED () + "      '" + dep + "'" + ENDC ())

  #····················································································································*

  def existsJobForTarget (self, target):
    for job in self.mJobList:
      for aTarget in job.mTargets:
        if aTarget == target:
          return True
    return False

  #····················································································································*

  def makeJob (self, target): # Return a bool indicating wheither the target should be built
  #--- If there are errors, return immediatly
    if self.mErrorCount != 0:
      return False
  #--- Target already in job list ?
    if self.existsJobForTarget (target):
      return True # yes, return target will be built
  #--- Find a rule for making the target
    absTarget = os.path.abspath (target)
    rule = None
    matchCount = 0
    for r in self.mRuleList:
      for aTarget in r.mTargets:
        if target == aTarget:
          matchCount = matchCount + 1
          rule = r
    if matchCount == 0:
      absTarget = os.path.abspath (target)
      if not os.path.exists (absTarget):
        print (BOLD_RED () + "No rule for making '" + target + "'" + ENDC ())
        self.mErrorCount = self.mErrorCount + 1
      return False # Error or target exists, and no rule for building it
    elif matchCount > 1:
      print (BOLD_RED () + str (matchCount) + " rules for making '" + target + "'" + ENDC ())
      self.mErrorCount = self.mErrorCount + 1
      return False # Error
  #--- Target file does not exist, and 'rule' variable indicates how build it
    appendToJobList = not os.path.exists (absTarget)
  #--- Build primary dependences
    jobDependenceFiles = []
    for dependence in rule.mDependences:
      willBeBuilt = self.makeJob (dependence)
      if willBeBuilt:
        jobDependenceFiles.append (dependence)
        appendToJobList = True
  #--- Check primary file modification dates
    if not appendToJobList:
      targetDateModification = os.path.getmtime (absTarget)
      for source in rule.mDependences:
        sourceDateModification = os.path.getmtime (source)
        if targetDateModification < sourceDateModification:
          appendToJobList = True
          break
  #--- Check for secondary dependancy files
    if not appendToJobList:
      targetDateModification = os.path.getmtime (absTarget)
      if targetDateModification < rule.mSecondaryMostRecentModificationDate:
        appendToJobList = True
  #--- Append to job list
    if appendToJobList:
      self.mJobList.append (Job (
        rule.mTargets,
        jobDependenceFiles,
        rule.mCommand,
        rule.mPostCommands,
        rule.mPriority,
        rule.mTitle,
        rule.mOpenSourceOnError,
        self.mLogUtilityTool
      ))
  #--- Return
    return appendToJobList

  #····················································································································*
  #Job state
  # 0: waiting
  # 1:running
  # 2: waiting for executing post command
  # 3:executing for executing post command
  # 4: completed

  def runJobs (self, maxConcurrentJobs, showCommand):
    if self.mErrorCount == 0:
      if len (self.mJobList) == 0:
        print (BOLD_BLUE () + "Nothing to make." + ENDC ())
      else:
      #--- Sort jobs following their priorities
        self.mJobList = sorted (self.mJobList, key=operator.attrgetter("mPriority"), reverse=True)
      #--- Run
        if maxConcurrentJobs <= 0:
          maxConcurrentJobs = processorCount () - maxConcurrentJobs
        jobCount = 0 ;
        terminationSemaphore = threading.Semaphore (0)
        displayLock = threading.Lock ()
        loop = True
        returnCode = 0
        totalJobCount = float (len (self.mJobList))
        launchedJobCount = 0.0
        while loop:
        #--- Launch jobs in parallel
          for job in self.mJobList:
            if (returnCode == 0) and (jobCount < maxConcurrentJobs):
              if (job.mState == 0) and (len (job.mRequiredFiles) == 0):
                #--- Create target directory if does not exist
                for aTarget in job.mTargets:
                  absTargetDirectory = os.path.dirname (os.path.abspath (aTarget))
                  if not os.path.exists (absTargetDirectory):
                    displayLock.acquire ()
                    runCommand (
                      ["mkdir", "-p", os.path.dirname (aTarget)], "Making \"" + os.path.dirname (aTarget) + "\" directory",
                      showCommand,
                      job.mLogUtilityTool
                    )
                    displayLock.release ()
                #--- Progress string
                launchedJobCount += 1.0
                if self.mShowProgressString:
                  progressString = "[{0:3d}%] ".format (int (100.0 * launchedJobCount / totalJobCount))
                else:
                  progressString = ""
                #--- Run job
                job.run (displayLock, terminationSemaphore, showCommand, progressString)
                jobCount = jobCount + 1
                job.mState = 1 # Means is running
              elif job.mState == 2: # Waiting for executing post command
                job.mReturnCode = None # Means post command not terminated
                job.runPostCommand (displayLock, terminationSemaphore, showCommand)
                jobCount = jobCount + 1
                job.mState = 3 # Means post command is running
        #--- Wait for a job termination
          #print ("wait " + str (jobCount) + " " + str (len (self.mJobList)))
          terminationSemaphore.acquire ()
        #--- Checks for terminated jobs
          index = 0
          while index < len (self.mJobList):
            job = self.mJobList [index]
            index = index + 1
            if (job.mState == 1) and (job.mReturnCode != None) and (job.mReturnCode == 0) : # Terminated without error
              jobCount = jobCount - 1
              for aTarget in job.mTargets:
                if not os.path.exists (os.path.abspath (aTarget)): # Warning: target does not exist
                  displayLock.acquire ()
                  print (MAGENTA () + BOLD () + "Warning: target \"" + aTarget + "\" was not created by rule execution." + ENDC ())
                  displayLock.release ()
              if len (job.mPostCommands) > 0:
                job.mState = 2 # Ready to execute next post command
              else:
                job.mState = 4 # Completed
                index = index - 1 # For removing job from list
            elif (job.mState == 1) and (job.mReturnCode != None) and (job.mReturnCode > 0) : # terminated with error : exit
              jobCount = jobCount - 1
              job.mState = 4 # Means Terminated
              index = index - 1 # For removing job from list
              if job.mOpenSourceOnError:
                for line in job.mOutputLines:
                  components = line.split (':')
                  if (len (components) > 1) and os.path.exists (os.path.abspath (components [0])) :
                    if sys.platform == "darwin":
                      os.system ("open -a \"" + self.mMacTextEditor + "\" \"" + components [0] + "\"")
                    elif sys.platform == "linux2":
                      os.system ("\"" + self.mLinuxTextEditor + "\" \"" + components [0] + "\"")
            elif (job.mState == 3) and (job.mReturnCode != None) and (job.mReturnCode == 0): # post command is terminated without error
              jobCount = jobCount - 1
              job.mPostCommands.pop (0) # Remove completed post command
              if len (job.mPostCommands) > 0:
                job.mState = 2 # Ready to execute next post command
              else:
                job.mState = 4 # Completed
                index = index - 1 # For removing job from list
            elif (job.mState == 3) and (job.mReturnCode != None) and (job.mReturnCode > 0): # post command is terminated with error
              jobCount = jobCount - 1
              job.mState = 4 # Completed
              index = index - 1 # For removing job from list
            elif job.mState == 4: # Completed: delete job
              index = index - 1
              self.mJobList.pop (index) # Remove terminated job
              #displayLock.acquire ()
              #print ("Completed '" + job.mTitle + "'")
              #--- Remove dependences from this job
              idx = 0
              while idx < len (self.mJobList):
                aJob = self.mJobList [idx]
                idx = idx + 1
                for aTarget in job.mTargets:
                  while aJob.mRequiredFiles.count (aTarget) > 0 :
                    aJob.mRequiredFiles.remove (aTarget)
                  #print ("  Removed from '" + aJob.mTitle + "': " + str (len (aJob.mRequiredFiles)))
              #displayLock.release ()
              #--- Signal error ?
              if (job.mReturnCode > 0) and (returnCode == 0):
                self.mErrorCount = self.mErrorCount + 1
                print (BOLD_RED () + "Return code: " + str (job.mReturnCode) + ENDC ())
                if (returnCode == 0) and (jobCount > 0) :
                  print ("Wait for job termination...")
                returnCode = job.mReturnCode
          loop = (len (self.mJobList) > 0) if (returnCode == 0) else (jobCount > 0)

  #····················································································································*

  def searchFileInRelativeDirectories (self, file, directoryList): # returns "" if not found, register error
    matchCount = 0
    result = ""
    for sourceDir in directoryList:
      sourcePath = sourceDir + "/" + file
      if os.path.exists (os.path.abspath (sourcePath)):
        matchCount = matchCount + 1
        prefix = os.path.commonprefix ([os.getcwd (), sourcePath])
        result = sourcePath [len (prefix):]
        if result [0] == '/' :
          result = result [1:]
    if matchCount == 0:
      print (BOLD_RED () + "Cannot find '" + file + "'" + ENDC ())
      self.mErrorCount = self.mErrorCount + 1
    elif matchCount > 1:
      print (BOLD_RED () + str (matchCount) + " source files for making '" + file + "'" + ENDC ())
      self.mErrorCount = self.mErrorCount + 1
      result = ""
    return result

  #····················································································································*

  def searchFileInDirectories (self, file, directoryList): # returns "" if not found, register error
    matchCount = 0
    result = ""
    for sourceDir in directoryList:
      sourcePath = sourceDir + "/" + file
      if os.path.exists (os.path.abspath (sourcePath)):
        matchCount = matchCount + 1
        result = sourcePath
    if matchCount == 0:
      print (BOLD_RED () + "Cannot find '" + file + "'" + ENDC ())
      self.mErrorCount = self.mErrorCount + 1
    elif matchCount > 1:
      print (BOLD_RED () + str (matchCount) + " source files for making '" + file + "'" + ENDC ())
      self.mErrorCount = self.mErrorCount + 1
      result = ""
    return result

  #····················································································································*

  def addGoal (self, goal, targetList, message):
    if not argumentIsString (goal):
      print (BOLD_RED () + "*** Make.addGoal: 'goal' first argument is not a string ***" + ENDC ())
      traceback.print_stack ()
      sys.exit (1)
    if not type (targetList) is list:
      print (BOLD_RED () + "*** Make.addGoal: 'targetList' second argument is not a list ***" + ENDC ())
      traceback.print_stack ()
      sys.exit (1)
    else:
      for aTarget in targetList:
        if not argumentIsString (aTarget):
          print (BOLD_RED () + "*** Make.addGoal: an element of 'targetList' second argument 'targets' is not a string ***" + ENDC ())
          traceback.print_stack ()
          sys.exit (1)
    if not argumentIsString (message):
      print (BOLD_RED () + "*** Make.addGoal: 'message' third argument is not a string ***" + ENDC ())
      traceback.print_stack ()
      sys.exit (1)
    if (goal in self.mGoals) or (goal == "clean") :
      self.enterError ("The '" + goal + "' goal is already defined")
    else:
      self.mGoals [goal] = (targetList, message)
    #print ('%s' % ', '.join(map(str, self.mGoals)))

  #····················································································································*

  def printGoals (self):
    print (BOLD_BLUE () + "--- Print " + str (len (self.mGoals)) + " goal" + ("s" if len (self.mGoals) > 1 else "") + " ---" + ENDC ())
    for goalKey in self.mGoals.keys ():
      print (BOLD_GREEN () + "Goal: \"" + goalKey + "\"" + ENDC ())
      (targetList, message) = self.mGoals [goalKey]
      for target in targetList:
        print ("  Target: \"" + target + "\"")
      print ("  Message: \"" + message + "\"")

    print (BOLD_BLUE () + "--- End of print goals ---" + ENDC ())

  #····················································································································*

  def runGoal (self, maxConcurrentJobs, showCommand):
    if not isinstance (maxConcurrentJobs, int):
      print (BOLD_RED () + "*** Make.runGoal: 'maxConcurrentJobs' first argument is not an integer ***" + ENDC ())
      traceback.print_stack ()
      sys.exit (1)
    if not isinstance (showCommand, bool):
      print (BOLD_RED () + "*** Make.runGoal: 'showCommand' second argument is not a boolean ***" + ENDC ())
      traceback.print_stack ()
      sys.exit (1)
    if self.mSelectedGoal in self.mGoals :
      (targetList, message) = self.mGoals [self.mSelectedGoal]
      for target in targetList:
        self.makeJob (target)
      self.runJobs (maxConcurrentJobs, showCommand)
      if self.mErrorCount > 0:
        for rule in self.mRuleList:
          for aTarget in rule.mTargets:
            if rule.mDeleteTargetOnError and os.path.exists (os.path.abspath (aTarget)):
              runCommand (["rm", aTarget], "Delete \"" + aTarget + "\" on error", showCommand, self.mLogUtilityTool)
    elif self.mSelectedGoal == "clean" :
      filesToRemoveList = []
      directoriesToRemoveSet = set ()
      for rule in self.mRuleList:
        if rule.mCleanOperation == 1: # Delete target
          for aTarget in rule.mTargets:
            filesToRemoveList.append (aTarget)
        elif rule.mCleanOperation == 2: # Delete target directories
          for aTarget in rule.mTargets:
            dirPath = os.path.dirname (aTarget)
            if dirPath == "":
              filesToRemoveList.append (aTarget)
            else:
              directoriesToRemoveSet.add (dirPath)
      for dir in directoriesToRemoveSet:
        if os.path.exists (os.path.abspath (dir)):
          if self.mSimulateClean:
            print (MAGENTA () + BOLD () + "Simulated clean command: " + ENDC () + "rm -fr '" + dir + "'")
          else:
            runCommand (["rm", "-fr", dir], "Removing \"" + dir + "\"", showCommand, self.mLogUtilityTool)
      for file in filesToRemoveList:
        if os.path.exists (os.path.abspath (file)):
          if self.mSimulateClean:
            print (MAGENTA () + BOLD () + "Simulated clean command: " + ENDC () + "rm -f '" + file + "'")
          else:
            runCommand (["rm", "-f", file], "Deleting \"" + file + "\"", showCommand, self.mLogUtilityTool)
    else:
      errorMessage = "The '" + self.mSelectedGoal + "' goal is not defined; defined goals:"
      for key in self.mGoals:
        (targetList, message) = self.mGoals [key]
        errorMessage += "\n  '" + key + "': " + message
      print (BOLD_RED () + errorMessage + ENDC ())
      self.mErrorCount = self.mErrorCount + 1

  #····················································································································*

  def simulateClean (self):
    self.mSimulateClean = True

  #····················································································································*

  def enterError (self, message):
    print (BOLD_RED () + message + ENDC ())
    self.mErrorCount = self.mErrorCount + 1

  #····················································································································*

  def printErrorCountAndExitOnError (self):
    if self.mErrorCount == 1:
      print (BOLD_RED () + "1 error." + ENDC ())
      sys.exit (1)
    elif self.mErrorCount > 1:
      print (BOLD_RED () + str (self.mErrorCount) + " errors." + ENDC ())
      sys.exit (1)

  #····················································································································*

  def printErrorCount (self):
    if self.mErrorCount == 1:
      print (BOLD_RED () + "1 error." + ENDC ())
    elif self.mErrorCount > 1:
      print (BOLD_RED () + str (self.mErrorCount) + " errors." + ENDC ())

  #····················································································································*

  def errorCount (self):
    return self.mErrorCount

#——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
