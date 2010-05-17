//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_options.cpp'                           *
//                       Generated by version 1.9.12                         *
//                       may 17th, 2010, at 15h23'41"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 742
  #error "This file has been compiled with a version of GALGAS that uses libpm version 742, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

#include <string.h>

//---------------------------------------------------------------------------*

#include "goil_options.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                               Bool options                                *
//                                                                           *
//---------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_goil_5F_options_autosar_5F_on ("goil_options",
                                         "autosar_on",
                                         97,
                                         "autosar",
                                         "Parse Autosar objects and attributes") ;

C_BoolCommandLineOption gOption_goil_5F_options_generate_5F_log ("goil_options",
                                         "generate_log",
                                         108,
                                         "logfile",
                                         "generate a goil.log file containing the a log of the compilation") ;

C_BoolCommandLineOption gOption_goil_5F_options_generate_5F_makefile ("goil_options",
                                         "generate_makefile",
                                         103,
                                         "generate-makefile",
                                         "Generate a Makefile from OS extra attributes") ;

C_BoolCommandLineOption gOption_goil_5F_options_posix_5F_it ("goil_options",
                                         "posix_it",
                                         105,
                                         "interrupts",
                                         "Generate an interrupt table") ;

//---------------------------------------------------------------------------*
//                                                                           *
//                               UInt options                                *
//                                                                           *
//---------------------------------------------------------------------------*

//---------------------------------------------------------------------------*
//                                                                           *
//                              String options                               *
//                                                                           *
//---------------------------------------------------------------------------*

C_StringCommandLineOption gOption_goil_5F_options_project_5F_dir ("goil_options",
                                         "project_dir",
                                         112,
                                         "project",
                                         "Specifies project directory (by default, the project directory is the name of the oil file, without the .oil extension)",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_target_5F_platform ("goil_options",
                                         "target_platform",
                                         116,
                                         "target",
                                         "Specifies target platform (avr, h8300h, libpcl, posix, posix_vp2, v850e, arm, c166, hcs12, ppc or cortex-m3)",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_template_5F_dir ("goil_options",
                                         "template_dir",
                                         0,
                                         "templates",
                                         "Specifies template directory (used by goil for code generation)",
                                         "") ;

//---------------------------------------------------------------------------*


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



