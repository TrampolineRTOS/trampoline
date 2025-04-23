#!/usr/bin/env bash
#
# SPDX-FileCopyrightText: Copyright 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the License); you may
# not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an AS IS BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Version: 1.0
# Date: 2024-05-21
# This bash script downloads unit test dependencies, builds unit tests and also runs the tests.

CPU="cortex-m55"
OPTIMIZATION="-Ofast"
QUIET=0
BUILD=1
RUN=1
SETUP_ENVIRONMENT=1
USE_ARM_COMPILER=0
USE_PYTHON_VENV=1
USE_FVP_FROM_DOWNLOAD=1
USE_GCC_FROM_DOWNLOAD=1

ETHOS_U_CORE_PLATFORM_PATH=""
CMSIS_5_PATH=""


usage="
Helper script to setup, build and run CMSIS-NN unit tests

args:
    -h  Display this message.
    -c  Target cpu. Takes multiple arguments as a comma seperated list. eg cortex-m3,cortex-m7,cortex-m55 (default: cortex-m55)
    -o  Optimization level. (default: '-Ofast')
    -q  Quiet mode. This reduces the amount of info printed from building and running cmsis-unit tests.
    -b  Disable CMake build. Only works with previously built targets. Designed to quickly rerun cpu targets. 
    -r  Disable running the unit tests. Designed to test build only or allow user to manually run individual test cases outside of this script.
    -e  Disable environment setup. This flag will stop the script from attempting to download dependencies. This is just a quiet mode to reduce print outs.
    -a  Use Arm Compiler that is previously available on machine. Ensure compiler directory is added to path and export CC.
    -p  Disable the usage of python venv from download directory. Requires dependencies to be install before calling script.
    -f  Disable the usage of FVP from download directory. Requires FVP to be in path before calling script.
    -u  Path to ethos-u-core-platform
    -g  Disable the usage of GCC that is already from download directory. Requires gcc to be in path before calling script.
    -C  Path to cmsis 5

    example usage: $(basename "$0") -c cortex-m3,cortex-m4 -o '-O2' -q
"

while getopts hc:o:qbreapfu:gC: flag
do
    case "${flag}" in
        h) echo "${usage}"
           exit 1;;
        c) CPU=${OPTARG};;
        o) OPTIMIZATION=${OPTARG};;
        q) QUIET=1;;
        b) BUILD=0;;
        r) RUN=0;;
        e) SETUP_ENVIRONMENT=0;;
        a) USE_ARM_COMPILER=1;;
        p) USE_PYTHON_VENV=0;;
        f) USE_FVP_FROM_DOWNLOAD=0;;
        u) ETHOS_U_CORE_PLATFORM_PATH="${OPTARG}";;
        g) USE_GCC_FROM_DOWNLOAD=0;;
        C) CMSIS_5_PATH="${OPTARG}";;
    esac
done

Setup_Environment() {
    set -e
    echo "++ Downloading Corstone300"
    if [[ -d ${WORKING_DIR}/corstone300_download ]]; then
        echo "Corstone300 already installed. If you wish to install a new version, please delete the old folder."
    else
        if [[ ${UNAME_M} == x86_64 ]]; then
            CORSTONE_URL=https://developer.arm.com/-/media/Arm%20Developer%20Community/Downloads/OSS/FVP/Corstone-300/FVP_Corstone_SSE-300_11.24_13_Linux64.tgz
        elif [[ ${UNAME_M} == aarch64 ]]; then
            CORSTONE_URL=https://developer.arm.com/-/media/Arm%20Developer%20Community/Downloads/OSS/FVP/Corstone-300/FVP_Corstone_SSE-300_11.24_13_Linux64_armv8l.tgz
        fi

        TEMPFILE=$(mktemp -d)/temp_file
        wget ${CORSTONE_URL} -O ${TEMPFILE} >&2

        TEMPDIR=$(mktemp -d)
        tar -C ${TEMPDIR} -xvzf ${TEMPFILE} >&2
        mkdir ${WORKING_DIR}/corstone300_download
        ${TEMPDIR}/FVP_Corstone_SSE-300.sh --i-agree-to-the-contained-eula --no-interactive -d ${WORKING_DIR}/corstone300_download >&2
    fi

    echo "++ Downloading GCC"
    if [[ -d ${WORKING_DIR}/arm_gcc_download ]]; then
        echo "Arm GCC already installed. If you wish to install a new version, please delete the old folder."
    else
        if [[ ${UNAME_M} == x86_64 ]]; then
            GCC_URL="https://developer.arm.com/-/media/Files/downloads/gnu/13.2.rel1/binrel/arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz"
        elif [[ ${UNAME_M} == aarch64 ]]; then
            GCC_URL="https://developer.arm.com/-/media/Files/downloads/gnu/13.2.rel1/binrel/arm-gnu-toolchain-13.2.rel1-aarch64-arm-none-eabi.tar.xz"
        fi

        TEMPFILE=$(mktemp -d)/temp_file
        wget ${GCC_URL} -O ${TEMPFILE} >&2
        mkdir ${WORKING_DIR}/arm_gcc_download

        tar -C ${WORKING_DIR}/arm_gcc_download --strip-components=1 -xJf ${TEMPFILE} >&2
    fi

    echo "++ Cloning CMSIS-5"
    if [[ -d ${WORKING_DIR}/CMSIS_5 ]]; then
        echo "CMSIS-5 already installed. If you wish to install a new version, please delete the old folder."
    else
        git clone https://github.com/ARM-software/CMSIS_5.git
    fi

    echo "++ Cloning Ethos-U core platform"
    if [[ -d ${WORKING_DIR}/ethos-u-core-platform ]]; then
        echo "Ethos-U core platform already installed. If you wish to install a new version, please delete the old folder."
    else
        git clone https://review.mlplatform.org/ml/ethos-u/ethos-u-core-platform
    fi

    echo "++ Setting up python environment"
    if [[ -d ${WORKING_DIR}/cmsis_nn_venv ]]; then
        echo "Python venv already installed. If you wish to install a new version, please delete the old folder."
    else
        python3 -m venv cmsis_nn_venv
        source cmsis_nn_venv/bin/activate
        pip3 install -r ../requirements.txt
        deactivate
    fi
}

Build_Tests() {
    set -e
    echo "++ Building Tests"
    if [[ ${QUIET} -eq 0 ]]; then
        cmake -S ./ -B build-${cpu}-${compiler} -DCMAKE_TOOLCHAIN_FILE=${TOOLCHAIN_FILE} -DTARGET_CPU=${cpu} -DCMSIS_PATH=${CMSIS_5_PATH} -DCMSIS_OPTIMIZATION_LEVEL=${OPTIMIZATION}
        cmake --build build-${cpu}-${compiler}/

        echo "Built successfully into build-${cpu}-${compiler}"
    else
        cmake_command=$(cmake -S ./ -B build-${cpu}-${compiler} -DCMAKE_TOOLCHAIN_FILE=${TOOLCHAIN_FILE} -DTARGET_CPU=${cpu} -DCMSIS_PATH=${CMSIS_5_PATH} -DCMSIS_OPTIMIZATION_LEVEL=${OPTIMIZATION} 2>&1)
        make_command=$(cmake --build build-${cpu}-${compiler}/ 2>&1)
        echo "${cmake_command}" > build-${cpu}-${compiler}/cmake_command.txt
        echo "${make_command}" > build-${cpu}-${compiler}/make_command.txt

        echo "Built successfully into build-${cpu}-${compiler}"
    fi
}

Run_Tests() {
    set +e
    echo "++ Running Unit Tests"
    readarray -d '' tests < <(find ./build-${cpu}-${compiler}/ -iname "*.elf" -print0)
    for test in "${tests[@]}"
    do
        echo "Test: ${test}"
        output=$(FVP_Corstone_SSE-300_Ethos-U55 -C mps3_board.uart0.shutdown_on_eot=1 -C mps3_board.visualisation.disable-visualisation=1 -C mps3_board.telnetterminal0.start_telnet=0 -C mps3_board.uart0.out_file="-" -C mps3_board.uart0.unbuffered_output=1 ${test})
        echo "$output" | grep "0 Failures" -vqz
        if [[ $? -eq 0 ]]; then
            echo "${output}"
            echo "${test} failed. Script exiting."
            exit 1
        elif [[ ${QUIET} -eq 0 ]]; then
            echo "${output}"
        fi
    done
    echo "Tests for ${cpu} ran successfully."
}

if [[ ${BUILD} -eq 0 && ${RUN} -eq 0 && ${SETUP_ENVIRONMENT} -eq 0 ]]; then
    echo "All script functions are disabled. Script will exit and do nothing."
    exit 1
fi

UNAME_M=$(uname -m)
UNAME_S=$(uname -s)

if [[ ${UNAME_S} != Linux ]]; then
    echo "Error: This script only supports Linux."
    exit 1
fi

mkdir -p downloads
pushd downloads
WORKING_DIR=$(pwd)

if [[ ${SETUP_ENVIRONMENT} -eq 1 ]]; then
    echo "++ Setting Environment"
    Setup_Environment
fi

if [[ ${USE_PYTHON_VENV} -eq 1 ]]; then
    source cmsis_nn_venv/bin/activate
fi

if [[ -z "${ETHOS_U_CORE_PLATFORM_PATH}" ]]; then
    ETHOS_U_CORE_PLATFORM_PATH="${WORKING_DIR}/ethos-u-core-platform"
fi

if [[ -z "${CMSIS_5_PATH}" ]]; then
    CMSIS_5_PATH="${WORKING_DIR}/CMSIS_5"
fi

popd
IFS=',' read -r -a cpu_array <<< "$CPU"

if [[ ${BUILD} -eq 1 || ${RUN} -eq 1 ]]; then
    for cpu in "${cpu_array[@]}"
    do
        echo "++ Targetting ${cpu}"
        if [[ ${USE_ARM_COMPILER} -eq 1 ]]; then
            compiler="arm-compiler"
            TOOLCHAIN_FILE=${ETHOS_U_CORE_PLATFORM_PATH}/cmake/toolchain/armclang.cmake
        else
            if [[ ${USE_GCC_FROM_DOWNLOAD} -eq 1 ]]; then
                export PATH=${WORKING_DIR}/arm_gcc_download/bin/:${PATH}
            fi
            compiler="gcc"
            TOOLCHAIN_FILE=${ETHOS_U_CORE_PLATFORM_PATH}/cmake/toolchain/arm-none-eabi-gcc.cmake
        fi

        if [[ $USE_FVP_FROM_DOWNLOAD -eq 1 ]]; then
            if [[ ${UNAME_M} == x86_64 ]]; then
                export PATH=${WORKING_DIR}/corstone300_download/models/Linux64_GCC-9.3/:${PATH}
            elif [[ ${UNAME_M} == aarch64 ]]; then
                export PATH=${WORKING_DIR}/corstone300_download/models/Linux64_armv8l_GCC-9.3/:${PATH}
            fi
        fi

        if [[ ${BUILD} -eq 1 ]]; then
            Build_Tests
        fi

        if [[ ${RUN} -eq 1 ]]; then
            Run_Tests
        fi
    done
fi

echo ""
echo "++ Tests for ${CPU} ran successfully"
if [[ ${USE_PYTHON_VENV} -eq 1 ]]; then
    deactivate
fi