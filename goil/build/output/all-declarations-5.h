#pragma once

//--------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-4.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @void_5F_sint_36__34__5F_class  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_void_5F_sint_36__34__5F_class : public GALGAS_sint_36__34__5F_class {
//--------------------------------- Default constructor
  public: GALGAS_void_5F_sint_36__34__5F_class (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_void_5F_sint_36__34__5F_class * ptr (void) const {
    return (const cPtr_void_5F_sint_36__34__5F_class *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_void_5F_sint_36__34__5F_class (const cPtr_void_5F_sint_36__34__5F_class * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_void_5F_sint_36__34__5F_class extractObject (const GALGAS_object & inObject,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_void_5F_sint_36__34__5F_class class_func_new (const class GALGAS_lstring & inOperand0,
                                                                            const class GALGAS_location & inOperand1,
                                                                            const class GALGAS_sint_36__34_ & inOperand2
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_void_5F_sint_36__34__5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_void_5F_sint_36__34__5F_class class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_sint_36__34__5F_class ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @void_sint64_class class
//
//--------------------------------------------------------------------------------------------------

class cPtr_void_5F_sint_36__34__5F_class : public cPtr_sint_36__34__5F_class {


//--- Properties

//--- Constructor
  public: cPtr_void_5F_sint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                              const GALGAS_location & in_location,
                                              const GALGAS_sint_36__34_ & in_value
                                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @void_5F_float_5F_class  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_void_5F_float_5F_class : public GALGAS_float_5F_class {
//--------------------------------- Default constructor
  public: GALGAS_void_5F_float_5F_class (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_void_5F_float_5F_class * ptr (void) const {
    return (const cPtr_void_5F_float_5F_class *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_void_5F_float_5F_class (const cPtr_void_5F_float_5F_class * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_void_5F_float_5F_class extractObject (const GALGAS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_void_5F_float_5F_class class_func_new (const class GALGAS_lstring & inOperand0,
                                                                     const class GALGAS_location & inOperand1,
                                                                     const class GALGAS_double & inOperand2
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_void_5F_float_5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_void_5F_float_5F_class class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_float_5F_class ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @void_float_class class
//
//--------------------------------------------------------------------------------------------------

class cPtr_void_5F_float_5F_class : public cPtr_float_5F_class {


//--- Properties

//--- Constructor
  public: cPtr_void_5F_float_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                       const GALGAS_location & in_location,
                                       const GALGAS_double & in_value
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @void_5F_string_5F_class  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_void_5F_string_5F_class : public GALGAS_string_5F_class {
//--------------------------------- Default constructor
  public: GALGAS_void_5F_string_5F_class (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_void_5F_string_5F_class * ptr (void) const {
    return (const cPtr_void_5F_string_5F_class *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_void_5F_string_5F_class (const cPtr_void_5F_string_5F_class * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_void_5F_string_5F_class extractObject (const GALGAS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_void_5F_string_5F_class class_func_new (const class GALGAS_lstring & inOperand0,
                                                                      const class GALGAS_location & inOperand1,
                                                                      const class GALGAS_string & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_void_5F_string_5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_void_5F_string_5F_class class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_string_5F_class ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @void_string_class class
//
//--------------------------------------------------------------------------------------------------

class cPtr_void_5F_string_5F_class : public cPtr_string_5F_class {


//--- Properties

//--- Constructor
  public: cPtr_void_5F_string_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                        const GALGAS_location & in_location,
                                        const GALGAS_string & in_value
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @void_5F_bool_5F_t  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_void_5F_bool_5F_t : public GALGAS_bool_5F_t {
//--------------------------------- Default constructor
  public: GALGAS_void_5F_bool_5F_t (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_void_5F_bool_5F_t * ptr (void) const {
    return (const cPtr_void_5F_bool_5F_t *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_void_5F_bool_5F_t (const cPtr_void_5F_bool_5F_t * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_void_5F_bool_5F_t extractObject (const GALGAS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_void_5F_bool_5F_t class_func_new (const class GALGAS_lstring & inOperand0,
                                                                const class GALGAS_location & inOperand1,
                                                                const class GALGAS_bool & inOperand2
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_void_5F_bool_5F_t & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_void_5F_bool_5F_t class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_bool_5F_t ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @void_bool_t class
//
//--------------------------------------------------------------------------------------------------

class cPtr_void_5F_bool_5F_t : public cPtr_bool_5F_t {


//--- Properties

//--- Constructor
  public: cPtr_void_5F_bool_5F_t (const GALGAS_lstring & in_oil_5F_desc,
                                  const GALGAS_location & in_location,
                                  const GALGAS_bool & in_value
                                  COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @oil_5F_obj  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_oil_5F_obj : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_oil_5F_obj (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_oil_5F_obj * ptr (void) const {
    return (const cPtr_oil_5F_obj *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_oil_5F_obj (const cPtr_oil_5F_obj * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_desc (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_oil_5F_obj extractObject (const GALGAS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_oil_5F_obj & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setDesc (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_oil_5F_obj class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_oil_5F_obj ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @oil_obj class
//
//--------------------------------------------------------------------------------------------------

class cPtr_oil_5F_obj : public acPtr_class {


//--- Properties
  public: GALGAS_lstring mProperty_desc ;

//--- Constructor
  public: cPtr_oil_5F_obj (const GALGAS_lstring & in_desc
                           COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_desc (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDesc (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@applicationDefinition applicationWithDefaults'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_applicationDefinition callExtensionGetter_applicationWithDefaults (const cPtr_applicationDefinition * inObject,
                                                                                const class GALGAS_implementation constin_imp,
                                                                                class Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@impType verifyApplication'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyApplication (class cPtr_impType * inObject,
                                            const class GALGAS_objectAttributes constin_attrs,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@impType verifyMultipleType'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyMultipleType (class cPtr_impType * inObject,
                                             const class GALGAS_object_5F_t constin_attr,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@impType verifyType'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyType (class cPtr_impType * inObject,
                                     const class GALGAS_object_5F_t constin_attr,
                                     Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@objectsMap verifyCrossReferences'
//
//--------------------------------------------------------------------------------------------------

void extensionMethod_verifyCrossReferences (const class GALGAS_objectsMap inObject,
                                            const class GALGAS_implementation constin_imp,
                                            class Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@objectKind verifyCrossReferences'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyCrossReferences (class cPtr_objectKind * inObject,
                                                const class GALGAS_objectsMap constin_allObjects,
                                                const class GALGAS_implementationObject constin_obj,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@applicationDefinition verifyCrossReferences'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyCrossReferences (class cPtr_applicationDefinition * inObject,
                                                const class GALGAS_implementation constin_imp,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'attributeRangeWithNumberList'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_attributeRange function_attributeRangeWithNumberList (const class GALGAS_numberList & constinArgument0,
                                                                   const class GALGAS_dataType & constinArgument1,
                                                                   class Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'buildRange'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_attributeRange function_buildRange (const class GALGAS_dataType & constinArgument0,
                                                 const class GALGAS_object_5F_t & constinArgument1,
                                                 const class GALGAS_object_5F_t & constinArgument2,
                                                 class Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'checkNewTypeWithinPreviousType'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool function_checkNewTypeWithinPreviousType (const class GALGAS_lstring & constinArgument0,
                                                           const class GALGAS_impType & constinArgument1,
                                                           const class GALGAS_impType & constinArgument2,
                                                           class Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//  GRAMMAR goil_implementation_level_include
//--------------------------------------------------------------------------------------------------

class cGrammar_goil_5F_implementation_5F_level_5F_include : public cParser_goil_5F_syntax,
                                                            public cParser_implementation_5F_parser {
//------------------------------------- 'OIL_version' non terminal
//--- 'parse' label
  public: virtual void nt_OIL_5F_version_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_OIL_5F_version_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_OIL_5F_version_ (GALGAS_lstring & outArgument0,
                                           GALGAS_lstring & outArgument1,
                                           Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'application_definition' non terminal
//--- 'parse' label
  public: virtual void nt_application_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_application_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_application_5F_definition_ (const GALGAS_implementation inArgument0,
                                                      GALGAS_applicationDefinition & ioArgument1,
                                                      GALGAS_string & ioArgument2,
                                                      const GALGAS_bool inArgument3,
                                                      Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean' non terminal
//--- 'parse' label
  public: virtual void nt_boolean_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_boolean_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_boolean_ (GALGAS_lbool & outArgument0,
                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean_options' non terminal
//--- 'parse' label
  public: virtual void nt_boolean_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_boolean_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_boolean_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'description' non terminal
//--- 'parse' label
  public: virtual void nt_description_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_description_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_description_ (GALGAS_lstring & outArgument0,
                                        Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_item' non terminal
//--- 'parse' label
  public: virtual void nt_enum_5F_item_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_enum_5F_item_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_enum_5F_item_ (GALGAS_enumValues & ioArgument0,
                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_options' non terminal
//--- 'parse' label
  public: virtual void nt_enum_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_enum_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_enum_5F_options_ (GALGAS_lstring & outArgument0,
                                            GALGAS_impType & outArgument1,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file' non terminal
//--- 'parse' label
  public: virtual void nt_file_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_ (GALGAS_implementation & ioArgument0,
                                 GALGAS_applicationDefinition & ioArgument1,
                                 GALGAS_string & ioArgument2,
                                 const GALGAS_bool inArgument3,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file_without_include' non terminal
//--- 'parse' label
  public: virtual void nt_file_5F_without_5F_include_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_5F_without_5F_include_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_5F_without_5F_include_ (GALGAS_implementation & ioArgument0,
                                                       GALGAS_applicationDefinition & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_attribute' non terminal
//--- 'parse' label
  public: virtual void nt_identifier_5F_or_5F_attribute_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_identifier_5F_or_5F_attribute_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & outArgument0,
                                                          Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_enum_value' non terminal
//--- 'parse' label
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & outArgument0,
                                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_definition' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_definition_ (GALGAS_implementation & ioArgument0,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_list' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_list_ (GALGAS_implementationObjectMap & ioArgument0,
                                                   Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_object_list' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_object_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_object_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_object_5F_list_ (GALGAS_implementation & ioArgument0,
                                                             Lexique_goil_5F_lexique * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_implementation & ioArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    GALGAS_implementation & ioArgument0
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (Compiler * inCompiler,
                                       const String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (Compiler * inCompiler,
                                                  const String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (Compiler * inCompiler,
                                                 const String & inSourceFilePath) ;

//------------------------------------- 'implementation_objects' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_objects_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_objects_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_objects_ (GALGAS_implementation & ioArgument0,
                                                      Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_type' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_type_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_type_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_type_ (GALGAS_lstring & outArgument0,
                                                   GALGAS_impType & outArgument1,
                                                   Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_cpu_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_cpu_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_cpu_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_cpu_5F_level_ (const GALGAS_implementation inArgument0,
                                                    GALGAS_objectsMap & ioArgument1,
                                                    GALGAS_string & ioArgument2,
                                                    const GALGAS_bool inArgument3,
                                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_file_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_file_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_file_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_file_5F_level_ (GALGAS_implementation & ioArgument0,
                                                     GALGAS_applicationDefinition & ioArgument1,
                                                     GALGAS_string & ioArgument2,
                                                     const GALGAS_bool inArgument3,
                                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_implementation_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_implementation_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_implementation_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_implementation_5F_level_ (GALGAS_implementation & ioArgument0,
                                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_object_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_object_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_object_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_type_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_type_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_type_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & ioArgument0,
                                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'int_or_float' non terminal
//--- 'parse' label
  public: virtual void nt_int_5F_or_5F_float_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_int_5F_or_5F_float_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & outArgument0,
                                               const GALGAS_dataType inArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'multiple' non terminal
//--- 'parse' label
  public: virtual void nt_multiple_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_multiple_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_multiple_ (GALGAS_bool & outArgument0,
                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'number_options' non terminal
//--- 'parse' label
  public: virtual void nt_number_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_number_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_number_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              const GALGAS_dataType inArgument2,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'object_definition_list' non terminal
//--- 'parse' label
  public: virtual void nt_object_5F_definition_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_object_5F_definition_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_object_5F_definition_5F_list_ (const GALGAS_implementation inArgument0,
                                                         GALGAS_objectsMap & ioArgument1,
                                                         GALGAS_string & ioArgument2,
                                                         const GALGAS_bool inArgument3,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'objref_option' non terminal
//--- 'parse' label
  public: virtual void nt_objref_5F_option_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_objref_5F_option_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_objref_5F_option_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             GALGAS_lstring inArgument2,
                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap inArgument0,
                                               GALGAS_objectAttributes & ioArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration_list' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range' non terminal
//--- 'parse' label
  public: virtual void nt_range_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_range_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_range_ (GALGAS_attributeRange & outArgument0,
                                  const GALGAS_dataType inArgument1,
                                  Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range_content' non terminal
//--- 'parse' label
  public: virtual void nt_range_5F_content_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_range_5F_content_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_range_5F_content_ (GALGAS_attributeRange & outArgument0,
                                             const GALGAS_dataType inArgument1,
                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'set_followup' non terminal
//--- 'parse' label
  public: virtual void nt_set_5F_followup_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_set_5F_followup_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_set_5F_followup_ (GALGAS_numberList & ioArgument0,
                                            const GALGAS_dataType inArgument1,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'sign' non terminal
//--- 'parse' label
  public: virtual void nt_sign_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_sign_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_sign_ (GALGAS_bool & outArgument0,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'start' non terminal
//--- 'parse' label
  public: virtual void nt_start_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_start_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_start_ (Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'string_options' non terminal
//--- 'parse' label
  public: virtual void nt_string_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_string_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_string_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'struct_options' non terminal
//--- 'parse' label
  public: virtual void nt_struct_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_struct_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_struct_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'type_options' non terminal
//--- 'parse' label
  public: virtual void nt_type_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_type_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_type_5F_options_ (GALGAS_lstring & outArgument0,
                                            GALGAS_impType & outArgument1,
                                            const GALGAS_dataType inArgument2,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'with_auto' non terminal
//--- 'parse' label
  public: virtual void nt_with_5F_auto_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_with_5F_auto_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_with_5F_auto_ (GALGAS_bool & outArgument0,
                                         Lexique_goil_5F_lexique * inCompiler) ;

  public: virtual int32_t select_goil_5F_syntax_0 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_1 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_2 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_3 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_4 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_5 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_6 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_7 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_8 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_9 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_10 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_11 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_12 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_13 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_14 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_15 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_16 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_17 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_18 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_0 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_1 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_2 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_3 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_4 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_5 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_6 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_7 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_8 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_9 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_10 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_11 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_12 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_13 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_14 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_15 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_16 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_17 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_18 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_19 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_20 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_21 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_22 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_23 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_24 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_25 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_26 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_27 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_28 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_29 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_30 (Lexique_goil_5F_lexique *) ;
} ;

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//  GRAMMAR goil_type_level_include
//--------------------------------------------------------------------------------------------------

class cGrammar_goil_5F_type_5F_level_5F_include : public cParser_goil_5F_syntax,
                                                  public cParser_implementation_5F_parser {
//------------------------------------- 'OIL_version' non terminal
//--- 'parse' label
  public: virtual void nt_OIL_5F_version_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_OIL_5F_version_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_OIL_5F_version_ (GALGAS_lstring & outArgument0,
                                           GALGAS_lstring & outArgument1,
                                           Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'application_definition' non terminal
//--- 'parse' label
  public: virtual void nt_application_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_application_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_application_5F_definition_ (const GALGAS_implementation inArgument0,
                                                      GALGAS_applicationDefinition & ioArgument1,
                                                      GALGAS_string & ioArgument2,
                                                      const GALGAS_bool inArgument3,
                                                      Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean' non terminal
//--- 'parse' label
  public: virtual void nt_boolean_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_boolean_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_boolean_ (GALGAS_lbool & outArgument0,
                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean_options' non terminal
//--- 'parse' label
  public: virtual void nt_boolean_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_boolean_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_boolean_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'description' non terminal
//--- 'parse' label
  public: virtual void nt_description_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_description_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_description_ (GALGAS_lstring & outArgument0,
                                        Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_item' non terminal
//--- 'parse' label
  public: virtual void nt_enum_5F_item_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_enum_5F_item_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_enum_5F_item_ (GALGAS_enumValues & ioArgument0,
                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_options' non terminal
//--- 'parse' label
  public: virtual void nt_enum_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_enum_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_enum_5F_options_ (GALGAS_lstring & outArgument0,
                                            GALGAS_impType & outArgument1,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file' non terminal
//--- 'parse' label
  public: virtual void nt_file_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_ (GALGAS_implementation & ioArgument0,
                                 GALGAS_applicationDefinition & ioArgument1,
                                 GALGAS_string & ioArgument2,
                                 const GALGAS_bool inArgument3,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file_without_include' non terminal
//--- 'parse' label
  public: virtual void nt_file_5F_without_5F_include_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_5F_without_5F_include_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_5F_without_5F_include_ (GALGAS_implementation & ioArgument0,
                                                       GALGAS_applicationDefinition & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_attribute' non terminal
//--- 'parse' label
  public: virtual void nt_identifier_5F_or_5F_attribute_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_identifier_5F_or_5F_attribute_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & outArgument0,
                                                          Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_enum_value' non terminal
//--- 'parse' label
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & outArgument0,
                                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_definition' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_definition_ (GALGAS_implementation & ioArgument0,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_list' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_list_ (GALGAS_implementationObjectMap & ioArgument0,
                                                   Lexique_goil_5F_lexique * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_implementationObjectMap & ioArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    GALGAS_implementationObjectMap & ioArgument0
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (Compiler * inCompiler,
                                       const String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (Compiler * inCompiler,
                                                  const String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (Compiler * inCompiler,
                                                 const String & inSourceFilePath) ;

//------------------------------------- 'implementation_object_list' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_object_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_object_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_object_5F_list_ (GALGAS_implementation & ioArgument0,
                                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_objects' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_objects_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_objects_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_objects_ (GALGAS_implementation & ioArgument0,
                                                      Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_type' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_type_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_type_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_type_ (GALGAS_lstring & outArgument0,
                                                   GALGAS_impType & outArgument1,
                                                   Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_cpu_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_cpu_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_cpu_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_cpu_5F_level_ (const GALGAS_implementation inArgument0,
                                                    GALGAS_objectsMap & ioArgument1,
                                                    GALGAS_string & ioArgument2,
                                                    const GALGAS_bool inArgument3,
                                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_file_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_file_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_file_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_file_5F_level_ (GALGAS_implementation & ioArgument0,
                                                     GALGAS_applicationDefinition & ioArgument1,
                                                     GALGAS_string & ioArgument2,
                                                     const GALGAS_bool inArgument3,
                                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_implementation_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_implementation_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_implementation_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_implementation_5F_level_ (GALGAS_implementation & ioArgument0,
                                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_object_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_object_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_object_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_type_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_type_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_type_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & ioArgument0,
                                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'int_or_float' non terminal
//--- 'parse' label
  public: virtual void nt_int_5F_or_5F_float_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_int_5F_or_5F_float_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & outArgument0,
                                               const GALGAS_dataType inArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'multiple' non terminal
//--- 'parse' label
  public: virtual void nt_multiple_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_multiple_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_multiple_ (GALGAS_bool & outArgument0,
                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'number_options' non terminal
//--- 'parse' label
  public: virtual void nt_number_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_number_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_number_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              const GALGAS_dataType inArgument2,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'object_definition_list' non terminal
//--- 'parse' label
  public: virtual void nt_object_5F_definition_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_object_5F_definition_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_object_5F_definition_5F_list_ (const GALGAS_implementation inArgument0,
                                                         GALGAS_objectsMap & ioArgument1,
                                                         GALGAS_string & ioArgument2,
                                                         const GALGAS_bool inArgument3,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'objref_option' non terminal
//--- 'parse' label
  public: virtual void nt_objref_5F_option_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_objref_5F_option_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_objref_5F_option_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             GALGAS_lstring inArgument2,
                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap inArgument0,
                                               GALGAS_objectAttributes & ioArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration_list' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range' non terminal
//--- 'parse' label
  public: virtual void nt_range_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_range_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_range_ (GALGAS_attributeRange & outArgument0,
                                  const GALGAS_dataType inArgument1,
                                  Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range_content' non terminal
//--- 'parse' label
  public: virtual void nt_range_5F_content_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_range_5F_content_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_range_5F_content_ (GALGAS_attributeRange & outArgument0,
                                             const GALGAS_dataType inArgument1,
                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'set_followup' non terminal
//--- 'parse' label
  public: virtual void nt_set_5F_followup_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_set_5F_followup_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_set_5F_followup_ (GALGAS_numberList & ioArgument0,
                                            const GALGAS_dataType inArgument1,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'sign' non terminal
//--- 'parse' label
  public: virtual void nt_sign_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_sign_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_sign_ (GALGAS_bool & outArgument0,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'start' non terminal
//--- 'parse' label
  public: virtual void nt_start_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_start_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_start_ (Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'string_options' non terminal
//--- 'parse' label
  public: virtual void nt_string_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_string_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_string_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'struct_options' non terminal
//--- 'parse' label
  public: virtual void nt_struct_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_struct_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_struct_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'type_options' non terminal
//--- 'parse' label
  public: virtual void nt_type_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_type_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_type_5F_options_ (GALGAS_lstring & outArgument0,
                                            GALGAS_impType & outArgument1,
                                            const GALGAS_dataType inArgument2,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'with_auto' non terminal
//--- 'parse' label
  public: virtual void nt_with_5F_auto_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_with_5F_auto_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_with_5F_auto_ (GALGAS_bool & outArgument0,
                                         Lexique_goil_5F_lexique * inCompiler) ;

  public: virtual int32_t select_goil_5F_syntax_0 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_1 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_2 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_3 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_4 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_5 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_6 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_7 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_8 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_9 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_10 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_11 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_12 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_13 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_14 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_15 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_16 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_17 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_18 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_0 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_1 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_2 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_3 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_4 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_5 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_6 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_7 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_8 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_9 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_10 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_11 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_12 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_13 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_14 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_15 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_16 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_17 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_18 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_19 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_20 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_21 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_22 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_23 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_24 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_25 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_26 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_27 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_28 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_29 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_30 (Lexique_goil_5F_lexique *) ;
} ;

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//
//Routine 'verifyEnum?'
//
//--------------------------------------------------------------------------------------------------

void routine_verifyEnum_3F_ (const class GALGAS_impType constinArgument0,
                             class Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//  GRAMMAR goil_file_level_include_without_include
//--------------------------------------------------------------------------------------------------

class cGrammar_goil_5F_file_5F_level_5F_include_5F_without_5F_include : public cParser_goil_5F_syntax,
                                                                        public cParser_implementation_5F_parser {
//------------------------------------- 'OIL_version' non terminal
//--- 'parse' label
  public: virtual void nt_OIL_5F_version_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_OIL_5F_version_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_OIL_5F_version_ (GALGAS_lstring & outArgument0,
                                           GALGAS_lstring & outArgument1,
                                           Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'application_definition' non terminal
//--- 'parse' label
  public: virtual void nt_application_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_application_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_application_5F_definition_ (const GALGAS_implementation inArgument0,
                                                      GALGAS_applicationDefinition & ioArgument1,
                                                      GALGAS_string & ioArgument2,
                                                      const GALGAS_bool inArgument3,
                                                      Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean' non terminal
//--- 'parse' label
  public: virtual void nt_boolean_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_boolean_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_boolean_ (GALGAS_lbool & outArgument0,
                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean_options' non terminal
//--- 'parse' label
  public: virtual void nt_boolean_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_boolean_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_boolean_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'description' non terminal
//--- 'parse' label
  public: virtual void nt_description_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_description_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_description_ (GALGAS_lstring & outArgument0,
                                        Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_item' non terminal
//--- 'parse' label
  public: virtual void nt_enum_5F_item_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_enum_5F_item_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_enum_5F_item_ (GALGAS_enumValues & ioArgument0,
                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_options' non terminal
//--- 'parse' label
  public: virtual void nt_enum_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_enum_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_enum_5F_options_ (GALGAS_lstring & outArgument0,
                                            GALGAS_impType & outArgument1,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file' non terminal
//--- 'parse' label
  public: virtual void nt_file_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_ (GALGAS_implementation & ioArgument0,
                                 GALGAS_applicationDefinition & ioArgument1,
                                 GALGAS_string & ioArgument2,
                                 const GALGAS_bool inArgument3,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file_without_include' non terminal
//--- 'parse' label
  public: virtual void nt_file_5F_without_5F_include_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_5F_without_5F_include_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_5F_without_5F_include_ (GALGAS_implementation & ioArgument0,
                                                       GALGAS_applicationDefinition & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_implementation & ioArgument0,
                                                  GALGAS_applicationDefinition & ioArgument1
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    GALGAS_implementation & ioArgument0,
                                                    GALGAS_applicationDefinition & ioArgument1
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (Compiler * inCompiler,
                                       const String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (Compiler * inCompiler,
                                                  const String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (Compiler * inCompiler,
                                                 const String & inSourceFilePath) ;

//------------------------------------- 'identifier_or_attribute' non terminal
//--- 'parse' label
  public: virtual void nt_identifier_5F_or_5F_attribute_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_identifier_5F_or_5F_attribute_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & outArgument0,
                                                          Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_enum_value' non terminal
//--- 'parse' label
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & outArgument0,
                                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_definition' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_definition_ (GALGAS_implementation & ioArgument0,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_list' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_list_ (GALGAS_implementationObjectMap & ioArgument0,
                                                   Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_object_list' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_object_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_object_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_object_5F_list_ (GALGAS_implementation & ioArgument0,
                                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_objects' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_objects_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_objects_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_objects_ (GALGAS_implementation & ioArgument0,
                                                      Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_type' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_type_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_type_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_type_ (GALGAS_lstring & outArgument0,
                                                   GALGAS_impType & outArgument1,
                                                   Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_cpu_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_cpu_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_cpu_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_cpu_5F_level_ (const GALGAS_implementation inArgument0,
                                                    GALGAS_objectsMap & ioArgument1,
                                                    GALGAS_string & ioArgument2,
                                                    const GALGAS_bool inArgument3,
                                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_file_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_file_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_file_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_file_5F_level_ (GALGAS_implementation & ioArgument0,
                                                     GALGAS_applicationDefinition & ioArgument1,
                                                     GALGAS_string & ioArgument2,
                                                     const GALGAS_bool inArgument3,
                                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_implementation_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_implementation_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_implementation_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_implementation_5F_level_ (GALGAS_implementation & ioArgument0,
                                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_object_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_object_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_object_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_type_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_type_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_type_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & ioArgument0,
                                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'int_or_float' non terminal
//--- 'parse' label
  public: virtual void nt_int_5F_or_5F_float_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_int_5F_or_5F_float_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & outArgument0,
                                               const GALGAS_dataType inArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'multiple' non terminal
//--- 'parse' label
  public: virtual void nt_multiple_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_multiple_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_multiple_ (GALGAS_bool & outArgument0,
                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'number_options' non terminal
//--- 'parse' label
  public: virtual void nt_number_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_number_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_number_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              const GALGAS_dataType inArgument2,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'object_definition_list' non terminal
//--- 'parse' label
  public: virtual void nt_object_5F_definition_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_object_5F_definition_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_object_5F_definition_5F_list_ (const GALGAS_implementation inArgument0,
                                                         GALGAS_objectsMap & ioArgument1,
                                                         GALGAS_string & ioArgument2,
                                                         const GALGAS_bool inArgument3,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'objref_option' non terminal
//--- 'parse' label
  public: virtual void nt_objref_5F_option_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_objref_5F_option_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_objref_5F_option_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             GALGAS_lstring inArgument2,
                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap inArgument0,
                                               GALGAS_objectAttributes & ioArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration_list' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range' non terminal
//--- 'parse' label
  public: virtual void nt_range_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_range_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_range_ (GALGAS_attributeRange & outArgument0,
                                  const GALGAS_dataType inArgument1,
                                  Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range_content' non terminal
//--- 'parse' label
  public: virtual void nt_range_5F_content_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_range_5F_content_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_range_5F_content_ (GALGAS_attributeRange & outArgument0,
                                             const GALGAS_dataType inArgument1,
                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'set_followup' non terminal
//--- 'parse' label
  public: virtual void nt_set_5F_followup_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_set_5F_followup_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_set_5F_followup_ (GALGAS_numberList & ioArgument0,
                                            const GALGAS_dataType inArgument1,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'sign' non terminal
//--- 'parse' label
  public: virtual void nt_sign_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_sign_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_sign_ (GALGAS_bool & outArgument0,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'start' non terminal
//--- 'parse' label
  public: virtual void nt_start_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_start_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_start_ (Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'string_options' non terminal
//--- 'parse' label
  public: virtual void nt_string_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_string_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_string_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'struct_options' non terminal
//--- 'parse' label
  public: virtual void nt_struct_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_struct_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_struct_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'type_options' non terminal
//--- 'parse' label
  public: virtual void nt_type_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_type_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_type_5F_options_ (GALGAS_lstring & outArgument0,
                                            GALGAS_impType & outArgument1,
                                            const GALGAS_dataType inArgument2,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'with_auto' non terminal
//--- 'parse' label
  public: virtual void nt_with_5F_auto_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_with_5F_auto_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_with_5F_auto_ (GALGAS_bool & outArgument0,
                                         Lexique_goil_5F_lexique * inCompiler) ;

  public: virtual int32_t select_goil_5F_syntax_0 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_1 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_2 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_3 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_4 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_5 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_6 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_7 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_8 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_9 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_10 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_11 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_12 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_13 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_14 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_15 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_16 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_17 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_18 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_0 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_1 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_2 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_3 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_4 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_5 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_6 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_7 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_8 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_9 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_10 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_11 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_12 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_13 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_14 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_15 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_16 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_17 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_18 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_19 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_20 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_21 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_22 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_23 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_24 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_25 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_26 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_27 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_28 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_29 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_30 (Lexique_goil_5F_lexique *) ;
} ;

//--------------------------------------------------------------------------------------------------
