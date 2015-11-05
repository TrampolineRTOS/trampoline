#ifndef all_2D_declarations_2D__34__ENTITIES_DEFINED
#define all_2D_declarations_2D__34__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-3.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Category getter '@enumValues mergeWithEnum' (as function)                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_enumValues extensionGetter_mergeWithEnum (const class GALGAS_enumValues & inObject,
                                                       const class GALGAS_enumValues & constinArgument0,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//          Category getter '@implementationObjectMap mergeImplementationObjectAttributesWith' (as function)           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_implementationObjectMap extensionGetter_mergeImplementationObjectAttributesWith (const class GALGAS_implementationObjectMap & inObject,
                                                                                              const class GALGAS_implementationObjectMap & constinArgument0,
                                                                                              class C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Category getter '@implementation hasLKey'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*categoryGetterSignature_implementation_hasLKey) (const class cPtr_implementation * inObject,
                                                                             const class GALGAS_lstring & constinArgument0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryGetter_hasLKey (const int32_t inClassIndex,
                                  categoryGetterSignature_implementation_hasLKey inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callCategoryGetter_hasLKey (const cPtr_implementation * inObject,
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
//                                  Abstract category getter '@impType mergeWithType'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_impType (*categoryGetterSignature_impType_mergeWithType) (const class cPtr_impType * inObject,
                                                                               class GALGAS_impType inArgument0,
                                                                               class C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryGetter_mergeWithType (const int32_t inClassIndex,
                                        categoryGetterSignature_impType_mergeWithType inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_impType callCategoryGetter_mergeWithType (const class cPtr_impType * inObject,
                                                       GALGAS_impType in_typeToMerge,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Category getter '@objectAttributes fieldMap'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_TfieldMap (*categoryGetterSignature_objectAttributes_fieldMap) (const class cPtr_objectAttributes * inObject,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryGetter_fieldMap (const int32_t inClassIndex,
                                   categoryGetterSignature_objectAttributes_fieldMap inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TfieldMap callCategoryGetter_fieldMap (const cPtr_objectAttributes * inObject,
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
//                          Category getter '@applicationDefinition applicationWithDefaults'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_applicationDefinition (*categoryGetterSignature_applicationDefinition_applicationWithDefaults) (const class cPtr_applicationDefinition * inObject,
                                                                                                                     const class GALGAS_implementation & constinArgument0,
                                                                                                                     C_Compiler * inCompiler
                                                                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryGetter_applicationWithDefaults (const int32_t inClassIndex,
                                                  categoryGetterSignature_applicationDefinition_applicationWithDefaults inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_applicationDefinition callCategoryGetter_applicationWithDefaults (const cPtr_applicationDefinition * inObject,
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
