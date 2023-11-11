#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-3.h"

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlExecutableEntity checkArguments'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_checkArguments (class cPtr_gtlExecutableEntity * inObject,
                                         const class GALGAS_location constin_fromLocation,
                                         const class GALGAS_gtlDataList constin_actualArguments,
                                         class GALGAS_gtlData & out_entityVariableMap,
                                         class GALGAS_bool & out_result,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlProcedure class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlProcedure : public cPtr_gtlExecutableEntity {

//--- Extension method call
  public: virtual void method_call (class GALGAS_gtlContext & context,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           const class GALGAS_location fromLocation,
           const class GALGAS_gtlDataList actualArguments,
           C_Compiler * COMMA_LOCATION_ARGS) ;


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
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlProcedure call'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_call (class cPtr_gtlProcedure * inObject,
                               class GALGAS_gtlContext & io_context,
                               class GALGAS_library & io_lib,
                               class GALGAS_string & io_outputString,
                               const class GALGAS_location constin_fromLocation,
                               const class GALGAS_gtlDataList constin_actualArguments,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlFunction call'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_call (const cPtr_gtlFunction * inObject,
                                               const class GALGAS_location constin_fromLocation,
                                               class GALGAS_gtlContext in_context,
                                               class GALGAS_library in_lib,
                                               const class GALGAS_gtlDataList constin_actualArguments,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlGetter callGetter'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_callGetter (const cPtr_gtlGetter * inObject,
                                                     const class GALGAS_location constin_fromLocation,
                                                     class GALGAS_gtlContext in_context,
                                                     class GALGAS_library in_lib,
                                                     const class GALGAS_gtlData constin_target,
                                                     const class GALGAS_gtlDataList constin_actualArguments,
                                                     class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlGetter typedName'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_typedName (const cPtr_gtlGetter * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlSetter callSetter'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_callSetter (class cPtr_gtlSetter * inObject,
                                     const class GALGAS_location constin_fromLocation,
                                     class GALGAS_gtlContext in_context,
                                     class GALGAS_library in_lib,
                                     class GALGAS_gtlData & io_target,
                                     const class GALGAS_gtlDataList constin_actualArguments,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlSetter typedName'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_typedName (const cPtr_gtlSetter * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlModule  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlModule : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_gtlModule (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlModule constructor_default (LOCATION_ARGS) ;

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

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlModule extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlModule constructor_new (const class GALGAS_lstring & inOperand0,
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


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlModule ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlModule class
//
//----------------------------------------------------------------------------------------------------------------------

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
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlEmitInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlEmitInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlEmitInstruction (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlEmitInstruction * ptr (void) const {
    return (const cPtr_gtlEmitInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlEmitInstruction (const cPtr_gtlEmitInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpression readProperty_rValue (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlEmitInstruction extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlEmitInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                  const class GALGAS_string & inOperand1,
                                                                  const class GALGAS_gtlExpression & inOperand2
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlEmitInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setRValue (class GALGAS_gtlExpression inArgument0
                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlEmitInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlEmitInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlEmitInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlEmitInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlExpression mProperty_rValue ;

//--- Constructor
  public: cPtr_gtlEmitInstruction (const GALGAS_location & in_where,
                                   const GALGAS_string & in_signature,
                                   const GALGAS_gtlExpression & in_rValue
                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_rValue (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setRValue (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlWriteToInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlWriteToInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlWriteToInstruction (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlWriteToInstruction * ptr (void) const {
    return (const cPtr_gtlWriteToInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlWriteToInstruction (const cPtr_gtlWriteToInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpression readProperty_fileNameExpression (void) const ;

  public: class GALGAS_bool readProperty_isExecutable (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_instructions (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlWriteToInstruction extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlWriteToInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                     const class GALGAS_string & inOperand1,
                                                                     const class GALGAS_gtlExpression & inOperand2,
                                                                     const class GALGAS_bool & inOperand3,
                                                                     const class GALGAS_gtlInstructionList & inOperand4
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlWriteToInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setFileNameExpression (class GALGAS_gtlExpression inArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setInstructions (class GALGAS_gtlInstructionList inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setIsExecutable (class GALGAS_bool inArgument0
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlWriteToInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlWriteToInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlWriteToInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlWriteToInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlExpression mProperty_fileNameExpression ;
  public: GALGAS_bool mProperty_isExecutable ;
  public: GALGAS_gtlInstructionList mProperty_instructions ;

//--- Constructor
  public: cPtr_gtlWriteToInstruction (const GALGAS_location & in_where,
                                      const GALGAS_string & in_signature,
                                      const GALGAS_gtlExpression & in_fileNameExpression,
                                      const GALGAS_bool & in_isExecutable,
                                      const GALGAS_gtlInstructionList & in_instructions
                                      COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_fileNameExpression (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setFileNameExpression (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_isExecutable (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setIsExecutable (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_instructions (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setInstructions (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlTemplateInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTemplateInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlTemplateInstruction (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlTemplateInstruction * ptr (void) const {
    return (const cPtr_gtlTemplateInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlTemplateInstruction (const cPtr_gtlTemplateInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_prefix (void) const ;

  public: class GALGAS_gtlExpression readProperty_fileName (void) const ;

  public: class GALGAS_bool readProperty_ifExists (void) const ;

  public: class GALGAS_bool readProperty_isGlobal (void) const ;

  public: class GALGAS_gtlExpressionList readProperty_arguments (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_instructionsIfNotFound (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlTemplateInstruction extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlTemplateInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                      const class GALGAS_string & inOperand1,
                                                                      const class GALGAS_lstring & inOperand2,
                                                                      const class GALGAS_gtlExpression & inOperand3,
                                                                      const class GALGAS_bool & inOperand4,
                                                                      const class GALGAS_bool & inOperand5,
                                                                      const class GALGAS_gtlExpressionList & inOperand6,
                                                                      const class GALGAS_gtlInstructionList & inOperand7
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlTemplateInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setArguments (class GALGAS_gtlExpressionList inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setFileName (class GALGAS_gtlExpression inArgument0
                                                    COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setIfExists (class GALGAS_bool inArgument0
                                                    COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setInstructionsIfNotFound (class GALGAS_gtlInstructionList inArgument0
                                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setIsGlobal (class GALGAS_bool inArgument0
                                                    COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setPrefix (class GALGAS_lstring inArgument0
                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlTemplateInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTemplateInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlTemplateInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlTemplateInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_lstring mProperty_prefix ;
  public: GALGAS_gtlExpression mProperty_fileName ;
  public: GALGAS_bool mProperty_ifExists ;
  public: GALGAS_bool mProperty_isGlobal ;
  public: GALGAS_gtlExpressionList mProperty_arguments ;
  public: GALGAS_gtlInstructionList mProperty_instructionsIfNotFound ;

//--- Constructor
  public: cPtr_gtlTemplateInstruction (const GALGAS_location & in_where,
                                       const GALGAS_string & in_signature,
                                       const GALGAS_lstring & in_prefix,
                                       const GALGAS_gtlExpression & in_fileName,
                                       const GALGAS_bool & in_ifExists,
                                       const GALGAS_bool & in_isGlobal,
                                       const GALGAS_gtlExpressionList & in_arguments,
                                       const GALGAS_gtlInstructionList & in_instructionsIfNotFound
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_prefix (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setPrefix (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_fileName (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setFileName (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_ifExists (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setIfExists (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_isGlobal (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setIsGlobal (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_arguments (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setArguments (GALGAS_gtlExpressionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_instructionsIfNotFound (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setInstructionsIfNotFound (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlForeachStatementInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlForeachStatementInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlForeachStatementInstruction (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlForeachStatementInstruction * ptr (void) const {
    return (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlForeachStatementInstruction (const cPtr_gtlForeachStatementInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_keyName (void) const ;

  public: class GALGAS_lstring readProperty_variableName (void) const ;

  public: class GALGAS_lstring readProperty_indexName (void) const ;

  public: class GALGAS_gtlExpression readProperty_iterable (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_beforeList (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_betweenList (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_afterList (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_doList (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlForeachStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlForeachStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
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
  public: typeComparisonResult objectCompare (const GALGAS_gtlForeachStatementInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setAfterList (class GALGAS_gtlInstructionList inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setBeforeList (class GALGAS_gtlInstructionList inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setBetweenList (class GALGAS_gtlInstructionList inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setDoList (class GALGAS_gtlInstructionList inArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setIndexName (class GALGAS_lstring inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setIterable (class GALGAS_gtlExpression inArgument0
                                                    COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setKeyName (class GALGAS_lstring inArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setVariableName (class GALGAS_lstring inArgument0
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlForeachStatementInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlForeachStatementInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlForeachStatementInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlForeachStatementInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method iterateOnList
  public: virtual void method_iterateOnList (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           const class GALGAS_gtlList iterableList,
           C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method iterateOnMap
  public: virtual void method_iterateOnMap (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           const class GALGAS_gtlMap iterableMap,
           C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method iterateOnSet
  public: virtual void method_iterateOnSet (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           const class GALGAS_gtlSet iterableSet,
           C_Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_lstring mProperty_keyName ;
  public: GALGAS_lstring mProperty_variableName ;
  public: GALGAS_lstring mProperty_indexName ;
  public: GALGAS_gtlExpression mProperty_iterable ;
  public: GALGAS_gtlInstructionList mProperty_beforeList ;
  public: GALGAS_gtlInstructionList mProperty_betweenList ;
  public: GALGAS_gtlInstructionList mProperty_afterList ;
  public: GALGAS_gtlInstructionList mProperty_doList ;

//--- Constructor
  public: cPtr_gtlForeachStatementInstruction (const GALGAS_location & in_where,
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
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_keyName (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setKeyName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_variableName (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setVariableName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_indexName (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setIndexName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_iterable (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setIterable (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_beforeList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setBeforeList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setBetweenList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_afterList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setAfterList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDoList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlForeachStatementInstruction iterateOnMap'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_iterateOnMap (class cPtr_gtlForeachStatementInstruction * inObject,
                                       class GALGAS_gtlContext & io_context,
                                       class GALGAS_gtlData & io_vars,
                                       class GALGAS_library & io_lib,
                                       class GALGAS_string & io_outputString,
                                       const class GALGAS_gtlMap constin_iterableMap,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlForeachStatementInstruction iterateOnList'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_iterateOnList (class cPtr_gtlForeachStatementInstruction * inObject,
                                        class GALGAS_gtlContext & io_context,
                                        class GALGAS_gtlData & io_vars,
                                        class GALGAS_library & io_lib,
                                        class GALGAS_string & io_outputString,
                                        const class GALGAS_gtlList constin_iterableList,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlForeachStatementInstruction iterateOnSet'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_iterateOnSet (class cPtr_gtlForeachStatementInstruction * inObject,
                                       class GALGAS_gtlContext & io_context,
                                       class GALGAS_gtlData & io_vars,
                                       class GALGAS_library & io_lib,
                                       class GALGAS_string & io_outputString,
                                       const class GALGAS_gtlSet constin_iterableSet,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlForStatementInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlForStatementInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlForStatementInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlForStatementInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlForStatementInstruction * ptr (void) const {
    return (const cPtr_gtlForStatementInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlForStatementInstruction (const cPtr_gtlForStatementInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_identifier (void) const ;

  public: class GALGAS_gtlExpressionList readProperty_iterable (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_betweenList (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_doList (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlForStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlForStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                          const class GALGAS_string & inOperand1,
                                                                          const class GALGAS_lstring & inOperand2,
                                                                          const class GALGAS_gtlExpressionList & inOperand3,
                                                                          const class GALGAS_gtlInstructionList & inOperand4,
                                                                          const class GALGAS_gtlInstructionList & inOperand5
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlForStatementInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setBetweenList (class GALGAS_gtlInstructionList inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setDoList (class GALGAS_gtlInstructionList inArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setIdentifier (class GALGAS_lstring inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setIterable (class GALGAS_gtlExpressionList inArgument0
                                                    COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlForStatementInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlForStatementInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlForStatementInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlForStatementInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_lstring mProperty_identifier ;
  public: GALGAS_gtlExpressionList mProperty_iterable ;
  public: GALGAS_gtlInstructionList mProperty_betweenList ;
  public: GALGAS_gtlInstructionList mProperty_doList ;

//--- Constructor
  public: cPtr_gtlForStatementInstruction (const GALGAS_location & in_where,
                                           const GALGAS_string & in_signature,
                                           const GALGAS_lstring & in_identifier,
                                           const GALGAS_gtlExpressionList & in_iterable,
                                           const GALGAS_gtlInstructionList & in_betweenList,
                                           const GALGAS_gtlInstructionList & in_doList
                                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_identifier (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setIdentifier (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_iterable (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setIterable (GALGAS_gtlExpressionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setBetweenList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDoList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlLoopStatementInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlLoopStatementInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlLoopStatementInstruction (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlLoopStatementInstruction * ptr (void) const {
    return (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlLoopStatementInstruction (const cPtr_gtlLoopStatementInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_identifier (void) const ;

  public: class GALGAS_gtlExpression readProperty_start (void) const ;

  public: class GALGAS_gtlExpression readProperty_stop (void) const ;

  public: class GALGAS_gtlExpression readProperty_step (void) const ;

  public: class GALGAS_sint_36__34_ readProperty_upDown (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_beforeList (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_betweenList (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_afterList (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_doList (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlLoopStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlLoopStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
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
  public: typeComparisonResult objectCompare (const GALGAS_gtlLoopStatementInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setAfterList (class GALGAS_gtlInstructionList inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setBeforeList (class GALGAS_gtlInstructionList inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setBetweenList (class GALGAS_gtlInstructionList inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setDoList (class GALGAS_gtlInstructionList inArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setIdentifier (class GALGAS_lstring inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setStart (class GALGAS_gtlExpression inArgument0
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setStep (class GALGAS_gtlExpression inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setStop (class GALGAS_gtlExpression inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setUpDown (class GALGAS_sint_36__34_ inArgument0
                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlLoopStatementInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLoopStatementInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlLoopStatementInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlLoopStatementInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_lstring mProperty_identifier ;
  public: GALGAS_gtlExpression mProperty_start ;
  public: GALGAS_gtlExpression mProperty_stop ;
  public: GALGAS_gtlExpression mProperty_step ;
  public: GALGAS_sint_36__34_ mProperty_upDown ;
  public: GALGAS_gtlInstructionList mProperty_beforeList ;
  public: GALGAS_gtlInstructionList mProperty_betweenList ;
  public: GALGAS_gtlInstructionList mProperty_afterList ;
  public: GALGAS_gtlInstructionList mProperty_doList ;

//--- Constructor
  public: cPtr_gtlLoopStatementInstruction (const GALGAS_location & in_where,
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
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_identifier (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setIdentifier (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_start (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setStart (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_stop (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setStop (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_step (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setStep (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ getter_upDown (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setUpDown (GALGAS_sint_36__34_ inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_beforeList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setBeforeList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setBetweenList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_afterList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setAfterList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDoList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlRepeatStatementInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlRepeatStatementInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlRepeatStatementInstruction (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlRepeatStatementInstruction * ptr (void) const {
    return (const cPtr_gtlRepeatStatementInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlRepeatStatementInstruction (const cPtr_gtlRepeatStatementInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpression readProperty_limit (void) const ;

  public: class GALGAS_gtlExpression readProperty_condition (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_continueList (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_doList (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlRepeatStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlRepeatStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                             const class GALGAS_string & inOperand1,
                                                                             const class GALGAS_gtlExpression & inOperand2,
                                                                             const class GALGAS_gtlExpression & inOperand3,
                                                                             const class GALGAS_gtlInstructionList & inOperand4,
                                                                             const class GALGAS_gtlInstructionList & inOperand5
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlRepeatStatementInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setCondition (class GALGAS_gtlExpression inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setContinueList (class GALGAS_gtlInstructionList inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setDoList (class GALGAS_gtlInstructionList inArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLimit (class GALGAS_gtlExpression inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlRepeatStatementInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlRepeatStatementInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlRepeatStatementInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlRepeatStatementInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlExpression mProperty_limit ;
  public: GALGAS_gtlExpression mProperty_condition ;
  public: GALGAS_gtlInstructionList mProperty_continueList ;
  public: GALGAS_gtlInstructionList mProperty_doList ;

//--- Constructor
  public: cPtr_gtlRepeatStatementInstruction (const GALGAS_location & in_where,
                                              const GALGAS_string & in_signature,
                                              const GALGAS_gtlExpression & in_limit,
                                              const GALGAS_gtlExpression & in_condition,
                                              const GALGAS_gtlInstructionList & in_continueList,
                                              const GALGAS_gtlInstructionList & in_doList
                                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_limit (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setLimit (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_condition (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setCondition (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_continueList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setContinueList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDoList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlErrorStatementInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlErrorStatementInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlErrorStatementInstruction (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlErrorStatementInstruction * ptr (void) const {
    return (const cPtr_gtlErrorStatementInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlErrorStatementInstruction (const cPtr_gtlErrorStatementInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlVarPath readProperty_identifier (void) const ;

  public: class GALGAS_bool readProperty_hereInstead (void) const ;

  public: class GALGAS_gtlExpression readProperty_errorMessage (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlErrorStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlErrorStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                            const class GALGAS_string & inOperand1,
                                                                            const class GALGAS_gtlVarPath & inOperand2,
                                                                            const class GALGAS_bool & inOperand3,
                                                                            const class GALGAS_gtlExpression & inOperand4
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlErrorStatementInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setErrorMessage (class GALGAS_gtlExpression inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setHereInstead (class GALGAS_bool inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setIdentifier (class GALGAS_gtlVarPath inArgument0
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlErrorStatementInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlErrorStatementInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlErrorStatementInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlErrorStatementInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlVarPath mProperty_identifier ;
  public: GALGAS_bool mProperty_hereInstead ;
  public: GALGAS_gtlExpression mProperty_errorMessage ;

//--- Constructor
  public: cPtr_gtlErrorStatementInstruction (const GALGAS_location & in_where,
                                             const GALGAS_string & in_signature,
                                             const GALGAS_gtlVarPath & in_identifier,
                                             const GALGAS_bool & in_hereInstead,
                                             const GALGAS_gtlExpression & in_errorMessage
                                             COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_identifier (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setIdentifier (GALGAS_gtlVarPath inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_hereInstead (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setHereInstead (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_errorMessage (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setErrorMessage (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlWarningStatementInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlWarningStatementInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlWarningStatementInstruction (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlWarningStatementInstruction * ptr (void) const {
    return (const cPtr_gtlWarningStatementInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlWarningStatementInstruction (const cPtr_gtlWarningStatementInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlVarPath readProperty_identifier (void) const ;

  public: class GALGAS_bool readProperty_hereInstead (void) const ;

  public: class GALGAS_gtlExpression readProperty_warningMessage (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlWarningStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlWarningStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                              const class GALGAS_string & inOperand1,
                                                                              const class GALGAS_gtlVarPath & inOperand2,
                                                                              const class GALGAS_bool & inOperand3,
                                                                              const class GALGAS_gtlExpression & inOperand4
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlWarningStatementInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setHereInstead (class GALGAS_bool inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setIdentifier (class GALGAS_gtlVarPath inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setWarningMessage (class GALGAS_gtlExpression inArgument0
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlWarningStatementInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlWarningStatementInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlWarningStatementInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlWarningStatementInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlVarPath mProperty_identifier ;
  public: GALGAS_bool mProperty_hereInstead ;
  public: GALGAS_gtlExpression mProperty_warningMessage ;

//--- Constructor
  public: cPtr_gtlWarningStatementInstruction (const GALGAS_location & in_where,
                                               const GALGAS_string & in_signature,
                                               const GALGAS_gtlVarPath & in_identifier,
                                               const GALGAS_bool & in_hereInstead,
                                               const GALGAS_gtlExpression & in_warningMessage
                                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_identifier (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setIdentifier (GALGAS_gtlVarPath inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_hereInstead (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setHereInstead (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_warningMessage (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setWarningMessage (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlSortStatementInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlSortStatementInstruction : public GALGAS_gtlAbstractSortInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlSortStatementInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlSortStatementInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlSortStatementInstruction * ptr (void) const {
    return (const cPtr_gtlSortStatementInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlSortStatementInstruction (const cPtr_gtlSortStatementInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lsint readProperty_order (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlSortStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlSortStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                           const class GALGAS_string & inOperand1,
                                                                           const class GALGAS_gtlVarPath & inOperand2,
                                                                           const class GALGAS_lsint & inOperand3
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlSortStatementInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setOrder (class GALGAS_lsint inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlSortStatementInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSortStatementInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlSortStatementInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlSortStatementInstruction : public cPtr_gtlAbstractSortInstruction {

//--- Extension getter compare
  public: virtual class GALGAS_sint getter_compare (const class GALGAS_gtlData s1,
           const class GALGAS_gtlData s2,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_lsint mProperty_order ;

//--- Constructor
  public: cPtr_gtlSortStatementInstruction (const GALGAS_location & in_where,
                                            const GALGAS_string & in_signature,
                                            const GALGAS_gtlVarPath & in_variablePath,
                                            const GALGAS_lsint & in_order
                                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lsint getter_order (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setOrder (GALGAS_lsint inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlTabStatementInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTabStatementInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlTabStatementInstruction (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlTabStatementInstruction * ptr (void) const {
    return (const cPtr_gtlTabStatementInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlTabStatementInstruction (const cPtr_gtlTabStatementInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpression readProperty_tabValue (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlTabStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlTabStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                          const class GALGAS_string & inOperand1,
                                                                          const class GALGAS_gtlExpression & inOperand2
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlTabStatementInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setTabValue (class GALGAS_gtlExpression inArgument0
                                                    COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlTabStatementInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTabStatementInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlTabStatementInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlTabStatementInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlExpression mProperty_tabValue ;

//--- Constructor
  public: cPtr_gtlTabStatementInstruction (const GALGAS_location & in_where,
                                           const GALGAS_string & in_signature,
                                           const GALGAS_gtlExpression & in_tabValue
                                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_tabValue (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setTabValue (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlSetterCallInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlSetterCallInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlSetterCallInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlSetterCallInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlSetterCallInstruction * ptr (void) const {
    return (const cPtr_gtlSetterCallInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlSetterCallInstruction (const cPtr_gtlSetterCallInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlVarPath readProperty_target (void) const ;

  public: class GALGAS_lstring readProperty_setterName (void) const ;

  public: class GALGAS_gtlExpressionList readProperty_arguments (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlSetterCallInstruction extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlSetterCallInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                        const class GALGAS_string & inOperand1,
                                                                        const class GALGAS_gtlVarPath & inOperand2,
                                                                        const class GALGAS_lstring & inOperand3,
                                                                        const class GALGAS_gtlExpressionList & inOperand4
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlSetterCallInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setArguments (class GALGAS_gtlExpressionList inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setSetterName (class GALGAS_lstring inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTarget (class GALGAS_gtlVarPath inArgument0
                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlSetterCallInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSetterCallInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlSetterCallInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlSetterCallInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlVarPath mProperty_target ;
  public: GALGAS_lstring mProperty_setterName ;
  public: GALGAS_gtlExpressionList mProperty_arguments ;

//--- Constructor
  public: cPtr_gtlSetterCallInstruction (const GALGAS_location & in_where,
                                         const GALGAS_string & in_signature,
                                         const GALGAS_gtlVarPath & in_target,
                                         const GALGAS_lstring & in_setterName,
                                         const GALGAS_gtlExpressionList & in_arguments
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_target (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setTarget (GALGAS_gtlVarPath inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_setterName (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setSetterName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_arguments (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setArguments (GALGAS_gtlExpressionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext appendInstructionToStepDo'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_debuggerContext_appendInstructionToStepDo) (class cPtr_debuggerContext * inObject,
                                                                                    class GALGAS_gtlInstruction inArgument0,
                                                                                    class C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_appendInstructionToStepDo (const int32_t inClassIndex,
                                                     extensionSetterSignature_debuggerContext_appendInstructionToStepDo inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_appendInstructionToStepDo (class cPtr_debuggerContext * inObject,
                                                    GALGAS_gtlInstruction in_instruction,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext deleteStepDoInstruction'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_debuggerContext_deleteStepDoInstruction) (class cPtr_debuggerContext * inObject,
                                                                                  const class GALGAS_lbigint constinArgument0,
                                                                                  class C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteStepDoInstruction (const int32_t inClassIndex,
                                                   extensionSetterSignature_debuggerContext_deleteStepDoInstruction inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteStepDoInstruction (class cPtr_debuggerContext * inObject,
                                                  const GALGAS_lbigint constin_numToDelete,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext deleteAllStepDoInstructions'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_debuggerContext_deleteAllStepDoInstructions) (class cPtr_debuggerContext * inObject,
                                                                                      class C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteAllStepDoInstructions (const int32_t inClassIndex,
                                                       extensionSetterSignature_debuggerContext_deleteAllStepDoInstructions inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteAllStepDoInstructions (class cPtr_debuggerContext * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@debuggerContext listStepDoInstructions'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_listStepDoInstructions (class cPtr_debuggerContext * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext setBreakpoint'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_debuggerContext_setBreakpoint) (class cPtr_debuggerContext * inObject,
                                                                        const class GALGAS_string constinArgument0,
                                                                        const class GALGAS_uint constinArgument1,
                                                                        class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setBreakpoint (const int32_t inClassIndex,
                                         extensionSetterSignature_debuggerContext_setBreakpoint inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setBreakpoint (class cPtr_debuggerContext * inObject,
                                        const GALGAS_string constin_fileName,
                                        const GALGAS_uint constin_lineNum,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@debuggerContext listBreakpoints'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_listBreakpoints (class cPtr_debuggerContext * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext deleteBreakpoint'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_debuggerContext_deleteBreakpoint) (class cPtr_debuggerContext * inObject,
                                                                           const class GALGAS_lbigint constinArgument0,
                                                                           class C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteBreakpoint (const int32_t inClassIndex,
                                            extensionSetterSignature_debuggerContext_deleteBreakpoint inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteBreakpoint (class cPtr_debuggerContext * inObject,
                                           const GALGAS_lbigint constin_numToDelete,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext deleteAllBreakpoints'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_debuggerContext_deleteAllBreakpoints) (class cPtr_debuggerContext * inObject,
                                                                               class C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteAllBreakpoints (const int32_t inClassIndex,
                                                extensionSetterSignature_debuggerContext_deleteAllBreakpoints inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteAllBreakpoints (class cPtr_debuggerContext * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext setWatchpoint'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_debuggerContext_setWatchpoint) (class cPtr_debuggerContext * inObject,
                                                                        const class GALGAS_gtlExpression constinArgument0,
                                                                        class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setWatchpoint (const int32_t inClassIndex,
                                         extensionSetterSignature_debuggerContext_setWatchpoint inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setWatchpoint (class cPtr_debuggerContext * inObject,
                                        const GALGAS_gtlExpression constin_watchExpression,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@debuggerContext listWatchpoints'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_listWatchpoints (class cPtr_debuggerContext * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext deleteWatchpoint'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_debuggerContext_deleteWatchpoint) (class cPtr_debuggerContext * inObject,
                                                                           const class GALGAS_lbigint constinArgument0,
                                                                           class C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteWatchpoint (const int32_t inClassIndex,
                                            extensionSetterSignature_debuggerContext_deleteWatchpoint inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteWatchpoint (class cPtr_debuggerContext * inObject,
                                           const GALGAS_lbigint constin_numToDelete,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext deleteAllWatchpoints'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_debuggerContext_deleteAllWatchpoints) (class cPtr_debuggerContext * inObject,
                                                                               class C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteAllWatchpoints (const int32_t inClassIndex,
                                                extensionSetterSignature_debuggerContext_deleteAllWatchpoints inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteAllWatchpoints (class cPtr_debuggerContext * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@debuggerContext breakOn'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_breakOn (const cPtr_debuggerContext * inObject,
                                               const class GALGAS_gtlInstruction constin_instruction,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@debuggerContext watchOn'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_watchOn (const cPtr_debuggerContext * inObject,
                                               const class GALGAS_gtlContext constin_context,
                                               const class GALGAS_gtlData constin_vars,
                                               const class GALGAS_library constin_lib,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@debuggerContext hereWeAre'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_hereWeAre (class cPtr_debuggerContext * inObject,
                                    const class GALGAS_uint constin_window,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'bold'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_bold (class C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'red'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_red (class C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext pushInstructionList'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_debuggerContext_pushInstructionList) (class cPtr_debuggerContext * inObject,
                                                                              const class GALGAS_gtlInstructionList constinArgument0,
                                                                              class C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_pushInstructionList (const int32_t inClassIndex,
                                               extensionSetterSignature_debuggerContext_pushInstructionList inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_pushInstructionList (class cPtr_debuggerContext * inObject,
                                              const GALGAS_gtlInstructionList constin_instructions,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext popInstructionList'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_debuggerContext_popInstructionList) (class cPtr_debuggerContext * inObject,
                                                                             class C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_popInstructionList (const int32_t inClassIndex,
                                              extensionSetterSignature_debuggerContext_popInstructionList inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_popInstructionList (class cPtr_debuggerContext * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@debuggerContext getCommand'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_debuggerContext_getCommand) (class cPtr_debuggerContext * inObject,
                                                                     class GALGAS_string & outArgument0,
                                                                     class C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_getCommand (const int32_t inClassIndex,
                                      extensionSetterSignature_debuggerContext_getCommand inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_getCommand (class cPtr_debuggerContext * inObject,
                                     GALGAS_string & out_command,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string callExtensionGetter_stringRepresentation (const class cPtr_gtlData * inObject,
                                                              class C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @void  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_void : public GALGAS_object_5F_t {
//--------------------------------- Default constructor
  public: GALGAS_void (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_void constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_void * ptr (void) const {
    return (const cPtr_void *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_void (const cPtr_void * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_void extractObject (const GALGAS_object & inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_void constructor_new (const class GALGAS_lstring & inOperand0,
                                                    const class GALGAS_location & inOperand1
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_void & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_void class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @void class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_void : public cPtr_object_5F_t {


//--- Properties

//--- Constructor
  public: cPtr_void (const GALGAS_lstring & in_oil_5F_desc,
                     const GALGAS_location & in_location
                     COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@impType setDefValue'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_impType_setDefValue) (class cPtr_impType * inObject,
                                                              class GALGAS_object_5F_t inArgument0,
                                                              class C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setDefValue (const int32_t inClassIndex,
                                       extensionSetterSignature_impType_setDefValue inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setDefValue (class cPtr_impType * inObject,
                                      GALGAS_object_5F_t in_inDefaultValue,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@impAutoDefaultType setDefault'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_setDefault (class cPtr_impAutoDefaultType * inObject,
                                     class GALGAS_objectAttributes & io_attributes,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @refType  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_refType : public GALGAS_impType {
//--------------------------------- Default constructor
  public: GALGAS_refType (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_refType * ptr (void) const {
    return (const cPtr_refType *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_refType (const cPtr_refType * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_ref (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_refType extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_refType constructor_new (const class GALGAS_locationList & inOperand0,
                                                       const class GALGAS_dataType & inOperand1,
                                                       const class GALGAS_lstring & inOperand2,
                                                       const class GALGAS_bool & inOperand3,
                                                       const class GALGAS_lstringlist & inOperand4,
                                                       const class GALGAS_lstring & inOperand5
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_refType & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setRef (class GALGAS_lstring inArgument0
                                               COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_refType class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_refType ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @refType class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_refType : public cPtr_impType {

//--- Extension getter mergeWithType
  public: virtual class GALGAS_impType getter_mergeWithType (const class GALGAS_impType typeToMerge,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method checkAttributeReferences
  public: virtual void method_checkAttributeReferences (const class GALGAS_implementation imp,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method verifyType
  public: virtual void method_verifyType (const class GALGAS_object_5F_t attr,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_lstring mProperty_ref ;

//--- Constructor
  public: cPtr_refType (const GALGAS_locationList & in_locations,
                        const GALGAS_dataType & in_type,
                        const GALGAS_lstring & in_name,
                        const GALGAS_bool & in_multiple,
                        const GALGAS_lstringlist & in_descs,
                        const GALGAS_lstring & in_ref
                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_ref (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setRef (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@implementationObject mergeImplementationObjectWith'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_implementationObject callExtensionGetter_mergeImplementationObjectWith (const cPtr_implementationObject * inObject,
                                                                                     const class GALGAS_implementationObject constin_objToMerge,
                                                                                     class C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) ;

