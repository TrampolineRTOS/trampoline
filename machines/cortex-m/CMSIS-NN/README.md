# CMSIS NN
CMSIS NN software library is a collection of efficient neural network kernels developed to maximize the
performance and minimize the memory footprint of neural networks on Arm Cortex-M processors.

## Supported Framework
The library follows the [int8](https://www.tensorflow.org/lite/performance/quantization_spec) and int16 quantization specification of TensorFlow Lite for Microcontrollers.
This means CMSIS-NN is bit-exact with Tensorflow Lite reference kernels. In some cases TFL and TFLM reference kernels may not be bit-exact. In that case CMSIS-NN follows TFLM reference kernels. The unit test readme provides an [overview](https://github.com/ARM-software/CMSIS-NN/blob/main/Tests/UnitTest/README.md#tests-depending-on-tflm-interpreter).

## Branches and Tags
There is a single branch called 'main'.
Tags are created during a release. Two releases are planned to be done in a year. The releases can be found
[here](https://github.com/ARM-software/CMSIS-NN/releases) .

## Current Operator Support
In general optimizations are written for an architecture feature. This falls into one of the following categories.
Based on feature flags for a processor or architecture provided to the compiler, the right implementation is picked.
### Pure C
 There is always a pure C implementation for an operator. This is used for processors like Arm Cortex-M0 or Cortex-M3.
### DSP Extension
Processors with DSP extension uses Single Instruction Multiple Data(SIMD) instructions for optimization. Examples of
processors here are Cortex-M4 or a Cortex-M33 configured with optional DSP extension.

### MVE Extension
Processors with Arm Helium Technology use the Arm M-profile Vector Extension(MVE) instructions for optimization.
Examples are Cortex-M55 or Cortex-M85 configured with MVE.

| Operator        | C <br> int8 | C<br>int16 | C<br>int4* | DSP<br>int8 | DSP<br>int16 | DSP<br>int4* | MVE<br>int8 | MVE<br>int16 | MVE<br>int4* |
| --------------- | ----------- | ---------- |------------|-------------| -------------|--------------|-------------| -------------|--------------|
| Conv2D          | Yes         | Yes        | Yes        | Yes         | Yes          | Yes          | Yes         | Yes          | Yes          |
| DepthwiseConv2D | Yes         | Yes        | Yes        | Yes         | Yes          | Yes          | Yes         | Yes          | Yes          |
| TransposeConv2D | Yes         | No         | No         | Yes         | No           | No           | Yes         | No           | No           |
| Fully Connected | Yes         | Yes        | Yes        | Yes         | Yes          | Yes          | Yes         | Yes          | Yes          |
| Batch Matmul    | Yes         | Yes        | No         | Yes         | Yes          | No           | Yes         | Yes          | No           |
| Add             | Yes         | Yes        | N/A        | Yes         | Yes          | N/A          | Yes         | Yes          | N/A          |
| Minimum         | Yes         | No         | N/A        | No          | No           | N/A          | Yes         | No           | N/A          |
| Maximum         | Yes         | No         | N/A        | No          | No           | N/A          | Yes         | No           | N/A          |
| Mul             | Yes         | Yes        | N/A        | Yes         | Yes          | N/A          | Yes         | Yes          | N/A          |
| MaxPooling      | Yes         | Yes        | N/A        | Yes         | Yes          | N/A          | Yes         | Yes          | N/A          |
| AvgPooling      | Yes         | Yes        | N/A        | Yes         | Yes          | N/A          | Yes         | Yes          | N/A          |
| Softmax         | Yes         | Yes        | N/A        | Yes         | Yes          | N/A          | Yes         | No           | N/A          |
| LSTM            | Yes         | Yes        | No         | Yes         | Yes          | No           | Yes         | Yes          | No           |
| SVDF            | Yes         | No         | No         | Yes         | No           | No           | Yes         | No           | No           |
| Pad             | Yes         | No         | N/A        | No          | No           | N/A          | Yes         | No           | N/A          |
| Transpose       | Yes         | No         | N/A        | No          | No           | N/A          | Yes         | No           | N/A          |

* int4 weights + int8 activations

## Contribution Guideline
First, a thank you for the contribution. Here are some guidelines and good to know information to get started.

### Coding Guideline
By default, follow the style used in the file. You'll soon start noticing a pattern like
* Variable and function names are lower case with an underscore separator.
* Hungarian notation is not used. Well, almost.
* If the variable names don't convey the action, then add comments.

### New Files
One function per file is followed in most places. In those cases, the file name must match the function name. Connect
the function to an appropriate Doxygen group as well.

### Doxygen
Function prototypes must have a detailed comment header in Doxygen format. You can execute the doxygen document generation
script in the Documentation/Doxygen folder to check that no errors are introduced.

### Unit Tests
For any new features and bug fixes, new unit tests are needed. Improvements have to be verifed by unit tests. If you do
not have the means to execute the tests, you can still make the PR and comment that you need help in completing/executing
the unit tests.

### Version & Date
Each File has a version number and a date field that must be updated when making any change to that file. The versioning
follows Semantic Versioning 2.0.0 format. For details check: https://semver.org/

## Building CMSIS-NN as a library
It is recommended to use toolchain files from [Arm Ethos-U Core Platform](https://review.mlplatform.org/admin/repos/ml/ethos-u/ethos-u-core-platform) project. These are supporting TARGET_CPU, which is a required argument. Note that if not specifying TARGET_CPU, these toolchains will set some default. The format must be TARGET_CPU=cortex-mXX, see examples below.

Here is an example:

```
cd </path/to/CMSIS_NN>
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=</path/to/ethos-u-core-platform>/cmake/toolchain/arm-none-eabi-gcc.cmake -DTARGET_CPU=cortex-m55
make
```

Some more examples:

```
cmake .. -DCMAKE_TOOLCHAIN_FILE=</path/to/ethos-u-core-platform>/cmake/toolchain/armclang.cmake -DTARGET_CPU=cortex-m55
cmake .. -DCMAKE_TOOLCHAIN_FILE=</path/to/ethos-u-core-platform>/cmake/toolchain/arm-none-eabi-gcc.cmake -DTARGET_CPU=cortex-m7
cmake .. -DCMAKE_TOOLCHAIN_FILE=</path/to/ethos-u-core-platform>/cmake/toolchain/armclang.cmake -DTARGET_CPU=cortex-m3
```

### Compiler Options
Default optimization level is set at Ofast. This can be overwritten with CMake on command line by using <nobr>*"-DCMSIS_OPTIMIZATION_LEVEL"*</nobr>. Please change according to project needs.
Just bear in mind this can impact performance. With only optimization level -O0, *ARM_MATH_AUTOVECTORIZE* needs to be defined for processors with Helium
Technology.

The compiler option *'-fomit-frame-pointer'* is enabled by default at -O and higher. When no optimization level is specified,
you may need to specify '-fomit-frame-pointer'.

The compiler option *'-fno-builtin'* does not utilize optimized implementations of e.g. memcpy and memset, which are heavily used by CMSIS-NN. It can significantly downgrade performance. So this should be avoided. The compiler option *'-ffreestanding'* should also be avoided as it enables '-fno-builtin' implicitly.

Another option is to enable CMSIS_NN_USE_SINGLE_ROUNDING. This may affect the output. If enabling this the equivalent flag should be enabled in TFL/TFLM.

For processors with DSP extension, int4 and int8 convolutions make use of the restrict keyword for the output pointer. This can allow the compiler to make optimizations but the actual performance result depends on the Arm(R) Cortex(R)-M processor, the compiler and the model. This optimization can be enabled by providing the compiler with a defition of OPTIONAL_RESTRICT_KEYWORD=__restrict . In general Arm Cortex-M7 will benefit from this. Similar Arm Cortex-M4 and Cortex-M33, will generally not benefit from it, but it may still bring an uplift depending on the model and compiler. It is recommended to enable this for Cortex-M7.

### Supported Compilers
* CMSIS-NN is tested on Arm Compiler 6 and on Arm GNU Toolchain.
* IAR compiler is not tested and there can be compilation and/or performance issues.
* Compilation for Host is not supported out of the box. It should be possible to use the C implementation and compile for host with minor stubbing effort.

## Inclusive Language
This product confirms to Arm’s inclusive language policy and, to the best of our knowledge, does not contain any non-inclusive language. If you find something that concerns you, email terms@arm.com.

## Support / Contact

For any questions or to reach the CMSIS-NN team, please create a new issue in https://github.com/ARM-software/CMSIS-NN/issues
