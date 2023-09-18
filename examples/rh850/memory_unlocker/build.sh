#!/usr/bin/env bash

set -e

PROGRAM_NAME=memory_unlocker
FLASH_TOOL_PROGRAM_NAME=App_CDD_ICCOM_S4_Sample_G4MH

echo "*** Run Goil ***"
mkdir -p _build
goil --target=rh850/g4mh --templates=../../../goil/templates/ ${PROGRAM_NAME}.oil

echo "*** Run CMake ***"
cd _build
cmake -G "Unix Makefiles" -D CMAKE_TOOLCHAIN_FILE=../${PROGRAM_NAME}/compiler.cmake ..

echo "*** Run Make ***"
make

# Create the S-Record file to provide to Flash_Tool to set the G4MH core default firmware on board boot
# The flashing procedure expects 32-bit addresses, so use S3 records instead of S1
objcopy -O srec --srec-forceS3 ${PROGRAM_NAME}_exe.abs ${FLASH_TOOL_PROGRAM_NAME}.s3
# Add a specific header (it has been downloaded here : https://raw.githubusercontent.com/renesas-rcar/whitebox-sdk/v4.x/mcu/G4MH_Head.srec)
rlink ../G4MH_Head.srec ${FLASH_TOOL_PROGRAM_NAME}.s3 -FOrm=SType -OUtput=${FLASH_TOOL_PROGRAM_NAME}.srec
rm -f ${FLASH_TOOL_PROGRAM_NAME}.s3
