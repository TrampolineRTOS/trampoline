#! /bin/bash

# This script must be launched by "run.sh" scripts located in the examples
# directory.

# Reset shell script invocation counter
OPTIND=1
TIMEOUT_EXIT_FAILURE=124

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
    $GOIL --target=$GOIL_TARGET $GOIL_SOURCE
}

local_compile() {
    echo "Compiling locally"
    ./build.py
}

remote_compile() {
    echo "Syncing sources"
    rsync -avz --delete $LOCAL_TRAMPOLINE/ $RSYNC_EXCLUDE $SSH_SERVER:$REMOTE_TRAMPOLINE
    echo "Compiling on remote server"
    retval=$TIMEOUT_EXIT_FAILURE
    while [ $retval -eq $TIMEOUT_EXIT_FAILURE ]; do
      ssh $SSH_SERVER "cd $REMOTE_EXAMPLE_DIR;
                       $BUILD_TIMEOUT ./build.py;"
      retval=$?
    done

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

