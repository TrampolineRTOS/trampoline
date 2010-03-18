//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_obj_ipdu.h'                           *
//                       Generated by version 1.9.10                         *
//                      march 18th, 2010, at 9h49'45"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_obj_ipdu_DEFINED
#define goil_obj_ipdu_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"
#include "goil_lexique.h"

//---------------------------------------------------------------------------*

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
//                  Parser class goil_obj_ipdu declaration                   *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_obj_ipdu {
  public : virtual ~goil_obj_ipdu (void) {}

  protected : virtual void nt_ipdu_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_ipduproperty_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_transmissionmode_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_timeperiod_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_timeoffset_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_minimumdelaytime_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_timeout_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_firsttimeout_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_ipducallout_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_layerused_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_sent_5F_attributes_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_received_5F_attributes_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_direct_5F_attributes_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_periodic_5F_attributes_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_mixed_5F_attributes_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_sizeinbits_ (C_Lexique_goil_5F_lexique &,
                                GGS_luint64  &) = 0 ;

  protected : virtual void nt_description_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : void rule_goil_5F_obj_5F_ipdu_ipdu_i0_ (C_Lexique_goil_5F_lexique &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_0 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_ipdu_ipduproperty_i1_ (C_Lexique_goil_5F_lexique &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_1 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_ipdu_ipducallout_i2_ (C_Lexique_goil_5F_lexique &) ;

  protected : void rule_goil_5F_obj_5F_ipdu_layerused_i3_ (C_Lexique_goil_5F_lexique &) ;

  protected : void rule_goil_5F_obj_5F_ipdu_sent_5F_attributes_i4_ (C_Lexique_goil_5F_lexique &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_2 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_ipdu_received_5F_attributes_i5_ (C_Lexique_goil_5F_lexique &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_3 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_ipdu_transmissionmode_i6_ (C_Lexique_goil_5F_lexique &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_4 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_ipdu_timeout_i7_ (C_Lexique_goil_5F_lexique &) ;

  protected : void rule_goil_5F_obj_5F_ipdu_firsttimeout_i8_ (C_Lexique_goil_5F_lexique &) ;

  protected : void rule_goil_5F_obj_5F_ipdu_direct_5F_attributes_i9_ (C_Lexique_goil_5F_lexique &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_5 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_ipdu_periodic_5F_attributes_i10_ (C_Lexique_goil_5F_lexique &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_6 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_ipdu_mixed_5F_attributes_i11_ (C_Lexique_goil_5F_lexique &) ;

  protected : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_7 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_obj_5F_ipdu_minimumdelaytime_i12_ (C_Lexique_goil_5F_lexique &) ;

  protected : void rule_goil_5F_obj_5F_ipdu_timeperiod_i13_ (C_Lexique_goil_5F_lexique &) ;

  protected : void rule_goil_5F_obj_5F_ipdu_timeoffset_i14_ (C_Lexique_goil_5F_lexique &) ;

} ;

//---------------------------------------------------------------------------*

#endif
