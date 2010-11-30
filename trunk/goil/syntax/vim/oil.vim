" Vim syntax file
" Language:     OSEK Implementation Language (tested for ProOSEK OIL/ORTI)
" Maintainer:   Christian Drothler <christian.drothler@freenet.de>
" Last Change:  2002 April 02

" You are free to use this file as you please, but
" if you make a change or improvement you must send it
" to the maintainer at <christian.drothler@freenet.de>
" 
"------------------------------------------------------------------------
" Quit if syntax file already loaded and vim > 6.00
if !exists("main_syntax")
  if version < 600
    syntax clear
  elseif exists("b:current_syntax")
    finish
  endif
" we define it here so that included files can test for it
let main_syntax='oil'
endif

"---------------------------------------------------------------------------
" keyword definitions:
syn keyword oilStatement      OS TASK ISR COUNTER MESSAGE APPMODE
syn keyword oilStatement      ALARM EVENT RESOURCE COM NM
syn keyword oilStatement      IMPLEMENTATION CPU STACK
syn keyword oilStatement      OSEK_ARM7 OSEK_C16X OSEK_H8 OSEK_HC08 OSEK_HC12 OSEK_PPC 
syn keyword oilStatement      OSEK_SH2 OSEK_ST30  OSEK_TMS470 OSEK_V850 OSEK_Win32x86
" OS:
syn keyword oilConstant       CC SCHEDULE MICROCONTROLLER USERMAIN STATUS
syn keyword oilConstant       STARTUPHOOK ERRORHOOK PRETASKHOOK POSTTASKHOOK SHUTDOWNHOOK
syn keyword oilConstant       USEGETSERVICEID USEPARAMETERACCESS EXTRA_RUNTIME_CHECKS
syn keyword oilConstant       SERVICETRACE USELASTERROR IMPLEMENTS_REALTIMECLOCK
syn keyword oilConstant       STACKCHECK TRACEBUFFER 
syn keyword oilConstant       ARM7_REALTIMECLOCK C16X_REALTIMECLOCK F2MC16L_REALTIMECLOCK H8_REALTIMECLOCK 
syn keyword oilConstant       HC08_REALTIMECLOCK HC12_REALTIMECLOCK PPC_REALTIMECLOCK SH2_REALTIMECLOCK 
syn keyword oilConstant       ST30_REALTIMECLOCK TMS470_REALTIMECLOCK V850_REALTIMECLOCK WIN32X86_REALTIMECLOCK
syn keyword oilSpecial        AUTO BCC1 BCC2 ECC1 ECC2
syn keyword oilSpecial        NON FULL MIXED
syn keyword oilSpecial        STANDARD EXTENDED
syn keyword oilSpecial        OIL_VERSION
" TASK:
syn keyword oilConstant       ACTIVATION CALLSCHEDULER PRIORITY SCHEDULE STACKSIZE TYPE
syn keyword oilConstant       AUTOSTART ACCESSOR ACCESSNAME
syn keyword oilSpecial        BASIC EXTENDED
syn keyword oilSpecial        NON FULL
syn keyword oilBoolean        NO YES DONTKNOW
" ISR:
syn keyword oilConstant       ENABLE_ON_STARTUP CATEGORY INITIAL_INTERRUPT_DESCRIPTOR
syn keyword oilConstant       ARM_VECTOR ARM_LEVEL ARM7_VECTOR ARM7_LEVEL C16X_VECTOR C16X_LEVEL
syn keyword oilConstant       F2MC16L_VECTOR F2MC16L_LEVEL H8_VECTOR H8_LEVEL HC08_VECTOR HC08_LEVEL 
syn keyword oilConstant       HC12_VECTOR HC12__LEVEL PPC_VECTOR PPC_LEVEL SH2_VECTOR SH2_PRIORITY  
syn keyword oilConstant       ST30_NUMBER ST30_PRIO TMS470_NUMBER TMS470_LEVEL V850_VECTOR V850_LEVEL 
syn keyword oilConstant       WIN32X86_VECTOR WIN32X86_LEVEL
syn keyword oilSpecial        FIQ IRQ
" COUNTER:
syn keyword oilConstant       MINCYCLE MAXALLOWEDVALUE TIME_IN_NS TICKSPERBASE
syn keyword oilConstant       ARM_TYPE ARM7_TYPE C16X_TYPE F2MC16L_TYPE H8_TYPE HC08_TYPE HC12_TYPE 
syn keyword oilConstant       PPC_TYPE SH2_TYPE ST30_TYPE TMS470_TYPE V850_TYPE WIN32X86_TYPE 
syn keyword oilSpecial        USERCOUNTER
" MESSAGE:
syn keyword oilConstant       LENGTH TYPE CDATATYPE ACTION QUEUEDEPTH
syn keyword oilConstant       QUEUELENGTH CALLBACKNAME FLAGNAME
syn keyword oilType           ADDRESS STRING QUEUED UNQUEUED
syn keyword oilSpecial        RECEIVED SENT WITHCOPY WITHOUTCOPY withcopy withoutcopy 
" APPMODE:  
syn keyword oilSpecial        OSDEFAULTAPPMODE
" ALARM:
syn keyword oilConstant       AUTOSTART ALARMTIME CYCLETIME ALARMCALLBACKNAME
syn keyword oilSpecial        ACTIVATETASK ALARMCALLBACK SETEVENT
" EVENT:
syn keyword oilConstant       MASK
" RESOURCE:
syn keyword oilConstant       RESOURCEPROPERTY LINKEDRESOURCE
syn keyword oilSpecial        STANDARD LINKED INTERNAL
" COM:
syn keyword oilConstant       USEMESSAGERESOURCE USEMESSAGESTATUS

"---------------------------------------------------------------------------
" another OILs: 
syn keyword oilType           ALARM_TYPE COUNTER_TYPE EVENT_TYPE ISR_TYPE MESSAGE_TYPE RESOURCE_TYPE TASK_TYPE 
syn keyword oilType           ENUM WITH_AUTO BOOLEAN COUNTER_TYPE 
syn keyword oilType           UINT8 UINT16 UINT32 UINT64 INT8 INT16 INT32 INT64
syn keyword oilType           ADDRESS STRING QUEUED UNQUEUED
syn keyword oilType           char int INT CHAR 
"
syn keyword oilSpecial        SMALL LARGE BANKED NONBANKED
syn keyword oilSpecial        STANDARD FULLUSERSTACK
syn keyword oilSpecial        SysCounter
"
syn keyword oilBoolean        FALSE TRUE NOT_USED 
"
syn keyword oilConstant       STATE STACKEND STACKSTART SHAREDSTACK
syn keyword oilConstant       MAXVALUE STARTADDRESS SIZE NULL
syn keyword oilConstant       VALUE TICKPERBASE RUNNINGTASK
"
syn keyword oilNumber         Number NUMBER number

"---------------------------------------------------------------------------
" ARM7:
syn keyword oilSpecial        ARMUL TMS470 ST_SUPERARGUS ST_ZEPHYRUS ARM7 Plain_OIL
" C16X:
syn keyword oilSpecial        C161CS C164CI C167CR C167CS ST10F269 ST10F276 C16X
syn keyword oilSpecial        C16X_MEMORYMODEL C16X_STACKMODEL C16X_SYSSTACKSIZE
syn keyword oilSpecial        C16X_GLOBAL_DISABLE C16X_GROUP 
" F2MC16L:
syn keyword oilSpecial        MB90540 MB90545 MB90590 MB90595 MB90495 MB90390 MB90340
syn keyword oilSpecial        EIIOS_COMPLETION 
" H8:
syn keyword oilSpecial        H8S2612 H8S2623 H8 H8S
" HC08:
syn keyword oilSpecial        MC68HC908AZ60 MC68HC908AS60 HC08
" HC12:
syn keyword oilSpecial        MC68HC912BC32 MC68HC912D60 MC68HC912D60A 
syn keyword oilSpecial        MC68HC912DG128A MC68HC912DG128 MCS912DP256 
syn keyword oilSpecial        MCS912DB128 MCS912D64 MCS912DG128 HC12 STAR12
syn keyword oilSpecial        HC12_VECTOR_NAME  HC12_ALLOW_NESTED_ISRS  
" PPC:
syn keyword oilSpecial        MPC555 MPC561 MPC562 MPC563 MPC564 MPC565 MPC566
syn keyword oilSpecial        PPC_NODISPATCHER PPC_ENHANCEDIRQ USE_HW_FP PPC_PREEMPT_ISR  
" SH2:
syn keyword oilSpecial        SH7047 SH7055 
syn keyword oilSpecial        SH2_VBR SH2_VBRADR 
syn keyword oilSpecial        NO_ACTION SET_TO_VBRADR MERGE
" ST30:
syn keyword oilSpecial        ST_SUPERARGUS ST_ZEPHYRUS ST30
syn keyword oilSpecial        ST30_CONNECT  ST30_ALLOW_NESTED_ISRS  
" TMS470:
syn keyword oilSpecial        TMS470R1B31B TMS470_CONNECT   
" V850:
syn keyword oilSpecial        V850SF1 V850DB1 V850ESGB1 
" WIN32X86:
syn keyword oilSpecial        Intel80x86 GUITRACE   

"---------------------------------------------------------------------------
"--Comes from c.vim:
syn match   oilSpecial      display contained "\\\(x\x\+\|\o\{1,3}\|.\|$\)"
syn region  oilString       start=+L\="+ skip=+\\\\\|\\"+ end=+"+ contains=oilSpecial,oilFormat
syn match   oilCharacter    "L\='[^\\]'"
syn match   oilCharacter    "L'[^']*'" contains=oilSpecial

if exists("oil_comment_strings")
  syntax match	oilCommentSkip	contained "^\s*\*\($\|\s\+\)"
  syntax region oilCommentString	contained start=+L\="+ skip=+\\\\\|\\"+ end=+"+ end=+\*/+me=s-1 contains=oilSpecial,oilCommentSkip
  syntax region oilComment2String	contained start=+L\="+ skip=+\\\\\|\\"+ end=+"+ end="$" contains=oilSpecial
  syntax region  oilCommentL	start="//" skip="\\$" end="$" keepend contains=@oilCommentGroup,oilComment2String,oilCharacter,oilNumbersCom,oilSpaceError
  syntax region oilComment	matchgroup=oilCommentStart start="/\*" matchgroup=NONE end="\*/" contains=@oilCommentGroup,oilCommentStartError,oilCommentString,oilCharacter,oilNumbersCom,oilSpaceError
else
  syn region	oilCommentL	start="//" skip="\\$" end="$" keepend contains=@oilCommentGroup,oilSpaceError
  syn region	oilComment	matchgroup=oilCommentStart start="/\*" matchgroup=NONE end="\*/" contains=@oilCommentGroup,oilCommentStartError,oilSpaceError
endif

syntax match	oilCommentError	display "\*/"
syntax match	oilCommentStartError display "/\*"me=e-1 contained

"---------------------------------------------------------------------------
"integer number, or floating point number without a dot and with "f".
syn case ignore
syn match	oilNumbers	display transparent "\<\d\|\.\d" contains=oilNumber,oilFloat,oilOctalError,oilOctal
" Same, but without octal error (for comments)
syn match	oilNumbersCom	display contained transparent "\<\d\|\.\d" contains=oilNumber,oilFloat,oilOctal
syn match	oilNumber	display contained "\d\+\(u\=l\{0,2}\|ll\=u\)\>"
"hex number
syn match	oilNumber	display contained "0x\x\+\(u\=l\{0,2}\|ll\=u\)\>"
" Flag the first zero of an octal number as something special
syn match	oilOctal	display contained "0\o\+\(u\=l\{0,2}\|ll\=u\)\>" contains=oilOctalZero
syn match	oilOctalZero	display contained "\<0"
syn match	oilFloat	display contained "\d\+f"
"floating point number, with dot, optional exponent
syn match	oilFloat	display contained "\d\+\.\d*\(e[-+]\=\d\+\)\=[fl]\="
"floating point number, starting with a dot, optional exponent
syn match	oilFloat	display contained "\.\d\+\(e[-+]\=\d\+\)\=[fl]\=\>"
"floating point number, without dot, with exponent
syn match	oilFloat	display contained "\d\+e[-+]\=\d\+[fl]\=\>"
" flag an octal number with wrong digits
syn match	oilOctalError	display contained "0\o*[89]\d*"
syn case match

"---------------------------------------------------------------------------
" Default highlighting
if version >= 508 || !exists("did_oil_syntax_inits")
  if version < 508
    let did_oil_syntax_inits = 1
    command -nargs=+ HiLink hi link <args>
  else
    command -nargs=+ HiLink hi def link <args>
  endif
  highlight link oilType            Type
  highlight link oilStatement       Statement
  highlight link oilSpecial         Special
  highlight link oilBoolean         Boolean
  highlight link oilNumber          Number
  highlight link oilConstant        Constant
  highlight link oilString          String
  highlight link oilCharacter       Character
  highlight link oilComment         Comment
  highlight link oilCommentStart	oilComment
  delcommand HiLink
endif

let b:current_syntax = "oil"

