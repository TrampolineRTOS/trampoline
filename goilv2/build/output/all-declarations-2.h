#ifndef all_2D_declarations_2D__32__ENTITIES_DEFINED
#define all_2D_declarations_2D__32__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-1.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'template_string'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_template_5F_string (class GALGAS_string inArgument0,
                                                 class GALGAS_string inArgument1,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'templateFilePath'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_templateFilePath (const class GALGAS_string & constinArgument0,
                                               const class GALGAS_string & constinArgument1,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'config_file'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring function_config_5F_file (class C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'extra_config_file'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring function_extra_5F_config_5F_file (class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Routine 'prefix'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_prefix (class GALGAS_prefix_5F_map inArgument0,
                     class GALGAS_string inArgument1,
                     class GALGAS_string & outArgument2,
                     class C_Compiler * inCompiler
                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'performReplace'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_performReplace (class GALGAS_prefix_5F_map inArgument0,
                             class GALGAS_string inArgument1,
                             class GALGAS_string inArgument2,
                             class GALGAS_string & ioArgument3,
                             class C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'doReplace'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_doReplace (class GALGAS_string & ioArgument0,
                        class GALGAS_string inArgument1,
                        class GALGAS_string inArgument2,
                        class C_Compiler * inCompiler
                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'do_replace_default'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_do_5F_replace_5F_default (class GALGAS_string & ioArgument0,
                                       class GALGAS_string inArgument1,
                                       class GALGAS_string inArgument2,
                                       class GALGAS_string inArgument3,
                                       class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'replace_no_prefix'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_replace_5F_no_5F_prefix (class GALGAS_prefix_5F_map inArgument0,
                                      class GALGAS_string inArgument1,
                                      class GALGAS_string inArgument2,
                                      class GALGAS_string & ioArgument3,
                                      class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'table_core'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_table_5F_core (class GALGAS_string inArgument0,
                            class GALGAS_string inArgument1,
                            class GALGAS_string inArgument2,
                            class GALGAS_stringset inArgument3,
                            class GALGAS_string & ioArgument4,
                            class GALGAS_string & ioArgument5,
                            class C_Compiler * inCompiler
                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'add_to_stringset'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_to_5F_stringset (class GALGAS_stringset & ioArgument0,
                                     class GALGAS_string inArgument1,
                                     class C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'is_in_lstringlist'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_is_5F_in_5F_lstringlist (class GALGAS_lstringlist inArgument0,
                                      class GALGAS_lstring inArgument1,
                                      class GALGAS_lstring & outArgument2,
                                      class GALGAS_bool & outArgument3,
                                      class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'isInLstringlist'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool function_isInLstringlist (class GALGAS_lstringlist inArgument0,
                                            class GALGAS_lstring inArgument1,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'add_lstring_unique'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_lstring_5F_unique (class GALGAS_lstringlist & ioArgument0,
                                       class GALGAS_lstring inArgument1,
                                       class GALGAS_string inArgument2,
                                       class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'set_lstring_if_empty'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_set_5F_lstring_5F_if_5F_empty (class GALGAS_lstring & ioArgument0,
                                            class GALGAS_lstring inArgument1,
                                            class GALGAS_string inArgument2,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Routine 'add_makefile_flag_if_not_empty'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_makefile_5F_flag_5F_if_5F_not_5F_empty (class GALGAS_string & ioArgument0,
                                                            class GALGAS_string inArgument1,
                                                            class GALGAS_string inArgument2,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'stripString'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_stripString (class GALGAS_string inArgument0,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'errorNoFileFound'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_errorNoFileFound (const class GALGAS_stringlist constinArgument0,
                               const class GALGAS_string constinArgument1,
                               const class GALGAS_lstring constinArgument2,
                               class C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'attributeAllowsAuto'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool function_attributeAllowsAuto (const class GALGAS_impType & constinArgument0,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'verifyAllAttributes'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyAllAttributes (const class GALGAS_implementation constinArgument0,
                                  const class GALGAS_objectsMap constinArgument1,
                                  class C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Category method '@applicationDefinition verifyCrossReferences'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_applicationDefinition_verifyCrossReferences) (const class cPtr_applicationDefinition * inObject,
                                                                                     const class GALGAS_implementation constinArgument0,
                                                                                     class C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                categoryMethodSignature_applicationDefinition_verifyCrossReferences inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_verifyCrossReferences (const class cPtr_applicationDefinition * inObject,
                                               const GALGAS_implementation constin_imp,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Category method '@implementation verifyApplication'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_implementation_verifyApplication) (const class cPtr_implementation * inObject,
                                                                          const class GALGAS_applicationDefinition constinArgument0,
                                                                          class C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_verifyApplication (const int32_t inClassIndex,
                                            categoryMethodSignature_implementation_verifyApplication inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_verifyApplication (const class cPtr_implementation * inObject,
                                           const GALGAS_applicationDefinition constin_appDef,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'osObject'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_objectAttributes function_osObject (const class GALGAS_objectsMap & constinArgument0,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'objectForKindAndName'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_objectAttributes function_objectForKindAndName (const class GALGAS_objectsMap & constinArgument0,
                                                             const class GALGAS_string & constinArgument1,
                                                             const class GALGAS_string & constinArgument2,
                                                             class C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'setObjectForKindAndName'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setObjectForKindAndName (class GALGAS_objectsMap & ioArgument0,
                                      const class GALGAS_string constinArgument1,
                                      const class GALGAS_string constinArgument2,
                                      const class GALGAS_objectAttributes constinArgument3,
                                      class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'objectsForKind'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_objectKind function_objectsForKind (const class GALGAS_objectsMap & constinArgument0,
                                                 const class GALGAS_string & constinArgument1,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'listInOS'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_identifierList function_listInOS (const class GALGAS_objectsMap & constinArgument0,
                                               const class GALGAS_string & constinArgument1,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'generate_signed_type'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_signed_5F_type (class GALGAS_uint_36__34_ inArgument0,
                                         class GALGAS_string inArgument1,
                                         class GALGAS_string & outArgument2,
                                         class C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'generate_unsigned_type'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_unsigned_5F_type (class GALGAS_uint_36__34_ inArgument0,
                                           class GALGAS_string inArgument1,
                                           class GALGAS_string & outArgument2,
                                           class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'generate_mask_type'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_mask_5F_type (class GALGAS_uint_36__34_ inArgument0,
                                       class GALGAS_string inArgument1,
                                       class GALGAS_string & outArgument2,
                                       class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @autostart_5F_obj class                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_autostart_5F_obj : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_autostart_5F_obj (void) ;

//---
  public : inline const class cPtr_autostart_5F_obj * ptr (void) const { return (const cPtr_autostart_5F_obj *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_autostart_5F_obj (const cPtr_autostart_5F_obj * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_autostart_5F_obj extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_autostart_5F_obj & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_location (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_autostart_5F_obj class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_autostart_5F_obj ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Pointer class for @autostart_obj class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_autostart_5F_obj : public acPtr_class {
//--- Attributes
  public : GALGAS_location mAttribute_location ;

//--- Constructor
  public : cPtr_autostart_5F_obj (const GALGAS_location & in_location
                                  COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_location reader_location (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @autostart_5F_false class                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_autostart_5F_false : public GALGAS_autostart_5F_obj {
//--- Constructor
  public : GALGAS_autostart_5F_false (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_autostart_5F_false constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_autostart_5F_false * ptr (void) const { return (const cPtr_autostart_5F_false *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_autostart_5F_false (const cPtr_autostart_5F_false * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_autostart_5F_false extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_autostart_5F_false constructor_new (const class GALGAS_location & inOperand0
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_autostart_5F_false & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_autostart_5F_false class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_autostart_5F_false ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @autostart_false class                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_autostart_5F_false : public cPtr_autostart_5F_obj {
//--- Attributes

//--- Constructor
  public : cPtr_autostart_5F_false (const GALGAS_location & in_location
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
//                                              @autostart_5F_void class                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_autostart_5F_void : public GALGAS_autostart_5F_obj {
//--- Constructor
  public : GALGAS_autostart_5F_void (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_autostart_5F_void constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_autostart_5F_void * ptr (void) const { return (const cPtr_autostart_5F_void *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_autostart_5F_void (const cPtr_autostart_5F_void * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_autostart_5F_void extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_autostart_5F_void constructor_new (const class GALGAS_location & inOperand0
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_autostart_5F_void & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_autostart_5F_void class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_autostart_5F_void ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Pointer class for @autostart_void class                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_autostart_5F_void : public cPtr_autostart_5F_obj {
//--- Attributes

//--- Constructor
  public : cPtr_autostart_5F_void (const GALGAS_location & in_location
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
//                                          Pointer class for @gtlData class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlData : public acPtr_class {
//--- Attributes
  public : GALGAS_location mAttribute_where ;

//--- Constructor
  public : cPtr_gtlData (const GALGAS_location & in_where
                         COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_location reader_where (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void modifier_setWhere (GALGAS_location inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @gtlBool class                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlBool : public GALGAS_gtlData {
//--- Constructor
  public : GALGAS_gtlBool (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlBool constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlBool * ptr (void) const { return (const cPtr_gtlBool *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlBool (const cPtr_gtlBool * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlBool extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlBool constructor_new (const class GALGAS_location & inOperand0,
                                                  const class GALGAS_bool & inOperand1
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlBool & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlBool class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlBool ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Pointer class for @gtlBool class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlBool : public cPtr_gtlData {
//--- Attributes
  public : GALGAS_bool mAttribute_value ;

//--- Constructor
  public : cPtr_gtlBool (const GALGAS_location & in_where,
                         const GALGAS_bool & in_value
                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_bool reader_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @gtlFloat class                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlFloat : public GALGAS_gtlData {
//--- Constructor
  public : GALGAS_gtlFloat (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlFloat constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlFloat * ptr (void) const { return (const cPtr_gtlFloat *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlFloat (const cPtr_gtlFloat * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlFloat extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlFloat constructor_new (const class GALGAS_location & inOperand0,
                                                   const class GALGAS_double & inOperand1
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlFloat & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_double reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlFloat class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlFloat ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Pointer class for @gtlFloat class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlFloat : public cPtr_gtlData {
//--- Attributes
  public : GALGAS_double mAttribute_value ;

//--- Constructor
  public : cPtr_gtlFloat (const GALGAS_location & in_where,
                          const GALGAS_double & in_value
                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_double reader_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @gtlInt class                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlInt : public GALGAS_gtlData {
//--- Constructor
  public : GALGAS_gtlInt (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlInt constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlInt * ptr (void) const { return (const cPtr_gtlInt *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlInt (const cPtr_gtlInt * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlInt extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlInt constructor_new (const class GALGAS_location & inOperand0,
                                                 const class GALGAS_sint_36__34_ & inOperand1
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlInt & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlInt class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlInt ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Pointer class for @gtlInt class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlInt : public cPtr_gtlData {
//--- Attributes
  public : GALGAS_sint_36__34_ mAttribute_value ;

//--- Constructor
  public : cPtr_gtlInt (const GALGAS_location & in_where,
                        const GALGAS_sint_36__34_ & in_value
                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ reader_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @gtlList class                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlList : public GALGAS_gtlData {
//--- Constructor
  public : GALGAS_gtlList (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlList constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlList * ptr (void) const { return (const cPtr_gtlList *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlList (const cPtr_gtlList * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlList extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlList constructor_new (const class GALGAS_location & inOperand0,
                                                  const class GALGAS_list & inOperand1
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlList & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_list reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlList class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlList ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Pointer class for @gtlList class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlList : public cPtr_gtlData {
//--- Attributes
  public : GALGAS_list mAttribute_value ;

//--- Constructor
  public : cPtr_gtlList (const GALGAS_location & in_where,
                         const GALGAS_list & in_value
                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_list reader_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @gtlMap class                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlMap : public GALGAS_gtlData {
//--- Constructor
  public : GALGAS_gtlMap (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlMap constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlMap * ptr (void) const { return (const cPtr_gtlMap *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlMap (const cPtr_gtlMap * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlMap extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlMap constructor_new (const class GALGAS_location & inOperand0,
                                                 const class GALGAS_map & inOperand1
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlMap & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_map reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlMap class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Pointer class for @gtlMap class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlMap : public cPtr_gtlData {
//--- Attributes
  public : GALGAS_map mAttribute_value ;

//--- Constructor
  public : cPtr_gtlMap (const GALGAS_location & in_where,
                        const GALGAS_map & in_value
                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_map reader_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlString class                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlString : public GALGAS_gtlData {
//--- Constructor
  public : GALGAS_gtlString (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlString constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlString * ptr (void) const { return (const cPtr_gtlString *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlString (const cPtr_gtlString * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlString extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlString constructor_new (const class GALGAS_location & inOperand0,
                                                    const class GALGAS_string & inOperand1
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlString & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlString class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlString ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Pointer class for @gtlString class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlString : public cPtr_gtlData {
//--- Attributes
  public : GALGAS_string mAttribute_value ;

//--- Constructor
  public : cPtr_gtlString (const GALGAS_location & in_where,
                           const GALGAS_string & in_value
                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_string reader_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlStruct class                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlStruct : public GALGAS_gtlData {
//--- Constructor
  public : GALGAS_gtlStruct (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlStruct constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlStruct * ptr (void) const { return (const cPtr_gtlStruct *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlStruct (const cPtr_gtlStruct * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlStruct extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlStruct constructor_new (const class GALGAS_location & inOperand0,
                                                    const class GALGAS_map & inOperand1
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlStruct & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_map reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlStruct class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlStruct ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Pointer class for @gtlStruct class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlStruct : public cPtr_gtlData {
//--- Attributes
  public : GALGAS_map mAttribute_value ;

//--- Constructor
  public : cPtr_gtlStruct (const GALGAS_location & in_where,
                           const GALGAS_map & in_value
                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_map reader_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @gtlExpression class                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlExpression : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_gtlExpression (void) ;

//---
  public : inline const class cPtr_gtlExpression * ptr (void) const { return (const cPtr_gtlExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlExpression (const cPtr_gtlExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlExpression extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_where (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Pointer class for @gtlExpression class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlExpression : public acPtr_class {
//--- Attributes
  public : GALGAS_location mAttribute_where ;

//--- Constructor
  public : cPtr_gtlExpression (const GALGAS_location & in_where
                               COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_location reader_where (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlBinaryExpression class                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlBinaryExpression : public GALGAS_gtlExpression {
//--- Constructor
  public : GALGAS_gtlBinaryExpression (void) ;

//---
  public : inline const class cPtr_gtlBinaryExpression * ptr (void) const { return (const cPtr_gtlBinaryExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlBinaryExpression (const cPtr_gtlBinaryExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlBinaryExpression extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlBinaryExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression reader_lSon (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression reader_rSon (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlBinaryExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlBinaryExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Pointer class for @gtlBinaryExpression class                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlBinaryExpression : public cPtr_gtlExpression {
//--- Attributes
  public : GALGAS_gtlExpression mAttribute_lSon ;
  public : GALGAS_gtlExpression mAttribute_rSon ;

//--- Constructor
  public : cPtr_gtlBinaryExpression (const GALGAS_location & in_where,
                                     const GALGAS_gtlExpression & in_lSon,
                                     const GALGAS_gtlExpression & in_rSon
                                     COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression reader_lSon (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression reader_rSon (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlAddExpression class                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlAddExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlAddExpression (void) ;

//---
  public : inline const class cPtr_gtlAddExpression * ptr (void) const { return (const cPtr_gtlAddExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlAddExpression (const cPtr_gtlAddExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlAddExpression extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlAddExpression constructor_new (const class GALGAS_location & inOperand0,
                                                           const class GALGAS_gtlExpression & inOperand1,
                                                           const class GALGAS_gtlExpression & inOperand2
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlAddExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlAddExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlAddExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @gtlAddExpression class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlAddExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlAddExpression (const GALGAS_location & in_where,
                                  const GALGAS_gtlExpression & in_lSon,
                                  const GALGAS_gtlExpression & in_rSon
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
//                                               @gtlAndExpression class                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlAndExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlAndExpression (void) ;

//---
  public : inline const class cPtr_gtlAndExpression * ptr (void) const { return (const cPtr_gtlAndExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlAndExpression (const cPtr_gtlAndExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlAndExpression extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlAndExpression constructor_new (const class GALGAS_location & inOperand0,
                                                           const class GALGAS_gtlExpression & inOperand1,
                                                           const class GALGAS_gtlExpression & inOperand2
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlAndExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlAndExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlAndExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @gtlAndExpression class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlAndExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlAndExpression (const GALGAS_location & in_where,
                                  const GALGAS_gtlExpression & in_lSon,
                                  const GALGAS_gtlExpression & in_rSon
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
//                                             @gtlDivideExpression class                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlDivideExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlDivideExpression (void) ;

//---
  public : inline const class cPtr_gtlDivideExpression * ptr (void) const { return (const cPtr_gtlDivideExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlDivideExpression (const cPtr_gtlDivideExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlDivideExpression extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlDivideExpression constructor_new (const class GALGAS_location & inOperand0,
                                                              const class GALGAS_gtlExpression & inOperand1,
                                                              const class GALGAS_gtlExpression & inOperand2
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlDivideExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlDivideExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlDivideExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Pointer class for @gtlDivideExpression class                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlDivideExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlDivideExpression (const GALGAS_location & in_where,
                                     const GALGAS_gtlExpression & in_lSon,
                                     const GALGAS_gtlExpression & in_rSon
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
//                                              @gtlEqualExpression class                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlEqualExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlEqualExpression (void) ;

//---
  public : inline const class cPtr_gtlEqualExpression * ptr (void) const { return (const cPtr_gtlEqualExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlEqualExpression (const cPtr_gtlEqualExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlEqualExpression extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlEqualExpression constructor_new (const class GALGAS_location & inOperand0,
                                                             const class GALGAS_gtlExpression & inOperand1,
                                                             const class GALGAS_gtlExpression & inOperand2
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlEqualExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlEqualExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @gtlEqualExpression class                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlEqualExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlEqualExpression (const GALGAS_location & in_where,
                                    const GALGAS_gtlExpression & in_lSon,
                                    const GALGAS_gtlExpression & in_rSon
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
//                                         @gtlGreaterOrEqualExpression class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlGreaterOrEqualExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlGreaterOrEqualExpression (void) ;

//---
  public : inline const class cPtr_gtlGreaterOrEqualExpression * ptr (void) const { return (const cPtr_gtlGreaterOrEqualExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlGreaterOrEqualExpression (const cPtr_gtlGreaterOrEqualExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlGreaterOrEqualExpression extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlGreaterOrEqualExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                      const class GALGAS_gtlExpression & inOperand1,
                                                                      const class GALGAS_gtlExpression & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlGreaterOrEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlGreaterOrEqualExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlGreaterOrEqualExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Pointer class for @gtlGreaterOrEqualExpression class                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlGreaterOrEqualExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlGreaterOrEqualExpression (const GALGAS_location & in_where,
                                             const GALGAS_gtlExpression & in_lSon,
                                             const GALGAS_gtlExpression & in_rSon
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
//                                           @gtlGreaterThanExpression class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlGreaterThanExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlGreaterThanExpression (void) ;

//---
  public : inline const class cPtr_gtlGreaterThanExpression * ptr (void) const { return (const cPtr_gtlGreaterThanExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlGreaterThanExpression (const cPtr_gtlGreaterThanExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlGreaterThanExpression extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlGreaterThanExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                   const class GALGAS_gtlExpression & inOperand1,
                                                                   const class GALGAS_gtlExpression & inOperand2
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlGreaterThanExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlGreaterThanExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlGreaterThanExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Pointer class for @gtlGreaterThanExpression class                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlGreaterThanExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlGreaterThanExpression (const GALGAS_location & in_where,
                                          const GALGAS_gtlExpression & in_lSon,
                                          const GALGAS_gtlExpression & in_rSon
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
//                                          @gtlLowerOrEqualExpression class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlLowerOrEqualExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlLowerOrEqualExpression (void) ;

//---
  public : inline const class cPtr_gtlLowerOrEqualExpression * ptr (void) const { return (const cPtr_gtlLowerOrEqualExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlLowerOrEqualExpression (const cPtr_gtlLowerOrEqualExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlLowerOrEqualExpression extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlLowerOrEqualExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                    const class GALGAS_gtlExpression & inOperand1,
                                                                    const class GALGAS_gtlExpression & inOperand2
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlLowerOrEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlLowerOrEqualExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLowerOrEqualExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Pointer class for @gtlLowerOrEqualExpression class                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlLowerOrEqualExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlLowerOrEqualExpression (const GALGAS_location & in_where,
                                           const GALGAS_gtlExpression & in_lSon,
                                           const GALGAS_gtlExpression & in_rSon
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
//                                            @gtlLowerThanExpression class                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlLowerThanExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlLowerThanExpression (void) ;

//---
  public : inline const class cPtr_gtlLowerThanExpression * ptr (void) const { return (const cPtr_gtlLowerThanExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlLowerThanExpression (const cPtr_gtlLowerThanExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlLowerThanExpression extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlLowerThanExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                 const class GALGAS_gtlExpression & inOperand1,
                                                                 const class GALGAS_gtlExpression & inOperand2
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlLowerThanExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlLowerThanExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLowerThanExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Pointer class for @gtlLowerThanExpression class                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlLowerThanExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlLowerThanExpression (const GALGAS_location & in_where,
                                        const GALGAS_gtlExpression & in_lSon,
                                        const GALGAS_gtlExpression & in_rSon
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
//                                            @gtlMultiplyExpression class                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlMultiplyExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlMultiplyExpression (void) ;

//---
  public : inline const class cPtr_gtlMultiplyExpression * ptr (void) const { return (const cPtr_gtlMultiplyExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlMultiplyExpression (const cPtr_gtlMultiplyExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlMultiplyExpression extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlMultiplyExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                const class GALGAS_gtlExpression & inOperand1,
                                                                const class GALGAS_gtlExpression & inOperand2
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlMultiplyExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlMultiplyExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlMultiplyExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Pointer class for @gtlMultiplyExpression class                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlMultiplyExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlMultiplyExpression (const GALGAS_location & in_where,
                                       const GALGAS_gtlExpression & in_lSon,
                                       const GALGAS_gtlExpression & in_rSon
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
//                                            @gtlNotEqualExpression class                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlNotEqualExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlNotEqualExpression (void) ;

//---
  public : inline const class cPtr_gtlNotEqualExpression * ptr (void) const { return (const cPtr_gtlNotEqualExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlNotEqualExpression (const cPtr_gtlNotEqualExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlNotEqualExpression extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlNotEqualExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                const class GALGAS_gtlExpression & inOperand1,
                                                                const class GALGAS_gtlExpression & inOperand2
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlNotEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlNotEqualExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlNotEqualExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Pointer class for @gtlNotEqualExpression class                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlNotEqualExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlNotEqualExpression (const GALGAS_location & in_where,
                                       const GALGAS_gtlExpression & in_lSon,
                                       const GALGAS_gtlExpression & in_rSon
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
//                                               @gtlOrExpression class                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlOrExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlOrExpression (void) ;

//---
  public : inline const class cPtr_gtlOrExpression * ptr (void) const { return (const cPtr_gtlOrExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlOrExpression (const cPtr_gtlOrExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlOrExpression extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlOrExpression constructor_new (const class GALGAS_location & inOperand0,
                                                          const class GALGAS_gtlExpression & inOperand1,
                                                          const class GALGAS_gtlExpression & inOperand2
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlOrExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlOrExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlOrExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @gtlOrExpression class                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlOrExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlOrExpression (const GALGAS_location & in_where,
                                 const GALGAS_gtlExpression & in_lSon,
                                 const GALGAS_gtlExpression & in_rSon
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
//                                            @gtlShiftLeftExpression class                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlShiftLeftExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlShiftLeftExpression (void) ;

//---
  public : inline const class cPtr_gtlShiftLeftExpression * ptr (void) const { return (const cPtr_gtlShiftLeftExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlShiftLeftExpression (const cPtr_gtlShiftLeftExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlShiftLeftExpression extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlShiftLeftExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                 const class GALGAS_gtlExpression & inOperand1,
                                                                 const class GALGAS_gtlExpression & inOperand2
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlShiftLeftExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlShiftLeftExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlShiftLeftExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Pointer class for @gtlShiftLeftExpression class                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlShiftLeftExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlShiftLeftExpression (const GALGAS_location & in_where,
                                        const GALGAS_gtlExpression & in_lSon,
                                        const GALGAS_gtlExpression & in_rSon
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
//                                           @gtlShiftRightExpression class                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlShiftRightExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlShiftRightExpression (void) ;

//---
  public : inline const class cPtr_gtlShiftRightExpression * ptr (void) const { return (const cPtr_gtlShiftRightExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlShiftRightExpression (const cPtr_gtlShiftRightExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlShiftRightExpression extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlShiftRightExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                  const class GALGAS_gtlExpression & inOperand1,
                                                                  const class GALGAS_gtlExpression & inOperand2
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlShiftRightExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlShiftRightExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlShiftRightExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Pointer class for @gtlShiftRightExpression class                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlShiftRightExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlShiftRightExpression (const GALGAS_location & in_where,
                                         const GALGAS_gtlExpression & in_lSon,
                                         const GALGAS_gtlExpression & in_rSon
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
//                                            @gtlSubstractExpression class                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlSubstractExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlSubstractExpression (void) ;

//---
  public : inline const class cPtr_gtlSubstractExpression * ptr (void) const { return (const cPtr_gtlSubstractExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlSubstractExpression (const cPtr_gtlSubstractExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlSubstractExpression extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlSubstractExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                 const class GALGAS_gtlExpression & inOperand1,
                                                                 const class GALGAS_gtlExpression & inOperand2
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlSubstractExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlSubstractExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSubstractExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Pointer class for @gtlSubstractExpression class                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlSubstractExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlSubstractExpression (const GALGAS_location & in_where,
                                        const GALGAS_gtlExpression & in_lSon,
                                        const GALGAS_gtlExpression & in_rSon
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
//                                               @gtlXorExpression class                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlXorExpression : public GALGAS_gtlBinaryExpression {
//--- Constructor
  public : GALGAS_gtlXorExpression (void) ;

//---
  public : inline const class cPtr_gtlXorExpression * ptr (void) const { return (const cPtr_gtlXorExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlXorExpression (const cPtr_gtlXorExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlXorExpression extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlXorExpression constructor_new (const class GALGAS_location & inOperand0,
                                                           const class GALGAS_gtlExpression & inOperand1,
                                                           const class GALGAS_gtlExpression & inOperand2
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlXorExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlXorExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlXorExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @gtlXorExpression class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlXorExpression : public cPtr_gtlBinaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlXorExpression (const GALGAS_location & in_where,
                                  const GALGAS_gtlExpression & in_lSon,
                                  const GALGAS_gtlExpression & in_rSon
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
//                                                 @gtlTerminal class                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlTerminal : public GALGAS_gtlExpression {
//--- Constructor
  public : GALGAS_gtlTerminal (void) ;

//---
  public : inline const class cPtr_gtlTerminal * ptr (void) const { return (const cPtr_gtlTerminal *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlTerminal (const cPtr_gtlTerminal * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlTerminal extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlTerminal constructor_new (const class GALGAS_location & inOperand0,
                                                      const class GALGAS_gtlData & inOperand1
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlTerminal & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlData reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlTerminal class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTerminal ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Pointer class for @gtlTerminal class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlTerminal : public cPtr_gtlExpression {
//--- Attributes
  public : GALGAS_gtlData mAttribute_value ;

//--- Constructor
  public : cPtr_gtlTerminal (const GALGAS_location & in_where,
                             const GALGAS_gtlData & in_value
                             COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlData reader_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlUnaryExpression class                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlUnaryExpression : public GALGAS_gtlExpression {
//--- Constructor
  public : GALGAS_gtlUnaryExpression (void) ;

//---
  public : inline const class cPtr_gtlUnaryExpression * ptr (void) const { return (const cPtr_gtlUnaryExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlUnaryExpression (const cPtr_gtlUnaryExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlUnaryExpression extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlUnaryExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression reader_son (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlUnaryExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlUnaryExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @gtlUnaryExpression class                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlUnaryExpression : public cPtr_gtlExpression {
//--- Attributes
  public : GALGAS_gtlExpression mAttribute_son ;

//--- Constructor
  public : cPtr_gtlUnaryExpression (const GALGAS_location & in_where,
                                    const GALGAS_gtlExpression & in_son
                                    COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression reader_son (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlMinusExpression class                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlMinusExpression : public GALGAS_gtlUnaryExpression {
//--- Constructor
  public : GALGAS_gtlMinusExpression (void) ;

//---
  public : inline const class cPtr_gtlMinusExpression * ptr (void) const { return (const cPtr_gtlMinusExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlMinusExpression (const cPtr_gtlMinusExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlMinusExpression extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlMinusExpression constructor_new (const class GALGAS_location & inOperand0,
                                                             const class GALGAS_gtlExpression & inOperand1
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlMinusExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlMinusExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlMinusExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @gtlMinusExpression class                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlMinusExpression : public cPtr_gtlUnaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlMinusExpression (const GALGAS_location & in_where,
                                    const GALGAS_gtlExpression & in_son
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
//                                               @gtlNotExpression class                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlNotExpression : public GALGAS_gtlUnaryExpression {
//--- Constructor
  public : GALGAS_gtlNotExpression (void) ;

//---
  public : inline const class cPtr_gtlNotExpression * ptr (void) const { return (const cPtr_gtlNotExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlNotExpression (const cPtr_gtlNotExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlNotExpression extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlNotExpression constructor_new (const class GALGAS_location & inOperand0,
                                                           const class GALGAS_gtlExpression & inOperand1
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlNotExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlNotExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlNotExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @gtlNotExpression class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlNotExpression : public cPtr_gtlUnaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlNotExpression (const GALGAS_location & in_where,
                                  const GALGAS_gtlExpression & in_son
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
//                                          @gtlParenthesizedExpression class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlParenthesizedExpression : public GALGAS_gtlUnaryExpression {
//--- Constructor
  public : GALGAS_gtlParenthesizedExpression (void) ;

//---
  public : inline const class cPtr_gtlParenthesizedExpression * ptr (void) const { return (const cPtr_gtlParenthesizedExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlParenthesizedExpression (const cPtr_gtlParenthesizedExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlParenthesizedExpression extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlParenthesizedExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                     const class GALGAS_gtlExpression & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlParenthesizedExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlParenthesizedExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlParenthesizedExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Pointer class for @gtlParenthesizedExpression class                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlParenthesizedExpression : public cPtr_gtlUnaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlParenthesizedExpression (const GALGAS_location & in_where,
                                            const GALGAS_gtlExpression & in_son
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
//                                              @gtlPlusExpression class                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlPlusExpression : public GALGAS_gtlUnaryExpression {
//--- Constructor
  public : GALGAS_gtlPlusExpression (void) ;

//---
  public : inline const class cPtr_gtlPlusExpression * ptr (void) const { return (const cPtr_gtlPlusExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlPlusExpression (const cPtr_gtlPlusExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlPlusExpression extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_gtlPlusExpression constructor_new (const class GALGAS_location & inOperand0,
                                                            const class GALGAS_gtlExpression & inOperand1
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlPlusExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlPlusExpression class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlPlusExpression ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @gtlPlusExpression class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlPlusExpression : public cPtr_gtlUnaryExpression {
//--- Attributes

//--- Constructor
  public : cPtr_gtlPlusExpression (const GALGAS_location & in_where,
                                   const GALGAS_gtlExpression & in_son
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
//                                                @gtlInstruction class                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlInstruction : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_gtlInstruction (void) ;

//---
  public : inline const class cPtr_gtlInstruction * ptr (void) const { return (const cPtr_gtlInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlInstruction (const cPtr_gtlInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlInstruction extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Pointer class for @gtlInstruction class                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlInstruction : public acPtr_class {
//--- Attributes

//--- Constructor
  public : cPtr_gtlInstruction (LOCATION_ARGS) ;

//--- Attribute accessors
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @bool_5F_t class                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool_5F_t : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_bool_5F_t (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_bool_5F_t constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_bool_5F_t * ptr (void) const { return (const cPtr_bool_5F_t *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_bool_5F_t (const cPtr_bool_5F_t * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_bool_5F_t extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_bool_5F_t constructor_new (const class GALGAS_lstring & inOperand0,
                                                    const class GALGAS_location & inOperand1,
                                                    const class GALGAS_bool & inOperand2
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_bool_5F_t & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_bool_5F_t class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_bool_5F_t ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Pointer class for @bool_t class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_bool_5F_t : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_bool mAttribute_value ;

//--- Constructor
  public : cPtr_bool_5F_t (const GALGAS_lstring & in_oil_5F_desc,
                           const GALGAS_location & in_location,
                           const GALGAS_bool & in_value
                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_bool reader_value (LOCATION_ARGS) const ;
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
  public : static GALGAS_void_5F_bool_5F_t constructor_new (const class GALGAS_lstring & inOperand0,
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
  public : static GALGAS_void_5F_float_5F_class constructor_new (const class GALGAS_lstring & inOperand0,
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
//                                        @void_5F_sint_33__32__5F_class class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_void_5F_sint_33__32__5F_class : public GALGAS_sint_33__32__5F_class {
//--- Constructor
  public : GALGAS_void_5F_sint_33__32__5F_class (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_void_5F_sint_33__32__5F_class constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_void_5F_sint_33__32__5F_class * ptr (void) const { return (const cPtr_void_5F_sint_33__32__5F_class *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_void_5F_sint_33__32__5F_class (const cPtr_void_5F_sint_33__32__5F_class * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_void_5F_sint_33__32__5F_class extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_void_5F_sint_33__32__5F_class constructor_new (const class GALGAS_lstring & inOperand0,
                                                                        const class GALGAS_location & inOperand1,
                                                                        const class GALGAS_sint & inOperand2
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_void_5F_sint_33__32__5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_void_5F_sint_33__32__5F_class class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_sint_33__32__5F_class ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @void_sint32_class class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_void_5F_sint_33__32__5F_class : public cPtr_sint_33__32__5F_class {
//--- Attributes

//--- Constructor
  public : cPtr_void_5F_sint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                               const GALGAS_location & in_location,
                                               const GALGAS_sint & in_value
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
  public : static GALGAS_void_5F_sint_36__34__5F_class constructor_new (const class GALGAS_lstring & inOperand0,
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
  public : static GALGAS_void_5F_string_5F_class constructor_new (const class GALGAS_lstring & inOperand0,
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
//                                        @void_5F_uint_33__32__5F_class class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_void_5F_uint_33__32__5F_class : public GALGAS_uint_33__32__5F_class {
//--- Constructor
  public : GALGAS_void_5F_uint_33__32__5F_class (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_void_5F_uint_33__32__5F_class constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_void_5F_uint_33__32__5F_class * ptr (void) const { return (const cPtr_void_5F_uint_33__32__5F_class *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_void_5F_uint_33__32__5F_class (const cPtr_void_5F_uint_33__32__5F_class * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_void_5F_uint_33__32__5F_class extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_void_5F_uint_33__32__5F_class constructor_new (const class GALGAS_lstring & inOperand0,
                                                                        const class GALGAS_location & inOperand1,
                                                                        const class GALGAS_uint & inOperand2
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_void_5F_uint_33__32__5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_void_5F_uint_33__32__5F_class class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_uint_33__32__5F_class ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @void_uint32_class class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_void_5F_uint_33__32__5F_class : public cPtr_uint_33__32__5F_class {
//--- Attributes

//--- Constructor
  public : cPtr_void_5F_uint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                               const GALGAS_location & in_location,
                                               const GALGAS_uint & in_value
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
  public : static GALGAS_void_5F_uint_36__34__5F_class constructor_new (const class GALGAS_lstring & inOperand0,
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
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_desc (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG GALGAS_lstring reader_desc (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Abstract category reader '@gtlExpression eval'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlExpression_eval) (const class cPtr_gtlExpression * inObject,
                                                                            class C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_eval (const int32_t inClassIndex,
                               categoryReaderSignature_gtlExpression_eval inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_eval (const class cPtr_gtlExpression * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract category method '@gtlInstruction execute'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_gtlInstruction_execute) (const class cPtr_gtlInstruction * inObject,
                                                                class GALGAS_TfieldMap & ioArgument0,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_execute (const int32_t inClassIndex,
                                  categoryMethodSignature_gtlInstruction_execute inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_execute (const class cPtr_gtlInstruction * inObject,
                                 GALGAS_TfieldMap & io_gtlVariableMap,
                                 C_Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Category Reader '@enumValues mergeWithEnum'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_enumValues categoryReader_mergeWithEnum (const class GALGAS_enumValues & inObject,
                                                      const class GALGAS_enumValues & constinArgument0,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                 Category Reader '@implementationObjectMap mergeImplementationObjectAttributesWith'                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_implementationObjectMap categoryReader_mergeImplementationObjectAttributesWith (const class GALGAS_implementationObjectMap & inObject,
                                                                                             const class GALGAS_implementationObjectMap & constinArgument0,
                                                                                             class C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Category reader '@implementation hasLKey'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*categoryReaderSignature_implementation_hasLKey) (const class cPtr_implementation * inObject,
                                                                             const class GALGAS_lstring & constinArgument0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_hasLKey (const int32_t inClassIndex,
                                  categoryReaderSignature_implementation_hasLKey inReader) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callCategoryReader_hasLKey (const cPtr_implementation * inObject,
                                              const GALGAS_lstring & constin_key,
                                              class C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Category method '@implementation checkTypeForKind'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_implementation_checkTypeForKind) (const class cPtr_implementation * inObject,
                                                                         const class GALGAS_string constinArgument0,
                                                                         const class GALGAS_string constinArgument1,
                                                                         const class GALGAS_dataType constinArgument2,
                                                                         class C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_checkTypeForKind (const int32_t inClassIndex,
                                           categoryMethodSignature_implementation_checkTypeForKind inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_checkTypeForKind (const class cPtr_implementation * inObject,
                                          const GALGAS_string constin_objKind,
                                          const GALGAS_string constin_attributeName,
                                          const GALGAS_dataType constin_expectedType,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Category method '@impType checkAttributeReferences'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_impType_checkAttributeReferences) (const class cPtr_impType * inObject,
                                                                          const class GALGAS_implementation constinArgument0,
                                                                          class C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_checkAttributeReferences (const int32_t inClassIndex,
                                                   categoryMethodSignature_impType_checkAttributeReferences inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_checkAttributeReferences (const class cPtr_impType * inObject,
                                                  const GALGAS_implementation constin_imp,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Abstract category reader '@impType mergeWithType'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_impType (*categoryReaderSignature_impType_mergeWithType) (const class cPtr_impType * inObject,
                                                                               class GALGAS_impType inArgument0,
                                                                               class C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_mergeWithType (const int32_t inClassIndex,
                                        categoryReaderSignature_impType_mergeWithType inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_impType callCategoryReader_mergeWithType (const class cPtr_impType * inObject,
                                                       GALGAS_impType in_typeToMerge,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Category reader '@objectAttributes fieldMap'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_TfieldMap (*categoryReaderSignature_objectAttributes_fieldMap) (const class cPtr_objectAttributes * inObject,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_fieldMap (const int32_t inClassIndex,
                                   categoryReaderSignature_objectAttributes_fieldMap inReader) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TfieldMap callCategoryReader_fieldMap (const cPtr_objectAttributes * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Category method '@object_t set'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_object_5F_t_set) (const class cPtr_object_5F_t * inObject,
                                                         const class GALGAS_lstring constinArgument0,
                                                         class GALGAS_TfieldMap & ioArgument1,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_set (const int32_t inClassIndex,
                              categoryMethodSignature_object_5F_t_set inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_set (const class cPtr_object_5F_t * inObject,
                             const GALGAS_lstring constin_name,
                             GALGAS_TfieldMap & io_result,
                             C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Category method '@implementationObject verifyApplication'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_implementationObject_verifyApplication) (const class cPtr_implementationObject * inObject,
                                                                                const class GALGAS_objectKind constinArgument0,
                                                                                class C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_verifyApplication (const int32_t inClassIndex,
                                            categoryMethodSignature_implementationObject_verifyApplication inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_verifyApplication (const class cPtr_implementationObject * inObject,
                                           const GALGAS_objectKind constin_objectsOfKind,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Category method '@objectAttributes verifyCrossReferences'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_objectAttributes_verifyCrossReferences) (const class cPtr_objectAttributes * inObject,
                                                                                const class GALGAS_objectsMap constinArgument0,
                                                                                const class GALGAS_implementationObjectMap constinArgument1,
                                                                                class C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                categoryMethodSignature_objectAttributes_verifyCrossReferences inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_verifyCrossReferences (const class cPtr_objectAttributes * inObject,
                                               const GALGAS_objectsMap constin_allObjects,
                                               const GALGAS_implementationObjectMap constin_attributes,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Category method '@object_t verifyCrossReferences'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_object_5F_t_verifyCrossReferences) (const class cPtr_object_5F_t * inObject,
                                                                           const class GALGAS_objectsMap constinArgument0,
                                                                           const class GALGAS_impType constinArgument1,
                                                                           class C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                categoryMethodSignature_object_5F_t_verifyCrossReferences inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_verifyCrossReferences (const class cPtr_object_5F_t * inObject,
                                               const GALGAS_objectsMap constin_allObjects,
                                               const GALGAS_impType constin_type,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract category reader '@gtlData plusOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_plusOp) (const class cPtr_gtlData * inObject,
                                                                        class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_plusOp (const int32_t inClassIndex,
                                 categoryReaderSignature_gtlData_plusOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_plusOp (const class cPtr_gtlData * inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract category reader '@gtlData minusOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_minusOp) (const class cPtr_gtlData * inObject,
                                                                         class C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_minusOp (const int32_t inClassIndex,
                                  categoryReaderSignature_gtlData_minusOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_minusOp (const class cPtr_gtlData * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData notOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_notOp) (const class cPtr_gtlData * inObject,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_notOp (const int32_t inClassIndex,
                                categoryReaderSignature_gtlData_notOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_notOp (const class cPtr_gtlData * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData addOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_addOp) (const class cPtr_gtlData * inObject,
                                                                       const class GALGAS_gtlData & constinArgument0,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_addOp (const int32_t inClassIndex,
                                categoryReaderSignature_gtlData_addOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_addOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData & constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData subOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_subOp) (const class cPtr_gtlData * inObject,
                                                                       const class GALGAS_gtlData & constinArgument0,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_subOp (const int32_t inClassIndex,
                                categoryReaderSignature_gtlData_subOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_subOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData & constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData mulOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_mulOp) (const class cPtr_gtlData * inObject,
                                                                       const class GALGAS_gtlData & constinArgument0,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_mulOp (const int32_t inClassIndex,
                                categoryReaderSignature_gtlData_mulOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_mulOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData & constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData divOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_divOp) (const class cPtr_gtlData * inObject,
                                                                       const class GALGAS_gtlData & constinArgument0,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_divOp (const int32_t inClassIndex,
                                categoryReaderSignature_gtlData_divOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_divOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData & constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData andOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_andOp) (const class cPtr_gtlData * inObject,
                                                                       const class GALGAS_gtlData & constinArgument0,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_andOp (const int32_t inClassIndex,
                                categoryReaderSignature_gtlData_andOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_andOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData & constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData orOp'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_orOp) (const class cPtr_gtlData * inObject,
                                                                      const class GALGAS_gtlData & constinArgument0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_orOp (const int32_t inClassIndex,
                               categoryReaderSignature_gtlData_orOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_orOp (const class cPtr_gtlData * inObject,
                                              const GALGAS_gtlData & constin_right,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData xorOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_xorOp) (const class cPtr_gtlData * inObject,
                                                                       const class GALGAS_gtlData & constinArgument0,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_xorOp (const int32_t inClassIndex,
                                categoryReaderSignature_gtlData_xorOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_xorOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData & constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData slOp'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_slOp) (const class cPtr_gtlData * inObject,
                                                                      const class GALGAS_gtlData & constinArgument0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_slOp (const int32_t inClassIndex,
                               categoryReaderSignature_gtlData_slOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_slOp (const class cPtr_gtlData * inObject,
                                              const GALGAS_gtlData & constin_right,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData srOp'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_srOp) (const class cPtr_gtlData * inObject,
                                                                      const class GALGAS_gtlData & constinArgument0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_srOp (const int32_t inClassIndex,
                               categoryReaderSignature_gtlData_srOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_srOp (const class cPtr_gtlData * inObject,
                                              const GALGAS_gtlData & constin_right,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData neqOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_neqOp) (const class cPtr_gtlData * inObject,
                                                                       const class GALGAS_gtlData & constinArgument0,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_neqOp (const int32_t inClassIndex,
                                categoryReaderSignature_gtlData_neqOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_neqOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData & constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData eqOp'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_eqOp) (const class cPtr_gtlData * inObject,
                                                                      const class GALGAS_gtlData & constinArgument0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_eqOp (const int32_t inClassIndex,
                               categoryReaderSignature_gtlData_eqOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_eqOp (const class cPtr_gtlData * inObject,
                                              const GALGAS_gtlData & constin_right,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData ltOp'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_ltOp) (const class cPtr_gtlData * inObject,
                                                                      const class GALGAS_gtlData & constinArgument0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_ltOp (const int32_t inClassIndex,
                               categoryReaderSignature_gtlData_ltOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_ltOp (const class cPtr_gtlData * inObject,
                                              const GALGAS_gtlData & constin_right,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData leOp'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_leOp) (const class cPtr_gtlData * inObject,
                                                                      const class GALGAS_gtlData & constinArgument0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_leOp (const int32_t inClassIndex,
                               categoryReaderSignature_gtlData_leOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_leOp (const class cPtr_gtlData * inObject,
                                              const GALGAS_gtlData & constin_right,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData gtOp'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_gtOp) (const class cPtr_gtlData * inObject,
                                                                      const class GALGAS_gtlData & constinArgument0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_gtOp (const int32_t inClassIndex,
                               categoryReaderSignature_gtlData_gtOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_gtOp (const class cPtr_gtlData * inObject,
                                              const GALGAS_gtlData & constin_right,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract category reader '@gtlData geOp'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*categoryReaderSignature_gtlData_geOp) (const class cPtr_gtlData * inObject,
                                                                      const class GALGAS_gtlData & constinArgument0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_geOp (const int32_t inClassIndex,
                               categoryReaderSignature_gtlData_geOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callCategoryReader_geOp (const class cPtr_gtlData * inObject,
                                              const GALGAS_gtlData & constin_right,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Category reader '@applicationDefinition applicationWithDefaults'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_applicationDefinition (*categoryReaderSignature_applicationDefinition_applicationWithDefaults) (const class cPtr_applicationDefinition * inObject,
                                                                                                                     const class GALGAS_implementation & constinArgument0,
                                                                                                                     C_Compiler * inCompiler
                                                                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_applicationWithDefaults (const int32_t inClassIndex,
                                                  categoryReaderSignature_applicationDefinition_applicationWithDefaults inReader) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_applicationDefinition callCategoryReader_applicationWithDefaults (const cPtr_applicationDefinition * inObject,
                                                                               const GALGAS_implementation & constin_imp,
                                                                               class C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Category method '@impType verifyApplication'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_impType_verifyApplication) (const class cPtr_impType * inObject,
                                                                   const class GALGAS_objectAttributes constinArgument0,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_verifyApplication (const int32_t inClassIndex,
                                            categoryMethodSignature_impType_verifyApplication inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_verifyApplication (const class cPtr_impType * inObject,
                                           const GALGAS_objectAttributes constin_attrs,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Category method '@impType verifyMultipleType'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_impType_verifyMultipleType) (const class cPtr_impType * inObject,
                                                                    const class GALGAS_object_5F_t constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_verifyMultipleType (const int32_t inClassIndex,
                                             categoryMethodSignature_impType_verifyMultipleType inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_verifyMultipleType (const class cPtr_impType * inObject,
                                            const GALGAS_object_5F_t constin_attr,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Category method '@impType verifyType'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_impType_verifyType) (const class cPtr_impType * inObject,
                                                            const class GALGAS_object_5F_t constinArgument0,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_verifyType (const int32_t inClassIndex,
                                     categoryMethodSignature_impType_verifyType inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_verifyType (const class cPtr_impType * inObject,
                                    const GALGAS_object_5F_t constin_attr,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Category method '@objectsMap verifyCrossReferences'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void categoryMethod_verifyCrossReferences (const class GALGAS_objectsMap inObject,
                                           const class GALGAS_implementation constin_imp,
                                           class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Category method '@objectKind verifyCrossReferences'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_objectKind_verifyCrossReferences) (const class cPtr_objectKind * inObject,
                                                                          const class GALGAS_objectsMap constinArgument0,
                                                                          const class GALGAS_implementationObject constinArgument1,
                                                                          class C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                categoryMethodSignature_objectKind_verifyCrossReferences inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_verifyCrossReferences (const class cPtr_objectKind * inObject,
                                               const GALGAS_objectsMap constin_allObjects,
                                               const GALGAS_implementationObject constin_obj,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

#endif
