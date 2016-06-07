#! /bin/bash

# By default, this script compiles on a remote server using below SSH_SERVER,
# LOCAL_TRAMPOLINE, REMOTE_TRAMPOLINE and REMOTE_EXAMPLE_DIR variables.
# Please set all below variables accordingly


# Reset shell script invocation counter
OPTIND=1

# Remote server address
SSH_SERVER="groscalin"
# Path to the local trampoline directory (Ex: $HOME/trampoline)
LOCAL_TRAMPOLINE="$HOME/trampoline/trampoline"
# Path to the remote trampoline directory (Ex: /home/bob/trampoline)
REMOTE_TRAMPOLINE="trampoline"
# Path to the remote example directory (Ex: /home/bob/trampoline/examples/arch/blink)
REMOTE_EXAMPLE_DIR="$REMOTE_TRAMPOLINE/examples/ppc/multicore/blink_1c"
# Rsync excluded directories (when copying trampoline)
RSYNC_EXCLUDE="--exclude .git
               --exclude documentation
               --exclude tests
               --exclude goil"

# Goil arch target (Ex: ppc/mpc5643l)
GOIL_TARGET="ppc/mpc5643l"
# Goil source (Ex: ./blink.oil)
GOIL_SOURCE="./blink.oil"
# Goil output (deleted on clean only)
GOIL_OUTPUT="./make.py ./build.py ./blink"
# Build ouptut (deleted on clean, copied from server after compilation)
BUILD_OUTPUT="./build ./blink_exe ./blink_exe.elf ./mapping"

print_help() {
    echo "Usage : $0 [ARG]"
    echo "Possible Arguments :"
    echo "  -h  : print_help"
    echo "  -c  : Clean"
    echo "  -g  : Generate files using goil"
    echo "  -m  : Make"
    echo "  -l  : Compile localy"
    echo "  -a  : Clean, Generate, Compile"
}

clean() {
    echo "Cleaning"
    rm -rf $GOIL_OUTPUT $BUILD_OUTPUT
}

goil_generate() {
    echo "Generating files"
    goil --target=$GOIL_TARGET $GOIL_SOURCE
}

local_compile() {
    echo "Compiling locally"
    ./build.py
}

remote_compile() {
    echo "Syncing sources"
    rsync -avz --delete $LOCAL_TRAMPOLINE/ $RSYNC_EXCLUDE $SSH_SERVER:$REMOTE_TRAMPOLINE
    echo "Cross-Compiling on remote server"
    ssh $SSH_SERVER "cd $REMOTE_EXAMPLE_DIR;
                     ./build.py;"
    echo "Retrieve output files"
    scp -r $SSH_SERVER:$REMOTE_EXAMPLE_DIR/{${BUILD_OUTPUT// /,}} .
}

generate=0
compile=0
clean=0
compile_local=0

while getopts "cmaglh" OPT; do
  case "$OPT" in
    c) clean=1;;
    g) generate=1;;
    m) compile=1;;
    a) compile=1;
       generate=1;
       clean=1;;
    l) compile_local=1;;
    h) print_help;
       exit;;
    *) # getopts produces error
       echo "Getopts error";
       print_help;
       exit;;
  esac
done

if [ $clean -eq 1 ]; then
    clean
fi

if [ $generate -eq 1 ]; then
    goil_generate
fi

if [ $compile -eq 1 ] && [ $compile_local -eq 1 ] ; then
    local_compile
fi

if [ $compile -eq 1 ] && [ $compile_local -eq 0 ] ; then
    remote_compile
fi

if [ $clean -eq 0 ] && [ $compile -eq 0 ] && [ $generate -eq 0 ] ; then
    print_help
fi

