#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-9.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    Function 'pi'                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double function_pi (C_Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  result_result = GALGAS_double::constructor_pi (SOURCE_FILE ("gtl_functions.galgas", 270)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_pi [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_pi (C_Compiler * inCompiler,
                                                   const cObjectArray & /* inEffectiveParameterArray */,
                                                   const GALGAS_location & /* inErrorLocation */
                                                   COMMA_LOCATION_ARGS) {
  return function_pi (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_pi ("pi",
                                                    functionWithGenericHeader_pi,
                                                    & kTypeDescriptor_GALGAS_double,
                                                    0,
                                                    functionArgs_pi) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Bool options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_gtl_5F_options_debug ("gtl_options",
                                         "debug",
                                         0,
                                         "debug",
                                         "Execute the GTL templates in debug mode") ;

C_BoolCommandLineOption gOption_gtl_5F_options_warnDeprecated ("gtl_options",
                                         "warnDeprecated",
                                         0,
                                         "warn-deprecated",
                                         "Warns about deprecated constructs in the GTL template language") ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               UInt options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String options                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String List options                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'signature'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_signature (GALGAS_location inArgument_loc,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (gOption_gtl_5F_options_debug.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_string var_signatureString_789 = inArgument_loc.getter_file (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 33)).getter_lastPathComponent (SOURCE_FILE ("gtl_debugger.galgas", 33)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 33)).add_operation (inArgument_loc.getter_line (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 35)).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 34)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 34)) ;
    result_result = var_signatureString_789.getter_md_35_ (SOURCE_FILE ("gtl_debugger.galgas", 36)) ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_signature [2] = {
  & kTypeDescriptor_GALGAS_location,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_signature (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_location operand0 = GALGAS_location::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  return function_signature (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_signature ("signature",
                                                           functionWithGenericHeader_signature,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_signature) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'bold'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_bold (C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_bold ; // Returned variable
  result_bold = GALGAS_string ("\x1B""[1m") ;
//---
  return result_bold ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_bold = false ;
static GALGAS_string gOnceFunctionResult_bold ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_bold (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_bold) {
    gOnceFunctionResult_bold = onceFunction_bold (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_bold = true ;
  }
  return gOnceFunctionResult_bold ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_bold (void) {
  gOnceFunctionResult_bold.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_bold (NULL,
                                                  releaseOnceFunctionResult_bold) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_bold [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_bold (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_bold (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_bold ("bold",
                                                      functionWithGenericHeader_bold,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_bold) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Once function 'underline'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_underline (C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_underline ; // Returned variable
  result_underline = GALGAS_string ("\x1B""[4m") ;
//---
  return result_underline ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_underline = false ;
static GALGAS_string gOnceFunctionResult_underline ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_underline (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_underline) {
    gOnceFunctionResult_underline = onceFunction_underline (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_underline = true ;
  }
  return gOnceFunctionResult_underline ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_underline (void) {
  gOnceFunctionResult_underline.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_underline (NULL,
                                                       releaseOnceFunctionResult_underline) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_underline [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_underline (C_Compiler * inCompiler,
                                                          const cObjectArray & /* inEffectiveParameterArray */,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  return function_underline (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_underline ("underline",
                                                           functionWithGenericHeader_underline,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           0,
                                                           functionArgs_underline) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'blink'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_blink (C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_blink ; // Returned variable
  result_blink = GALGAS_string ("\x1B""[5m") ;
//---
  return result_blink ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_blink = false ;
static GALGAS_string gOnceFunctionResult_blink ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_blink (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_blink) {
    gOnceFunctionResult_blink = onceFunction_blink (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_blink = true ;
  }
  return gOnceFunctionResult_blink ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_blink (void) {
  gOnceFunctionResult_blink.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_blink (NULL,
                                                   releaseOnceFunctionResult_blink) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_blink [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_blink (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_blink (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_blink ("blink",
                                                       functionWithGenericHeader_blink,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_blink) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'black'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_black (C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_black ; // Returned variable
  result_black = GALGAS_string ("\x1B""[90m") ;
//---
  return result_black ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_black = false ;
static GALGAS_string gOnceFunctionResult_black ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_black (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_black) {
    gOnceFunctionResult_black = onceFunction_black (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_black = true ;
  }
  return gOnceFunctionResult_black ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_black (void) {
  gOnceFunctionResult_black.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_black (NULL,
                                                   releaseOnceFunctionResult_black) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_black [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_black (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_black (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_black ("black",
                                                       functionWithGenericHeader_black,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_black) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Once function 'red'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_red (C_Compiler * /* inCompiler */
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_red ; // Returned variable
  result_red = GALGAS_string ("\x1B""[91m") ;
//---
  return result_red ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_red = false ;
static GALGAS_string gOnceFunctionResult_red ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_red (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_red) {
    gOnceFunctionResult_red = onceFunction_red (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_red = true ;
  }
  return gOnceFunctionResult_red ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_red (void) {
  gOnceFunctionResult_red.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_red (NULL,
                                                 releaseOnceFunctionResult_red) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_red [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_red (C_Compiler * inCompiler,
                                                    const cObjectArray & /* inEffectiveParameterArray */,
                                                    const GALGAS_location & /* inErrorLocation */
                                                    COMMA_LOCATION_ARGS) {
  return function_red (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_red ("red",
                                                     functionWithGenericHeader_red,
                                                     & kTypeDescriptor_GALGAS_string,
                                                     0,
                                                     functionArgs_red) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'green'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_green (C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_green ; // Returned variable
  result_green = GALGAS_string ("\x1B""[92m") ;
//---
  return result_green ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_green = false ;
static GALGAS_string gOnceFunctionResult_green ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_green (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_green) {
    gOnceFunctionResult_green = onceFunction_green (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_green = true ;
  }
  return gOnceFunctionResult_green ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_green (void) {
  gOnceFunctionResult_green.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_green (NULL,
                                                   releaseOnceFunctionResult_green) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_green [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_green (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_green (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_green ("green",
                                                       functionWithGenericHeader_green,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_green) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Once function 'yellow'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_yellow (C_Compiler * /* inCompiler */
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_yellow ; // Returned variable
  result_yellow = GALGAS_string ("\x1B""[93m") ;
//---
  return result_yellow ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_yellow = false ;
static GALGAS_string gOnceFunctionResult_yellow ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_yellow (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_yellow) {
    gOnceFunctionResult_yellow = onceFunction_yellow (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_yellow = true ;
  }
  return gOnceFunctionResult_yellow ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_yellow (void) {
  gOnceFunctionResult_yellow.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_yellow (NULL,
                                                    releaseOnceFunctionResult_yellow) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_yellow [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_yellow (C_Compiler * inCompiler,
                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                       const GALGAS_location & /* inErrorLocation */
                                                       COMMA_LOCATION_ARGS) {
  return function_yellow (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_yellow ("yellow",
                                                        functionWithGenericHeader_yellow,
                                                        & kTypeDescriptor_GALGAS_string,
                                                        0,
                                                        functionArgs_yellow) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'blue'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_blue (C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_blue ; // Returned variable
  result_blue = GALGAS_string ("\x1B""[94m") ;
//---
  return result_blue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_blue = false ;
static GALGAS_string gOnceFunctionResult_blue ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_blue (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_blue) {
    gOnceFunctionResult_blue = onceFunction_blue (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_blue = true ;
  }
  return gOnceFunctionResult_blue ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_blue (void) {
  gOnceFunctionResult_blue.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_blue (NULL,
                                                  releaseOnceFunctionResult_blue) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_blue [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_blue (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_blue (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_blue ("blue",
                                                      functionWithGenericHeader_blue,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_blue) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Once function 'magenta'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_magenta (C_Compiler * /* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_magenta ; // Returned variable
  result_magenta = GALGAS_string ("\x1B""[95m") ;
//---
  return result_magenta ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_magenta = false ;
static GALGAS_string gOnceFunctionResult_magenta ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_magenta (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_magenta) {
    gOnceFunctionResult_magenta = onceFunction_magenta (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_magenta = true ;
  }
  return gOnceFunctionResult_magenta ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_magenta (void) {
  gOnceFunctionResult_magenta.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_magenta (NULL,
                                                     releaseOnceFunctionResult_magenta) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_magenta [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_magenta (C_Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_magenta (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_magenta ("magenta",
                                                         functionWithGenericHeader_magenta,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_magenta) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'cyan'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_cyan (C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_cyan ; // Returned variable
  result_cyan = GALGAS_string ("\x1B""[96m") ;
//---
  return result_cyan ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_cyan = false ;
static GALGAS_string gOnceFunctionResult_cyan ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_cyan (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_cyan) {
    gOnceFunctionResult_cyan = onceFunction_cyan (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_cyan = true ;
  }
  return gOnceFunctionResult_cyan ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_cyan (void) {
  gOnceFunctionResult_cyan.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_cyan (NULL,
                                                  releaseOnceFunctionResult_cyan) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_cyan [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_cyan (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_cyan (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_cyan ("cyan",
                                                      functionWithGenericHeader_cyan,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_cyan) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Once function 'darkred'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_darkred (C_Compiler * /* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_red ; // Returned variable
  result_red = GALGAS_string ("\x1B""[31m") ;
//---
  return result_red ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_darkred = false ;
static GALGAS_string gOnceFunctionResult_darkred ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_darkred (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkred) {
    gOnceFunctionResult_darkred = onceFunction_darkred (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkred = true ;
  }
  return gOnceFunctionResult_darkred ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_darkred (void) {
  gOnceFunctionResult_darkred.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_darkred (NULL,
                                                     releaseOnceFunctionResult_darkred) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_darkred [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_darkred (C_Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_darkred (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_darkred ("darkred",
                                                         functionWithGenericHeader_darkred,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_darkred) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Once function 'darkgreen'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_darkgreen (C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_green ; // Returned variable
  result_green = GALGAS_string ("\x1B""[32m") ;
//---
  return result_green ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_darkgreen = false ;
static GALGAS_string gOnceFunctionResult_darkgreen ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_darkgreen (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkgreen) {
    gOnceFunctionResult_darkgreen = onceFunction_darkgreen (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkgreen = true ;
  }
  return gOnceFunctionResult_darkgreen ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_darkgreen (void) {
  gOnceFunctionResult_darkgreen.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_darkgreen (NULL,
                                                       releaseOnceFunctionResult_darkgreen) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_darkgreen [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_darkgreen (C_Compiler * inCompiler,
                                                          const cObjectArray & /* inEffectiveParameterArray */,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  return function_darkgreen (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_darkgreen ("darkgreen",
                                                           functionWithGenericHeader_darkgreen,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           0,
                                                           functionArgs_darkgreen) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Once function 'darkyellow'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_darkyellow (C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_yellow ; // Returned variable
  result_yellow = GALGAS_string ("\x1B""[33m") ;
//---
  return result_yellow ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_darkyellow = false ;
static GALGAS_string gOnceFunctionResult_darkyellow ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_darkyellow (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkyellow) {
    gOnceFunctionResult_darkyellow = onceFunction_darkyellow (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkyellow = true ;
  }
  return gOnceFunctionResult_darkyellow ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_darkyellow (void) {
  gOnceFunctionResult_darkyellow.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_darkyellow (NULL,
                                                        releaseOnceFunctionResult_darkyellow) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_darkyellow [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_darkyellow (C_Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_darkyellow (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_darkyellow ("darkyellow",
                                                            functionWithGenericHeader_darkyellow,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_darkyellow) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Once function 'darkblue'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_darkblue (C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_blue ; // Returned variable
  result_blue = GALGAS_string ("\x1B""[34m") ;
//---
  return result_blue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_darkblue = false ;
static GALGAS_string gOnceFunctionResult_darkblue ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_darkblue (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkblue) {
    gOnceFunctionResult_darkblue = onceFunction_darkblue (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkblue = true ;
  }
  return gOnceFunctionResult_darkblue ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_darkblue (void) {
  gOnceFunctionResult_darkblue.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_darkblue (NULL,
                                                      releaseOnceFunctionResult_darkblue) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_darkblue [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_darkblue (C_Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_darkblue (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_darkblue ("darkblue",
                                                          functionWithGenericHeader_darkblue,
                                                          & kTypeDescriptor_GALGAS_string,
                                                          0,
                                                          functionArgs_darkblue) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Once function 'darkmagenta'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_darkmagenta (C_Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_magenta ; // Returned variable
  result_magenta = GALGAS_string ("\x1B""[35m") ;
//---
  return result_magenta ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_darkmagenta = false ;
static GALGAS_string gOnceFunctionResult_darkmagenta ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_darkmagenta (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkmagenta) {
    gOnceFunctionResult_darkmagenta = onceFunction_darkmagenta (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkmagenta = true ;
  }
  return gOnceFunctionResult_darkmagenta ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_darkmagenta (void) {
  gOnceFunctionResult_darkmagenta.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_darkmagenta (NULL,
                                                         releaseOnceFunctionResult_darkmagenta) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_darkmagenta [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_darkmagenta (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_darkmagenta (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_darkmagenta ("darkmagenta",
                                                             functionWithGenericHeader_darkmagenta,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             0,
                                                             functionArgs_darkmagenta) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Once function 'darkcyan'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_darkcyan (C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_cyan ; // Returned variable
  result_cyan = GALGAS_string ("\x1B""[36m") ;
//---
  return result_cyan ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_darkcyan = false ;
static GALGAS_string gOnceFunctionResult_darkcyan ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_darkcyan (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkcyan) {
    gOnceFunctionResult_darkcyan = onceFunction_darkcyan (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkcyan = true ;
  }
  return gOnceFunctionResult_darkcyan ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_darkcyan (void) {
  gOnceFunctionResult_darkcyan.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_darkcyan (NULL,
                                                      releaseOnceFunctionResult_darkcyan) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_darkcyan [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_darkcyan (C_Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_darkcyan (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_darkcyan ("darkcyan",
                                                          functionWithGenericHeader_darkcyan,
                                                          & kTypeDescriptor_GALGAS_string,
                                                          0,
                                                          functionArgs_darkcyan) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'white'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_white (C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_white ; // Returned variable
  result_white = GALGAS_string ("\x1B""[97m") ;
//---
  return result_white ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_white = false ;
static GALGAS_string gOnceFunctionResult_white ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_white (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_white) {
    gOnceFunctionResult_white = onceFunction_white (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_white = true ;
  }
  return gOnceFunctionResult_white ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_white (void) {
  gOnceFunctionResult_white.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_white (NULL,
                                                   releaseOnceFunctionResult_white) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_white [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_white (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_white (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_white ("white",
                                                       functionWithGenericHeader_white,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_white) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'endc'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_endc (C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_endc ; // Returned variable
  result_endc = GALGAS_string ("\x1B""[0m") ;
//---
  return result_endc ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_endc = false ;
static GALGAS_string gOnceFunctionResult_endc ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_endc (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_endc) {
    gOnceFunctionResult_endc = onceFunction_endc (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_endc = true ;
  }
  return gOnceFunctionResult_endc ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_endc (void) {
  gOnceFunctionResult_endc.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_endc (NULL,
                                                  releaseOnceFunctionResult_endc) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_endc [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_endc (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_endc (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_endc ("endc",
                                                      functionWithGenericHeader_endc,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_endc) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'defaultDebugSettings'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext function_defaultDebugSettings (C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_debuggerContext result_debugSettings ; // Returned variable
  result_debugSettings = GALGAS_debuggerContext::constructor_new (GALGAS_bool (gOption_gtl_5F_options_debug.getter_value ()), GALGAS_bool (gOption_gtl_5F_options_debug.getter_value ()), GALGAS_bool (false), function_red (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 347)), GALGAS_string::makeEmptyString (), function_blue (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 349)), function_bold (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 350)), function_darkgreen (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 351)), GALGAS_string::makeEmptyString (), function_darkyellow (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 353)), function_bold (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 354)), GALGAS_bool (false), GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 356)), GALGAS_gtlBreakpointList::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 357)), GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 358)), GALGAS_uint ((uint32_t) 0U), GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 360)), GALGAS_gtlInstructionListContextStack::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 361)), GALGAS_debugCommandInput::constructor_new (GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 362))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 362))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 343)) ;
//---
  return result_debugSettings ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_defaultDebugSettings [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_defaultDebugSettings (C_Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_defaultDebugSettings (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_defaultDebugSettings ("defaultDebugSettings",
                                                                      functionWithGenericHeader_defaultDebugSettings,
                                                                      & kTypeDescriptor_GALGAS_debuggerContext,
                                                                      0,
                                                                      functionArgs_defaultDebugSettings) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension getter '@gtlVarItemField stringRepresentation'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlVarItemField_stringRepresentation (const cPtr_gtlVarItem * inObject,
                                                                           const GALGAS_string & constinArgument_concatString,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlVarItemField * object = (const cPtr_gtlVarItemField *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemField) ;
  result_result = constinArgument_concatString.add_operation (object->mAttribute_field.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 594)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 594)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemField_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlVarItemField.mSlotID,
                                             extensionGetter_gtlVarItemField_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemField_stringRepresentation (defineExtensionGetter_gtlVarItemField_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension getter '@gtlVarItemSubCollection stringRepresentation'                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlVarItemSubCollection_stringRepresentation (const cPtr_gtlVarItem * inObject,
                                                                                   const GALGAS_string & /* constinArgument_concatString */,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlVarItemSubCollection * object = (const cPtr_gtlVarItemSubCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemSubCollection) ;
  result_result = GALGAS_string ("[").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 602)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 602)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 602)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemSubCollection_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlVarItemSubCollection.mSlotID,
                                             extensionGetter_gtlVarItemSubCollection_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemSubCollection_stringRepresentation (defineExtensionGetter_gtlVarItemSubCollection_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Overriding extension getter '@gtlVarItemCollection stringRepresentation'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlVarItemCollection_stringRepresentation (const cPtr_gtlVarItem * inObject,
                                                                                const GALGAS_string & constinArgument_concatString,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlVarItemCollection * object = (const cPtr_gtlVarItemCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemCollection) ;
  result_result = constinArgument_concatString.add_operation (object->mAttribute_field.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 610)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 610)).add_operation (GALGAS_char (TO_UNICODE (91)).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 610)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 610)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 610)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 610)).add_operation (GALGAS_char (TO_UNICODE (93)).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 610)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 610)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemCollection_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlVarItemCollection.mSlotID,
                                             extensionGetter_gtlVarItemCollection_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemCollection_stringRepresentation (defineExtensionGetter_gtlVarItemCollection_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension getter '@gtlAddExpression stringRepresentation'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlAddExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlAddExpression * object = (const cPtr_gtlAddExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlAddExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 621)).add_operation (GALGAS_string (" + "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 621)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 621)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 621)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlAddExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlAddExpression.mSlotID,
                                             extensionGetter_gtlAddExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlAddExpression_stringRepresentation (defineExtensionGetter_gtlAddExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension getter '@gtlAndExpression stringRepresentation'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlAndExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlAndExpression * object = (const cPtr_gtlAndExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlAndExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 628)).add_operation (GALGAS_string (" & "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 628)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 628)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 628)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlAndExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlAndExpression.mSlotID,
                                             extensionGetter_gtlAndExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlAndExpression_stringRepresentation (defineExtensionGetter_gtlAndExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension getter '@gtlDivideExpression stringRepresentation'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlDivideExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlDivideExpression * object = (const cPtr_gtlDivideExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlDivideExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 635)).add_operation (GALGAS_string (" / "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 635)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 635)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 635)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlDivideExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlDivideExpression.mSlotID,
                                             extensionGetter_gtlDivideExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlDivideExpression_stringRepresentation (defineExtensionGetter_gtlDivideExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension getter '@gtlEqualExpression stringRepresentation'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlEqualExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlEqualExpression * object = (const cPtr_gtlEqualExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEqualExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 642)).add_operation (GALGAS_string (" == "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 642)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 642)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 642)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEqualExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlEqualExpression.mSlotID,
                                             extensionGetter_gtlEqualExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEqualExpression_stringRepresentation (defineExtensionGetter_gtlEqualExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   Overriding extension getter '@gtlGreaterOrEqualExpression stringRepresentation'                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlGreaterOrEqualExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlGreaterOrEqualExpression * object = (const cPtr_gtlGreaterOrEqualExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlGreaterOrEqualExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 649)).add_operation (GALGAS_string (" >= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 649)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 649)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 649)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlGreaterOrEqualExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlGreaterOrEqualExpression.mSlotID,
                                             extensionGetter_gtlGreaterOrEqualExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlGreaterOrEqualExpression_stringRepresentation (defineExtensionGetter_gtlGreaterOrEqualExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    Overriding extension getter '@gtlGreaterThanExpression stringRepresentation'                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlGreaterThanExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlGreaterThanExpression * object = (const cPtr_gtlGreaterThanExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlGreaterThanExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 656)).add_operation (GALGAS_string (" > "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 656)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 656)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 656)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlGreaterThanExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlGreaterThanExpression.mSlotID,
                                             extensionGetter_gtlGreaterThanExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlGreaterThanExpression_stringRepresentation (defineExtensionGetter_gtlGreaterThanExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    Overriding extension getter '@gtlLowerOrEqualExpression stringRepresentation'                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlLowerOrEqualExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlLowerOrEqualExpression * object = (const cPtr_gtlLowerOrEqualExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLowerOrEqualExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 663)).add_operation (GALGAS_string (" <= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 663)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 663)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 663)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlLowerOrEqualExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlLowerOrEqualExpression.mSlotID,
                                             extensionGetter_gtlLowerOrEqualExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlLowerOrEqualExpression_stringRepresentation (defineExtensionGetter_gtlLowerOrEqualExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension getter '@gtlLowerThanExpression stringRepresentation'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlLowerThanExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlLowerThanExpression * object = (const cPtr_gtlLowerThanExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLowerThanExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 670)).add_operation (GALGAS_string (" < "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 670)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 670)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 670)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlLowerThanExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlLowerThanExpression.mSlotID,
                                             extensionGetter_gtlLowerThanExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlLowerThanExpression_stringRepresentation (defineExtensionGetter_gtlLowerThanExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Overriding extension getter '@gtlModulusExpression stringRepresentation'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlModulusExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlModulusExpression * object = (const cPtr_gtlModulusExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlModulusExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 677)).add_operation (GALGAS_string (" mod "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 677)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 677)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 677)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlModulusExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlModulusExpression.mSlotID,
                                             extensionGetter_gtlModulusExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlModulusExpression_stringRepresentation (defineExtensionGetter_gtlModulusExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Overriding extension getter '@gtlMultiplyExpression stringRepresentation'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlMultiplyExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlMultiplyExpression * object = (const cPtr_gtlMultiplyExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMultiplyExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 684)).add_operation (GALGAS_string (" * "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 684)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 684)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 684)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlMultiplyExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlMultiplyExpression.mSlotID,
                                             extensionGetter_gtlMultiplyExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlMultiplyExpression_stringRepresentation (defineExtensionGetter_gtlMultiplyExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Overriding extension getter '@gtlNotEqualExpression stringRepresentation'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlNotEqualExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlNotEqualExpression * object = (const cPtr_gtlNotEqualExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlNotEqualExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 691)).add_operation (GALGAS_string (" != "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 691)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 691)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 691)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlNotEqualExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlNotEqualExpression.mSlotID,
                                             extensionGetter_gtlNotEqualExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlNotEqualExpression_stringRepresentation (defineExtensionGetter_gtlNotEqualExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension getter '@gtlOrExpression stringRepresentation'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlOrExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlOrExpression * object = (const cPtr_gtlOrExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlOrExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 698)).add_operation (GALGAS_string (" | "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 698)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 698)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 698)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlOrExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlOrExpression.mSlotID,
                                             extensionGetter_gtlOrExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlOrExpression_stringRepresentation (defineExtensionGetter_gtlOrExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension getter '@gtlShiftLeftExpression stringRepresentation'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlShiftLeftExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlShiftLeftExpression * object = (const cPtr_gtlShiftLeftExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlShiftLeftExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 705)).add_operation (GALGAS_string (" << "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 705)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 705)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 705)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlShiftLeftExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlShiftLeftExpression.mSlotID,
                                             extensionGetter_gtlShiftLeftExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlShiftLeftExpression_stringRepresentation (defineExtensionGetter_gtlShiftLeftExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension getter '@gtlShiftRightExpression stringRepresentation'                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlShiftRightExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlShiftRightExpression * object = (const cPtr_gtlShiftRightExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlShiftRightExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 712)).add_operation (GALGAS_string (" >> "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 712)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 712)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 712)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlShiftRightExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlShiftRightExpression.mSlotID,
                                             extensionGetter_gtlShiftRightExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlShiftRightExpression_stringRepresentation (defineExtensionGetter_gtlShiftRightExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension getter '@gtlSubstractExpression stringRepresentation'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlSubstractExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlSubstractExpression * object = (const cPtr_gtlSubstractExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSubstractExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 719)).add_operation (GALGAS_string (" - "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 719)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 719)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 719)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlSubstractExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlSubstractExpression.mSlotID,
                                             extensionGetter_gtlSubstractExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlSubstractExpression_stringRepresentation (defineExtensionGetter_gtlSubstractExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension getter '@gtlXorExpression stringRepresentation'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlXorExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlXorExpression * object = (const cPtr_gtlXorExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlXorExpression) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 726)).add_operation (GALGAS_string (" ^ "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 726)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 726)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 726)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlXorExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlXorExpression.mSlotID,
                                             extensionGetter_gtlXorExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlXorExpression_stringRepresentation (defineExtensionGetter_gtlXorExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension getter '@gtlExistsExpression stringRepresentation'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlExistsExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlExistsExpression * object = (const cPtr_gtlExistsExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlExistsExpression) ;
  result_result = GALGAS_string ("exists ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_variable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 733)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 733)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlExistsExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlExistsExpression.mSlotID,
                                             extensionGetter_gtlExistsExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlExistsExpression_stringRepresentation (defineExtensionGetter_gtlExistsExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   Overriding extension getter '@gtlExistsDefaultExpression stringRepresentation'                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlExistsDefaultExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlExistsDefaultExpression * object = (const cPtr_gtlExistsDefaultExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlExistsDefaultExpression) ;
  result_result = GALGAS_string ("exists ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_variable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 741)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 740)).add_operation (GALGAS_string (" default ( "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 741)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_defaultValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 743)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 742)).add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 743)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlExistsDefaultExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlExistsDefaultExpression.mSlotID,
                                             extensionGetter_gtlExistsDefaultExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlExistsDefaultExpression_stringRepresentation (defineExtensionGetter_gtlExistsDefaultExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    Overriding extension getter '@gtlFunctionCallExpression stringRepresentation'                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlFunctionCallExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlFunctionCallExpression * object = (const cPtr_gtlFunctionCallExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFunctionCallExpression) ;
  result_result = object->mAttribute_functionName.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 751)).add_operation (GALGAS_string ("("), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 751)).add_operation (extensionGetter_stringRepresentation (object->mAttribute_functionArguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 751)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 751)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 751)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFunctionCallExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlFunctionCallExpression.mSlotID,
                                             extensionGetter_gtlFunctionCallExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFunctionCallExpression_stringRepresentation (defineExtensionGetter_gtlFunctionCallExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension getter '@gtlGetterCallExpression stringRepresentation'                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlGetterCallExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlGetterCallExpression * object = (const cPtr_gtlGetterCallExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlGetterCallExpression) ;
  result_result = GALGAS_string ("[").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_target.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 758)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 758)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 758)).add_operation (object->mAttribute_getterName.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 758)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 758)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, object->mAttribute_arguments.getter_length (SOURCE_FILE ("gtl_debugger.galgas", 759)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = result_result.add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 760)).add_operation (extensionGetter_stringRepresentation (object->mAttribute_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 760)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 760)) ;
  }
  result_result = result_result.add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 762)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlGetterCallExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlGetterCallExpression.mSlotID,
                                             extensionGetter_gtlGetterCallExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlGetterCallExpression_stringRepresentation (defineExtensionGetter_gtlGetterCallExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension getter '@gtlListOfExpression stringRepresentation'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlListOfExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlListOfExpression * object = (const cPtr_gtlListOfExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlListOfExpression) ;
  result_result = GALGAS_string ("listof ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_expression.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 769)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 769)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlListOfExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlListOfExpression.mSlotID,
                                             extensionGetter_gtlListOfExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlListOfExpression_stringRepresentation (defineExtensionGetter_gtlListOfExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    Overriding extension getter '@gtlLiteralListExpression stringRepresentation'                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlLiteralListExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlLiteralListExpression * object = (const cPtr_gtlLiteralListExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLiteralListExpression) ;
  result_result = GALGAS_string ("@( ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 776)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 776)).add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 776)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlLiteralListExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlLiteralListExpression.mSlotID,
                                             extensionGetter_gtlLiteralListExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlLiteralListExpression_stringRepresentation (defineExtensionGetter_gtlLiteralListExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension getter '@gtlLiteralMapExpression stringRepresentation'                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlLiteralMapExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlLiteralMapExpression * object = (const cPtr_gtlLiteralMapExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLiteralMapExpression) ;
  result_result = GALGAS_string ("@[ ").add_operation (extensionGetter_mapRepresentation (object->mAttribute_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 783)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 783)).add_operation (GALGAS_string (" ]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 783)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlLiteralMapExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlLiteralMapExpression.mSlotID,
                                             extensionGetter_gtlLiteralMapExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlLiteralMapExpression_stringRepresentation (defineExtensionGetter_gtlLiteralMapExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension getter '@gtlLiteralSetExpression stringRepresentation'                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlLiteralSetExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlLiteralSetExpression * object = (const cPtr_gtlLiteralSetExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLiteralSetExpression) ;
  result_result = GALGAS_string ("@! ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 790)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 790)).add_operation (GALGAS_string (" !"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 790)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlLiteralSetExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlLiteralSetExpression.mSlotID,
                                             extensionGetter_gtlLiteralSetExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlLiteralSetExpression_stringRepresentation (defineExtensionGetter_gtlLiteralSetExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   Overriding extension getter '@gtlLiteralStructExpression stringRepresentation'                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlLiteralStructExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlLiteralStructExpression * object = (const cPtr_gtlLiteralStructExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLiteralStructExpression) ;
  result_result = GALGAS_string ("@{ ").add_operation (extensionGetter_structRepresentation (object->mAttribute_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 797)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 797)).add_operation (GALGAS_string (" }"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 797)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlLiteralStructExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlLiteralStructExpression.mSlotID,
                                             extensionGetter_gtlLiteralStructExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlLiteralStructExpression_stringRepresentation (defineExtensionGetter_gtlLiteralStructExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    Overriding extension getter '@gtlMapOfStructExpression stringRepresentation'                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlMapOfStructExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlMapOfStructExpression * object = (const cPtr_gtlMapOfStructExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMapOfStructExpression) ;
  result_result = GALGAS_string ("mapof ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_expression.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 804)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 804)).add_operation (GALGAS_string (" end"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 804)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlMapOfStructExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlMapOfStructExpression.mSlotID,
                                             extensionGetter_gtlMapOfStructExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlMapOfStructExpression_stringRepresentation (defineExtensionGetter_gtlMapOfStructExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension getter '@gtlTerminal stringRepresentation'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlTerminal_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlTerminal * object = (const cPtr_gtlTerminal *) inObject ;
  macroValidSharedObject (object, cPtr_gtlTerminal) ;
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlData *) object->mAttribute_value.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 811)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlTerminal_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlTerminal.mSlotID,
                                             extensionGetter_gtlTerminal_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlTerminal_stringRepresentation (defineExtensionGetter_gtlTerminal_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension getter '@gtlTypeOfExpression stringRepresentation'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlTypeOfExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlTypeOfExpression * object = (const cPtr_gtlTypeOfExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlTypeOfExpression) ;
  result_result = GALGAS_string ("typeof ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_variable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 818)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 818)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlTypeOfExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlTypeOfExpression.mSlotID,
                                             extensionGetter_gtlTypeOfExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlTypeOfExpression_stringRepresentation (defineExtensionGetter_gtlTypeOfExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension getter '@gtlMinusExpression stringRepresentation'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlMinusExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlMinusExpression * object = (const cPtr_gtlMinusExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMinusExpression) ;
  result_result = GALGAS_string ("-").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_son.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 825)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 825)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlMinusExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlMinusExpression.mSlotID,
                                             extensionGetter_gtlMinusExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlMinusExpression_stringRepresentation (defineExtensionGetter_gtlMinusExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension getter '@gtlNotExpression stringRepresentation'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlNotExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlNotExpression * object = (const cPtr_gtlNotExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlNotExpression) ;
  result_result = GALGAS_string ("not ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_son.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 832)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 832)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlNotExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlNotExpression.mSlotID,
                                             extensionGetter_gtlNotExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlNotExpression_stringRepresentation (defineExtensionGetter_gtlNotExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   Overriding extension getter '@gtlParenthesizedExpression stringRepresentation'                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlParenthesizedExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlParenthesizedExpression * object = (const cPtr_gtlParenthesizedExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlParenthesizedExpression) ;
  result_result = GALGAS_string ("(").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_son.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 839)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 839)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 839)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlParenthesizedExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlParenthesizedExpression.mSlotID,
                                             extensionGetter_gtlParenthesizedExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlParenthesizedExpression_stringRepresentation (defineExtensionGetter_gtlParenthesizedExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension getter '@gtlPlusExpression stringRepresentation'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlPlusExpression_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlPlusExpression * object = (const cPtr_gtlPlusExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlPlusExpression) ;
  result_result = GALGAS_string ("+").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_son.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 846)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 846)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlPlusExpression_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlPlusExpression.mSlotID,
                                             extensionGetter_gtlPlusExpression_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlPlusExpression_stringRepresentation (defineExtensionGetter_gtlPlusExpression_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@gtlVarRef stringRepresentation'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlVarRef_stringRepresentation (const cPtr_gtlExpression * inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlVarRef * object = (const cPtr_gtlVarRef *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarRef) ;
  result_result = extensionGetter_stringRepresentation (object->mAttribute_variableName, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 853)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarRef_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlVarRef.mSlotID,
                                             extensionGetter_gtlVarRef_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarRef_stringRepresentation (defineExtensionGetter_gtlVarRef_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlBool stringRepresentation'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlBool_stringRepresentation (const cPtr_gtlData * inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  const GALGAS_gtlBool temp_0 = object ;
  result_result = callExtensionGetter_string ((const cPtr_gtlBool *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 864)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlBool_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                                             extensionGetter_gtlBool_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlBool_stringRepresentation (defineExtensionGetter_gtlBool_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlChar stringRepresentation'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlChar_stringRepresentation (const cPtr_gtlData * inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  const GALGAS_gtlChar temp_0 = object ;
  result_result = callExtensionGetter_string ((const cPtr_gtlChar *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 871)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                             extensionGetter_gtlChar_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_stringRepresentation (defineExtensionGetter_gtlChar_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlEnum stringRepresentation'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlEnum_stringRepresentation (const cPtr_gtlData * inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  const GALGAS_gtlEnum temp_0 = object ;
  result_result = GALGAS_string ("$").add_operation (callExtensionGetter_string ((const cPtr_gtlEnum *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 878)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 878)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                             extensionGetter_gtlEnum_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_stringRepresentation (defineExtensionGetter_gtlEnum_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@gtlFloat stringRepresentation'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlFloat_stringRepresentation (const cPtr_gtlData * inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const GALGAS_gtlFloat temp_0 = object ;
  result_result = callExtensionGetter_string ((const cPtr_gtlFloat *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 885)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                             extensionGetter_gtlFloat_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_stringRepresentation (defineExtensionGetter_gtlFloat_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlInt stringRepresentation'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlInt_stringRepresentation (const cPtr_gtlData * inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const GALGAS_gtlInt temp_0 = object ;
  result_result = callExtensionGetter_string ((const cPtr_gtlInt *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 892)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                             extensionGetter_gtlInt_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_stringRepresentation (defineExtensionGetter_gtlInt_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@gtlString stringRepresentation'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlString_stringRepresentation (const cPtr_gtlData * inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  const GALGAS_gtlString temp_0 = object ;
  GALGAS_string var_literalString_27740 = callExtensionGetter_string ((const cPtr_gtlString *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 899)) ;
  var_literalString_27740 = var_literalString_27740.getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string ("\\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 900)) ;
  var_literalString_27740 = var_literalString_27740.getter_stringByReplacingStringByString (GALGAS_string ("\t"), GALGAS_string ("\\t"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 901)) ;
  var_literalString_27740 = var_literalString_27740.getter_stringByReplacingStringByString (GALGAS_string ("\f"), GALGAS_string ("\\f"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 902)) ;
  var_literalString_27740 = var_literalString_27740.getter_stringByReplacingStringByString (GALGAS_string ("\r"), GALGAS_string ("\\r"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 903)) ;
  var_literalString_27740 = var_literalString_27740.getter_stringByReplacingStringByString (GALGAS_string ("\v"), GALGAS_string ("\\v"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 904)) ;
  var_literalString_27740 = var_literalString_27740.getter_stringByReplacingStringByString (GALGAS_string ("\\"), GALGAS_string ("\\\\"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 905)) ;
  var_literalString_27740 = var_literalString_27740.getter_stringByReplacingStringByString (GALGAS_string ("\""), GALGAS_string ("\\\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 906)) ;
  result_result = GALGAS_string ("\"").add_operation (var_literalString_27740, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 907)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 907)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlString_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                                             extensionGetter_gtlString_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlString_stringRepresentation (defineExtensionGetter_gtlString_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension getter '@gtlUnconstructed stringRepresentation'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlUnconstructed_stringRepresentation (const cPtr_gtlData * /* inObject */,
                                                                            C_Compiler * /* inCompiler */
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("*UNCONSTRUCTED*") ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                             extensionGetter_gtlUnconstructed_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_stringRepresentation (defineExtensionGetter_gtlUnconstructed_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlType stringRepresentation'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlType_stringRepresentation (const cPtr_gtlData * inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  const GALGAS_gtlType temp_0 = object ;
  result_result = GALGAS_string ("@").add_operation (callExtensionGetter_string ((const cPtr_gtlType *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 921)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 921)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                             extensionGetter_gtlType_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_stringRepresentation (defineExtensionGetter_gtlType_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlList stringRepresentation'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlList_stringRepresentation (const cPtr_gtlData * inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlList * object = (const cPtr_gtlList *) inObject ;
  macroValidSharedObject (object, cPtr_gtlList) ;
  result_result = GALGAS_string ("@( ") ;
  cEnumerator_list enumerator_28921 (object->mAttribute_value, kEnumeration_up) ;
  while (enumerator_28921.hasCurrentObject ()) {
    result_result = result_result.add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlData *) enumerator_28921.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 930)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 930)) ;
    if (enumerator_28921.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 932)) ;
    }
    enumerator_28921.gotoNextObject () ;
  }
  result_result = result_result.add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 934)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlList_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlList.mSlotID,
                                             extensionGetter_gtlList_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlList_stringRepresentation (defineExtensionGetter_gtlList_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlMap stringRepresentation'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlMap_stringRepresentation (const cPtr_gtlData * inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlMap * object = (const cPtr_gtlMap *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMap) ;
  result_result = GALGAS_string ("@[ ") ;
  cEnumerator_gtlVarMap enumerator_29234 (object->mAttribute_value, kEnumeration_up) ;
  while (enumerator_29234.hasCurrentObject ()) {
    result_result = result_result.add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 943)).add_operation (enumerator_29234.current_lkey (HERE).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 943)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 943)).add_operation (GALGAS_string ("\": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 943)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlData *) enumerator_29234.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 943)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 943)) ;
    if (enumerator_29234.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 945)) ;
    }
    enumerator_29234.gotoNextObject () ;
  }
  result_result = result_result.add_operation (GALGAS_string (" ]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 947)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlMap_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlMap.mSlotID,
                                             extensionGetter_gtlMap_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlMap_stringRepresentation (defineExtensionGetter_gtlMap_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@gtlStruct stringRepresentation'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlStruct_stringRepresentation (const cPtr_gtlData * inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlStruct * object = (const cPtr_gtlStruct *) inObject ;
  macroValidSharedObject (object, cPtr_gtlStruct) ;
  result_result = GALGAS_string ("@{ ") ;
  cEnumerator_gtlVarMap enumerator_29574 (object->mAttribute_value, kEnumeration_up) ;
  while (enumerator_29574.hasCurrentObject ()) {
    result_result = result_result.add_operation (enumerator_29574.current_lkey (HERE).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 956)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 956)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 956)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlData *) enumerator_29574.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 956)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 956)) ;
    if (enumerator_29574.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 958)) ;
    }
    enumerator_29574.gotoNextObject () ;
  }
  result_result = result_result.add_operation (GALGAS_string (" }"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 960)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlStruct_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlStruct.mSlotID,
                                             extensionGetter_gtlStruct_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlStruct_stringRepresentation (defineExtensionGetter_gtlStruct_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlSet stringRepresentation'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlSet_stringRepresentation (const cPtr_gtlData * inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  result_result = GALGAS_string ("@! ") ;
  cEnumerator_stringset enumerator_29898 (object->mAttribute_value, kEnumeration_up) ;
  while (enumerator_29898.hasCurrentObject ()) {
    result_result = result_result.add_operation (enumerator_29898.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 969)) ;
    if (enumerator_29898.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 971)) ;
    }
    enumerator_29898.gotoNextObject () ;
  }
  result_result = result_result.add_operation (GALGAS_string (" !"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 973)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlSet_stringRepresentation (void) {
  enterExtensionGetter_stringRepresentation (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                                             extensionGetter_gtlSet_stringRepresentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlSet_stringRepresentation (defineExtensionGetter_gtlSet_stringRepresentation, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@gtlLetUnconstructedInstruction display'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLetUnconstructedInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLetUnconstructedInstruction * object = (const cPtr_gtlLetUnconstructedInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLetUnconstructedInstruction) ;
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1072)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1072))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1072)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLetUnconstructedInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLetUnconstructedInstruction.mSlotID,
                                extensionMethod_gtlLetUnconstructedInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLetUnconstructedInstruction_display (defineExtensionMethod_gtlLetUnconstructedInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@gtlLetInstruction display'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLetInstruction_display (const cPtr_gtlInstruction * inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLetInstruction * object = (const cPtr_gtlLetInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLetInstruction) ;
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1079)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1078)).add_operation (GALGAS_string (" := "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1079)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1081)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1080))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1078)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLetInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLetInstruction.mSlotID,
                                extensionMethod_gtlLetInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLetInstruction_display (defineExtensionMethod_gtlLetInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@gtlLetAddInstruction display'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLetAddInstruction_display (const cPtr_gtlInstruction * inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLetAddInstruction * object = (const cPtr_gtlLetAddInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLetAddInstruction) ;
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1088)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1087)).add_operation (GALGAS_string (" += "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1088)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1090)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1089))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1087)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLetAddInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLetAddInstruction.mSlotID,
                                extensionMethod_gtlLetAddInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLetAddInstruction_display (defineExtensionMethod_gtlLetAddInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@gtlLetSubstractInstruction display'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLetSubstractInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLetSubstractInstruction * object = (const cPtr_gtlLetSubstractInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLetSubstractInstruction) ;
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1097)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1096)).add_operation (GALGAS_string (" -= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1097)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1099)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1098))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1096)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLetSubstractInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLetSubstractInstruction.mSlotID,
                                extensionMethod_gtlLetSubstractInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLetSubstractInstruction_display (defineExtensionMethod_gtlLetSubstractInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@gtlLetMultiplyInstruction display'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLetMultiplyInstruction_display (const cPtr_gtlInstruction * inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLetMultiplyInstruction * object = (const cPtr_gtlLetMultiplyInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLetMultiplyInstruction) ;
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1106)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1105)).add_operation (GALGAS_string (" *= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1106)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1108)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1107))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1105)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLetMultiplyInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLetMultiplyInstruction.mSlotID,
                                extensionMethod_gtlLetMultiplyInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLetMultiplyInstruction_display (defineExtensionMethod_gtlLetMultiplyInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@gtlLetDivideInstruction display'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLetDivideInstruction_display (const cPtr_gtlInstruction * inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLetDivideInstruction * object = (const cPtr_gtlLetDivideInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLetDivideInstruction) ;
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1115)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1114)).add_operation (GALGAS_string (" /= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1115)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1117)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1116))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1114)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLetDivideInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLetDivideInstruction.mSlotID,
                                extensionMethod_gtlLetDivideInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLetDivideInstruction_display (defineExtensionMethod_gtlLetDivideInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@gtlLetModuloInstruction display'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLetModuloInstruction_display (const cPtr_gtlInstruction * inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLetModuloInstruction * object = (const cPtr_gtlLetModuloInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLetModuloInstruction) ;
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1124)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1123)).add_operation (GALGAS_string (" mod= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1124)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1126)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1125))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1123)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLetModuloInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLetModuloInstruction.mSlotID,
                                extensionMethod_gtlLetModuloInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLetModuloInstruction_display (defineExtensionMethod_gtlLetModuloInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@gtlLetShiftLeftInstruction display'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLetShiftLeftInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLetShiftLeftInstruction * object = (const cPtr_gtlLetShiftLeftInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLetShiftLeftInstruction) ;
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1133)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1132)).add_operation (GALGAS_string (" <<= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1133)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1135)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1134))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1132)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLetShiftLeftInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLetShiftLeftInstruction.mSlotID,
                                extensionMethod_gtlLetShiftLeftInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLetShiftLeftInstruction_display (defineExtensionMethod_gtlLetShiftLeftInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlLetShiftRightInstruction display'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLetShiftRightInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLetShiftRightInstruction * object = (const cPtr_gtlLetShiftRightInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLetShiftRightInstruction) ;
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1142)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1141)).add_operation (GALGAS_string (" >>= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1142)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1144)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1143))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1141)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLetShiftRightInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLetShiftRightInstruction.mSlotID,
                                extensionMethod_gtlLetShiftRightInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLetShiftRightInstruction_display (defineExtensionMethod_gtlLetShiftRightInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@gtlLetAndInstruction display'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLetAndInstruction_display (const cPtr_gtlInstruction * inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLetAndInstruction * object = (const cPtr_gtlLetAndInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLetAndInstruction) ;
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1151)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1150)).add_operation (GALGAS_string (" &= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1151)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1153)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1152))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1150)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLetAndInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLetAndInstruction.mSlotID,
                                extensionMethod_gtlLetAndInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLetAndInstruction_display (defineExtensionMethod_gtlLetAndInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@gtlLetOrInstruction display'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLetOrInstruction_display (const cPtr_gtlInstruction * inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLetOrInstruction * object = (const cPtr_gtlLetOrInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLetOrInstruction) ;
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1160)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1159)).add_operation (GALGAS_string (" |= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1160)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1162)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1161))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1159)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLetOrInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLetOrInstruction.mSlotID,
                                extensionMethod_gtlLetOrInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLetOrInstruction_display (defineExtensionMethod_gtlLetOrInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@gtlLetXorInstruction display'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLetXorInstruction_display (const cPtr_gtlInstruction * inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLetXorInstruction * object = (const cPtr_gtlLetXorInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLetXorInstruction) ;
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1169)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1168)).add_operation (GALGAS_string (" ^= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1169)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1171)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1170))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1168)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLetXorInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLetXorInstruction.mSlotID,
                                extensionMethod_gtlLetXorInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLetXorInstruction_display (defineExtensionMethod_gtlLetXorInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlLoopStatementInstruction display'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLoopStatementInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLoopStatementInstruction * object = (const cPtr_gtlLoopStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLoopStatementInstruction) ;
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, object->mAttribute_upDown.objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1181)).getter_sint_36__34_ (SOURCE_FILE ("gtl_debugger.galgas", 1181)))).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string (" down") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string::makeEmptyString () ;
  }
  inCompiler->printMessage (GALGAS_string ("loop ").add_operation (object->mAttribute_identifier.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1177)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1177)).add_operation (GALGAS_string (" from "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1178)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_start.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1180)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1179)).add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1180)).add_operation (GALGAS_string (" to "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1181)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_stop.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1183)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1182)).add_operation (GALGAS_string (" step "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1183)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_step.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1185)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1184)).add_operation (GALGAS_string (" do"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1185))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1177)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLoopStatementInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLoopStatementInstruction.mSlotID,
                                extensionMethod_gtlLoopStatementInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLoopStatementInstruction_display (defineExtensionMethod_gtlLoopStatementInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@gtlWarningStatementInstruction display'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWarningStatementInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlWarningStatementInstruction * object = (const cPtr_gtlWarningStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlWarningStatementInstruction) ;
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = object->mAttribute_hereInstead.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string ("here") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = extensionGetter_stringRepresentation (object->mAttribute_identifier, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1193)) ;
  }
  inCompiler->printMessage (GALGAS_string ("warning ").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1192)).add_operation (GALGAS_string (" : "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1193)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_warningMessage.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1195)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1194))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1192)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWarningStatementInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlWarningStatementInstruction.mSlotID,
                                extensionMethod_gtlWarningStatementInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWarningStatementInstruction_display (defineExtensionMethod_gtlWarningStatementInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlErrorStatementInstruction display'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlErrorStatementInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlErrorStatementInstruction * object = (const cPtr_gtlErrorStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlErrorStatementInstruction) ;
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = object->mAttribute_hereInstead.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string ("here") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = extensionGetter_stringRepresentation (object->mAttribute_identifier, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1202)) ;
  }
  inCompiler->printMessage (GALGAS_string ("error ").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1201)).add_operation (GALGAS_string (" : "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1202)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_errorMessage.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1204)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1203))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1201)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlErrorStatementInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlErrorStatementInstruction.mSlotID,
                                extensionMethod_gtlErrorStatementInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlErrorStatementInstruction_display (defineExtensionMethod_gtlErrorStatementInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@gtlDisplayStatementInstruction display'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlDisplayStatementInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlDisplayStatementInstruction * object = (const cPtr_gtlDisplayStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlDisplayStatementInstruction) ;
  inCompiler->printMessage (GALGAS_string ("display ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_variablePath, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1210)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1210))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1210)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlDisplayStatementInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlDisplayStatementInstruction.mSlotID,
                                extensionMethod_gtlDisplayStatementInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlDisplayStatementInstruction_display (defineExtensionMethod_gtlDisplayStatementInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlPrintStatementInstruction display'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlPrintStatementInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlPrintStatementInstruction * object = (const cPtr_gtlPrintStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlPrintStatementInstruction) ;
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = object->mAttribute_carriageReturn.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string ("ln ") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string (" ") ;
  }
  inCompiler->printMessage (GALGAS_string ("print").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1216)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_messageToPrint.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1218)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1217))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1216)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlPrintStatementInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlPrintStatementInstruction.mSlotID,
                                extensionMethod_gtlPrintStatementInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlPrintStatementInstruction_display (defineExtensionMethod_gtlPrintStatementInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlTemplateStringInstruction display'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlTemplateStringInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlTemplateStringInstruction * object = (const cPtr_gtlTemplateStringInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlTemplateStringInstruction) ;
  inCompiler->printMessage (GALGAS_string ("%").add_operation (object->mAttribute_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1224)).add_operation (GALGAS_string ("%"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1224))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1224)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlTemplateStringInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlTemplateStringInstruction.mSlotID,
                                extensionMethod_gtlTemplateStringInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlTemplateStringInstruction_display (defineExtensionMethod_gtlTemplateStringInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlInputStatementInstruction display'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlInputStatementInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlInputStatementInstruction * object = (const cPtr_gtlInputStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInputStatementInstruction) ;
  inCompiler->printMessage (GALGAS_string ("input ( ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_formalArguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1230)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1230)).add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1230))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1230)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlInputStatementInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlInputStatementInstruction.mSlotID,
                                extensionMethod_gtlInputStatementInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlInputStatementInstruction_display (defineExtensionMethod_gtlInputStatementInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlSortStatementInstruction display'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlSortStatementInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlSortStatementInstruction * object = (const cPtr_gtlSortStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSortStatementInstruction) ;
  inCompiler->printMessage (GALGAS_string ("sort ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_variablePath, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1237)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1236)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1237)).add_operation (extensionGetter_stringRepresentation (object->mAttribute_order, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1239)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1238))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1236)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlSortStatementInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlSortStatementInstruction.mSlotID,
                                extensionMethod_gtlSortStatementInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlSortStatementInstruction_display (defineExtensionMethod_gtlSortStatementInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Overriding extension method '@gtlSortStatementStructInstruction display'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlSortStatementStructInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlSortStatementStructInstruction * object = (const cPtr_gtlSortStatementStructInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSortStatementStructInstruction) ;
  inCompiler->printMessage (GALGAS_string ("sort ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_variablePath, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1246)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1245)).add_operation (GALGAS_string (" by "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1246)).add_operation (extensionGetter_stringRepresentation (object->mAttribute_sortingKey, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1248)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1247))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1245)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlSortStatementStructInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlSortStatementStructInstruction.mSlotID,
                                extensionMethod_gtlSortStatementStructInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlSortStatementStructInstruction_display (defineExtensionMethod_gtlSortStatementStructInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@gtlTemplateInstruction display'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlTemplateInstruction_display (const cPtr_gtlInstruction * inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlTemplateInstruction * object = (const cPtr_gtlTemplateInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlTemplateInstruction) ;
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = object->mAttribute_isGlobal.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string::makeEmptyString () ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string ("( ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1255)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1255)).add_operation (GALGAS_string (" ) "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1255)) ;
  }
  GALGAS_string temp_2 ;
  const enumGalgasBool test_3 = object->mAttribute_ifExists.boolEnum () ;
  if (kBoolTrue == test_3) {
    temp_2 = GALGAS_string ("if exists ") ;
  }else if (kBoolFalse == test_3) {
    temp_2 = GALGAS_string::makeEmptyString () ;
  }
  GALGAS_string temp_4 ;
  const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, GALGAS_string::makeEmptyString ().objectCompare (object->mAttribute_prefix.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1258)))).boolEnum () ;
  if (kBoolTrue == test_5) {
    temp_4 = GALGAS_string (" ") ;
  }else if (kBoolFalse == test_5) {
    temp_4 = GALGAS_string (" in ").add_operation (object->mAttribute_prefix.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1258)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1258)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1258)) ;
  }
  GALGAS_string temp_6 ;
  const enumGalgasBool test_7 = object->mAttribute_ifExists.operator_and (GALGAS_bool (kIsStrictSup, object->mAttribute_instructionsIfNotFound.getter_length (SOURCE_FILE ("gtl_debugger.galgas", 1259)).objectCompare (GALGAS_uint ((uint32_t) 0U))) COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1259)).boolEnum () ;
  if (kBoolTrue == test_7) {
    temp_6 = GALGAS_string ("or ...") ;
  }else if (kBoolFalse == test_7) {
    temp_6 = GALGAS_string::makeEmptyString () ;
  }
  inCompiler->printMessage (GALGAS_string ("template ").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1254)).add_operation (temp_2, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1255)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_fileName.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1257)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1256)).add_operation (temp_4, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1257)).add_operation (temp_6, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1258))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1254)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlTemplateInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlTemplateInstruction.mSlotID,
                                extensionMethod_gtlTemplateInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlTemplateInstruction_display (defineExtensionMethod_gtlTemplateInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@gtlEmitInstruction display'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlEmitInstruction_display (const cPtr_gtlInstruction * inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlEmitInstruction * object = (const cPtr_gtlEmitInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEmitInstruction) ;
  inCompiler->printMessage (GALGAS_string ("! ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1265)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1265))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1265)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlEmitInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlEmitInstruction.mSlotID,
                                extensionMethod_gtlEmitInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlEmitInstruction_display (defineExtensionMethod_gtlEmitInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@gtlIfStatementInstruction display'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlIfStatementInstruction_display (const cPtr_gtlInstruction * inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlIfStatementInstruction * object = (const cPtr_gtlIfStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlIfStatementInstruction) ;
  inCompiler->printMessage (GALGAS_string ("if ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_thenElsifList.getter_conditionAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1272)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1272)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1271)).add_operation (GALGAS_string (" then"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1272))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1271)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlIfStatementInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlIfStatementInstruction.mSlotID,
                                extensionMethod_gtlIfStatementInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlIfStatementInstruction_display (defineExtensionMethod_gtlIfStatementInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@gtlForStatementInstruction display'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlForStatementInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlForStatementInstruction * object = (const cPtr_gtlForStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlForStatementInstruction) ;
  inCompiler->printMessage (GALGAS_string ("for ").add_operation (object->mAttribute_identifier.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1279)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1279)).add_operation (GALGAS_string (" in "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1280)).add_operation (extensionGetter_stringRepresentation (object->mAttribute_iterable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1282)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1281)).add_operation (GALGAS_string (" do"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1282))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1279)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlForStatementInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlForStatementInstruction.mSlotID,
                                extensionMethod_gtlForStatementInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlForStatementInstruction_display (defineExtensionMethod_gtlForStatementInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@gtlForeachStatementInstruction display'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlForeachStatementInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlForeachStatementInstruction * object = (const cPtr_gtlForeachStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlForeachStatementInstruction) ;
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, GALGAS_string::makeEmptyString ().objectCompare (object->mAttribute_keyName.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1290)))).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string::makeEmptyString () ;
  }else if (kBoolFalse == test_1) {
    temp_0 = object->mAttribute_keyName.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1290)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1290)) ;
  }
  inCompiler->printMessage (GALGAS_string ("foreach ").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1289)).add_operation (object->mAttribute_variableName.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1290)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1290)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1291)).add_operation (object->mAttribute_indexName.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1292)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1292)).add_operation (GALGAS_string (") "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1292)).add_operation (GALGAS_string (" in "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1292)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_iterable.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1294)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1293))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1289)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlForeachStatementInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlForeachStatementInstruction.mSlotID,
                                extensionMethod_gtlForeachStatementInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlForeachStatementInstruction_display (defineExtensionMethod_gtlForeachStatementInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@gtlGetColumnInstruction display'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlGetColumnInstruction_display (const cPtr_gtlInstruction * inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlGetColumnInstruction * object = (const cPtr_gtlGetColumnInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlGetColumnInstruction) ;
  inCompiler->printMessage (GALGAS_string ("\? ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_destVariable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1300)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1300))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1300)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlGetColumnInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlGetColumnInstruction.mSlotID,
                                extensionMethod_gtlGetColumnInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlGetColumnInstruction_display (defineExtensionMethod_gtlGetColumnInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@gtlLibrariesInstruction display'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLibrariesInstruction_display (const cPtr_gtlInstruction * /* inObject */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("libraries")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1306)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLibrariesInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLibrariesInstruction.mSlotID,
                                extensionMethod_gtlLibrariesInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLibrariesInstruction_display (defineExtensionMethod_gtlLibrariesInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@gtlRepeatStatementInstruction display'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlRepeatStatementInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlRepeatStatementInstruction * object = (const cPtr_gtlRepeatStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlRepeatStatementInstruction) ;
  inCompiler->printMessage (GALGAS_string ("repeat ")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1312)) ;
  if (object->mAttribute_limit.isValid ()) {
    if (object->mAttribute_limit.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlTerminal) {
      GALGAS_gtlTerminal cast_39448_term ((cPtr_gtlTerminal *) object->mAttribute_limit.ptr ()) ;
      if (cast_39448_term.getter_value (SOURCE_FILE ("gtl_debugger.galgas", 1315)).isValid ()) {
        if (cast_39448_term.getter_value (SOURCE_FILE ("gtl_debugger.galgas", 1315)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
          GALGAS_gtlInt cast_39500_intLimit ((cPtr_gtlInt *) cast_39448_term.getter_value (SOURCE_FILE ("gtl_debugger.galgas", 1315)).ptr ()) ;
          const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, cast_39500_intLimit.getter_value (SOURCE_FILE ("gtl_debugger.galgas", 1317)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1317)).objectCompare (GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_debugger.galgas", 1317)))).boolEnum () ;
          if (kBoolTrue == test_0) {
            inCompiler->printMessage (GALGAS_string (" (").add_operation (callExtensionGetter_string ((const cPtr_gtlInt *) cast_39500_intLimit.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1318)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1318)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1318))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1318)) ;
          }
        }
      }
    }else{
      inCompiler->printMessage (GALGAS_string (" (").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_limit.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1322)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1322)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1322))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1322)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlRepeatStatementInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlRepeatStatementInstruction.mSlotID,
                                extensionMethod_gtlRepeatStatementInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlRepeatStatementInstruction_display (defineExtensionMethod_gtlRepeatStatementInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@gtlSetterCallInstruction display'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlSetterCallInstruction_display (const cPtr_gtlInstruction * inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlSetterCallInstruction * object = (const cPtr_gtlSetterCallInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSetterCallInstruction) ;
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, object->mAttribute_arguments.getter_length (SOURCE_FILE ("gtl_debugger.galgas", 1332)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string (": ").add_operation (extensionGetter_stringRepresentation (object->mAttribute_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1333)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1333)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1333)) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string ("]") ;
  }
  inCompiler->printMessage (GALGAS_string ("[!").add_operation (extensionGetter_stringRepresentation (object->mAttribute_target, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1330)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1329)).add_operation (object->mAttribute_setterName.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1330)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1330)).add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1331))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1329)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlSetterCallInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlSetterCallInstruction.mSlotID,
                                extensionMethod_gtlSetterCallInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlSetterCallInstruction_display (defineExtensionMethod_gtlSetterCallInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@gtlVariablesInstruction display'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlVariablesInstruction_display (const cPtr_gtlInstruction * /* inObject */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("variables")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1342)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlVariablesInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlVariablesInstruction.mSlotID,
                                extensionMethod_gtlVariablesInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlVariablesInstruction_display (defineExtensionMethod_gtlVariablesInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@gtlWriteToInstruction display'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWriteToInstruction_display (const cPtr_gtlInstruction * inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlWriteToInstruction * object = (const cPtr_gtlWriteToInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlWriteToInstruction) ;
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = object->mAttribute_isExecutable.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string ("executable ") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string::makeEmptyString () ;
  }
  inCompiler->printMessage (GALGAS_string ("write to ").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1348)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_fileNameExpression.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1350)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1349)).add_operation (GALGAS_string (" :"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1350))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1348)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWriteToInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlWriteToInstruction.mSlotID,
                                extensionMethod_gtlWriteToInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWriteToInstruction_display (defineExtensionMethod_gtlWriteToInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@gtlTabStatementInstruction display'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlTabStatementInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlTabStatementInstruction * object = (const cPtr_gtlTabStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlTabStatementInstruction) ;
  inCompiler->printMessage (GALGAS_string ("tab ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mAttribute_tabValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1358)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1358))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1358)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlTabStatementInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlTabStatementInstruction.mSlotID,
                                extensionMethod_gtlTabStatementInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlTabStatementInstruction_display (defineExtensionMethod_gtlTabStatementInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                Overriding extension getter '@gtlDisplayStatementInstruction mayExecuteWithoutError'                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlDisplayStatementInstruction_mayExecuteWithoutError (const cPtr_gtlInstruction * inObject,
                                                                                          const GALGAS_gtlContext & constinArgument_exeContext,
                                                                                          const GALGAS_gtlData & constinArgument_context,
                                                                                          const GALGAS_library & constinArgument_lib,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_may ; // Returned variable
  const cPtr_gtlDisplayStatementInstruction * object = (const cPtr_gtlDisplayStatementInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlDisplayStatementInstruction) ;
  result_may = extensionGetter_exists (object->mAttribute_variablePath, constinArgument_exeContext, constinArgument_context, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1379)) ;
//---
  return result_may ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlDisplayStatementInstruction_mayExecuteWithoutError (void) {
  enterExtensionGetter_mayExecuteWithoutError (kTypeDescriptor_GALGAS_gtlDisplayStatementInstruction.mSlotID,
                                               extensionGetter_gtlDisplayStatementInstruction_mayExecuteWithoutError) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlDisplayStatementInstruction_mayExecuteWithoutError (defineExtensionGetter_gtlDisplayStatementInstruction_mayExecuteWithoutError, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@gtlStepInstruction execute'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlStepInstruction_execute (const cPtr_gtlInstruction * /* inObject */,
                                                        GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & /* ioArgument_vars */,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_41612 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setLoopOnCommand ((cPtr_gtlContext *) ptr_41612, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1393)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlStepInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlStepInstruction.mSlotID,
                                extensionMethod_gtlStepInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlStepInstruction_execute (defineExtensionMethod_gtlStepInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@gtlDoInstInstruction execute'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlDoInstInstruction_execute (const cPtr_gtlInstruction * inObject,
                                                          GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & /* ioArgument_vars */,
                                                          GALGAS_library & /* ioArgument_lib */,
                                                          GALGAS_string & /* ioArgument_outputString */,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlDoInstInstruction * object = (const cPtr_gtlDoInstInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlDoInstInstruction) ;
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_42110 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_appendInstructionToStepDo ((cPtr_gtlContext *) ptr_42110, object->mAttribute_instructionToDo, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1410)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlDoInstInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlDoInstInstruction.mSlotID,
                                extensionMethod_gtlDoInstInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlDoInstInstruction_execute (defineExtensionMethod_gtlDoInstInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@gtlDoNotInstruction execute'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlDoNotInstruction_execute (const cPtr_gtlInstruction * inObject,
                                                         GALGAS_gtlContext & ioArgument_context,
                                                         GALGAS_gtlData & /* ioArgument_vars */,
                                                         GALGAS_library & /* ioArgument_lib */,
                                                         GALGAS_string & /* ioArgument_outputString */,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlDoNotInstruction * object = (const cPtr_gtlDoNotInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlDoNotInstruction) ;
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_42609 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteStepDoInstruction ((cPtr_gtlContext *) ptr_42609, object->mAttribute_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1427)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlDoNotInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlDoNotInstruction.mSlotID,
                                extensionMethod_gtlDoNotInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlDoNotInstruction_execute (defineExtensionMethod_gtlDoNotInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension method '@gtlDoInstruction execute'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlDoInstruction_execute (const cPtr_gtlInstruction * /* inObject */,
                                                      GALGAS_gtlContext & ioArgument_context,
                                                      GALGAS_gtlData & /* ioArgument_vars */,
                                                      GALGAS_library & /* ioArgument_lib */,
                                                      GALGAS_string & /* ioArgument_outputString */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listStepDoInstructions ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1443)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlDoInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlDoInstruction.mSlotID,
                                extensionMethod_gtlDoInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlDoInstruction_execute (defineExtensionMethod_gtlDoInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@gtlContinueInstruction execute'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlContinueInstruction_execute (const cPtr_gtlInstruction * /* inObject */,
                                                            GALGAS_gtlContext & ioArgument_context,
                                                            GALGAS_gtlData & /* ioArgument_vars */,
                                                            GALGAS_library & /* ioArgument_lib */,
                                                            GALGAS_string & /* ioArgument_outputString */,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_43521 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setBreakOnNext ((cPtr_gtlContext *) ptr_43521, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1459)) ;
  }
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_43557 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setLoopOnCommand ((cPtr_gtlContext *) ptr_43557, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1460)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlContinueInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlContinueInstruction.mSlotID,
                                extensionMethod_gtlContinueInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlContinueInstruction_execute (defineExtensionMethod_gtlContinueInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@gtlBreakpointInstruction execute'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlBreakpointInstruction_execute (const cPtr_gtlInstruction * inObject,
                                                              GALGAS_gtlContext & ioArgument_context,
                                                              GALGAS_gtlData & /* ioArgument_vars */,
                                                              GALGAS_library & /* ioArgument_lib */,
                                                              GALGAS_string & /* ioArgument_outputString */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlBreakpointInstruction * object = (const cPtr_gtlBreakpointInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBreakpointInstruction) ;
  GALGAS_gtlInstructionList var_instructionList_44075 = ioArgument_context.getter_debuggerContext (SOURCE_FILE ("gtl_debugger.galgas", 1478)).getter_instructionList (SOURCE_FILE ("gtl_debugger.galgas", 1478)) ;
  GALGAS_string var_localFileName_44145 = GALGAS_string::makeEmptyString () ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_instructionList_44075.getter_length (SOURCE_FILE ("gtl_debugger.galgas", 1480)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_localFileName_44145 = callExtensionGetter_location ((const cPtr_gtlInstruction *) var_instructionList_44075.getter_instructionAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1482)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1482)).getter_file (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1482)).getter_lastPathComponent (SOURCE_FILE ("gtl_debugger.galgas", 1483)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, object->mAttribute_fileName.objectCompare (var_localFileName_44145)).operator_or (GALGAS_bool (kIsEqual, object->mAttribute_fileName.objectCompare (GALGAS_string::makeEmptyString ())) COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1485)).boolEnum () ;
    if (kBoolTrue == test_1) {
      inCompiler->printMessage (GALGAS_string ("Setting breakpoint at ").add_operation (var_localFileName_44145, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1486)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1486)).add_operation (object->mAttribute_lineNum.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1486)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1486)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1486))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1486)) ;
      {
      ioArgument_context.insulate (HERE) ;
      cPtr_gtlContext * ptr_44455 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
      callExtensionSetter_setBreakpoint ((cPtr_gtlContext *) ptr_44455, var_localFileName_44145, object->mAttribute_lineNum, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1487)) ;
      }
    }else if (kBoolFalse == test_1) {
      inCompiler->printMessage (GALGAS_string ("Setting breakpoint at ").add_operation (object->mAttribute_fileName, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1489)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1489)).add_operation (object->mAttribute_lineNum.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1489)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1489)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1489))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1489)) ;
      {
      ioArgument_context.insulate (HERE) ;
      cPtr_gtlContext * ptr_44598 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
      callExtensionSetter_setBreakpoint ((cPtr_gtlContext *) ptr_44598, object->mAttribute_fileName, object->mAttribute_lineNum, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1490)) ;
      }
    }
  }else if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("Unable to set a breakpoint in an empty file\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1493)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlBreakpointInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlBreakpointInstruction.mSlotID,
                                extensionMethod_gtlBreakpointInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlBreakpointInstruction_execute (defineExtensionMethod_gtlBreakpointInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlBreakpointListInstruction execute'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlBreakpointListInstruction_execute (const cPtr_gtlInstruction * /* inObject */,
                                                                  GALGAS_gtlContext & ioArgument_context,
                                                                  GALGAS_gtlData & /* ioArgument_vars */,
                                                                  GALGAS_library & /* ioArgument_lib */,
                                                                  GALGAS_string & /* ioArgument_outputString */,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listBreakpoints ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1510)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlBreakpointListInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlBreakpointListInstruction.mSlotID,
                                extensionMethod_gtlBreakpointListInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlBreakpointListInstruction_execute (defineExtensionMethod_gtlBreakpointListInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@gtlBreakpointDeleteInstruction execute'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlBreakpointDeleteInstruction_execute (const cPtr_gtlInstruction * inObject,
                                                                    GALGAS_gtlContext & ioArgument_context,
                                                                    GALGAS_gtlData & /* ioArgument_vars */,
                                                                    GALGAS_library & /* ioArgument_lib */,
                                                                    GALGAS_string & /* ioArgument_outputString */,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlBreakpointDeleteInstruction * object = (const cPtr_gtlBreakpointDeleteInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBreakpointDeleteInstruction) ;
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_45666 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteBreakpoint ((cPtr_gtlContext *) ptr_45666, object->mAttribute_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1527)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlBreakpointDeleteInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlBreakpointDeleteInstruction.mSlotID,
                                extensionMethod_gtlBreakpointDeleteInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlBreakpointDeleteInstruction_execute (defineExtensionMethod_gtlBreakpointDeleteInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@gtlWatchpointInstruction execute'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWatchpointInstruction_execute (const cPtr_gtlInstruction * inObject,
                                                              GALGAS_gtlContext & ioArgument_context,
                                                              GALGAS_gtlData & /* ioArgument_vars */,
                                                              GALGAS_library & /* ioArgument_lib */,
                                                              GALGAS_string & /* ioArgument_outputString */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlWatchpointInstruction * object = (const cPtr_gtlWatchpointInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlWatchpointInstruction) ;
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_46177 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setWatchpoint ((cPtr_gtlContext *) ptr_46177, object->mAttribute_watchExpression, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1544)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWatchpointInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlWatchpointInstruction.mSlotID,
                                extensionMethod_gtlWatchpointInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWatchpointInstruction_execute (defineExtensionMethod_gtlWatchpointInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlWatchpointListInstruction execute'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWatchpointListInstruction_execute (const cPtr_gtlInstruction * /* inObject */,
                                                                  GALGAS_gtlContext & ioArgument_context,
                                                                  GALGAS_gtlData & /* ioArgument_vars */,
                                                                  GALGAS_library & /* ioArgument_lib */,
                                                                  GALGAS_string & /* ioArgument_outputString */,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listWatchpoints ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1560)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWatchpointListInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlWatchpointListInstruction.mSlotID,
                                extensionMethod_gtlWatchpointListInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWatchpointListInstruction_execute (defineExtensionMethod_gtlWatchpointListInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@gtlWatchpointDeleteInstruction execute'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWatchpointDeleteInstruction_execute (const cPtr_gtlInstruction * inObject,
                                                                    GALGAS_gtlContext & ioArgument_context,
                                                                    GALGAS_gtlData & /* ioArgument_vars */,
                                                                    GALGAS_library & /* ioArgument_lib */,
                                                                    GALGAS_string & /* ioArgument_outputString */,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlWatchpointDeleteInstruction * object = (const cPtr_gtlWatchpointDeleteInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlWatchpointDeleteInstruction) ;
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_47162 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteWatchpoint ((cPtr_gtlContext *) ptr_47162, object->mAttribute_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1577)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWatchpointDeleteInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlWatchpointDeleteInstruction.mSlotID,
                                extensionMethod_gtlWatchpointDeleteInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWatchpointDeleteInstruction_execute (defineExtensionMethod_gtlWatchpointDeleteInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@gtlListInstruction execute'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlListInstruction_execute (const cPtr_gtlInstruction * inObject,
                                                        GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & /* ioArgument_vars */,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlListInstruction * object = (const cPtr_gtlListInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlListInstruction) ;
  callExtensionMethod_hereWeAre ((const cPtr_gtlContext *) ioArgument_context.ptr (), object->mAttribute_window, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1594)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlListInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlListInstruction.mSlotID,
                                extensionMethod_gtlListInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlListInstruction_execute (defineExtensionMethod_gtlListInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@gtlHistoryInstruction execute'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlHistoryInstruction_execute (const cPtr_gtlInstruction * /* inObject */,
                                                           GALGAS_gtlContext & ioArgument_context,
                                                           GALGAS_gtlData & /* ioArgument_vars */,
                                                           GALGAS_library & /* ioArgument_lib */,
                                                           GALGAS_string & /* ioArgument_outputString */,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listHistory ((const cPtr_debugCommandInput *) ioArgument_context.getter_debuggerContext (SOURCE_FILE ("gtl_debugger.galgas", 1610)).getter_commandInput (SOURCE_FILE ("gtl_debugger.galgas", 1610)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1610)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlHistoryInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlHistoryInstruction.mSlotID,
                                extensionMethod_gtlHistoryInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlHistoryInstruction_execute (defineExtensionMethod_gtlHistoryInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@gtlHelpInstruction execute'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlHelpInstruction_execute (const cPtr_gtlInstruction * /* inObject */,
                                                        GALGAS_gtlContext & /* ioArgument_context */,
                                                        GALGAS_gtlData & /* ioArgument_vars */,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("Available commands:\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1626)) ;
  inCompiler->printMessage (GALGAS_string ("  break <filename>:<line>        : set a breakpoint at <line> in file <filename>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1627)) ;
  inCompiler->printMessage (GALGAS_string ("  break <line>                   : set a breakpoint at <line> in the current file\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1628)) ;
  inCompiler->printMessage (GALGAS_string ("  break                          : lists the breakpoints\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1629)) ;
  inCompiler->printMessage (GALGAS_string ("  break not <num>                : delete breakpoint at index <num>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1630)) ;
  inCompiler->printMessage (GALGAS_string ("  cont                           : continue execution until the next breakpoint or the end\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1631)) ;
  inCompiler->printMessage (GALGAS_string ("  display <variable>             : display variable <variable>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1632)) ;
  inCompiler->printMessage (GALGAS_string ("  do <command>                   : do a command each time a step is done\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1633)) ;
  inCompiler->printMessage (GALGAS_string ("  do                             : list the do commands\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1634)) ;
  inCompiler->printMessage (GALGAS_string ("  do not <num>                   : delete the do command at index <num>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1635)) ;
  inCompiler->printMessage (GALGAS_string ("  list                           : lists instructions +/- 5 around current one\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1636)) ;
  inCompiler->printMessage (GALGAS_string ("  let <variable> := <expression> : compute <expression> and set <variable> to the result\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1637)) ;
  inCompiler->printMessage (GALGAS_string ("  print <expression>             : prints the <expression>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1638)) ;
  inCompiler->printMessage (GALGAS_string ("  step                           : step one instruction\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1639)) ;
  inCompiler->printMessage (GALGAS_string ("  unlet <variable>               : delete <variable>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1640)) ;
  inCompiler->printMessage (GALGAS_string ("  variables                      : display all variables in scope\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1641)) ;
  inCompiler->printMessage (GALGAS_string ("  watch (<expression>)           : set a watchpoint matching the boolean <expression>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1642)) ;
  inCompiler->printMessage (GALGAS_string ("  watch                          : lists the watchpoints\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1643)) ;
  inCompiler->printMessage (GALGAS_string ("  watch not <num>                : delete watchpoint at index <num>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1644)) ;
  inCompiler->printMessage (GALGAS_string ("  <return>                       : step one instruction\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1645)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlHelpInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlHelpInstruction.mSlotID,
                                extensionMethod_gtlHelpInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlHelpInstruction_execute (defineExtensionMethod_gtlHelpInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Bool options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_goil_5F_options_generate_5F_log ("goil_options",
                                         "generate_log",
                                         108,
                                         "logfile",
                                         "generate a goil.log file containing the a log of the compilation") ;

C_BoolCommandLineOption gOption_goil_5F_options_pierreOption ("goil_options",
                                         "pierreOption",
                                         0,
                                         "pierre",
                                         "Special option to pass a galgas bug to Pierre") ;

C_BoolCommandLineOption gOption_goil_5F_options_warnMultiple ("goil_options",
                                         "warnMultiple",
                                         0,
                                         "warn-multiple",
                                         "Emit a warning if an object not defined for the first time in the implementation does not have the same multiple attribute as in the first definition") ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               UInt options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String options                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

C_StringCommandLineOption gOption_goil_5F_options_config ("goil_options",
                                         "config",
                                         99,
                                         "config",
                                         "Specifies the OIL config file used by goil",
                                         "config") ;

C_StringCommandLineOption gOption_goil_5F_options_passOption ("goil_options",
                                         "passOption",
                                         111,
                                         "option",
                                         "Pass options to the template root script",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_project_5F_dir ("goil_options",
                                         "project_dir",
                                         112,
                                         "project",
                                         "Specifies project directory (by default, the project directory is the name of the oil file, without the .oil extension)",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_root ("goil_options",
                                         "root",
                                         114,
                                         "root",
                                         "Specifies the root template file to use to generate the output files",
                                         "root") ;

C_StringCommandLineOption gOption_goil_5F_options_target_5F_platform ("goil_options",
                                         "target_platform",
                                         116,
                                         "target",
                                         "Specifies target platform. Available target platform are located in machines/ directory. Targets are specified using a path like avr/arduino.",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_template_5F_dir ("goil_options",
                                         "template_dir",
                                         0,
                                         "templates",
                                         "Specifies template directory (used by goil for code generation)",
                                         "") ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String List options                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'checkEnums'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_checkEnums (const GALGAS_impEnumType & constinArgument_previousEnum,
                                 const GALGAS_impEnumType & constinArgument_newEnum,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_inside ; // Returned variable
  GALGAS_stringset var_newValues_15823 = constinArgument_newEnum.getter_valuesMap (SOURCE_FILE ("implementation_parser.galgas", 596)).getter_keySet (SOURCE_FILE ("implementation_parser.galgas", 596)) ;
  GALGAS_stringset var_previousValues_15882 = constinArgument_previousEnum.getter_valuesMap (SOURCE_FILE ("implementation_parser.galgas", 597)).getter_keySet (SOURCE_FILE ("implementation_parser.galgas", 597)) ;
  result_inside = GALGAS_bool (kIsEqual, var_newValues_15823.operator_and (var_previousValues_15882 COMMA_SOURCE_FILE ("implementation_parser.galgas", 598)).objectCompare (var_newValues_15823)) ;
  const enumGalgasBool test_0 = result_inside.operator_not (SOURCE_FILE ("implementation_parser.galgas", 599)).boolEnum () ;
  if (kBoolTrue == test_0) {
    cEnumerator_locationList enumerator_16026 (constinArgument_newEnum.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 600)), kEnumeration_up) ;
    while (enumerator_16026.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (enumerator_16026.current_location (HERE), GALGAS_string ("ENUM is not within previous enum declaration"), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 601)) ;
      enumerator_16026.gotoNextObject () ;
    }
    cEnumerator_locationList enumerator_16145 (constinArgument_previousEnum.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 603)), kEnumeration_up) ;
    while (enumerator_16145.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (enumerator_16145.current_location (HERE), GALGAS_string ("previous ENUM declaration was here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 604)) ;
      enumerator_16145.gotoNextObject () ;
    }
  }
//---
  return result_inside ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkEnums [3] = {
  & kTypeDescriptor_GALGAS_impEnumType,
  & kTypeDescriptor_GALGAS_impEnumType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkEnums (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_impEnumType operand0 = GALGAS_impEnumType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_impEnumType operand1 = GALGAS_impEnumType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  return function_checkEnums (operand0,
                              operand1,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkEnums ("checkEnums",
                                                            functionWithGenericHeader_checkEnums,
                                                            & kTypeDescriptor_GALGAS_bool,
                                                            2,
                                                            functionArgs_checkEnums) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'checkRanged'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_checkRanged (const GALGAS_impRangedType & constinArgument_previousRanged,
                                  const GALGAS_impRangedType & constinArgument_newRanged,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_inside ; // Returned variable
  callExtensionMethod_enclose ((const cPtr_attributeRange *) constinArgument_previousRanged.getter_setOrRange (SOURCE_FILE ("implementation_parser.galgas", 617)).ptr (), result_inside, constinArgument_newRanged.getter_setOrRange (SOURCE_FILE ("implementation_parser.galgas", 617)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 617)) ;
  const enumGalgasBool test_0 = result_inside.operator_not (SOURCE_FILE ("implementation_parser.galgas", 618)).boolEnum () ;
  if (kBoolTrue == test_0) {
    cEnumerator_locationList enumerator_16508 (constinArgument_newRanged.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 619)), kEnumeration_up) ;
    while (enumerator_16508.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (enumerator_16508.current_location (HERE), GALGAS_string ("new range or set is not within previous range or set declaration"), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 620)) ;
      enumerator_16508.gotoNextObject () ;
    }
    cEnumerator_locationList enumerator_16649 (constinArgument_previousRanged.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 622)), kEnumeration_up) ;
    while (enumerator_16649.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (enumerator_16649.current_location (HERE), GALGAS_string ("previous range or set declaration was here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 623)) ;
      enumerator_16649.gotoNextObject () ;
    }
  }
//---
  return result_inside ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkRanged [3] = {
  & kTypeDescriptor_GALGAS_impRangedType,
  & kTypeDescriptor_GALGAS_impRangedType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkRanged (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_impRangedType operand0 = GALGAS_impRangedType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_impRangedType operand1 = GALGAS_impRangedType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  return function_checkRanged (operand0,
                               operand1,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkRanged ("checkRanged",
                                                             functionWithGenericHeader_checkRanged,
                                                             & kTypeDescriptor_GALGAS_bool,
                                                             2,
                                                             functionArgs_checkRanged) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Function 'checkNewTypeWithinPreviousType'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_checkNewTypeWithinPreviousType (const GALGAS_lstring & constinArgument_name,
                                                     const GALGAS_impType & constinArgument_previousType,
                                                     const GALGAS_impType & constinArgument_newType,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, constinArgument_newType.getter_type (SOURCE_FILE ("implementation_parser.galgas", 634)).objectCompare (constinArgument_previousType.getter_type (SOURCE_FILE ("implementation_parser.galgas", 634)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    cEnumerator_locationList enumerator_16964 (constinArgument_newType.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 635)), kEnumeration_up) ;
    while (enumerator_16964.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (enumerator_16964.current_location (HERE), constinArgument_name.getter_string (SOURCE_FILE ("implementation_parser.galgas", 636)).add_operation (GALGAS_string (" should be a "), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 636)).add_operation (extensionGetter_oilType (constinArgument_previousType.getter_type (SOURCE_FILE ("implementation_parser.galgas", 636)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 636)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 636)), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 636)) ;
      enumerator_16964.gotoNextObject () ;
    }
    cEnumerator_locationList enumerator_17096 (constinArgument_previousType.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 638)), kEnumeration_up) ;
    while (enumerator_17096.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (enumerator_17096.current_location (HERE), constinArgument_name.getter_string (SOURCE_FILE ("implementation_parser.galgas", 639)).add_operation (GALGAS_string (" was previouly defined here"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 639)), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 639)) ;
      enumerator_17096.gotoNextObject () ;
    }
    result_result = GALGAS_bool (false) ;
  }else if (kBoolFalse == test_0) {
    if (constinArgument_previousType.isValid ()) {
      if (constinArgument_previousType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
        GALGAS_impEnumType cast_17259_previousEnum ((cPtr_impEnumType *) constinArgument_previousType.ptr ()) ;
        if (constinArgument_newType.isValid ()) {
          if (constinArgument_newType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
            GALGAS_impEnumType cast_17315_newEnum ((cPtr_impEnumType *) constinArgument_newType.ptr ()) ;
            result_result = function_checkEnums (cast_17259_previousEnum, cast_17315_newEnum, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 647)) ;
          }
        }
      }else if (constinArgument_previousType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
        GALGAS_impRangedType cast_17426_previousRanged ((cPtr_impRangedType *) constinArgument_previousType.ptr ()) ;
        if (constinArgument_newType.isValid ()) {
          if (constinArgument_newType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
            GALGAS_impRangedType cast_17486_newRanged ((cPtr_impRangedType *) constinArgument_newType.ptr ()) ;
            result_result = function_checkRanged (cast_17426_previousRanged, cast_17486_newRanged, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 652)) ;
          }
        }
      }else{
        result_result = GALGAS_bool (true) ;
      }
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkNewTypeWithinPreviousType [4] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_impType,
  & kTypeDescriptor_GALGAS_impType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkNewTypeWithinPreviousType (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_impType operand1 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_impType operand2 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_checkNewTypeWithinPreviousType (operand0,
                                                  operand1,
                                                  operand2,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkNewTypeWithinPreviousType ("checkNewTypeWithinPreviousType",
                                                                                functionWithGenericHeader_checkNewTypeWithinPreviousType,
                                                                                & kTypeDescriptor_GALGAS_bool,
                                                                                3,
                                                                                functionArgs_checkNewTypeWithinPreviousType) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'buildRange'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange function_buildRange (const GALGAS_dataType & constinArgument_type,
                                           const GALGAS_object_5F_t & constinArgument_start,
                                           const GALGAS_object_5F_t & constinArgument_stop,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_attributeRange result_range ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 665)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_range = GALGAS_uint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 666)), function_uint_33__32_OrError (constinArgument_start, GALGAS_string ("UINT32 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 666)), function_uint_33__32_OrError (constinArgument_stop, GALGAS_string ("UINT32 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 666))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 666)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 667)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_range = GALGAS_sint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 668)), function_sint_33__32_OrError (constinArgument_start, GALGAS_string ("SINT32 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 668)), function_sint_33__32_OrError (constinArgument_stop, GALGAS_string ("SINT32 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 668))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 668)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 669)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_range = GALGAS_uint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 670)), function_uint_36__34_OrError (constinArgument_start, GALGAS_string ("UINT64 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 670)), function_uint_36__34_OrError (constinArgument_stop, GALGAS_string ("UINT64 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 670))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 670)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 671)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_range = GALGAS_sint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 672)), function_sint_36__34_OrError (constinArgument_start, GALGAS_string ("SINT64 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 672)), function_sint_36__34_OrError (constinArgument_stop, GALGAS_string ("SINT64 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 672))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 672)) ;
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_parser.galgas", 673)))).boolEnum () ;
          if (kBoolTrue == test_4) {
            result_range = GALGAS_floatAttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 674)), function_floatOrError (constinArgument_start, GALGAS_string ("FLOAT Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 674)), function_floatOrError (constinArgument_stop, GALGAS_string ("FLOAT Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 674))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 674)) ;
          }else if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 676)), GALGAS_string ("internal. Unknown number type"), fixItArray5  COMMA_SOURCE_FILE ("implementation_parser.galgas", 676)) ;
            result_range.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_range ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_buildRange [4] = {
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_object_5F_t,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_buildRange (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_dataType operand0 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_object_5F_t operand1 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_object_5F_t operand2 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  return function_buildRange (operand0,
                              operand1,
                              operand2,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_buildRange ("buildRange",
                                                            functionWithGenericHeader_buildRange,
                                                            & kTypeDescriptor_GALGAS_attributeRange,
                                                            3,
                                                            functionArgs_buildRange) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithUInt32List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithUInt_33__32_List (const GALGAS_uint_33__32_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_uint_33__32_List enumerator_1878 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_1878.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_1878.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 68)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 68)) ;
    if (enumerator_1878.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 68)) ;
    }
    enumerator_1878.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_uint_33__32_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithUInt_33__32_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_uint_33__32_List operand0 = GALGAS_uint_33__32_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithUInt_33__32_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithUInt_33__32_List ("stringWithUInt32List",
                                                                            functionWithGenericHeader_stringWithUInt_33__32_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithUInt_33__32_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithUInt64List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithUInt_36__34_List (const GALGAS_uint_36__34_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_uint_36__34_List enumerator_2040 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_2040.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2040.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 73)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 73)) ;
    if (enumerator_2040.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 73)) ;
    }
    enumerator_2040.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithUInt_36__34_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_uint_36__34_List operand0 = GALGAS_uint_36__34_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithUInt_36__34_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithUInt_36__34_List ("stringWithUInt64List",
                                                                            functionWithGenericHeader_stringWithUInt_36__34_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithUInt_36__34_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithSInt32List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithSInt_33__32_List (const GALGAS_sint_33__32_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_sint_33__32_List enumerator_2202 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_2202.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2202.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 78)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 78)) ;
    if (enumerator_2202.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 78)) ;
    }
    enumerator_2202.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_sint_33__32_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithSInt_33__32_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_sint_33__32_List operand0 = GALGAS_sint_33__32_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithSInt_33__32_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithSInt_33__32_List ("stringWithSInt32List",
                                                                            functionWithGenericHeader_stringWithSInt_33__32_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithSInt_33__32_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithSInt64List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithSInt_36__34_List (const GALGAS_sint_36__34_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_sint_36__34_List enumerator_2364 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_2364.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2364.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 83)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 83)) ;
    if (enumerator_2364.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 83)) ;
    }
    enumerator_2364.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_sint_36__34_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithSInt_36__34_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_sint_36__34_List operand0 = GALGAS_sint_36__34_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithSInt_36__34_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithSInt_36__34_List ("stringWithSInt64List",
                                                                            functionWithGenericHeader_stringWithSInt_36__34_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithSInt_36__34_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithFloatList'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithFloatList (const GALGAS_floatList & constinArgument_values,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_floatList enumerator_2524 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_2524.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2524.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 88)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 88)) ;
    if (enumerator_2524.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 88)) ;
    }
    enumerator_2524.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithFloatList [2] = {
  & kTypeDescriptor_GALGAS_floatList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithFloatList (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_floatList operand0 = GALGAS_floatList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  return function_stringWithFloatList (operand0,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithFloatList ("stringWithFloatList",
                                                                     functionWithGenericHeader_stringWithFloatList,
                                                                     & kTypeDescriptor_GALGAS_string,
                                                                     1,
                                                                     functionArgs_stringWithFloatList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'uint32ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List function_uint_33__32_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_33__32_List result_result ; // Returned variable
  result_result = GALGAS_uint_33__32_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 92)) ;
  cEnumerator_numberList enumerator_2716 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_2716.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_2716.current_location (HERE), function_uint_33__32_OrError (enumerator_2716.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 94))  COMMA_SOURCE_FILE ("implementation_types.galgas", 94)) ;
    enumerator_2716.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_33__32_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_uint_33__32_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_33__32_ListWithNumberList ("uint32ListWithNumberList",
                                                                                functionWithGenericHeader_uint_33__32_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_uint_33__32_List,
                                                                                1,
                                                                                functionArgs_uint_33__32_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'sint32ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List function_sint_33__32_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_33__32_List result_result ; // Returned variable
  result_result = GALGAS_sint_33__32_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 99)) ;
  cEnumerator_numberList enumerator_2914 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_2914.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_2914.current_location (HERE), function_sint_33__32_OrError (enumerator_2914.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 101))  COMMA_SOURCE_FILE ("implementation_types.galgas", 101)) ;
    enumerator_2914.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_33__32_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_sint_33__32_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_33__32_ListWithNumberList ("sint32ListWithNumberList",
                                                                                functionWithGenericHeader_sint_33__32_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_sint_33__32_List,
                                                                                1,
                                                                                functionArgs_sint_33__32_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'uint64ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List function_uint_36__34_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_List result_result ; // Returned variable
  result_result = GALGAS_uint_36__34_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 106)) ;
  cEnumerator_numberList enumerator_3112 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_3112.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3112.current_location (HERE), function_uint_36__34_OrError (enumerator_3112.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 108))  COMMA_SOURCE_FILE ("implementation_types.galgas", 108)) ;
    enumerator_3112.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_36__34_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_uint_36__34_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_36__34_ListWithNumberList ("uint64ListWithNumberList",
                                                                                functionWithGenericHeader_uint_36__34_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_uint_36__34_List,
                                                                                1,
                                                                                functionArgs_uint_36__34_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'sint64ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List function_sint_36__34_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_List result_result ; // Returned variable
  result_result = GALGAS_sint_36__34_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 113)) ;
  cEnumerator_numberList enumerator_3310 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_3310.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3310.current_location (HERE), function_sint_36__34_OrError (enumerator_3310.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 115))  COMMA_SOURCE_FILE ("implementation_types.galgas", 115)) ;
    enumerator_3310.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_36__34_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_sint_36__34_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_36__34_ListWithNumberList ("sint64ListWithNumberList",
                                                                                functionWithGenericHeader_sint_36__34_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_sint_36__34_List,
                                                                                1,
                                                                                functionArgs_sint_36__34_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'floatListWithNumberList'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList function_floatListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_floatList result_result ; // Returned variable
  result_result = GALGAS_floatList::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 120)) ;
  cEnumerator_numberList enumerator_3505 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_3505.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3505.current_location (HERE), function_floatOrError (enumerator_3505.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 122))  COMMA_SOURCE_FILE ("implementation_types.galgas", 122)) ;
    enumerator_3505.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_floatListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_floatListWithNumberList (C_Compiler * inCompiler,
                                                                        const cObjectArray & inEffectiveParameterArray,
                                                                        const GALGAS_location & /* inErrorLocation */
                                                                        COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_floatListWithNumberList (operand0,
                                           inCompiler
                                           COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_floatListWithNumberList ("floatListWithNumberList",
                                                                         functionWithGenericHeader_floatListWithNumberList,
                                                                         & kTypeDescriptor_GALGAS_floatList,
                                                                         1,
                                                                         functionArgs_floatListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@noRange enclose'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_noRange_enclose (const cPtr_attributeRange * /* inObject */,
                                             GALGAS_bool & outArgument_isWithin,
                                             const GALGAS_attributeRange /* constinArgument_value */,
                                             C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (true) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_noRange_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_noRange.mSlotID,
                                extensionMethod_noRange_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_noRange_enclose (defineExtensionMethod_noRange_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@uint32AttributeSet enclose'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_33__32_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_33__32_AttributeSet * object = (const cPtr_uint_33__32_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_uint_33__32_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet) {
      GALGAS_uint_33__32_AttributeSet cast_4277_set ((cPtr_uint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_uint_33__32_List enumerator_4315 (cast_4277_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 155)), kEnumeration_up) ;
      while (enumerator_4315.hasCurrentObject ()) {
        GALGAS_bool var_ok_4333 = GALGAS_bool (false) ;
        cEnumerator_uint_33__32_List enumerator_4374 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_4374.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_4315.current_value (HERE).objectCompare (enumerator_4374.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_4333 = GALGAS_bool (true) ;
          }
          enumerator_4374.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_4333 COMMA_SOURCE_FILE ("implementation_types.galgas", 162)) ;
        enumerator_4315.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 165)), GALGAS_string ("Incompatible set. Should be a UINT32 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 165)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 166)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_33__32_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_33__32_AttributeSet.mSlotID,
                                extensionMethod_uint_33__32_AttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_33__32_AttributeSet_enclose (defineExtensionMethod_uint_33__32_AttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@uint64AttributeSet enclose'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_36__34_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_36__34_AttributeSet * object = (const cPtr_uint_36__34_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_uint_36__34_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet) {
      GALGAS_uint_36__34_AttributeSet cast_4888_set ((cPtr_uint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_uint_36__34_List enumerator_4926 (cast_4888_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 179)), kEnumeration_up) ;
      while (enumerator_4926.hasCurrentObject ()) {
        GALGAS_bool var_ok_4944 = GALGAS_bool (false) ;
        cEnumerator_uint_36__34_List enumerator_4985 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_4985.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_4926.current_value (HERE).objectCompare (enumerator_4985.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_4944 = GALGAS_bool (true) ;
          }
          enumerator_4985.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_4944 COMMA_SOURCE_FILE ("implementation_types.galgas", 186)) ;
        enumerator_4926.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 189)), GALGAS_string ("Incompatible set. Should be a UINT64 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 189)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 190)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_36__34_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_36__34_AttributeSet.mSlotID,
                                extensionMethod_uint_36__34_AttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_36__34_AttributeSet_enclose (defineExtensionMethod_uint_36__34_AttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@sint32AttributeSet enclose'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_33__32_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_33__32_AttributeSet * object = (const cPtr_sint_33__32_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_sint_33__32_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet) {
      GALGAS_sint_33__32_AttributeSet cast_5499_set ((cPtr_sint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_sint_33__32_List enumerator_5537 (cast_5499_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 203)), kEnumeration_up) ;
      while (enumerator_5537.hasCurrentObject ()) {
        GALGAS_bool var_ok_5555 = GALGAS_bool (false) ;
        cEnumerator_sint_33__32_List enumerator_5596 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_5596.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_5537.current_value (HERE).objectCompare (enumerator_5596.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_5555 = GALGAS_bool (true) ;
          }
          enumerator_5596.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_5555 COMMA_SOURCE_FILE ("implementation_types.galgas", 210)) ;
        enumerator_5537.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 213)), GALGAS_string ("Incompatible set. Should be a INT32 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 213)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 214)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_33__32_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_33__32_AttributeSet.mSlotID,
                                extensionMethod_sint_33__32_AttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_33__32_AttributeSet_enclose (defineExtensionMethod_sint_33__32_AttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@sint64AttributeSet enclose'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_36__34_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_36__34_AttributeSet * object = (const cPtr_sint_36__34_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_sint_36__34_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet) {
      GALGAS_sint_36__34_AttributeSet cast_6109_set ((cPtr_sint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_sint_36__34_List enumerator_6147 (cast_6109_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 227)), kEnumeration_up) ;
      while (enumerator_6147.hasCurrentObject ()) {
        GALGAS_bool var_ok_6165 = GALGAS_bool (false) ;
        cEnumerator_sint_36__34_List enumerator_6206 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_6206.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_6147.current_value (HERE).objectCompare (enumerator_6206.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_6165 = GALGAS_bool (true) ;
          }
          enumerator_6206.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_6165 COMMA_SOURCE_FILE ("implementation_types.galgas", 234)) ;
        enumerator_6147.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 237)), GALGAS_string ("Incompatible set. Should be a INT64 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 237)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 238)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_36__34_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_36__34_AttributeSet.mSlotID,
                                extensionMethod_sint_36__34_AttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_36__34_AttributeSet_enclose (defineExtensionMethod_sint_36__34_AttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@floatAttributeSet enclose'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_floatAttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                       GALGAS_bool & outArgument_isWithin,
                                                       const GALGAS_attributeRange constinArgument_value,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_floatAttributeSet * object = (const cPtr_floatAttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_floatAttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeSet) {
      GALGAS_floatAttributeSet cast_6717_set ((cPtr_floatAttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_floatList enumerator_6755 (cast_6717_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 251)), kEnumeration_up) ;
      while (enumerator_6755.hasCurrentObject ()) {
        GALGAS_bool var_ok_6773 = GALGAS_bool (false) ;
        cEnumerator_floatList enumerator_6814 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_6814.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_6755.current_value (HERE).objectCompare (enumerator_6814.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_6773 = GALGAS_bool (true) ;
          }
          enumerator_6814.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_6773 COMMA_SOURCE_FILE ("implementation_types.galgas", 258)) ;
        enumerator_6755.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 261)), GALGAS_string ("Incompatible set. Should be a FLOAT set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 261)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 262)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_floatAttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_floatAttributeSet.mSlotID,
                                extensionMethod_floatAttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_floatAttributeSet_enclose (defineExtensionMethod_floatAttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@uint32AttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_33__32_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_33__32_AttributeMinMax * object = (const cPtr_uint_33__32_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_uint_33__32_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax) {
      GALGAS_uint_33__32_AttributeMinMax cast_7340_minmax ((cPtr_uint_33__32_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_7340_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 276)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_7340_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 276)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 276)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet) {
      GALGAS_uint_33__32_AttributeSet cast_7460_set ((cPtr_uint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_uint_33__32_List enumerator_7513 (cast_7460_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 281)), kEnumeration_up) ;
      while (enumerator_7513.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_7513.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_7513.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 282)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_7513.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 287)), GALGAS_string ("Incompatible set. Should be a UINT32 range or UINT32 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 287)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 288)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_33__32_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax.mSlotID,
                                extensionMethod_uint_33__32_AttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_33__32_AttributeMinMax_enclose (defineExtensionMethod_uint_33__32_AttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@uint64AttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_36__34_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_36__34_AttributeMinMax * object = (const cPtr_uint_36__34_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_uint_36__34_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax) {
      GALGAS_uint_36__34_AttributeMinMax cast_7999_minmax ((cPtr_uint_36__34_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_7999_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 301)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_7999_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 301)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 301)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet) {
      GALGAS_uint_36__34_AttributeSet cast_8119_set ((cPtr_uint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_uint_36__34_List enumerator_8172 (cast_8119_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 306)), kEnumeration_up) ;
      while (enumerator_8172.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_8172.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_8172.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 307)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_8172.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 312)), GALGAS_string ("Incompatible set. Should be a UINT64 range or UINT64 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 312)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 313)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_36__34_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax.mSlotID,
                                extensionMethod_uint_36__34_AttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_36__34_AttributeMinMax_enclose (defineExtensionMethod_uint_36__34_AttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@sint32AttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_33__32_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_33__32_AttributeMinMax * object = (const cPtr_sint_33__32_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_sint_33__32_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax) {
      GALGAS_sint_33__32_AttributeMinMax cast_8654_minmax ((cPtr_sint_33__32_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_8654_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 326)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_8654_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 326)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 326)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet) {
      GALGAS_sint_33__32_AttributeSet cast_8774_set ((cPtr_sint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_sint_33__32_List enumerator_8827 (cast_8774_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 331)), kEnumeration_up) ;
      while (enumerator_8827.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_8827.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_8827.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 332)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_8827.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 337)), GALGAS_string ("Incompatible set. Should be a INT32 range or INT32 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 337)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 338)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_33__32_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax.mSlotID,
                                extensionMethod_sint_33__32_AttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_33__32_AttributeMinMax_enclose (defineExtensionMethod_sint_33__32_AttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@sint64AttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_36__34_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_36__34_AttributeMinMax * object = (const cPtr_sint_36__34_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_sint_36__34_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax) {
      GALGAS_sint_36__34_AttributeMinMax cast_9311_minmax ((cPtr_sint_36__34_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_9311_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 351)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_9311_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 351)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 351)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet) {
      GALGAS_sint_36__34_AttributeSet cast_9431_set ((cPtr_sint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_sint_36__34_List enumerator_9484 (cast_9431_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 356)), kEnumeration_up) ;
      while (enumerator_9484.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_9484.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_9484.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 357)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_9484.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 362)), GALGAS_string ("Incompatible set. Should be a INT64 range or INT64 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 362)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 363)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_36__34_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax.mSlotID,
                                extensionMethod_sint_36__34_AttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_36__34_AttributeMinMax_enclose (defineExtensionMethod_sint_36__34_AttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@floatAttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_floatAttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                          GALGAS_bool & outArgument_isWithin,
                                                          const GALGAS_attributeRange constinArgument_value,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_floatAttributeMinMax * object = (const cPtr_floatAttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_floatAttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeMinMax) {
      GALGAS_floatAttributeMinMax cast_9966_minmax ((cPtr_floatAttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_9966_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 376)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_9966_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 376)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 376)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeSet) {
      GALGAS_floatAttributeSet cast_10085_set ((cPtr_floatAttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_floatList enumerator_10138 (cast_10085_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 381)), kEnumeration_up) ;
      while (enumerator_10138.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_10138.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_10138.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 382)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_10138.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 387)), GALGAS_string ("Incompatible set. Should be a FLOAT range or FLOAT set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 387)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 388)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_floatAttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_floatAttributeMinMax.mSlotID,
                                extensionMethod_floatAttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_floatAttributeMinMax_enclose (defineExtensionMethod_floatAttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Function 'attributeRangeWithNumberList'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange function_attributeRangeWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                             const GALGAS_dataType & constinArgument_type,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_attributeRange result_range ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 397)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_range = GALGAS_uint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 398)), function_uint_33__32_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 398))  COMMA_SOURCE_FILE ("implementation_types.galgas", 398)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 399)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_range = GALGAS_sint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 400)), function_sint_33__32_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 400))  COMMA_SOURCE_FILE ("implementation_types.galgas", 400)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 401)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_range = GALGAS_uint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 402)), function_uint_36__34_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 402))  COMMA_SOURCE_FILE ("implementation_types.galgas", 402)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 403)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_range = GALGAS_sint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 404)), function_sint_36__34_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 404))  COMMA_SOURCE_FILE ("implementation_types.galgas", 404)) ;
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 405)))).boolEnum () ;
          if (kBoolTrue == test_4) {
            result_range = GALGAS_floatAttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 406)), function_floatListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 406))  COMMA_SOURCE_FILE ("implementation_types.galgas", 406)) ;
          }else if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 408)), GALGAS_string ("internal. Unknown number type"), fixItArray5  COMMA_SOURCE_FILE ("implementation_types.galgas", 408)) ;
            result_range.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_range ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_attributeRangeWithNumberList [3] = {
  & kTypeDescriptor_GALGAS_numberList,
  & kTypeDescriptor_GALGAS_dataType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_attributeRangeWithNumberList (C_Compiler * inCompiler,
                                                                             const cObjectArray & inEffectiveParameterArray,
                                                                             const GALGAS_location & /* inErrorLocation */
                                                                             COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  return function_attributeRangeWithNumberList (operand0,
                                                operand1,
                                                inCompiler
                                                COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_attributeRangeWithNumberList ("attributeRangeWithNumberList",
                                                                              functionWithGenericHeader_attributeRangeWithNumberList,
                                                                              & kTypeDescriptor_GALGAS_attributeRange,
                                                                              2,
                                                                              functionArgs_attributeRangeWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@impStructType mergeWithType'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impStructType_mergeWithType (const cPtr_impType * inObject,
                                                                   GALGAS_impType inArgument_typeToMerge,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impStructType * object = (const cPtr_impStructType *) inObject ;
  macroValidSharedObject (object, cPtr_impStructType) ;
  GALGAS_impStructType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impStructType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impStructType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impStructType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 441)) ;
    }
  }
  GALGAS_impStructType var_castTypeToMerge_12022 = temp_0 ;
  GALGAS_implementationObjectMap var_mergedAttributes_12098 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 442)) ;
  cEnumerator_implementationObjectMap enumerator_12139 (object->mAttribute_structAttributes, kEnumeration_up) ;
  while (enumerator_12139.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_12166 = enumerator_12139.current_type (HERE) ;
    const enumGalgasBool test_1 = var_castTypeToMerge_12022.getter_structAttributes (SOURCE_FILE ("implementation_types.galgas", 445)).getter_hasKey (enumerator_12139.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 445)) COMMA_SOURCE_FILE ("implementation_types.galgas", 445)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_impType var_subTypeToMerge_12321 ;
      var_castTypeToMerge_12022.getter_structAttributes (SOURCE_FILE ("implementation_types.galgas", 446)).method_get (enumerator_12139.current_lkey (HERE), var_subTypeToMerge_12321, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 446)) ;
      var_mergedAttr_12166 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_12139.current_type (HERE).ptr (), var_subTypeToMerge_12321, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 447)) ;
    }
    {
    var_mergedAttributes_12098.setter_put (enumerator_12139.current_lkey (HERE), var_mergedAttr_12166, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 449)) ;
    }
    enumerator_12139.gotoNextObject () ;
  }
  result_mergedType = GALGAS_impStructType::constructor_new (object->mAttribute_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 452)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 452)), object->mAttribute_type, object->mAttribute_name, object->mAttribute_multiple, object->mAttribute_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 456)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 456)), var_mergedAttributes_12098  COMMA_SOURCE_FILE ("implementation_types.galgas", 451)) ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impStructType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impStructType.mSlotID,
                                      extensionGetter_impStructType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impStructType_mergeWithType (defineExtensionGetter_impStructType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@impVoid mergeWithType'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impVoid_mergeWithType (const cPtr_impType * inObject,
                                                             GALGAS_impType /* inArgument_typeToMerge */,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impVoid * object = (const cPtr_impVoid *) inObject ;
  macroValidSharedObject (object, cPtr_impVoid) ;
  const GALGAS_impVoid temp_0 = object ;
  result_mergedType = temp_0 ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impVoid_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impVoid.mSlotID,
                                      extensionGetter_impVoid_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impVoid_mergeWithType (defineExtensionGetter_impVoid_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension getter '@impAutoDefaultType mergeWithType'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impAutoDefaultType_mergeWithType (const cPtr_impType * inObject,
                                                                        GALGAS_impType /* inArgument_typeToMerge */,
                                                                        C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impAutoDefaultType * object = (const cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  const GALGAS_impAutoDefaultType temp_0 = object ;
  result_mergedType = temp_0 ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impAutoDefaultType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                      extensionGetter_impAutoDefaultType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impAutoDefaultType_mergeWithType (defineExtensionGetter_impAutoDefaultType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@impAutoDefaultType autoAllowed'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_impAutoDefaultType_autoAllowed (const cPtr_impType * inObject,
                                                                   C_Compiler * /* inCompiler */
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_impAutoDefaultType * object = (const cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  result_result = object->mAttribute_withAuto ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impAutoDefaultType_autoAllowed (void) {
  enterExtensionGetter_autoAllowed (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                    extensionGetter_impAutoDefaultType_autoAllowed) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impAutoDefaultType_autoAllowed (defineExtensionGetter_impAutoDefaultType_autoAllowed, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'multiError'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_multiError (GALGAS_locationList inArgument_locations,
                         GALGAS_string inArgument_errorMessage,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_locationList enumerator_13729 (inArgument_locations, kEnumeration_up) ;
  while (enumerator_13729.hasCurrentObject ()) {
    TC_Array <C_FixItDescription> fixItArray0 ;
    inCompiler->emitSemanticError (enumerator_13729.current_location (HERE), inArgument_errorMessage, fixItArray0  COMMA_SOURCE_FILE ("implementation_types.galgas", 508)) ;
    enumerator_13729.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@refType mergeWithType'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_refType_mergeWithType (const cPtr_impType * inObject,
                                                             GALGAS_impType inArgument_typeToMerge,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_refType * object = (const cPtr_refType *) inObject ;
  macroValidSharedObject (object, cPtr_refType) ;
  GALGAS_refType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_refType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_refType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("refType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 520)) ;
    }
  }
  GALGAS_refType var_castTypeToMerge_13962 = temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, object->mAttribute_ref.getter_string (SOURCE_FILE ("implementation_types.galgas", 521)).objectCompare (var_castTypeToMerge_13962.getter_ref (SOURCE_FILE ("implementation_types.galgas", 521)).getter_string (SOURCE_FILE ("implementation_types.galgas", 521)))).boolEnum () ;
  if (kBoolTrue == test_1) {
    object->mAttribute_ref.log ("ref"  COMMA_SOURCE_FILE ("implementation_types.galgas", 522)) ;
    GALGAS_lstring var_csatRef_14078 = var_castTypeToMerge_13962.getter_ref (SOURCE_FILE ("implementation_types.galgas", 523)) ;
    var_csatRef_14078.log ("csatRef"  COMMA_SOURCE_FILE ("implementation_types.galgas", 524)) ;
    {
    routine_multiError (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 525)), GALGAS_string ("Redefinition of ").add_operation (object->mAttribute_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 525)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 525)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 525)) ;
    }
    {
    routine_multiError (object->mAttribute_locations, GALGAS_string ("Was defined here"), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 526)) ;
    }
  }
  result_mergedType = GALGAS_refType::constructor_new (object->mAttribute_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 529)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 529)), object->mAttribute_type, object->mAttribute_name, object->mAttribute_multiple, object->mAttribute_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 533)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 533)), object->mAttribute_ref  COMMA_SOURCE_FILE ("implementation_types.galgas", 528)) ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_refType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_refType.mSlotID,
                                      extensionGetter_refType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_refType_mergeWithType (defineExtensionGetter_refType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'valueList'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_valueList (const GALGAS_enumValues & constinArgument_values,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_enumValues enumerator_15054 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_15054.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_15054.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 562)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 562)) ;
    if (enumerator_15054.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 564)) ;
    }
    enumerator_15054.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueList [2] = {
  & kTypeDescriptor_GALGAS_enumValues,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueList (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_enumValues operand0 = GALGAS_enumValues::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_valueList (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueList ("valueList",
                                                           functionWithGenericHeader_valueList,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_valueList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@impRangedType mergeWithType'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impRangedType_mergeWithType (const cPtr_impType * inObject,
                                                                   GALGAS_impType inArgument_typeToMerge,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impRangedType * object = (const cPtr_impRangedType *) inObject ;
  macroValidSharedObject (object, cPtr_impRangedType) ;
  GALGAS_impRangedType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impRangedType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impRangedType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impRangedType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 576)) ;
    }
  }
  GALGAS_impRangedType var_castTypeToMerge_15328 = temp_0 ;
  const GALGAS_impRangedType temp_1 = object ;
  const enumGalgasBool test_2 = function_checkRanged (temp_1, var_castTypeToMerge_15328, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 577)).boolEnum () ;
  if (kBoolTrue == test_2) {
    result_mergedType = inArgument_typeToMerge ;
  }else if (kBoolFalse == test_2) {
    const GALGAS_impRangedType temp_3 = object ;
    result_mergedType = temp_3 ;
  }
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impRangedType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impRangedType.mSlotID,
                                      extensionGetter_impRangedType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impRangedType_mergeWithType (defineExtensionGetter_impRangedType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension getter '@impBoolType mergeWithType'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impBoolType_mergeWithType (const cPtr_impType * inObject,
                                                                 GALGAS_impType inArgument_typeToMerge,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  GALGAS_impBoolType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impBoolType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impBoolType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impBoolType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 593)) ;
    }
  }
  GALGAS_impBoolType var_castTypeToMerge_15734 = temp_0 ;
  GALGAS_implementationObjectMap var_mergedTrueAttributes_15812 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 594)) ;
  GALGAS_implementationObjectMap var_mergedFalseAttributes_15873 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 595)) ;
  cEnumerator_implementationObjectMap enumerator_15915 (object->mAttribute_trueSubAttributes, kEnumeration_up) ;
  while (enumerator_15915.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_15942 = enumerator_15915.current_type (HERE) ;
    const enumGalgasBool test_1 = var_castTypeToMerge_15734.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 598)).getter_hasKey (enumerator_15915.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 598)) COMMA_SOURCE_FILE ("implementation_types.galgas", 598)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_impType var_subTypeToMerge_16099 ;
      var_castTypeToMerge_15734.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 599)).method_get (enumerator_15915.current_lkey (HERE), var_subTypeToMerge_16099, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 599)) ;
      var_mergedAttr_15942 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_15915.current_type (HERE).ptr (), var_subTypeToMerge_16099, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 600)) ;
    }
    {
    var_mergedTrueAttributes_15812.setter_put (enumerator_15915.current_lkey (HERE), var_mergedAttr_15942, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 602)) ;
    }
    enumerator_15915.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_16308 (var_castTypeToMerge_15734.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 605)), kEnumeration_up) ;
  while (enumerator_16308.hasCurrentObject ()) {
    const enumGalgasBool test_2 = object->mAttribute_trueSubAttributes.getter_hasKey (enumerator_16308.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 606)) COMMA_SOURCE_FILE ("implementation_types.galgas", 606)).operator_not (SOURCE_FILE ("implementation_types.galgas", 606)).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      var_mergedTrueAttributes_15812.setter_put (enumerator_16308.current_lkey (HERE), enumerator_16308.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 607)) ;
      }
    }
    enumerator_16308.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_16464 (object->mAttribute_falseSubAttributes, kEnumeration_up) ;
  while (enumerator_16464.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_16491 = enumerator_16464.current_type (HERE) ;
    const enumGalgasBool test_3 = var_castTypeToMerge_15734.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 613)).getter_hasKey (enumerator_16464.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 613)) COMMA_SOURCE_FILE ("implementation_types.galgas", 613)).boolEnum () ;
    if (kBoolTrue == test_3) {
      GALGAS_impType var_subTypeToMerge_16650 ;
      var_castTypeToMerge_15734.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 614)).method_get (enumerator_16464.current_lkey (HERE), var_subTypeToMerge_16650, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 614)) ;
      var_mergedAttr_16491 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_16464.current_type (HERE).ptr (), var_subTypeToMerge_16650, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 615)) ;
    }
    {
    var_mergedFalseAttributes_15873.setter_put (enumerator_16464.current_lkey (HERE), var_mergedAttr_16491, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 617)) ;
    }
    enumerator_16464.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_16861 (var_castTypeToMerge_15734.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 620)), kEnumeration_up) ;
  while (enumerator_16861.hasCurrentObject ()) {
    const enumGalgasBool test_4 = object->mAttribute_falseSubAttributes.getter_hasKey (enumerator_16861.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 621)) COMMA_SOURCE_FILE ("implementation_types.galgas", 621)).operator_not (SOURCE_FILE ("implementation_types.galgas", 621)).boolEnum () ;
    if (kBoolTrue == test_4) {
      {
      var_mergedTrueAttributes_15812.setter_put (enumerator_16861.current_lkey (HERE), enumerator_16861.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 622)) ;
      }
    }
    enumerator_16861.gotoNextObject () ;
  }
  result_mergedType = GALGAS_impBoolType::constructor_new (object->mAttribute_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 627)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 627)), object->mAttribute_type, object->mAttribute_name, object->mAttribute_multiple, object->mAttribute_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 631)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 631)), object->mAttribute_withAuto, object->mAttribute_defaultValue, var_mergedTrueAttributes_15812, var_mergedFalseAttributes_15873  COMMA_SOURCE_FILE ("implementation_types.galgas", 626)) ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impBoolType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                      extensionGetter_impBoolType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impBoolType_mergeWithType (defineExtensionGetter_impBoolType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@impBoolType setDefault'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impBoolType_setDefault (const cPtr_impAutoDefaultType * inObject,
                                                    GALGAS_objectAttributes & ioArgument_attributes,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  if (object->mAttribute_defaultValue.isValid ()) {
    if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_void) {
    }else if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_17451_b ((cPtr_boolAttribute *) object->mAttribute_defaultValue.ptr ()) ;
      const enumGalgasBool test_0 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 647)).getter_hasKey (object->mAttribute_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 647)) COMMA_SOURCE_FILE ("implementation_types.galgas", 647)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_identifierMap var_userAttributes_17727 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 650)) ;
        GALGAS_object_5F_t var_value_17779 ;
        var_userAttributes_17727.method_get (object->mAttribute_name, var_value_17779, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 652)) ;
        if (var_value_17779.isValid ()) {
          if (var_value_17779.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
            GALGAS_boolAttribute cast_17881_boolValue ((cPtr_boolAttribute *) var_value_17779.ptr ()) ;
            GALGAS_implementationObjectMap var_subImpAttributes_17935 ;
            const enumGalgasBool test_1 = cast_17881_boolValue.getter_value (SOURCE_FILE ("implementation_types.galgas", 656)).boolEnum () ;
            if (kBoolTrue == test_1) {
              var_subImpAttributes_17935 = object->mAttribute_trueSubAttributes ;
            }else if (kBoolFalse == test_1) {
              var_subImpAttributes_17935 = object->mAttribute_falseSubAttributes ;
            }
            GALGAS_objectAttributes var_subAttributes_18141 = cast_17881_boolValue.getter_subAttributes (SOURCE_FILE ("implementation_types.galgas", 661)) ;
            {
            routine_setDefaultsForType (var_subImpAttributes_17935, var_subAttributes_18141, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 662)) ;
            }
            GALGAS_boolAttribute var_bv_18296 = cast_17881_boolValue ;
            {
            var_bv_18296.setter_setSubAttributes (var_subAttributes_18141 COMMA_SOURCE_FILE ("implementation_types.galgas", 665)) ;
            }
            {
            var_userAttributes_17727.setter_setValueForKey (var_bv_18296, object->mAttribute_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 666)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 666)) ;
            }
            {
            ioArgument_attributes.setter_setObjectParams (var_userAttributes_17727 COMMA_SOURCE_FILE ("implementation_types.galgas", 667)) ;
            }
          }
        }
      }else if (kBoolFalse == test_0) {
        GALGAS_implementationObjectMap var_subImpAttributes_18555 ;
        const enumGalgasBool test_2 = cast_17451_b.getter_value (SOURCE_FILE ("implementation_types.galgas", 671)).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_subImpAttributes_18555 = object->mAttribute_trueSubAttributes ;
        }else if (kBoolFalse == test_2) {
          var_subImpAttributes_18555 = object->mAttribute_falseSubAttributes ;
        }
        GALGAS_objectAttributes var_subAttributes_18741 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 676)) ;
        {
        routine_setDefaultsForType (var_subImpAttributes_18555, var_subAttributes_18741, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 677)) ;
        }
        GALGAS_boolAttribute var_defaults_18853 = GALGAS_boolAttribute::constructor_new (cast_17451_b.getter_oil_5F_desc (SOURCE_FILE ("implementation_types.galgas", 678)), cast_17451_b.getter_location (SOURCE_FILE ("implementation_types.galgas", 678)), cast_17451_b.getter_value (SOURCE_FILE ("implementation_types.galgas", 678)), var_subAttributes_18741  COMMA_SOURCE_FILE ("implementation_types.galgas", 678)) ;
        GALGAS_identifierMap var_attr_18960 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 679)) ;
        {
        var_attr_18960.setter_put (object->mAttribute_name, var_defaults_18853, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 680)) ;
        }
        {
        ioArgument_attributes.setter_setObjectParams (var_attr_18960 COMMA_SOURCE_FILE ("implementation_types.galgas", 681)) ;
        }
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impBoolType_setDefault (void) {
  enterExtensionMethod_setDefault (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                   extensionMethod_impBoolType_setDefault) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impBoolType_setDefault (defineExtensionMethod_impBoolType_setDefault, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension getter '@impEnumType mergeWithType'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impEnumType_mergeWithType (const cPtr_impType * inObject,
                                                                 GALGAS_impType inArgument_typeToMerge,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impEnumType * object = (const cPtr_impEnumType *) inObject ;
  macroValidSharedObject (object, cPtr_impEnumType) ;
  GALGAS_impEnumType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impEnumType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impEnumType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impEnumType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 716)) ;
    }
  }
  GALGAS_impEnumType var_castTypeToMerge_19902 = temp_0 ;
  result_mergedType = GALGAS_impEnumType::constructor_new (object->mAttribute_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 718)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 718)), object->mAttribute_type, object->mAttribute_name, object->mAttribute_multiple, object->mAttribute_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 722)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 722)), object->mAttribute_withAuto, object->mAttribute_defaultValue, extensionGetter_mergeWithEnum (object->mAttribute_valuesMap, var_castTypeToMerge_19902.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 725)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 725))  COMMA_SOURCE_FILE ("implementation_types.galgas", 717)) ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impEnumType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impEnumType.mSlotID,
                                      extensionGetter_impEnumType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impEnumType_mergeWithType (defineExtensionGetter_impEnumType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'verifyEnum'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyEnum (const GALGAS_impType constinArgument_anEnum,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_anEnum.isValid ()) {
    if (constinArgument_anEnum.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
      GALGAS_impEnumType cast_20350_realEnum ((cPtr_impEnumType *) constinArgument_anEnum.ptr ()) ;
      if (cast_20350_realEnum.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 737)).isValid ()) {
        if (cast_20350_realEnum.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 737)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_string_5F_class) {
          GALGAS_string_5F_class cast_20424_defaultValue ((cPtr_string_5F_class *) cast_20350_realEnum.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 737)).ptr ()) ;
          const enumGalgasBool test_0 = cast_20350_realEnum.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 739)).getter_hasKey (cast_20424_defaultValue.getter_value (SOURCE_FILE ("implementation_types.galgas", 739)) COMMA_SOURCE_FILE ("implementation_types.galgas", 739)).operator_not (SOURCE_FILE ("implementation_types.galgas", 739)).boolEnum () ;
          if (kBoolTrue == test_0) {
            TC_Array <C_FixItDescription> fixItArray1 ;
            inCompiler->emitSemanticError (cast_20424_defaultValue.getter_location (SOURCE_FILE ("implementation_types.galgas", 740)), GALGAS_string ("Default enum value does not match any enum value"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 740)) ;
          }
        }
      }
    }else{
      cEnumerator_locationList enumerator_20649 (constinArgument_anEnum.getter_locations (SOURCE_FILE ("implementation_types.galgas", 744)), kEnumeration_up) ;
      while (enumerator_20649.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_20649.current_location (HERE), GALGAS_string ("Internal, not an @impEnumType"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 745)) ;
        enumerator_20649.gotoNextObject () ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'checkAndGetIntegerNumber'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t function_checkAndGetIntegerNumber (const GALGAS_lstring & constinArgument_oil_5F_desc,
                                                      const GALGAS_dataType & constinArgument_type,
                                                      const GALGAS_luint_36__34_ & constinArgument_number,
                                                      const GALGAS_bool & constinArgument_signed,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_value ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_signed.boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 806)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_value = GALGAS_sint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 807)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 807)).getter_sint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 807)).multiply_operation (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 807)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 807))  COMMA_SOURCE_FILE ("implementation_types.galgas", 807)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 808)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_value = GALGAS_sint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 809)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 809)).getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 809)).multiply_operation (GALGAS_sint_36__34_ ((int64_t) 1LL).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 809)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 809))  COMMA_SOURCE_FILE ("implementation_types.galgas", 809)) ;
      }else if (kBoolFalse == test_2) {
        result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 811))  COMMA_SOURCE_FILE ("implementation_types.galgas", 811)) ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 812)), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 812)).add_operation (GALGAS_string (" expected, got a SINT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 812)), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 812)) ;
      }
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 815)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      result_value = GALGAS_sint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 816)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 816)).getter_sint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 816))  COMMA_SOURCE_FILE ("implementation_types.galgas", 816)) ;
    }else if (kBoolFalse == test_4) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 817)))).boolEnum () ;
      if (kBoolTrue == test_5) {
        result_value = GALGAS_sint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 818)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 818)).getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 818))  COMMA_SOURCE_FILE ("implementation_types.galgas", 818)) ;
      }else if (kBoolFalse == test_5) {
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 819)))).boolEnum () ;
        if (kBoolTrue == test_6) {
          result_value = GALGAS_uint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 820)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 820)).getter_uint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 820))  COMMA_SOURCE_FILE ("implementation_types.galgas", 820)) ;
        }else if (kBoolFalse == test_6) {
          const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 821)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            result_value = GALGAS_uint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 822)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 822))  COMMA_SOURCE_FILE ("implementation_types.galgas", 822)) ;
          }else if (kBoolFalse == test_7) {
            result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 824))  COMMA_SOURCE_FILE ("implementation_types.galgas", 824)) ;
            TC_Array <C_FixItDescription> fixItArray8 ;
            inCompiler->emitSemanticError (constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 825)), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 825)).add_operation (GALGAS_string (" expected, got a UINT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 825)), fixItArray8  COMMA_SOURCE_FILE ("implementation_types.galgas", 825)) ;
          }
        }
      }
    }
  }
//---
  return result_value ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkAndGetIntegerNumber [5] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_luint_36__34_,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkAndGetIntegerNumber (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_luint_36__34_ operand2 = GALGAS_luint_36__34_::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_bool operand3 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (3 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_checkAndGetIntegerNumber (operand0,
                                            operand1,
                                            operand2,
                                            operand3,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkAndGetIntegerNumber ("checkAndGetIntegerNumber",
                                                                          functionWithGenericHeader_checkAndGetIntegerNumber,
                                                                          & kTypeDescriptor_GALGAS_object_5F_t,
                                                                          4,
                                                                          functionArgs_checkAndGetIntegerNumber) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'checkAndGetFloatNumber'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t function_checkAndGetFloatNumber (const GALGAS_lstring & constinArgument_oil_5F_desc,
                                                    const GALGAS_dataType & constinArgument_type,
                                                    const GALGAS_ldouble & constinArgument_number,
                                                    const GALGAS_bool & constinArgument_signed,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_value ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_signed.boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 837)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_value = GALGAS_float_5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 838)), constinArgument_number.getter_double (SOURCE_FILE ("implementation_types.galgas", 838)).multiply_operation (GALGAS_double (1).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 838)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 838))  COMMA_SOURCE_FILE ("implementation_types.galgas", 838)) ;
    }else if (kBoolFalse == test_1) {
      result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 840))  COMMA_SOURCE_FILE ("implementation_types.galgas", 840)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 841)), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 841)).add_operation (GALGAS_string (" expected, got a FLOAT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 841)), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 841)) ;
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 844)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      result_value = GALGAS_float_5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 845)), constinArgument_number.getter_double (SOURCE_FILE ("implementation_types.galgas", 845))  COMMA_SOURCE_FILE ("implementation_types.galgas", 845)) ;
    }else if (kBoolFalse == test_3) {
      result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 847))  COMMA_SOURCE_FILE ("implementation_types.galgas", 847)) ;
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 848)), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848)).add_operation (GALGAS_string (" expected, got a FLOAT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848)), fixItArray4  COMMA_SOURCE_FILE ("implementation_types.galgas", 848)) ;
    }
  }
//---
  return result_value ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkAndGetFloatNumber [5] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_ldouble,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkAndGetFloatNumber (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_ldouble operand2 = GALGAS_ldouble::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_bool operand3 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (3 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_checkAndGetFloatNumber (operand0,
                                          operand1,
                                          operand2,
                                          operand3,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkAndGetFloatNumber ("checkAndGetFloatNumber",
                                                                        functionWithGenericHeader_checkAndGetFloatNumber,
                                                                        & kTypeDescriptor_GALGAS_object_5F_t,
                                                                        4,
                                                                        functionArgs_checkAndGetFloatNumber) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'checkTypeForAttribute'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkTypeForAttribute (const GALGAS_implementationObjectMap constinArgument_obj,
                                    const GALGAS_string constinArgument_attributeName,
                                    const GALGAS_dataType constinArgument_expectedType,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = constinArgument_obj.getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 857)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_type_24042 ;
    constinArgument_obj.method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 859)), var_type_24042, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 859)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_type_24042.getter_type (SOURCE_FILE ("implementation_types.galgas", 860)).objectCompare (constinArgument_expectedType)).boolEnum () ;
    if (kBoolTrue == test_1) {
      cEnumerator_locationList enumerator_24164 (var_type_24042.getter_locations (SOURCE_FILE ("implementation_types.galgas", 861)), kEnumeration_up) ;
      while (enumerator_24164.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_24164.current_location (HERE), constinArgument_attributeName.add_operation (GALGAS_string (" is a "), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 862)).add_operation (extensionGetter_oilType (var_type_24042.getter_type (SOURCE_FILE ("implementation_types.galgas", 862)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 862)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 862)), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 862)) ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (enumerator_24164.current_location (HERE), constinArgument_attributeName.add_operation (GALGAS_string (" should be a "), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 863)).add_operation (extensionGetter_oilType (constinArgument_expectedType, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 863)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 863)), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 863)) ;
        enumerator_24164.gotoNextObject () ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'boolSubAttributes'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap function_boolSubAttributes (const GALGAS_implementationObject & constinArgument_obj,
                                                           const GALGAS_string & constinArgument_attributeName,
                                                           const GALGAS_bool & constinArgument_boolValue,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_subImplementation ; // Returned variable
  result_subImplementation = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 874)) ;
  const enumGalgasBool test_0 = constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 875)).getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 875)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_type_24623 ;
    constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 877)).method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 877)), var_type_24623, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 877)) ;
    if (var_type_24623.isValid ()) {
      if (var_type_24623.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impBoolType) {
        GALGAS_impBoolType cast_24733_boolType ((cPtr_impBoolType *) var_type_24623.ptr ()) ;
        const enumGalgasBool test_1 = constinArgument_boolValue.boolEnum () ;
        if (kBoolTrue == test_1) {
          result_subImplementation = cast_24733_boolType.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 881)) ;
        }else if (kBoolFalse == test_1) {
          result_subImplementation = cast_24733_boolType.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 883)) ;
        }
      }
    }
  }
//---
  return result_subImplementation ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_boolSubAttributes [4] = {
  & kTypeDescriptor_GALGAS_implementationObject,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_boolSubAttributes (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_implementationObject operand0 = GALGAS_implementationObject::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                           inCompiler
                                                                                           COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_bool operand2 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_boolSubAttributes (operand0,
                                     operand1,
                                     operand2,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_boolSubAttributes ("boolSubAttributes",
                                                                   functionWithGenericHeader_boolSubAttributes,
                                                                   & kTypeDescriptor_GALGAS_implementationObjectMap,
                                                                   3,
                                                                   functionArgs_boolSubAttributes) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'enumSubAttributes'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap function_enumSubAttributes (const GALGAS_implementationObject & constinArgument_obj,
                                                           const GALGAS_string & constinArgument_attributeName,
                                                           const GALGAS_string & constinArgument_enumValue,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_subImplementation ; // Returned variable
  result_subImplementation = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 894)) ;
  const enumGalgasBool test_0 = constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 895)).getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 895)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_type_25202 ;
    constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 897)).method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 897)), var_type_25202, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 897)) ;
    if (var_type_25202.isValid ()) {
      if (var_type_25202.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
        GALGAS_impEnumType cast_25312_enumType ((cPtr_impEnumType *) var_type_25202.ptr ()) ;
        const enumGalgasBool test_1 = cast_25312_enumType.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 900)).getter_hasKey (constinArgument_enumValue COMMA_SOURCE_FILE ("implementation_types.galgas", 900)).boolEnum () ;
        if (kBoolTrue == test_1) {
          cast_25312_enumType.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 901)).method_get (function_lstringWith (constinArgument_enumValue, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)), result_subImplementation, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)) ;
        }
      }
    }
  }
//---
  return result_subImplementation ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_enumSubAttributes [4] = {
  & kTypeDescriptor_GALGAS_implementationObject,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_enumSubAttributes (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_implementationObject operand0 = GALGAS_implementationObject::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                           inCompiler
                                                                                           COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_enumSubAttributes (operand0,
                                     operand1,
                                     operand2,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_enumSubAttributes ("enumSubAttributes",
                                                                   functionWithGenericHeader_enumSubAttributes,
                                                                   & kTypeDescriptor_GALGAS_implementationObjectMap,
                                                                   3,
                                                                   functionArgs_enumSubAttributes) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'checkFilters'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkFilters (const GALGAS_implementationObject constinArgument_messageProperty,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap var_filter_25598 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 912)) ;
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 913)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 913)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("X"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 914)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 914)) ;
  }
  var_filter_25598 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWDIFFERSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 915)) ;
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 916)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 916)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("X"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 917)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 917)) ;
  }
  var_filter_25598 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSMASKEDOLD"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 918)) ;
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 919)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 919)) ;
  }
  var_filter_25598 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISWITHIN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 920)) ;
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MIN"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 921)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 921)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MAX"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 922)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 922)) ;
  }
  var_filter_25598 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISOUTSIDE"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 923)) ;
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MIN"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 924)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 924)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MAX"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 925)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 925)) ;
  }
  var_filter_25598 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("ONEEVERYN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 926)) ;
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("PERIOD"), GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 927)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 927)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("OFFSET"), GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 928)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 928)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@refType checkAttributeReferences'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_refType_checkAttributeReferences (const cPtr_impType * inObject,
                                                              const GALGAS_implementation constinArgument_imp,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_refType * object = (const cPtr_refType *) inObject ;
  macroValidSharedObject (object, cPtr_refType) ;
  const enumGalgasBool test_0 = callExtensionGetter_hasKey ((const cPtr_implementation *) constinArgument_imp.ptr (), object->mAttribute_ref.getter_string (SOURCE_FILE ("implementation_types.galgas", 943)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 943)).operator_not (SOURCE_FILE ("implementation_types.galgas", 943)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mAttribute_ref.getter_location (SOURCE_FILE ("implementation_types.galgas", 944)), object->mAttribute_ref.getter_string (SOURCE_FILE ("implementation_types.galgas", 944)).add_operation (GALGAS_string (" object kind does not exist"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 944)), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 944)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_refType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_refType.mSlotID,
                                                 extensionMethod_refType_checkAttributeReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_refType_checkAttributeReferences (defineExtensionMethod_refType_checkAttributeReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@impBoolType checkAttributeReferences'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impBoolType_checkAttributeReferences (const cPtr_impType * inObject,
                                                                  const GALGAS_implementation constinArgument_imp,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  cEnumerator_implementationObjectMap enumerator_27488 (object->mAttribute_trueSubAttributes, kEnumeration_up) ;
  while (enumerator_27488.hasCurrentObject ()) {
    callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_27488.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 952)) ;
    enumerator_27488.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_27571 (object->mAttribute_falseSubAttributes, kEnumeration_up) ;
  while (enumerator_27571.hasCurrentObject ()) {
    callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_27571.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 955)) ;
    enumerator_27571.gotoNextObject () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impBoolType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                                 extensionMethod_impBoolType_checkAttributeReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impBoolType_checkAttributeReferences (defineExtensionMethod_impBoolType_checkAttributeReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@impEnumType checkAttributeReferences'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impEnumType_checkAttributeReferences (const cPtr_impType * inObject,
                                                                  const GALGAS_implementation constinArgument_imp,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impEnumType * object = (const cPtr_impEnumType *) inObject ;
  macroValidSharedObject (object, cPtr_impEnumType) ;
  cEnumerator_enumValues enumerator_27731 (object->mAttribute_valuesMap, kEnumeration_up) ;
  while (enumerator_27731.hasCurrentObject ()) {
    cEnumerator_implementationObjectMap enumerator_27763 (enumerator_27731.current_subAttributes (HERE), kEnumeration_up) ;
    while (enumerator_27763.hasCurrentObject ()) {
      callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_27763.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 964)) ;
      enumerator_27763.gotoNextObject () ;
    }
    enumerator_27731.gotoNextObject () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impEnumType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_impEnumType.mSlotID,
                                                 extensionMethod_impEnumType_checkAttributeReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impEnumType_checkAttributeReferences (defineExtensionMethod_impEnumType_checkAttributeReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'setDefaultsForType'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setDefaultsForType (const GALGAS_implementationObjectMap constinArgument_impObject,
                                 GALGAS_objectAttributes & ioArgument_objectParams,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_implementationObjectMap enumerator_27955 (constinArgument_impObject, kEnumeration_up) ;
  while (enumerator_27955.hasCurrentObject ()) {
    if (enumerator_27955.current_type (HERE).isValid ()) {
      if (NULL != dynamic_cast <const cPtr_impAutoDefaultType *> (enumerator_27955.current_type (HERE).ptr ())) {
        GALGAS_impAutoDefaultType cast_28016_defaultType ((cPtr_impAutoDefaultType *) enumerator_27955.current_type (HERE).ptr ()) ;
        callExtensionMethod_setDefault ((const cPtr_impAutoDefaultType *) cast_28016_defaultType.ptr (), ioArgument_objectParams, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 976)) ;
      }
    }
    enumerator_27955.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Once function 'emptyLString'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring onceFunction_emptyLString (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_ls ; // Returned variable
  result_ls = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 29))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 29)) ;
//---
  return result_ls ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_emptyLString = false ;
static GALGAS_lstring gOnceFunctionResult_emptyLString ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_emptyLString (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_emptyLString) {
    gOnceFunctionResult_emptyLString = onceFunction_emptyLString (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_emptyLString = true ;
  }
  return gOnceFunctionResult_emptyLString ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_emptyLString (void) {
  gOnceFunctionResult_emptyLString.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_emptyLString (NULL,
                                                          releaseOnceFunctionResult_emptyLString) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyLString [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyLString (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_emptyLString (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyLString ("emptyLString",
                                                              functionWithGenericHeader_emptyLString,
                                                              & kTypeDescriptor_GALGAS_lstring,
                                                              0,
                                                              functionArgs_emptyLString) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'emptyObject'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_emptyObject (C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_result ; // Returned variable
  result_result = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_basic_types.galgas", 52))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 52)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyObject [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyObject (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_emptyObject (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyObject ("emptyObject",
                                                             functionWithGenericHeader_emptyObject,
                                                             & kTypeDescriptor_GALGAS_objectAttributes,
                                                             0,
                                                             functionArgs_emptyObject) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'multipleAttributeOrError'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList function_multipleAttributeOrError (const GALGAS_object_5F_t & constinArgument_t,
                                                         const GALGAS_string & constinArgument_att,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList result_v ; // Returned variable
  result_v = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("goil_basic_types.galgas", 71)) ;
  if (constinArgument_t.isValid ()) {
    if (constinArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
      GALGAS_multipleAttribute cast_1710_l ((cPtr_multipleAttribute *) constinArgument_t.ptr ()) ;
      result_v = cast_1710_l.getter_items (SOURCE_FILE ("goil_basic_types.galgas", 74)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 76)), GALGAS_string ("Internal error, ").add_operation (constinArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 76)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 76)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 76)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_multipleAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_multipleAttributeOrError (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_multipleAttributeOrError (operand0,
                                            operand1,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_multipleAttributeOrError ("multipleAttributeOrError",
                                                                          functionWithGenericHeader_multipleAttributeOrError,
                                                                          & kTypeDescriptor_GALGAS_identifierList,
                                                                          2,
                                                                          functionArgs_multipleAttributeOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'boolAttributeOrError'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_boolAttributeOrError (GALGAS_object_5F_t inArgument_t,
                                           GALGAS_string inArgument_att,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_v ; // Returned variable
  result_v = GALGAS_bool (false) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_2046_attribute ((cPtr_boolAttribute *) inArgument_t.ptr ()) ;
      result_v = cast_2046_attribute.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 92)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 94)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 94)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 94)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 94)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_boolAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_boolAttributeOrError (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_boolAttributeOrError (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_boolAttributeOrError ("boolAttributeOrError",
                                                                      functionWithGenericHeader_boolAttributeOrError,
                                                                      & kTypeDescriptor_GALGAS_bool,
                                                                      2,
                                                                      functionArgs_boolAttributeOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'uint32_or_error'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint function_uint_33__32__5F_or_5F_error (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint result_v ; // Returned variable
  result_v = GALGAS_uint ((uint32_t) 0U) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      GALGAS_uint_33__32__5F_class cast_2567_ui ((cPtr_uint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_2567_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 123)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 125)), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 125)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 125)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_33__32__5F_or_5F_error [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_33__32__5F_or_5F_error (C_Compiler * inCompiler,
                                                                            const cObjectArray & inEffectiveParameterArray,
                                                                            const GALGAS_location & /* inErrorLocation */
                                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_33__32__5F_or_5F_error (operand0,
                                               operand1,
                                               inCompiler
                                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_33__32__5F_or_5F_error ("uint32_or_error",
                                                                             functionWithGenericHeader_uint_33__32__5F_or_5F_error,
                                                                             & kTypeDescriptor_GALGAS_uint,
                                                                             2,
                                                                             functionArgs_uint_33__32__5F_or_5F_error) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'uint32OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint function_uint_33__32_OrError (GALGAS_object_5F_t inArgument_t,
                                          GALGAS_string inArgument_att,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint result_v ; // Returned variable
  result_v = GALGAS_uint ((uint32_t) 0U) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      GALGAS_uint_33__32__5F_class cast_2766_ui ((cPtr_uint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_2766_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 136)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 138)), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 138)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 138)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_33__32_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_33__32_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_33__32_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_33__32_OrError ("uint32OrError",
                                                                     functionWithGenericHeader_uint_33__32_OrError,
                                                                     & kTypeDescriptor_GALGAS_uint,
                                                                     2,
                                                                     functionArgs_uint_33__32_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'sint32OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint function_sint_33__32_OrError (GALGAS_object_5F_t inArgument_t,
                                          GALGAS_string inArgument_att,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint result_v ; // Returned variable
  result_v = GALGAS_sint ((int32_t) 0L) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      GALGAS_sint_33__32__5F_class cast_3104_ui ((cPtr_sint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_3104_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 156)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 158)), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 158)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 158)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_33__32_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_33__32_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_sint_33__32_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_33__32_OrError ("sint32OrError",
                                                                     functionWithGenericHeader_sint_33__32_OrError,
                                                                     & kTypeDescriptor_GALGAS_sint,
                                                                     2,
                                                                     functionArgs_sint_33__32_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'uint64OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ function_uint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_uint_36__34_ ((uint64_t) 0ULL) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_3442_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_3442_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 176)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 178)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 178)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 178)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 178)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_36__34_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_36__34_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_36__34_OrError ("uint64OrError",
                                                                     functionWithGenericHeader_uint_36__34_OrError,
                                                                     & kTypeDescriptor_GALGAS_uint_36__34_,
                                                                     2,
                                                                     functionArgs_uint_36__34_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'luint64OrError'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint_36__34_ function_luint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                    GALGAS_string inArgument_att,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result_v ; // Returned variable
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_3660_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = GALGAS_luint_36__34_::constructor_new (cast_3660_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 188)), cast_3660_ui.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 188))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 188)) ;
    }else{
      result_v = GALGAS_luint_36__34_::constructor_new (GALGAS_uint_36__34_ ((uint64_t) 0ULL), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 190))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 190)) ;
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 191)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 191)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 191)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 191)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_luint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_luint_36__34_OrError (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_luint_36__34_OrError (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_luint_36__34_OrError ("luint64OrError",
                                                                      functionWithGenericHeader_luint_36__34_OrError,
                                                                      & kTypeDescriptor_GALGAS_luint_36__34_,
                                                                      2,
                                                                      functionArgs_luint_36__34_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'sint64OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ function_sint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_sint_36__34_ ((int64_t) 0LL) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      GALGAS_sint_36__34__5F_class cast_4102_ui ((cPtr_sint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4102_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 209)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 211)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 211)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 211)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 211)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_36__34_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_sint_36__34_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_36__34_OrError ("sint64OrError",
                                                                     functionWithGenericHeader_sint_36__34_OrError,
                                                                     & kTypeDescriptor_GALGAS_sint_36__34_,
                                                                     2,
                                                                     functionArgs_sint_36__34_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'floatOrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double function_floatOrError (GALGAS_object_5F_t inArgument_t,
                                     GALGAS_string inArgument_att,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_v ; // Returned variable
  result_v = GALGAS_double (0) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      GALGAS_float_5F_class cast_4452_ui ((cPtr_float_5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4452_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 229)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 231)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 231)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 231)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 231)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_floatOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_floatOrError (C_Compiler * inCompiler,
                                                             const cObjectArray & inEffectiveParameterArray,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_floatOrError (operand0,
                                operand1,
                                inCompiler
                                COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_floatOrError ("floatOrError",
                                                              functionWithGenericHeader_floatOrError,
                                                              & kTypeDescriptor_GALGAS_double,
                                                              2,
                                                              functionArgs_floatOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'stringAttributeOrError'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_stringAttributeOrError (const GALGAS_object_5F_t & constinArgument_attribute,
                                                const GALGAS_string & constinArgument_attributeName,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  result_result = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 253)) ;
  if (constinArgument_attribute.isValid ()) {
    if (constinArgument_attribute.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_stringAttribute) {
      GALGAS_stringAttribute cast_5004_attribute ((cPtr_stringAttribute *) constinArgument_attribute.ptr ()) ;
      result_result = GALGAS_lstring::constructor_new (cast_5004_attribute.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 256)), cast_5004_attribute.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 256))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 256)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_attribute.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 258)), GALGAS_string ("Internal error ").add_operation (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 258)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 258)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 258)) ;
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringAttributeOrError (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_stringAttributeOrError (operand0,
                                          operand1,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringAttributeOrError ("stringAttributeOrError",
                                                                        functionWithGenericHeader_stringAttributeOrError,
                                                                        & kTypeDescriptor_GALGAS_lstring,
                                                                        2,
                                                                        functionArgs_stringAttributeOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'empty_lstring'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_empty_5F_lstring (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_ls ; // Returned variable
  result_ls = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 428))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 428)) ;
//---
  return result_ls ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_empty_5F_lstring [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_empty_5F_lstring (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_empty_5F_lstring (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_empty_5F_lstring ("empty_lstring",
                                                                  functionWithGenericHeader_empty_5F_lstring,
                                                                  & kTypeDescriptor_GALGAS_lstring,
                                                                  0,
                                                                  functionArgs_empty_5F_lstring) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'void_obj'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t function_void_5F_obj (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_v ; // Returned variable
  result_v = GALGAS_void::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 433)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 433))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 433)) ;
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_void_5F_obj [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_void_5F_obj (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_void_5F_obj (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_void_5F_obj ("void_obj",
                                                             functionWithGenericHeader_void_5F_obj,
                                                             & kTypeDescriptor_GALGAS_object_5F_t,
                                                             0,
                                                             functionArgs_void_5F_obj) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'luint64_value'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint_36__34_ function_luint_36__34__5F_value (const GALGAS_uint_36__34__5F_class & constinArgument_c,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_luint_36__34_::constructor_new (constinArgument_c.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 627)), constinArgument_c.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 627))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 627)) ;
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_luint_36__34__5F_value [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34__5F_class,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_luint_36__34__5F_value (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_uint_36__34__5F_class operand0 = GALGAS_uint_36__34__5F_class::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                             inCompiler
                                                                                             COMMA_THERE) ;
  return function_luint_36__34__5F_value (operand0,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_luint_36__34__5F_value ("luint64_value",
                                                                        functionWithGenericHeader_luint_36__34__5F_value,
                                                                        & kTypeDescriptor_GALGAS_luint_36__34_,
                                                                        1,
                                                                        functionArgs_luint_36__34__5F_value) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'projectName'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_projectName (C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_directory ; // Returned variable
  result_directory = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 30)).getter_stringByDeletingPathExtension (SOURCE_FILE ("goil_routines.galgas", 30)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string (gOption_goil_5F_options_project_5F_dir.getter_value ()).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_directory = GALGAS_string (gOption_goil_5F_options_project_5F_dir.getter_value ()) ;
  }
//---
  return result_directory ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_projectName [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_projectName (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_projectName (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_projectName ("projectName",
                                                             functionWithGenericHeader_projectName,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             0,
                                                             functionArgs_projectName) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'oil_dir'                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_oil_5F_dir (C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_dir ; // Returned variable
  result_dir = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 37)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_routines.galgas", 37)) ;
//---
  return result_dir ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_oil_5F_dir [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_oil_5F_dir (C_Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_oil_5F_dir (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_oil_5F_dir ("oil_dir",
                                                            functionWithGenericHeader_oil_5F_dir,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_oil_5F_dir) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Function 'arch'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_arch (C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_arch_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1211 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 45)) ;
  var_components_1211.method_first (result_arch_5F_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 46)) ;
//---
  return result_arch_5F_name ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_arch [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_arch (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_arch (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_arch ("arch",
                                                      functionWithGenericHeader_arch,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_arch) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Function 'chip'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_chip (C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_chip_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1528 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 54)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_components_1528.getter_length (SOURCE_FILE ("goil_routines.galgas", 55)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_chip_5F_name = var_components_1528.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 56)) ;
  }else if (kBoolFalse == test_0) {
    result_chip_5F_name = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_chip_5F_name ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_chip [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_chip (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_chip (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_chip ("chip",
                                                      functionWithGenericHeader_chip,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_chip) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Function 'board'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_board (C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_board_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1946 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 68)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_components_1946.getter_length (SOURCE_FILE ("goil_routines.galgas", 69)).objectCompare (GALGAS_uint ((uint32_t) 2U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    GALGAS_string joker_2090 ; // Joker input parameter
    var_components_1946.setter_popFirst (joker_2090, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 70)) ;
    }
    {
    GALGAS_string joker_2121 ; // Joker input parameter
    var_components_1946.setter_popFirst (joker_2121, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 71)) ;
    }
    result_board_5F_name = GALGAS_string::constructor_componentsJoinedByString (var_components_1946, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 72)) ;
  }else if (kBoolFalse == test_0) {
    result_board_5F_name = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_board_5F_name ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_board [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_board (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_board (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_board ("board",
                                                       functionWithGenericHeader_board,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_board) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'targetPathList'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list function_targetPathList (C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_list result_pathList ; // Returned variable
  GALGAS_stringlist var_components_2360 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 82)) ;
  result_pathList = GALGAS_list::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 83)) ;
  cEnumerator_stringlist enumerator_2500 (var_components_2360, kEnumeration_up) ;
  while (enumerator_2500.hasCurrentObject ()) {
    GALGAS_gtlData var_cont_2521 = GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 85)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 85)), enumerator_2500.current_mValue (HERE)  COMMA_SOURCE_FILE ("goil_routines.galgas", 85)) ;
    result_pathList.addAssign_operation (var_cont_2521  COMMA_SOURCE_FILE ("goil_routines.galgas", 86)) ;
    enumerator_2500.gotoNextObject () ;
  }
//---
  return result_pathList ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_targetPathList [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_targetPathList (C_Compiler * inCompiler,
                                                               const cObjectArray & /* inEffectiveParameterArray */,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  return function_targetPathList (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_targetPathList ("targetPathList",
                                                                functionWithGenericHeader_targetPathList,
                                                                & kTypeDescriptor_GALGAS_list,
                                                                0,
                                                                functionArgs_targetPathList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'add_path_component'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_add_5F_path_5F_component (GALGAS_string inArgument_path,
                                                 GALGAS_string inArgument_component,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_new_5F_path ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_path.getter_characterAtIndex (inArgument_path.getter_length (SOURCE_FILE ("goil_routines.galgas", 97)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 97)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 97)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_new_5F_path = inArgument_path.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 98)).add_operation (inArgument_component, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 98)) ;
  }else if (kBoolFalse == test_0) {
    result_new_5F_path = inArgument_path.add_operation (inArgument_component, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 100)) ;
  }
//---
  return result_new_5F_path ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_add_5F_path_5F_component [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_add_5F_path_5F_component (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_add_5F_path_5F_component (operand0,
                                            operand1,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_add_5F_path_5F_component ("add_path_component",
                                                                          functionWithGenericHeader_add_5F_path_5F_component,
                                                                          & kTypeDescriptor_GALGAS_string,
                                                                          2,
                                                                          functionArgs_add_5F_path_5F_component) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'rootTemplatesDirectory'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_rootTemplatesDirectory (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_templateDirectory ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string (gOption_goil_5F_options_template_5F_dir.getter_value ()).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_templateDirectory = GALGAS_string (gOption_goil_5F_options_template_5F_dir.getter_value ()) ;
  }else if (kBoolFalse == test_0) {
    GALGAS_string var_env_3086 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_TEMPLATES")  COMMA_SOURCE_FILE ("goil_routines.galgas", 110)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_env_3086.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_templateDirectory = var_env_3086 ;
    }else if (kBoolFalse == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 114)), GALGAS_string ("The templates path is not set. Use --templates option or set the GOIL_TEMPLATES environment variable"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 114)) ;
      result_templateDirectory.drop () ; // Release error dropped variable
    }
  }
  result_templateDirectory = result_templateDirectory.getter_unixPathWithNativePath (SOURCE_FILE ("goil_routines.galgas", 118)) ;
  result_templateDirectory = result_templateDirectory.getter_stringByStandardizingPath (SOURCE_FILE ("goil_routines.galgas", 119)) ;
  const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, result_templateDirectory.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 121)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
  if (kBoolTrue == test_3) {
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, result_templateDirectory.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 122)).objectCompare (GALGAS_char (TO_UNICODE (126)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      GALGAS_string var_home_3651 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("HOME")  COMMA_SOURCE_FILE ("goil_routines.galgas", 123)) ;
      GALGAS_string var_relativeToHome_3738 = result_templateDirectory.getter_rightSubString (result_templateDirectory.getter_length (SOURCE_FILE ("goil_routines.galgas", 124)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 124)) COMMA_SOURCE_FILE ("goil_routines.galgas", 124)) ;
      result_templateDirectory = var_home_3651.add_operation (var_relativeToHome_3738, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 125)) ;
    }else if (kBoolFalse == test_4) {
      GALGAS_string var_currentDirectory_3895 = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 127)) ;
      result_templateDirectory = var_currentDirectory_3895.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 128)).add_operation (result_templateDirectory, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 128)) ;
    }
    result_templateDirectory = result_templateDirectory.getter_stringByStandardizingPath (SOURCE_FILE ("goil_routines.galgas", 130)) ;
  }
//---
  return result_templateDirectory ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_rootTemplatesDirectory [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_rootTemplatesDirectory (C_Compiler * inCompiler,
                                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  return function_rootTemplatesDirectory (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_rootTemplatesDirectory ("rootTemplatesDirectory",
                                                                        functionWithGenericHeader_rootTemplatesDirectory,
                                                                        & kTypeDescriptor_GALGAS_string,
                                                                        0,
                                                                        functionArgs_rootTemplatesDirectory) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'templates_directory'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_templates_5F_directory (GALGAS_string inArgument_prefix,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_temp_5F_dir ; // Returned variable
  result_temp_5F_dir = function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 135)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_temp_5F_dir = function_add_5F_path_5F_component (result_temp_5F_dir, inArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 137)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 139)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_string var_curdir_4402 = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 140)) ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).objectCompare (GALGAS_char (TO_UNICODE (46)))).operator_and (GALGAS_bool (kIsEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).objectCompare (GALGAS_char (TO_UNICODE (47)))) COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_temp_5F_dir = result_temp_5F_dir.getter_stringByRemovingCharacterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 142)).getter_stringByRemovingCharacterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 142)) ;
      }
      result_temp_5F_dir = var_curdir_4402.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 144)).add_operation (result_temp_5F_dir, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 144)) ;
    }
    const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.getter_characterAtIndex (result_temp_5F_dir.getter_length (SOURCE_FILE ("goil_routines.galgas", 146)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 146)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 146)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      result_temp_5F_dir.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 147)) ;
    }
  }
//---
  return result_temp_5F_dir ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_templates_5F_directory [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_templates_5F_directory (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_templates_5F_directory (operand0,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_templates_5F_directory ("templates_directory",
                                                                        functionWithGenericHeader_templates_5F_directory,
                                                                        & kTypeDescriptor_GALGAS_string,
                                                                        1,
                                                                        functionArgs_templates_5F_directory) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'templateFilePath'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_templateFilePath (const GALGAS_string & constinArgument_prefix,
                                         const GALGAS_string & constinArgument_file,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_path ; // Returned variable
  GALGAS_stringlist var_components_5004 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 158)) ;
  GALGAS_string var_templateDir_5107 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 159)) ;
  GALGAS_bool var_notFound_5155 = GALGAS_bool (true) ;
  GALGAS_bool var_notOver_5178 = GALGAS_bool (true) ;
  result_path = GALGAS_string::makeEmptyString () ;
  if (var_components_5004.getter_length (SOURCE_FILE ("goil_routines.galgas", 164)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 164)).isValid ()) {
    uint32_t variant_5207 = var_components_5004.getter_length (SOURCE_FILE ("goil_routines.galgas", 164)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 164)).uintValue () ;
    bool loop_5207 = true ;
    while (loop_5207) {
      loop_5207 = var_notFound_5155.operator_and (var_notOver_5178 COMMA_SOURCE_FILE ("goil_routines.galgas", 165)).isValid () ;
      if (loop_5207) {
        loop_5207 = var_notFound_5155.operator_and (var_notOver_5178 COMMA_SOURCE_FILE ("goil_routines.galgas", 165)).boolValue () ;
      }
      if (loop_5207 && (0 == variant_5207)) {
        loop_5207 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 164)) ;
      }
      if (loop_5207) {
        variant_5207 -- ;
        GALGAS_string var_targetPath_5284 = var_templateDir_5107.add_operation (GALGAS_string::constructor_componentsJoinedByString (var_components_5004, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 166)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)) ;
        const enumGalgasBool test_0 = var_targetPath_5284.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 168)).boolEnum () ;
        if (kBoolTrue == test_0) {
          var_notFound_5155 = GALGAS_bool (false) ;
          result_path = var_targetPath_5284 ;
        }
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, var_components_5004.getter_length (SOURCE_FILE ("goil_routines.galgas", 172)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          GALGAS_string joker_5560 ; // Joker input parameter
          var_components_5004.setter_popLast (joker_5560, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 173)) ;
          }
        }else if (kBoolFalse == test_1) {
          var_notOver_5178 = GALGAS_bool (false) ;
        }
      }
    }
  }
//---
  return result_path ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_templateFilePath [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_templateFilePath (C_Compiler * inCompiler,
                                                                 const cObjectArray & inEffectiveParameterArray,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_templateFilePath (operand0,
                                    operand1,
                                    inCompiler
                                    COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_templateFilePath ("templateFilePath",
                                                                  functionWithGenericHeader_templateFilePath,
                                                                  & kTypeDescriptor_GALGAS_string,
                                                                  2,
                                                                  functionArgs_templateFilePath) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'allTemplatePaths'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist function_allTemplatePaths (const GALGAS_string & constinArgument_prefix,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist result_paths ; // Returned variable
  GALGAS_stringlist var_components_5703 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 184)) ;
  GALGAS_string var_partialPath_5806 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 185)) ;
  result_paths = GALGAS_stringlist::constructor_listWithValue (var_partialPath_5806  COMMA_SOURCE_FILE ("goil_routines.galgas", 187)) ;
  cEnumerator_stringlist enumerator_5938 (var_components_5703, kEnumeration_up) ;
  while (enumerator_5938.hasCurrentObject ()) {
    var_partialPath_5806 = function_add_5F_path_5F_component (var_partialPath_5806, enumerator_5938.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 190)) ;
    {
    result_paths.setter_insertAtIndex (var_partialPath_5806, GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 191)) ;
    }
    enumerator_5938.gotoNextObject () ;
  }
//---
  return result_paths ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_allTemplatePaths [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_allTemplatePaths (C_Compiler * inCompiler,
                                                                 const cObjectArray & inEffectiveParameterArray,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_allTemplatePaths (operand0,
                                    inCompiler
                                    COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_allTemplatePaths ("allTemplatePaths",
                                                                  functionWithGenericHeader_allTemplatePaths,
                                                                  & kTypeDescriptor_GALGAS_stringlist,
                                                                  1,
                                                                  functionArgs_allTemplatePaths) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'checkTemplatesPath'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkTemplatesPath (C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_configDir_6102 = function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 197)).add_operation (GALGAS_string ("/config"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 197)) ;
  const enumGalgasBool test_0 = var_configDir_6102.getter_directoryExists (SOURCE_FILE ("goil_routines.galgas", 198)).operator_not (SOURCE_FILE ("goil_routines.galgas", 198)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)), GALGAS_string ("The templates path '").add_operation (var_configDir_6102, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 199)).add_operation (GALGAS_string ("' is not set to the templates directory"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 199)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)) ;
  }else if (kBoolFalse == test_0) {
    GALGAS_string var_partialPath_6319 = var_configDir_6102 ;
    GALGAS_bool var_continueIt_6352 = GALGAS_bool (true) ;
    GALGAS_stringlist var_components_6386 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 203)) ;
    cEnumerator_stringlist enumerator_6504 (var_components_6386, kEnumeration_up) ;
    while (enumerator_6504.hasCurrentObject ()) {
      var_partialPath_6319 = var_partialPath_6319.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 205)).add_operation (enumerator_6504.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 205)) ;
      GALGAS_bool test_2 = var_continueIt_6352 ;
      if (kBoolTrue == test_2.boolEnum ()) {
        test_2 = var_partialPath_6319.getter_directoryExists (SOURCE_FILE ("goil_routines.galgas", 206)).operator_not (SOURCE_FILE ("goil_routines.galgas", 206)) ;
      }
      const enumGalgasBool test_3 = test_2.boolEnum () ;
      if (kBoolTrue == test_3) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 207)), GALGAS_string ("The templates path '").add_operation (var_partialPath_6319, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 207)).add_operation (GALGAS_string ("' does not exist in the templates directory"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 207)), fixItArray4  COMMA_SOURCE_FILE ("goil_routines.galgas", 207)) ;
        var_continueIt_6352 = GALGAS_bool (false) ;
      }
      enumerator_6504.gotoNextObject () ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'allTemplateFilePaths'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist function_allTemplateFilePaths (const GALGAS_string & constinArgument_prefix,
                                                 const GALGAS_string & constinArgument_file,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist result_paths ; // Returned variable
  GALGAS_stringlist var_components_6901 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 220)) ;
  GALGAS_string var_templateDir_7004 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 221)) ;
  GALGAS_bool var_notOver_7051 = GALGAS_bool (true) ;
  result_paths = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 223)) ;
  if (var_components_6901.getter_length (SOURCE_FILE ("goil_routines.galgas", 225)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 225)).isValid ()) {
    uint32_t variant_7101 = var_components_6901.getter_length (SOURCE_FILE ("goil_routines.galgas", 225)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 225)).uintValue () ;
    bool loop_7101 = true ;
    while (loop_7101) {
      loop_7101 = var_notOver_7051.isValid () ;
      if (loop_7101) {
        loop_7101 = var_notOver_7051.boolValue () ;
      }
      if (loop_7101 && (0 == variant_7101)) {
        loop_7101 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 225)) ;
      }
      if (loop_7101) {
        variant_7101 -- ;
        GALGAS_string var_intermediatePath_7173 = GALGAS_string::constructor_componentsJoinedByString (var_components_6901, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 227)) ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_intermediatePath_7173.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          var_intermediatePath_7173.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 228)) ;
        }
        GALGAS_string var_targetPath_7315 = var_templateDir_7004.add_operation (var_intermediatePath_7173, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 229)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 229)) ;
        const enumGalgasBool test_1 = var_targetPath_7315.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 231)).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_paths.addAssign_operation (var_targetPath_7315  COMMA_SOURCE_FILE ("goil_routines.galgas", 232)) ;
        }
        const enumGalgasBool test_2 = GALGAS_bool (kIsStrictSup, var_components_6901.getter_length (SOURCE_FILE ("goil_routines.galgas", 234)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_2) {
          {
          GALGAS_string joker_7530 ; // Joker input parameter
          var_components_6901.setter_popLast (joker_7530, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 235)) ;
          }
        }else if (kBoolFalse == test_2) {
          var_notOver_7051 = GALGAS_bool (false) ;
        }
      }
    }
  }
//---
  return result_paths ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_allTemplateFilePaths [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_allTemplateFilePaths (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_allTemplateFilePaths (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_allTemplateFilePaths ("allTemplateFilePaths",
                                                                      functionWithGenericHeader_allTemplateFilePaths,
                                                                      & kTypeDescriptor_GALGAS_stringlist,
                                                                      2,
                                                                      functionArgs_allTemplateFilePaths) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Routine 'prefix'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_prefix (GALGAS_prefix_5F_map inArgument_p,
                     GALGAS_string inArgument_key,
                     GALGAS_string & outArgument_val,
                     C_Compiler * inCompiler
                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_val.drop () ; // Release 'out' argument
  GALGAS_lstring var_lkey_7653 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 243))  COMMA_SOURCE_FILE ("goil_routines.galgas", 243)) ;
  GALGAS_string joker_7720 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey_7653, outArgument_val, joker_7720, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 244)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'performReplace'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_performReplace (GALGAS_prefix_5F_map inArgument_p,
                             GALGAS_string inArgument_key,
                             GALGAS_string inArgument_name,
                             GALGAS_string & ioArgument_res,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkey_7821 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 248))  COMMA_SOURCE_FILE ("goil_routines.galgas", 248)) ;
  GALGAS_string var_prefix_7880 ;
  GALGAS_string var_tag_5F_to_5F_rep_7903 ;
  inArgument_p.method_prefix (var_lkey_7821, var_prefix_7880, var_tag_5F_to_5F_rep_7903, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 251)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep_7903, var_prefix_7880.add_operation (inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 252)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 252)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'doReplace'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_doReplace (GALGAS_string & ioArgument_s,
                        GALGAS_string inArgument_o,
                        GALGAS_string inArgument_n,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_n, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 256)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'do_replace_default'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_do_5F_replace_5F_default (GALGAS_string & ioArgument_s,
                                       GALGAS_string inArgument_o,
                                       GALGAS_string inArgument_n,
                                       GALGAS_string inArgument_d,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_n.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_n, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 261)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_d, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 263)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'replace_no_prefix'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_replace_5F_no_5F_prefix (GALGAS_prefix_5F_map inArgument_p,
                                      GALGAS_string inArgument_key,
                                      GALGAS_string inArgument_name,
                                      GALGAS_string & ioArgument_res,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkey_8426 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 268))  COMMA_SOURCE_FILE ("goil_routines.galgas", 268)) ;
  GALGAS_string var_tag_5F_to_5F_rep_8511 ;
  GALGAS_string joker_8533 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey_8426, joker_8533, var_tag_5F_to_5F_rep_8511, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 271)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep_8511, inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 272)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'table_core'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_table_5F_core (GALGAS_string inArgument_typename,
                            GALGAS_string inArgument_varname,
                            GALGAS_string inArgument_obj_5F_prefix,
                            GALGAS_stringset inArgument_names,
                            GALGAS_string & ioArgument_header,
                            GALGAS_string & ioArgument_implementation,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_n_8962 = GALGAS_uint ((uint32_t) 0U) ;
  cEnumerator_stringset enumerator_8999 (inArgument_names, kEnumeration_up) ;
  while (enumerator_8999.hasCurrentObject ()) {
    ioArgument_header = ioArgument_header.add_operation (GALGAS_string ("#define "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (inArgument_varname, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("_id_of_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (enumerator_8999.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("  "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (var_n_8962.getter_string (SOURCE_FILE ("goil_routines.galgas", 291)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)) ;
    ioArgument_header = ioArgument_header.add_operation (GALGAS_string ("#define "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (enumerator_8999.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("  "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (inArgument_varname, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("_id_of_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (enumerator_8999.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)) ;
    ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string ("    (tpl_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (inArgument_typename, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (GALGAS_string (" *)&"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (inArgument_obj_5F_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (enumerator_8999.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)) ;
    var_n_8962.increment_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 301)) ;
    const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_n_8962.objectCompare (inArgument_names.getter_count (SOURCE_FILE ("goil_routines.galgas", 302)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string (",\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 303)) ;
    }else if (kBoolFalse == test_0) {
      ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 304)) ;
    }
    enumerator_8999.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'add_to_stringset'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_to_5F_stringset (GALGAS_stringset & ioArgument_ss,
                                     GALGAS_string inArgument_new,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = ioArgument_ss.getter_hasKey (inArgument_new COMMA_SOURCE_FILE ("goil_routines.galgas", 409)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 410)), GALGAS_string ("'").add_operation (inArgument_new, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 410)).add_operation (GALGAS_string ("' is already declared before"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 410)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 410)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_ss.addAssign_operation (inArgument_new  COMMA_SOURCE_FILE ("goil_routines.galgas", 412)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'file_in_path'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_file_5F_in_5F_path (GALGAS_lstring & ioArgument_file_5F_name,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_include_5F_path_12819 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_INCLUDE_PATH")  COMMA_SOURCE_FILE ("goil_routines.galgas", 418)) ;
  GALGAS_stringlist var_systemPaths_13034 = function_allTemplatePaths (GALGAS_string ("config"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 422)) ;
  GALGAS_stringlist var_includePathList_13096 ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_include_5F_path_12819.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_includePathList_13096 = var_include_5F_path_12819.getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("goil_routines.galgas", 425)) ;
  }else if (kBoolFalse == test_0) {
    var_includePathList_13096 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 427)) ;
  }
  GALGAS_stringlist var_path_5F_list_13290 = var_includePathList_13096.add_operation (var_systemPaths_13034, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 429)) ;
  GALGAS_bool var_not_5F_found_13343 = GALGAS_bool (true) ;
  cEnumerator_stringlist enumerator_13387 (var_path_5F_list_13290, kEnumeration_up) ;
  while (enumerator_13387.hasCurrentObject ()) {
    GALGAS_string var_full_5F_file_5F_path_13421 = enumerator_13387.current_mValue (HERE) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_full_5F_file_5F_path_13421.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, var_full_5F_file_5F_path_13421.getter_characterAtIndex (var_full_5F_file_5F_path_13421.getter_length (SOURCE_FILE ("goil_routines.galgas", 435)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 435)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 435)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_full_5F_file_5F_path_13421.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 436)) ;
      }
    }
    var_full_5F_file_5F_path_13421.plusAssign_operation(ioArgument_file_5F_name.getter_string (SOURCE_FILE ("goil_routines.galgas", 439)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 439)) ;
    const enumGalgasBool test_3 = var_full_5F_file_5F_path_13421.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 440)).operator_and (var_not_5F_found_13343 COMMA_SOURCE_FILE ("goil_routines.galgas", 440)).boolEnum () ;
    if (kBoolTrue == test_3) {
      ioArgument_file_5F_name = GALGAS_lstring::constructor_new (var_full_5F_file_5F_path_13421, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 441))  COMMA_SOURCE_FILE ("goil_routines.galgas", 441)) ;
      var_not_5F_found_13343 = GALGAS_bool (false) ;
    }
    enumerator_13387.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'is_in_lstringlist'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_is_5F_in_5F_lstringlist (GALGAS_lstringlist inArgument_l,
                                      GALGAS_lstring inArgument_e,
                                      GALGAS_lstring & outArgument_f,
                                      GALGAS_bool & outArgument_p,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_f.drop () ; // Release 'out' argument
  outArgument_p.drop () ; // Release 'out' argument
  outArgument_p = GALGAS_bool (false) ;
  outArgument_f = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 453))  COMMA_SOURCE_FILE ("goil_routines.galgas", 453)) ;
  cEnumerator_lstringlist enumerator_14030 (inArgument_l, kEnumeration_up) ;
  while (enumerator_14030.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_14030.current_mValue (HERE).getter_string (SOURCE_FILE ("goil_routines.galgas", 455)).objectCompare (inArgument_e.getter_string (SOURCE_FILE ("goil_routines.galgas", 455)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_p = GALGAS_bool (true) ;
      outArgument_f = enumerator_14030.current_mValue (HERE) ;
    }
    enumerator_14030.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'isInLstringlist'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_isInLstringlist (GALGAS_lstringlist inArgument_l,
                                      GALGAS_lstring inArgument_e,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_p ; // Returned variable
  result_p = GALGAS_bool (false) ;
  cEnumerator_lstringlist enumerator_14228 (inArgument_l, kEnumeration_up) ;
  while (enumerator_14228.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_14228.current_mValue (HERE).getter_string (SOURCE_FILE ("goil_routines.galgas", 468)).objectCompare (inArgument_e.getter_string (SOURCE_FILE ("goil_routines.galgas", 468)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_p = GALGAS_bool (true) ;
    }
    enumerator_14228.gotoNextObject () ;
  }
//---
  return result_p ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_isInLstringlist [3] = {
  & kTypeDescriptor_GALGAS_lstringlist,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_isInLstringlist (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_lstringlist operand0 = GALGAS_lstringlist::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_isInLstringlist (operand0,
                                   operand1,
                                   inCompiler
                                   COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_isInLstringlist ("isInLstringlist",
                                                                 functionWithGenericHeader_isInLstringlist,
                                                                 & kTypeDescriptor_GALGAS_bool,
                                                                 2,
                                                                 functionArgs_isInLstringlist) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'add_lstring_unique'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_lstring_5F_unique (GALGAS_lstringlist & ioArgument_l,
                                       GALGAS_lstring inArgument_e,
                                       GALGAS_string inArgument_att,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool var_found_14388 ;
  GALGAS_lstring var_res_14403 ;
  {
  routine_is_5F_in_5F_lstringlist (ioArgument_l, inArgument_e, var_res_14403, var_found_14388, inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 480)) ;
  }
  const enumGalgasBool test_0 = var_found_14388.boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (inArgument_e.getter_location (SOURCE_FILE ("goil_routines.galgas", 482)), inArgument_att.add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)).add_operation (inArgument_e.getter_string (SOURCE_FILE ("goil_routines.galgas", 482)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)).add_operation (GALGAS_string (" has already be listed"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 482)) ;
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (var_res_14403.getter_location (SOURCE_FILE ("goil_routines.galgas", 483)), GALGAS_string ("was listed here"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 483)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_l.addAssign_operation (inArgument_e  COMMA_SOURCE_FILE ("goil_routines.galgas", 485)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'set_lstring_if_empty'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_set_5F_lstring_5F_if_5F_empty (GALGAS_lstring & ioArgument_s,
                                            GALGAS_lstring inArgument_ns,
                                            GALGAS_string inArgument_att,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, ioArgument_s.getter_string (SOURCE_FILE ("goil_routines.galgas", 493)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_s = inArgument_ns ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (inArgument_ns.getter_location (SOURCE_FILE ("goil_routines.galgas", 496)), inArgument_att.add_operation (GALGAS_string (" Redefinition"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 496)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 496)) ;
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (ioArgument_s.getter_location (SOURCE_FILE ("goil_routines.galgas", 497)), GALGAS_string ("was defined here"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 497)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Routine 'add_makefile_flag_if_not_empty'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_makefile_5F_flag_5F_if_5F_not_5F_empty (GALGAS_string & ioArgument_receiver,
                                                            GALGAS_string inArgument_flag_5F_name,
                                                            GALGAS_string inArgument_flag_5F_value,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_flag_5F_value.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_receiver.plusAssign_operation(inArgument_flag_5F_name.add_operation (GALGAS_string ("="), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)).add_operation (inArgument_flag_5F_value, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 506)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'lstringWith'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_lstringWith (GALGAS_string inArgument_s,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_r ; // Returned variable
  result_r = GALGAS_lstring::constructor_new (inArgument_s, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 511))  COMMA_SOURCE_FILE ("goil_routines.galgas", 511)) ;
//---
  return result_r ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_lstringWith [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_lstringWith (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_lstringWith (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_lstringWith ("lstringWith",
                                                             functionWithGenericHeader_lstringWith,
                                                             & kTypeDescriptor_GALGAS_lstring,
                                                             1,
                                                             functionArgs_lstringWith) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'stripString'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stripString (GALGAS_string inArgument_s,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_r ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 515)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_uint var_first_15136 = GALGAS_uint ((uint32_t) 0U) ;
    GALGAS_uint var_last_15155 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 517)) ;
    GALGAS_bool var_finished_15243 = GALGAS_bool (false) ;
    if (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 520)).isValid ()) {
      uint32_t variant_15260 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 520)).uintValue () ;
      bool loop_15260 = true ;
      while (loop_15260) {
        loop_15260 = var_finished_15243.operator_not (SOURCE_FILE ("goil_routines.galgas", 521)).isValid () ;
        if (loop_15260) {
          loop_15260 = var_finished_15243.operator_not (SOURCE_FILE ("goil_routines.galgas", 521)).boolValue () ;
        }
        if (loop_15260 && (0 == variant_15260)) {
          loop_15260 = false ;
          inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 520)) ;
        }
        if (loop_15260) {
          variant_15260 -- ;
          const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, inArgument_s.getter_characterAtIndex (var_first_15136, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 522)).objectCompare (GALGAS_char (TO_UNICODE (32)))).boolEnum () ;
          if (kBoolTrue == test_1) {
            var_first_15136.increment_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 523)) ;
            const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_first_15136.objectCompare (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 524)))).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_finished_15243 = GALGAS_bool (true) ;
            }
          }else if (kBoolFalse == test_1) {
            var_finished_15243 = GALGAS_bool (true) ;
          }
        }
      }
    }
    var_finished_15243 = GALGAS_bool (false) ;
    if (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 529)).isValid ()) {
      uint32_t variant_15545 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 529)).uintValue () ;
      bool loop_15545 = true ;
      while (loop_15545) {
        loop_15545 = var_finished_15243.operator_not (SOURCE_FILE ("goil_routines.galgas", 530)).isValid () ;
        if (loop_15545) {
          loop_15545 = var_finished_15243.operator_not (SOURCE_FILE ("goil_routines.galgas", 530)).boolValue () ;
        }
        if (loop_15545 && (0 == variant_15545)) {
          loop_15545 = false ;
          inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 529)) ;
        }
        if (loop_15545) {
          variant_15545 -- ;
          const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, inArgument_s.getter_characterAtIndex (var_last_15155.substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 531)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 531)).objectCompare (GALGAS_char (TO_UNICODE (32)))).boolEnum () ;
          if (kBoolTrue == test_3) {
            var_last_15155.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 532)) ;
            const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_last_15155.objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
            if (kBoolTrue == test_4) {
              var_finished_15243 = GALGAS_bool (true) ;
            }
          }else if (kBoolFalse == test_3) {
            var_finished_15243 = GALGAS_bool (true) ;
          }
        }
      }
    }
    const enumGalgasBool test_5 = GALGAS_bool (kIsStrictInf, var_first_15136.objectCompare (var_last_15155)).boolEnum () ;
    if (kBoolTrue == test_5) {
      result_r = inArgument_s.getter_subString (var_first_15136, var_last_15155.substract_operation (var_first_15136, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 538)) COMMA_SOURCE_FILE ("goil_routines.galgas", 538)) ;
    }else if (kBoolFalse == test_5) {
      result_r = GALGAS_string::makeEmptyString () ;
    }
  }else if (kBoolFalse == test_0) {
    result_r = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_r ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stripString [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stripString (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_stripString (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stripString ("stripString",
                                                             functionWithGenericHeader_stripString,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             1,
                                                             functionArgs_stripString) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'errorNoFileFound'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_errorNoFileFound (const GALGAS_stringlist constinArgument_searchedPaths,
                               const GALGAS_string constinArgument_kind,
                               const GALGAS_lstring constinArgument_file,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_m_16011 = GALGAS_string ("cannot find a valid path for the '").add_operation (constinArgument_file.getter_string (SOURCE_FILE ("goil_routines.galgas", 551)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)).add_operation (GALGAS_string ("' "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)).add_operation (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)).add_operation (GALGAS_string (" file. I have tried:"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)) ;
  cEnumerator_stringlist enumerator_16123 (constinArgument_searchedPaths, kEnumeration_up) ;
  while (enumerator_16123.hasCurrentObject ()) {
    var_m_16011.plusAssign_operation(GALGAS_string ("\n"
      "  - '").add_operation (enumerator_16123.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 553)).add_operation (GALGAS_string ("'"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 553)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 553)) ;
    enumerator_16123.gotoNextObject () ;
  }
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (constinArgument_file.getter_location (SOURCE_FILE ("goil_routines.galgas", 555)), var_m_16011, fixItArray0  COMMA_SOURCE_FILE ("goil_routines.galgas", 555)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'stringLBool'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringLBool (const GALGAS_lbool & constinArgument_boolValue,
                                    C_Compiler * /* inCompiler */
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_boolValue.getter_bool (SOURCE_FILE ("goil_routines.galgas", 561)).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_string ("TRUE") ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("FALSE") ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringLBool [2] = {
  & kTypeDescriptor_GALGAS_lbool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringLBool (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_lbool operand0 = GALGAS_lbool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                             inCompiler
                                                             COMMA_THERE) ;
  return function_stringLBool (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringLBool ("stringLBool",
                                                             functionWithGenericHeader_stringLBool,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             1,
                                                             functionArgs_stringLBool) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension method '@structAttribute set'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_structAttribute_set (const cPtr_object_5F_t * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_gtlData & ioArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structAttribute * object = (const cPtr_structAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_structAttribute) ;
  GALGAS_gtlData var_subAttrs_935 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 33)) ;
  {
  var_subAttrs_935.insulate (HERE) ;
  cPtr_gtlData * ptr_976 = (cPtr_gtlData *) var_subAttrs_935.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_976, GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), object->mAttribute_structName.getter_location (SOURCE_FILE ("systemConfig.galgas", 35))  COMMA_SOURCE_FILE ("systemConfig.galgas", 35)), GALGAS_gtlString::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_structName.getter_string (SOURCE_FILE ("systemConfig.galgas", 36))  COMMA_SOURCE_FILE ("systemConfig.galgas", 36)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 34)) ;
  }
  {
  var_subAttrs_935.setter_setMeta (object->mAttribute_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 38)) ;
  }
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_1129 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1129, constinArgument_name, var_subAttrs_935, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 39)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_structAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_structAttribute.mSlotID,
                            extensionMethod_structAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_structAttribute_set (defineExtensionMethod_structAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@boolAttribute set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_boolAttribute_set (const cPtr_object_5F_t * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               GALGAS_gtlData & ioArgument_result,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_boolAttribute * object = (const cPtr_boolAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_boolAttribute) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_1575 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1575, constinArgument_name, GALGAS_gtlBool::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 52)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 52)) ;
  }
  GALGAS_gtlData var_subAttrs_1662 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 53)) ;
  GALGAS_gtlStruct temp_0 ;
  if (var_subAttrs_1662.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_1662.ptr ())) {
      temp_0 = (cPtr_gtlStruct *) var_subAttrs_1662.ptr () ;
    }else{
      inCompiler->castError ("gtlStruct", var_subAttrs_1662.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 54)) ;
    }
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_value (SOURCE_FILE ("systemConfig.galgas", 54)).getter_count (SOURCE_FILE ("systemConfig.galgas", 54)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_lstring var_structName_1766 = GALGAS_lstring::constructor_new (constinArgument_name.getter_string (SOURCE_FILE ("systemConfig.galgas", 55)).add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 55)), constinArgument_name.getter_location (SOURCE_FILE ("systemConfig.galgas", 55))  COMMA_SOURCE_FILE ("systemConfig.galgas", 55)) ;
    {
    var_subAttrs_1662.setter_setMeta (object->mAttribute_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 56)) ;
    }
    {
    ioArgument_result.insulate (HERE) ;
    cPtr_gtlData * ptr_1872 = (cPtr_gtlData *) ioArgument_result.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1872, var_structName_1766, var_subAttrs_1662, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 57)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_boolAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_boolAttribute.mSlotID,
                            extensionMethod_boolAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_boolAttribute_set (defineExtensionMethod_boolAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@enumAttribute set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_enumAttribute_set (const cPtr_object_5F_t * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               GALGAS_gtlData & ioArgument_result,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_enumAttribute * object = (const cPtr_enumAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_enumAttribute) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2191 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2191, constinArgument_name, GALGAS_gtlString::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 66)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 66)) ;
  }
  GALGAS_gtlData var_subAttrs_2280 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 67)) ;
  GALGAS_gtlStruct temp_0 ;
  if (var_subAttrs_2280.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_2280.ptr ())) {
      temp_0 = (cPtr_gtlStruct *) var_subAttrs_2280.ptr () ;
    }else{
      inCompiler->castError ("gtlStruct", var_subAttrs_2280.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 68)) ;
    }
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_value (SOURCE_FILE ("systemConfig.galgas", 68)).getter_count (SOURCE_FILE ("systemConfig.galgas", 68)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_lstring var_structName_2384 = GALGAS_lstring::constructor_new (constinArgument_name.getter_string (SOURCE_FILE ("systemConfig.galgas", 69)).add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 69)), constinArgument_name.getter_location (SOURCE_FILE ("systemConfig.galgas", 69))  COMMA_SOURCE_FILE ("systemConfig.galgas", 69)) ;
    {
    var_subAttrs_2280.setter_setMeta (object->mAttribute_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 70)) ;
    }
    {
    ioArgument_result.insulate (HERE) ;
    cPtr_gtlData * ptr_2490 = (cPtr_gtlData *) ioArgument_result.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2490, var_structName_2384, var_subAttrs_2280, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 71)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_enumAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_enumAttribute.mSlotID,
                            extensionMethod_enumAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_enumAttribute_set (defineExtensionMethod_enumAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension method '@stringAttribute set'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_stringAttribute_set (const cPtr_object_5F_t * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_gtlData & ioArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_stringAttribute * object = (const cPtr_stringAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_stringAttribute) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2625 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2625, constinArgument_name, GALGAS_gtlString::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 76)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 76)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_stringAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_stringAttribute.mSlotID,
                            extensionMethod_stringAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_stringAttribute_set (defineExtensionMethod_stringAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@string_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_string_5F_class_set (const cPtr_object_5F_t * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_gtlData & ioArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_string_5F_class * object = (const cPtr_string_5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_string_5F_class) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2782 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2782, constinArgument_name, GALGAS_gtlString::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 80)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 80)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_string_5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_string_5F_class.mSlotID,
                            extensionMethod_string_5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_string_5F_class_set (defineExtensionMethod_string_5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@objectRefAttribute set'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_objectRefAttribute_set (const cPtr_object_5F_t * inObject,
                                                    const GALGAS_lstring constinArgument_name,
                                                    GALGAS_gtlData & ioArgument_result,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectRefAttribute * object = (const cPtr_objectRefAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_objectRefAttribute) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2945 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2945, constinArgument_name, GALGAS_gtlString::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value.getter_string (SOURCE_FILE ("systemConfig.galgas", 84))  COMMA_SOURCE_FILE ("systemConfig.galgas", 84)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 84)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_objectRefAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_objectRefAttribute.mSlotID,
                            extensionMethod_objectRefAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_objectRefAttribute_set (defineExtensionMethod_objectRefAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@multipleAttribute set'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_multipleAttribute_set (const cPtr_object_5F_t * inObject,
                                                   const GALGAS_lstring constinArgument_name,
                                                   GALGAS_gtlData & ioArgument_result,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_multipleAttribute * object = (const cPtr_multipleAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_multipleAttribute) ;
  GALGAS_gtlList var_multiple_3115 = GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 88)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 88)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("systemConfig.galgas", 88))  COMMA_SOURCE_FILE ("systemConfig.galgas", 88)) ;
  cEnumerator_identifierList enumerator_3180 (object->mAttribute_items, kEnumeration_up) ;
  while (enumerator_3180.hasCurrentObject ()) {
    GALGAS_gtlData var_multipleItem_3209 = GALGAS_gtlStruct::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 90))  COMMA_SOURCE_FILE ("systemConfig.galgas", 90)) ;
    if (enumerator_3180.current_item (HERE).isValid ()) {
      if (enumerator_3180.current_item (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
        GALGAS_structAttribute cast_3312_aStruct ((cPtr_structAttribute *) enumerator_3180.current_item (HERE).ptr ()) ;
        {
        var_multipleItem_3209.insulate (HERE) ;
        cPtr_gtlData * ptr_3336 = (cPtr_gtlData *) var_multipleItem_3209.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3336, GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), cast_3312_aStruct.getter_location (SOURCE_FILE ("systemConfig.galgas", 94))  COMMA_SOURCE_FILE ("systemConfig.galgas", 94)), GALGAS_gtlString::constructor_new (cast_3312_aStruct.getter_location (SOURCE_FILE ("systemConfig.galgas", 96)), cast_3312_aStruct.getter_oil_5F_desc (SOURCE_FILE ("systemConfig.galgas", 97)), cast_3312_aStruct.getter_structName (SOURCE_FILE ("systemConfig.galgas", 98)).getter_string (SOURCE_FILE ("systemConfig.galgas", 98))  COMMA_SOURCE_FILE ("systemConfig.galgas", 95)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 93)) ;
        }
        GALGAS_gtlData var_subAttrs_3566 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) cast_3312_aStruct.getter_subAttributes (SOURCE_FILE ("systemConfig.galgas", 101)).ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 101)) ;
        GALGAS_gtlStruct temp_0 ;
        if (var_subAttrs_3566.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_3566.ptr ())) {
            temp_0 = (cPtr_gtlStruct *) var_subAttrs_3566.ptr () ;
          }else{
            inCompiler->castError ("gtlStruct", var_subAttrs_3566.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 102)) ;
          }
        }
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_value (SOURCE_FILE ("systemConfig.galgas", 102)).getter_count (SOURCE_FILE ("systemConfig.galgas", 102)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlStruct temp_2 ;
          if (var_subAttrs_3566.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_3566.ptr ())) {
              temp_2 = (cPtr_gtlStruct *) var_subAttrs_3566.ptr () ;
            }else{
              inCompiler->castError ("gtlStruct", var_subAttrs_3566.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 103)) ;
            }
          }
          cEnumerator_gtlVarMap enumerator_3710 (temp_2.getter_value (SOURCE_FILE ("systemConfig.galgas", 103)), kEnumeration_up) ;
          while (enumerator_3710.hasCurrentObject ()) {
            {
            var_multipleItem_3209.insulate (HERE) ;
            cPtr_gtlData * ptr_3739 = (cPtr_gtlData *) var_multipleItem_3209.ptr () ;
            callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3739, enumerator_3710.current_lkey (HERE), enumerator_3710.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 104)) ;
            }
            enumerator_3710.gotoNextObject () ;
          }
        }
      }else{
        callExtensionMethod_set ((const cPtr_object_5F_t *) enumerator_3180.current_item (HERE).ptr (), GALGAS_lstring::constructor_new (GALGAS_string ("VALUE"), enumerator_3180.current_item (HERE).getter_location (SOURCE_FILE ("systemConfig.galgas", 108))  COMMA_SOURCE_FILE ("systemConfig.galgas", 108)), var_multipleItem_3209, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 108)) ;
      }
    }
    {
    var_multiple_3115.insulate (HERE) ;
    cPtr_gtlList * ptr_3899 = (cPtr_gtlList *) var_multiple_3115.ptr () ;
    callExtensionSetter_appendItem ((cPtr_gtlList *) ptr_3899, var_multipleItem_3209, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 110)) ;
    }
    enumerator_3180.gotoNextObject () ;
  }
  {
  var_multiple_3115.setter_setMeta (object->mAttribute_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 112)) ;
  }
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_3976 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3976, constinArgument_name, var_multiple_3115, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 113)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_multipleAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_multipleAttribute.mSlotID,
                            extensionMethod_multipleAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_multipleAttribute_set (defineExtensionMethod_multipleAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@uint32_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_33__32__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_gtlData & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_33__32__5F_class * object = (const cPtr_uint_33__32__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_uint_33__32__5F_class) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4096 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4096, constinArgument_name, GALGAS_gtlInt::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 119))  COMMA_SOURCE_FILE ("systemConfig.galgas", 119)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 117)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_33__32__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_uint_33__32__5F_class.mSlotID,
                            extensionMethod_uint_33__32__5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_33__32__5F_class_set (defineExtensionMethod_uint_33__32__5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@sint32_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_33__32__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_gtlData & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_33__32__5F_class * object = (const cPtr_sint_33__32__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_sint_33__32__5F_class) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4270 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4270, constinArgument_name, GALGAS_gtlInt::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 126))  COMMA_SOURCE_FILE ("systemConfig.galgas", 126)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 124)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_33__32__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_sint_33__32__5F_class.mSlotID,
                            extensionMethod_sint_33__32__5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_33__32__5F_class_set (defineExtensionMethod_sint_33__32__5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@uint64_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_36__34__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_gtlData & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_36__34__5F_class * object = (const cPtr_uint_36__34__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_uint_36__34__5F_class) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4444 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4444, constinArgument_name, GALGAS_gtlInt::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 133))  COMMA_SOURCE_FILE ("systemConfig.galgas", 133)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 131)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_36__34__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_uint_36__34__5F_class.mSlotID,
                            extensionMethod_uint_36__34__5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_36__34__5F_class_set (defineExtensionMethod_uint_36__34__5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@sint64_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_36__34__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_gtlData & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_36__34__5F_class * object = (const cPtr_sint_36__34__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_sint_36__34__5F_class) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4618 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4618, constinArgument_name, GALGAS_gtlInt::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 140))  COMMA_SOURCE_FILE ("systemConfig.galgas", 140)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 138)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_36__34__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_sint_36__34__5F_class.mSlotID,
                            extensionMethod_sint_36__34__5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_36__34__5F_class_set (defineExtensionMethod_sint_36__34__5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@float_class set'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_float_5F_class_set (const cPtr_object_5F_t * inObject,
                                                const GALGAS_lstring constinArgument_name,
                                                GALGAS_gtlData & ioArgument_result,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_float_5F_class * object = (const cPtr_float_5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_float_5F_class) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4791 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4791, constinArgument_name, GALGAS_gtlFloat::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 147)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 145)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_float_5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_float_5F_class.mSlotID,
                            extensionMethod_float_5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_float_5F_class_set (defineExtensionMethod_float_5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Overriding extension method '@auto set'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_auto_set (const cPtr_object_5F_t * inObject,
                                      const GALGAS_lstring constinArgument_name,
                                      GALGAS_gtlData & ioArgument_result,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_auto * object = (const cPtr_auto *) inObject ;
  macroValidSharedObject (object, cPtr_auto) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4950 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4950, constinArgument_name, GALGAS_gtlEnum::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, GALGAS_string ("auto")  COMMA_SOURCE_FILE ("systemConfig.galgas", 154)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 152)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_auto_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_auto.mSlotID,
                            extensionMethod_auto_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_auto_set (defineExtensionMethod_auto_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'setDefaults'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setDefaults (const GALGAS_implementation constinArgument_imp,
                          GALGAS_applicationDefinition & ioArgument_application,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectsMap var_objects_876 = ioArgument_application.getter_objects (SOURCE_FILE ("defaults.galgas", 32)) ;
  cEnumerator_lstringlist enumerator_980 (var_objects_876.getter_keyList (SOURCE_FILE ("defaults.galgas", 35)), kEnumeration_up) ;
  while (enumerator_980.hasCurrentObject ()) {
    cMapElement_objectsMap * objectArray_992 = (cMapElement_objectsMap *) var_objects_876.readWriteAccessForWithInstructionWithErrorMessage (inCompiler, enumerator_980.current_mValue (HERE), kSearchErrorMessage_objectsMap_get  COMMA_SOURCE_FILE ("defaults.galgas", 36)) ;
    if (NULL != objectArray_992) {
        macroValidSharedObject (objectArray_992, cMapElement_objectsMap) ;
      GALGAS_objectKindMap var_objOfKind_1069 = objectArray_992->mAttribute_objectsOfKind.getter_objects (SOURCE_FILE ("defaults.galgas", 37)) ;
      cEnumerator_lstringlist enumerator_1151 (var_objOfKind_1069.getter_keyList (SOURCE_FILE ("defaults.galgas", 38)), kEnumeration_up) ;
      while (enumerator_1151.hasCurrentObject ()) {
        cMapElement_objectKindMap * objectArray_1167 = (cMapElement_objectKindMap *) var_objOfKind_1069.readWriteAccessForWithInstructionWithErrorMessage (inCompiler, enumerator_1151.current_mValue (HERE), kSearchErrorMessage_objectKindMap_get  COMMA_SOURCE_FILE ("defaults.galgas", 39)) ;
        if (NULL != objectArray_1167) {
            macroValidSharedObject (objectArray_1167, cMapElement_objectKindMap) ;
          GALGAS_implementationObject var_impObject_1257 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_980.current_mValue (HERE).getter_string (SOURCE_FILE ("defaults.galgas", 40)), inCompiler COMMA_SOURCE_FILE ("defaults.galgas", 40)) ;
          {
          routine_setDefaultsForType (var_impObject_1257.getter_attributes (SOURCE_FILE ("defaults.galgas", 41)), objectArray_1167->mAttribute_attributes, inCompiler  COMMA_SOURCE_FILE ("defaults.galgas", 41)) ;
          }
        }
        enumerator_1151.gotoNextObject () ;
      }
      {
      objectArray_992->mAttribute_objectsOfKind.setter_setObjects (var_objOfKind_1069 COMMA_SOURCE_FILE ("defaults.galgas", 44)) ;
      }
    }
    enumerator_980.gotoNextObject () ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_876 COMMA_SOURCE_FILE ("defaults.galgas", 48)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension method '@impStructType verifyType'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impStructType_verifyType (const cPtr_impType * inObject,
                                                      const GALGAS_object_5F_t constinArgument_attr,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impStructType * object = (const cPtr_impStructType *) inObject ;
  macroValidSharedObject (object, cPtr_impStructType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
      GALGAS_structAttribute cast_2379_sa ((cPtr_structAttribute *) constinArgument_attr.ptr ()) ;
      cEnumerator_implementationObjectMap enumerator_2413 (object->mAttribute_structAttributes, kEnumeration_up) ;
      while (enumerator_2413.hasCurrentObject ()) {
        const enumGalgasBool test_0 = cast_2379_sa.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 88)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 88)).getter_hasKey (enumerator_2413.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 88)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 88)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_object_5F_t var_subAttr_2514 ;
          cast_2379_sa.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 90)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 90)).method_get (enumerator_2413.current_lkey (HERE), var_subAttr_2514, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 90)) ;
          callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_2413.current_type (HERE).ptr (), var_subAttr_2514, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 91)) ;
        }
        enumerator_2413.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 95)), GALGAS_string ("STRUCT expected"), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 95)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impStructType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impStructType.mSlotID,
                                   extensionMethod_impStructType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impStructType_verifyType (defineExtensionMethod_impStructType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@refType verifyType'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_refType_verifyType (const cPtr_impType * /* inObject */,
                                                const GALGAS_object_5F_t constinArgument_attr,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_objectRefAttribute) {
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 105)), GALGAS_string ("object reference expected"), fixItArray0  COMMA_SOURCE_FILE ("semantic_verification.galgas", 105)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_refType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_refType.mSlotID,
                                   extensionMethod_refType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_refType_verifyType (defineExtensionMethod_refType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@impBoolType verifyType'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impBoolType_verifyType (const cPtr_impType * inObject,
                                                    const GALGAS_object_5F_t constinArgument_attr,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_3136_b ((cPtr_boolAttribute *) constinArgument_attr.ptr ()) ;
      const enumGalgasBool test_0 = cast_3136_b.getter_value (SOURCE_FILE ("semantic_verification.galgas", 114)).boolEnum () ;
      if (kBoolTrue == test_0) {
        cEnumerator_implementationObjectMap enumerator_3195 (object->mAttribute_trueSubAttributes, kEnumeration_up) ;
        while (enumerator_3195.hasCurrentObject ()) {
          const enumGalgasBool test_1 = cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 116)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 116)).getter_hasKey (enumerator_3195.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 116)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 116)).boolEnum () ;
          if (kBoolTrue == test_1) {
            GALGAS_object_5F_t var_subAttrs_3300 ;
            cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 118)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 118)).method_get (enumerator_3195.current_lkey (HERE), var_subAttrs_3300, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 118)) ;
            callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_3195.current_type (HERE).ptr (), var_subAttrs_3300, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 119)) ;
          }
          enumerator_3195.gotoNextObject () ;
        }
      }else if (kBoolFalse == test_0) {
        cEnumerator_implementationObjectMap enumerator_3478 (object->mAttribute_falseSubAttributes, kEnumeration_up) ;
        while (enumerator_3478.hasCurrentObject ()) {
          const enumGalgasBool test_2 = cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 124)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 124)).getter_hasKey (enumerator_3478.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 124)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 124)).boolEnum () ;
          if (kBoolTrue == test_2) {
            GALGAS_object_5F_t var_subAttrs_3583 ;
            cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 126)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 126)).method_get (enumerator_3478.current_lkey (HERE), var_subAttrs_3583, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 126)) ;
            callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_3478.current_type (HERE).ptr (), var_subAttrs_3583, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 127)) ;
          }
          enumerator_3478.gotoNextObject () ;
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 132)), GALGAS_string ("BOOLEAN expected"), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 132)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impBoolType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                   extensionMethod_impBoolType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impBoolType_verifyType (defineExtensionMethod_impBoolType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@impEnumType verifyType'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impEnumType_verifyType (const cPtr_impType * inObject,
                                                    const GALGAS_object_5F_t constinArgument_attr,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impEnumType * object = (const cPtr_impEnumType *) inObject ;
  macroValidSharedObject (object, cPtr_impEnumType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_enumAttribute) {
      GALGAS_enumAttribute cast_3969_e ((cPtr_enumAttribute *) constinArgument_attr.ptr ()) ;
      const enumGalgasBool test_0 = object->mAttribute_valuesMap.getter_hasKey (cast_3969_e.getter_value (SOURCE_FILE ("semantic_verification.galgas", 141)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 141)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_implementationObjectMap var_validVal_4053 ;
        object->mAttribute_valuesMap.method_get (function_lstringWith (cast_3969_e.getter_value (SOURCE_FILE ("semantic_verification.galgas", 143)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 143)), var_validVal_4053, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 143)) ;
        cEnumerator_implementationObjectMap enumerator_4136 (var_validVal_4053, kEnumeration_up) ;
        while (enumerator_4136.hasCurrentObject ()) {
          const enumGalgasBool test_1 = cast_3969_e.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 145)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 145)).getter_hasKey (enumerator_4136.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 145)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 145)).boolEnum () ;
          if (kBoolTrue == test_1) {
            GALGAS_object_5F_t var_subAttrs_4241 ;
            cast_3969_e.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 147)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 147)).method_get (enumerator_4136.current_lkey (HERE), var_subAttrs_4241, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 147)) ;
            callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_4136.current_type (HERE).ptr (), var_subAttrs_4241, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 148)) ;
          }
          enumerator_4136.gotoNextObject () ;
        }
      }else if (kBoolFalse == test_0) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (cast_3969_e.getter_location (SOURCE_FILE ("semantic_verification.galgas", 152)), cast_3969_e.getter_value (SOURCE_FILE ("semantic_verification.galgas", 152)).add_operation (GALGAS_string (" is not a valid enum value"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 152)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 152)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else{
      inCompiler->printMessage (GALGAS_string ("**** @impEnumType ****\n")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 156)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 157)), GALGAS_string ("ENUM expected"), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 157)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impEnumType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impEnumType.mSlotID,
                                   extensionMethod_impEnumType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impEnumType_verifyType (defineExtensionMethod_impEnumType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@impAutoDefaultType verifyType'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impAutoDefaultType_verifyType (const cPtr_impType * inObject,
                                                           const GALGAS_object_5F_t constinArgument_attr,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impAutoDefaultType * object = (const cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_stringAttribute) {
      const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_string (SOURCE_FILE ("semantic_verification.galgas", 167)))).operator_and (GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_identifier (SOURCE_FILE ("semantic_verification.galgas", 167)))) COMMA_SOURCE_FILE ("semantic_verification.galgas", 167)).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 168)), GALGAS_string ("string of identifier expected"), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 168)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_string_5F_class) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_identifier (SOURCE_FILE ("semantic_verification.galgas", 171)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 172)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else{
      inCompiler->printMessage (GALGAS_string ("*** @impAutoDefaultType ***\n")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 176)) ;
      constinArgument_attr.log ("attr"  COMMA_SOURCE_FILE ("semantic_verification.galgas", 177)) ;
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 178)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)), fixItArray4  COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impAutoDefaultType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                   extensionMethod_impAutoDefaultType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impAutoDefaultType_verifyType (defineExtensionMethod_impAutoDefaultType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension method '@impRangedType verifyType'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impRangedType_verifyType (const cPtr_impType * inObject,
                                                      const GALGAS_object_5F_t constinArgument_attr,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impRangedType * object = (const cPtr_impRangedType *) inObject ;
  macroValidSharedObject (object, cPtr_impRangedType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("semantic_verification.galgas", 188)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 189)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("semantic_verification.galgas", 192)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 193)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      const enumGalgasBool test_4 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("semantic_verification.galgas", 196)))).boolEnum () ;
      if (kBoolTrue == test_4) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 197)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)), fixItArray5  COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      const enumGalgasBool test_6 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("semantic_verification.galgas", 200)))).boolEnum () ;
      if (kBoolTrue == test_6) {
        TC_Array <C_FixItDescription> fixItArray7 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 201)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)), fixItArray7  COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      const enumGalgasBool test_8 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("semantic_verification.galgas", 204)))).boolEnum () ;
      if (kBoolTrue == test_8) {
        TC_Array <C_FixItDescription> fixItArray9 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 205)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)), fixItArray9  COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
      const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, object->mAttribute_withAuto.objectCompare (GALGAS_bool (false))).boolEnum () ;
      if (kBoolTrue == test_10) {
        TC_Array <C_FixItDescription> fixItArray11 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 209)), GALGAS_string ("AUTO is not allowed for ").add_operation (object->mAttribute_name.getter_string (SOURCE_FILE ("semantic_verification.galgas", 209)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)), fixItArray11  COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)) ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray12 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 213)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)), fixItArray12  COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impRangedType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impRangedType.mSlotID,
                                   extensionMethod_impRangedType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impRangedType_verifyType (defineExtensionMethod_impRangedType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'attributeAllowsAuto'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_attributeAllowsAuto (const GALGAS_impType & constinArgument_type,
                                          C_Compiler * /* inCompiler */
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_allowsAuto ; // Returned variable
  result_allowsAuto = GALGAS_bool (true) ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impAutoDefaultType *> (constinArgument_type.ptr ())) {
      GALGAS_impAutoDefaultType cast_6562_autoType ((cPtr_impAutoDefaultType *) constinArgument_type.ptr ()) ;
      const enumGalgasBool test_0 = cast_6562_autoType.getter_withAuto (SOURCE_FILE ("semantic_verification.galgas", 225)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 225)).boolEnum () ;
      if (kBoolTrue == test_0) {
        result_allowsAuto = GALGAS_bool (false) ;
      }
    }else{
      result_allowsAuto = GALGAS_bool (false) ;
    }
  }
//---
  return result_allowsAuto ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_attributeAllowsAuto [2] = {
  & kTypeDescriptor_GALGAS_impType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_attributeAllowsAuto (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_impType operand0 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_attributeAllowsAuto (operand0,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_attributeAllowsAuto ("attributeAllowsAuto",
                                                                     functionWithGenericHeader_attributeAllowsAuto,
                                                                     & kTypeDescriptor_GALGAS_bool,
                                                                     1,
                                                                     functionArgs_attributeAllowsAuto) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'verifyAllAttributes'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyAllAttributes (const GALGAS_implementation constinArgument_imp,
                                  const GALGAS_objectsMap constinArgument_objects,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_objectsMap enumerator_6874 (constinArgument_objects, kEnumeration_up) ;
  while (enumerator_6874.hasCurrentObject ()) {
    GALGAS_implementationObject var_impObj_6910 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 242)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 242)) ;
    cEnumerator_objectKindMap enumerator_7042 (enumerator_6874.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("semantic_verification.galgas", 244)), kEnumeration_up) ;
    while (enumerator_7042.hasCurrentObject ()) {
      cEnumerator_implementationObjectMap enumerator_7087 (var_impObj_6910.getter_attributes (SOURCE_FILE ("semantic_verification.galgas", 245)), kEnumeration_up) ;
      while (enumerator_7087.hasCurrentObject ()) {
        const enumGalgasBool test_0 = enumerator_7042.current_attributes (HERE).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 246)).getter_hasKey (enumerator_7087.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 246)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 246)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_object_5F_t var_value_7288 ;
          enumerator_7042.current_attributes (HERE).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 250)).method_get (enumerator_7087.current_lkey (HERE), var_value_7288, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 250)) ;
          if (var_value_7288.isValid ()) {
            if (var_value_7288.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
              const enumGalgasBool test_1 = function_attributeAllowsAuto (enumerator_7087.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 254)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 254)).boolEnum () ;
              if (kBoolTrue == test_1) {
                TC_Array <C_FixItDescription> fixItArray2 ;
                inCompiler->emitSemanticError (var_value_7288.getter_location (SOURCE_FILE ("semantic_verification.galgas", 255)), GALGAS_string ("AUTO value is not allowed for the ").add_operation (enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 255)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)) ;
              }
            }
          }
        }else if (kBoolFalse == test_0) {
          const enumGalgasBool test_3 = function_attributeAllowsAuto (enumerator_7087.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)).operator_and (enumerator_7087.current_type (HERE).getter_multiple (SOURCE_FILE ("semantic_verification.galgas", 260)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).boolEnum () ;
          if (kBoolTrue == test_3) {
            TC_Array <C_FixItDescription> fixItArray4 ;
            inCompiler->emitSemanticError (enumerator_7042.current_lkey (HERE).getter_location (SOURCE_FILE ("semantic_verification.galgas", 261)), GALGAS_string ("In ").add_operation (enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7042.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (", attribute "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7087.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" is not defined and is not AUTO"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)), fixItArray4  COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)) ;
          }
        }
        if (enumerator_7087.current_type (HERE).isValid ()) {
          if (enumerator_7087.current_type (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impAutoDefaultType) {
          }
        }
        enumerator_7087.gotoNextObject () ;
      }
      enumerator_7042.gotoNextObject () ;
    }
    enumerator_6874.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension method '@multipleAttribute verifyCrossReferences'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_multipleAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                     const GALGAS_objectsMap constinArgument_allObjects,
                                                                     const GALGAS_impType constinArgument_type,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_multipleAttribute * object = (const cPtr_multipleAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_multipleAttribute) ;
  cEnumerator_identifierList enumerator_19027 (object->mAttribute_items, kEnumeration_up) ;
  while (enumerator_19027.hasCurrentObject ()) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_object_5F_t *) enumerator_19027.current_item (HERE).ptr (), constinArgument_allObjects, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 617)) ;
    enumerator_19027.gotoNextObject () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_multipleAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_multipleAttribute.mSlotID,
                                              extensionMethod_multipleAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_multipleAttribute_verifyCrossReferences (defineExtensionMethod_multipleAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@boolAttribute verifyCrossReferences'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_boolAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                 const GALGAS_objectsMap constinArgument_allObjects,
                                                                 const GALGAS_impType constinArgument_type,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_boolAttribute * object = (const cPtr_boolAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_boolAttribute) ;
  GALGAS_impBoolType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impBoolType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impBoolType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impBoolType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 625)) ;
    }
  }
  GALGAS_impBoolType var_boolType_19222 = temp_0 ;
  const enumGalgasBool test_1 = object->mAttribute_value.boolEnum () ;
  if (kBoolTrue == test_1) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), constinArgument_allObjects, var_boolType_19222.getter_trueSubAttributes (SOURCE_FILE ("semantic_verification.galgas", 627)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 627)) ;
  }else if (kBoolFalse == test_1) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), constinArgument_allObjects, var_boolType_19222.getter_falseSubAttributes (SOURCE_FILE ("semantic_verification.galgas", 629)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 629)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_boolAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_boolAttribute.mSlotID,
                                              extensionMethod_boolAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_boolAttribute_verifyCrossReferences (defineExtensionMethod_boolAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@enumAttribute verifyCrossReferences'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_enumAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                 const GALGAS_objectsMap constinArgument_allObjects,
                                                                 const GALGAS_impType constinArgument_type,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_enumAttribute * object = (const cPtr_enumAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_enumAttribute) ;
  GALGAS_impEnumType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impEnumType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impEnumType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impEnumType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 637)) ;
    }
  }
  GALGAS_impEnumType var_enumType_19578 = temp_0 ;
  GALGAS_lstring var_key_19620 = GALGAS_lstring::constructor_new (object->mAttribute_value, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638)) ;
  GALGAS_implementationObjectMap var_expectedAttributes_19729 ;
  var_enumType_19578.getter_valuesMap (SOURCE_FILE ("semantic_verification.galgas", 639)).method_get (var_key_19620, var_expectedAttributes_19729, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 639)) ;
  callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), constinArgument_allObjects, var_expectedAttributes_19729, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 640)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_enumAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_enumAttribute.mSlotID,
                                              extensionMethod_enumAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_enumAttribute_verifyCrossReferences (defineExtensionMethod_enumAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@structAttribute verifyCrossReferences'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_structAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                   const GALGAS_objectsMap constinArgument_allObjects,
                                                                   const GALGAS_impType constinArgument_type,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structAttribute * object = (const cPtr_structAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_structAttribute) ;
  GALGAS_impStructType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impStructType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impStructType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impStructType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 647)) ;
    }
  }
  GALGAS_impStructType var_structType_19943 = temp_0 ;
  callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), constinArgument_allObjects, var_structType_19943.getter_structAttributes (SOURCE_FILE ("semantic_verification.galgas", 648)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 648)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_structAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_structAttribute.mSlotID,
                                              extensionMethod_structAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_structAttribute_verifyCrossReferences (defineExtensionMethod_structAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension method '@objectRefAttribute verifyCrossReferences'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_objectRefAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                      const GALGAS_objectsMap constinArgument_allObjects,
                                                                      const GALGAS_impType constinArgument_type,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectRefAttribute * object = (const cPtr_objectRefAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_objectRefAttribute) ;
  GALGAS_refType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_refType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_refType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("refType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 655)) ;
    }
  }
  GALGAS_refType var_refType_20190 = temp_0 ;
  GALGAS_objectKind var_kindMap_20313 ;
  constinArgument_allObjects.method_get (var_refType_20190.getter_ref (SOURCE_FILE ("semantic_verification.galgas", 657)), var_kindMap_20313, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 657)) ;
  const enumGalgasBool test_1 = var_kindMap_20313.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 658)).getter_hasKey (object->mAttribute_value.getter_string (SOURCE_FILE ("semantic_verification.galgas", 658)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 658)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 658)).boolEnum () ;
  if (kBoolTrue == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (object->mAttribute_value.getter_location (SOURCE_FILE ("semantic_verification.galgas", 659)), GALGAS_string ("Referenced ").add_operation (var_refType_20190.getter_ref (SOURCE_FILE ("semantic_verification.galgas", 659)).getter_string (SOURCE_FILE ("semantic_verification.galgas", 659)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (object->mAttribute_value.getter_string (SOURCE_FILE ("semantic_verification.galgas", 659)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (GALGAS_string (" does not exist"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_objectRefAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_objectRefAttribute.mSlotID,
                                              extensionMethod_objectRefAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_objectRefAttribute_verifyCrossReferences (defineExtensionMethod_objectRefAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'verifyAll'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyAll (const GALGAS_implementation constinArgument_imp,
                        const GALGAS_applicationDefinition constinArgument_application,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_verifyAllAttributes (constinArgument_imp, constinArgument_application.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 681)), inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 681)) ;
  }
  callExtensionMethod_verifyApplication ((const cPtr_implementation *) constinArgument_imp.ptr (), constinArgument_application, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 682)) ;
  callExtensionMethod_verifyCrossReferences ((const cPtr_applicationDefinition *) constinArgument_application.ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 685)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Function 'emptyApplicationDefinition'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition function_emptyApplicationDefinition (C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_applicationDefinition result_result ; // Returned variable
  result_result = GALGAS_applicationDefinition::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 56)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 57)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 58)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 59)), GALGAS_objectsMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 60))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 55)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyApplicationDefinition [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyApplicationDefinition (C_Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_emptyApplicationDefinition (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyApplicationDefinition ("emptyApplicationDefinition",
                                                                            functionWithGenericHeader_emptyApplicationDefinition,
                                                                            & kTypeDescriptor_GALGAS_applicationDefinition,
                                                                            0,
                                                                            functionArgs_emptyApplicationDefinition) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'osObject'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_osObject (const GALGAS_objectsMap & constinArgument_objects,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_os ; // Returned variable
  GALGAS_objectKind var_objectsForKind_1623 ;
  constinArgument_objects.method_get (function_lstringWith (GALGAS_string ("OS"), inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)), var_objectsForKind_1623, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)) ;
  GALGAS_lstringlist var_names_1696 = var_objectsForKind_1623.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 68)).getter_keyList (SOURCE_FILE ("goil_types_root.galgas", 68)) ;
  GALGAS_lstring var_name_1749 ;
  var_names_1696.method_first (var_name_1749, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 70)) ;
  var_objectsForKind_1623.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 71)).method_get (var_name_1749, result_os, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 71)) ;
//---
  return result_os ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_osObject [2] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_osObject (C_Compiler * inCompiler,
                                                         const cObjectArray & inEffectiveParameterArray,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_osObject (operand0,
                            inCompiler
                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_osObject ("osObject",
                                                          functionWithGenericHeader_osObject,
                                                          & kTypeDescriptor_GALGAS_objectAttributes,
                                                          1,
                                                          functionArgs_osObject) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'objectForKindAndName'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_objectForKindAndName (const GALGAS_objectsMap & constinArgument_objects,
                                                       const GALGAS_string & constinArgument_kind,
                                                       const GALGAS_string & constinArgument_name,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_object ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 79)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_objectKind var_kindObj_1998 ;
    constinArgument_objects.method_get (function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)), var_kindObj_1998, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)) ;
    const enumGalgasBool test_1 = var_kindObj_1998.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 82)).getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 82)).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_kindObj_1998.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 83)).method_get (function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)), result_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)) ;
    }else if (kBoolFalse == test_1) {
      result_object = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 85))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 85)) ;
    }
  }else if (kBoolFalse == test_0) {
    result_object = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 88))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 88)) ;
  }
//---
  return result_object ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_objectForKindAndName [4] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_objectForKindAndName (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_objectForKindAndName (operand0,
                                        operand1,
                                        operand2,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_objectForKindAndName ("objectForKindAndName",
                                                                      functionWithGenericHeader_objectForKindAndName,
                                                                      & kTypeDescriptor_GALGAS_objectAttributes,
                                                                      3,
                                                                      functionArgs_objectForKindAndName) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'setObjectForKindAndName'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setObjectForKindAndName (GALGAS_objectsMap & ioArgument_objects,
                                      const GALGAS_string constinArgument_kind,
                                      const GALGAS_string constinArgument_name,
                                      const GALGAS_objectAttributes constinArgument_object,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkind_2457 = function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 97)) ;
  GALGAS_lstring var_lname_2495 = function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 98)) ;
  GALGAS_objectKind var_kindObj_2538 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 99))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 99)) ;
  const enumGalgasBool test_0 = ioArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 100)).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    ioArgument_objects.setter_del (var_lkind_2457, var_kindObj_2538, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 101)) ;
    }
  }
  GALGAS_objectKindMap var_kindMap_2686 = var_kindObj_2538.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 103)) ;
  const enumGalgasBool test_1 = var_kindMap_2686.getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 104)).boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    GALGAS_objectAttributes joker_2767 ; // Joker input parameter
    var_kindMap_2686.setter_del (var_lname_2495, joker_2767, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 105)) ;
    }
  }
  {
  var_kindMap_2686.setter_put (var_lname_2495, constinArgument_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 107)) ;
  }
  {
  var_kindObj_2538.setter_setObjects (var_kindMap_2686 COMMA_SOURCE_FILE ("goil_types_root.galgas", 108)) ;
  }
  {
  ioArgument_objects.setter_put (var_lkind_2457, var_kindObj_2538, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 109)) ;
  }
}


