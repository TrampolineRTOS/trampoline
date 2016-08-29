#ifndef all_2D_declarations_2D__35__ENTITIES_DEFINED
#define all_2D_declarations_2D__35__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "all-predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-4.h"

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

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Pointer class for @gtlTemplate class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlTemplate : public acPtr_class {
//--- Attributes
  public : GALGAS_string mAttribute_path ;
  public : GALGAS_gtlInstructionList mAttribute_program ;

//--- Constructor
  public : cPtr_gtlTemplate (const GALGAS_string & in_path,
                             const GALGAS_gtlInstructionList & in_program
                             COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_path (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_program (LOCATION_ARGS) const ;
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
//                                    Extension setter '@gtlVarMap replaceOrCreate'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_replaceOrCreate (class GALGAS_gtlVarMap & ioObject,
                                      const class GALGAS_lstring constin_key,
                                      const class GALGAS_gtlData constin_data,
                                      class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension setter '@gtlVarMap replaceOrCreateAtLevel'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_replaceOrCreateAtLevel (class GALGAS_gtlVarMap & ioObject,
                                             const class GALGAS_lstring constin_key,
                                             const class GALGAS_gtlData constin_data,
                                             const class GALGAS_uint constin_level,
                                             class C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@gtlTemplateMap getTemplate'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_getTemplate (class GALGAS_gtlTemplateMap & ioObject,
                                  const class GALGAS_gtlContext constin_context,
                                  class GALGAS_lstring in_path,
                                  class GALGAS_bool in_ifExists,
                                  class GALGAS_library & io_lib,
                                  class GALGAS_bool & out_found,
                                  class GALGAS_gtlTemplate & out_result,
                                  class C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract extension getter '@gtlVarItem stringPath'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_string (*enterExtensionGetter_gtlVarItem_stringPath) (const class cPtr_gtlVarItem * inObject,
                                                                           const class GALGAS_gtlData & constinArgument0,
                                                                           const class GALGAS_library & constinArgument1,
                                                                           class C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_stringPath (const int32_t inClassIndex,
                                      enterExtensionGetter_gtlVarItem_stringPath inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string callExtensionGetter_stringPath (const class cPtr_gtlVarItem * inObject,
                                                    const GALGAS_gtlData & constin_vars,
                                                    const GALGAS_library & constin_lib,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Abstract extension getter '@gtlVarItem location'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_location (*enterExtensionGetter_gtlVarItem_location) (const class cPtr_gtlVarItem * inObject,
                                                                           class C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_location (const int32_t inClassIndex,
                                    enterExtensionGetter_gtlVarItem_location inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_location callExtensionGetter_location (const class cPtr_gtlVarItem * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Abstract extension method '@gtlVarItem setInContext'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlVarItem_setInContext) (const class cPtr_gtlVarItem * inObject,
                                                                  class GALGAS_gtlData & ioArgument0,
                                                                  const class GALGAS_gtlData constinArgument1,
                                                                  const class GALGAS_library constinArgument2,
                                                                  const class GALGAS_gtlVarPath constinArgument3,
                                                                  const class GALGAS_gtlData constinArgument4,
                                                                  class C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_setInContext (const int32_t inClassIndex,
                                        extensionMethodSignature_gtlVarItem_setInContext inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_setInContext (const class cPtr_gtlVarItem * inObject,
                                       GALGAS_gtlData & io_context,
                                       const GALGAS_gtlData constin_vars,
                                       const GALGAS_library constin_lib,
                                       const GALGAS_gtlVarPath constin_path,
                                       const GALGAS_gtlData constin_newData,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Abstract extension getter '@gtlVarItem getInContext'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlVarItem_getInContext) (const class cPtr_gtlVarItem * inObject,
                                                                              const class GALGAS_gtlData & constinArgument0,
                                                                              const class GALGAS_gtlData & constinArgument1,
                                                                              const class GALGAS_library & constinArgument2,
                                                                              const class GALGAS_gtlVarPath & constinArgument3,
                                                                              class C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getInContext (const int32_t inClassIndex,
                                        enterExtensionGetter_gtlVarItem_getInContext inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_getInContext (const class cPtr_gtlVarItem * inObject,
                                                       const GALGAS_gtlData & constin_context,
                                                       const GALGAS_gtlData & constin_vars,
                                                       const GALGAS_library & constin_lib,
                                                       const GALGAS_gtlVarPath & constin_path,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Abstract extension getter '@gtlVarItem existsInContext'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_gtlVarItem_existsInContext) (const class cPtr_gtlVarItem * inObject,
                                                                              const class GALGAS_gtlData & constinArgument0,
                                                                              const class GALGAS_gtlData & constinArgument1,
                                                                              const class GALGAS_library & constinArgument2,
                                                                              const class GALGAS_gtlVarPath & constinArgument3,
                                                                              class C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_existsInContext (const int32_t inClassIndex,
                                           enterExtensionGetter_gtlVarItem_existsInContext inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_existsInContext (const class cPtr_gtlVarItem * inObject,
                                                       const GALGAS_gtlData & constin_context,
                                                       const GALGAS_gtlData & constin_vars,
                                                       const GALGAS_library & constin_lib,
                                                       const GALGAS_gtlVarPath & constin_path,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Abstract extension method '@gtlVarItem deleteInContext'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlVarItem_deleteInContext) (const class cPtr_gtlVarItem * inObject,
                                                                     class GALGAS_gtlData & ioArgument0,
                                                                     const class GALGAS_gtlData constinArgument1,
                                                                     const class GALGAS_library constinArgument2,
                                                                     const class GALGAS_gtlVarPath constinArgument3,
                                                                     class C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_deleteInContext (const int32_t inClassIndex,
                                           extensionMethodSignature_gtlVarItem_deleteInContext inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_deleteInContext (const class cPtr_gtlVarItem * inObject,
                                          GALGAS_gtlData & io_context,
                                          const GALGAS_gtlData constin_vars,
                                          const GALGAS_library constin_lib,
                                          const GALGAS_gtlVarPath constin_path,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension getter '@gtlVarPath stringPath' (as function)                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string extensionGetter_stringPath (const class GALGAS_gtlVarPath & inObject,
                                                const class GALGAS_gtlData & constinArgument0,
                                                const class GALGAS_library & constinArgument1,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Extension method '@gtlVarPath set'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_set (const class GALGAS_gtlVarPath inObject,
                          class GALGAS_gtlData & io_vars,
                          const class GALGAS_library constin_lib,
                          const class GALGAS_gtlData constin_data,
                          class C_Compiler * inCompiler
                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension getter '@gtlVarPath get' (as function)                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData extensionGetter_get (const class GALGAS_gtlVarPath & inObject,
                                          const class GALGAS_gtlData & constinArgument0,
                                          const class GALGAS_library & constinArgument1,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension getter '@gtlVarPath exists' (as function)                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool extensionGetter_exists (const class GALGAS_gtlVarPath & inObject,
                                          const class GALGAS_gtlData & constinArgument0,
                                          const class GALGAS_library & constinArgument1,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension method '@gtlVarPath delete'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_delete (const class GALGAS_gtlVarPath inObject,
                             class GALGAS_gtlData & io_vars,
                             const class GALGAS_library constin_lib,
                             class C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension getter '@gtlVarPath location' (as function)                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_location extensionGetter_location (const class GALGAS_gtlVarPath & inObject,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension getter '@string gtlType' (as function)                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_type extensionGetter_gtlType (const class GALGAS_string & inObject,
                                           const class GALGAS_location & constinArgument0,
                                           class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlInstruction location'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_location (*enterExtensionGetter_gtlInstruction_location) (const class cPtr_gtlInstruction * inObject,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_location (const int32_t inClassIndex,
                                    enterExtensionGetter_gtlInstruction_location inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_location callExtensionGetter_location (const cPtr_gtlInstruction * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension method '@gtlInstructionList execute'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_execute (const class GALGAS_gtlInstructionList inObject,
                              class GALGAS_gtlContext & io_context,
                              class GALGAS_gtlData & io_vars,
                              class GALGAS_library & io_lib,
                              class GALGAS_string & io_outputString,
                              class C_Compiler * inCompiler
                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlContext breakOnNext'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_gtlContext_breakOnNext) (const class cPtr_gtlContext * inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_breakOnNext (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlContext_breakOnNext inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_breakOnNext (const cPtr_gtlContext * inObject,
                                                   class C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlContext debugActive'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_gtlContext_debugActive) (const class cPtr_gtlContext * inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_debugActive (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlContext_debugActive inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_debugActive (const cPtr_gtlContext * inObject,
                                                   class C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension getter '@gtlContext loopOnCommand'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_gtlContext_loopOnCommand) (const class cPtr_gtlContext * inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_loopOnCommand (const int32_t inClassIndex,
                                         enterExtensionGetter_gtlContext_loopOnCommand inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_loopOnCommand (const cPtr_gtlContext * inObject,
                                                     class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlContext outputStyle'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_string (*enterExtensionGetter_gtlContext_outputStyle) (const class cPtr_gtlContext * inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_outputStyle (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlContext_outputStyle inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string callExtensionGetter_outputStyle (const cPtr_gtlContext * inObject,
                                                     class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlContext promptStyle'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_string (*enterExtensionGetter_gtlContext_promptStyle) (const class cPtr_gtlContext * inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_promptStyle (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlContext_promptStyle inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string callExtensionGetter_promptStyle (const cPtr_gtlContext * inObject,
                                                     class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension getter '@gtlInstruction mayExecuteWithoutError'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_gtlInstruction_mayExecuteWithoutError) (const class cPtr_gtlInstruction * inObject,
                                                                                         const class GALGAS_gtlData & constinArgument0,
                                                                                         const class GALGAS_library & constinArgument1,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_mayExecuteWithoutError (const int32_t inClassIndex,
                                                  enterExtensionGetter_gtlInstruction_mayExecuteWithoutError inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_mayExecuteWithoutError (const cPtr_gtlInstruction * inObject,
                                                              const GALGAS_gtlData & constin_context,
                                                              const GALGAS_library & constin_lib,
                                                              class C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension method '@gtlContext executeStepDoList'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlContext_executeStepDoList) (const class cPtr_gtlContext * inObject,
                                                                       class GALGAS_gtlContext & ioArgument0,
                                                                       class GALGAS_gtlData & ioArgument1,
                                                                       class GALGAS_library & ioArgument2,
                                                                       class GALGAS_string & ioArgument3,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_executeStepDoList (const int32_t inClassIndex,
                                             extensionMethodSignature_gtlContext_executeStepDoList inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_executeStepDoList (const class cPtr_gtlContext * inObject,
                                            GALGAS_gtlContext & io_context,
                                            GALGAS_gtlData & io_vars,
                                            GALGAS_library & io_lib,
                                            GALGAS_string & io_outputString,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension method '@gtlInstruction displayWithLocation'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlInstruction_displayWithLocation) (const class cPtr_gtlInstruction * inObject,
                                                                             const class GALGAS_debuggerContext constinArgument0,
                                                                             class C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_displayWithLocation (const int32_t inClassIndex,
                                               extensionMethodSignature_gtlInstruction_displayWithLocation inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_displayWithLocation (const class cPtr_gtlInstruction * inObject,
                                              const GALGAS_debuggerContext constin_context,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@gtlContext setLoopOnCommand'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_gtlContext_setLoopOnCommand) (class cPtr_gtlContext * inObject,
                                                                      class GALGAS_bool inArgument0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setLoopOnCommand (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_setLoopOnCommand inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setLoopOnCommand (class cPtr_gtlContext * inObject,
                                           GALGAS_bool in_loopOnCommand,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Abstract extension getter '@gtlAbstractSortInstruction compare'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_sint (*enterExtensionGetter_gtlAbstractSortInstruction_compare) (const class cPtr_gtlAbstractSortInstruction * inObject,
                                                                                      const class GALGAS_gtlData & constinArgument0,
                                                                                      const class GALGAS_gtlData & constinArgument1,
                                                                                      class C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_compare (const int32_t inClassIndex,
                                   enterExtensionGetter_gtlAbstractSortInstruction_compare inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_sint callExtensionGetter_compare (const class cPtr_gtlAbstractSortInstruction * inObject,
                                               const GALGAS_gtlData & constin_s_31_,
                                               const GALGAS_gtlData & constin_s_32_,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@gtlAbstractSortInstruction swap'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlAbstractSortInstruction_swap) (const class cPtr_gtlAbstractSortInstruction * inObject,
                                                                          class GALGAS_list & ioArgument0,
                                                                          const class GALGAS_uint constinArgument1,
                                                                          const class GALGAS_uint constinArgument2,
                                                                          class C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_swap (const int32_t inClassIndex,
                                extensionMethodSignature_gtlAbstractSortInstruction_swap inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_swap (const class cPtr_gtlAbstractSortInstruction * inObject,
                               GALGAS_list & io_aList,
                               const GALGAS_uint constin_index_31_,
                               const GALGAS_uint constin_index_32_,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension method '@gtlAbstractSortInstruction partition'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlAbstractSortInstruction_partition) (const class cPtr_gtlAbstractSortInstruction * inObject,
                                                                               class GALGAS_list & ioArgument0,
                                                                               const class GALGAS_uint constinArgument1,
                                                                               const class GALGAS_uint constinArgument2,
                                                                               class GALGAS_uint & ioArgument3,
                                                                               class C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_partition (const int32_t inClassIndex,
                                     extensionMethodSignature_gtlAbstractSortInstruction_partition inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_partition (const class cPtr_gtlAbstractSortInstruction * inObject,
                                    GALGAS_list & io_aList,
                                    const GALGAS_uint constin_min,
                                    const GALGAS_uint constin_max,
                                    GALGAS_uint & io_pivotIndex,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@gtlAbstractSortInstruction sort'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlAbstractSortInstruction_sort) (const class cPtr_gtlAbstractSortInstruction * inObject,
                                                                          class GALGAS_list & ioArgument0,
                                                                          const class GALGAS_uint constinArgument1,
                                                                          const class GALGAS_uint constinArgument2,
                                                                          class C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_sort (const int32_t inClassIndex,
                                extensionMethodSignature_gtlAbstractSortInstruction_sort inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_sort (const class cPtr_gtlAbstractSortInstruction * inObject,
                               GALGAS_list & io_aList,
                               const GALGAS_uint constin_min,
                               const GALGAS_uint constin_max,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension getter '@gtlSortStatementStructInstruction compareElements'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_sint (*enterExtensionGetter_gtlSortStatementStructInstruction_compareElements) (const class cPtr_gtlSortStatementStructInstruction * inObject,
                                                                                                     const class GALGAS_gtlData & constinArgument0,
                                                                                                     const class GALGAS_gtlData & constinArgument1,
                                                                                                     class GALGAS_sortingKeyList inArgument2,
                                                                                                     C_Compiler * inCompiler
                                                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_compareElements (const int32_t inClassIndex,
                                           enterExtensionGetter_gtlSortStatementStructInstruction_compareElements inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_sint callExtensionGetter_compareElements (const cPtr_gtlSortStatementStructInstruction * inObject,
                                                       const GALGAS_gtlData & constin_s_31_,
                                                       const GALGAS_gtlData & constin_s_32_,
                                                       GALGAS_sortingKeyList in_keyList,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData bool'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_gtlData_bool) (const class cPtr_gtlData * inObject,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_bool (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_bool inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_bool (const class cPtr_gtlData * inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData gtOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_gtOp) (const class cPtr_gtlData * inObject,
                                                                   const class GALGAS_gtlData & constinArgument0,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_gtOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_gtOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_gtOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData & constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData ltOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_gtlData (*enterExtensionGetter_gtlData_ltOp) (const class cPtr_gtlData * inObject,
                                                                   const class GALGAS_gtlData & constinArgument0,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_ltOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_ltOp inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlData callExtensionGetter_ltOp (const class cPtr_gtlData * inObject,
                                               const GALGAS_gtlData & constin_right,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension method '@gtlVariablesInstruction displayShort'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlVariablesInstruction_displayShort) (const class cPtr_gtlVariablesInstruction * inObject,
                                                                               const class GALGAS_gtlData constinArgument0,
                                                                               class C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_displayShort (const int32_t inClassIndex,
                                        extensionMethodSignature_gtlVariablesInstruction_displayShort inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_displayShort (const class cPtr_gtlVariablesInstruction * inObject,
                                       const GALGAS_gtlData constin_vars,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData desc'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_string (*enterExtensionGetter_gtlData_desc) (const class cPtr_gtlData * inObject,
                                                                  const class GALGAS_uint & constinArgument0,
                                                                  class C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_desc (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_desc inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string callExtensionGetter_desc (const class cPtr_gtlData * inObject,
                                              const GALGAS_uint & constin_tab,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension method '@gtlVariablesInstruction displayLong'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlVariablesInstruction_displayLong) (const class cPtr_gtlVariablesInstruction * inObject,
                                                                              const class GALGAS_gtlData constinArgument0,
                                                                              class C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_displayLong (const int32_t inClassIndex,
                                       extensionMethodSignature_gtlVariablesInstruction_displayLong inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_displayLong (const class cPtr_gtlVariablesInstruction * inObject,
                                      const GALGAS_gtlData constin_vars,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Extension getter '@gtlVarPath stringRepresentation' (as function)                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string extensionGetter_stringRepresentation (const class GALGAS_gtlVarPath & inObject,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Abstract extension getter '@gtlVarItem stringRepresentation'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_string (*enterExtensionGetter_gtlVarItem_stringRepresentation) (const class cPtr_gtlVarItem * inObject,
                                                                                     const class GALGAS_string & constinArgument0,
                                                                                     class C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_stringRepresentation (const int32_t inClassIndex,
                                                enterExtensionGetter_gtlVarItem_stringRepresentation inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string callExtensionGetter_stringRepresentation (const class cPtr_gtlVarItem * inObject,
                                                              const GALGAS_string & constin_concatString,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Extension getter '@gtlExpressionList stringRepresentation' (as function)                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string extensionGetter_stringRepresentation (const class GALGAS_gtlExpressionList & inObject,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Abstract extension getter '@gtlExpression stringRepresentation'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_string (*enterExtensionGetter_gtlExpression_stringRepresentation) (const class cPtr_gtlExpression * inObject,
                                                                                        class C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_stringRepresentation (const int32_t inClassIndex,
                                                enterExtensionGetter_gtlExpression_stringRepresentation inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string callExtensionGetter_stringRepresentation (const class cPtr_gtlExpression * inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension getter '@gtlExpressionMap mapRepresentation' (as function)                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string extensionGetter_mapRepresentation (const class GALGAS_gtlExpressionMap & inObject,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Extension getter '@gtlExpressionMap structRepresentation' (as function)                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string extensionGetter_structRepresentation (const class GALGAS_gtlExpressionMap & inObject,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Extension getter '@gtlArgumentList stringRepresentation' (as function)                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string extensionGetter_stringRepresentation (const class GALGAS_gtlArgumentList & inObject,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension getter '@sortingKeyList stringRepresentation' (as function)                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string extensionGetter_stringRepresentation (const class GALGAS_sortingKeyList & inObject,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension getter '@lsint stringRepresentation' (as function)                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string extensionGetter_stringRepresentation (const class GALGAS_lsint & inObject,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension getter '@gtlInstruction shortLocation'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_string (*enterExtensionGetter_gtlInstruction_shortLocation) (const class cPtr_gtlInstruction * inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_shortLocation (const int32_t inClassIndex,
                                         enterExtensionGetter_gtlInstruction_shortLocation inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string callExtensionGetter_shortLocation (const cPtr_gtlInstruction * inObject,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension method '@gtlInstruction display'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_gtlInstruction_display) (const class cPtr_gtlInstruction * inObject,
                                                                 class C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_display (const int32_t inClassIndex,
                                   extensionMethodSignature_gtlInstruction_display inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_display (const class cPtr_gtlInstruction * inObject,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension getter '@enumValues mergeWithEnum' (as function)                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_enumValues extensionGetter_mergeWithEnum (const class GALGAS_enumValues & inObject,
                                                       const class GALGAS_enumValues & constinArgument0,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//          Extension getter '@implementationObjectMap mergeImplementationObjectAttributesWith' (as function)          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_implementationObjectMap extensionGetter_mergeImplementationObjectAttributesWith (const class GALGAS_implementationObjectMap & inObject,
                                                                                              const class GALGAS_implementationObjectMap & constinArgument0,
                                                                                              class C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) ;

#endif
