# Unit tests for CMSIS-NN

Unit test CMSIS-NN functions on any [Arm Mbed OS](https://os.mbed.com/mbed-os/) supported HW or using a fixed virtual platform (FVP) based on [Arm Corstone-300 software](https://developer.arm.com/ip-products/subsystem/corstone/corstone-300).

The [Unity test framework](http://www.throwtheswitch.org/unity) is used for running the actual unit tests.

For a quick setup, it is reccomended to the helper script targetting the Arm Corstone-300 softwware. See the section " Using FVP based on Arm Corstone-300 software ".

## Requirements

The following apt packages are required. Replace python venv version with your python version.
```
sudo apt install ruby-full cmake python3.X-venv pip curl git git-lfs
```

Python3 is required.
It has been tested with Python 3.10 and it has been tested on Ubuntu 22.04.

Make sure to use the latest pip version before starting.
If in a virtual environment just start by upgrading pip.

```
pip install --upgrade pip
```

After upgrading pip, the requirements file found in Tests/UnitTests can be installed. This contains all
python modules required to run all of the scripts. This will install tensorflow and keras to allow the use of
the generate_test_data.py script. If you have version specific requirements, it is reccomended to install this
requirements.txt in a virtual environment.

```
pip install -r requirements.txt
```

#### Get flatc and schema

Note this is only needed for generating SVDF unit tests.

For flatc compiler clone this [repo](https://github.com/google/flatbuffers) and build:
```
cd flatbuffers
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
make
```
Remember to add the built flatc binary to the path.

For schema file download [schema.fbs](https://raw.githubusercontent.com/tensorflow/tensorflow/master/tensorflow/lite/schema/schema.fbs).

#### Interpreter for generating reference output
Python package tensorflow is always needed however the script has the option to use other interpreters than the tensorflow default, which will generate the actual reference output.

##### tflite_runtime
Python package tflite_runtime can be installed with pip and it can also be built locally. Check this [link](https://www.tensorflow.org/lite/guide/build_cmake_pip) on how to do that.
Use the -h flag to get more info on supported interpreters.

##### tflite_micro
Python package tflite_micro can be installed with pip and it can also be built locally. See this comment for more info: https://github.com/tensorflow/tflite-micro/issues/1484#issuecomment-1677842603. This interpreter is only partially supported, see *Tests depending on TFLM interpreter*.

## Getting started

### Using Arm Mbed OS supported hardware

Connect any HW (e.g. NUCLEO_F746ZG) that is supported by Arm Mbed OS. Multiple boards are supported. Note that board must be mounted, which may or may not be done automatically depending on OS. If all requirements are satisfied you can just run:

```
./unittest_targets.py
```

Use the -h flag to get more info.

### Using FVP based on Arm Corstone-300 software

The easiest way to run the unit tests on Corstone-300 is to use the build_and_run_tests.sh script. This script will install required packages, build unit tests and run unit tests. This script has been designed for Linux hosts with both aarch64 and x86_64 architectures. For more help use the '-h' flag on the script.

Sample usage:
```
./build_and_run_tests.sh -c cortex-m3,cortex-m7,cortex-m55 -o '-Ofast'
```
By default the script will download and target gcc. To use arm compiler ensure that arm compilers folder is located in path, export CC and use the -a option on the script.

Downloaded dependencies including python venv can be found in Tests/UnitTests/downloads. Test elfs can be found in Tests/UnitTests/build-($cpu) directories.

Otherwise, you can build it manually:

The build for unit tests differs from the build of CMSIS-NN as a [standalone library](https://github.com/ARM-software/CMSIS-NN/blob/main/README.md#building-cmsis-nn-as-a-library) in that, there is a dependency to [CMSIS](https://github.com/ARM-software/CMSIS_5) project for the startup files from CMSIS-Core. This is specified by the mandatory CMSIS_PATH CMake argument.


Here is an example for testing on Arm Cortex-M55:

```
cd </path/to/CMSIS_NN/Tests/Unittest>
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=</path/to/ethos-u-core-platform>/cmake/toolchain/arm-none-eabi-gcc.cmake -DTARGET_CPU=cortex-m55 -DCMSIS_PATH=</path/to/CMSIS>
make
```

This will build all unit tests. You can also just build a specific unit test only, for example:

```
make test_arm_depthwise_conv_s8_opt
```

Then you need to download and install the FVP based Arm Corstone-300 software, for example:

```
mkdir -p /home/$user/FVP
wget https://developer.arm.com/-/media/Arm%20Developer%20Community/Downloads/OSS/FVP/Corstone-300/FVP_Corstone_SSE-300_Ethos-U55_11.12_57.tgz
tar -xvzf FVP_Corstone_SSE-300_Ethos-U55_11.12_57.tgz
./FVP_Corstone_SSE-300_Ethos-U55.sh --i-agree-to-the-contained-eula --no-interactive -d /home/$user/FVP
export PATH="/home/$user/FVP/models/Linux64_GCC-6.4:$PATH"
```

Finally you can run the unit tests. For example:

```
FVP_Corstone_SSE-300_Ethos-U55 --cpulimit 2 -C mps3_board.visualisation.disable-visualisation=1 -C mps3_board.telnetterminal0.start_telnet=0 -C mps3_board.uart0.out_file="-" -C mps3_board.uart0.unbuffered_output=1 ./TestCases/test_arm_depthwise_conv_s8_opt/test_arm_depthwise_conv_s8_opt.elf
```

## Generating new test data
**NOTE:** The data generation scrips are being reworked, see *Refactoring of generate_test_data*

Generating new test data is done with the following script. Use the -h flag to get more info.

```
./generate_test_data.py -h

```

The script use a concept of test data sets, i.e. it need a test set data name as input. It will then generate files with that name as prefix. Multiple header files of different test sets can then be included in the actual unit test files.
When adding a new test data set, new c files should be added or existing c files should be updated to use the new data set. See overview of the folders on how/where to add new c files.

The steps to add a new unit test are as follows. Add a new test test in the load_all_testdatasets() function. Run the generate script with that new test set as input. Add the new generated header files to an existing or new unit test.

### Tests depending on TFLM interpreter

If TFL and TFLM reference kernels differ, CMSIS-NN aims to be bit-exact to TFLM reference kernels. Hence those operators depends on tflite_micro interpreter.

Operator bit-exactness compability:

| Operator        |  TFL bit-exact  | TFLM bit-exact |  Notes
| ---             | ---             | ---       | ---
| convolution     |   x             |  x        |
| fully_connected |   x             |  x        |
| lstm            |                 |  x        |
| svdf            |                 |  x        | Operator is only fully supported by TFLM.
| softmax         |   x             |  x        |
| avgpool         |   x             |  x        |
| maxpool         |   x             |  x        |
| add             |   x             |  x        |
| mul             |   x             |  x        |
| batch matmul    |   x             |  x        |
| pad             |   x             |  x        |
| minimum         |   x             |  x        |
| maximum         |   x             |  x        |
| transpose       |   x             |  x        |

### Refactoring of generate_test_data.py
Test data generation is in progress of incrementally moving over to the cleaned up scripts placed in `RefactoredTestGen`.

To try out the new scripts, use
```
./RefactoredTestGen/generate_test_data.py --help
```

The previous generate_test_data will remain as the main data generator until all functionality is replicated with the new scripts.

Current progress:

| Operator        | Old  | New | Notes
| ---             | ---  | --- | ---
| convolution     |  x   |  x  | New version only supports 16x8 and int4 packed weights
| depthwise conv  |  x   |     |
| fully_connected |  x   |  x  | New version supports int4 packed weights. Only new version supports per channels quantization for int8.
| lstm            |      |  x  | Only new version supporting 16x8
| svdf            |  x   |     |
| softmax         |  x   |     |
| avgpool         |      |  x  |
| maxpool         |      |  x  |
| add             |  x   |     |
| mul             |  x   |     |
| batch matmul    |      |  x  |
| pad             |      |  x  |
| minimum         |      |  x  |
| maximum         |      |  x  |
| transpose       |      |  x  |

## Overview of the Folders

- `Corstone-300` - These are dependencies, like linker files etc, needed when building binaries targeting the FVP based on Arm Corstone-300 software. This is mostly taken from Arm Ethos-U Core Platform project.
- `Mbed` - These are the Arm Mbed OS settings that are used. See Mbed/README.md.
- `Output` - This will be created when building.
- `PregeneratedData` - Host local(Not part of GitHub) test data for model creation using Keras in unit tests. It can be used for debug purposes when
                       adding new operators or debugging existing ones.
- `TestCases` - Here are the actual unit tests. For each function under test there is a folder under here.
- `TestCases/<cmsis-nn function name>` - For each function under test there is a folder with the same name with test_ prepended to the name and it contains a c-file with the actual unit tests. For example for arm_convolve_s8() the file is called test_arm_convolve_s8.c
- `TestCases/<cmsis-nn function name>/Unity` - This folder contains a Unity file that calls the actual unit tests. For example for arm_convolve_s8() the file is called unity_test_arm_convolve_s8.c.
- `TestCases/<cmsis-nn function name>/Unity/TestRunner` - This folder will contain the autogenerated Unity test runner.
- `TestCases/TestData` - This is auto generated test data in .h files that the unit tests are using. The data in PregenrateData folder has fp32 data of a network whereas  here it is the quantized equivalent of the same. They are not the same. All data can regenerated or only parts of it (e.g. only bias data). Of course even the config can be regenerated. This partial/full regeneration is useful during debugging.
- `TestCases/Common` - Common files used in test data generation is placed here.
- `RefactoredTestGen` - Temporary location for new test generation scripts

## Formatting

The python test scripts should be formatted with yapf.

```
pip install --upgrade yapf
```

The following settings are used.

```
python -m yapf --in-place --style='{based_on_style:pep8,column_limit:120,indent_width:4}' *.py
```
