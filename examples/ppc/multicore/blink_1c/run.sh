#! /bin/sh

# Check if COSMIC_PATH environment variable is set
# It must be equal to the path to the cosmic executables
# Ex : if cxvle is located in $HOME/mybin/wine/cosmic/cxvle.exe,
#      set the variable with `export COSMIC_PATH=$HOME/mybin/wine/cosmic`
: "${COSMIC_PATH?COSMIC_PATH env variable must be set}"


OPTIND=1 # Reset shell script invocation counter

print_help() {
    echo "Usage : $0 [ARG]"
    echo "Possible Arguments :"
    echo "  -h  print_help"
    echo "  -c  : Clean"
    echo "  -g  : Generate files using goil"
    echo "  -m  : Make"
    echo "  -a  : Do everything"
}

generate=0
build=0
clean=0

while getopts "cmagh" OPT; do
  case "$OPT" in
    c) clean=1;;
    g) generate=1;;
    m) build=1;;
    a) build=1;
       generate=1;
       clean=1;;
    h) print_help;
       exit;;
    *) # getopts produces error
       echo "Getopts error";
       print_help;
       exit;;
  esac
done

if [ $clean -eq 1 ]; then
    echo "Cleaning"
    rm -rf ./blink ./build ./make.py ./build.py ./blink_exe ./blink_exe.elf ./mapping
fi

if [ $generate -eq 1 ]; then
    echo "Generating files"
    goil --target=ppc/mpc5643l blink.oil
fi

if [ $build -eq 1 ]; then
    echo "Building"
    ./make.py
fi

if [ $clean -eq 0 ] && [ $build -eq 0 ] && [ $generate -eq 0 ] ; then
    print_help
fi

