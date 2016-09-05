#ifndef all_2D_declarations_2D__34__ENTITIES_DEFINED
#define all_2D_declarations_2D__34__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "all-predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-3.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlEmitInstruction class                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlEmitInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlEmitInstruction (void) ;

//---
  public : inline const class cPtr_gtlEmitInstruction * ptr (void) const { return (const cPtr_gtlEmitInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlEmitInstruction (const cPtr_gtlEmitInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlEmitInstruction extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlEmitInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                   const class GALGAS_string & inOperand1,
                                                                   const class GALGAS_gtlExpression & inOperand2
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlEmitInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_rValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlEmitInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlEmitInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @gtlEmitInstruction class                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlEmitInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlExpression mAttribute_rValue ;

//--- Constructor
  public : cPtr_gtlEmitInstruction (const GALGAS_location & in_where,
                                    const GALGAS_string & in_signature,
                                    const GALGAS_gtlExpression & in_rValue
                                    COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_rValue (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlWriteToInstruction class                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlWriteToInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlWriteToInstruction (void) ;

//---
  public : inline const class cPtr_gtlWriteToInstruction * ptr (void) const { return (const cPtr_gtlWriteToInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlWriteToInstruction (const cPtr_gtlWriteToInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlWriteToInstruction extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlWriteToInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                      const class GALGAS_string & inOperand1,
                                                                      const class GALGAS_gtlExpression & inOperand2,
                                                                      const class GALGAS_bool & inOperand3,
                                                                      const class GALGAS_gtlInstructionList & inOperand4
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlWriteToInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_fileNameExpression (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_instructions (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isExecutable (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlWriteToInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlWriteToInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Pointer class for @gtlWriteToInstruction class                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlWriteToInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlExpression mAttribute_fileNameExpression ;
  public : GALGAS_bool mAttribute_isExecutable ;
  public : GALGAS_gtlInstructionList mAttribute_instructions ;

//--- Constructor
  public : cPtr_gtlWriteToInstruction (const GALGAS_location & in_where,
                                       const GALGAS_string & in_signature,
                                       const GALGAS_gtlExpression & in_fileNameExpression,
                                       const GALGAS_bool & in_isExecutable,
                                       const GALGAS_gtlInstructionList & in_instructions
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_fileNameExpression (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_isExecutable (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_instructions (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlTemplateInstruction class                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlTemplateInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlTemplateInstruction (void) ;

//---
  public : inline const class cPtr_gtlTemplateInstruction * ptr (void) const { return (const cPtr_gtlTemplateInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlTemplateInstruction (const cPtr_gtlTemplateInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlTemplateInstruction extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlTemplateInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                       const class GALGAS_string & inOperand1,
                                                                       const class GALGAS_lstring & inOperand2,
                                                                       const class GALGAS_gtlExpression & inOperand3,
                                                                       const class GALGAS_bool & inOperand4,
                                                                       const class GALGAS_bool & inOperand5,
                                                                       const class GALGAS_gtlExpressionList & inOperand6,
                                                                       const class GALGAS_gtlInstructionList & inOperand7
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlTemplateInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpressionList getter_arguments (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_fileName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_ifExists (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_instructionsIfNotFound (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isGlobal (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_prefix (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlTemplateInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTemplateInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Pointer class for @gtlTemplateInstruction class                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlTemplateInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_lstring mAttribute_prefix ;
  public : GALGAS_gtlExpression mAttribute_fileName ;
  public : GALGAS_bool mAttribute_ifExists ;
  public : GALGAS_bool mAttribute_isGlobal ;
  public : GALGAS_gtlExpressionList mAttribute_arguments ;
  public : GALGAS_gtlInstructionList mAttribute_instructionsIfNotFound ;

//--- Constructor
  public : cPtr_gtlTemplateInstruction (const GALGAS_location & in_where,
                                        const GALGAS_string & in_signature,
                                        const GALGAS_lstring & in_prefix,
                                        const GALGAS_gtlExpression & in_fileName,
                                        const GALGAS_bool & in_ifExists,
                                        const GALGAS_bool & in_isGlobal,
                                        const GALGAS_gtlExpressionList & in_arguments,
                                        const GALGAS_gtlInstructionList & in_instructionsIfNotFound
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_prefix (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_fileName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_ifExists (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_isGlobal (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_arguments (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_instructionsIfNotFound (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @gtlForeachStatementInstruction class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlForeachStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlForeachStatementInstruction (void) ;

//---
  public : inline const class cPtr_gtlForeachStatementInstruction * ptr (void) const { return (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlForeachStatementInstruction (const cPtr_gtlForeachStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlForeachStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlForeachStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                               const class GALGAS_string & inOperand1,
                                                                               const class GALGAS_lstring & inOperand2,
                                                                               const class GALGAS_lstring & inOperand3,
                                                                               const class GALGAS_lstring & inOperand4,
                                                                               const class GALGAS_gtlExpression & inOperand5,
                                                                               const class GALGAS_gtlInstructionList & inOperand6,
                                                                               const class GALGAS_gtlInstructionList & inOperand7,
                                                                               const class GALGAS_gtlInstructionList & inOperand8,
                                                                               const class GALGAS_gtlInstructionList & inOperand9
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlForeachStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_afterList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_beforeList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_indexName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_iterable (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_keyName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_variableName (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlForeachStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlForeachStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Pointer class for @gtlForeachStatementInstruction class                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlForeachStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_lstring mAttribute_keyName ;
  public : GALGAS_lstring mAttribute_variableName ;
  public : GALGAS_lstring mAttribute_indexName ;
  public : GALGAS_gtlExpression mAttribute_iterable ;
  public : GALGAS_gtlInstructionList mAttribute_beforeList ;
  public : GALGAS_gtlInstructionList mAttribute_betweenList ;
  public : GALGAS_gtlInstructionList mAttribute_afterList ;
  public : GALGAS_gtlInstructionList mAttribute_doList ;

//--- Constructor
  public : cPtr_gtlForeachStatementInstruction (const GALGAS_location & in_where,
                                                const GALGAS_string & in_signature,
                                                const GALGAS_lstring & in_keyName,
                                                const GALGAS_lstring & in_variableName,
                                                const GALGAS_lstring & in_indexName,
                                                const GALGAS_gtlExpression & in_iterable,
                                                const GALGAS_gtlInstructionList & in_beforeList,
                                                const GALGAS_gtlInstructionList & in_betweenList,
                                                const GALGAS_gtlInstructionList & in_afterList,
                                                const GALGAS_gtlInstructionList & in_doList
                                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_keyName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_variableName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_indexName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_iterable (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_beforeList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_afterList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Extension method '@gtlForeachStatementInstruction iterateOnMap'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlForeachStatementInstruction_iterateOnMap) (const class cPtr_gtlForeachStatementInstruction * inObject,
                                                                                      class GALGAS_gtlContext & ioArgument0,
                                                                                      class GALGAS_gtlData & ioArgument1,
                                                                                      class GALGAS_library & ioArgument2,
                                                                                      class GALGAS_string & ioArgument3,
                                                                                      const class GALGAS_gtlMap constinArgument4,
                                                                                      class C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_iterateOnMap (const int32_t inClassIndex,
                                        extensionMethodSignature_gtlForeachStatementInstruction_iterateOnMap inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_iterateOnMap (const class cPtr_gtlForeachStatementInstruction * inObject,
                                       GALGAS_gtlContext & io_context,
                                       GALGAS_gtlData & io_vars,
                                       GALGAS_library & io_lib,
                                       GALGAS_string & io_outputString,
                                       const GALGAS_gtlMap constin_iterableMap,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Extension method '@gtlForeachStatementInstruction iterateOnList'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlForeachStatementInstruction_iterateOnList) (const class cPtr_gtlForeachStatementInstruction * inObject,
                                                                                       class GALGAS_gtlContext & ioArgument0,
                                                                                       class GALGAS_gtlData & ioArgument1,
                                                                                       class GALGAS_library & ioArgument2,
                                                                                       class GALGAS_string & ioArgument3,
                                                                                       const class GALGAS_gtlList constinArgument4,
                                                                                       class C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_iterateOnList (const int32_t inClassIndex,
                                         extensionMethodSignature_gtlForeachStatementInstruction_iterateOnList inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_iterateOnList (const class cPtr_gtlForeachStatementInstruction * inObject,
                                        GALGAS_gtlContext & io_context,
                                        GALGAS_gtlData & io_vars,
                                        GALGAS_library & io_lib,
                                        GALGAS_string & io_outputString,
                                        const GALGAS_gtlList constin_iterableList,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Extension method '@gtlForeachStatementInstruction iterateOnSet'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlForeachStatementInstruction_iterateOnSet) (const class cPtr_gtlForeachStatementInstruction * inObject,
                                                                                      class GALGAS_gtlContext & ioArgument0,
                                                                                      class GALGAS_gtlData & ioArgument1,
                                                                                      class GALGAS_library & ioArgument2,
                                                                                      class GALGAS_string & ioArgument3,
                                                                                      const class GALGAS_gtlSet constinArgument4,
                                                                                      class C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_iterateOnSet (const int32_t inClassIndex,
                                        extensionMethodSignature_gtlForeachStatementInstruction_iterateOnSet inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_iterateOnSet (const class cPtr_gtlForeachStatementInstruction * inObject,
                                       GALGAS_gtlContext & io_context,
                                       GALGAS_gtlData & io_vars,
                                       GALGAS_library & io_lib,
                                       GALGAS_string & io_outputString,
                                       const GALGAS_gtlSet constin_iterableSet,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlForStatementInstruction class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlForStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlForStatementInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlForStatementInstruction constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlForStatementInstruction * ptr (void) const { return (const cPtr_gtlForStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlForStatementInstruction (const cPtr_gtlForStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlForStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlForStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                           const class GALGAS_string & inOperand1,
                                                                           const class GALGAS_lstring & inOperand2,
                                                                           const class GALGAS_gtlExpressionList & inOperand3,
                                                                           const class GALGAS_gtlInstructionList & inOperand4,
                                                                           const class GALGAS_gtlInstructionList & inOperand5
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlForStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_identifier (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpressionList getter_iterable (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlForStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlForStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Pointer class for @gtlForStatementInstruction class                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlForStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_lstring mAttribute_identifier ;
  public : GALGAS_gtlExpressionList mAttribute_iterable ;
  public : GALGAS_gtlInstructionList mAttribute_betweenList ;
  public : GALGAS_gtlInstructionList mAttribute_doList ;

//--- Constructor
  public : cPtr_gtlForStatementInstruction (const GALGAS_location & in_where,
                                            const GALGAS_string & in_signature,
                                            const GALGAS_lstring & in_identifier,
                                            const GALGAS_gtlExpressionList & in_iterable,
                                            const GALGAS_gtlInstructionList & in_betweenList,
                                            const GALGAS_gtlInstructionList & in_doList
                                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_identifier (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_iterable (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlLoopStatementInstruction class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlLoopStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlLoopStatementInstruction (void) ;

//---
  public : inline const class cPtr_gtlLoopStatementInstruction * ptr (void) const { return (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlLoopStatementInstruction (const cPtr_gtlLoopStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlLoopStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlLoopStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                            const class GALGAS_string & inOperand1,
                                                                            const class GALGAS_lstring & inOperand2,
                                                                            const class GALGAS_gtlExpression & inOperand3,
                                                                            const class GALGAS_gtlExpression & inOperand4,
                                                                            const class GALGAS_gtlExpression & inOperand5,
                                                                            const class GALGAS_sint_36__34_ & inOperand6,
                                                                            const class GALGAS_gtlInstructionList & inOperand7,
                                                                            const class GALGAS_gtlInstructionList & inOperand8,
                                                                            const class GALGAS_gtlInstructionList & inOperand9,
                                                                            const class GALGAS_gtlInstructionList & inOperand10
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlLoopStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_afterList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_beforeList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_identifier (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_start (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_step (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_stop (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_upDown (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlLoopStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLoopStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Pointer class for @gtlLoopStatementInstruction class                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlLoopStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_lstring mAttribute_identifier ;
  public : GALGAS_gtlExpression mAttribute_start ;
  public : GALGAS_gtlExpression mAttribute_stop ;
  public : GALGAS_gtlExpression mAttribute_step ;
  public : GALGAS_sint_36__34_ mAttribute_upDown ;
  public : GALGAS_gtlInstructionList mAttribute_beforeList ;
  public : GALGAS_gtlInstructionList mAttribute_betweenList ;
  public : GALGAS_gtlInstructionList mAttribute_afterList ;
  public : GALGAS_gtlInstructionList mAttribute_doList ;

//--- Constructor
  public : cPtr_gtlLoopStatementInstruction (const GALGAS_location & in_where,
                                             const GALGAS_string & in_signature,
                                             const GALGAS_lstring & in_identifier,
                                             const GALGAS_gtlExpression & in_start,
                                             const GALGAS_gtlExpression & in_stop,
                                             const GALGAS_gtlExpression & in_step,
                                             const GALGAS_sint_36__34_ & in_upDown,
                                             const GALGAS_gtlInstructionList & in_beforeList,
                                             const GALGAS_gtlInstructionList & in_betweenList,
                                             const GALGAS_gtlInstructionList & in_afterList,
                                             const GALGAS_gtlInstructionList & in_doList
                                             COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_identifier (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_start (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_stop (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_step (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ getter_upDown (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_beforeList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_afterList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @gtlRepeatStatementInstruction class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlRepeatStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlRepeatStatementInstruction (void) ;

//---
  public : inline const class cPtr_gtlRepeatStatementInstruction * ptr (void) const { return (const cPtr_gtlRepeatStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlRepeatStatementInstruction (const cPtr_gtlRepeatStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlRepeatStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlRepeatStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                              const class GALGAS_string & inOperand1,
                                                                              const class GALGAS_gtlExpression & inOperand2,
                                                                              const class GALGAS_gtlExpression & inOperand3,
                                                                              const class GALGAS_gtlInstructionList & inOperand4,
                                                                              const class GALGAS_gtlInstructionList & inOperand5
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlRepeatStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_condition (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_continueList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_limit (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlRepeatStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlRepeatStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Pointer class for @gtlRepeatStatementInstruction class                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlRepeatStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlExpression mAttribute_limit ;
  public : GALGAS_gtlExpression mAttribute_condition ;
  public : GALGAS_gtlInstructionList mAttribute_continueList ;
  public : GALGAS_gtlInstructionList mAttribute_doList ;

//--- Constructor
  public : cPtr_gtlRepeatStatementInstruction (const GALGAS_location & in_where,
                                               const GALGAS_string & in_signature,
                                               const GALGAS_gtlExpression & in_limit,
                                               const GALGAS_gtlExpression & in_condition,
                                               const GALGAS_gtlInstructionList & in_continueList,
                                               const GALGAS_gtlInstructionList & in_doList
                                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_limit (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_condition (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_continueList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlErrorStatementInstruction class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlErrorStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlErrorStatementInstruction (void) ;

//---
  public : inline const class cPtr_gtlErrorStatementInstruction * ptr (void) const { return (const cPtr_gtlErrorStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlErrorStatementInstruction (const cPtr_gtlErrorStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlErrorStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlErrorStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                             const class GALGAS_string & inOperand1,
                                                                             const class GALGAS_gtlVarPath & inOperand2,
                                                                             const class GALGAS_bool & inOperand3,
                                                                             const class GALGAS_gtlExpression & inOperand4
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlErrorStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_errorMessage (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_hereInstead (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlVarPath getter_identifier (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlErrorStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlErrorStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Pointer class for @gtlErrorStatementInstruction class                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlErrorStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlVarPath mAttribute_identifier ;
  public : GALGAS_bool mAttribute_hereInstead ;
  public : GALGAS_gtlExpression mAttribute_errorMessage ;

//--- Constructor
  public : cPtr_gtlErrorStatementInstruction (const GALGAS_location & in_where,
                                              const GALGAS_string & in_signature,
                                              const GALGAS_gtlVarPath & in_identifier,
                                              const GALGAS_bool & in_hereInstead,
                                              const GALGAS_gtlExpression & in_errorMessage
                                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_identifier (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_hereInstead (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_errorMessage (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @gtlWarningStatementInstruction class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlWarningStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlWarningStatementInstruction (void) ;

//---
  public : inline const class cPtr_gtlWarningStatementInstruction * ptr (void) const { return (const cPtr_gtlWarningStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlWarningStatementInstruction (const cPtr_gtlWarningStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlWarningStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlWarningStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                               const class GALGAS_string & inOperand1,
                                                                               const class GALGAS_gtlVarPath & inOperand2,
                                                                               const class GALGAS_bool & inOperand3,
                                                                               const class GALGAS_gtlExpression & inOperand4
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlWarningStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_hereInstead (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlVarPath getter_identifier (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_warningMessage (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlWarningStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlWarningStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Pointer class for @gtlWarningStatementInstruction class                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlWarningStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlVarPath mAttribute_identifier ;
  public : GALGAS_bool mAttribute_hereInstead ;
  public : GALGAS_gtlExpression mAttribute_warningMessage ;

//--- Constructor
  public : cPtr_gtlWarningStatementInstruction (const GALGAS_location & in_where,
                                                const GALGAS_string & in_signature,
                                                const GALGAS_gtlVarPath & in_identifier,
                                                const GALGAS_bool & in_hereInstead,
                                                const GALGAS_gtlExpression & in_warningMessage
                                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_identifier (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_hereInstead (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_warningMessage (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlSortStatementInstruction class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlSortStatementInstruction : public GALGAS_gtlAbstractSortInstruction {
//--- Constructor
  public : GALGAS_gtlSortStatementInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlSortStatementInstruction constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlSortStatementInstruction * ptr (void) const { return (const cPtr_gtlSortStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlSortStatementInstruction (const cPtr_gtlSortStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlSortStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlSortStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                            const class GALGAS_string & inOperand1,
                                                                            const class GALGAS_gtlVarPath & inOperand2,
                                                                            const class GALGAS_lsint & inOperand3
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlSortStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lsint getter_order (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlSortStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSortStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Pointer class for @gtlSortStatementInstruction class                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlSortStatementInstruction : public cPtr_gtlAbstractSortInstruction {
//--- Attributes
  public : GALGAS_lsint mAttribute_order ;

//--- Constructor
  public : cPtr_gtlSortStatementInstruction (const GALGAS_location & in_where,
                                             const GALGAS_string & in_signature,
                                             const GALGAS_gtlVarPath & in_variablePath,
                                             const GALGAS_lsint & in_order
                                             COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lsint getter_order (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlTabStatementInstruction class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlTabStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlTabStatementInstruction (void) ;

//---
  public : inline const class cPtr_gtlTabStatementInstruction * ptr (void) const { return (const cPtr_gtlTabStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlTabStatementInstruction (const cPtr_gtlTabStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlTabStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlTabStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                           const class GALGAS_string & inOperand1,
                                                                           const class GALGAS_gtlExpression & inOperand2
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlTabStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_tabValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlTabStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTabStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Pointer class for @gtlTabStatementInstruction class                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlTabStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlExpression mAttribute_tabValue ;

//--- Constructor
  public : cPtr_gtlTabStatementInstruction (const GALGAS_location & in_where,
                                            const GALGAS_string & in_signature,
                                            const GALGAS_gtlExpression & in_tabValue
                                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_tabValue (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlSetterCallInstruction class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlSetterCallInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlSetterCallInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlSetterCallInstruction constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlSetterCallInstruction * ptr (void) const { return (const cPtr_gtlSetterCallInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlSetterCallInstruction (const cPtr_gtlSetterCallInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlSetterCallInstruction extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlSetterCallInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                         const class GALGAS_string & inOperand1,
                                                                         const class GALGAS_gtlVarPath & inOperand2,
                                                                         const class GALGAS_lstring & inOperand3,
                                                                         const class GALGAS_gtlExpressionList & inOperand4
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlSetterCallInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpressionList getter_arguments (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_setterName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlVarPath getter_target (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlSetterCallInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSetterCallInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Pointer class for @gtlSetterCallInstruction class                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlSetterCallInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlVarPath mAttribute_target ;
  public : GALGAS_lstring mAttribute_setterName ;
  public : GALGAS_gtlExpressionList mAttribute_arguments ;

//--- Constructor
  public : cPtr_gtlSetterCallInstruction (const GALGAS_location & in_where,
                                          const GALGAS_string & in_signature,
                                          const GALGAS_gtlVarPath & in_target,
                                          const GALGAS_lstring & in_setterName,
                                          const GALGAS_gtlExpressionList & in_arguments
                                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_target (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_setterName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_arguments (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension setter '@debuggerContext appendInstructionToStepDo'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_debuggerContext_appendInstructionToStepDo) (class cPtr_debuggerContext * inObject,
                                                                                    class GALGAS_gtlInstruction inArgument0,
                                                                                    class C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_appendInstructionToStepDo (const int32_t inClassIndex,
                                                     extensionSetterSignature_debuggerContext_appendInstructionToStepDo inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_appendInstructionToStepDo (class cPtr_debuggerContext * inObject,
                                                    GALGAS_gtlInstruction in_instruction,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension setter '@debuggerContext deleteStepDoInstruction'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_debuggerContext_deleteStepDoInstruction) (class cPtr_debuggerContext * inObject,
                                                                                  const class GALGAS_lbigint constinArgument0,
                                                                                  class C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteStepDoInstruction (const int32_t inClassIndex,
                                                   extensionSetterSignature_debuggerContext_deleteStepDoInstruction inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteStepDoInstruction (class cPtr_debuggerContext * inObject,
                                                  const GALGAS_lbigint constin_numToDelete,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Extension setter '@debuggerContext deleteAllStepDoInstructions'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_debuggerContext_deleteAllStepDoInstructions) (class cPtr_debuggerContext * inObject,
                                                                                      class C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteAllStepDoInstructions (const int32_t inClassIndex,
                                                       extensionSetterSignature_debuggerContext_deleteAllStepDoInstructions inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteAllStepDoInstructions (class cPtr_debuggerContext * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension method '@debuggerContext listStepDoInstructions'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_debuggerContext_listStepDoInstructions) (const class cPtr_debuggerContext * inObject,
                                                                                 class C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_listStepDoInstructions (const int32_t inClassIndex,
                                                  extensionMethodSignature_debuggerContext_listStepDoInstructions inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_listStepDoInstructions (const class cPtr_debuggerContext * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension setter '@debuggerContext setBreakpoint'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_debuggerContext_setBreakpoint) (class cPtr_debuggerContext * inObject,
                                                                        const class GALGAS_string constinArgument0,
                                                                        const class GALGAS_uint constinArgument1,
                                                                        class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setBreakpoint (const int32_t inClassIndex,
                                         extensionSetterSignature_debuggerContext_setBreakpoint inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setBreakpoint (class cPtr_debuggerContext * inObject,
                                        const GALGAS_string constin_fileName,
                                        const GALGAS_uint constin_lineNum,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@debuggerContext listBreakpoints'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_debuggerContext_listBreakpoints) (const class cPtr_debuggerContext * inObject,
                                                                          class C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_listBreakpoints (const int32_t inClassIndex,
                                           extensionMethodSignature_debuggerContext_listBreakpoints inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_listBreakpoints (const class cPtr_debuggerContext * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension setter '@debuggerContext deleteBreakpoint'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_debuggerContext_deleteBreakpoint) (class cPtr_debuggerContext * inObject,
                                                                           const class GALGAS_lbigint constinArgument0,
                                                                           class C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteBreakpoint (const int32_t inClassIndex,
                                            extensionSetterSignature_debuggerContext_deleteBreakpoint inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteBreakpoint (class cPtr_debuggerContext * inObject,
                                           const GALGAS_lbigint constin_numToDelete,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension setter '@debuggerContext deleteAllBreakpoints'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_debuggerContext_deleteAllBreakpoints) (class cPtr_debuggerContext * inObject,
                                                                               class C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteAllBreakpoints (const int32_t inClassIndex,
                                                extensionSetterSignature_debuggerContext_deleteAllBreakpoints inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteAllBreakpoints (class cPtr_debuggerContext * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension setter '@debuggerContext setWatchpoint'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_debuggerContext_setWatchpoint) (class cPtr_debuggerContext * inObject,
                                                                        const class GALGAS_gtlExpression constinArgument0,
                                                                        class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setWatchpoint (const int32_t inClassIndex,
                                         extensionSetterSignature_debuggerContext_setWatchpoint inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setWatchpoint (class cPtr_debuggerContext * inObject,
                                        const GALGAS_gtlExpression constin_watchExpression,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@debuggerContext listWatchpoints'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_debuggerContext_listWatchpoints) (const class cPtr_debuggerContext * inObject,
                                                                          class C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_listWatchpoints (const int32_t inClassIndex,
                                           extensionMethodSignature_debuggerContext_listWatchpoints inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_listWatchpoints (const class cPtr_debuggerContext * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension setter '@debuggerContext deleteWatchpoint'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_debuggerContext_deleteWatchpoint) (class cPtr_debuggerContext * inObject,
                                                                           const class GALGAS_lbigint constinArgument0,
                                                                           class C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteWatchpoint (const int32_t inClassIndex,
                                            extensionSetterSignature_debuggerContext_deleteWatchpoint inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteWatchpoint (class cPtr_debuggerContext * inObject,
                                           const GALGAS_lbigint constin_numToDelete,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension setter '@debuggerContext deleteAllWatchpoints'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_debuggerContext_deleteAllWatchpoints) (class cPtr_debuggerContext * inObject,
                                                                               class C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteAllWatchpoints (const int32_t inClassIndex,
                                                extensionSetterSignature_debuggerContext_deleteAllWatchpoints inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteAllWatchpoints (class cPtr_debuggerContext * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@debuggerContext breakOn'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_debuggerContext_breakOn) (const class cPtr_debuggerContext * inObject,
                                                                           const class GALGAS_gtlInstruction & constinArgument0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_breakOn (const int32_t inClassIndex,
                                   enterExtensionGetter_debuggerContext_breakOn inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_breakOn (const cPtr_debuggerContext * inObject,
                                               const GALGAS_gtlInstruction & constin_instruction,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@debuggerContext watchOn'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_debuggerContext_watchOn) (const class cPtr_debuggerContext * inObject,
                                                                           const class GALGAS_gtlContext & constinArgument0,
                                                                           const class GALGAS_gtlData & constinArgument1,
                                                                           const class GALGAS_library & constinArgument2,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_watchOn (const int32_t inClassIndex,
                                   enterExtensionGetter_debuggerContext_watchOn inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_watchOn (const cPtr_debuggerContext * inObject,
                                               const GALGAS_gtlContext & constin_context,
                                               const GALGAS_gtlData & constin_vars,
                                               const GALGAS_library & constin_lib,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension method '@debuggerContext hereWeAre'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_debuggerContext_hereWeAre) (const class cPtr_debuggerContext * inObject,
                                                                    const class GALGAS_uint constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_hereWeAre (const int32_t inClassIndex,
                                     extensionMethodSignature_debuggerContext_hereWeAre inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_hereWeAre (const class cPtr_debuggerContext * inObject,
                                    const GALGAS_uint constin_window,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Function 'bold'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_bold (class C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Function 'red'                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_red (class C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension setter '@debuggerContext pushInstructionList'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_debuggerContext_pushInstructionList) (class cPtr_debuggerContext * inObject,
                                                                              const class GALGAS_gtlInstructionList constinArgument0,
                                                                              class C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_pushInstructionList (const int32_t inClassIndex,
                                               extensionSetterSignature_debuggerContext_pushInstructionList inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_pushInstructionList (class cPtr_debuggerContext * inObject,
                                              const GALGAS_gtlInstructionList constin_instructions,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension setter '@debuggerContext popInstructionList'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_debuggerContext_popInstructionList) (class cPtr_debuggerContext * inObject,
                                                                             class C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_popInstructionList (const int32_t inClassIndex,
                                              extensionSetterSignature_debuggerContext_popInstructionList inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_popInstructionList (class cPtr_debuggerContext * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@debuggerContext getCommand'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_debuggerContext_getCommand) (class cPtr_debuggerContext * inObject,
                                                                     class GALGAS_string & outArgument0,
                                                                     class C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_getCommand (const int32_t inClassIndex,
                                      extensionSetterSignature_debuggerContext_getCommand inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_getCommand (class cPtr_debuggerContext * inObject,
                                     GALGAS_string & out_command,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Abstract extension getter '@gtlData stringRepresentation'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_string (*enterExtensionGetter_gtlData_stringRepresentation) (const class cPtr_gtlData * inObject,
                                                                                  class C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_stringRepresentation (const int32_t inClassIndex,
                                                enterExtensionGetter_gtlData_stringRepresentation inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string callExtensionGetter_stringRepresentation (const class cPtr_gtlData * inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension method '@impAutoDefaultType setDefault'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_impAutoDefaultType_setDefault) (const class cPtr_impAutoDefaultType * inObject,
                                                                        class GALGAS_objectAttributes & ioArgument0,
                                                                        class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_setDefault (const int32_t inClassIndex,
                                      extensionMethodSignature_impAutoDefaultType_setDefault inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_setDefault (const class cPtr_impAutoDefaultType * inObject,
                                     GALGAS_objectAttributes & io_attributes,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                     @void class                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_void : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_void (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_void constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_void * ptr (void) const { return (const cPtr_void *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_void (const cPtr_void * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_void extractObject (const GALGAS_object & inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_void constructor_new (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_location & inOperand1
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_void & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_void class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Pointer class for @void class                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_void : public cPtr_object_5F_t {
//--- Attributes

//--- Constructor
  public : cPtr_void (const GALGAS_lstring & in_oil_5F_desc,
                      const GALGAS_location & in_location
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
//                                                   @refType class                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_refType : public GALGAS_impType {
//--- Constructor
  public : GALGAS_refType (void) ;

//---
  public : inline const class cPtr_refType * ptr (void) const { return (const cPtr_refType *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_refType (const cPtr_refType * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_refType extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_refType constructor_new (const class GALGAS_locationList & inOperand0,
                                                        const class GALGAS_dataType & inOperand1,
                                                        const class GALGAS_lstring & inOperand2,
                                                        const class GALGAS_bool & inOperand3,
                                                        const class GALGAS_lstringlist & inOperand4,
                                                        const class GALGAS_lstring & inOperand5
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_refType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_ref (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_refType class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_refType ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Pointer class for @refType class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_refType : public cPtr_impType {
//--- Attributes
  public : GALGAS_lstring mAttribute_ref ;

//--- Constructor
  public : cPtr_refType (const GALGAS_locationList & in_locations,
                         const GALGAS_dataType & in_type,
                         const GALGAS_lstring & in_name,
                         const GALGAS_bool & in_multiple,
                         const GALGAS_lstringlist & in_descs,
                         const GALGAS_lstring & in_ref
                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_ref (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @impRangedType class                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_impRangedType : public GALGAS_impAutoDefaultType {
//--- Constructor
  public : GALGAS_impRangedType (void) ;

//---
  public : inline const class cPtr_impRangedType * ptr (void) const { return (const cPtr_impRangedType *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_impRangedType (const cPtr_impRangedType * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_impRangedType extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_impRangedType constructor_new (const class GALGAS_locationList & inOperand0,
                                                              const class GALGAS_dataType & inOperand1,
                                                              const class GALGAS_lstring & inOperand2,
                                                              const class GALGAS_bool & inOperand3,
                                                              const class GALGAS_lstringlist & inOperand4,
                                                              const class GALGAS_bool & inOperand5,
                                                              const class GALGAS_object_5F_t & inOperand6,
                                                              const class GALGAS_attributeRange & inOperand7
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_impRangedType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_attributeRange getter_setOrRange (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_impRangedType class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impRangedType ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Pointer class for @impRangedType class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_impRangedType : public cPtr_impAutoDefaultType {
//--- Attributes
  public : GALGAS_attributeRange mAttribute_setOrRange ;

//--- Constructor
  public : cPtr_impRangedType (const GALGAS_locationList & in_locations,
                               const GALGAS_dataType & in_type,
                               const GALGAS_lstring & in_name,
                               const GALGAS_bool & in_multiple,
                               const GALGAS_lstringlist & in_descs,
                               const GALGAS_bool & in_withAuto,
                               const GALGAS_object_5F_t & in_defaultValue,
                               const GALGAS_attributeRange & in_setOrRange
                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_attributeRange getter_setOrRange (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Extension getter '@implementationObject mergeImplementationObjectWith'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_implementationObject (*enterExtensionGetter_implementationObject_mergeImplementationObjectWith) (const class cPtr_implementationObject * inObject,
                                                                                                                      const class GALGAS_implementationObject & constinArgument0,
                                                                                                                      C_Compiler * inCompiler
                                                                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_mergeImplementationObjectWith (const int32_t inClassIndex,
                                                         enterExtensionGetter_implementationObject_mergeImplementationObjectWith inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_implementationObject callExtensionGetter_mergeImplementationObjectWith (const cPtr_implementationObject * inObject,
                                                                                     const GALGAS_implementationObject & constin_objToMerge,
                                                                                     class C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @uint_33__32__5F_class class                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_uint_33__32__5F_class : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_uint_33__32__5F_class (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_uint_33__32__5F_class constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_uint_33__32__5F_class * ptr (void) const { return (const cPtr_uint_33__32__5F_class *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_uint_33__32__5F_class (const cPtr_uint_33__32__5F_class * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_uint_33__32__5F_class extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_uint_33__32__5F_class constructor_new (const class GALGAS_lstring & inOperand0,
                                                                      const class GALGAS_location & inOperand1,
                                                                      const class GALGAS_uint & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_uint_33__32__5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_uint_33__32__5F_class class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_33__32__5F_class ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Pointer class for @uint32_class class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_uint_33__32__5F_class : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_uint mAttribute_value ;

//--- Constructor
  public : cPtr_uint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                       const GALGAS_location & in_location,
                                       const GALGAS_uint & in_value
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_uint getter_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @sint_33__32__5F_class class                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_sint_33__32__5F_class : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_sint_33__32__5F_class (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_sint_33__32__5F_class constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_sint_33__32__5F_class * ptr (void) const { return (const cPtr_sint_33__32__5F_class *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_sint_33__32__5F_class (const cPtr_sint_33__32__5F_class * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_sint_33__32__5F_class extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_sint_33__32__5F_class constructor_new (const class GALGAS_lstring & inOperand0,
                                                                      const class GALGAS_location & inOperand1,
                                                                      const class GALGAS_sint & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_sint_33__32__5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_sint getter_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_sint_33__32__5F_class class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sint_33__32__5F_class ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Pointer class for @sint32_class class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_sint_33__32__5F_class : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_sint mAttribute_value ;

//--- Constructor
  public : cPtr_sint_33__32__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                       const GALGAS_location & in_location,
                                       const GALGAS_sint & in_value
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_sint getter_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @uint_36__34__5F_class class                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_uint_36__34__5F_class : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_uint_36__34__5F_class (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_uint_36__34__5F_class constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_uint_36__34__5F_class * ptr (void) const { return (const cPtr_uint_36__34__5F_class *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_uint_36__34__5F_class (const cPtr_uint_36__34__5F_class * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_uint_36__34__5F_class extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_uint_36__34__5F_class constructor_new (const class GALGAS_lstring & inOperand0,
                                                                      const class GALGAS_location & inOperand1,
                                                                      const class GALGAS_uint_36__34_ & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_uint_36__34__5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_uint_36__34__5F_class class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_36__34__5F_class ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Pointer class for @uint64_class class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_uint_36__34__5F_class : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_uint_36__34_ mAttribute_value ;

//--- Constructor
  public : cPtr_uint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                       const GALGAS_location & in_location,
                                       const GALGAS_uint_36__34_ & in_value
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ getter_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @sint_36__34__5F_class class                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_sint_36__34__5F_class : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_sint_36__34__5F_class (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_sint_36__34__5F_class constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_sint_36__34__5F_class * ptr (void) const { return (const cPtr_sint_36__34__5F_class *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_sint_36__34__5F_class (const cPtr_sint_36__34__5F_class * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_sint_36__34__5F_class extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_sint_36__34__5F_class constructor_new (const class GALGAS_lstring & inOperand0,
                                                                      const class GALGAS_location & inOperand1,
                                                                      const class GALGAS_sint_36__34_ & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_sint_36__34__5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_sint_36__34__5F_class class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sint_36__34__5F_class ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Pointer class for @sint64_class class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_sint_36__34__5F_class : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_sint_36__34_ mAttribute_value ;

//--- Constructor
  public : cPtr_sint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                       const GALGAS_location & in_location,
                                       const GALGAS_sint_36__34_ & in_value
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ getter_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @float_5F_class class                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_float_5F_class : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_float_5F_class (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_float_5F_class constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_float_5F_class * ptr (void) const { return (const cPtr_float_5F_class *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_float_5F_class (const cPtr_float_5F_class * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_float_5F_class extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_float_5F_class constructor_new (const class GALGAS_lstring & inOperand0,
                                                               const class GALGAS_location & inOperand1,
                                                               const class GALGAS_double & inOperand2
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_float_5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_float_5F_class class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_float_5F_class ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Pointer class for @float_class class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_float_5F_class : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_double mAttribute_value ;

//--- Constructor
  public : cPtr_float_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                const GALGAS_location & in_location,
                                const GALGAS_double & in_value
                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_double getter_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

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
  public : static class GALGAS_bool_5F_t constructor_new (const class GALGAS_lstring & inOperand0,
                                                          const class GALGAS_location & inOperand1,
                                                          const class GALGAS_bool & inOperand2
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_bool_5F_t & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_value (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_value (LOCATION_ARGS) const ;
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
  public : static class GALGAS_void_5F_uint_33__32__5F_class constructor_new (const class GALGAS_lstring & inOperand0,
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
  public : static class GALGAS_void_5F_sint_33__32__5F_class constructor_new (const class GALGAS_lstring & inOperand0,
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

#endif
