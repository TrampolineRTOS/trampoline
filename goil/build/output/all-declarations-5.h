#ifndef all_2D_declarations_2D__35__ENTITIES_DEFINED
#define all_2D_declarations_2D__35__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "all-predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-4.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @void_5F_uint_36__34__5F_class class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_void_5F_uint_36__34__5F_class : public GALGAS_uint_36__34__5F_class {
//--- Constructor
  public : GALGAS_void_5F_uint_36__34__5F_class (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_void_5F_uint_36__34__5F_class constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_void_5F_uint_36__34__5F_class * ptr (void) const { return (const cPtr_void_5F_uint_36__34__5F_class *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_void_5F_uint_36__34__5F_class (const cPtr_void_5F_uint_36__34__5F_class * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_void_5F_uint_36__34__5F_class extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_void_5F_uint_36__34__5F_class constructor_new (const class GALGAS_lstring & inOperand0,
                                                                              const class GALGAS_location & inOperand1,
                                                                              const class GALGAS_uint_36__34_ & inOperand2
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_void_5F_uint_36__34__5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_void_5F_uint_36__34__5F_class class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @void_uint64_class class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_void_5F_uint_36__34__5F_class : public cPtr_uint_36__34__5F_class {
//--- Attributes

//--- Constructor
  public : cPtr_void_5F_uint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                               const GALGAS_location & in_location,
                                               const GALGAS_uint_36__34_ & in_value
                                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @void_5F_sint_36__34__5F_class class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_void_5F_sint_36__34__5F_class : public GALGAS_sint_36__34__5F_class {
//--- Constructor
  public : GALGAS_void_5F_sint_36__34__5F_class (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_void_5F_sint_36__34__5F_class constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_void_5F_sint_36__34__5F_class * ptr (void) const { return (const cPtr_void_5F_sint_36__34__5F_class *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_void_5F_sint_36__34__5F_class (const cPtr_void_5F_sint_36__34__5F_class * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_void_5F_sint_36__34__5F_class extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_void_5F_sint_36__34__5F_class constructor_new (const class GALGAS_lstring & inOperand0,
                                                                              const class GALGAS_location & inOperand1,
                                                                              const class GALGAS_sint_36__34_ & inOperand2
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_void_5F_sint_36__34__5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_void_5F_sint_36__34__5F_class class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_sint_36__34__5F_class ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @void_sint64_class class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_void_5F_sint_36__34__5F_class : public cPtr_sint_36__34__5F_class {
//--- Attributes

//--- Constructor
  public : cPtr_void_5F_sint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                               const GALGAS_location & in_location,
                                               const GALGAS_sint_36__34_ & in_value
                                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @void_5F_float_5F_class class                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_void_5F_float_5F_class : public GALGAS_float_5F_class {
//--- Constructor
  public : GALGAS_void_5F_float_5F_class (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_void_5F_float_5F_class constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_void_5F_float_5F_class * ptr (void) const { return (const cPtr_void_5F_float_5F_class *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_void_5F_float_5F_class (const cPtr_void_5F_float_5F_class * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_void_5F_float_5F_class extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_void_5F_float_5F_class constructor_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_location & inOperand1,
                                                                       const class GALGAS_double & inOperand2
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_void_5F_float_5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_void_5F_float_5F_class class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_float_5F_class ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @void_float_class class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_void_5F_float_5F_class : public cPtr_float_5F_class {
//--- Attributes

//--- Constructor
  public : cPtr_void_5F_float_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                        const GALGAS_location & in_location,
                                        const GALGAS_double & in_value
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @void_5F_string_5F_class class                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_void_5F_string_5F_class : public GALGAS_string_5F_class {
//--- Constructor
  public : GALGAS_void_5F_string_5F_class (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_void_5F_string_5F_class constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_void_5F_string_5F_class * ptr (void) const { return (const cPtr_void_5F_string_5F_class *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_void_5F_string_5F_class (const cPtr_void_5F_string_5F_class * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_void_5F_string_5F_class extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_void_5F_string_5F_class constructor_new (const class GALGAS_lstring & inOperand0,
                                                                        const class GALGAS_location & inOperand1,
                                                                        const class GALGAS_string & inOperand2
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_void_5F_string_5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_void_5F_string_5F_class class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_string_5F_class ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @void_string_class class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_void_5F_string_5F_class : public cPtr_string_5F_class {
//--- Attributes

//--- Constructor
  public : cPtr_void_5F_string_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                         const GALGAS_location & in_location,
                                         const GALGAS_string & in_value
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @void_5F_bool_5F_t class                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_void_5F_bool_5F_t : public GALGAS_bool_5F_t {
//--- Constructor
  public : GALGAS_void_5F_bool_5F_t (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_void_5F_bool_5F_t constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_void_5F_bool_5F_t * ptr (void) const { return (const cPtr_void_5F_bool_5F_t *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_void_5F_bool_5F_t (const cPtr_void_5F_bool_5F_t * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_void_5F_bool_5F_t extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_void_5F_bool_5F_t constructor_new (const class GALGAS_lstring & inOperand0,
                                                                  const class GALGAS_location & inOperand1,
                                                                  const class GALGAS_bool & inOperand2
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_void_5F_bool_5F_t & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_void_5F_bool_5F_t class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_bool_5F_t ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Pointer class for @void_bool_t class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_void_5F_bool_5F_t : public cPtr_bool_5F_t {
//--- Attributes

//--- Constructor
  public : cPtr_void_5F_bool_5F_t (const GALGAS_lstring & in_oil_5F_desc,
                                   const GALGAS_location & in_location,
                                   const GALGAS_bool & in_value
                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @oil_5F_obj class                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_oil_5F_obj : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_oil_5F_obj (void) ;

//---
  public : inline const class cPtr_oil_5F_obj * ptr (void) const { return (const cPtr_oil_5F_obj *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_oil_5F_obj (const cPtr_oil_5F_obj * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_oil_5F_obj extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_oil_5F_obj & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_desc (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_oil_5F_obj class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_oil_5F_obj ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Pointer class for @oil_obj class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_oil_5F_obj : public acPtr_class {
//--- Attributes
  public : GALGAS_lstring mAttribute_desc ;

//--- Constructor
  public : cPtr_oil_5F_obj (const GALGAS_lstring & in_desc
                            COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_desc (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Extension getter '@applicationDefinition applicationWithDefaults'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_applicationDefinition (*enterExtensionGetter_applicationDefinition_applicationWithDefaults) (const class cPtr_applicationDefinition * inObject,
                                                                                                                  const class GALGAS_implementation constinArgument0,
                                                                                                                  C_Compiler * inCompiler
                                                                                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_applicationWithDefaults (const int32_t inClassIndex,
                                                   enterExtensionGetter_applicationDefinition_applicationWithDefaults inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_applicationDefinition callExtensionGetter_applicationWithDefaults (const cPtr_applicationDefinition * inObject,
                                                                                const GALGAS_implementation constin_imp,
                                                                                class C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension method '@impType verifyApplication'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_impType_verifyApplication) (const class cPtr_impType * inObject,
                                                                    const class GALGAS_objectAttributes constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_verifyApplication (const int32_t inClassIndex,
                                             extensionMethodSignature_impType_verifyApplication inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_verifyApplication (const class cPtr_impType * inObject,
                                            const GALGAS_objectAttributes constin_attrs,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension method '@impType verifyMultipleType'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_impType_verifyMultipleType) (const class cPtr_impType * inObject,
                                                                     const class GALGAS_object_5F_t constinArgument0,
                                                                     class C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_verifyMultipleType (const int32_t inClassIndex,
                                              extensionMethodSignature_impType_verifyMultipleType inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_verifyMultipleType (const class cPtr_impType * inObject,
                                             const GALGAS_object_5F_t constin_attr,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension method '@impType verifyType'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_impType_verifyType) (const class cPtr_impType * inObject,
                                                             const class GALGAS_object_5F_t constinArgument0,
                                                             class C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_verifyType (const int32_t inClassIndex,
                                      extensionMethodSignature_impType_verifyType inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_verifyType (const class cPtr_impType * inObject,
                                     const GALGAS_object_5F_t constin_attr,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension method '@objectsMap verifyCrossReferences'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_verifyCrossReferences (const class GALGAS_objectsMap inObject,
                                            const class GALGAS_implementation constin_imp,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension method '@objectKind verifyCrossReferences'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_objectKind_verifyCrossReferences) (const class cPtr_objectKind * inObject,
                                                                           const class GALGAS_objectsMap constinArgument0,
                                                                           const class GALGAS_implementationObject constinArgument1,
                                                                           class C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                 extensionMethodSignature_objectKind_verifyCrossReferences inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_verifyCrossReferences (const class cPtr_objectKind * inObject,
                                                const GALGAS_objectsMap constin_allObjects,
                                                const GALGAS_implementationObject constin_obj,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Extension method '@applicationDefinition verifyCrossReferences'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_applicationDefinition_verifyCrossReferences) (const class cPtr_applicationDefinition * inObject,
                                                                                      const class GALGAS_implementation constinArgument0,
                                                                                      class C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                 extensionMethodSignature_applicationDefinition_verifyCrossReferences inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_verifyCrossReferences (const class cPtr_applicationDefinition * inObject,
                                                const GALGAS_implementation constin_imp,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Function 'attributeRangeWithNumberList'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_attributeRange function_attributeRangeWithNumberList (const class GALGAS_numberList & constinArgument0,
                                                                   const class GALGAS_dataType & constinArgument1,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'buildRange'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_attributeRange function_buildRange (const class GALGAS_dataType & constinArgument0,
                                                 const class GALGAS_object_5F_t & constinArgument1,
                                                 const class GALGAS_object_5F_t & constinArgument2,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Function 'checkNewTypeWithinPreviousType'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool function_checkNewTypeWithinPreviousType (const class GALGAS_lstring & constinArgument0,
                                                           const class GALGAS_impType & constinArgument1,
                                                           const class GALGAS_impType & constinArgument2,
                                                           class C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//  GRAMMAR goil_implementation_level_include
//---------------------------------------------------------------------------------------------------------------------*

class cGrammar_goil_5F_implementation_5F_level_5F_include : public cParser_goil_5F_syntax,
                                                            public cParser_implementation_5F_parser {
//------------------------------------- 'OIL_version' non terminal
//--- 'parse' label
  public : virtual void nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_OIL_5F_version_ (GALGAS_lstring & outArgument0,
                                            GALGAS_lstring & outArgument1,
                                            C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'application_definition' non terminal
//--- 'parse' label
  public : virtual void nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_application_5F_definition_ (const GALGAS_implementation inArgument0,
                                                       GALGAS_applicationDefinition & ioArgument1,
                                                       GALGAS_string & ioArgument2,
                                                       const GALGAS_bool inArgument3,
                                                       C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean' non terminal
//--- 'parse' label
  public : virtual void nt_boolean_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_boolean_ (GALGAS_lbool & outArgument0,
                                     C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean_options' non terminal
//--- 'parse' label
  public : virtual void nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_boolean_5F_options_ (GALGAS_lstring & outArgument0,
                                                GALGAS_impType & outArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'description' non terminal
//--- 'parse' label
  public : virtual void nt_description_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_description_ (GALGAS_lstring & outArgument0,
                                         C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_item' non terminal
//--- 'parse' label
  public : virtual void nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_enum_5F_item_ (GALGAS_enumValues & ioArgument0,
                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_options' non terminal
//--- 'parse' label
  public : virtual void nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_enum_5F_options_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file' non terminal
//--- 'parse' label
  public : virtual void nt_file_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_file_ (GALGAS_implementation & ioArgument0,
                                  GALGAS_applicationDefinition & ioArgument1,
                                  GALGAS_string & ioArgument2,
                                  const GALGAS_bool inArgument3,
                                  C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_attribute' non terminal
//--- 'parse' label
  public : virtual void nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & outArgument0,
                                                           C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_enum_value' non terminal
//--- 'parse' label
  public : virtual void nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & outArgument0,
                                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_definition' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_definition_ (GALGAS_implementation & ioArgument0,
                                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_list' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_list_ (GALGAS_implementationObjectMap & ioArgument0,
                                                    C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_object_list' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_object_5F_list_ (GALGAS_implementation & ioArgument0,
                                                              C_Lexique_goil_5F_lexique * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName,
                                                   GALGAS_implementation & ioArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString,
                                                     GALGAS_string inNameString,
                                                     GALGAS_implementation & ioArgument0
                                                     COMMA_LOCATION_ARGS) ;

//--- Indexing
  public : static void performIndexing (C_Compiler * inCompiler,
                                        const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public : static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                   const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public : static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//------------------------------------- 'implementation_objects' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_objects_ (GALGAS_implementation & ioArgument0,
                                                       C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_type' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_type_ (GALGAS_lstring & outArgument0,
                                                    GALGAS_impType & outArgument1,
                                                    C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_cpu_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_cpu_5F_level_ (const GALGAS_implementation inArgument0,
                                                     GALGAS_objectsMap & ioArgument1,
                                                     GALGAS_string & ioArgument2,
                                                     const GALGAS_bool inArgument3,
                                                     C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_file_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_file_5F_level_ (GALGAS_implementation & ioArgument0,
                                                      GALGAS_applicationDefinition & ioArgument1,
                                                      GALGAS_string & ioArgument2,
                                                      const GALGAS_bool inArgument3,
                                                      C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_implementation_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_implementation_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_implementation_5F_level_ (GALGAS_implementation & ioArgument0,
                                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_object_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap inArgument0,
                                                        GALGAS_objectAttributes & ioArgument1,
                                                        C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_type_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_type_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & ioArgument0,
                                                      C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'int_or_float' non terminal
//--- 'parse' label
  public : virtual void nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & outArgument0,
                                                const GALGAS_dataType inArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'multiple' non terminal
//--- 'parse' label
  public : virtual void nt_multiple_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_multiple_ (GALGAS_bool & outArgument0,
                                      C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'number_options' non terminal
//--- 'parse' label
  public : virtual void nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_number_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               const GALGAS_dataType inArgument2,
                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'object_definition_list' non terminal
//--- 'parse' label
  public : virtual void nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_object_5F_definition_5F_list_ (const GALGAS_implementation inArgument0,
                                                          GALGAS_objectsMap & ioArgument1,
                                                          GALGAS_string & ioArgument2,
                                                          const GALGAS_bool inArgument3,
                                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'objref_option' non terminal
//--- 'parse' label
  public : virtual void nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_objref_5F_option_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              GALGAS_lstring inArgument2,
                                              C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration' non terminal
//--- 'parse' label
  public : virtual void nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap inArgument0,
                                                GALGAS_objectAttributes & ioArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration_list' non terminal
//--- 'parse' label
  public : virtual void nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap inArgument0,
                                                        GALGAS_objectAttributes & ioArgument1,
                                                        C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range' non terminal
//--- 'parse' label
  public : virtual void nt_range_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_range_ (GALGAS_attributeRange & outArgument0,
                                   const GALGAS_dataType inArgument1,
                                   C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range_content' non terminal
//--- 'parse' label
  public : virtual void nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_range_5F_content_ (GALGAS_attributeRange & outArgument0,
                                              const GALGAS_dataType inArgument1,
                                              C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'set_followup' non terminal
//--- 'parse' label
  public : virtual void nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_set_5F_followup_ (GALGAS_numberList & ioArgument0,
                                             const GALGAS_dataType inArgument1,
                                             C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'sign' non terminal
//--- 'parse' label
  public : virtual void nt_sign_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_sign_ (GALGAS_bool & outArgument0,
                                  C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'start' non terminal
//--- 'parse' label
  public : virtual void nt_start_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_start_ (C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'string_options' non terminal
//--- 'parse' label
  public : virtual void nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_string_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'struct_options' non terminal
//--- 'parse' label
  public : virtual void nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_struct_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'type_options' non terminal
//--- 'parse' label
  public : virtual void nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_type_5F_options_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             const GALGAS_dataType inArgument2,
                                             C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'with_auto' non terminal
//--- 'parse' label
  public : virtual void nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_with_5F_auto_ (GALGAS_bool & outArgument0,
                                          C_Lexique_goil_5F_lexique * inCompiler) ;

  public : virtual int32_t select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_27 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_28 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_29 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_30 (C_Lexique_goil_5F_lexique *) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//---------------------------------------------------------------------------------------------------------------------*
//  GRAMMAR goil_type_level_include
//---------------------------------------------------------------------------------------------------------------------*

class cGrammar_goil_5F_type_5F_level_5F_include : public cParser_goil_5F_syntax,
                                                  public cParser_implementation_5F_parser {
//------------------------------------- 'OIL_version' non terminal
//--- 'parse' label
  public : virtual void nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_OIL_5F_version_ (GALGAS_lstring & outArgument0,
                                            GALGAS_lstring & outArgument1,
                                            C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'application_definition' non terminal
//--- 'parse' label
  public : virtual void nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_application_5F_definition_ (const GALGAS_implementation inArgument0,
                                                       GALGAS_applicationDefinition & ioArgument1,
                                                       GALGAS_string & ioArgument2,
                                                       const GALGAS_bool inArgument3,
                                                       C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean' non terminal
//--- 'parse' label
  public : virtual void nt_boolean_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_boolean_ (GALGAS_lbool & outArgument0,
                                     C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean_options' non terminal
//--- 'parse' label
  public : virtual void nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_boolean_5F_options_ (GALGAS_lstring & outArgument0,
                                                GALGAS_impType & outArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'description' non terminal
//--- 'parse' label
  public : virtual void nt_description_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_description_ (GALGAS_lstring & outArgument0,
                                         C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_item' non terminal
//--- 'parse' label
  public : virtual void nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_enum_5F_item_ (GALGAS_enumValues & ioArgument0,
                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_options' non terminal
//--- 'parse' label
  public : virtual void nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_enum_5F_options_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file' non terminal
//--- 'parse' label
  public : virtual void nt_file_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_file_ (GALGAS_implementation & ioArgument0,
                                  GALGAS_applicationDefinition & ioArgument1,
                                  GALGAS_string & ioArgument2,
                                  const GALGAS_bool inArgument3,
                                  C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_attribute' non terminal
//--- 'parse' label
  public : virtual void nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & outArgument0,
                                                           C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_enum_value' non terminal
//--- 'parse' label
  public : virtual void nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & outArgument0,
                                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_definition' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_definition_ (GALGAS_implementation & ioArgument0,
                                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_list' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_list_ (GALGAS_implementationObjectMap & ioArgument0,
                                                    C_Lexique_goil_5F_lexique * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName,
                                                   GALGAS_implementationObjectMap & ioArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString,
                                                     GALGAS_string inNameString,
                                                     GALGAS_implementationObjectMap & ioArgument0
                                                     COMMA_LOCATION_ARGS) ;

//--- Indexing
  public : static void performIndexing (C_Compiler * inCompiler,
                                        const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public : static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                   const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public : static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//------------------------------------- 'implementation_object_list' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_object_5F_list_ (GALGAS_implementation & ioArgument0,
                                                              C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_objects' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_objects_ (GALGAS_implementation & ioArgument0,
                                                       C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_type' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_type_ (GALGAS_lstring & outArgument0,
                                                    GALGAS_impType & outArgument1,
                                                    C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_cpu_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_cpu_5F_level_ (const GALGAS_implementation inArgument0,
                                                     GALGAS_objectsMap & ioArgument1,
                                                     GALGAS_string & ioArgument2,
                                                     const GALGAS_bool inArgument3,
                                                     C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_file_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_file_5F_level_ (GALGAS_implementation & ioArgument0,
                                                      GALGAS_applicationDefinition & ioArgument1,
                                                      GALGAS_string & ioArgument2,
                                                      const GALGAS_bool inArgument3,
                                                      C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_implementation_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_implementation_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_implementation_5F_level_ (GALGAS_implementation & ioArgument0,
                                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_object_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap inArgument0,
                                                        GALGAS_objectAttributes & ioArgument1,
                                                        C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_type_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_type_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & ioArgument0,
                                                      C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'int_or_float' non terminal
//--- 'parse' label
  public : virtual void nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & outArgument0,
                                                const GALGAS_dataType inArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'multiple' non terminal
//--- 'parse' label
  public : virtual void nt_multiple_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_multiple_ (GALGAS_bool & outArgument0,
                                      C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'number_options' non terminal
//--- 'parse' label
  public : virtual void nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_number_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               const GALGAS_dataType inArgument2,
                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'object_definition_list' non terminal
//--- 'parse' label
  public : virtual void nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_object_5F_definition_5F_list_ (const GALGAS_implementation inArgument0,
                                                          GALGAS_objectsMap & ioArgument1,
                                                          GALGAS_string & ioArgument2,
                                                          const GALGAS_bool inArgument3,
                                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'objref_option' non terminal
//--- 'parse' label
  public : virtual void nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_objref_5F_option_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              GALGAS_lstring inArgument2,
                                              C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration' non terminal
//--- 'parse' label
  public : virtual void nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap inArgument0,
                                                GALGAS_objectAttributes & ioArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration_list' non terminal
//--- 'parse' label
  public : virtual void nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap inArgument0,
                                                        GALGAS_objectAttributes & ioArgument1,
                                                        C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range' non terminal
//--- 'parse' label
  public : virtual void nt_range_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_range_ (GALGAS_attributeRange & outArgument0,
                                   const GALGAS_dataType inArgument1,
                                   C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range_content' non terminal
//--- 'parse' label
  public : virtual void nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_range_5F_content_ (GALGAS_attributeRange & outArgument0,
                                              const GALGAS_dataType inArgument1,
                                              C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'set_followup' non terminal
//--- 'parse' label
  public : virtual void nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_set_5F_followup_ (GALGAS_numberList & ioArgument0,
                                             const GALGAS_dataType inArgument1,
                                             C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'sign' non terminal
//--- 'parse' label
  public : virtual void nt_sign_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_sign_ (GALGAS_bool & outArgument0,
                                  C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'start' non terminal
//--- 'parse' label
  public : virtual void nt_start_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_start_ (C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'string_options' non terminal
//--- 'parse' label
  public : virtual void nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_string_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'struct_options' non terminal
//--- 'parse' label
  public : virtual void nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_struct_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'type_options' non terminal
//--- 'parse' label
  public : virtual void nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_type_5F_options_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             const GALGAS_dataType inArgument2,
                                             C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'with_auto' non terminal
//--- 'parse' label
  public : virtual void nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_with_5F_auto_ (GALGAS_bool & outArgument0,
                                          C_Lexique_goil_5F_lexique * inCompiler) ;

  public : virtual int32_t select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_27 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_28 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_29 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_30 (C_Lexique_goil_5F_lexique *) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'verifyEnum'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyEnum (const class GALGAS_impType constinArgument0,
                         class C_Compiler * inCompiler
                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//  GRAMMAR options_grammar
//---------------------------------------------------------------------------------------------------------------------*

class cGrammar_options_5F_grammar : public cParser_options_5F_parser {
//------------------------------------- 'list_option_value' non terminal
//--- 'parse' label
  public : virtual void nt_list_5F_option_5F_value_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_list_5F_option_5F_value_ (GALGAS_gtlData & outArgument0,
                                                     C_Lexique_options_5F_scanner * inCompiler) ;

//------------------------------------- 'option_item' non terminal
//--- 'parse' label
  public : virtual void nt_option_5F_item_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_option_5F_item_ (GALGAS_gtlData & ioArgument0,
                                            C_Lexique_options_5F_scanner * inCompiler) ;

//------------------------------------- 'option_parser_start' non terminal
//--- 'parse' label
  public : virtual void nt_option_5F_parser_5F_start_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_option_5F_parser_5F_start_ (GALGAS_gtlData & outArgument0,
                                                       C_Lexique_options_5F_scanner * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName,
                                                   GALGAS_gtlData & outArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString,
                                                     GALGAS_string inNameString,
                                                     GALGAS_gtlData & outArgument0
                                                     COMMA_LOCATION_ARGS) ;

//--- Indexing
  public : static void performIndexing (C_Compiler * inCompiler,
                                        const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public : static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                   const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public : static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//------------------------------------- 'option_value' non terminal
//--- 'parse' label
  public : virtual void nt_option_5F_value_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_option_5F_value_ (GALGAS_gtlData & outArgument0,
                                             C_Lexique_options_5F_scanner * inCompiler) ;

  public : virtual int32_t select_options_5F_parser_0 (C_Lexique_options_5F_scanner *) ;

  public : virtual int32_t select_options_5F_parser_1 (C_Lexique_options_5F_scanner *) ;

  public : virtual int32_t select_options_5F_parser_2 (C_Lexique_options_5F_scanner *) ;

  public : virtual int32_t select_options_5F_parser_3 (C_Lexique_options_5F_scanner *) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Parser class 'arxml_parser' declaration                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cParser_arxml_5F_parser {
//--- Virtual destructor
  public : virtual ~ cParser_arxml_5F_parser (void) {}

//--- Non terminal declarations
  protected : virtual void nt_arxml_5F_start_5F_symbol_ (class GALGAS_arxmlNode & outArgument0,
                                                         const class GALGAS_bool constinArgument1,
                                                         const class GALGAS_bool constinArgument2,
                                                         class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_arxml_5F_start_5F_symbol_parse (class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_element_ (class GALGAS_arxmlNodeList & ioArgument0,
                                        const class GALGAS_bool constinArgument1,
                                        const class GALGAS_bool constinArgument2,
                                        class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_element_parse (class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_element_5F_list_ (class GALGAS_arxmlNodeList & ioArgument0,
                                                const class GALGAS_bool constinArgument1,
                                                const class GALGAS_bool constinArgument2,
                                                class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_element_5F_list_parse (class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected : void rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_ (GALGAS_arxmlNode & outArgument0,
                                                                      const GALGAS_bool constinArgument1,
                                                                      const GALGAS_bool constinArgument2,
                                                                      C_Lexique_arxml_5F_scanner * inLexique) ;

  protected : void rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_parse (C_Lexique_arxml_5F_scanner * inLexique) ;

  protected : void rule_arxml_5F_parser_element_5F_list_i1_ (GALGAS_arxmlNodeList & ioArgument0,
                                                             const GALGAS_bool constinArgument1,
                                                             const GALGAS_bool constinArgument2,
                                                             C_Lexique_arxml_5F_scanner * inLexique) ;

  protected : void rule_arxml_5F_parser_element_5F_list_i1_parse (C_Lexique_arxml_5F_scanner * inLexique) ;

  protected : void rule_arxml_5F_parser_element_i2_ (GALGAS_arxmlNodeList & ioArgument0,
                                                     const GALGAS_bool constinArgument1,
                                                     const GALGAS_bool constinArgument2,
                                                     C_Lexique_arxml_5F_scanner * inLexique) ;

  protected : void rule_arxml_5F_parser_element_i2_parse (C_Lexique_arxml_5F_scanner * inLexique) ;

  protected : void rule_arxml_5F_parser_element_i3_ (GALGAS_arxmlNodeList & ioArgument0,
                                                     const GALGAS_bool constinArgument1,
                                                     const GALGAS_bool constinArgument2,
                                                     C_Lexique_arxml_5F_scanner * inLexique) ;

  protected : void rule_arxml_5F_parser_element_i3_parse (C_Lexique_arxml_5F_scanner * inLexique) ;



//--- Select methods
  protected : virtual int32_t select_arxml_5F_parser_0 (C_Lexique_arxml_5F_scanner *) = 0 ;

  protected : virtual int32_t select_arxml_5F_parser_1 (C_Lexique_arxml_5F_scanner *) = 0 ;

  protected : virtual int32_t select_arxml_5F_parser_2 (C_Lexique_arxml_5F_scanner *) = 0 ;

  protected : virtual int32_t select_arxml_5F_parser_3 (C_Lexique_arxml_5F_scanner *) = 0 ;


} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @arxmlCommentNode class                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_arxmlCommentNode : public GALGAS_arxmlNode {
//--- Constructor
  public : GALGAS_arxmlCommentNode (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_arxmlCommentNode constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_arxmlCommentNode * ptr (void) const { return (const cPtr_arxmlCommentNode *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_arxmlCommentNode (const cPtr_arxmlCommentNode * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_arxmlCommentNode extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_arxmlCommentNode constructor_new (const class GALGAS_lstring & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_arxmlCommentNode & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_comment (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_arxmlCommentNode class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlCommentNode ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @arxmlCommentNode class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_arxmlCommentNode : public cPtr_arxmlNode {
//--- Attributes
  public : GALGAS_lstring mAttribute_comment ;

//--- Constructor
  public : cPtr_arxmlCommentNode (const GALGAS_lstring & in_comment
                                  COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_comment (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @arxmlElementNode class                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_arxmlElementNode : public GALGAS_arxmlNode {
//--- Constructor
  public : GALGAS_arxmlElementNode (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_arxmlElementNode constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_arxmlElementNode * ptr (void) const { return (const cPtr_arxmlElementNode *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_arxmlElementNode (const cPtr_arxmlElementNode * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_arxmlElementNode extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_arxmlElementNode constructor_new (const class GALGAS_lstring & inOperand0,
                                                                 const class GALGAS_arxmlAttributeMap & inOperand1,
                                                                 const class GALGAS_arxmlNodeList & inOperand2
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_arxmlElementNode & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_arxmlAttributeMap getter_attributes (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_arxmlNodeList getter_enclosedNodes (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_name (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_arxmlElementNode class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlElementNode ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @arxmlElementNode class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_arxmlElementNode : public cPtr_arxmlNode {
//--- Attributes
  public : GALGAS_lstring mAttribute_name ;
  public : GALGAS_arxmlAttributeMap mAttribute_attributes ;
  public : GALGAS_arxmlNodeList mAttribute_enclosedNodes ;

//--- Constructor
  public : cPtr_arxmlElementNode (const GALGAS_lstring & in_name,
                                  const GALGAS_arxmlAttributeMap & in_attributes,
                                  const GALGAS_arxmlNodeList & in_enclosedNodes
                                  COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_name (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_arxmlAttributeMap getter_attributes (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_arxmlNodeList getter_enclosedNodes (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Routine 'addText'                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addText (class GALGAS_arxmlNodeList & ioArgument0,
                      const class GALGAS_bool constinArgument1,
                      class C_Compiler * inCompiler
                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @arxmlTextNode class                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_arxmlTextNode : public GALGAS_arxmlNode {
//--- Constructor
  public : GALGAS_arxmlTextNode (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_arxmlTextNode constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_arxmlTextNode * ptr (void) const { return (const cPtr_arxmlTextNode *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_arxmlTextNode (const cPtr_arxmlTextNode * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_arxmlTextNode extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_arxmlTextNode constructor_new (const class GALGAS_lstring & inOperand0
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_arxmlTextNode & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_text (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_arxmlTextNode class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlTextNode ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Pointer class for @arxmlTextNode class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_arxmlTextNode : public cPtr_arxmlNode {
//--- Attributes
  public : GALGAS_lstring mAttribute_text ;

//--- Constructor
  public : cPtr_arxmlTextNode (const GALGAS_lstring & in_text
                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_text (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

#endif
