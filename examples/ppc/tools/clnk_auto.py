#! /usr/bin/env python

import argparse
import os
import subprocess

################################# GLOBALS #################################

LINK_COMMAND = os.getenv("COSMIC_CLNK", "clnk")
LINK_FLAGS   = (
                " -m mapping "           # Generate mapping file
                " -p"                    # Print physical @ in mapping file
                " -u15"                  # Print unused symbols
               )

ELF_COMMAND  = os.getenv("COSMIC_CVDWARF", "cvdwarf")
ELF_FLAGS   = (
                " -e _tpl_master_core_startup"   # Start address
               )


########################### ARGUMENTS PARSING ###########################

import sys
print("\n\t\t####### COMMAND : #######\n" + " ".join(sys.argv))

parser = argparse.ArgumentParser(description='gcc to clnk command parser.')
parser.add_argument('-o', metavar="output obj1 obj2...", type=str, nargs="+",
                    required=True, help='output following by object files')
parser.add_argument('-l', metavar="library", type=str, nargs=1,
                    required=False, help='output following by object files')
parser.add_argument('-T', metavar="path/to/lkfscript", nargs=1, type=str,
                    required=True, help='File to include')

args = parser.parse_args()

command = LINK_COMMAND + " " + LINK_FLAGS

# Libraries
if args.l != None :
    for obj in args.l:
        command = command + " -l " + "".join(obj)

# Get output
output = args.o.pop(0)
command = command + " -o " + output

# Get ldscript
if args.T != None :
    command = command + " " + "".join(args.T)

# Includes
if args.o != None :
    for obj in args.o:
        command = command + " " + "".join(obj)



print ("LINKING : \n" + command)

process = subprocess.Popen([command], universal_newlines=True, shell=True)
process.wait()

command = ELF_COMMAND + " " + ELF_FLAGS + " " + output

print ("CREATE ELF : \n" + command)

process = subprocess.Popen([command], universal_newlines=True, shell=True)
process.wait()

