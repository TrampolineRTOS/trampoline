
// PMCocoaCallsDebug.h

//---------------------------------------------------------------------------*

#import <Cocoa/Cocoa.h>

//---------------------------------------------------------------------------*

#define PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG
  #define HERE                  atFile:__FILE__  atLine:__LINE__
  #define COLON_HERE            :__FILE__  atLine:__LINE__
  #define THERE                 atFile:IN_SOURCE_FILE  atLine:IN_SOURCE_LINE
  #define COLON_THERE           IN_SOURCE_FILE  atLine:IN_SOURCE_LINE
  #define LOCATION_ARGS         atFile: (const char *) IN_SOURCE_FILE  atLine: (int) IN_SOURCE_LINE
  #define COLON_LOCATION_ARGS   : (const char *) IN_SOURCE_FILE  atLine: (int) IN_SOURCE_LINE
  #define OF_CLASS_ARG          ofClass: (Class) inClass
  #define OFCLASS(className)    ofClass:[className class]
#else
  #define HERE
  #define COLON_HERE
  #define THERE
  #define COLON_THERE
  #define LOCATION_ARGS
  #define COLON_LOCATION_ARGS
  #define OF_CLASS_ARG
  #define OFCLASS(className)
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//  NSInteger and NSUInteger definitions                                     *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef NSINTEGER_DEFINED
  typedef int NSInteger;
  typedef unsigned int NSUInteger;
  #define NSINTEGER_DEFINED 1
  #define NSIntegerMax    LONG_MAX
  #define NSIntegerMin    LONG_MIN
  #define NSUIntegerMax   ULONG_MAX
#endif

//---------------------------------------------------------------------------*

#define value_for_key  valueForKey
#define set_value      setValue
#define for_key        forKey

//---------------------------------------------------------------------------*

//--- Define DEBUG_ENUMERATORS, in order to detect
//    "Collection ... was mutated while being enumerated" exception

//#define DEBUG_ENUMERATORS

//---------------------------------------------------------------------------*

#import "PMArrayDebugCategory.h"
#import "PMMutableArrayDebugCategory.h"
#import "PMArrayControllerDebugCategory.h"
#import "PMMutableDictionaryDebugCategory.h"
#import "PMDictionaryDebugCategory.h"
#import "PMSetDebugCategory.h"
#import "PMMutableSetDebugCategory.h"
#import "PMMutableStringDebugCategory.h"
#import "PMPointerArrayDebugCategory.h"

//---------------------------------------------------------------------------*
