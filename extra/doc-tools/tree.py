#!/usr/local/bin/python

import sys, os, argparse

#------------------------------------------------------------------------------
def dir2tex(dir, maxlevel, excluded, parent = "", nodeSrc = "",  orig = 0, level = 0):
  if level >= maxlevel:
    return 0
  else:
    lst = sorted(os.listdir(dir))
    dirs = [adir for adir in lst if os.path.isdir(os.path.join(dir, adir)) and not adir.startswith('.') ]
    offset = 0
    numberOfDirs = 0
    previousNodeName = ""
    for idx, adir in enumerate(dirs):
      fullpath = os.path.join(parent, adir)
      if not fullpath in excluded:
        numberOfDirs += 1
        firstNodeName = "c" + str(level) + "l0"
        nodeName = "c" + str(level) + "l" + str(idx)
        print(" " * (4*level) + "\\node[dir" + str(level) + "] (" + nodeName + ") at (" + str(level) + "," + str(idx + orig + offset) + ") {" + adir + "};")
        if level == 0:
          if idx == 0:
            print("\\draw ($(" + nodeName + ".west)+(-.1,0)$) -- (" + nodeName + ");")
          else:
            print("\\draw ($(" + previousNodeName + ".west)+(-.05,0)$) |- (" + nodeName + ");")
        else:
          if idx == 0:
            print(" " * (4*level) + "\draw (" + nodeSrc + ".east) -- (" + nodeName +");") 
          else:
            print(" " * (4*level) + "\draw ($(" + nodeSrc + ".east)!.5!(" + firstNodeName + ".west)$) |- (" + nodeName +");") 
        offset += dir2tex(os.path.join(dir, adir), maxlevel, excluded, fullpath, nodeName, idx + orig + offset, level + 1)
        previousNodeName = nodeName
  
    if len(dirs) == 0:
      return 0
    else:
      return numberOfDirs - 1 + offset
#------------------------------------------------------------------------------

parser = argparse.ArgumentParser()
parser.add_argument('dir', help='root directory of the hierarchy')
parser.add_argument('level', help='depth level', type=int)
parser.add_argument('-e','--exclude', help='exclude directories', nargs='+', default=[])
args = parser.parse_args()

dir = args.dir
maxlevel = args.level
exclude = set(args.exclude)

dir2tex(dir, maxlevel, exclude)
