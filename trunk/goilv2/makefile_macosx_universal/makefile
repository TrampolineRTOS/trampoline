#---------------------------------------------------------------------------*
#                                                                           *
# MAKEFILE for building "goil" 32-bits command line tools for Mac OS X   *
#                                                                           *
#---------------------------------------------------------------------------*

#---------------------------------------------------------------------------*
#                                                                           *
#                               Executables                                 *
#                                                                           *
#---------------------------------------------------------------------------*

EXECUTABLE := goil
EXECUTABLE_DEBUG := goil_debug

#---------------------------------------------------------------------------*
#                                                                           *
#                  Install directory (for "install" goal)                   *
#                                                                           *
#---------------------------------------------------------------------------*

INSTALL_DIR := /usr/local/bin

#---------------------------------------------------------------------------*
#                                                                           *
#                        'all' goal                                         *
#                                                                           *
#---------------------------------------------------------------------------*

all:
	$(MAKE) -C ../makefile_macosx_ppc $(EXECUTABLE)
	$(MAKE) -C ../makefile_macosx_intel $(EXECUTABLE)
	lipo -create ../makefile_macosx_ppc/$(EXECUTABLE) ../makefile_macosx_intel/$(EXECUTABLE) -output $(EXECUTABLE)
	lipo -info $(EXECUTABLE)
	$(MAKE) -C ../makefile_macosx_ppc $(EXECUTABLE_DEBUG)
	$(MAKE) -C ../makefile_macosx_intel $(EXECUTABLE_DEBUG)
	lipo -create ../makefile_macosx_ppc/$(EXECUTABLE_DEBUG) ../makefile_macosx_intel/$(EXECUTABLE_DEBUG) -output $(EXECUTABLE_DEBUG)
	lipo -info $(EXECUTABLE_DEBUG)

#---------------------------------------------------------------------------*
#                                                                           *
#                        'clean' goal                                       *
#                                                                           *
#---------------------------------------------------------------------------*

clean:
	rm -f $(EXECUTABLE) $(EXECUTABLE_DEBUG)

#---------------------------------------------------------------------------*
