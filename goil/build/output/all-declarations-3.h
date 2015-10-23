#ifndef all_2D_declarations_2D__33__ENTITIES_DEFINED
#define all_2D_declarations_2D__33__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-2.h"

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
