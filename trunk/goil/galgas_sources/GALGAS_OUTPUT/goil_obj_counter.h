//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'goil_obj_counter.h'                          *
//                        Generated by version 1.8.2                         *
//                       may 20th, 2009, at 8h38'13"                         *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_obj_counter_DEFINED
#define goil_obj_counter_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/C_GGS_Object.h"
#include "galgas/GGS_location.h"
#include "galgas/GGS_lbool.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_lstring.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_luint64.h"
#include "galgas/GGS_lsint64.h"
#include "galgas/GGS_stringset.h"
#include "galgas/GGS_binaryset.h"
#include "galgas/GGS_filewrapper.h"
#include "galgas/predefined_types.h"
#include "galgas/AC_galgas_class.h"
#include "galgas/AC_galgas_domain.h"
#include "galgas/AC_galgas_mapindex.h"
#include "galgas/AC_galgas_map.h"
#include "galgas/AC_galgas_listmap.h"
#include "galgas/AC_galgas_list.h"
#include "galgas/AC_galgas_sortedlist.h"

//---------------------------------------------------------------------------*

#include "goil_lexique.h"

// Include imported semantics
#include "goil_options.h"
#include "goil_semantics.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                Parser class goil_obj_counter declaration                  *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_obj_counter {
  public : virtual ~goil_obj_counter (void) {}

  protected : virtual void nt_counter_ (goil_lexique &,
                                GGS_counter_map  &) = 0 ;

  protected : virtual void nt_counter_parameters_ (goil_lexique &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_lstring  &,
                                GGS_lstringlist  &,
                                GGS_counter_type  &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_counter_type_attrs_ (goil_lexique &,
                                GGS_counter_type  &) = 0 ;

  protected : virtual void nt_description_ (goil_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : void pr_counter_goil_obj_counter_46_14_ (goil_lexique &,
                                GGS_counter_map  &) ;

  protected : void pr_counter_parameters_goil_obj_counter_110_25_ (goil_lexique &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_basic_type  &,
                                GGS_lstring  &,
                                GGS_lstringlist  &,
                                GGS_counter_type  &,
                                GGS_lstring  &) ;

  protected : virtual sint16 select_repeat_goil_obj_counter_0 (goil_lexique &) = 0 ;

  protected : virtual sint16 select_goil_obj_counter_1 (goil_lexique &) = 0 ;

  protected : virtual sint16 select_goil_obj_counter_2 (goil_lexique &) = 0 ;

  protected : void pr_counter_type_attrs_goil_obj_counter_176_25_ (goil_lexique &,
                                GGS_counter_type  &) ;

  protected : virtual sint16 select_goil_obj_counter_3 (goil_lexique &) = 0 ;

  protected : virtual sint16 select_repeat_goil_obj_counter_4 (goil_lexique &) = 0 ;

  protected : virtual sint16 select_goil_obj_counter_5 (goil_lexique &) = 0 ;

  protected : virtual sint16 select_repeat_goil_obj_counter_6 (goil_lexique &) = 0 ;

  protected : virtual sint16 select_repeat_goil_obj_counter_7 (goil_lexique &) = 0 ;

} ;

//---------------------------------------------------------------------------*

#endif
