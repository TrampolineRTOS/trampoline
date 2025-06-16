//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#pragma once

//--------------------------------------------------------------------------------------------------

#include "String-class.h"
#include "Timer.h"
#include "AC_GALGAS_root.h"
#include "C_galgas_type_descriptor.h"
#include "typeComparisonResult.h"
#include "cGenericAbstractEnumerator.h"
#include "cEnumerator_range.h"
#include "AC_GALGAS_list.h"
#include "AC_GALGAS_sortedlist.h"
#include "AC_GALGAS_map.h"
#include "AC_GALGAS_reference_class.h"
#include "AC_GALGAS_value_class.h"
#include "AC_GALGAS_enumAssociatedValues.h"
#include "AC_GALGAS_graph.h"
#include "acStrongPtr_class.h"
#include "cPtr_weakReference_proxy.h"
#include "AC_GALGAS_weak_reference.h"
#include "C_BoolCommandLineOption.h"
#include "C_UIntCommandLineOption.h"
#include "C_StringCommandLineOption.h"
#include "C_StringListCommandLineOption.h"
#include "PrologueEpilogue.h"
#include "BigSigned.h"

//--------------------------------------------------------------------------------------------------

class Compiler ;
class GALGAS_string ;
class GALGAS_bool ;
class GALGAS_stringset ;
class GALGAS_location ;
class GALGAS_type ;
class GALGAS_char ;
class GALGAS_bigint ;
class GALGAS_double ;
class GALGAS_sint64 ;
class GALGAS_uint ;
class GALGAS_uint64 ;
class GALGAS_sint ;
class GALGAS_application ;
class GALGAS_binaryset ;
class GALGAS_data ;
class GALGAS_filewrapper ;
class GALGAS_function ;
class GALGAS_object ;
class GALGAS_timer ;

//--------------------------------------------------------------------------------------------------
//
//   @string type
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: bool mIsValid ;
  private: String mString ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mIsValid ; }
  public: VIRTUAL_IN_DEBUG void drop (void) override ;
  public: inline String stringValue (void) const { return mString ; }

//--------------------------------- Default constructor
  public: GALGAS_string (void) ;

//--------------------------------- Constructor for making an empty string
  public: static GALGAS_string makeEmptyString (void) ;

//--------------------------------- Native constructor
  public: GALGAS_string (const String & inValue) ;

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (const char * inPropertyName) const override ;
  #endif

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_string extractObject (const GALGAS_object & inObject,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_string class_func_CppChar (const class GALGAS_char & inOperand0
                                                         COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_CppLineComment (LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_CppSpaceComment (LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_CppString (const class GALGAS_string & inOperand0
                                                           COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_CppTitleComment (const class GALGAS_string & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_componentsJoinedByString (const class GALGAS_stringlist & inOperand0,
                                                                          const class GALGAS_string & inOperand1
                                                                          COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_homeDirectory (LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_newWithStdIn (LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_retrieveAndResetTemplateString (Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_separatorString (Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_stringByRepeatingString (const class GALGAS_string & inOperand0,
                                                                         const class GALGAS_uint & inOperand1
                                                                         COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_stringWithContentsOfFile (const class GALGAS_string & inOperand0,
                                                                          class Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_stringWithCurrentDateTime (LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_stringWithCurrentDirectory (LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_stringWithEnvironmentVariable (const class GALGAS_string & inOperand0,
                                                                               class Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_stringWithEnvironmentVariableOrEmpty (const class GALGAS_string & inOperand0
                                                                                      COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_stringWithSequenceOfCharacters (const class GALGAS_char & inOperand0,
                                                                                const class GALGAS_uint & inOperand1
                                                                                COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_stringWithSourceFilePath (Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_stringWithSymbolicLinkContents (const class GALGAS_string & inOperand0,
                                                                                class Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_string inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_string add_operation (const GALGAS_string & inOperand,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_string & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_appendSpacesUntilColumn (class GALGAS_uint constinArgument0,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_decIndentation (class GALGAS_uint constinArgument0,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_incIndentation (class GALGAS_uint constinArgument0,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertCharacterAtIndex (class GALGAS_char constinArgument0,
                                                               class GALGAS_uint constinArgument1,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeCharacterAtIndex (class GALGAS_char & outArgument0,
                                                               class GALGAS_uint constinArgument1,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setCapacity (class GALGAS_uint constinArgument0,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setCharacterAtIndex (class GALGAS_char constinArgument0,
                                                            class GALGAS_uint constinArgument1,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_makeDirectory (Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_makeDirectoryAndWriteToExecutableFile (class GALGAS_string constinArgument0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_makeDirectoryAndWriteToFile (class GALGAS_string constinArgument0,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_makeSymbolicLinkWithPath (class GALGAS_string constinArgument0,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_writeToExecutableFile (class GALGAS_string constinArgument0,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_writeToExecutableFileWhenDifferentContents (class GALGAS_string constinArgument0,
                                                                                   class GALGAS_bool & outArgument1,
                                                                                   Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_writeToFile (class GALGAS_string constinArgument0,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_writeToFileWhenDifferentContents (class GALGAS_string constinArgument0,
                                                                         class GALGAS_bool & outArgument1,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods
  public: static void class_method_deleteFile (class GALGAS_string constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: static void class_method_deleteFileIfExists (class GALGAS_string constinArgument0,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public: static void class_method_generateFile (class GALGAS_string constinArgument0,
                                                 class GALGAS_string constinArgument1,
                                                 class GALGAS_string constinArgument2,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: static void class_method_generateFileWithPattern (class GALGAS_string constinArgument0,
                                                            class GALGAS_string constinArgument1,
                                                            class GALGAS_string constinArgument2,
                                                            class GALGAS_string constinArgument3,
                                                            class GALGAS_string constinArgument4,
                                                            class GALGAS_string constinArgument5,
                                                            class GALGAS_string constinArgument6,
                                                            class GALGAS_string constinArgument7,
                                                            class GALGAS_bool constinArgument8,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

  public: static void class_method_removeDirectoryRecursively (class GALGAS_string constinArgument0,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

  public: static void class_method_removeEmptyDirectory (class GALGAS_string constinArgument0,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_HTMLRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_absolutePathFromPath (const class GALGAS_string & constinOperand0
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_assemblerRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_cStringRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_capacity (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_char getter_characterAtIndex (const class GALGAS_uint & constinOperand0,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint getter_commandWithArguments (const class GALGAS_stringlist & constinOperand0,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_componentsSeparatedByString (const class GALGAS_string & constinOperand0
                                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_containsCharacter (const class GALGAS_char & constinOperand0
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_containsCharacterInRange (const class GALGAS_char & constinOperand0,
                                                                              const class GALGAS_char & constinOperand1
                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_count (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_currentColumn (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_decimalSigned_36__34_Number (Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bigint getter_decimalSignedBigInt (Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint getter_decimalSignedNumber (Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_decimalUnsigned_36__34_Number (Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_decimalUnsignedNumber (Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_decodedStringFromRepresentation (Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_directories (const class GALGAS_bool & constinOperand0
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_directoriesWithExtensions (const class GALGAS_bool & constinOperand0,
                                                                                     const class GALGAS_stringlist & constinOperand1
                                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_directoryExists (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_doesEnvironmentVariableExist (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_doubleNumber (Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_fileExists (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_fileNameRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_char getter_firstCharacterOrNul (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lstring getter_here (Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_hiddenCommandWithArguments (const class GALGAS_stringlist & constinOperand0,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_hiddenFiles (const class GALGAS_bool & constinOperand0
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_identifierRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isDecimalSigned_36__34_Number (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isDecimalSignedBigInt (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isDecimalSignedNumber (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isDecimalUnsigned_36__34_Number (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isDecimalUnsignedNumber (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isDoubleNumber (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isSymbolicLink (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_char getter_lastCharacter (Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_lastPathComponent (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_leftSubString (const class GALGAS_uint & constinOperand0
                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_lowercaseString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_md_35_ (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_nameRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_nativePathWithUnixPath (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lstring getter_nowhere (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_pathExtension (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_popen (Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_range getter_range (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_regularFiles (const class GALGAS_bool & constinOperand0
                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_regularFilesWithExtensions (const class GALGAS_bool & constinOperand0,
                                                                                      const class GALGAS_stringlist & constinOperand1
                                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_relativePathFromPath (const class GALGAS_string & constinOperand0
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_reversedString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_rightSubString (const class GALGAS_uint & constinOperand0
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_sha_32__35__36_ (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByCapitalizingFirstCharacter (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByDeletingLastPathComponent (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByDeletingPathExtension (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByLeftAndRightPadding (const class GALGAS_uint & constinOperand0,
                                                                                   const class GALGAS_char & constinOperand1
                                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByLeftPadding (const class GALGAS_uint & constinOperand0,
                                                                           const class GALGAS_char & constinOperand1
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByRemovingCharacterAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                        Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByReplacingStringByString (const class GALGAS_string & constinOperand0,
                                                                                       const class GALGAS_string & constinOperand1,
                                                                                       Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByRightPadding (const class GALGAS_uint & constinOperand0,
                                                                            const class GALGAS_char & constinOperand1
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByStandardizingPath (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByTrimmingWhiteSpaces (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_subString (const class GALGAS_uint & constinOperand0,
                                                                 const class GALGAS_uint & constinOperand1
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_subStringFromIndex (const class GALGAS_uint & constinOperand0
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint getter_system (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_unixPathWithNativePath (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_uppercaseString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_utf_33__32_Representation (const class GALGAS_bool & constinOperand0
                                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_utf_38_Length (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_utf_38_Representation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_utf_38_RepresentationEnclosedWithin (const class GALGAS_char & constinOperand0
                                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_utf_38_RepresentationEscapingQuestionMark (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_utf_38_RepresentationWithUnicodeEscaping (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_utf_38_RepresentationWithoutDelimiters (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_extractBigInt (class GALGAS_bigint & outOperand0) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_string class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_string ;

//--------------------------------------------------------------------------------------------------
//
//@bool type
//
//--------------------------------------------------------------------------------------------------

typedef enum {kBoolNotValid, kBoolFalse, kBoolTrue} enumGalgasBool ;

//--------------------------------------------------------------------------------------------------

class GALGAS_bool : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: bool mIsValid ;
  private: bool mBoolValue ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mIsValid ; }
  public: inline bool isValidAndTrue (void) const { return mIsValid && mBoolValue ; }
  public: inline bool boolValue (void) const { return mBoolValue ; }
  public: enumGalgasBool boolEnum (void) const ;

//--------------------------------- Drop
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mIsValid = false ; }

//--------------------------------- Default constructor
  public: GALGAS_bool (void) ;

//--------------------------------- Native constructors
  public: GALGAS_bool (const bool inValue) ; // Is built
  public: GALGAS_bool (const bool inBuilt, const bool inValue) ;

//--------------------------------- Constructor for comparison result
  public: GALGAS_bool (const typeComparisonKind inComparisonKind,
                        const typeComparisonResult inComparisonResult) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_bool extractObject (const GALGAS_object & inObject,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_bool class_func_default (LOCATION_ARGS) ;

//--------------------------------- & operator
  public: VIRTUAL_IN_DEBUG GALGAS_bool operator_and (const GALGAS_bool & inOperand
                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public: VIRTUAL_IN_DEBUG GALGAS_bool operator_or (const GALGAS_bool & inOperand
                                                    COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public: VIRTUAL_IN_DEBUG GALGAS_bool operator_xor (const GALGAS_bool & inOperand
                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- not operator
  public: VIRTUAL_IN_DEBUG GALGAS_bool operator_not (LOCATION_ARGS) const ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_bool & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigint (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_cString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_ocString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_bool class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_bool ;

//--------------------------------------------------------------------------------------------------
//
//   @stringset type
//
//--------------------------------------------------------------------------------------------------

class GALGAS_stringset : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: class cSharedStringsetRoot * mSharedRoot ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mSharedRoot != nullptr ; }
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_stringset (void) ;

//--------------------------------- Destructor (virtual in debug mode)
  public: virtual ~ GALGAS_stringset (void) ;

//--------------------------------- In debug mode : check method
  protected: void checkStringset (LOCATION_ARGS) const ;

//--------------------------------- Insulate
  protected: void insulate (LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_stringset extractObject (const GALGAS_object & inObject,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_stringset class_func_emptySet (LOCATION_ARGS) ;

  public: static class GALGAS_stringset class_func_setWithLStringList (const class GALGAS_lstringlist & inOperand0
                                                                       COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_stringset class_func_setWithString (const class GALGAS_string & inOperand0
                                                                  COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_stringset class_func_setWithStringList (const class GALGAS_stringlist & inOperand0
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Handle copy
  public: GALGAS_stringset (const GALGAS_stringset & inSource) ;
  public: GALGAS_stringset & operator = (const GALGAS_stringset & inSource) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_stringset inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_string & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- & operator
  public: VIRTUAL_IN_DEBUG GALGAS_stringset operator_and (const GALGAS_stringset & inOperand
                                                          COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public: VIRTUAL_IN_DEBUG GALGAS_stringset operator_or (const GALGAS_stringset & inOperand
                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- - operator
  public: VIRTUAL_IN_DEBUG GALGAS_stringset substract_operation (const GALGAS_stringset & inOperand,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_stringset & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insert (class GALGAS_string constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeKey (class GALGAS_string inArgument0
                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_anyString (Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_count (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_hasKey (const class GALGAS_string & constinOperand0
                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_stringList (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Enumeration helper methods
  protected: VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & inEnumerationArray) const ;

//--------------------------------- Friend

  friend class cEnumerator_stringset ;
 
} ; // End of GALGAS_stringset class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_stringset : public cGenericAbstractEnumerator {
  public: cEnumerator_stringset (const GALGAS_stringset & inEnumeratedObject,
                                 const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_string current_key (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_string current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringset ;

//--------------------------------------------------------------------------------------------------
//
//   @location type
//
//--------------------------------------------------------------------------------------------------

#include "LocationInSource.h"
#include "SourceTextInString.h"

//--------------------------------------------------------------------------------------------------

class GALGAS_location : public AC_GALGAS_root {
//--------------------------------- Private properties
  private: class InternalLocation * mInternalLocation ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG bool isValidAndNotNowhere (void) const ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;
  public: LocationInSource startLocation (void) const ;
  public: LocationInSource endLocation (void) const ;
  public: SourceTextInString sourceText (void) const ;

//--------------------------------- Default constructor
  public: GALGAS_location (void) ;

//--------------------------------- Handle copy
  public: GALGAS_location (const GALGAS_location & inSource) ;
  public: GALGAS_location & operator = (const GALGAS_location & inSource) ;

//--------------------------------- Destructor
  public: virtual ~ GALGAS_location (void) ;

//--------------------------------- Native constructor
  public: GALGAS_location (const LocationInSource & inStartLocationInSource,
                           const LocationInSource & inEndLocationInSource,
                           const SourceTextInString & inSourceText) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_location extractObject (const GALGAS_object & inObject,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_location class_func_here (Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_location class_func_next (Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_location class_func_nowhere (LOCATION_ARGS) ;

  public: static class GALGAS_location class_func_separator (Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_location & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_endColumn (Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_endLine (Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_endLocationIndex (Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_endLocationString (Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_file (Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isNowhere (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_startColumn (Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_startLine (Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_startLocationIndex (Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_startLocationString (Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_location getter_union (const class GALGAS_location & constinOperand0,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_location class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_location ;

//--------------------------------------------------------------------------------------------------
//
//   @type type
//
//--------------------------------------------------------------------------------------------------

class GALGAS_type : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: const C_galgas_type_descriptor * mTypeDescriptor ;

//--------------------------------- Accessors
  public: inline bool isValid (void) const override { return nullptr != mTypeDescriptor ; }
  public: inline void drop (void) override { mTypeDescriptor = nullptr ; }
  public: inline const C_galgas_type_descriptor * typeValue (void) const { return mTypeDescriptor ; }

//--------------------------------- Default constructor
  public: GALGAS_type (void) ;

//--------------------------------- Destructor (virtual in debug mode)
  public: virtual ~ GALGAS_type (void) ;

//--------------------------------- Handle copy
  public: GALGAS_type (const GALGAS_type & inSource) ;
  public: GALGAS_type & operator = (const GALGAS_type & inSource) ;

//--------------------------------- Native constructor
  public: GALGAS_type (const C_galgas_type_descriptor * inValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_type extractObject (const GALGAS_object & inObject,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typelist class_func_typeList (LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_type & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_hasSuperclass (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_name (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_type getter_superclass (Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_type class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_type ;

//--------------------------------------------------------------------------------------------------
//
//   @char type
//
//--------------------------------------------------------------------------------------------------

class GALGAS_char : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: bool mIsValid ;
  private: utf32 mCharValue ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mIsValid ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mIsValid = false ; }
  public: inline utf32 charValue (void) const { return mCharValue ; }

//--------------------------------- Default constructor
  public: GALGAS_char (void) ;

//--------------------------------- Native constructor
  public: GALGAS_char (const utf32 inValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_char extractObject (const GALGAS_object & inObject,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_char class_func_replacementCharacter (LOCATION_ARGS) ;

  public: static class GALGAS_char class_func_unicodeCharacterFromRawKeyboard (Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_char class_func_unicodeCharacterWithUnsigned (const class GALGAS_uint & inOperand0
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_char & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeCommand (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeLetter (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeMark (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeNumber (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodePunctuation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeSeparator (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeSymbol (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isalnum (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isalpha (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_iscntrl (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isdigit (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_islower (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isupper (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isxdigit (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_unicodeName (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_char getter_unicodeToLower (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_char getter_unicodeToUpper (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_utf_33__32_CharConstantRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_utf_38_Length (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_char class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_char ;

//--------------------------------------------------------------------------------------------------
//
//   @bigint type
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint : public AC_GALGAS_root {
//--------------------------------- Private properties
  private: bool mIsValid ;
  private: BigSigned mValue ;

//--------------------------------- Accessors
  public: inline bool isValid (void) const override { return mIsValid ; }
  public: inline BigSigned bigintValue (void) const { return mValue ; }
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_bigint (void) ;

//--------------------------------- Constructor
  public: GALGAS_bigint (const BigSigned & inValue) ;
  public: GALGAS_bigint (const char * inDecimalString, Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--------------------------------- Destructor
  public: virtual ~ GALGAS_bigint (void) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_bigint extractObject (const GALGAS_object & inObject,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_bigint class_func_zero (LOCATION_ARGS) ;

//--------------------------------- << and >> shift operators
  public: VIRTUAL_IN_DEBUG GALGAS_bigint left_shift_operation (const GALGAS_uint inShiftOperand,
                                                               class Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_bigint left_shift_operation (const GALGAS_bigint inShiftOperand,
                                                               class Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_bigint right_shift_operation (const GALGAS_uint inShiftOperand,
                                                                class Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_bigint right_shift_operation (const GALGAS_bigint inShiftOperand,
                                                                class Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_bigint inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- -= operator (with expression)
  public: VIRTUAL_IN_DEBUG void minusAssign_operation (const GALGAS_bigint inOperand,
                                                        class Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- *= operator (with expression)
  public: VIRTUAL_IN_DEBUG void mulAssign_operation (const GALGAS_bigint inOperand,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- /= operator (with expression)
  public: VIRTUAL_IN_DEBUG void divAssign_operation (const GALGAS_bigint inOperand,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- & operator
  public: VIRTUAL_IN_DEBUG GALGAS_bigint operator_and (const GALGAS_bigint & inOperand
                                                       COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public: VIRTUAL_IN_DEBUG GALGAS_bigint operator_or (const GALGAS_bigint & inOperand
                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public: VIRTUAL_IN_DEBUG GALGAS_bigint operator_xor (const GALGAS_bigint & inOperand
                                                       COMMA_LOCATION_ARGS) const ;

//--------------------------------- ~ operator
  public: VIRTUAL_IN_DEBUG GALGAS_bigint operator_tilde (LOCATION_ARGS) const ;

//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_bigint add_operation (const GALGAS_bigint & inOperand,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;

//--------------------------------- - operator
  public: VIRTUAL_IN_DEBUG GALGAS_bigint substract_operation (const GALGAS_bigint & inOperand,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- * operator
  public: VIRTUAL_IN_DEBUG GALGAS_bigint multiply_operation (const GALGAS_bigint & inOperand,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- / operator
  public: VIRTUAL_IN_DEBUG GALGAS_bigint divide_operation (const GALGAS_bigint & inOperand,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

//--------------------------------- mod operator
  public: VIRTUAL_IN_DEBUG GALGAS_bigint modulo_operation (const GALGAS_bigint & inOperand,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

//--------------------------------- prefix - operator
  public: VIRTUAL_IN_DEBUG GALGAS_bigint operator_unary_minus (Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

//--------------------------------- ++, -- operators
  public: VIRTUAL_IN_DEBUG void increment_operation (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void decrement_operation (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_bigint & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_complementBitAtIndex (class GALGAS_uint constinArgument0
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setBitAtIndex (class GALGAS_bool constinArgument0,
                                                      class GALGAS_uint constinArgument1
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_divideBy (class GALGAS_bigint constinArgument0,
                                                 class GALGAS_bigint & outArgument1,
                                                 class GALGAS_bigint & outArgument2,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bigint getter_abs (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_bitAtIndex (const class GALGAS_uint & constinOperand0
                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_bitCountForSignedRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_bitCountForUnsignedRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_extract_33__32_ForSignedRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_extract_33__32_ForUnsignedRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_list getter_extract_36__34_ForSignedRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_list getter_extract_36__34_ForUnsignedRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_extract_38_ForSignedRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_extract_38_ForUnsignedRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_fitsInSInt (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_fitsInSInt_36__34_ (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_fitsInUInt (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_fitsInUInt_36__34_ (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_hexString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_hexStringSeparatedBy (const class GALGAS_char & constinOperand0,
                                                                            const class GALGAS_uint & constinOperand1,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isZero (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint getter_sign (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_spacedString (const class GALGAS_uint & constinOperand0
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_xString (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_bigint class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_bigint ;

//--------------------------------------------------------------------------------------------------
//
//  @double type
//
//--------------------------------------------------------------------------------------------------

class GALGAS_double : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: bool mIsValid ;
  private: double mDoubleValue ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mIsValid ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mIsValid = false ; }
  public: inline double doubleValue (void) const { return mDoubleValue ; }

//--------------------------------- Default constructor
  public: GALGAS_double (void) ;

//--------------------------------- Native constructor
  public: GALGAS_double (const double inValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_double extractObject (const GALGAS_object & inObject,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_double class_func_doubleWithBinaryImage (const class GALGAS_uint_36__34_ & inOperand0
                                                                       COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_double class_func_pi (LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_double inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- -= operator (with expression)
  public: VIRTUAL_IN_DEBUG void minusAssign_operation (const GALGAS_double inOperand,
                                                        class Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- *= operator (with expression)
  public: VIRTUAL_IN_DEBUG void mulAssign_operation (const GALGAS_double inOperand,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- /= operator (with expression)
  public: VIRTUAL_IN_DEBUG void divAssign_operation (const GALGAS_double inOperand,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_double add_operation (const GALGAS_double & inOperand,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;

//--------------------------------- - operator
  public: VIRTUAL_IN_DEBUG GALGAS_double substract_operation (const GALGAS_double & inOperand,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- * operator
  public: VIRTUAL_IN_DEBUG GALGAS_double multiply_operation (const GALGAS_double & inOperand,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- / operator
  public: VIRTUAL_IN_DEBUG GALGAS_double divide_operation (const GALGAS_double & inOperand,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

//--------------------------------- &/ operator
  public: VIRTUAL_IN_DEBUG GALGAS_double divide_operation_no_ovf (const GALGAS_double & inOperand) const ;

//--------------------------------- mod operator
  public: VIRTUAL_IN_DEBUG GALGAS_double modulo_operation (const GALGAS_double & inOperand,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

//--------------------------------- prefix - operator
  public: VIRTUAL_IN_DEBUG GALGAS_double operator_unary_minus (Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_double & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_binaryImage (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_cos (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_cosDegree (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_exp (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_log_31__30_ (Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_log_32_ (Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_logn (Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_power (const class GALGAS_double & constinOperand0,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_sin (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_sinDegree (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_sqrt (Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_tan (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_tanDegree (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_double class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_double ;

//--------------------------------------------------------------------------------------------------
//
//   @sint64 type
//
//--------------------------------------------------------------------------------------------------

class GALGAS_sint_36__34_ : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: bool mIsValid ;
  private: int64_t mSInt64Value ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mIsValid ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mIsValid = false ; }
  public: inline int64_t int64Value (void) const { return mSInt64Value ; }

//--------------------------------- Default constructor
  public: GALGAS_sint_36__34_ (void) ;

//--------------------------------- Native constructor
  public: GALGAS_sint_36__34_ (const int64_t inValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_sint_36__34_ extractObject (const GALGAS_object & inObject,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_sint_36__34_ class_func_max (LOCATION_ARGS) ;

  public: static class GALGAS_sint_36__34_ class_func_min (LOCATION_ARGS) ;

//--------------------------------- << and >> shift operators
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ left_shift_operation (const GALGAS_uint inShiftOperand,
                                                                     class Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ left_shift_operation (const GALGAS_bigint inShiftOperand,
                                                                     class Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ right_shift_operation (const GALGAS_uint inShiftOperand,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ right_shift_operation (const GALGAS_bigint inShiftOperand,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_sint_36__34_ inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- -= operator (with expression)
  public: VIRTUAL_IN_DEBUG void minusAssign_operation (const GALGAS_sint_36__34_ inOperand,
                                                        class Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- *= operator (with expression)
  public: VIRTUAL_IN_DEBUG void mulAssign_operation (const GALGAS_sint_36__34_ inOperand,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- /= operator (with expression)
  public: VIRTUAL_IN_DEBUG void divAssign_operation (const GALGAS_sint_36__34_ inOperand,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- & operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ operator_and (const GALGAS_sint_36__34_ & inOperand
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ operator_or (const GALGAS_sint_36__34_ & inOperand
                                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ operator_xor (const GALGAS_sint_36__34_ & inOperand
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- ~ operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ operator_tilde (LOCATION_ARGS) const ;

//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ add_operation (const GALGAS_sint_36__34_ & inOperand,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- &+ operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ add_operation_no_ovf (const GALGAS_sint_36__34_ & inOperand) const ;

//--------------------------------- &- operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ substract_operation_no_ovf (const GALGAS_sint_36__34_ & inOperand) const ;

//--------------------------------- - operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ substract_operation (const GALGAS_sint_36__34_ & inOperand,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

//--------------------------------- * operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ multiply_operation (const GALGAS_sint_36__34_ & inOperand,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- &* operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ multiply_operation_no_ovf (const GALGAS_sint_36__34_ & inOperand) const ;

//--------------------------------- / operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ divide_operation (const GALGAS_sint_36__34_ & inOperand,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

//--------------------------------- &/ operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ divide_operation_no_ovf (const GALGAS_sint_36__34_ & inOperand) const ;

//--------------------------------- mod operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ modulo_operation (const GALGAS_sint_36__34_ & inOperand,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

//--------------------------------- prefix - operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ operator_unary_minus (Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- prefix &- operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ operator_unary_minus_no_ovf (void) const ;

//--------------------------------- ++, -- operators
  public: VIRTUAL_IN_DEBUG void increment_operation (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void decrement_operation (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- &++, &-- operators
  public: VIRTUAL_IN_DEBUG void increment_operation_no_overflow (void) ;

  public: VIRTUAL_IN_DEBUG void decrement_operation_no_overflow (void) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_sint_36__34_ & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigint (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canAdd (const class GALGAS_sint_36__34_ & constinOperand0
                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canDivide (const class GALGAS_sint_36__34_ & constinOperand0
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canMultiply (const class GALGAS_sint_36__34_ & constinOperand0
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canSubstract (const class GALGAS_sint_36__34_ & constinOperand0
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_double (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_hexString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_hexStringSeparatedBy (const class GALGAS_char & constinOperand0,
                                                                            const class GALGAS_uint & constinOperand1,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_xString (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_sint_36__34_ class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sint_36__34_ ;

//--------------------------------------------------------------------------------------------------
//
//   @uint type
//
//--------------------------------------------------------------------------------------------------

class GALGAS_uint : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: bool mIsValid ;
  private: uint32_t mUIntValue ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mIsValid ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mIsValid = false ; }
  public: inline uint32_t uintValue (void) const { return mUIntValue ; }
  public: inline void increment (void) { mUIntValue ++ ; }

//--------------------------------- Default constructor
  public: GALGAS_uint (void) ;

//--------------------------------- Native constructors
  public: GALGAS_uint (const uint32_t inValue) ;
  public: GALGAS_uint (const bool inValid, const uint32_t inValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_uint extractObject (const GALGAS_object & inObject,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_uint class_func_compilationMode (LOCATION_ARGS) ;

  public: static class GALGAS_uint class_func_errorCount (LOCATION_ARGS) ;

  public: static class GALGAS_uint class_func_max (LOCATION_ARGS) ;

  public: static class GALGAS_uint class_func_random (LOCATION_ARGS) ;

  public: static class GALGAS_uint class_func_valueWithMask (const class GALGAS_uint & inOperand0,
                                                             const class GALGAS_uint & inOperand1,
                                                             class Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_uint class_func_warningCount (LOCATION_ARGS) ;

//--------------------------------- << and >> shift operators
  public: VIRTUAL_IN_DEBUG GALGAS_uint left_shift_operation (const GALGAS_uint inShiftOperand,
                                                             class Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_uint left_shift_operation (const GALGAS_bigint inShiftOperand,
                                                             class Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_uint right_shift_operation (const GALGAS_uint inShiftOperand,
                                                              class Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_uint right_shift_operation (const GALGAS_bigint inShiftOperand,
                                                              class Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_uint inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- -= operator (with expression)
  public: VIRTUAL_IN_DEBUG void minusAssign_operation (const GALGAS_uint inOperand,
                                                        class Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- *= operator (with expression)
  public: VIRTUAL_IN_DEBUG void mulAssign_operation (const GALGAS_uint inOperand,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- /= operator (with expression)
  public: VIRTUAL_IN_DEBUG void divAssign_operation (const GALGAS_uint inOperand,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- & operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint operator_and (const GALGAS_uint & inOperand
                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint operator_or (const GALGAS_uint & inOperand
                                                    COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint operator_xor (const GALGAS_uint & inOperand
                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- ~ operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint operator_tilde (LOCATION_ARGS) const ;

//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint add_operation (const GALGAS_uint & inOperand,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- &+ operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint add_operation_no_ovf (const GALGAS_uint & inOperand) const ;

//--------------------------------- &- operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint substract_operation_no_ovf (const GALGAS_uint & inOperand) const ;

//--------------------------------- - operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint substract_operation (const GALGAS_uint & inOperand,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- * operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint multiply_operation (const GALGAS_uint & inOperand,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

//--------------------------------- &* operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint multiply_operation_no_ovf (const GALGAS_uint & inOperand) const ;

//--------------------------------- / operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint divide_operation (const GALGAS_uint & inOperand,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- &/ operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint divide_operation_no_ovf (const GALGAS_uint & inOperand) const ;

//--------------------------------- mod operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint modulo_operation (const GALGAS_uint & inOperand,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- ++, -- operators
  public: VIRTUAL_IN_DEBUG void increment_operation (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void decrement_operation (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- &++, &-- operators
  public: VIRTUAL_IN_DEBUG void increment_operation_no_overflow (void) ;

  public: VIRTUAL_IN_DEBUG void decrement_operation_no_overflow (void) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_uint & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods
  public: static void class_method_setRandomSeed (class GALGAS_uint constinArgument0
                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_alphaString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigint (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canAdd (const class GALGAS_uint & constinOperand0
                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canDivide (const class GALGAS_uint & constinOperand0
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canMultiply (const class GALGAS_uint & constinOperand0
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canSubstract (const class GALGAS_uint & constinOperand0
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_double (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_hexString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_hexStringSeparatedBy (const class GALGAS_char & constinOperand0,
                                                                            const class GALGAS_uint & constinOperand1,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isInRange (const class GALGAS_range & constinOperand0
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeValueAssigned (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_lsbIndex (Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_oneBitCount (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_significantBitCount (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_xString (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_uint class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint ;

//--------------------------------------------------------------------------------------------------
//
//  @uint64 type
//
//--------------------------------------------------------------------------------------------------

class GALGAS_uint_36__34_ : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: bool mIsValid ;
  private: uint64_t mUInt64Value ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mIsValid ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mIsValid = false ; }
  public: inline uint64_t uint64Value (void) const { return mUInt64Value ; }

//--------------------------------- Default constructor
  public: GALGAS_uint_36__34_ (void) ;

//--------------------------------- Native constructor
  public: GALGAS_uint_36__34_ (const uint64_t inValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_uint_36__34_ extractObject (const GALGAS_object & inObject,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_uint_36__34_ class_func_max (LOCATION_ARGS) ;

  public: static class GALGAS_uint_36__34_ class_func_uint_36__34_BaseValueWithCompressedBitString (const class GALGAS_string & inOperand0,
                                                                                                    class Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_uint_36__34_ class_func_uint_36__34_MaskWithCompressedBitString (const class GALGAS_string & inOperand0,
                                                                                               class Compiler * inCompiler
                                                                                               COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_uint_36__34_ class_func_uint_36__34_WithBitString (const class GALGAS_string & inOperand0,
                                                                                 class Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- << and >> shift operators
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ left_shift_operation (const GALGAS_uint inShiftOperand,
                                                                     class Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ left_shift_operation (const GALGAS_bigint inShiftOperand,
                                                                     class Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ right_shift_operation (const GALGAS_uint inShiftOperand,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ right_shift_operation (const GALGAS_bigint inShiftOperand,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_uint_36__34_ inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- -= operator (with expression)
  public: VIRTUAL_IN_DEBUG void minusAssign_operation (const GALGAS_uint_36__34_ inOperand,
                                                        class Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- *= operator (with expression)
  public: VIRTUAL_IN_DEBUG void mulAssign_operation (const GALGAS_uint_36__34_ inOperand,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- /= operator (with expression)
  public: VIRTUAL_IN_DEBUG void divAssign_operation (const GALGAS_uint_36__34_ inOperand,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- & operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ operator_and (const GALGAS_uint_36__34_ & inOperand
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ operator_or (const GALGAS_uint_36__34_ & inOperand
                                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ operator_xor (const GALGAS_uint_36__34_ & inOperand
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- ~ operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ operator_tilde (LOCATION_ARGS) const ;

//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ add_operation (const GALGAS_uint_36__34_ & inOperand,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- &+ operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ add_operation_no_ovf (const GALGAS_uint_36__34_ & inOperand) const ;

//--------------------------------- &- operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ substract_operation_no_ovf (const GALGAS_uint_36__34_ & inOperand) const ;

//--------------------------------- - operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ substract_operation (const GALGAS_uint_36__34_ & inOperand,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

//--------------------------------- * operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ multiply_operation (const GALGAS_uint_36__34_ & inOperand,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- &* operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ multiply_operation_no_ovf (const GALGAS_uint_36__34_ & inOperand) const ;

//--------------------------------- / operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ divide_operation (const GALGAS_uint_36__34_ & inOperand,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

//--------------------------------- &/ operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ divide_operation_no_ovf (const GALGAS_uint_36__34_ & inOperand) const ;

//--------------------------------- mod operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ modulo_operation (const GALGAS_uint_36__34_ & inOperand,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

//--------------------------------- ++, -- operators
  public: VIRTUAL_IN_DEBUG void increment_operation (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void decrement_operation (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- &++, &-- operators
  public: VIRTUAL_IN_DEBUG void increment_operation_no_overflow (void) ;

  public: VIRTUAL_IN_DEBUG void decrement_operation_no_overflow (void) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_uint_36__34_ & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_alphaString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigint (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canAdd (const class GALGAS_uint_36__34_ & constinOperand0
                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canDivide (const class GALGAS_uint_36__34_ & constinOperand0
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canMultiply (const class GALGAS_uint_36__34_ & constinOperand0
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canSubstract (const class GALGAS_uint_36__34_ & constinOperand0
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_double (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_hexString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_hexStringSeparatedBy (const class GALGAS_char & constinOperand0,
                                                                            const class GALGAS_uint & constinOperand1,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_uintSlice (const class GALGAS_uint & constinOperand0,
                                                               const class GALGAS_uint & constinOperand1,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_xString (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_uint_36__34_ class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_36__34_ ;

//--------------------------------------------------------------------------------------------------
//
//   @sint type
//
//--------------------------------------------------------------------------------------------------

class GALGAS_sint : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: bool mIsValid ;
  private: int32_t mSIntValue ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mIsValid ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mIsValid = false ; }
  public: inline int32_t intValue (void) const { return mSIntValue ; }

//--------------------------------- Default constructor
  public: GALGAS_sint (void) ;

//--------------------------------- Native constructor
  public: GALGAS_sint (const int32_t inValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_sint extractObject (const GALGAS_object & inObject,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_sint class_func_max (LOCATION_ARGS) ;

  public: static class GALGAS_sint class_func_min (LOCATION_ARGS) ;

//--------------------------------- << and >> shift operators
  public: VIRTUAL_IN_DEBUG GALGAS_sint left_shift_operation (const GALGAS_uint inShiftOperand,
                                                             class Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_sint left_shift_operation (const GALGAS_bigint inShiftOperand,
                                                             class Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_sint right_shift_operation (const GALGAS_uint inShiftOperand,
                                                              class Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_sint right_shift_operation (const GALGAS_bigint inShiftOperand,
                                                              class Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_sint inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- -= operator (with expression)
  public: VIRTUAL_IN_DEBUG void minusAssign_operation (const GALGAS_sint inOperand,
                                                        class Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- *= operator (with expression)
  public: VIRTUAL_IN_DEBUG void mulAssign_operation (const GALGAS_sint inOperand,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- /= operator (with expression)
  public: VIRTUAL_IN_DEBUG void divAssign_operation (const GALGAS_sint inOperand,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- & operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint operator_and (const GALGAS_sint & inOperand
                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint operator_or (const GALGAS_sint & inOperand
                                                    COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint operator_xor (const GALGAS_sint & inOperand
                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- ~ operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint operator_tilde (LOCATION_ARGS) const ;

//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint add_operation (const GALGAS_sint & inOperand,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- &+ operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint add_operation_no_ovf (const GALGAS_sint & inOperand) const ;

//--------------------------------- &- operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint substract_operation_no_ovf (const GALGAS_sint & inOperand) const ;

//--------------------------------- - operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint substract_operation (const GALGAS_sint & inOperand,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- * operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint multiply_operation (const GALGAS_sint & inOperand,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

//--------------------------------- &* operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint multiply_operation_no_ovf (const GALGAS_sint & inOperand) const ;

//--------------------------------- / operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint divide_operation (const GALGAS_sint & inOperand,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- &/ operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint divide_operation_no_ovf (const GALGAS_sint & inOperand) const ;

//--------------------------------- mod operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint modulo_operation (const GALGAS_sint & inOperand,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- prefix - operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint operator_unary_minus (Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- prefix &- operator
  public: VIRTUAL_IN_DEBUG GALGAS_sint operator_unary_minus_no_ovf (void) const ;

//--------------------------------- ++, -- operators
  public: VIRTUAL_IN_DEBUG void increment_operation (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void decrement_operation (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- &++, &-- operators
  public: VIRTUAL_IN_DEBUG void increment_operation_no_overflow (void) ;

  public: VIRTUAL_IN_DEBUG void decrement_operation_no_overflow (void) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_sint & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigint (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canAdd (const class GALGAS_sint & constinOperand0
                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canDivide (const class GALGAS_sint & constinOperand0
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canMultiply (const class GALGAS_sint & constinOperand0
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_canSubstract (const class GALGAS_sint & constinOperand0
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_double getter_double (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_hexString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_hexStringSeparatedBy (const class GALGAS_char & constinOperand0,
                                                                            const class GALGAS_uint & constinOperand1,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_xString (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_sint class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sint ;

//--------------------------------------------------------------------------------------------------
//
//@application package
//
//--------------------------------------------------------------------------------------------------

class GALGAS_application final {

//-- Start of package generic part

//--------------------------------- GALGAS class getters
  public: static class GALGAS_string class_func_boolOptionCommentString (const class GALGAS_string & inOperand0,
                                                                         const class GALGAS_string & inOperand1
                                                                         COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_char class_func_boolOptionInvocationCharacter (const class GALGAS_string & inOperand0,
                                                                             const class GALGAS_string & inOperand1
                                                                             COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_boolOptionInvocationString (const class GALGAS_string & inOperand0,
                                                                            const class GALGAS_string & inOperand1
                                                                            COMMA_LOCATION_ARGS) ;

  public: static class GALGAS__32_stringlist class_func_boolOptionNameList (LOCATION_ARGS) ;

  public: static class GALGAS_bool class_func_boolOptionValue (const class GALGAS_string & inOperand0,
                                                               const class GALGAS_string & inOperand1
                                                               COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_commandLineArgumentAtIndex (const class GALGAS_uint & inOperand0,
                                                                            class Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_uint class_func_commandLineArgumentCount (LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_galgasVersionString (LOCATION_ARGS) ;

  public: static class GALGAS_stringset class_func_keywordIdentifierSet (LOCATION_ARGS) ;

  public: static class GALGAS_stringlist class_func_keywordListForIdentifier (const class GALGAS_string & inOperand0
                                                                              COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_projectVersionString (LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_stringOptionCommentString (const class GALGAS_string & inOperand0,
                                                                           const class GALGAS_string & inOperand1
                                                                           COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_char class_func_stringOptionInvocationCharacter (const class GALGAS_string & inOperand0,
                                                                               const class GALGAS_string & inOperand1
                                                                               COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_stringOptionInvocationString (const class GALGAS_string & inOperand0,
                                                                              const class GALGAS_string & inOperand1
                                                                              COMMA_LOCATION_ARGS) ;

  public: static class GALGAS__32_stringlist class_func_stringOptionNameList (LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_stringOptionValue (const class GALGAS_string & inOperand0,
                                                                   const class GALGAS_string & inOperand1
                                                                   COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_system (LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_uintOptionCommentString (const class GALGAS_string & inOperand0,
                                                                         const class GALGAS_string & inOperand1
                                                                         COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_char class_func_uintOptionInvocationCharacter (const class GALGAS_string & inOperand0,
                                                                             const class GALGAS_string & inOperand1
                                                                             COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_string class_func_uintOptionInvocationString (const class GALGAS_string & inOperand0,
                                                                            const class GALGAS_string & inOperand1
                                                                            COMMA_LOCATION_ARGS) ;

  public: static class GALGAS__32_stringlist class_func_uintOptionNameList (LOCATION_ARGS) ;

  public: static class GALGAS_uint class_func_uintOptionValue (const class GALGAS_string & inOperand0,
                                                               const class GALGAS_string & inOperand1
                                                               COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_bool class_func_verboseOutput (LOCATION_ARGS) ;

//--------------------------------- Class Methods
  public: static void class_method_exit (class GALGAS_uint constinArgument0
                                         COMMA_LOCATION_ARGS) ;

  public: static void class_method_setBoolOptionValue (class GALGAS_string constinArgument0,
                                                       class GALGAS_string constinArgument1,
                                                       class GALGAS_bool constinArgument2
                                                       COMMA_LOCATION_ARGS) ;

  public: static void class_method_setStringOptionValue (class GALGAS_string constinArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         class GALGAS_string constinArgument2
                                                         COMMA_LOCATION_ARGS) ;

  public: static void class_method_setUIntOptionValue (class GALGAS_string constinArgument0,
                                                       class GALGAS_string constinArgument1,
                                                       class GALGAS_uint constinArgument2
                                                       COMMA_LOCATION_ARGS) ;


} ;

//--------------------------------------------------------------------------------------------------
//
// @binaryset type
//
//--------------------------------------------------------------------------------------------------

#include "C_BDD.h"

//--------------------------------------------------------------------------------------------------

class GALGAS_binaryset : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: bool mIsValid ;
  private: C_BDD mBDD ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mIsValid ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mIsValid = false ; }
  public: inline C_BDD bddValue (void) const { return mBDD ; }

//--------------------------------- Default constructor
  public: GALGAS_binaryset (void) ;

//--------------------------------- Native constructor
  public: GALGAS_binaryset (const C_BDD & inValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_binaryset extractObject (const GALGAS_object & inObject,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_binaryset class_func_binarySetWithBit (const class GALGAS_uint & inOperand0,
                                                                     class Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithEqualComparison (const class GALGAS_uint & inOperand0,
                                                                                 const class GALGAS_uint & inOperand1,
                                                                                 const class GALGAS_uint & inOperand2,
                                                                                 class Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithEqualToConstant (const class GALGAS_uint & inOperand0,
                                                                                 const class GALGAS_uint & inOperand1,
                                                                                 const class GALGAS_uint_36__34_ & inOperand2,
                                                                                 class Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithGreaterOrEqualComparison (const class GALGAS_uint & inOperand0,
                                                                                          const class GALGAS_uint & inOperand1,
                                                                                          const class GALGAS_uint & inOperand2,
                                                                                          class Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithGreaterOrEqualToConstant (const class GALGAS_uint & inOperand0,
                                                                                          const class GALGAS_uint & inOperand1,
                                                                                          const class GALGAS_uint_36__34_ & inOperand2,
                                                                                          class Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithLowerOrEqualComparison (const class GALGAS_uint & inOperand0,
                                                                                        const class GALGAS_uint & inOperand1,
                                                                                        const class GALGAS_uint & inOperand2,
                                                                                        class Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithLowerOrEqualToConstant (const class GALGAS_uint & inOperand0,
                                                                                        const class GALGAS_uint & inOperand1,
                                                                                        const class GALGAS_uint_36__34_ & inOperand2,
                                                                                        class Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithNotEqualComparison (const class GALGAS_uint & inOperand0,
                                                                                    const class GALGAS_uint & inOperand1,
                                                                                    const class GALGAS_uint & inOperand2,
                                                                                    class Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithNotEqualToConstant (const class GALGAS_uint & inOperand0,
                                                                                    const class GALGAS_uint & inOperand1,
                                                                                    const class GALGAS_uint_36__34_ & inOperand2,
                                                                                    class Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithPredicateString (const class GALGAS_string & inOperand0,
                                                                                 class Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithStrictGreaterComparison (const class GALGAS_uint & inOperand0,
                                                                                         const class GALGAS_uint & inOperand1,
                                                                                         const class GALGAS_uint & inOperand2,
                                                                                         class Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithStrictGreaterThanConstant (const class GALGAS_uint & inOperand0,
                                                                                           const class GALGAS_uint & inOperand1,
                                                                                           const class GALGAS_uint_36__34_ & inOperand2,
                                                                                           class Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithStrictLowerComparison (const class GALGAS_uint & inOperand0,
                                                                                       const class GALGAS_uint & inOperand1,
                                                                                       const class GALGAS_uint & inOperand2,
                                                                                       class Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_binarySetWithStrictLowerThanConstant (const class GALGAS_uint & inOperand0,
                                                                                         const class GALGAS_uint & inOperand1,
                                                                                         const class GALGAS_uint_36__34_ & inOperand2,
                                                                                         class Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_emptyBinarySet (LOCATION_ARGS) ;

  public: static class GALGAS_binaryset class_func_fullBinarySet (LOCATION_ARGS) ;

//--------------------------------- << and >> shift operators
  public: VIRTUAL_IN_DEBUG GALGAS_binaryset left_shift_operation (const GALGAS_uint inShiftOperand,
                                                                  class Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_binaryset left_shift_operation (const GALGAS_bigint inShiftOperand,
                                                                  class Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_binaryset right_shift_operation (const GALGAS_uint inShiftOperand,
                                                                   class Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_binaryset right_shift_operation (const GALGAS_bigint inShiftOperand,
                                                                   class Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- & operator
  public: VIRTUAL_IN_DEBUG GALGAS_binaryset operator_and (const GALGAS_binaryset & inOperand
                                                          COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public: VIRTUAL_IN_DEBUG GALGAS_binaryset operator_or (const GALGAS_binaryset & inOperand
                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public: VIRTUAL_IN_DEBUG GALGAS_binaryset operator_xor (const GALGAS_binaryset & inOperand
                                                          COMMA_LOCATION_ARGS) const ;

//--------------------------------- ~ operator
  public: VIRTUAL_IN_DEBUG GALGAS_binaryset operator_tilde (LOCATION_ARGS) const ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_binaryset & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods
  public: static void class_method_setAndTableSize (class GALGAS_uint constinArgument0
                                                    COMMA_LOCATION_ARGS) ;

  public: static void class_method_setNodeTableSize (class GALGAS_uint constinArgument0
                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_ITE (const class GALGAS_binaryset & constinOperand0,
                                                              const class GALGAS_binaryset & constinOperand1
                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_accessibleStates (const class GALGAS_binaryset & constinOperand0,
                                                                           const class GALGAS_uint & constinOperand1
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigValueCount (const class GALGAS_uint & constinOperand0,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_binarySetByTranslatingFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                          const class GALGAS_uint & constinOperand1
                                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_compressedStringValueList (const class GALGAS_uint & constinOperand0,
                                                                                     Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_compressedValueCount (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_containsValue (const class GALGAS_uint_36__34_ & constinOperand0,
                                                                   const class GALGAS_uint & constinOperand1,
                                                                   const class GALGAS_uint & constinOperand2
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_equalTo (const class GALGAS_binaryset & constinOperand0
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_existOnBitIndex (const class GALGAS_uint & constinOperand0
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_existOnBitIndexAndBeyond (const class GALGAS_uint & constinOperand0
                                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_existsOnBitRange (const class GALGAS_uint & constinOperand0,
                                                                           const class GALGAS_uint & constinOperand1
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_forAllOnBitIndex (const class GALGAS_uint & constinOperand0
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_forAllOnBitIndexAndBeyond (const class GALGAS_uint & constinOperand0
                                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_graphviz (const class GALGAS_stringlist & constinOperand0
                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_graphvizDump (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_greaterOrEqualTo (const class GALGAS_binaryset & constinOperand0
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_implies (const class GALGAS_binaryset & constinOperand0
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isEmpty (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isFull (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_lowerOrEqualTo (const class GALGAS_binaryset & constinOperand0
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_nodeCount (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_notEqualTo (const class GALGAS_binaryset & constinOperand0
                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_predicateStringValue (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_print (const class GALGAS_stringlist & constinOperand0,
                                                             const class GALGAS_uintlist & constinOperand1
                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_significantVariableCount (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_strictGreaterThan (const class GALGAS_binaryset & constinOperand0
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_strictLowerThan (const class GALGAS_binaryset & constinOperand0
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_stringValueList (const class GALGAS_uint & constinOperand0
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_stringValueListWithNameList (const class GALGAS_uint & constinOperand0,
                                                                                       const class GALGAS_stringlist & constinOperand1,
                                                                                       Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_swap_30__32__31_ (const class GALGAS_uint & constinOperand0,
                                                                           const class GALGAS_uint & constinOperand1,
                                                                           const class GALGAS_uint & constinOperand2
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_swap_31__30_ (const class GALGAS_uint & constinOperand0,
                                                                       const class GALGAS_uint & constinOperand1
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_swap_31__30__32_ (const class GALGAS_uint & constinOperand0,
                                                                           const class GALGAS_uint & constinOperand1,
                                                                           const class GALGAS_uint & constinOperand2
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_swap_31__32__30_ (const class GALGAS_uint & constinOperand0,
                                                                           const class GALGAS_uint & constinOperand1,
                                                                           const class GALGAS_uint & constinOperand2
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_swap_32__30__31_ (const class GALGAS_uint & constinOperand0,
                                                                           const class GALGAS_uint & constinOperand1,
                                                                           const class GALGAS_uint & constinOperand2
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_swap_32__31__30_ (const class GALGAS_uint & constinOperand0,
                                                                           const class GALGAS_uint & constinOperand1,
                                                                           const class GALGAS_uint & constinOperand2
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_transformedBy (const class GALGAS_uintlist & constinOperand0
                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_transitiveClosure (const class GALGAS_uint & constinOperand0
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_transposedBy (const class GALGAS_uintlist & constinOperand0,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_list getter_uint_36__34_ValueList (const class GALGAS_uint & constinOperand0
                                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_valueCount (const class GALGAS_uint & constinOperand0,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_binaryset class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_binaryset ;

//--------------------------------------------------------------------------------------------------
//
//   @data type
//
//--------------------------------------------------------------------------------------------------

class GALGAS_data : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: bool mIsValid ;
  private: U8Data mData ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mIsValid ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mIsValid = false ; }
  public: inline U8Data dataValue (void) const { return mData ; }

//--------------------------------- Default constructor
  public: GALGAS_data (void) ;

//--------------------------------- Native constructor
  public: GALGAS_data (const U8Data & inData) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_data extractObject (const GALGAS_object & inObject,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_data class_func_dataWithContentsOfFile (const class GALGAS_string & inOperand0,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_data class_func_emptyData (LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_data & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_appendByte (class GALGAS_uint constinArgument0,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_appendData (class GALGAS_data constinArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_appendShortBE (class GALGAS_uint constinArgument0,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_appendShortLE (class GALGAS_uint constinArgument0,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_appendUIntBE (class GALGAS_uint constinArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_appendUIntLE (class GALGAS_uint constinArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_appendUTF_38_String (class GALGAS_string constinArgument0
                                                            COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_writeToExecutableFile (class GALGAS_string constinArgument0,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_writeToFile (class GALGAS_string constinArgument0,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_writeToFileWhenDifferentContents (class GALGAS_string constinArgument0,
                                                                         class GALGAS_bool & outArgument1,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_cStringRepresentation (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_count (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Enumeration helper methods
  protected: VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & inEnumerationArray) const ;

//--------------------------------- Friend

  friend class cEnumerator_data ;
 
} ; // End of GALGAS_data class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_data : public cGenericAbstractEnumerator {
  public: cEnumerator_data (const GALGAS_data & inEnumeratedObject,
                            const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_uint current_data (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_uint current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_data ;

//--------------------------------------------------------------------------------------------------
//
//   @filewrapper type
//
//--------------------------------------------------------------------------------------------------

class cRegularFileWrapper {
  public: const char * mName ;
  public: const char * mExtension ;
  public: const bool mIsTextFile ; // True: text file, false: binary file
  public: const uint32_t mFileLength ;
  public: const char * mContents ;

//--- Constructor
  public: cRegularFileWrapper (const char * inName,
                                const char * inExtension,
                                const bool inIsTextFile,
                                const uint32_t inFileLength,
                                const char * inContents) ;

//--- No copy
  private: cRegularFileWrapper (const cRegularFileWrapper &) ;
  private: cRegularFileWrapper & operator = (const cRegularFileWrapper &) ;
} ;

//--------------------------------------------------------------------------------------------------

class cDirectoryWrapper {
  public: const char * mDirectoryName ;
  public: const uint32_t mFileCount ;
  public: const cRegularFileWrapper * * const mFiles ;
  public: const uint32_t mDirectoryCount ;
  public: const cDirectoryWrapper * * mDirectories ;

//--- Constructor
  public: cDirectoryWrapper (const char * inDirectoryName,
                              const uint32_t inFileCount,
                              const cRegularFileWrapper * * const inFiles,
                              const uint32_t inDirectoryCount,
                              const cDirectoryWrapper * * inDirectories) ;

//--- No copy
  private: cDirectoryWrapper (const cDirectoryWrapper &) ;
  private: cDirectoryWrapper & operator = (const cDirectoryWrapper &) ;
} ;

//--------------------------------------------------------------------------------------------------

class GALGAS_filewrapper : public AC_GALGAS_root {
//--------------------------------- Private data members
  private: const cDirectoryWrapper * mRootDirectoryPtr ;
  private: String mCurrentDirectory ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return nullptr != mRootDirectoryPtr ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mRootDirectoryPtr = nullptr ; }

//--------------------------------- Default constructor
  public: GALGAS_filewrapper (void) ;

//--------------------------------- Native constructor
  public: GALGAS_filewrapper (const cDirectoryWrapper & inRootDirectory) ;

//--------------------------------- Handle copy
  public: GALGAS_filewrapper (const GALGAS_filewrapper & inSource) ;
  public: GALGAS_filewrapper & operator = (const GALGAS_filewrapper & inSource) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_filewrapper extractObject (const GALGAS_object & inObject,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_filewrapper & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setCurrentDirectory (class GALGAS_string constinArgument0,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_absolutePathForPath (const class GALGAS_string & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_allBinaryFilePathes (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_allDirectoryPathes (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_allFilePathesWithExtension (const class GALGAS_string & constinOperand0
                                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_allTextFilePathes (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_data getter_binaryFileContentsAtPath (const class GALGAS_string & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_binaryFilesAtPath (const class GALGAS_string & constinOperand0,
                                                                             Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_currentDirectory (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_directoriesAtPath (const class GALGAS_string & constinOperand0,
                                                                             Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_directoryExistsAtPath (const class GALGAS_string & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_fileExistsAtPath (const class GALGAS_string & constinOperand0,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_textFileContentsAtPath (const class GALGAS_string & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_textFilesAtPath (const class GALGAS_string & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_filewrapper class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_filewrapper ;

//--------------------------------------------------------------------------------------------------
//
//   @function type
//
//--------------------------------------------------------------------------------------------------

class C_galgas_function_descriptor ;

//--------------------------------------------------------------------------------------------------

class GALGAS_function : public AC_GALGAS_root {
//--------------------------------- Private data member
  private: const C_galgas_function_descriptor * mFunctionDescriptor ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return nullptr != mFunctionDescriptor ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mFunctionDescriptor = nullptr ; }
  public: VIRTUAL_IN_DEBUG inline const C_galgas_function_descriptor * functionValue (void) const { return mFunctionDescriptor ; }

//--------------------------------- Default constructor
  public: GALGAS_function (void) ;

//--------------------------------- Destructor (virtual in debug mode)
  public: virtual ~ GALGAS_function (void) ;

//--------------------------------- Handle copy
  public: GALGAS_function (const GALGAS_function & inSource) ;
  public: GALGAS_function & operator = (const GALGAS_function & inSource) ;

//--------------------------------- Native constructor
  public: GALGAS_function (const C_galgas_function_descriptor * inValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_function extractObject (const GALGAS_object & inObject,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_functionlist class_func_functionList (LOCATION_ARGS) ;

  public: static class GALGAS_function class_func_functionWithName (const class GALGAS_string & inOperand0
                                                                    COMMA_LOCATION_ARGS) ;

  public: static class GALGAS_bool class_func_isFunctionDefined (const class GALGAS_string & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_function & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_typelist getter_formalParameterTypeList (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_object getter_invoke (const class GALGAS_objectlist & constinOperand0,
                                                              const class GALGAS_location & constinOperand1,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_name (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_type getter_resultType (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_function class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_function ;

//--------------------------------------------------------------------------------------------------
//
//   @object type
//
//--------------------------------------------------------------------------------------------------

class cPtr_object ;

//--------------------------------------------------------------------------------------------------

class GALGAS_object : public AC_GALGAS_root {
//--------------------------------- Private data member
  private: cPtr_object * mSharedObject ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mSharedObject != nullptr ; }
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_object (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_object (AC_GALGAS_root * inObjectPointer
                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Destructor (virtual in debug mode)
  public: virtual ~ GALGAS_object (void) ;

//--------------------------------- Handle copy
  public: GALGAS_object (const GALGAS_object & inSource) ;
  public: GALGAS_object & operator = (const GALGAS_object & inSource) ;

//--------------------------------- Embedded Object
  public: const AC_GALGAS_root * embeddedObject (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_object extractObject (const GALGAS_object & inObject,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_object & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_type getter_objectDynamicType (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_type getter_objectStaticType (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_object class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_object ;

//--------------------------------------------------------------------------------------------------
//
//   @timer type
//
//--------------------------------------------------------------------------------------------------

class GALGAS_timer : public AC_GALGAS_root {
//--------------------------------- Private properties
  private: bool mIsValid ;
  private: Timer mTimer ;

//--------------------------------- Accessors
  public: inline bool isValid (void) const override { return mIsValid ; }
  public: VIRTUAL_IN_DEBUG void drop (void) override { mIsValid = false ; }

//--------------------------------- Default constructor
  public: GALGAS_timer (void) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_timer extractObject (const GALGAS_object & inObject,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_timer class_func_start (LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_timer & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_resume (LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_stop (LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRunning (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_msFromStart (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_timer class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_timer ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @stringlist list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_stringlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_stringlist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_stringlist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_string & in_mValue
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_stringlist extractObject (const GALGAS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_stringlist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_stringlist class_func_listWithValue (const class GALGAS_string & inOperand0
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_stringlist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_string & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_stringlist add_operation (const GALGAS_stringlist & inOperand,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_string constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_string constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_string & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_string & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_string & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_string constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_string & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_string & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_stringlist ;
 
} ; // End of GALGAS_stringlist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_stringlist : public cGenericAbstractEnumerator {
  public: cEnumerator_stringlist (const GALGAS_stringlist & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_string current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_stringlist_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringlist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @lbigint struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lbigint : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_bigint mProperty_bigint ;
  public: inline GALGAS_bigint readProperty_bigint (void) const {
    return mProperty_bigint ;
  }

  public: GALGAS_location mProperty_location ;
  public: inline GALGAS_location readProperty_location (void) const {
    return mProperty_location ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_lbigint (void) ;

//--------------------------------- Property setters
  public: inline void setter_setBigint (const GALGAS_bigint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_bigint = inValue ;
  }

  public: inline void setter_setLocation (const GALGAS_location & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_location = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_lbigint (void) ;

//--------------------------------- Native constructor
  public: GALGAS_lbigint (const GALGAS_bigint & in_bigint,
                          const GALGAS_location & in_location) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lbigint extractObject (const GALGAS_object & inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_lbigint class_func_new (const class GALGAS_bigint & inOperand0,
                                                      const class GALGAS_location & inOperand1,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_lbigint & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_lbigint class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lbigint ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @lstringlist list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstringlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_lstringlist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_lstringlist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_lstring & in_mValue
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lstringlist extractObject (const GALGAS_object & inObject,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_lstringlist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_lstringlist class_func_listWithValue (const class GALGAS_lstring & inOperand0
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_lstringlist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_lstringlist add_operation (const GALGAS_lstringlist & inOperand,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_lstring constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_lstring & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_lstring & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_lstring constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lstringlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                             Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lstringlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lstringlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                             Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_lstringlist ;
 
} ; // End of GALGAS_lstringlist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_lstringlist : public cGenericAbstractEnumerator {
  public: cEnumerator_lstringlist (const GALGAS_lstringlist & inEnumeratedObject,
                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_lstringlist_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lstringlist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @lbool struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lbool : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_bool mProperty_bool ;
  public: inline GALGAS_bool readProperty_bool (void) const {
    return mProperty_bool ;
  }

  public: GALGAS_location mProperty_location ;
  public: inline GALGAS_location readProperty_location (void) const {
    return mProperty_location ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_lbool (void) ;

//--------------------------------- Property setters
  public: inline void setter_setBool (const GALGAS_bool & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_bool = inValue ;
  }

  public: inline void setter_setLocation (const GALGAS_location & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_location = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_lbool (void) ;

//--------------------------------- Native constructor
  public: GALGAS_lbool (const GALGAS_bool & in_bool,
                        const GALGAS_location & in_location) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lbool extractObject (const GALGAS_object & inObject,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_lbool class_func_new (const class GALGAS_bool & inOperand0,
                                                    const class GALGAS_location & inOperand1,
                                                    class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_lbool & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_lbool class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lbool ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @functionlist list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_functionlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_functionlist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_functionlist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_function & in_mValue
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_functionlist extractObject (const GALGAS_object & inObject,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_functionlist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_functionlist class_func_listWithValue (const class GALGAS_function & inOperand0
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_functionlist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_function & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_functionlist add_operation (const GALGAS_functionlist & inOperand,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_function constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_function constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_function & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_function & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_function & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_function constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_function & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_function & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_function getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_functionlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_functionlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_functionlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_functionlist ;
 
} ; // End of GALGAS_functionlist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_functionlist : public cGenericAbstractEnumerator {
  public: cEnumerator_functionlist (const GALGAS_functionlist & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_function current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_functionlist_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_functionlist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @luintlist list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_luintlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_luintlist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_luintlist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_luint & in_mValue
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_luintlist extractObject (const GALGAS_object & inObject,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_luintlist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_luintlist class_func_listWithValue (const class GALGAS_luint & inOperand0
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_luintlist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_luint & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_luintlist add_operation (const GALGAS_luintlist & inOperand,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_luint constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_luint constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_luint & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_luint & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_luint & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_luint constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_luint & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_luint & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luintlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luintlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luintlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_luintlist ;
 
} ; // End of GALGAS_luintlist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_luintlist : public cGenericAbstractEnumerator {
  public: cEnumerator_luintlist (const GALGAS_luintlist & inEnumeratedObject,
                                 const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_luint current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_luintlist_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_luintlist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @luint struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_luint : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_uint mProperty_uint ;
  public: inline GALGAS_uint readProperty_uint (void) const {
    return mProperty_uint ;
  }

  public: GALGAS_location mProperty_location ;
  public: inline GALGAS_location readProperty_location (void) const {
    return mProperty_location ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_luint (void) ;

//--------------------------------- Property setters
  public: inline void setter_setUint (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_uint = inValue ;
  }

  public: inline void setter_setLocation (const GALGAS_location & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_location = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_luint (void) ;

//--------------------------------- Native constructor
  public: GALGAS_luint (const GALGAS_uint & in_uint,
                        const GALGAS_location & in_location) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_luint extractObject (const GALGAS_object & inObject,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_luint class_func_new (const class GALGAS_uint & inOperand0,
                                                    const class GALGAS_location & inOperand1,
                                                    class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_luint & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_luint class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_luint ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @objectlist list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_objectlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_objectlist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_objectlist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_object & in_mValue
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_objectlist extractObject (const GALGAS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_objectlist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_objectlist class_func_listWithValue (const class GALGAS_object & inOperand0
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_objectlist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_object & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_objectlist add_operation (const GALGAS_objectlist & inOperand,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_object constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_object constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_object & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_object & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_object & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_object constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_object & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_object & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_object getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_objectlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_objectlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_objectlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_objectlist ;
 
} ; // End of GALGAS_objectlist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_objectlist : public cGenericAbstractEnumerator {
  public: cEnumerator_objectlist (const GALGAS_objectlist & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_object current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_objectlist_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectlist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typelist list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typelist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_typelist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_typelist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_type & in_mValue
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typelist extractObject (const GALGAS_object & inObject,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typelist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_typelist class_func_listWithValue (const class GALGAS_type & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_typelist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_type & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_typelist add_operation (const GALGAS_typelist & inOperand,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_type constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_type constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_type & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_type & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_type & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_type constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_type & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_type & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_type getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typelist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typelist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typelist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_typelist ;
 
} ; // End of GALGAS_typelist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_typelist : public cGenericAbstractEnumerator {
  public: cEnumerator_typelist (const GALGAS_typelist & inEnumeratedObject,
                                const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_type current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_typelist_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typelist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @uintlist list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_uintlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_uintlist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_uintlist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_uint & in_mValue
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_uintlist extractObject (const GALGAS_object & inObject,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_uintlist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_uintlist class_func_listWithValue (const class GALGAS_uint & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_uintlist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_uint & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_uintlist add_operation (const GALGAS_uintlist & inOperand,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_uint constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_uint constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_uint & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_uint & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_uint & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_uint constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_uint & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_uint & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_uintlist ;
 
} ; // End of GALGAS_uintlist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_uintlist : public cGenericAbstractEnumerator {
  public: cEnumerator_uintlist (const GALGAS_uintlist & inEnumeratedObject,
                                const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_uint current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_uintlist_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uintlist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @uint64list list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_uint_36__34_list : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_uint_36__34_list (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_uint_36__34_list (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_uint_36__34_ & in_mValue
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_uint_36__34_list extractObject (const GALGAS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_uint_36__34_list class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_uint_36__34_list class_func_listWithValue (const class GALGAS_uint_36__34_ & inOperand0
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_uint_36__34_list inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_uint_36__34_ & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_uint_36__34_list add_operation (const GALGAS_uint_36__34_list & inOperand,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_uint_36__34_ constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_uint_36__34_ constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_uint_36__34_ & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_uint_36__34_ & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_uint_36__34_ & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_uint_36__34_ constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_uint_36__34_ & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_uint_36__34_ & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_list getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_list getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_list getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_uint_36__34_list ;
 
} ; // End of GALGAS_uint_36__34_list class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_uint_36__34_list : public cGenericAbstractEnumerator {
  public: cEnumerator_uint_36__34_list (const GALGAS_uint_36__34_list & inEnumeratedObject,
                                        const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_uint_36__34_ current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_uint_36__34_list_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_36__34_list ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @bigintlist list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigintlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_bigintlist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_bigintlist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_bigint & in_mValue
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_bigintlist extractObject (const GALGAS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_bigintlist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_bigintlist class_func_listWithValue (const class GALGAS_bigint & inOperand0
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_bigintlist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_bigint & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_bigintlist add_operation (const GALGAS_bigintlist & inOperand,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_bigint constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_bigint constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_bigint & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_bigint & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_bigint & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_bigint constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_bigint & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_bigint & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bigint getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bigintlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bigintlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bigintlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_bigintlist ;
 
} ; // End of GALGAS_bigintlist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_bigintlist : public cGenericAbstractEnumerator {
  public: cEnumerator_bigintlist (const GALGAS_bigintlist & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_bigint current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_bigintlist_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_bigintlist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @lbigintlist list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lbigintlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_lbigintlist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_lbigintlist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_lbigint & in_mValue
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lbigintlist extractObject (const GALGAS_object & inObject,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_lbigintlist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_lbigintlist class_func_listWithValue (const class GALGAS_lbigint & inOperand0
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_lbigintlist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lbigint & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_lbigintlist add_operation (const GALGAS_lbigintlist & inOperand,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_lbigint constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_lbigint constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_lbigint & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_lbigint & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_lbigint & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_lbigint constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_lbigint & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_lbigint & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_lbigint getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lbigintlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                             Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lbigintlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lbigintlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                             Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_lbigintlist ;
 
} ; // End of GALGAS_lbigintlist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_lbigintlist : public cGenericAbstractEnumerator {
  public: cEnumerator_lbigintlist (const GALGAS_lbigintlist & inEnumeratedObject,
                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lbigint current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_lbigintlist_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lbigintlist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @lchar struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lchar : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_char mProperty_char ;
  public: inline GALGAS_char readProperty_char (void) const {
    return mProperty_char ;
  }

  public: GALGAS_location mProperty_location ;
  public: inline GALGAS_location readProperty_location (void) const {
    return mProperty_location ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_lchar (void) ;

//--------------------------------- Property setters
  public: inline void setter_setChar (const GALGAS_char & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_char = inValue ;
  }

  public: inline void setter_setLocation (const GALGAS_location & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_location = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_lchar (void) ;

//--------------------------------- Native constructor
  public: GALGAS_lchar (const GALGAS_char & in_char,
                        const GALGAS_location & in_location) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lchar extractObject (const GALGAS_object & inObject,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_lchar class_func_new (const class GALGAS_char & inOperand0,
                                                    const class GALGAS_location & inOperand1,
                                                    class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_lchar & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_lchar class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lchar ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @ldouble struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_ldouble : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_double mProperty_double ;
  public: inline GALGAS_double readProperty_double (void) const {
    return mProperty_double ;
  }

  public: GALGAS_location mProperty_location ;
  public: inline GALGAS_location readProperty_location (void) const {
    return mProperty_location ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_ldouble (void) ;

//--------------------------------- Property setters
  public: inline void setter_setDouble (const GALGAS_double & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_double = inValue ;
  }

  public: inline void setter_setLocation (const GALGAS_location & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_location = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_ldouble (void) ;

//--------------------------------- Native constructor
  public: GALGAS_ldouble (const GALGAS_double & in_double,
                          const GALGAS_location & in_location) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_ldouble extractObject (const GALGAS_object & inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_ldouble class_func_new (const class GALGAS_double & inOperand0,
                                                      const class GALGAS_location & inOperand1,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_ldouble & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_ldouble class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_ldouble ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @lsint_36__34_ struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lsint_36__34_ : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_sint_36__34_ mProperty_sint_36__34_ ;
  public: inline GALGAS_sint_36__34_ readProperty_sint_36__34_ (void) const {
    return mProperty_sint_36__34_ ;
  }

  public: GALGAS_location mProperty_location ;
  public: inline GALGAS_location readProperty_location (void) const {
    return mProperty_location ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_lsint_36__34_ (void) ;

//--------------------------------- Property setters
  public: inline void setter_setSint_36__34_ (const GALGAS_sint_36__34_ & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_sint_36__34_ = inValue ;
  }

  public: inline void setter_setLocation (const GALGAS_location & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_location = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_lsint_36__34_ (void) ;

//--------------------------------- Native constructor
  public: GALGAS_lsint_36__34_ (const GALGAS_sint_36__34_ & in_sint_36__34_,
                                const GALGAS_location & in_location) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lsint_36__34_ extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_lsint_36__34_ class_func_new (const class GALGAS_sint_36__34_ & inOperand0,
                                                            const class GALGAS_location & inOperand1,
                                                            class Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_lsint_36__34_ & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_lsint_36__34_ class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lsint_36__34_ ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @luint_36__34_ struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_luint_36__34_ : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_uint_36__34_ mProperty_uint_36__34_ ;
  public: inline GALGAS_uint_36__34_ readProperty_uint_36__34_ (void) const {
    return mProperty_uint_36__34_ ;
  }

  public: GALGAS_location mProperty_location ;
  public: inline GALGAS_location readProperty_location (void) const {
    return mProperty_location ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_luint_36__34_ (void) ;

//--------------------------------- Property setters
  public: inline void setter_setUint_36__34_ (const GALGAS_uint_36__34_ & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_uint_36__34_ = inValue ;
  }

  public: inline void setter_setLocation (const GALGAS_location & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_location = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_luint_36__34_ (void) ;

//--------------------------------- Native constructor
  public: GALGAS_luint_36__34_ (const GALGAS_uint_36__34_ & in_uint_36__34_,
                                const GALGAS_location & in_location) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_luint_36__34_ extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_luint_36__34_ class_func_new (const class GALGAS_uint_36__34_ & inOperand0,
                                                            const class GALGAS_location & inOperand1,
                                                            class Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_luint_36__34_ & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_luint_36__34_ class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_luint_36__34_ ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @2stringlist list
//
//--------------------------------------------------------------------------------------------------

class GALGAS__32_stringlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS__32_stringlist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS__32_stringlist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_string & in_mValue_30_,
                                                 const class GALGAS_string & in_mValue_31_
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS__32_stringlist extractObject (const GALGAS_object & inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS__32_stringlist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS__32_stringlist class_func_listWithValue (const class GALGAS_string & inOperand0,
                                                                       const class GALGAS_string & inOperand1
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS__32_stringlist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_string & inOperand0,
                                                     const class GALGAS_string & inOperand1
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS__32_stringlist add_operation (const GALGAS__32_stringlist & inOperand,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_string constinArgument0,
                                               class GALGAS_string constinArgument1,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_string constinArgument0,
                                                      class GALGAS_string constinArgument1,
                                                      class GALGAS_uint constinArgument2,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_string & outArgument0,
                                                 class GALGAS_string & outArgument1,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_string & outArgument0,
                                                class GALGAS_string & outArgument1,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_string & outArgument0,
                                                      class GALGAS_string & outArgument1,
                                                      class GALGAS_uint constinArgument2,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValue_30_AtIndex (class GALGAS_string constinArgument0,
                                                             class GALGAS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValue_31_AtIndex (class GALGAS_string constinArgument0,
                                                             class GALGAS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_string & outArgument0,
                                              class GALGAS_string & outArgument1,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_string & outArgument0,
                                             class GALGAS_string & outArgument1,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_mValue_30_AtIndex (const class GALGAS_uint & constinOperand0,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_mValue_31_AtIndex (const class GALGAS_uint & constinOperand0,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS__32_stringlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS__32_stringlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS__32_stringlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator__32_stringlist ;
 
} ; // End of GALGAS__32_stringlist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator__32_stringlist : public cGenericAbstractEnumerator {
  public: cEnumerator__32_stringlist (const GALGAS__32_stringlist & inEnumeratedObject,
                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_string current_mValue_30_ (LOCATION_ARGS) const ;
  public: class GALGAS_string current_mValue_31_ (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS__32_stringlist_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_stringlist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @range struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_range : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_uint mProperty_start ;
  public: inline GALGAS_uint readProperty_start (void) const {
    return mProperty_start ;
  }

  public: GALGAS_uint mProperty_length ;
  public: inline GALGAS_uint readProperty_length (void) const {
    return mProperty_length ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_range (void) ;

//--------------------------------- Property setters
  public: inline void setter_setStart (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_start = inValue ;
  }

  public: inline void setter_setLength (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_length = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_range (void) ;

//--------------------------------- Native constructor
  public: GALGAS_range (const GALGAS_uint & in_start,
                        const GALGAS_uint & in_length) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_range extractObject (const GALGAS_object & inObject,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_range class_func_new (const class GALGAS_uint & inOperand0,
                                                    const class GALGAS_uint & inOperand1,
                                                    class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_range & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_range class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_range ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @functionlist_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_functionlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_function mProperty_mValue ;
  public: inline GALGAS_function readProperty_mValue (void) const {
    return mProperty_mValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_functionlist_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue (const GALGAS_function & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_functionlist_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_functionlist_2D_element (const GALGAS_function & in_mValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_functionlist_2D_element extractObject (const GALGAS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_functionlist_2D_element class_func_new (const class GALGAS_function & inOperand0,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_functionlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_functionlist_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_functionlist_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @luintlist_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_luintlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_luint mProperty_mValue ;
  public: inline GALGAS_luint readProperty_mValue (void) const {
    return mProperty_mValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_luintlist_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_luintlist_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_luintlist_2D_element (const GALGAS_luint & in_mValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_luintlist_2D_element extractObject (const GALGAS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_luintlist_2D_element class_func_new (const class GALGAS_luint & inOperand0,
                                                                   class Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_luintlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_luintlist_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_luintlist_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @objectlist_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_objectlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_object mProperty_mValue ;
  public: inline GALGAS_object readProperty_mValue (void) const {
    return mProperty_mValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_objectlist_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue (const GALGAS_object & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_objectlist_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_objectlist_2D_element (const GALGAS_object & in_mValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_objectlist_2D_element extractObject (const GALGAS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_objectlist_2D_element class_func_new (const class GALGAS_object & inOperand0,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_objectlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_objectlist_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectlist_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @stringlist_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_stringlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_string mProperty_mValue ;
  public: inline GALGAS_string readProperty_mValue (void) const {
    return mProperty_mValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_stringlist_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue (const GALGAS_string & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_stringlist_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_stringlist_2D_element (const GALGAS_string & in_mValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_stringlist_2D_element extractObject (const GALGAS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_stringlist_2D_element class_func_new (const class GALGAS_string & inOperand0,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_stringlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_stringlist_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringlist_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typelist_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typelist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_type mProperty_mValue ;
  public: inline GALGAS_type readProperty_mValue (void) const {
    return mProperty_mValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_typelist_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue (const GALGAS_type & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_typelist_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_typelist_2D_element (const GALGAS_type & in_mValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typelist_2D_element extractObject (const GALGAS_object & inObject,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typelist_2D_element class_func_new (const class GALGAS_type & inOperand0,
                                                                  class Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_typelist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typelist_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typelist_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @uintlist_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_uintlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_uint mProperty_mValue ;
  public: inline GALGAS_uint readProperty_mValue (void) const {
    return mProperty_mValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_uintlist_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_uintlist_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_uintlist_2D_element (const GALGAS_uint & in_mValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_uintlist_2D_element extractObject (const GALGAS_object & inObject,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_uintlist_2D_element class_func_new (const class GALGAS_uint & inOperand0,
                                                                  class Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_uintlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_uintlist_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uintlist_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @uint_36__34_list_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_uint_36__34_list_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_uint_36__34_ mProperty_mValue ;
  public: inline GALGAS_uint_36__34_ readProperty_mValue (void) const {
    return mProperty_mValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_uint_36__34_list_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue (const GALGAS_uint_36__34_ & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_uint_36__34_list_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_uint_36__34_list_2D_element (const GALGAS_uint_36__34_ & in_mValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_uint_36__34_list_2D_element extractObject (const GALGAS_object & inObject,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_uint_36__34_list_2D_element class_func_new (const class GALGAS_uint_36__34_ & inOperand0,
                                                                          class Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_uint_36__34_list_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_uint_36__34_list_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_36__34_list_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @bigintlist_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigintlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_bigint mProperty_mValue ;
  public: inline GALGAS_bigint readProperty_mValue (void) const {
    return mProperty_mValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_bigintlist_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue (const GALGAS_bigint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_bigintlist_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_bigintlist_2D_element (const GALGAS_bigint & in_mValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_bigintlist_2D_element extractObject (const GALGAS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_bigintlist_2D_element class_func_new (const class GALGAS_bigint & inOperand0,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_bigintlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_bigintlist_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_bigintlist_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @lbigintlist_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lbigintlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lbigint mProperty_mValue ;
  public: inline GALGAS_lbigint readProperty_mValue (void) const {
    return mProperty_mValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_lbigintlist_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue (const GALGAS_lbigint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_lbigintlist_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_lbigintlist_2D_element (const GALGAS_lbigint & in_mValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lbigintlist_2D_element extractObject (const GALGAS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_lbigintlist_2D_element class_func_new (const class GALGAS_lbigint & inOperand0,
                                                                     class Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_lbigintlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_lbigintlist_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lbigintlist_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @_32_stringlist_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS__32_stringlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_string mProperty_mValue_30_ ;
  public: inline GALGAS_string readProperty_mValue_30_ (void) const {
    return mProperty_mValue_30_ ;
  }

  public: GALGAS_string mProperty_mValue_31_ ;
  public: inline GALGAS_string readProperty_mValue_31_ (void) const {
    return mProperty_mValue_31_ ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS__32_stringlist_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue_30_ (const GALGAS_string & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue_30_ = inValue ;
  }

  public: inline void setter_setMValue_31_ (const GALGAS_string & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue_31_ = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS__32_stringlist_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS__32_stringlist_2D_element (const GALGAS_string & in_mValue_30_,
                                            const GALGAS_string & in_mValue_31_) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS__32_stringlist_2D_element extractObject (const GALGAS_object & inObject,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS__32_stringlist_2D_element class_func_new (const class GALGAS_string & inOperand0,
                                                                        const class GALGAS_string & inOperand1,
                                                                        class Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS__32_stringlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS__32_stringlist_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_stringlist_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @lstring struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstring : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_string mProperty_string ;
  public: inline GALGAS_string readProperty_string (void) const {
    return mProperty_string ;
  }

  public: GALGAS_location mProperty_location ;
  public: inline GALGAS_location readProperty_location (void) const {
    return mProperty_location ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_lstring (void) ;

//--------------------------------- Property setters
  public: inline void setter_setString (const GALGAS_string & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_string = inValue ;
  }

  public: inline void setter_setLocation (const GALGAS_location & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_location = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_lstring (void) ;

//--------------------------------- Native constructor
  public: GALGAS_lstring (const GALGAS_string & in_string,
                          const GALGAS_location & in_location) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lstring extractObject (const GALGAS_object & inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_lstring class_func_new (const class GALGAS_string & inOperand0,
                                                      const class GALGAS_location & inOperand1,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_lstring & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_lstring class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lstring ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @lsint struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lsint : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_sint mProperty_sint ;
  public: inline GALGAS_sint readProperty_sint (void) const {
    return mProperty_sint ;
  }

  public: GALGAS_location mProperty_location ;
  public: inline GALGAS_location readProperty_location (void) const {
    return mProperty_location ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_lsint (void) ;

//--------------------------------- Property setters
  public: inline void setter_setSint (const GALGAS_sint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_sint = inValue ;
  }

  public: inline void setter_setLocation (const GALGAS_location & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_location = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_lsint (void) ;

//--------------------------------- Native constructor
  public: GALGAS_lsint (const GALGAS_sint & in_sint,
                        const GALGAS_location & in_location) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lsint extractObject (const GALGAS_object & inObject,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_lsint class_func_new (const class GALGAS_sint & inOperand0,
                                                    const class GALGAS_location & inOperand1,
                                                    class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_lsint & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_lsint class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lsint ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @lstringlist_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstringlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_mValue ;
  public: inline GALGAS_lstring readProperty_mValue (void) const {
    return mProperty_mValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_lstringlist_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_lstringlist_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_lstringlist_2D_element (const GALGAS_lstring & in_mValue) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lstringlist_2D_element extractObject (const GALGAS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_lstringlist_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                     class Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_lstringlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_lstringlist_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lstringlist_2D_element ;

//--------------------------------------------------------------------------------------------------

#include "cCollectionElement.h"

//--------------------------------------------------------------------------------------------------

class cMapElement : public cCollectionElement {
//--- Attribut
  public: GALGAS_lstring mProperty_lkey ;

//--- Default constructor
  public: cMapElement (const GALGAS_lstring & inLKey
                        COMMA_LOCATION_ARGS) ;

//--- No copy
  private: cMapElement (const cMapElement &) ;
  private: cMapElement & operator = (const cMapElement &) ;
} ;

//--------------------------------------------------------------------------------------------------

#include "cSortedListElement.h"
#include "capSortedListElement.h"
#include "C_galgas_function_descriptor.h"
#include "cObjectArray.h"


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2
