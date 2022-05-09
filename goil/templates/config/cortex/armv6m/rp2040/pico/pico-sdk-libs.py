#!/usr/bin/env python3
#  needs refactoring :(
#
# This script scan libs inside pico SDK and generate lib definitions 
# for Trampoline (including deps)
# Path to the SDK is hard-coded (end of file)
#usage: ./pico-sdk-libs.py > pico_sdk.oil

from os import listdir,walk
from os.path import isdir, join
import re

def printLib(sdk,cfilesDict,hfilesDict,deps):
    """ just print the lib in OIL description:
     * base: base directory
     * lib : lib name (same as directory name)
     * cFilesDict : with 'lib' key, get the list of c files
     * deps: with 'lib' key, get the libraries that are required.
    """
    for (libdir,lib) in deps:
        print('LIBRARY '+lib+'{')
        for hf in hfilesDict[(libdir,lib)]:
            print('\t//HEADERFILE = "'+hf+'";')
        print('\tUSE_PREFIX = TRUE { VARIABLE = "PICO_SDK_PATH";};')
        #convert set to list and sort for easy comprison on different runs.
        listDep = list(deps[(libdir,lib)])
        listDep.sort()
        for dep in listDep:
            print('\tNEEDS = '+dep+';')
        #make path relative to sdk path
        #2 cases: 
        # - automatically added (lib is in lib/include folder)
        # - manually added (no rule).
        # check with a hack :/ => refactoring and add boolean…
        path = join(join(libdir,lib),'include')
        if isdir(path):
            print('\tPATH = "'+path[len(sdk)+1:]+'";') #automatic
        else:
            print('\tPATH = "'+libdir[len(sdk)+1:]+'";') #manual
        #C files
        for cf in cfilesDict[(libdir,lib)]:
            print('\tCFILE = "../'+cf+'";')
        print('};\n')

#done only once
regexInc = re.compile('\s*#include\s+\"([^\"]*).*')

def includes(filename):
    """ search for the '#include "xxx"' pattern,
    and returns a list filenames 'xxx'
    """
    includedFiles = []
    try:
        with open(filename, 'r') as file:
            for line in file.readlines():
                result = regexInc.match(line)
                if result:
                    includedFiles.append(result.group(1))
    except FileNotFoundError:
        pass #this may occur for 'hand added' libs.
    return includedFiles

def computeDependancies(hFiles,cFiles):
    #dict : header file => lib associated.
    # * key is the header file name
    # * val is the (libdir,lib) that provides this header.
    #the goal is to get the lib name from the header included
    provideDict = {}
    liblist = set() #search for duplicates

    for libdir,lib in hFiles:
        if lib in liblist:
            print('lib '+lib+' defined twice!')
        liblist.add(lib)
        for hFile in hFiles[(libdir,lib)]:
            if hFile in provideDict:
                print('Header file already present!!')
            else:
                provideDict[hFile] = (libdir,lib)

    #dict: lib => included files
    # * key is the libdir,lib
    # * val is the list of header files.
    #goal: which headers are included in each libs
    includedFiles = {}
    for (libdir,lib) in hFiles:
        included = []
        hFileDir = join(join(libdir,lib),'include')
        for hFile in hFiles[(libdir,lib)]:
            hFileFullPath = join(hFileDir,hFile)
            included += includes(hFileFullPath)
        cFileDir = join(libdir,lib)
        for cFile in cFiles[(libdir,lib)]:
            cFileFullPath = join(cFileDir,cFile)
            included += includes(cFileFullPath)
        includedFiles[(libdir,lib)] = included

    # dict: lib => dep libs
    # * key is the libdir,lib
    # * val is the set of libs
    deps = {}
    for libdir,lib in includedFiles:
        #print('lib: '+lib)
        depSet = set()
        for headerIncluded in includedFiles[(libdir,lib)]:
            if headerIncluded in provideDict:
                libDep = provideDict[headerIncluded][1]
                if libDep != lib: #no self dependancy
                    depSet.add(provideDict[headerIncluded][1])
            # else:
            #     print('not found: '+headerIncluded+' for lib '+lib)
        deps[libdir,lib] = depSet
    return deps

def evalDir(sdk,libBaseDirList,excludeLibs,extraLibH):
    #dict: key is the base,lib name, content is the list of header files.
    if extraLibH:
        hFiles = extraLibH
    else:
        hFiles = dict()
    cFiles = {}
    for base,lib in hFiles:
        cFiles[(base,lib)] = []
    #find libs from 'libBaseDirList' (dir with 'include/' subdir).
    #for each lib:
    # - get C files
    # - get headers (recursively in include/ subdirs)
    for libBaseDir in libBaseDirList:
        #list dirs in directory
        dirs = [f for f in listdir(libBaseDir) if isdir(join(libBaseDir, f))]
        #libs have an 'include' subdir
        libs = [d for d in dirs if isdir(join(join(libBaseDir,d),'include'))]
        for lib in libs:
            if lib not in excludeLibs:
                libdir = join(libBaseDir,lib)
                incdir = join(libdir,'include')
                # incSubdirs = [d for d in listdir(incdir) if isdir(join(incdir,d))]

                headerFiles = []

                for root, dirs, files in walk(incdir):
                    for fileName in files:
                        if fileName.endswith('.h'):
                            fullHeaderName = join(root,fileName)
                            headerFiles.append(fullHeaderName[len(incdir)+1:]) # add '/'
                hFiles[(libBaseDir,lib)] = headerFiles
                cFiles[(libBaseDir,lib)] = [f for f in listdir(libdir) if f.endswith('.c')] 
                #print('lib => '+lib)
                #print(hFiles[lib])
    deps = computeDependancies(hFiles,cFiles)
    printLib(sdk,cFiles,hFiles,deps)
  

sdk = '/opt/pico-sdk'
libRP2DirList = [sdk+'/src/rp2_common',sdk+'/src/common',sdk+'/src/rp2040']
#libraries not to take care of
excludeLibs = ['pico_stdio_semihosting','pico_stdio_usb']
#add manually libs, so that it can be used for deps
extraLibH = dict()
extraLibH[(sdk+'/build/generated/pico_base','pico_version')] = ['pico/version.h']
evalDir(sdk,libRP2DirList,excludeLibs,extraLibH)
