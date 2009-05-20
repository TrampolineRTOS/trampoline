//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_lexique.h'                            *
//                        Generated by version 1.8.2                         *
//                       may 20th, 2009, at 8h37'21"                         *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_lexique_0_DEFINED
#define goil_lexique_0_DEFINED

//---------------------------------------------------------------------------*

#include "galgas/GGS_lstring.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_luint64.h"
#include "galgas/GGS_lsint64.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_lbool.h"

//---------------------------------------------------------------------------*

#include "galgas/C_Lexique.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                          Lexical scanner class                            *
//                                                                           *
//---------------------------------------------------------------------------*

class cTokenFor_goil_lexique : public cToken {
  public : C_String att_token ; // user defined attribute
  public : C_String a_string ; // user defined attribute
  public : uint64 integerNumber ; // user defined attribute
  public : double floatNumber ; // user defined attribute
  public : C_String number ; // user defined attribute

  public : cTokenFor_goil_lexique (void) ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Lexical scanner class                            *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_lexique : public C_Lexique {
//--- Constructors
  public : goil_lexique (C_Compiler * inCallerCompiler,
                       const C_String & inDependencyFileExtension,
                       const C_String & inDependencyFilePath,
                       C_galgas_io * inParametersPtr,
                       const C_String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public : goil_lexique (C_Compiler * inCallerCompiler,
                       C_galgas_io * inParametersPtr,
                       const C_String & inSourceString,
                       const C_String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~goil_lexique (void) {}
  #endif

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//--- Terminal symbols enumeration
  public : enum {goil_lexique_1_,
  goil_lexique_1_APP_5FSRC,
  goil_lexique_1_CFLAGS,
  goil_lexique_1_ASFLAGS,
  goil_lexique_1_LDFLAGS,
  goil_lexique_1_APP_5FNAME,
  goil_lexique_1_TRAMPOLINE_5FBASE_5FPATH,
  goil_lexique_1_OIL_5FVERSION,
  goil_lexique_1_IMPLEMENTATION,
  goil_lexique_1_OS,
  goil_lexique_1_TASK,
  goil_lexique_1_COUNTER,
  goil_lexique_1_ALARM,
  goil_lexique_1_RESOURCE,
  goil_lexique_1_EVENT,
  goil_lexique_1_ISR,
  goil_lexique_1_MESSAGE,
  goil_lexique_1_COM,
  goil_lexique_1_NM,
  goil_lexique_1_APPMODE,
  goil_lexique_1_IPDU,
  goil_lexique_1_CPU,
  goil_lexique_1_UINT32,
  goil_lexique_1_INT32,
  goil_lexique_1_UINT64,
  goil_lexique_1_INT64,
  goil_lexique_1_FLOAT,
  goil_lexique_1_ENUM,
  goil_lexique_1_STRING,
  goil_lexique_1_BOOLEAN,
  goil_lexique_1_WITH_5FAUTO,
  goil_lexique_1_NO_5FDEFAULT,
  goil_lexique_1_AUTO,
  goil_lexique_1_MASK,
  goil_lexique_1_CATEGORY,
  goil_lexique_1_OS_5FTYPE,
  goil_lexique_1_TASK_5FTYPE,
  goil_lexique_1_COUNTER_5FTYPE,
  goil_lexique_1_ALARM_5FTYPE,
  goil_lexique_1_RESOURCE_5FTYPE,
  goil_lexique_1_EVENT_5FTYPE,
  goil_lexique_1_ISR_5FTYPE,
  goil_lexique_1_MESSAGE_5FTYPE,
  goil_lexique_1_COM_5FTYPE,
  goil_lexique_1_NM_5FTYPE,
  goil_lexique_1_APPMODE_5FTYPE,
  goil_lexique_1_IPDU_5FTYPE,
  goil_lexique_1_STATUS,
  goil_lexique_1_EXTENDED,
  goil_lexique_1_STARTUPHOOK,
  goil_lexique_1_ERRORHOOK,
  goil_lexique_1_SHUTDOWNHOOK,
  goil_lexique_1_PRETASKHOOK,
  goil_lexique_1_POSTTASKHOOK,
  goil_lexique_1_USEGETSERVICEID,
  goil_lexique_1_USEPARAMETERACCESS,
  goil_lexique_1_USERESSCHEDULER,
  goil_lexique_1_SYSTEM_5FCALL,
  goil_lexique_1_TRACE,
  goil_lexique_1_FILE,
  goil_lexique_1_METHOD,
  goil_lexique_1_FORMAT,
  goil_lexique_1_TRACE_5FTASK,
  goil_lexique_1_TRACE_5FISR,
  goil_lexique_1_TRACE_5FRESOURCE,
  goil_lexique_1_TRACE_5FALARM,
  goil_lexique_1_TRACE_5FUSER,
  goil_lexique_1_DESCRIPTION,
  goil_lexique_1_PRIORITY,
  goil_lexique_1_SCHEDULE,
  goil_lexique_1_ACTIVATION,
  goil_lexique_1_AUTOSTART,
  goil_lexique_1_MAXALLOWEDVALUE,
  goil_lexique_1_TICKSPERBASE,
  goil_lexique_1_MINCYCLE,
  goil_lexique_1_TYPE,
  goil_lexique_1_UNIT,
  goil_lexique_1_ACTION,
  goil_lexique_1_SETEVENT,
  goil_lexique_1_ACTIVATETASK,
  goil_lexique_1_ALARMCALLBACK,
  goil_lexique_1_ALARMCALLBACKNAME,
  goil_lexique_1_ALARMTIME,
  goil_lexique_1_CYCLETIME,
  goil_lexique_1_INCREMENTCOUNTER,
  goil_lexique_1_RESOURCEPROPERTY,
  goil_lexique_1_STANDARD,
  goil_lexique_1_LINKED,
  goil_lexique_1_LINKEDRESOURCE,
  goil_lexique_1_INTERNAL,
  goil_lexique_1_MESSAGEPROPERTY,
  goil_lexique_1_NOTIFICATION,
  goil_lexique_1_NOTIFICATIONERROR,
  goil_lexique_1_SEND_5FSTATIC_5FINTERNAL,
  goil_lexique_1_SEND_5FSTATIC_5FEXTERNAL,
  goil_lexique_1_SEND_5FDYNAMIC_5FEXTERNAL,
  goil_lexique_1_SEND_5FZERO_5FINTERNAL,
  goil_lexique_1_SEND_5FZERO_5FEXTERNAL,
  goil_lexique_1_RECEIVE_5FZERO_5FINTERNAL,
  goil_lexique_1_RECEIVE_5FZERO_5FEXTERNAL,
  goil_lexique_1_RECEIVE_5FUNQUEUED_5FINTERNAL,
  goil_lexique_1_RECEIVE_5FQUEUED_5FINTERNAL,
  goil_lexique_1_RECEIVE_5FUNQUEUED_5FEXTERNAL,
  goil_lexique_1_RECEIVE_5FQUEUED_5FEXTERNAL,
  goil_lexique_1_RECEIVE_5FDYNAMIC_5FEXTERNAL,
  goil_lexique_1_RECEIVE_5FZERO_5FSENDERS,
  goil_lexique_1_CDATATYPE,
  goil_lexique_1_SENDINGMESSAGE,
  goil_lexique_1_NONE,
  goil_lexique_1_COMCALLBACK,
  goil_lexique_1_COMCALLBACKNAME,
  goil_lexique_1_INMCALLBACK,
  goil_lexique_1_CALLBACKROUTINENAME,
  goil_lexique_1_MONITOREDIPDU,
  goil_lexique_1_TRANSFERPROPERTY,
  goil_lexique_1_TRIGGERED,
  goil_lexique_1_PENDING,
  goil_lexique_1_NETWORKMESSAGE,
  goil_lexique_1_FILTER,
  goil_lexique_1_ALWAYS,
  goil_lexique_1_NEVER,
  goil_lexique_1_MASKEDNEWEQUALSX,
  goil_lexique_1_MASKEDNEWDIFFERSX,
  goil_lexique_1_NEWISEQUAL,
  goil_lexique_1_NEWISDIFFERENT,
  goil_lexique_1_MASKEDNEWEQUALSMASKEDOLD,
  goil_lexique_1_MASKEDNEWDIFFERSMASKEDOLD,
  goil_lexique_1_NEWISWITHIN,
  goil_lexique_1_NEWISOUTSIDE,
  goil_lexique_1_NEWISGREATER,
  goil_lexique_1_NEWISLESSOREQUAL,
  goil_lexique_1_NEWISLESS,
  goil_lexique_1_NEWISGREATEROREQUAL,
  goil_lexique_1_ONEEVERYN,
  goil_lexique_1_MIN,
  goil_lexique_1_MAX,
  goil_lexique_1_X,
  goil_lexique_1_PERIOD,
  goil_lexique_1_OFFSET,
  goil_lexique_1_NETWORKORDERCALLOUT,
  goil_lexique_1_CPUORDERCALLOUT,
  goil_lexique_1_INITIALVALUE,
  goil_lexique_1_QUEUESIZE,
  goil_lexique_1_LINK,
  goil_lexique_1_RECEIVEMESSAGE,
  goil_lexique_1_FLAG,
  goil_lexique_1_FLAGNAME,
  goil_lexique_1_STATIC,
  goil_lexique_1_DYNAMIC,
  goil_lexique_1_ZERO,
  goil_lexique_1_SIZEINBITS,
  goil_lexique_1_MAXSIZEINBITS,
  goil_lexique_1_BITORDERING,
  goil_lexique_1_BIGENDIAN,
  goil_lexique_1_LITTLEENDIAN,
  goil_lexique_1_BITPOSITION,
  goil_lexique_1_DATAINTERPRETATION,
  goil_lexique_1_UNSIGNEDINTEGER,
  goil_lexique_1_BYTEARRAY,
  goil_lexique_1_DIRECTION,
  goil_lexique_1_SENT,
  goil_lexique_1_RECEIVED,
  goil_lexique_1_COMTIMEBASE,
  goil_lexique_1_COMERRORHOOK,
  goil_lexique_1_COMUSEGETSERVICEID,
  goil_lexique_1_COMUSEPARAMETERACCESS,
  goil_lexique_1_COMSTARTCOMEXTENSION,
  goil_lexique_1_COMAPPMODE,
  goil_lexique_1_COMSTATUS,
  goil_lexique_1_USE,
  goil_lexique_1_COMEXTENDED,
  goil_lexique_1_COMSTANDARD,
  goil_lexique_1_IPDUPROPERTY,
  goil_lexique_1_IPDUCALLOUT,
  goil_lexique_1_LAYERUSED,
  goil_lexique_1_TRANSMISSIONMODE,
  goil_lexique_1_DIRECT,
  goil_lexique_1_PERIODIC,
  goil_lexique_1_MIXED,
  goil_lexique_1_TIMEOUT,
  goil_lexique_1_FIRTSTIMEOUT,
  goil_lexique_1_MINIMUMDELAYTIME,
  goil_lexique_1_TIMEPERIOD,
  goil_lexique_1_TIMEOFFSET,
  goil_lexique_1_NON,
  goil_lexique_1_FULL,
  goil_lexique_1_FALSE,
  goil_lexique_1_TRUE,
  goil_lexique_1_PROTECTIONHOOK,
  goil_lexique_1_SCALABILITYCLASS,
  goil_lexique_1_STACKMONITORING,
  goil_lexique_1_TIMING_5FPROTECTION,
  goil_lexique_1_ACCESSING_5FAPPLICATION,
  goil_lexique_1_SC1,
  goil_lexique_1_SC2,
  goil_lexique_1_SC3,
  goil_lexique_1_SC4,
  goil_lexique_1_SCHEDULETABLE,
  goil_lexique_1_APPLICATION,
  goil_lexique_1_LOCAL_5FTO_5FGLOBAL_5FTIME_5FSYNCHRONIZATION,
  goil_lexique_1_SYNC_5FSTRATEGY,
  goil_lexique_1_MAX_5FINCREASE,
  goil_lexique_1_MAX_5FDECREASE,
  goil_lexique_1_MAX_5FINCREASE_5FASYNC,
  goil_lexique_1_MAX_5FDECREASE_5FASYNC,
  goil_lexique_1_PRECISION,
  goil_lexique_1_LENGTH,
  goil_lexique_1_TRUSTED,
  goil_lexique_1_HAS_5FRESTARTTASK,
  goil_lexique_1_RESTARTTASK,
  goil_lexique_1_TRUSTED_5FFUNCTION,
  goil_lexique_1_NAME,
  goil_lexique_1_EXECUTIONBUDGET,
  goil_lexique_1_EXECUTIONTIME,
  goil_lexique_1_COUNTLIMIT,
  goil_lexique_1_TIMEFRAME,
  goil_lexique_1_MAXOSINTERRUPTLOCKTIME,
  goil_lexique_1_MAXALLINTERRUPTLOCKTIME,
  goil_lexique_1_LOCKINGTIME,
  goil_lexique_1_RESOURCELOCK,
  goil_lexique_1_MAXRESOURCELOCKTIME,
  goil_lexique_1_SMOOTH,
  goil_lexique_1_HARD,
  goil_lexique_1_TICKS,
  goil_lexique_1_NANOSECONDS,
  goil_lexique_1_SOFTWARE,
  goil_lexique_1_HARDWARE,
  goil_lexique_1_OSINTERNAL,
  goil_lexique_1_GPT,
  goil_lexique_1_NS_5FPER_5FHW_5FTICK,
  goil_lexique_1_GPTCHANNELNAME,
  goil_lexique_1_DRIVER,
  goil_lexique_1_TIMECONSTANTS,
  goil_lexique_1_TIMECONSTANT,
  goil_lexique_1_NS,
  goil_lexique_1_CONSTNAME,
  goil_lexique_1_SOURCE,
  goil_lexique_1_comment,
  goil_lexique_1_idf,
  goil_lexique_1__3B,
  goil_lexique_1__3A,
  goil_lexique_1__3D,
  goil_lexique_1__7B,
  goil_lexique_1__7D,
  goil_lexique_1__2E_2E,
  goil_lexique_1__5B,
  goil_lexique_1__5D,
  goil_lexique_1__2C,
  goil_lexique_1__2E,
  goil_lexique_1__2D,
  goil_lexique_1_string,
  goil_lexique_1_g_5Fstring,
  goil_lexique_1_uint_5Fnumber,
  goil_lexique_1_float_5Fnumber,
  goil_lexique_1_set_5Fstart_5Fuint_5Fnumber,
  goil_lexique_1_include,
  goil_lexique_1_command} ;

//--- Key words table 'makefileKeywords'
  public : static const sint16 goil_lexique_table_size_makefileKeywords ;
  private : static const C_lexique_table_entry goil_lexique_table_for_makefileKeywords [6] ;
  public : static sint16 search_into_makefileKeywords (const C_String & inSearchedString) ;

//--- Key words table 'oilVersion'
  public : static const sint16 goil_lexique_table_size_oilVersion ;
  private : static const C_lexique_table_entry goil_lexique_table_for_oilVersion [1] ;
  public : static sint16 search_into_oilVersion (const C_String & inSearchedString) ;

//--- Key words table 'oilDefinitions'
  public : static const sint16 goil_lexique_table_size_oilDefinitions ;
  private : static const C_lexique_table_entry goil_lexique_table_for_oilDefinitions [1] ;
  public : static sint16 search_into_oilDefinitions (const C_String & inSearchedString) ;

//--- Key words table 'objList'
  public : static const sint16 goil_lexique_table_size_objList ;
  private : static const C_lexique_table_entry goil_lexique_table_for_objList [13] ;
  public : static sint16 search_into_objList (const C_String & inSearchedString) ;

//--- Key words table 'dataTypes'
  public : static const sint16 goil_lexique_table_size_dataTypes ;
  private : static const C_lexique_table_entry goil_lexique_table_for_dataTypes [8] ;
  public : static sint16 search_into_dataTypes (const C_String & inSearchedString) ;

//--- Key words table 'miscSpecifiers'
  public : static const sint16 goil_lexique_table_size_miscSpecifiers ;
  private : static const C_lexique_table_entry goil_lexique_table_for_miscSpecifiers [5] ;
  public : static sint16 search_into_miscSpecifiers (const C_String & inSearchedString) ;

//--- Key words table 'objectRefType'
  public : static const sint16 goil_lexique_table_size_objectRefType ;
  private : static const C_lexique_table_entry goil_lexique_table_for_objectRefType [12] ;
  public : static sint16 search_into_objectRefType (const C_String & inSearchedString) ;

//--- Key words table 'os_attributes'
  public : static const sint16 goil_lexique_table_size_os_attributes ;
  private : static const C_lexique_table_entry goil_lexique_table_for_os_attributes [12] ;
  public : static sint16 search_into_os_attributes (const C_String & inSearchedString) ;

//--- Key words table 'trace_attributes'
  public : static const sint16 goil_lexique_table_size_trace_attributes ;
  private : static const C_lexique_table_entry goil_lexique_table_for_trace_attributes [9] ;
  public : static sint16 search_into_trace_attributes (const C_String & inSearchedString) ;

//--- Key words table 'task_attributes'
  public : static const sint16 goil_lexique_table_size_task_attributes ;
  private : static const C_lexique_table_entry goil_lexique_table_for_task_attributes [4] ;
  public : static sint16 search_into_task_attributes (const C_String & inSearchedString) ;

//--- Key words table 'counter_attributes'
  public : static const sint16 goil_lexique_table_size_counter_attributes ;
  private : static const C_lexique_table_entry goil_lexique_table_for_counter_attributes [3] ;
  public : static sint16 search_into_counter_attributes (const C_String & inSearchedString) ;

//--- Key words table 'as_counter_attributes'
  public : static const sint16 goil_lexique_table_size_as_counter_attributes ;
  private : static const C_lexique_table_entry goil_lexique_table_for_as_counter_attributes [2] ;
  public : static sint16 search_into_as_counter_attributes (const C_String & inSearchedString) ;

//--- Key words table 'alarm_attributes'
  public : static const sint16 goil_lexique_table_size_alarm_attributes ;
  private : static const C_lexique_table_entry goil_lexique_table_for_alarm_attributes [8] ;
  public : static sint16 search_into_alarm_attributes (const C_String & inSearchedString) ;

//--- Key words table 'resource_attributes'
  public : static const sint16 goil_lexique_table_size_resource_attributes ;
  private : static const C_lexique_table_entry goil_lexique_table_for_resource_attributes [5] ;
  public : static sint16 search_into_resource_attributes (const C_String & inSearchedString) ;

//--- Key words table 'message_attributes'
  public : static const sint16 goil_lexique_table_size_message_attributes ;
  private : static const C_lexique_table_entry goil_lexique_table_for_message_attributes [57] ;
  public : static sint16 search_into_message_attributes (const C_String & inSearchedString) ;

//--- Key words table 'networkmessage_attribute'
  public : static const sint16 goil_lexique_table_size_networkmessage_attribute ;
  private : static const C_lexique_table_entry goil_lexique_table_for_networkmessage_attribute [15] ;
  public : static sint16 search_into_networkmessage_attribute (const C_String & inSearchedString) ;

//--- Key words table 'com_attribute'
  public : static const sint16 goil_lexique_table_size_com_attribute ;
  private : static const C_lexique_table_entry goil_lexique_table_for_com_attribute [10] ;
  public : static sint16 search_into_com_attribute (const C_String & inSearchedString) ;

//--- Key words table 'ipdu_attribute'
  public : static const sint16 goil_lexique_table_size_ipdu_attribute ;
  private : static const C_lexique_table_entry goil_lexique_table_for_ipdu_attribute [12] ;
  public : static sint16 search_into_ipdu_attribute (const C_String & inSearchedString) ;

//--- Key words table 'scheduling'
  public : static const sint16 goil_lexique_table_size_scheduling ;
  private : static const C_lexique_table_entry goil_lexique_table_for_scheduling [2] ;
  public : static sint16 search_into_scheduling (const C_String & inSearchedString) ;

//--- Key words table 'boolean'
  public : static const sint16 goil_lexique_table_size_boolean ;
  private : static const C_lexique_table_entry goil_lexique_table_for_boolean [2] ;
  public : static sint16 search_into_boolean (const C_String & inSearchedString) ;

//--- Key words table 'autosar_attr'
  public : static const sint16 goil_lexique_table_size_autosar_attr ;
  private : static const C_lexique_table_entry goil_lexique_table_for_autosar_attr [5] ;
  public : static sint16 search_into_autosar_attr (const C_String & inSearchedString) ;

//--- Key words table 'autosar_key'
  public : static const sint16 goil_lexique_table_size_autosar_key ;
  private : static const C_lexique_table_entry goil_lexique_table_for_autosar_key [4] ;
  public : static sint16 search_into_autosar_key (const C_String & inSearchedString) ;

//--- Key words table 'autosar_objs'
  public : static const sint16 goil_lexique_table_size_autosar_objs ;
  private : static const C_lexique_table_entry goil_lexique_table_for_autosar_objs [2] ;
  public : static sint16 search_into_autosar_objs (const C_String & inSearchedString) ;

//--- Key words table 'schedtable_attrs'
  public : static const sint16 goil_lexique_table_size_schedtable_attrs ;
  private : static const C_lexique_table_entry goil_lexique_table_for_schedtable_attrs [8] ;
  public : static sint16 search_into_schedtable_attrs (const C_String & inSearchedString) ;

//--- Key words table 'application_attrs'
  public : static const sint16 goil_lexique_table_size_application_attrs ;
  private : static const C_lexique_table_entry goil_lexique_table_for_application_attrs [5] ;
  public : static sint16 search_into_application_attrs (const C_String & inSearchedString) ;

//--- Key words table 'timing_prot_attribs'
  public : static const sint16 goil_lexique_table_size_timing_prot_attribs ;
  private : static const C_lexique_table_entry goil_lexique_table_for_timing_prot_attribs [9] ;
  public : static sint16 search_into_timing_prot_attribs (const C_String & inSearchedString) ;

//--- Key words table 'sync_strategy'
  public : static const sint16 goil_lexique_table_size_sync_strategy ;
  private : static const C_lexique_table_entry goil_lexique_table_for_sync_strategy [2] ;
  public : static sint16 search_into_sync_strategy (const C_String & inSearchedString) ;

//--- Key words table 'unit'
  public : static const sint16 goil_lexique_table_size_unit ;
  private : static const C_lexique_table_entry goil_lexique_table_for_unit [2] ;
  public : static sint16 search_into_unit (const C_String & inSearchedString) ;

//--- Key words table 'cpt_type_attr'
  public : static const sint16 goil_lexique_table_size_cpt_type_attr ;
  private : static const C_lexique_table_entry goil_lexique_table_for_cpt_type_attr [11] ;
  public : static sint16 search_into_cpt_type_attr (const C_String & inSearchedString) ;

//--- Key words table 'it_src_attr'
  public : static const sint16 goil_lexique_table_size_it_src_attr ;
  private : static const C_lexique_table_entry goil_lexique_table_for_it_src_attr [1] ;
  public : static sint16 search_into_it_src_attr (const C_String & inSearchedString) ;

//--- Key words table 'OILDelimiters'
  public : static const sint16 goil_lexique_table_size_OILDelimiters ;
  private : static const C_lexique_table_entry goil_lexique_table_for_OILDelimiters [11] ;
  public : static sint16 search_into_OILDelimiters (const C_String & inSearchedString) ;

//--- Key words table 'commands'
  public : static const sint16 goil_lexique_table_size_commands ;
  private : static const C_lexique_table_entry goil_lexique_table_for_commands [1] ;
  public : static sint16 search_into_commands (const C_String & inSearchedString) ;

  protected : virtual bool parseLexicalToken (void) ;
  protected : virtual sint16 parseLexicalTokenForLexicalColoring (void) ;
  protected : virtual void appendTerminalMessageToSyntaxErrorMessage (const sint16 numeroTerminal,
                                                              C_String & messageErreur) ;

//--- Get attribute values
  public : void _assignFromAttribute_att_token (GGS_lstring & outValue) const ;
  public : C_String _attributeValue_att_token (void) const ;
  public : void _assignFromAttribute_a_string (GGS_lstring & outValue) const ;
  public : C_String _attributeValue_a_string (void) const ;
  public : void _assignFromAttribute_integerNumber (GGS_luint64 & outValue) const ;
  public : uint64 _attributeValue_integerNumber (void) const ;
  public : void _assignFromAttribute_floatNumber (GGS_ldouble & outValue) const ;
  public : double _attributeValue_floatNumber (void) const ;
  public : void _assignFromAttribute_number (GGS_lstring & outValue) const ;
  public : C_String _attributeValue_number (void) const ;
//--- Get terminal count
  public : virtual sint16 terminalVocabularyCount (void) const { return 256 ; }
//--- Get Token String
  public : virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const ;
//--- Enter Token
  protected : void _enterToken (const cTokenFor_goil_lexique & inToken) ;
//--- Style Definition
  public : static sint32 getStylesCount (void) ;
  public : static const char * getStyleName (const sint32 inIndex) ;
  public : static const char * getStyleIdentifier (const sint32 inIndex) ;
//--- Virtual method called getting terminal style index
  public : virtual uint8 terminalStyleIndex (const sint32 inTerminal) ;
} ;

//---------------------------------------------------------------------------*

#endif
