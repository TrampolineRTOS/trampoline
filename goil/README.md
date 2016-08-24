# GOIL

Goil is the OIL compiler of Trampoline. To compile Goil for you platform go in the corresponding subdirectory:

* `makefile-macosx` for Mac OS X. Then type `./build.py`;
* `makefile-unix` for Linux. Then type `./build.py`;
* `makefile-msys32-on-windows` for Windows with [MSYS](http://www.mingw.org/wiki/msys). Double click on `build.bat`.

In addition Goil can be built on Windows by using [Code::Blocks](http://www.codeblocks.org).
The project is in the `project-codeblocks-windows` subdirectory.

On Mac OS X Goil can be cross-built. Go into:

* `makefile-win32-on-macosx` to cross-build for Windows;
* `makefile-x86linux32-on-macosx` to cross-build for 32 bits Linux;
* `makefile-x86linux64-on-macosx` to cross-build for 64 bits Linux.

and type `./build.py`. The build system will download the corresponding toolchain before building goil.

## GTL

Goil includes a template language interpreter called GTL. Check https://github.com/TrampolineRTOS/GTL
