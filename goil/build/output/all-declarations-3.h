#ifndef all_2D_declarations_2D__33__ENTITIES_DEFINED
#define all_2D_declarations_2D__33__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "all-predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-2.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@library functionExists'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_library_functionExists) (const class cPtr_library * inObject,
                                                                          const class GALGAS_lstring constinArgument0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_functionExists (const int32_t inClassIndex,
                                          enterExtensionGetter_library_functionExists inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_functionExists (const cPtr_library * inObject,
                                                      const GALGAS_lstring constin_name,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@library getFunction'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlFunction (*enterExtensionGetter_library_getFunction) (const class cPtr_library * inObject,
                                                                              const class GALGAS_lstring constinArgument0,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getFunction (const int32_t inClassIndex,
                                       enterExtensionGetter_library_getFunction inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlFunction callExtensionGetter_getFunction (const cPtr_library * inObject,
                                                          const GALGAS_lstring constin_name,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@library putFunction'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_library_putFunction) (class cPtr_library * inObject,
                                                              const class GALGAS_lstring constinArgument0,
                                                              const class GALGAS_gtlFunction constinArgument1,
                                                              class C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_putFunction (const int32_t inClassIndex,
                                       extensionSetterSignature_library_putFunction inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_putFunction (class cPtr_library * inObject,
                                      const GALGAS_lstring constin_name,
                                      const GALGAS_gtlFunction constin_aFunction,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@library getterExists'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_library_getterExists) (const class cPtr_library * inObject,
                                                                        const class GALGAS_string constinArgument0,
                                                                        const class GALGAS_lstring constinArgument1,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getterExists (const int32_t inClassIndex,
                                        enterExtensionGetter_library_getterExists inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_getterExists (const cPtr_library * inObject,
                                                    const GALGAS_string constin_type,
                                                    const GALGAS_lstring constin_name,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@library getGetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlGetter (*enterExtensionGetter_library_getGetter) (const class cPtr_library * inObject,
                                                                          const class GALGAS_string constinArgument0,
                                                                          const class GALGAS_lstring constinArgument1,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getGetter (const int32_t inClassIndex,
                                     enterExtensionGetter_library_getGetter inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlGetter callExtensionGetter_getGetter (const cPtr_library * inObject,
                                                      const GALGAS_string constin_type,
                                                      const GALGAS_lstring constin_name,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Pointer class for @gtlGetter class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlGetter : public cPtr_gtlFunction {
//--- Attributes
  public : GALGAS_type mAttribute_targetType ;

//--- Constructor
  public : cPtr_gtlGetter (const GALGAS_location & in_where,
                           const GALGAS_lstring & in_name,
                           const GALGAS_gtlArgumentList & in_formalArguments,
                           const GALGAS_gtlInstructionList & in_instructions,
                           const GALGAS_lstring & in_returnVariable,
                           const GALGAS_type & in_targetType
                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_type getter_targetType (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension setter '@library putGetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_library_putGetter) (class cPtr_library * inObject,
                                                            const class GALGAS_lstring constinArgument0,
                                                            const class GALGAS_gtlGetter constinArgument1,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_putGetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putGetter inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_putGetter (class cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlGetter constin_aGetter,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@library setterExists'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_library_setterExists) (const class cPtr_library * inObject,
                                                                        const class GALGAS_string constinArgument0,
                                                                        const class GALGAS_lstring constinArgument1,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_setterExists (const int32_t inClassIndex,
                                        enterExtensionGetter_library_setterExists inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_setterExists (const cPtr_library * inObject,
                                                    const GALGAS_string constin_type,
                                                    const GALGAS_lstring constin_name,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@library getSetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlSetter (*enterExtensionGetter_library_getSetter) (const class cPtr_library * inObject,
                                                                          const class GALGAS_string constinArgument0,
                                                                          const class GALGAS_lstring constinArgument1,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getSetter (const int32_t inClassIndex,
                                     enterExtensionGetter_library_getSetter inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlSetter callExtensionGetter_getSetter (const cPtr_library * inObject,
                                                      const GALGAS_string constin_type,
                                                      const GALGAS_lstring constin_name,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Pointer class for @gtlSetter class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlSetter : public cPtr_gtlExecutableEntity {
//--- Attributes
  public : GALGAS_type mAttribute_targetType ;

//--- Constructor
  public : cPtr_gtlSetter (const GALGAS_location & in_where,
                           const GALGAS_lstring & in_name,
                           const GALGAS_gtlArgumentList & in_formalArguments,
                           const GALGAS_gtlInstructionList & in_instructions,
                           const GALGAS_type & in_targetType
                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_type getter_targetType (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension setter '@library putSetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_library_putSetter) (class cPtr_library * inObject,
                                                            const class GALGAS_lstring constinArgument0,
                                                            const class GALGAS_gtlSetter constinArgument1,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_putSetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putSetter inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_putSetter (class cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlSetter constin_aSetter,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@library hasImport'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_library_hasImport) (const class cPtr_library * inObject,
                                                                     const class GALGAS_string constinArgument0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasImport (const int32_t inClassIndex,
                                     enterExtensionGetter_library_hasImport inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_hasImport (const cPtr_library * inObject,
                                                 const GALGAS_string constin_importPath,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension setter '@library doImport'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_library_doImport) (class cPtr_library * inObject,
                                                           const class GALGAS_string constinArgument0,
                                                           class C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_doImport (const int32_t inClassIndex,
                                    extensionSetterSignature_library_doImport inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_doImport (class cPtr_library * inObject,
                                   const GALGAS_string constin_importPath,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@library getTemplate'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_library_getTemplate) (class cPtr_library * inObject,
                                                              const class GALGAS_gtlContext constinArgument0,
                                                              class GALGAS_lstring inArgument1,
                                                              class GALGAS_bool inArgument2,
                                                              class GALGAS_library & ioArgument3,
                                                              class GALGAS_bool & outArgument4,
                                                              class GALGAS_gtlTemplate & outArgument5,
                                                              class C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_getTemplate (const int32_t inClassIndex,
                                       extensionSetterSignature_library_getTemplate inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_getTemplate (class cPtr_library * inObject,
                                      const GALGAS_gtlContext constin_context,
                                      GALGAS_lstring in_path,
                                      GALGAS_bool in_ifExists,
                                      GALGAS_library & io_lib,
                                      GALGAS_bool & out_found,
                                      GALGAS_gtlTemplate & out_result,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension getter '@gtlVarItemField lstringPath'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_lstring (*enterExtensionGetter_gtlVarItemField_lstringPath) (const class cPtr_gtlVarItemField * inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_lstringPath (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlVarItemField_lstringPath inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring callExtensionGetter_lstringPath (const cPtr_gtlVarItemField * inObject,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlExpression location'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_location (*enterExtensionGetter_gtlExpression_location) (const class cPtr_gtlExpression * inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_location (const int32_t inClassIndex,
                                    enterExtensionGetter_gtlExpression_location inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_location callExtensionGetter_location (const cPtr_gtlExpression * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Abstract extension getter '@gtlExpression eval'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlExpression_eval) (const class cPtr_gtlExpression * inObject,
                                                                         const class GALGAS_gtlContext constinArgument0,
                                                                         const class GALGAS_gtlData constinArgument1,
                                                                         const class GALGAS_library constinArgument2,
                                                                         class C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_eval (const int32_t inClassIndex,
                                enterExtensionGetter_gtlExpression_eval inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_eval (const class cPtr_gtlExpression * inObject,
                                               const GALGAS_gtlContext constin_context,
                                               const GALGAS_gtlData constin_vars,
                                               const GALGAS_library constin_lib,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData string'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_string (*enterExtensionGetter_gtlData_string) (const class cPtr_gtlData * inObject,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_string (const int32_t inClassIndex,
                                  enterExtensionGetter_gtlData_string inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string callExtensionGetter_string (const class cPtr_gtlData * inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Abstract extension getter '@gtlData lstring'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_lstring (*enterExtensionGetter_gtlData_lstring) (const class cPtr_gtlData * inObject,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_lstring (const int32_t inClassIndex,
                                   enterExtensionGetter_gtlData_lstring inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring callExtensionGetter_lstring (const class cPtr_gtlData * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData int'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bigint (*enterExtensionGetter_gtlData_int) (const class cPtr_gtlData * inObject,
                                                                 class C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_int (const int32_t inClassIndex,
                               enterExtensionGetter_gtlData_int inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bigint callExtensionGetter_int (const class cPtr_gtlData * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData float'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_double (*enterExtensionGetter_gtlData_float) (const class cPtr_gtlData * inObject,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_float (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_float inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_double callExtensionGetter_float (const class cPtr_gtlData * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData plusOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_plusOp) (const class cPtr_gtlData * inObject,
                                                                     class C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_plusOp (const int32_t inClassIndex,
                                  enterExtensionGetter_gtlData_plusOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_plusOp (const class cPtr_gtlData * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Abstract extension getter '@gtlData minusOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_minusOp) (const class cPtr_gtlData * inObject,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_minusOp (const int32_t inClassIndex,
                                   enterExtensionGetter_gtlData_minusOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_minusOp (const class cPtr_gtlData * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData notOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_notOp) (const class cPtr_gtlData * inObject,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_notOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_notOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_notOp (const class cPtr_gtlData * inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData addOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_addOp) (const class cPtr_gtlData * inObject,
                                                                    const class GALGAS_gtlData constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_addOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_addOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_addOp (const class cPtr_gtlData * inObject,
                                                const GALGAS_gtlData constin_right,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData subOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_subOp) (const class cPtr_gtlData * inObject,
                                                                    const class GALGAS_gtlData constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_subOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_subOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_subOp (const class cPtr_gtlData * inObject,
                                                const GALGAS_gtlData constin_right,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData mulOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_mulOp) (const class cPtr_gtlData * inObject,
                                                                    const class GALGAS_gtlData constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_mulOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_mulOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_mulOp (const class cPtr_gtlData * inObject,
                                                const GALGAS_gtlData constin_right,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData divOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_divOp) (const class cPtr_gtlData * inObject,
                                                                    const class GALGAS_gtlData constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_divOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_divOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_divOp (const class cPtr_gtlData * inObject,
                                                const GALGAS_gtlData constin_right,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData modOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_modOp) (const class cPtr_gtlData * inObject,
                                                                    const class GALGAS_gtlData constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_modOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_modOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_modOp (const class cPtr_gtlData * inObject,
                                                const GALGAS_gtlData constin_right,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData andOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_andOp) (const class cPtr_gtlData * inObject,
                                                                    const class GALGAS_gtlData constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_andOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_andOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_andOp (const class cPtr_gtlData * inObject,
                                                const GALGAS_gtlData constin_right,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData orOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_orOp) (const class cPtr_gtlData * inObject,
                                                                   const class GALGAS_gtlData constinArgument0,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_orOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_orOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_orOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData xorOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_xorOp) (const class cPtr_gtlData * inObject,
                                                                    const class GALGAS_gtlData constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_xorOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_xorOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_xorOp (const class cPtr_gtlData * inObject,
                                                const GALGAS_gtlData constin_right,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData slOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_slOp) (const class cPtr_gtlData * inObject,
                                                                   const class GALGAS_gtlData constinArgument0,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_slOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_slOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_slOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData srOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_srOp) (const class cPtr_gtlData * inObject,
                                                                   const class GALGAS_gtlData constinArgument0,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_srOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_srOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_srOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData neqOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_neqOp) (const class cPtr_gtlData * inObject,
                                                                    const class GALGAS_gtlData constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_neqOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_neqOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_neqOp (const class cPtr_gtlData * inObject,
                                                const GALGAS_gtlData constin_right,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData eqOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_eqOp) (const class cPtr_gtlData * inObject,
                                                                   const class GALGAS_gtlData constinArgument0,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_eqOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_eqOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_eqOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData leOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_leOp) (const class cPtr_gtlData * inObject,
                                                                   const class GALGAS_gtlData constinArgument0,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_leOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_leOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_leOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData geOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_geOp) (const class cPtr_gtlData * inObject,
                                                                   const class GALGAS_gtlData constinArgument0,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_geOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_geOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_geOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Abstract extension getter '@gtlData embeddedType'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_type (*enterExtensionGetter_gtlData_embeddedType) (const class cPtr_gtlData * inObject,
                                                                        class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_embeddedType (const int32_t inClassIndex,
                                        enterExtensionGetter_gtlData_embeddedType inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_type callExtensionGetter_embeddedType (const class cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Abstract extension method '@gtlData addMyValue'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlData_addMyValue) (const class cPtr_gtlData * inObject,
                                                             class GALGAS_objectlist & ioArgument0,
                                                             class C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_addMyValue (const int32_t inClassIndex,
                                      extensionMethodSignature_gtlData_addMyValue inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_addMyValue (const class cPtr_gtlData * inObject,
                                     GALGAS_objectlist & io_objectList,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract extension getter '@gtlData performGetter'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_performGetter) (const class cPtr_gtlData * inObject,
                                                                            const class GALGAS_lstring constinArgument0,
                                                                            const class GALGAS_gtlDataList constinArgument1,
                                                                            const class GALGAS_gtlContext constinArgument2,
                                                                            const class GALGAS_library constinArgument3,
                                                                            class C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_performGetter (const int32_t inClassIndex,
                                         enterExtensionGetter_gtlData_performGetter inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_performGetter (const class cPtr_gtlData * inObject,
                                                        const GALGAS_lstring constin_methodName,
                                                        const GALGAS_gtlDataList constin_arguments,
                                                        const GALGAS_gtlContext constin_context,
                                                        const GALGAS_library constin_lib,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract extension setter '@gtlData performSetter'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_gtlData_performSetter) (class cPtr_gtlData * inObject,
                                                                const class GALGAS_lstring constinArgument0,
                                                                const class GALGAS_gtlDataList constinArgument1,
                                                                const class GALGAS_gtlContext constinArgument2,
                                                                const class GALGAS_library constinArgument3,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_performSetter (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlData_performSetter inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_performSetter (class cPtr_gtlData * inObject,
                                        const GALGAS_lstring constin_methodName,
                                        const GALGAS_gtlDataList constin_arguments,
                                        const GALGAS_gtlContext constin_context,
                                        const GALGAS_library constin_lib,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension method '@gtlData structField'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlData_structField) (const class cPtr_gtlData * inObject,
                                                              const class GALGAS_lstring constinArgument0,
                                                              class GALGAS_gtlData & outArgument1,
                                                              class C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_structField (const int32_t inClassIndex,
                                       extensionMethodSignature_gtlData_structField inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_structField (const class cPtr_gtlData * inObject,
                                      const GALGAS_lstring constin_name,
                                      GALGAS_gtlData & out_result,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlData resultField'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_resultField) (const class cPtr_gtlData * inObject,
                                                                          const class GALGAS_lstring constinArgument0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_resultField (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlData_resultField inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_resultField (const cPtr_gtlData * inObject,
                                                      const GALGAS_lstring constin_name,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension setter '@gtlData setStructFieldAtLevel'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_gtlData_setStructFieldAtLevel) (class cPtr_gtlData * inObject,
                                                                        const class GALGAS_lstring constinArgument0,
                                                                        const class GALGAS_gtlData constinArgument1,
                                                                        const class GALGAS_uint constinArgument2,
                                                                        class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setStructFieldAtLevel (const int32_t inClassIndex,
                                                 extensionSetterSignature_gtlData_setStructFieldAtLevel inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setStructFieldAtLevel (class cPtr_gtlData * inObject,
                                                const GALGAS_lstring constin_name,
                                                const GALGAS_gtlData constin_data,
                                                const GALGAS_uint constin_level,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlData deleteStructField'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_gtlData_deleteStructField) (class cPtr_gtlData * inObject,
                                                                    const class GALGAS_lstring constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteStructField (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlData_deleteStructField inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteStructField (class cPtr_gtlData * inObject,
                                            const GALGAS_lstring constin_name,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlData hasStructField'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_gtlData_hasStructField) (const class cPtr_gtlData * inObject,
                                                                          const class GALGAS_lstring constinArgument0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasStructField (const int32_t inClassIndex,
                                          enterExtensionGetter_gtlData_hasStructField inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_hasStructField (const cPtr_gtlData * inObject,
                                                      const GALGAS_lstring constin_name,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlData overrideMap'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlStruct (*enterExtensionGetter_gtlData_overrideMap) (const class cPtr_gtlData * inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_overrideMap (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlData_overrideMap inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlStruct callExtensionGetter_overrideMap (const cPtr_gtlData * inObject,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@gtlData overriddenMap'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlStruct (*enterExtensionGetter_gtlData_overriddenMap) (const class cPtr_gtlData * inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_overriddenMap (const int32_t inClassIndex,
                                         enterExtensionGetter_gtlData_overriddenMap inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlStruct callExtensionGetter_overriddenMap (const cPtr_gtlData * inObject,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Extension method '@gtlData mapItem'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlData_mapItem) (const class cPtr_gtlData * inObject,
                                                          const class GALGAS_lstring constinArgument0,
                                                          class GALGAS_gtlData & outArgument1,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_mapItem (const int32_t inClassIndex,
                                   extensionMethodSignature_gtlData_mapItem inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_mapItem (const class cPtr_gtlData * inObject,
                                  const GALGAS_lstring constin_name,
                                  GALGAS_gtlData & out_result,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlData hasMapItem'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_gtlData_hasMapItem) (const class cPtr_gtlData * inObject,
                                                                      const class GALGAS_lstring constinArgument0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasMapItem (const int32_t inClassIndex,
                                      enterExtensionGetter_gtlData_hasMapItem inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_hasMapItem (const cPtr_gtlData * inObject,
                                                  const GALGAS_lstring constin_name,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@gtlData setMapItem'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_gtlData_setMapItem) (class cPtr_gtlData * inObject,
                                                             const class GALGAS_lstring constinArgument0,
                                                             const class GALGAS_gtlData constinArgument1,
                                                             class C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setMapItem (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlData_setMapItem inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setMapItem (class cPtr_gtlData * inObject,
                                     const GALGAS_lstring constin_name,
                                     const GALGAS_gtlData constin_data,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension setter '@gtlData deleteMapItem'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_gtlData_deleteMapItem) (class cPtr_gtlData * inObject,
                                                                const class GALGAS_lstring constinArgument0,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteMapItem (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlData_deleteMapItem inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteMapItem (class cPtr_gtlData * inObject,
                                        const GALGAS_lstring constin_name,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension method '@gtlData itemAtIndex'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlData_itemAtIndex) (const class cPtr_gtlData * inObject,
                                                              class GALGAS_gtlData & outArgument0,
                                                              const class GALGAS_gtlInt constinArgument1,
                                                              class C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_itemAtIndex (const int32_t inClassIndex,
                                       extensionMethodSignature_gtlData_itemAtIndex inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_itemAtIndex (const class cPtr_gtlData * inObject,
                                      GALGAS_gtlData & out_result,
                                      const GALGAS_gtlInt constin_index,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlData hasItemAtIndex'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_gtlData_hasItemAtIndex) (const class cPtr_gtlData * inObject,
                                                                          const class GALGAS_gtlInt constinArgument0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasItemAtIndex (const int32_t inClassIndex,
                                          enterExtensionGetter_gtlData_hasItemAtIndex inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_hasItemAtIndex (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlInt constin_index,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension setter '@gtlData setItemAtIndex'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_gtlData_setItemAtIndex) (class cPtr_gtlData * inObject,
                                                                 const class GALGAS_gtlData constinArgument0,
                                                                 const class GALGAS_gtlInt constinArgument1,
                                                                 class C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setItemAtIndex (const int32_t inClassIndex,
                                          extensionSetterSignature_gtlData_setItemAtIndex inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setItemAtIndex (class cPtr_gtlData * inObject,
                                         const GALGAS_gtlData constin_data,
                                         const GALGAS_gtlInt constin_index,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlData deleteItemAtIndex'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_gtlData_deleteItemAtIndex) (class cPtr_gtlData * inObject,
                                                                    const class GALGAS_gtlInt constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteItemAtIndex (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlData_deleteItemAtIndex inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteItemAtIndex (class cPtr_gtlData * inObject,
                                            const GALGAS_gtlInt constin_index,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@gtlData appendItem'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_gtlData_appendItem) (class cPtr_gtlData * inObject,
                                                             const class GALGAS_gtlData constinArgument0,
                                                             class C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_appendItem (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlData_appendItem inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_appendItem (class cPtr_gtlData * inObject,
                                     const GALGAS_gtlData constin_item,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension method '@gtlExecutableEntity checkArguments'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlExecutableEntity_checkArguments) (const class cPtr_gtlExecutableEntity * inObject,
                                                                             const class GALGAS_location constinArgument0,
                                                                             const class GALGAS_gtlDataList constinArgument1,
                                                                             class GALGAS_gtlData & outArgument2,
                                                                             class GALGAS_bool & outArgument3,
                                                                             class C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_checkArguments (const int32_t inClassIndex,
                                          extensionMethodSignature_gtlExecutableEntity_checkArguments inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_checkArguments (const class cPtr_gtlExecutableEntity * inObject,
                                         const GALGAS_location constin_fromLocation,
                                         const GALGAS_gtlDataList constin_actualArguments,
                                         GALGAS_gtlData & out_entityVariableMap,
                                         GALGAS_bool & out_result,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Pointer class for @gtlProcedure class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlProcedure : public cPtr_gtlExecutableEntity {
//--- Attributes

//--- Constructor
  public : cPtr_gtlProcedure (const GALGAS_location & in_where,
                              const GALGAS_lstring & in_name,
                              const GALGAS_gtlArgumentList & in_formalArguments,
                              const GALGAS_gtlInstructionList & in_instructions
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
//                                        Extension method '@gtlProcedure call'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlProcedure_call) (const class cPtr_gtlProcedure * inObject,
                                                            class GALGAS_gtlContext & ioArgument0,
                                                            class GALGAS_library & ioArgument1,
                                                            class GALGAS_string & ioArgument2,
                                                            const class GALGAS_location constinArgument3,
                                                            const class GALGAS_gtlDataList constinArgument4,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_call (const int32_t inClassIndex,
                                extensionMethodSignature_gtlProcedure_call inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_call (const class cPtr_gtlProcedure * inObject,
                               GALGAS_gtlContext & io_context,
                               GALGAS_library & io_lib,
                               GALGAS_string & io_outputString,
                               const GALGAS_location constin_fromLocation,
                               const GALGAS_gtlDataList constin_actualArguments,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@gtlFunction call'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlFunction_call) (const class cPtr_gtlFunction * inObject,
                                                                       const class GALGAS_location constinArgument0,
                                                                       class GALGAS_gtlContext inArgument1,
                                                                       class GALGAS_library inArgument2,
                                                                       const class GALGAS_gtlDataList constinArgument3,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_call (const int32_t inClassIndex,
                                enterExtensionGetter_gtlFunction_call inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_call (const cPtr_gtlFunction * inObject,
                                               const GALGAS_location constin_fromLocation,
                                               GALGAS_gtlContext in_context,
                                               GALGAS_library in_lib,
                                               const GALGAS_gtlDataList constin_actualArguments,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@gtlGetter callGetter'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlGetter_callGetter) (const class cPtr_gtlGetter * inObject,
                                                                           const class GALGAS_location constinArgument0,
                                                                           class GALGAS_gtlContext inArgument1,
                                                                           class GALGAS_library inArgument2,
                                                                           const class GALGAS_gtlData constinArgument3,
                                                                           const class GALGAS_gtlDataList constinArgument4,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_callGetter (const int32_t inClassIndex,
                                      enterExtensionGetter_gtlGetter_callGetter inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_callGetter (const cPtr_gtlGetter * inObject,
                                                     const GALGAS_location constin_fromLocation,
                                                     GALGAS_gtlContext in_context,
                                                     GALGAS_library in_lib,
                                                     const GALGAS_gtlData constin_target,
                                                     const GALGAS_gtlDataList constin_actualArguments,
                                                     class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlGetter typedName'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_lstring (*enterExtensionGetter_gtlGetter_typedName) (const class cPtr_gtlGetter * inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_typedName (const int32_t inClassIndex,
                                     enterExtensionGetter_gtlGetter_typedName inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring callExtensionGetter_typedName (const cPtr_gtlGetter * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension method '@gtlSetter callSetter'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlSetter_callSetter) (const class cPtr_gtlSetter * inObject,
                                                               const class GALGAS_location constinArgument0,
                                                               class GALGAS_gtlContext inArgument1,
                                                               class GALGAS_library inArgument2,
                                                               class GALGAS_gtlData & ioArgument3,
                                                               const class GALGAS_gtlDataList constinArgument4,
                                                               class C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_callSetter (const int32_t inClassIndex,
                                      extensionMethodSignature_gtlSetter_callSetter inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_callSetter (const class cPtr_gtlSetter * inObject,
                                     const GALGAS_location constin_fromLocation,
                                     GALGAS_gtlContext in_context,
                                     GALGAS_library in_lib,
                                     GALGAS_gtlData & io_target,
                                     const GALGAS_gtlDataList constin_actualArguments,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlSetter typedName'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_lstring (*enterExtensionGetter_gtlSetter_typedName) (const class cPtr_gtlSetter * inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_typedName (const int32_t inClassIndex,
                                     enterExtensionGetter_gtlSetter_typedName inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring callExtensionGetter_typedName (const cPtr_gtlSetter * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlModule class                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlModule : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_gtlModule (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlModule constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlModule * ptr (void) const { return (const cPtr_gtlModule *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlModule (const cPtr_gtlModule * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlModule extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlModule constructor_new (const class GALGAS_lstring & inOperand0,
                                                          const class GALGAS_gtlProcMap & inOperand1,
                                                          const class GALGAS_gtlFuncMap & inOperand2
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlModule & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlFuncMap getter_functions (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_name (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlProcMap getter_procedures (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlModule class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlModule ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Pointer class for @gtlModule class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlModule : public acPtr_class {
//--- Attributes
  public : GALGAS_lstring mAttribute_name ;
  public : GALGAS_gtlProcMap mAttribute_procedures ;
  public : GALGAS_gtlFuncMap mAttribute_functions ;

//--- Constructor
  public : cPtr_gtlModule (const GALGAS_lstring & in_name,
                           const GALGAS_gtlProcMap & in_procedures,
                           const GALGAS_gtlFuncMap & in_functions
                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_name (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlProcMap getter_procedures (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlFuncMap getter_functions (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

#endif
