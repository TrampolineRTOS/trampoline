//---------------------------------------------------------------------------*
//                                                                           *
//                            File 'com_type.h'                              *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 27th, 2010, at 20h10'21"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef com_type_ENTITIES_DEFINED
#define com_type_ENTITIES_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------*

#include "goil_basic_types.h"
#include "goil_routines.h"

//---------------------------------------------------------------------------*

class GALGAS_com ;
class GALGASap_com ;
class GALGAS_basic_5F_type ;
class GALGASap_basic_5F_type ;
class GALGAS_string ;
class GALGASap_string ;
class GALGAS_uint ;
class GALGASap_uint ;
class GALGAS_uint_36__34_ ;
class GALGASap_uint_36__34_ ;
class GALGAS_luint_36__34_ ;
class GALGASap_luint_36__34_ ;
class GALGAS_lstring ;
class GALGASap_lstring ;
class GALGAS_lbool ;
class GALGASap_lbool ;
class GALGAS_bool ;
class GALGASap_bool ;
class GALGAS_uint_36__34__5F_class ;
class GALGASap_uint_36__34__5F_class ;
class GALGAS_stringlist ;
class GALGASap_stringlist ;
class GALGAS_prefix_5F_map ;
class GALGASap_prefix_5F_map ;
class GALGAS_stringset ;
class GALGASap_stringset ;
class GALGAS_lstringlist ;
class GALGASap_lstringlist ;
class GALGAS_object ;
class GALGASap_object ;
class GALGAS_type ;
class GALGASap_type ;
class GALGAS_enumerable ;
class GALGASap_enumerable ;
class GALGAS_class ;
class GALGASap_class ;
class GALGAS_struct ;
class GALGASap_struct ;
class GALGAS_enum ;
class GALGASap_enum ;
class GALGAS_mapproxy ;
class GALGASap_mapproxy ;
class GALGAS_location ;
class GALGASap_location ;
class GALGAS_functionlist ;
class GALGASap_functionlist ;
class GALGAS_function ;
class GALGASap_function ;
class GALGAS_typelist ;
class GALGASap_typelist ;
class GALGAS_objectlist ;
class GALGASap_objectlist ;
class GALGAS_binaryset ;
class GALGASap_binaryset ;
class GALGAS_uint_36__34_list ;
class GALGASap_uint_36__34_list ;
class GALGAS_luint ;
class GALGASap_luint ;
class GALGAS_lsint ;
class GALGASap_lsint ;
class GALGAS_sint ;
class GALGASap_sint ;
class GALGAS_lsint_36__34_ ;
class GALGASap_lsint_36__34_ ;
class GALGAS_sint_36__34_ ;
class GALGASap_sint_36__34_ ;
class GALGAS_lchar ;
class GALGASap_lchar ;
class GALGAS_char ;
class GALGASap_char ;
class GALGAS_ldouble ;
class GALGASap_ldouble ;
class GALGAS_double ;
class GALGASap_double ;
class GALGAS_number_5F_set ;
class GALGASap_number_5F_set ;
class GALGAS_imp_5F_type ;
class GALGASap_imp_5F_type ;
class GALGAS_oil_5F_obj ;
class GALGASap_oil_5F_obj ;
class GALGAS_autostart_5F_obj ;
class GALGASap_autostart_5F_obj ;
class GALGAS_list ;
class GALGASap_list ;
class GALGAS_sortedlist ;
class GALGASap_sortedlist ;
class GALGAS_map ;
class GALGASap_map ;
class GALGAS_listmap ;
class GALGASap_listmap ;
class GALGAS_data ;
class GALGASap_data ;
class GALGAS_imp_5F_sca_5F_type ;
class GALGASap_imp_5F_sca_5F_type ;
class GALGAS_imp_5F_obj_5F_ref ;
class GALGASap_imp_5F_obj_5F_ref ;
class GALGAS_void_5F_type ;
class GALGASap_void_5F_type ;
class GALGAS_list_5F_uint_33__32_ ;
class GALGASap_list_5F_uint_33__32_ ;
class GALGAS_list_5F_sint_33__32_ ;
class GALGASap_list_5F_sint_33__32_ ;
class GALGAS_list_5F_uint_36__34_ ;
class GALGASap_list_5F_uint_36__34_ ;
class GALGAS_list_5F_sint_36__34_ ;
class GALGASap_list_5F_sint_36__34_ ;
class GALGAS_ident_5F_list ;
class GALGASap_ident_5F_list ;
class GALGAS_luintlist ;
class GALGASap_luintlist ;
class GALGAS_uintlist ;
class GALGASap_uintlist ;
class GALGAS_ident_5F_map ;
class GALGASap_ident_5F_map ;
class GALGAS_stringMap ;
class GALGASap_stringMap ;
class GALGAS_lstringMap ;
class GALGASap_lstringMap ;
class GALGAS_stringset_5F_map ;
class GALGASap_stringset_5F_map ;
class GALGAS_ident_5F_list_5F_map ;
class GALGASap_ident_5F_list_5F_map ;
class GALGAS_uint_33__32__5F_set ;
class GALGASap_uint_33__32__5F_set ;
class GALGAS_sint_33__32__5F_set ;
class GALGASap_sint_33__32__5F_set ;
class GALGAS_uint_36__34__5F_set ;
class GALGASap_uint_36__34__5F_set ;
class GALGAS_sint_36__34__5F_set ;
class GALGASap_sint_36__34__5F_set ;
class GALGAS_float_5F_set ;
class GALGASap_float_5F_set ;
class GALGAS_sint_33__32__5F_empty_5F_set ;
class GALGASap_sint_33__32__5F_empty_5F_set ;
class GALGAS_sint_33__32__5F_range ;
class GALGASap_sint_33__32__5F_range ;
class GALGAS_sint_33__32__5F_list ;
class GALGASap_sint_33__32__5F_list ;
class GALGAS_sint_36__34__5F_empty_5F_set ;
class GALGASap_sint_36__34__5F_empty_5F_set ;
class GALGAS_sint_36__34__5F_range ;
class GALGASap_sint_36__34__5F_range ;
class GALGAS_sint_36__34__5F_list ;
class GALGASap_sint_36__34__5F_list ;
class GALGAS_uint_33__32__5F_empty_5F_set ;
class GALGASap_uint_33__32__5F_empty_5F_set ;
class GALGAS_uint_33__32__5F_range ;
class GALGASap_uint_33__32__5F_range ;
class GALGAS_uint_33__32__5F_list ;
class GALGASap_uint_33__32__5F_list ;
class GALGAS_uint_36__34__5F_empty_5F_set ;
class GALGASap_uint_36__34__5F_empty_5F_set ;
class GALGAS_uint_36__34__5F_range ;
class GALGASap_uint_36__34__5F_range ;
class GALGAS_uint_36__34__5F_list ;
class GALGASap_uint_36__34__5F_list ;
class GALGAS_autostart_5F_void ;
class GALGASap_autostart_5F_void ;
class GALGAS_autostart_5F_false ;
class GALGASap_autostart_5F_false ;
class GALGAS_void ;
class GALGASap_void ;
class GALGAS_uint_33__32__5F_class ;
class GALGASap_uint_33__32__5F_class ;
class GALGAS_sint_33__32__5F_class ;
class GALGASap_sint_33__32__5F_class ;
class GALGAS_sint_36__34__5F_class ;
class GALGASap_sint_36__34__5F_class ;
class GALGAS_float_5F_class ;
class GALGASap_float_5F_class ;
class GALGAS_string_5F_class ;
class GALGASap_string_5F_class ;
class GALGAS_bool_5F_class ;
class GALGASap_bool_5F_class ;
class GALGAS_void_5F_bool_5F_class ;
class GALGASap_void_5F_bool_5F_class ;
class GALGAS_auto_5F_bool_5F_class ;
class GALGASap_auto_5F_bool_5F_class ;
class GALGAS_void_5F_float_5F_class ;
class GALGASap_void_5F_float_5F_class ;
class GALGAS_float_5F_empty_5F_set ;
class GALGASap_float_5F_empty_5F_set ;
class GALGAS_uint_33__32__5F_type ;
class GALGASap_uint_33__32__5F_type ;
class GALGAS_sint_33__32__5F_type ;
class GALGASap_sint_33__32__5F_type ;
class GALGAS_uint_36__34__5F_type ;
class GALGASap_uint_36__34__5F_type ;
class GALGAS_sint_36__34__5F_type ;
class GALGASap_sint_36__34__5F_type ;
class GALGAS_void_5F_sint_33__32__5F_class ;
class GALGASap_void_5F_sint_33__32__5F_class ;
class GALGAS_auto_5F_sint_33__32__5F_class ;
class GALGASap_auto_5F_sint_33__32__5F_class ;
class GALGAS_void_5F_sint_36__34__5F_class ;
class GALGASap_void_5F_sint_36__34__5F_class ;
class GALGAS_auto_5F_sint_36__34__5F_class ;
class GALGASap_auto_5F_sint_36__34__5F_class ;
class GALGAS_void_5F_string_5F_class ;
class GALGASap_void_5F_string_5F_class ;
class GALGAS_auto_5F_string_5F_class ;
class GALGASap_auto_5F_string_5F_class ;
class GALGAS_void_5F_uint_33__32__5F_class ;
class GALGASap_void_5F_uint_33__32__5F_class ;
class GALGAS_auto_5F_uint_33__32__5F_class ;
class GALGASap_auto_5F_uint_33__32__5F_class ;
class GALGAS_void_5F_uint_36__34__5F_class ;
class GALGASap_void_5F_uint_36__34__5F_class ;
class GALGAS_auto_5F_uint_36__34__5F_class ;
class GALGASap_auto_5F_uint_36__34__5F_class ;

//---------------------------------------------------------------------------*
//                                                                           *
//                            @com auto ptr type                             *
//                                                                           *
//---------------------------------------------------------------------------*

class GALGASap_com : public GALGASap_oil_5F_obj {
//--- Default constructor
  public : inline GALGASap_com (void) : GALGASap_oil_5F_obj () {}

//--- Copy constructor
  public : GALGASap_com (const GALGASap_com & inSource) ;

//--- Assignment operator
  public : GALGASap_com & operator = (const GALGASap_com & inSource) ;

//--- Get pointer  
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : GALGAS_com * ptr (LOCATION_ARGS) ;
    public : const GALGAS_com * ptr (LOCATION_ARGS) const ;
  #else
    public : inline GALGAS_com * ptr (LOCATION_ARGS) {
      return (GALGAS_com *) mPtr ;
    }
    public : inline const GALGAS_com * ptr (LOCATION_ARGS) const {
      return (const GALGAS_com *) mPtr ;
    }
  #endif

//--- Constructor from generic object
  public : GALGASap_com (const GALGASap_object & inSource) ;

//--- Construction from pointer
  public : GALGASap_com (const GALGAS_com * inSourcePtr) ;

//--- Assignment from pointer
  public : GALGASap_com & operator = (GALGAS_com * inSourcePtr) ;

//--------------------------------- GALGAS constructors
  public : static GALGASap_com constructor_new (GALGASap_lstring & inOperand0,
                                                GALGASap_bool & inOperand1,
                                                GALGASap_basic_5F_type & inOperand2,
                                                GALGASap_basic_5F_type & inOperand3,
                                                GALGASap_basic_5F_type & inOperand4,
                                                GALGASap_basic_5F_type & inOperand5,
                                                GALGASap_basic_5F_type & inOperand6,
                                                GALGASap_lstringlist & inOperand7,
                                                GALGASap_lstring & inOperand8,
                                                GALGASap_lstringlist & inOperand9
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : static enumComparisonResult objectCompare (const GALGASap_com & inOperand1,
                                                      const GALGASap_com & inOperand2) ;
//--------------------------------- Reader invocation declaration
  public : VIRTUAL_IN_DEBUG GALGASap_lstringlist readerCall_appmodes (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGASap_basic_5F_type readerCall_errorhook (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGASap_basic_5F_type readerCall_startcomextension (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGASap_lstring readerCall_status (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGASap_basic_5F_type readerCall_timebase (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGASap_bool readerCall_usecom (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGASap_basic_5F_type readerCall_usegetserviceid (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGASap_basic_5F_type readerCall_useparameteraccess (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGASap_lstringlist readerCall_uses (LOCATION_ARGS) const ;

//--------------------------------- Modifier utility method
  public : void insulate (LOCATION_ARGS) ;

//--------------------------------- Modifier invocation
public : VIRTUAL_IN_DEBUG void modifierCall_setAppmodes (GALGASap_lstringlist inArgument0
                                                         COMMA_LOCATION_ARGS) ;

public : VIRTUAL_IN_DEBUG void modifierCall_setDesc (GALGASap_lstring inArgument0
                                                     COMMA_LOCATION_ARGS) ;

public : VIRTUAL_IN_DEBUG void modifierCall_setErrorhook (GALGASap_basic_5F_type inArgument0
                                                          COMMA_LOCATION_ARGS) ;

public : VIRTUAL_IN_DEBUG void modifierCall_setStartcomextension (GALGASap_basic_5F_type inArgument0
                                                                  COMMA_LOCATION_ARGS) ;

public : VIRTUAL_IN_DEBUG void modifierCall_setStatus (GALGASap_lstring inArgument0
                                                       COMMA_LOCATION_ARGS) ;

public : VIRTUAL_IN_DEBUG void modifierCall_setTimebase (GALGASap_basic_5F_type inArgument0
                                                         COMMA_LOCATION_ARGS) ;

public : VIRTUAL_IN_DEBUG void modifierCall_setUsecom (GALGASap_bool inArgument0
                                                       COMMA_LOCATION_ARGS) ;

public : VIRTUAL_IN_DEBUG void modifierCall_setUsegetserviceid (GALGASap_basic_5F_type inArgument0
                                                                COMMA_LOCATION_ARGS) ;

public : VIRTUAL_IN_DEBUG void modifierCall_setUseparameteraccess (GALGASap_basic_5F_type inArgument0
                                                                   COMMA_LOCATION_ARGS) ;

public : VIRTUAL_IN_DEBUG void modifierCall_setUses (GALGASap_lstringlist inArgument0
                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Method Invocation
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                              @com class type                              *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_com ;

//---------------------------------------------------------------------------*

class GALGAS_com : public GALGAS_oil_5F_obj {

//--------------------------------- C++ constructor
  public : GALGAS_com (const GALGASap_lstring & inAttribute_desc,
                       const GALGASap_bool & inAttribute_usecom,
                       const GALGASap_basic_5F_type & inAttribute_timebase,
                       const GALGASap_basic_5F_type & inAttribute_errorhook,
                       const GALGASap_basic_5F_type & inAttribute_usegetserviceid,
                       const GALGASap_basic_5F_type & inAttribute_useparameteraccess,
                       const GALGASap_basic_5F_type & inAttribute_startcomextension,
                       const GALGASap_lstringlist & inAttribute_appmodes,
                       const GALGASap_lstring & inAttribute_status,
                       const GALGASap_lstringlist & inAttribute_uses
                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Virtual destructor
  protected : virtual ~ GALGAS_com (void) ;

//--------------------------------- No copy
  private : GALGAS_com (const GALGAS_com &) ;
  private : GALGAS_com & operator = (const GALGAS_com &) ;

//--------------------------------- Implementation of reader 'description'
  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

//--------------------------------- Modifiers
  protected : void modifier_setAppmodes (GALGASap_lstringlist inArgument0
                                         COMMA_LOCATION_ARGS) ;

  protected : void modifier_setDesc (GALGASap_lstring inArgument0
                                     COMMA_LOCATION_ARGS) ;

  protected : void modifier_setErrorhook (GALGASap_basic_5F_type inArgument0
                                          COMMA_LOCATION_ARGS) ;

  protected : void modifier_setStartcomextension (GALGASap_basic_5F_type inArgument0
                                                  COMMA_LOCATION_ARGS) ;

  protected : void modifier_setStatus (GALGASap_lstring inArgument0
                                       COMMA_LOCATION_ARGS) ;

  protected : void modifier_setTimebase (GALGASap_basic_5F_type inArgument0
                                         COMMA_LOCATION_ARGS) ;

  protected : void modifier_setUsecom (GALGASap_bool inArgument0
                                       COMMA_LOCATION_ARGS) ;

  protected : void modifier_setUsegetserviceid (GALGASap_basic_5F_type inArgument0
                                                COMMA_LOCATION_ARGS) ;

  protected : void modifier_setUseparameteraccess (GALGASap_basic_5F_type inArgument0
                                                   COMMA_LOCATION_ARGS) ;

  protected : void modifier_setUses (GALGASap_lstringlist inArgument0
                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Readers
  protected : virtual GALGASap_lstringlist reader_appmodes (LOCATION_ARGS)  const ;

  protected : virtual GALGASap_basic_5F_type reader_errorhook (LOCATION_ARGS)  const ;

  protected : virtual GALGASap_basic_5F_type reader_startcomextension (LOCATION_ARGS)  const ;

  protected : virtual GALGASap_lstring reader_status (LOCATION_ARGS)  const ;

  protected : virtual GALGASap_basic_5F_type reader_timebase (LOCATION_ARGS)  const ;

  protected : virtual GALGASap_bool reader_usecom (LOCATION_ARGS)  const ;

  protected : virtual GALGASap_basic_5F_type reader_usegetserviceid (LOCATION_ARGS)  const ;

  protected : virtual GALGASap_basic_5F_type reader_useparameteraccess (LOCATION_ARGS)  const ;

  protected : virtual GALGASap_lstringlist reader_uses (LOCATION_ARGS)  const ;


//--------------------------------- Introspection
  public : virtual const C_galgas_type_descriptor * typeDescriptor (void) const ;

//--------------------------------- Private data member(s)
  public : GALGASap_bool mAttribute_usecom ;
  public : GALGASap_basic_5F_type mAttribute_timebase ;
  public : GALGASap_basic_5F_type mAttribute_errorhook ;
  public : GALGASap_basic_5F_type mAttribute_usegetserviceid ;
  public : GALGASap_basic_5F_type mAttribute_useparameteraccess ;
  public : GALGASap_basic_5F_type mAttribute_startcomextension ;
  public : GALGASap_lstringlist mAttribute_appmodes ;
  public : GALGASap_lstring mAttribute_status ;
  public : GALGASap_lstringlist mAttribute_uses ;
  

//--- Friend class
  friend class GALGASap_com ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Routine 'void_com_obj'                           *
//                                                                           *
//---------------------------------------------------------------------------*

GALGASap_com function_void_5F_com_5F_obj (C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

#endif