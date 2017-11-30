# Trampoline examples for PowerPC target

This is a simple blink example, tested and working for MPC5643L target using
Cosmic Software compiler. An alarm wakes up a task which will turn on/off the
led.

## How to build the example
To compile the example, one can use the bash script "run.sh" in this directory.
The -c option cleans the directory from outputs and generated files.
The -g option generate C files using goil.
The -m option launch the compilation. By default, the compilation is done on a
remote server. In that case, one should set the script variables "SSH_SERVER,
LOCAL_TRAMPOLINE, REMOTE_TRAMPOLINE " according to its expectations.
The -l option sets the compilation as to be done locally.
The -a option does everything (except setting the compilation as local, so one
needs to use ./run.sh -al if its wants to do everything locally).

## Using Cosmic Software tools
The build process uses Cosmic Software's compilation tools (property set in
blink.oil file). The call of these tools are made by the cxvle_auto.py and
clnk_auto.py python scripts located in ../../tools directory. These scripts, by
default, use the commands cxppc, cappc, cpppc, clnk and cvdwarf for the whole
compilation process. If one uses aliases of these commands (for instance, if
you're compiling using Cosmic software CXVLE Evaluation tools through wine),
one can set the environment variables COSMIC_CXPPC, COSMIC_CAPPC, COSMIC_CPPPC,
COSMIC_CLNK and COSMIC_CVDWARF to use these commands instead (so something like
'export COSMIC_CXPPC="wine ~/path/to/cosmic/tools/cxvle.exe"').

## Execute the program through T32 (Lauterbach)

SH $  : Command in shell
T32 & : Command in T32

First export Lauterbach's required environment variables :

SH $ export T32SYS=$HOME/Lauterbach/files        # T32 path to files directory
SH $ export T32TMP=/tmp                          # T32 tmp directory
SH $ export T32ID=T32                            # T32 ID
SH $ export PATH=$PATH:$T32SYS/bin/pc_linux64    # Path to the executables

You can put the exports in the ~/.bashrc files to avoid repeating this
operation for each new shell.

Launch T32 for powerpc :
SH $ t32mppc-qt &

In T32, launch the lauterbach script :
T32 $ do lauterbach.cmm
You can also launch the script using the menu "File->Run Script"

Then run the program :
T32 $ go

