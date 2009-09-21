//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_lexique.h'                            *
//                        Generated by version 1.9.1                         *
//                    september 21th, 2009, at 18h14'57"                     *
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
#include "galgas/C_Lexique.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                    E X T E R N    R O U T I N E S                         *
//                                                                           *
//---------------------------------------------------------------------------*

//---------------------------------------------------------------------------*
//                                                                           *
//                    E X T E R N    F U N C T I O N S                       *
//                                                                           *
//---------------------------------------------------------------------------*

//---------------------------------------------------------------------------*
//                                                                           *
//                       T O K E N    C L A S S                              *
//                                                                           *
//---------------------------------------------------------------------------*

class cTokenFor_goil_lexique : public cToken {
  public : C_String mLexicalAttribute_a_string ;
  public : C_String mLexicalAttribute_att_token ;
  public : double mLexicalAttribute_floatNumber ;
  public : uint64 mLexicalAttribute_integerNumber ;
  public : C_String mLexicalAttribute_number ;

  public : cTokenFor_goil_lexique (void) ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     S C A N N E R    C L A S S                            *
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
  goil_lexique_1_comment,
  goil_lexique_1_idf,
  goil_lexique_1_string,
  goil_lexique_1_g_5F_string,
  goil_lexique_1_uint_5F_number,
  goil_lexique_1_float_5F_number,
  goil_lexique_1_set_5F_start_5F_uint_5F_number,
  goil_lexique_1_command,
  goil_lexique_1_APP_5F_SRC,
  goil_lexique_1_CFLAGS,
  goil_lexique_1_ASFLAGS,
  goil_lexique_1_LDFLAGS,
  goil_lexique_1_APP_5F_NAME,
  goil_lexique_1_TRAMPOLINE_5F_BASE_5F_PATH,
  goil_lexique_1_OIL_5F_VERSION,
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
  goil_lexique_1_UINT_33__32_,
  goil_lexique_1_INT_33__32_,
  goil_lexique_1_UINT_36__34_,
  goil_lexique_1_INT_36__34_,
  goil_lexique_1_FLOAT,
  goil_lexique_1_ENUM,
  goil_lexique_1_STRING,
  goil_lexique_1_BOOLEAN,
  goil_lexique_1_WITH_5F_AUTO,
  goil_lexique_1_NO_5F_DEFAULT,
  goil_lexique_1_AUTO,
  goil_lexique_1_MASK,
  goil_lexique_1_CATEGORY,
  goil_lexique_1_OS_5F_TYPE,
  goil_lexique_1_TASK_5F_TYPE,
  goil_lexique_1_COUNTER_5F_TYPE,
  goil_lexique_1_ALARM_5F_TYPE,
  goil_lexique_1_RESOURCE_5F_TYPE,
  goil_lexique_1_EVENT_5F_TYPE,
  goil_lexique_1_ISR_5F_TYPE,
  goil_lexique_1_MESSAGE_5F_TYPE,
  goil_lexique_1_COM_5F_TYPE,
  goil_lexique_1_NM_5F_TYPE,
  goil_lexique_1_APPMODE_5F_TYPE,
  goil_lexique_1_IPDU_5F_TYPE,
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
  goil_lexique_1_SYSTEM_5F_CALL,
  goil_lexique_1_TRACE,
  goil_lexique_1_FILE,
  goil_lexique_1_METHOD,
  goil_lexique_1_FORMAT,
  goil_lexique_1_TRACE_5F_TASK,
  goil_lexique_1_TRACE_5F_ISR,
  goil_lexique_1_TRACE_5F_RESOURCE,
  goil_lexique_1_TRACE_5F_ALARM,
  goil_lexique_1_TRACE_5F_USER,
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
  goil_lexique_1_SEND_5F_STATIC_5F_INTERNAL,
  goil_lexique_1_SEND_5F_STATIC_5F_EXTERNAL,
  goil_lexique_1_SEND_5F_DYNAMIC_5F_EXTERNAL,
  goil_lexique_1_SEND_5F_ZERO_5F_INTERNAL,
  goil_lexique_1_SEND_5F_ZERO_5F_EXTERNAL,
  goil_lexique_1_RECEIVE_5F_ZERO_5F_INTERNAL,
  goil_lexique_1_RECEIVE_5F_ZERO_5F_EXTERNAL,
  goil_lexique_1_RECEIVE_5F_UNQUEUED_5F_INTERNAL,
  goil_lexique_1_RECEIVE_5F_QUEUED_5F_INTERNAL,
  goil_lexique_1_RECEIVE_5F_UNQUEUED_5F_EXTERNAL,
  goil_lexique_1_RECEIVE_5F_QUEUED_5F_EXTERNAL,
  goil_lexique_1_RECEIVE_5F_DYNAMIC_5F_EXTERNAL,
  goil_lexique_1_RECEIVE_5F_ZERO_5F_SENDERS,
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
  goil_lexique_1_TIMING_5F_PROTECTION,
  goil_lexique_1_ACCESSING_5F_APPLICATION,
  goil_lexique_1_SC_31_,
  goil_lexique_1_SC_32_,
  goil_lexique_1_SC_33_,
  goil_lexique_1_SC_34_,
  goil_lexique_1_SCHEDULETABLE,
  goil_lexique_1_APPLICATION,
  goil_lexique_1_LOCAL_5F_TO_5F_GLOBAL_5F_TIME_5F_SYNCHRONIZATION,
  goil_lexique_1_SYNC_5F_STRATEGY,
  goil_lexique_1_MAX_5F_INCREASE,
  goil_lexique_1_MAX_5F_DECREASE,
  goil_lexique_1_MAX_5F_INCREASE_5F_ASYNC,
  goil_lexique_1_MAX_5F_DECREASE_5F_ASYNC,
  goil_lexique_1_PRECISION,
  goil_lexique_1_LENGTH,
  goil_lexique_1_EXPIRY_5F_POINT,
  goil_lexique_1_MAX_5F_RETARD,
  goil_lexique_1_MAX_5F_ADVANCE,
  goil_lexique_1_ADJUSTABLE,
  goil_lexique_1_ABSOLUTE,
  goil_lexique_1_RELATIVE,
  goil_lexique_1_SYNCHRON,
  goil_lexique_1_START,
  goil_lexique_1_TRUSTED,
  goil_lexique_1_HAS_5F_RESTARTTASK,
  goil_lexique_1_RESTARTTASK,
  goil_lexique_1_TRUSTED_5F_FUNCTION,
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
  goil_lexique_1_NS_5F_PER_5F_HW_5F_TICK,
  goil_lexique_1_GPTCHANNELNAME,
  goil_lexique_1_DRIVER,
  goil_lexique_1_TIMECONSTANTS,
  goil_lexique_1_TIMECONSTANT,
  goil_lexique_1_NS,
  goil_lexique_1_CONSTNAME,
  goil_lexique_1_SOURCE,
  goil_lexique_1__3B_,
  goil_lexique_1__3A_,
  goil_lexique_1__3D_,
  goil_lexique_1__7B_,
  goil_lexique_1__7D_,
  goil_lexique_1__2E__2E_,
  goil_lexique_1__5B_,
  goil_lexique_1__5D_,
  goil_lexique_1__2C_,
  goil_lexique_1__2E_,
  goil_lexique_1__2D_,
  goil_lexique_1_include} ;

//--- Key words table 'makefileKeywords'
  public : static sint16 search_into_makefileKeywords (const C_String & inSearchedString) ;

//--- Key words table 'oilVersion'
  public : static sint16 search_into_oilVersion (const C_String & inSearchedString) ;

//--- Key words table 'oilDefinitions'
  public : static sint16 search_into_oilDefinitions (const C_String & inSearchedString) ;

//--- Key words table 'objList'
  public : static sint16 search_into_objList (const C_String & inSearchedString) ;

//--- Key words table 'dataTypes'
  public : static sint16 search_into_dataTypes (const C_String & inSearchedString) ;

//--- Key words table 'miscSpecifiers'
  public : static sint16 search_into_miscSpecifiers (const C_String & inSearchedString) ;

//--- Key words table 'objectRefType'
  public : static sint16 search_into_objectRefType (const C_String & inSearchedString) ;

//--- Key words table 'os_attributes'
  public : static sint16 search_into_os_attributes (const C_String & inSearchedString) ;

//--- Key words table 'trace_attributes'
  public : static sint16 search_into_trace_attributes (const C_String & inSearchedString) ;

//--- Key words table 'task_attributes'
  public : static sint16 search_into_task_attributes (const C_String & inSearchedString) ;

//--- Key words table 'counter_attributes'
  public : static sint16 search_into_counter_attributes (const C_String & inSearchedString) ;

//--- Key words table 'as_counter_attributes'
  public : static sint16 search_into_as_counter_attributes (const C_String & inSearchedString) ;

//--- Key words table 'alarm_attributes'
  public : static sint16 search_into_alarm_attributes (const C_String & inSearchedString) ;

//--- Key words table 'resource_attributes'
  public : static sint16 search_into_resource_attributes (const C_String & inSearchedString) ;

//--- Key words table 'message_attributes'
  public : static sint16 search_into_message_attributes (const C_String & inSearchedString) ;

//--- Key words table 'networkmessage_attribute'
  public : static sint16 search_into_networkmessage_attribute (const C_String & inSearchedString) ;

//--- Key words table 'com_attribute'
  public : static sint16 search_into_com_attribute (const C_String & inSearchedString) ;

//--- Key words table 'ipdu_attribute'
  public : static sint16 search_into_ipdu_attribute (const C_String & inSearchedString) ;

//--- Key words table 'scheduling'
  public : static sint16 search_into_scheduling (const C_String & inSearchedString) ;

//--- Key words table 'boolean'
  public : static sint16 search_into_boolean (const C_String & inSearchedString) ;

//--- Key words table 'autosar_attr'
  public : static sint16 search_into_autosar_attr (const C_String & inSearchedString) ;

//--- Key words table 'autosar_key'
  public : static sint16 search_into_autosar_key (const C_String & inSearchedString) ;

//--- Key words table 'autosar_objs'
  public : static sint16 search_into_autosar_objs (const C_String & inSearchedString) ;

//--- Key words table 'schedtable_attrs'
  public : static sint16 search_into_schedtable_attrs (const C_String & inSearchedString) ;

//--- Key words table 'autostart_attrs'
  public : static sint16 search_into_autostart_attrs (const C_String & inSearchedString) ;

//--- Key words table 'application_attrs'
  public : static sint16 search_into_application_attrs (const C_String & inSearchedString) ;

//--- Key words table 'timing_prot_attribs'
  public : static sint16 search_into_timing_prot_attribs (const C_String & inSearchedString) ;

//--- Key words table 'sync_strategy'
  public : static sint16 search_into_sync_strategy (const C_String & inSearchedString) ;

//--- Key words table 'unit'
  public : static sint16 search_into_unit (const C_String & inSearchedString) ;

//--- Key words table 'cpt_type_attr'
  public : static sint16 search_into_cpt_type_attr (const C_String & inSearchedString) ;

//--- Key words table 'it_src_attr'
  public : static sint16 search_into_it_src_attr (const C_String & inSearchedString) ;

//--- Key words table 'OILDelimiters'
  public : static sint16 search_into_OILDelimiters (const C_String & inSearchedString) ;

//--- Key words table 'commands'
  public : static sint16 search_into_commands (const C_String & inSearchedString) ;
  

//--- Assign from attribute
  public : void assignFromAttribute_a_string (GGS_lstring & outValue) const ;
  public : void assignFromAttribute_att_token (GGS_lstring & outValue) const ;
  public : void assignFromAttribute_floatNumber (GGS_ldouble & outValue) const ;
  public : void assignFromAttribute_integerNumber (GGS_luint64 & outValue) const ;
  public : void assignFromAttribute_number (GGS_lstring & outValue) const ;


//--- Attribute access
  public : C_String attributeValue_a_string (void) const ;
  public : C_String attributeValue_att_token (void) const ;
  public : double attributeValue_floatNumber (void) const ;
  public : uint64 attributeValue_integerNumber (void) const ;
  public : C_String attributeValue_number (void) const ;


//--- Parse lexical token
  protected : virtual bool parseLexicalToken (void) ;

//--- Append terminal message
  protected : virtual void appendTerminalMessageToSyntaxErrorMessage (const sint16 numeroTerminal,
                                                              C_String & messageErreur) ;

//--- Get terminal count
  public : virtual sint16 terminalVocabularyCount (void) const { return 264 ; }

//--- Get Token String
  public : virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const ;

//--- Enter Token
  protected : void enterToken (const cTokenFor_goil_lexique & inToken) ;
} ;

//---------------------------------------------------------------------------*

#endif
