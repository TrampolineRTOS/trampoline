#! /bin/bash

# By default, this script compiles on a remote server using below SSH_SERVER,
# LOCAL_TRAMPOLINE, REMOTE_TRAMPOLINE
# Please set all below variables accordingly

# Remote server address
SSH_SERVER="groscalin"
# Path to the local trampoline directory (Ex: $HOME/trampoline)
LOCAL_TRAMPOLINE="$HOME/trampoline/trampoline"
# Path to the remote trampoline directory (Ex: /home/bob/trampoline)
REMOTE_TRAMPOLINE="trampoline"
# Path to the remote example directory (Ex: /home/bob/trampoline/examples/arch/blink)
EXAMPLE_ABS_DIR=$(pwd)
EXAMPLE_REL_DIR=$(echo "$EXAMPLE_ABS_DIR" | sed "s#$LOCAL_TRAMPOLINE/\?##")
REMOTE_EXAMPLE_DIR="$REMOTE_TRAMPOLINE/$EXAMPLE_REL_DIR"
# Rsync excluded directories (when copying trampoline)
RSYNC_EXCLUDE="--exclude .git
               --exclude documentation
               --exclude tests
               --exclude goil"

# Goil command
GOIL="goil --warn-deprecated"
# Goil arch target (Ex: ppc/mpc5643l)
GOIL_TARGET="ppc/mpc5643l/multicore"
# Goil source (Ex: ./blink.oil)
GOIL_SOURCE="./button.oil"
# Goil output (deleted on clean only)
GOIL_OUTPUT="./make.py ./build.py ./button"
# Build ouptut (deleted on clean, copied from server after compilation)
BUILD_OUTPUT="./build ./button_exe ./button_exe.elf ./mapping"

# Timeout
BUILD_TIMEOUT="timeout 6s"

source ./../../tools/run_core.sh $@

