#! /usr/bin/env python

import argparse
import os
import subprocess


################################# GLOBALS #################################

C_COMMAND = "wine " + os.environ["COSMIC_PATH"] + "/cxvle.exe"
print (C_COMMAND)
C_CONST_FLAGS = (" -l"          # Create .lst files usefull for debug
                 " +debug"
#                 " +modv"
                 " +warn"
                 " +rev"
                 " -p -ku"
                 " -v"
                 " -no"         # FIXME : Optimizer disabled
                 " -ep"         # Enable preprocessor during asm compilation
                )

ASM_PREPROCESS_CMD = "wine " + os.environ["COSMIC_PATH"] + "/cpvle.exe"
ASM_PREPROCESS_FLAGS = (" -i ~/mybin/wine/cosmic/HPPC"
                        " -u"
                        " -m0x3030"
                        " -hmodv.h"
                        " -rb -x -ecq"
                        " -l"
                        " -d'__VERS__=\"V4.3.6\"'"
                       )
ASM_REMOVE_COMMENTS = "cpp -P"      # FIXME : Ugly
ASM_ASSEMBLER_CMD   = "wine " + os.environ["COSMIC_PATH"] + "/cavle.exe"
ASM_ASSEMBLER_FLAGS = (" -l"
                       " -x"
                      )

########################### COMPILING FUNCTIONS ###########################

###################### CALL GCC (DEBUG C FILES)
def gcc_call(args) :
    gcc_cmp = sys.argv
    gcc_cmp[0] = "gcc"
    gcc_cmp.remove("--gcc")
    command = " ".join(gcc_cmp)

    process = subprocess.Popen([command], universal_newlines=True, shell=True)
    process.wait()

###################### C FILES

def c_call(args) :
    command = C_COMMAND + " " + C_CONST_FLAGS

    if args.gcc :
        gcc_call(args)
        return

    # Verbose
    if args.v :
        command = command + " -v"

    # Includes
    if args.I != None :
        for include_elem in args.I:
            command = command + " -i " + "".join(include_elem)

    # Output
    if args.o != None :
        command = command + " -a " + " '-o " + "".join(args.o) + "'"

    command = command + " " + "".join(args.c)

    process = subprocess.Popen([command], universal_newlines=True, shell=True)
    process.wait()


###################### ASM FILES

def asm_call(args):
    command_preproc     = ASM_PREPROCESS_CMD + " " + ASM_PREPROCESS_FLAGS
    command_assemble    = ASM_ASSEMBLER_CMD + " " + ASM_ASSEMBLER_FLAGS
    command_rmv_comments = ASM_REMOVE_COMMENTS

    asm_file = (os.path.splitext("".join(args.o))[0]) + ".s"
    temp_file = (os.path.splitext("".join(args.o))[0]) + ".s.tmp"

    if args.o == None :
        print("Error : Assembly compiling needs an output !")
        return

    if args.I != None :
        for include_elem in args.I:
            command_preproc = command_preproc + " -i " + "".join(include_elem)
            command_assemble = command_assemble + " -i " + "".join(include_elem)

    command_preproc = command_preproc + " -o " + asm_file
    command_preproc = command_preproc + " " + "".join(args.c)

    command_rmv_comments = command_rmv_comments + " " + asm_file + " > " + temp_file

    command_assemble = command_assemble + " -o " + "".join(args.o)
    command_assemble = command_assemble + " " + temp_file

    print("##### PREPROC : \n" + command_preproc)
    print("##### CORRECT : \n" + command_rmv_comments)
    print("##### ASSEMBL : \n" + command_assemble)

    process = subprocess.Popen([command_preproc], universal_newlines=True, shell=True)
    process.wait()

    process = subprocess.Popen([command_rmv_comments], universal_newlines=True, shell=True)
    process.wait()

    process = subprocess.Popen([command_assemble], universal_newlines=True, shell=True)
    process.wait()

########################### ARGUMENTS PARSING ###########################

import sys
print("\n\t\t####### COMMAND : #######\n" + " ".join(sys.argv))

parser = argparse.ArgumentParser(description='gcc to cxvle command parser.')
parser.add_argument('-c', metavar="path/to/cfile", type=str, nargs=1,
                    required=True, help='File to compile')
parser.add_argument('-o', metavar="path/to/output", type=str, nargs=1,
                    required=False, help='Output')
parser.add_argument('-I', metavar="path/to/headers", nargs="+", action="append",
                    required=False, help='File to include')
parser.add_argument('-MD', action="store_true",
                    required=False, help='Not implemented')
parser.add_argument('-MP', action="store_true",
                    required=False, help='Not implemented')
parser.add_argument('-MF', metavar="path/to/dep", type=str, nargs=1,
                    required=False, help='Dependence file : Not implemented')
parser.add_argument('-v', action="store_true",
                    required=False, help='Verbose')
parser.add_argument('--gcc', action="store_true",
                    required=False, help='Use gcc instead of cosmic (debug C files)')

args = parser.parse_args()

# Call compiling functions following the file's extension

file_type = (os.path.splitext("".join(args.c))[1]).lower()

if file_type == ".c" :
    c_call(args)

elif file_type == ".s" :
    asm_call(args)

