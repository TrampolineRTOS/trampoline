#pragma once

//--------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-8.h"

//--------------------------------------------------------------------------------------------------
//
//Function 'customGtlStringGetter'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData function_customGtlStringGetter (const class GALGAS_lstring & constinArgument0,
                                                     const class GALGAS_gtlDataList & constinArgument1,
                                                     const class GALGAS_gtlContext & constinArgument2,
                                                     const class GALGAS_library & constinArgument3,
                                                     const class GALGAS_string & constinArgument4,
                                                     const class GALGAS_location & constinArgument5,
                                                     class Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'trueFalse'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_trueFalse (const class GALGAS_bool & constinArgument0,
                                        class Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'TrueFalse'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_TrueFalse (const class GALGAS_bool & constinArgument0,
                                        class Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'yesNo'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_yesNo (const class GALGAS_bool & constinArgument0,
                                    class Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'TRUEFALSE'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_TRUEFALSE (const class GALGAS_bool & constinArgument0,
                                        class Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'listOfSize'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_list function_listOfSize (class GALGAS_bigint inArgument0,
                                       class Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'version'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_version (class Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'majorVersion'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_majorVersion (class Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'minorVersion'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_minorVersion (class Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'revision'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_revision (class Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'currentDir'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_currentDir (class Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'homeDir'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_homeDir (class Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'currentDateTime'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_currentDateTime (class Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max8bitsUnsignedInt'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_38_bitsUnsignedInt (class Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max8bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_38_bitsSignedInt (class Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'min8bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_min_38_bitsSignedInt (class Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max16bitsUnsignedInt'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_31__36_bitsUnsignedInt (class Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max16bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_31__36_bitsSignedInt (class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'min16bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_min_31__36_bitsSignedInt (class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max32bitsUnsignedInt'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_33__32_bitsUnsignedInt (class Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max32bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_33__32_bitsSignedInt (class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'min32bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_min_33__32_bitsSignedInt (class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max64bitsUnsignedInt'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_36__34_bitsUnsignedInt (class Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'max64bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_36__34_bitsSignedInt (class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'min64bitsSignedInt'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint function_min_36__34_bitsSignedInt (class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'pi'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_double function_pi (class Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'underline'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_underline (class Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'blink'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_blink (class Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'black'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_black (class Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'green'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_green (class Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'yellow'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_yellow (class Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'blue'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_blue (class Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'magenta'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_magenta (class Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'cyan'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_cyan (class Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'darkred'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_darkred (class Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'darkgreen'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_darkgreen (class Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'darkyellow'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_darkyellow (class Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'darkblue'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_darkblue (class Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'darkmagenta'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_darkmagenta (class Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'darkcyan'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_darkcyan (class Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'white'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_white (class Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

