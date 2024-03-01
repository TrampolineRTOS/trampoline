#pragma once

//--------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-2.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaElementList_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaElementList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_arxmlMetaElement mProperty_lElement ;
  public: inline GALGAS_arxmlMetaElement readProperty_lElement (void) const {
    return mProperty_lElement ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaElementList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLElement (const GALGAS_arxmlMetaElement & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lElement = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_arxmlMetaElementList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_arxmlMetaElementList_2D_element (const GALGAS_arxmlMetaElement & in_lElement) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaElementList_2D_element extractObject (const GALGAS_object & inObject,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaElementList_2D_element class_func_new (const class GALGAS_arxmlMetaElement & inOperand0,
                                                                              class Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlMetaElementList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlMetaElementList_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaElementList_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaAttributeList_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaAttributeList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_arxmlMetaAttribute mProperty_lAttribute ;
  public: inline GALGAS_arxmlMetaAttribute readProperty_lAttribute (void) const {
    return mProperty_lAttribute ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaAttributeList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLAttribute (const GALGAS_arxmlMetaAttribute & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lAttribute = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_arxmlMetaAttributeList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_arxmlMetaAttributeList_2D_element (const GALGAS_arxmlMetaAttribute & in_lAttribute) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaAttributeList_2D_element extractObject (const GALGAS_object & inObject,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaAttributeList_2D_element class_func_new (const class GALGAS_arxmlMetaAttribute & inOperand0,
                                                                                class Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlMetaAttributeList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlMetaAttributeList_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaAttributeList_2D_element ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlMetaElementList string' (as function)
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string extensionGetter_string (const class GALGAS_arxmlMetaElementList & inObject,
                                            class Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlMetaAttributeList string' (as function)
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string extensionGetter_string (const class GALGAS_arxmlMetaAttributeList & inObject,
                                            class Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//                                            Phase 1: @restrictionType enum                                           *
//
//--------------------------------------------------------------------------------------------------

class GALGAS_restrictionType : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public: GALGAS_restrictionType (void) ;

//--------------------------------- Enumeration
  public: typedef enum {
    kNotBuilt,
    kEnum_restrictionSimple,
    kEnum_restrictionEnum,
    kEnum_restrictionOther,
    kEnum_restrictionUnused
  } enumeration ;
  
//--------------------------------- Private data member
  private: enumeration mEnum ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return kNotBuilt != mEnum ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mEnum = kNotBuilt ; }
  public: inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_restrictionType extractObject (const GALGAS_object & inObject,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_restrictionType class_func_restrictionEnum (LOCATION_ARGS) ;

  public: static class GALGAS_restrictionType class_func_restrictionOther (LOCATION_ARGS) ;

  public: static class GALGAS_restrictionType class_func_restrictionSimple (LOCATION_ARGS) ;

  public: static class GALGAS_restrictionType class_func_restrictionUnused (LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_restrictionType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionEnum (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionOther (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionSimple (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionUnused (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_restrictionEnum () const ;

  public: VIRTUAL_IN_DEBUG bool optional_restrictionOther () const ;

  public: VIRTUAL_IN_DEBUG bool optional_restrictionSimple () const ;

  public: VIRTUAL_IN_DEBUG bool optional_restrictionUnused () const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_restrictionType class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_restrictionType ;

//--------------------------------------------------------------------------------------------------
//
//                                          Phase 1: @restrictionBaseType enum                                         *
//
//--------------------------------------------------------------------------------------------------

class GALGAS_restrictionBaseType : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public: GALGAS_restrictionBaseType (void) ;

//--------------------------------- Enumeration
  public: typedef enum {
    kNotBuilt,
    kEnum_restrictionString,
    kEnum_restrictionUint,
    kEnum_restrictionDouble,
    kEnum_restrictionUndef
  } enumeration ;
  
//--------------------------------- Private data member
  private: enumeration mEnum ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return kNotBuilt != mEnum ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mEnum = kNotBuilt ; }
  public: inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_restrictionBaseType extractObject (const GALGAS_object & inObject,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_restrictionBaseType class_func_restrictionDouble (LOCATION_ARGS) ;

  public: static class GALGAS_restrictionBaseType class_func_restrictionString (LOCATION_ARGS) ;

  public: static class GALGAS_restrictionBaseType class_func_restrictionUint (LOCATION_ARGS) ;

  public: static class GALGAS_restrictionBaseType class_func_restrictionUndef (LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_restrictionBaseType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionDouble (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionUint (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionUndef (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_restrictionDouble () const ;

  public: VIRTUAL_IN_DEBUG bool optional_restrictionString () const ;

  public: VIRTUAL_IN_DEBUG bool optional_restrictionUint () const ;

  public: VIRTUAL_IN_DEBUG bool optional_restrictionUndef () const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_restrictionBaseType class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_restrictionBaseType ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlTemplate execute'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_execute (class cPtr_gtlTemplate * inObject,
                                  class GALGAS_gtlContext & io_context,
                                  class GALGAS_gtlData & io_vars,
                                  class GALGAS_library & io_lib,
                                  class GALGAS_string & io_outputString,
                                  Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@library functionExists'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_functionExists (const cPtr_library * inObject,
                                                      const class GALGAS_lstring constin_name,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@library getFunction'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlFunction callExtensionGetter_getFunction (const cPtr_library * inObject,
                                                          const class GALGAS_lstring constin_name,
                                                          class Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@library putFunction'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_library_putFunction) (class cPtr_library * inObject,
                                                              const class GALGAS_lstring constinArgument0,
                                                              const class GALGAS_gtlFunction constinArgument1,
                                                              class Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_putFunction (const int32_t inClassIndex,
                                       extensionSetterSignature_library_putFunction inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_putFunction (class cPtr_library * inObject,
                                      const GALGAS_lstring constin_name,
                                      const GALGAS_gtlFunction constin_aFunction,
                                      Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@library getterExists'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_getterExists (const cPtr_library * inObject,
                                                    const class GALGAS_string constin_type,
                                                    const class GALGAS_lstring constin_name,
                                                    class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@library getGetter'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlGetter callExtensionGetter_getGetter (const cPtr_library * inObject,
                                                      const class GALGAS_string constin_type,
                                                      const class GALGAS_lstring constin_name,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlGetter class
//
//--------------------------------------------------------------------------------------------------

class cPtr_gtlGetter : public cPtr_gtlFunction {

//--- Extension getter callGetter
  public: virtual class GALGAS_gtlData getter_callGetter (const class GALGAS_location fromLocation,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           const class GALGAS_gtlData target,
           const class GALGAS_gtlDataList actualArguments,
           Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter typedName
  public: virtual class GALGAS_lstring getter_typedName (Compiler * COMMA_LOCATION_ARGS) const ;


//--- Properties
  public: GALGAS_type mProperty_targetType ;

//--- Constructor
  public: cPtr_gtlGetter (const GALGAS_location & in_where,
                          const GALGAS_lstring & in_name,
                          const GALGAS_gtlArgumentList & in_formalArguments,
                          const GALGAS_gtlInstructionList & in_instructions,
                          const GALGAS_lstring & in_returnVariable,
                          const GALGAS_type & in_targetType
                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_type getter_targetType (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setTargetType (GALGAS_type inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@library putGetter'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_library_putGetter) (class cPtr_library * inObject,
                                                            const class GALGAS_lstring constinArgument0,
                                                            const class GALGAS_gtlGetter constinArgument1,
                                                            class Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_putGetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putGetter inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_putGetter (class cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlGetter constin_aGetter,
                                    Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@library setterExists'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_setterExists (const cPtr_library * inObject,
                                                    const class GALGAS_string constin_type,
                                                    const class GALGAS_lstring constin_name,
                                                    class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@library getSetter'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlSetter callExtensionGetter_getSetter (const cPtr_library * inObject,
                                                      const class GALGAS_string constin_type,
                                                      const class GALGAS_lstring constin_name,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlSetter class
//
//--------------------------------------------------------------------------------------------------

class cPtr_gtlSetter : public cPtr_gtlExecutableEntity {

//--- Extension getter typedName
  public: virtual class GALGAS_lstring getter_typedName (Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method callSetter
  public: virtual void method_callSetter (const class GALGAS_location fromLocation,
           class GALGAS_gtlContext context,
           class GALGAS_library lib,
           class GALGAS_gtlData & target,
           const class GALGAS_gtlDataList actualArguments,
           Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_type mProperty_targetType ;

//--- Constructor
  public: cPtr_gtlSetter (const GALGAS_location & in_where,
                          const GALGAS_lstring & in_name,
                          const GALGAS_gtlArgumentList & in_formalArguments,
                          const GALGAS_gtlInstructionList & in_instructions,
                          const GALGAS_type & in_targetType
                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_type getter_targetType (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setTargetType (GALGAS_type inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@library putSetter'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_library_putSetter) (class cPtr_library * inObject,
                                                            const class GALGAS_lstring constinArgument0,
                                                            const class GALGAS_gtlSetter constinArgument1,
                                                            class Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_putSetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putSetter inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_putSetter (class cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlSetter constin_aSetter,
                                    Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@library hasImport'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasImport (const cPtr_library * inObject,
                                                 const class GALGAS_string constin_importPath,
                                                 class Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@library doImport'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_library_doImport) (class cPtr_library * inObject,
                                                           const class GALGAS_string constinArgument0,
                                                           class Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_doImport (const int32_t inClassIndex,
                                    extensionSetterSignature_library_doImport inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_doImport (class cPtr_library * inObject,
                                   const GALGAS_string constin_importPath,
                                   Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@library getTemplate'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_library_getTemplate) (class cPtr_library * inObject,
                                                              const class GALGAS_gtlContext constinArgument0,
                                                              class GALGAS_lstring inArgument1,
                                                              class GALGAS_bool inArgument2,
                                                              class GALGAS_library & ioArgument3,
                                                              class GALGAS_bool & outArgument4,
                                                              class GALGAS_gtlTemplate & outArgument5,
                                                              class Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_getTemplate (const int32_t inClassIndex,
                                       extensionSetterSignature_library_getTemplate inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_getTemplate (class cPtr_library * inObject,
                                      const GALGAS_gtlContext constin_context,
                                      GALGAS_lstring in_path,
                                      GALGAS_bool in_ifExists,
                                      GALGAS_library & io_lib,
                                      GALGAS_bool & out_found,
                                      GALGAS_gtlTemplate & out_result,
                                      Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlVarItemField lstringPath'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_lstringPath (const cPtr_gtlVarItemField * inObject,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlExpression location'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_location callExtensionGetter_location (const cPtr_gtlExpression * inObject,
                                                    class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlExpression eval'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_eval (const class cPtr_gtlExpression * inObject,
                                               const class GALGAS_gtlContext constin_context,
                                               const class GALGAS_gtlData constin_vars,
                                               const class GALGAS_library constin_lib,
                                               class Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData string'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string callExtensionGetter_string (const class cPtr_gtlData * inObject,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData lstring'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_lstring (const class cPtr_gtlData * inObject,
                                                  class Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData int'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bigint callExtensionGetter_int (const class cPtr_gtlData * inObject,
                                             class Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData float'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_double callExtensionGetter_float (const class cPtr_gtlData * inObject,
                                               class Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData plusOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_plusOp (const class cPtr_gtlData * inObject,
                                                 class Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData minusOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_minusOp (const class cPtr_gtlData * inObject,
                                                  class Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData notOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_notOp (const class cPtr_gtlData * inObject,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData addOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_addOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData subOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_subOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData mulOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_mulOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData divOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_divOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData modOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_modOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData andOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_andOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData orOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_orOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData xorOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_xorOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData slOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_slOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData srOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_srOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData neqOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_neqOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData eqOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_eqOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData leOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_leOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData geOp'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_geOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData embeddedType'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_type callExtensionGetter_embeddedType (const class cPtr_gtlData * inObject,
                                                    class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension method '@gtlData addMyValue'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_addMyValue (class cPtr_gtlData * inObject,
                                     class GALGAS_objectlist & io_objectList,
                                     class Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData performGetter'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_performGetter (const class cPtr_gtlData * inObject,
                                                        const class GALGAS_lstring constin_methodName,
                                                        const class GALGAS_gtlDataList constin_arguments,
                                                        const class GALGAS_gtlContext constin_context,
                                                        const class GALGAS_library constin_lib,
                                                        class Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension setter '@gtlData performSetter'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_performSetter) (class cPtr_gtlData * inObject,
                                                                const class GALGAS_lstring constinArgument0,
                                                                const class GALGAS_gtlDataList constinArgument1,
                                                                const class GALGAS_gtlContext constinArgument2,
                                                                const class GALGAS_library constinArgument3,
                                                                class Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_performSetter (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlData_performSetter inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_performSetter (class cPtr_gtlData * inObject,
                                        const GALGAS_lstring constin_methodName,
                                        const GALGAS_gtlDataList constin_arguments,
                                        const GALGAS_gtlContext constin_context,
                                        const GALGAS_library constin_lib,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlData structField'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_structField (class cPtr_gtlData * inObject,
                                      const class GALGAS_lstring constin_name,
                                      class GALGAS_gtlData & out_result,
                                      class GALGAS_bool & out_found,
                                      Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData resultField'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_resultField (const cPtr_gtlData * inObject,
                                                      const class GALGAS_lstring constin_name,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData setStructFieldAtLevel'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_setStructFieldAtLevel) (class cPtr_gtlData * inObject,
                                                                        const class GALGAS_lstring constinArgument0,
                                                                        const class GALGAS_gtlData constinArgument1,
                                                                        const class GALGAS_uint constinArgument2,
                                                                        class Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_setStructFieldAtLevel (const int32_t inClassIndex,
                                                 extensionSetterSignature_gtlData_setStructFieldAtLevel inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_setStructFieldAtLevel (class cPtr_gtlData * inObject,
                                                const GALGAS_lstring constin_name,
                                                const GALGAS_gtlData constin_data,
                                                const GALGAS_uint constin_level,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData deleteStructField'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_deleteStructField) (class cPtr_gtlData * inObject,
                                                                    const class GALGAS_lstring constinArgument0,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteStructField (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlData_deleteStructField inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteStructField (class cPtr_gtlData * inObject,
                                            const GALGAS_lstring constin_name,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData hasStructField'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasStructField (const cPtr_gtlData * inObject,
                                                      const class GALGAS_lstring constin_name,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData overrideMap'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlStruct callExtensionGetter_overrideMap (const cPtr_gtlData * inObject,
                                                        class Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData overriddenMap'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlStruct callExtensionGetter_overriddenMap (const cPtr_gtlData * inObject,
                                                          class Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlData mapItem'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_mapItem (class cPtr_gtlData * inObject,
                                  const class GALGAS_lstring constin_name,
                                  class GALGAS_gtlData & out_result,
                                  Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData hasMapItem'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasMapItem (const cPtr_gtlData * inObject,
                                                  const class GALGAS_lstring constin_name,
                                                  class Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData setMapItem'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_setMapItem) (class cPtr_gtlData * inObject,
                                                             const class GALGAS_lstring constinArgument0,
                                                             const class GALGAS_gtlData constinArgument1,
                                                             class Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_setMapItem (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlData_setMapItem inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_setMapItem (class cPtr_gtlData * inObject,
                                     const GALGAS_lstring constin_name,
                                     const GALGAS_gtlData constin_data,
                                     Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData deleteMapItem'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_deleteMapItem) (class cPtr_gtlData * inObject,
                                                                const class GALGAS_lstring constinArgument0,
                                                                class Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteMapItem (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlData_deleteMapItem inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteMapItem (class cPtr_gtlData * inObject,
                                        const GALGAS_lstring constin_name,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlData itemAtIndex'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_itemAtIndex (class cPtr_gtlData * inObject,
                                      class GALGAS_gtlData & out_result,
                                      const class GALGAS_gtlInt constin_index,
                                      Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData hasItemAtIndex'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasItemAtIndex (const cPtr_gtlData * inObject,
                                                      const class GALGAS_gtlInt constin_index,
                                                      class Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData setItemAtIndex'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_setItemAtIndex) (class cPtr_gtlData * inObject,
                                                                 const class GALGAS_gtlData constinArgument0,
                                                                 const class GALGAS_gtlInt constinArgument1,
                                                                 class Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_setItemAtIndex (const int32_t inClassIndex,
                                          extensionSetterSignature_gtlData_setItemAtIndex inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_setItemAtIndex (class cPtr_gtlData * inObject,
                                         const GALGAS_gtlData constin_data,
                                         const GALGAS_gtlInt constin_index,
                                         Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData deleteItemAtIndex'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_deleteItemAtIndex) (class cPtr_gtlData * inObject,
                                                                    const class GALGAS_gtlInt constinArgument0,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteItemAtIndex (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlData_deleteItemAtIndex inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteItemAtIndex (class cPtr_gtlData * inObject,
                                            const GALGAS_gtlInt constin_index,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData appendItem'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_appendItem) (class cPtr_gtlData * inObject,
                                                             const class GALGAS_gtlData constinArgument0,
                                                             class Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_appendItem (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlData_appendItem inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_appendItem (class cPtr_gtlData * inObject,
                                     const GALGAS_gtlData constin_item,
                                     Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlExecutableEntity checkArguments'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_checkArguments (class cPtr_gtlExecutableEntity * inObject,
                                         const class GALGAS_location constin_fromLocation,
                                         const class GALGAS_gtlDataList constin_actualArguments,
                                         class GALGAS_gtlData & out_entityVariableMap,
                                         class GALGAS_bool & out_result,
                                         Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlProcedure class
//
//--------------------------------------------------------------------------------------------------

class cPtr_gtlProcedure : public cPtr_gtlExecutableEntity {

//--- Extension method call
  public: virtual void method_call (class GALGAS_gtlContext & context,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           const class GALGAS_location fromLocation,
           const class GALGAS_gtlDataList actualArguments,
           Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties

//--- Constructor
  public: cPtr_gtlProcedure (const GALGAS_location & in_where,
                             const GALGAS_lstring & in_name,
                             const GALGAS_gtlArgumentList & in_formalArguments,
                             const GALGAS_gtlInstructionList & in_instructions
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
//Extension method '@gtlProcedure call'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_call (class cPtr_gtlProcedure * inObject,
                               class GALGAS_gtlContext & io_context,
                               class GALGAS_library & io_lib,
                               class GALGAS_string & io_outputString,
                               const class GALGAS_location constin_fromLocation,
                               const class GALGAS_gtlDataList constin_actualArguments,
                               Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlFunction call'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_call (const cPtr_gtlFunction * inObject,
                                               const class GALGAS_location constin_fromLocation,
                                               class GALGAS_gtlContext in_context,
                                               class GALGAS_library in_lib,
                                               const class GALGAS_gtlDataList constin_actualArguments,
                                               class Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlGetter callGetter'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_callGetter (const cPtr_gtlGetter * inObject,
                                                     const class GALGAS_location constin_fromLocation,
                                                     class GALGAS_gtlContext in_context,
                                                     class GALGAS_library in_lib,
                                                     const class GALGAS_gtlData constin_target,
                                                     const class GALGAS_gtlDataList constin_actualArguments,
                                                     class Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlGetter typedName'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_typedName (const cPtr_gtlGetter * inObject,
                                                    class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlSetter callSetter'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_callSetter (class cPtr_gtlSetter * inObject,
                                     const class GALGAS_location constin_fromLocation,
                                     class GALGAS_gtlContext in_context,
                                     class GALGAS_library in_lib,
                                     class GALGAS_gtlData & io_target,
                                     const class GALGAS_gtlDataList constin_actualArguments,
                                     Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlSetter typedName'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_typedName (const cPtr_gtlSetter * inObject,
                                                    class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlModule  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlModule : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_gtlModule (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlModule * ptr (void) const {
    return (const cPtr_gtlModule *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlModule (const cPtr_gtlModule * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_name (void) const ;

  public: class GALGAS_gtlProcMap readProperty_procedures (void) const ;

  public: class GALGAS_gtlFuncMap readProperty_functions (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlModule extractObject (const GALGAS_object & inObject,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_gtlModule class_func_new (const class GALGAS_lstring & inOperand0,
                                                        const class GALGAS_gtlProcMap & inOperand1,
                                                        const class GALGAS_gtlFuncMap & inOperand2
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlModule & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setFunctions (class GALGAS_gtlFuncMap inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setName (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setProcedures (class GALGAS_gtlProcMap inArgument0
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlModule class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlModule ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlModule class
//
//--------------------------------------------------------------------------------------------------

class cPtr_gtlModule : public acPtr_class {


//--- Properties
  public: GALGAS_lstring mProperty_name ;
  public: GALGAS_gtlProcMap mProperty_procedures ;
  public: GALGAS_gtlFuncMap mProperty_functions ;

//--- Constructor
  public: cPtr_gtlModule (const GALGAS_lstring & in_name,
                          const GALGAS_gtlProcMap & in_procedures,
                          const GALGAS_gtlFuncMap & in_functions
                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_name (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlProcMap getter_procedures (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setProcedures (GALGAS_gtlProcMap inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlFuncMap getter_functions (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setFunctions (GALGAS_gtlFuncMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

