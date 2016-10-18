#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-11.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@gtlWatchpointInstruction execute'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWatchpointInstruction_execute (const cPtr_gtlInstruction * inObject,
                                                              GALGAS_gtlContext & ioArgument_context,
                                                              GALGAS_gtlData & /* ioArgument_vars */,
                                                              GALGAS_library & /* ioArgument_lib */,
                                                              GALGAS_string & /* ioArgument_outputString */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlWatchpointInstruction * object = (const cPtr_gtlWatchpointInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlWatchpointInstruction) ;
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_50272 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setWatchpoint ((cPtr_gtlContext *) ptr_50272, object->mProperty_watchExpression, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1702)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWatchpointInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlWatchpointInstruction.mSlotID,
                                extensionMethod_gtlWatchpointInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWatchpointInstruction_execute (defineExtensionMethod_gtlWatchpointInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@gtlWatchpointInstruction display'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWatchpointInstruction_display (const cPtr_gtlInstruction * inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlWatchpointInstruction * object = (const cPtr_gtlWatchpointInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlWatchpointInstruction) ;
  inCompiler->printMessage (GALGAS_string ("watch ( ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) object->mProperty_watchExpression.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1707)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1707)).add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1707))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1707)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWatchpointInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlWatchpointInstruction.mSlotID,
                                extensionMethod_gtlWatchpointInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWatchpointInstruction_display (defineExtensionMethod_gtlWatchpointInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlWatchpointListInstruction execute'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWatchpointListInstruction_execute (const cPtr_gtlInstruction * /* inObject */,
                                                                  GALGAS_gtlContext & ioArgument_context,
                                                                  GALGAS_gtlData & /* ioArgument_vars */,
                                                                  GALGAS_library & /* ioArgument_lib */,
                                                                  GALGAS_string & /* ioArgument_outputString */,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listWatchpoints ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1723)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWatchpointListInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlWatchpointListInstruction.mSlotID,
                                extensionMethod_gtlWatchpointListInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWatchpointListInstruction_execute (defineExtensionMethod_gtlWatchpointListInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlWatchpointListInstruction display'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWatchpointListInstruction_display (const cPtr_gtlInstruction * /* inObject */,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("watch")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1728)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWatchpointListInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlWatchpointListInstruction.mSlotID,
                                extensionMethod_gtlWatchpointListInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWatchpointListInstruction_display (defineExtensionMethod_gtlWatchpointListInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@gtlWatchpointDeleteInstruction execute'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWatchpointDeleteInstruction_execute (const cPtr_gtlInstruction * inObject,
                                                                    GALGAS_gtlContext & ioArgument_context,
                                                                    GALGAS_gtlData & /* ioArgument_vars */,
                                                                    GALGAS_library & /* ioArgument_lib */,
                                                                    GALGAS_string & /* ioArgument_outputString */,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlWatchpointDeleteInstruction * object = (const cPtr_gtlWatchpointDeleteInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlWatchpointDeleteInstruction) ;
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_51458 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteWatchpoint ((cPtr_gtlContext *) ptr_51458, object->mProperty_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1745)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWatchpointDeleteInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlWatchpointDeleteInstruction.mSlotID,
                                extensionMethod_gtlWatchpointDeleteInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWatchpointDeleteInstruction_execute (defineExtensionMethod_gtlWatchpointDeleteInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@gtlWatchpointDeleteInstruction display'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWatchpointDeleteInstruction_display (const cPtr_gtlInstruction * inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlWatchpointDeleteInstruction * object = (const cPtr_gtlWatchpointDeleteInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlWatchpointDeleteInstruction) ;
  inCompiler->printMessage (GALGAS_string ("watch not ").add_operation (object->mProperty_numToDelete.getter_bigint (SOURCE_FILE ("gtl_debugger.galgas", 1750)).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1750)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1750))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1750)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWatchpointDeleteInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlWatchpointDeleteInstruction.mSlotID,
                                extensionMethod_gtlWatchpointDeleteInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWatchpointDeleteInstruction_display (defineExtensionMethod_gtlWatchpointDeleteInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Overriding extension method '@gtlWatchpointDeleteAllInstruction execute'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWatchpointDeleteAllInstruction_execute (const cPtr_gtlInstruction * /* inObject */,
                                                                       GALGAS_gtlContext & ioArgument_context,
                                                                       GALGAS_gtlData & /* ioArgument_vars */,
                                                                       GALGAS_library & /* ioArgument_lib */,
                                                                       GALGAS_string & /* ioArgument_outputString */,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_52067 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteAllWatchpoints ((cPtr_gtlContext *) ptr_52067, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1766)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWatchpointDeleteAllInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlWatchpointDeleteAllInstruction.mSlotID,
                                extensionMethod_gtlWatchpointDeleteAllInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWatchpointDeleteAllInstruction_execute (defineExtensionMethod_gtlWatchpointDeleteAllInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Overriding extension method '@gtlWatchpointDeleteAllInstruction display'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlWatchpointDeleteAllInstruction_display (const cPtr_gtlInstruction * /* inObject */,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("watch not all")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1771)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlWatchpointDeleteAllInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlWatchpointDeleteAllInstruction.mSlotID,
                                extensionMethod_gtlWatchpointDeleteAllInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlWatchpointDeleteAllInstruction_display (defineExtensionMethod_gtlWatchpointDeleteAllInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@gtlListInstruction execute'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlListInstruction_execute (const cPtr_gtlInstruction * inObject,
                                                        GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & /* ioArgument_vars */,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlListInstruction * object = (const cPtr_gtlListInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlListInstruction) ;
  callExtensionMethod_hereWeAre ((const cPtr_gtlContext *) ioArgument_context.ptr (), object->mProperty_window, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1788)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlListInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlListInstruction.mSlotID,
                                extensionMethod_gtlListInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlListInstruction_execute (defineExtensionMethod_gtlListInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@gtlListInstruction display'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlListInstruction_display (const cPtr_gtlInstruction * inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlListInstruction * object = (const cPtr_gtlListInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlListInstruction) ;
  inCompiler->printMessage (GALGAS_string ("list ").add_operation (object->mProperty_window.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1793)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1793))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1793)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlListInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlListInstruction.mSlotID,
                                extensionMethod_gtlListInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlListInstruction_display (defineExtensionMethod_gtlListInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@gtlHistoryInstruction execute'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlHistoryInstruction_execute (const cPtr_gtlInstruction * /* inObject */,
                                                           GALGAS_gtlContext & ioArgument_context,
                                                           GALGAS_gtlData & /* ioArgument_vars */,
                                                           GALGAS_library & /* ioArgument_lib */,
                                                           GALGAS_string & /* ioArgument_outputString */,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listHistory ((const cPtr_debugCommandInput *) ioArgument_context.getter_debuggerContext (SOURCE_FILE ("gtl_debugger.galgas", 1809)).getter_commandInput (SOURCE_FILE ("gtl_debugger.galgas", 1809)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1809)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlHistoryInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlHistoryInstruction.mSlotID,
                                extensionMethod_gtlHistoryInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlHistoryInstruction_execute (defineExtensionMethod_gtlHistoryInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@gtlHistoryInstruction display'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlHistoryInstruction_display (const cPtr_gtlInstruction * /* inObject */,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("hist")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1814)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlHistoryInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlHistoryInstruction.mSlotID,
                                extensionMethod_gtlHistoryInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlHistoryInstruction_display (defineExtensionMethod_gtlHistoryInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@gtlLoadInstruction execute'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLoadInstruction_execute (const cPtr_gtlInstruction * inObject,
                                                        GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & ioArgument_vars,
                                                        GALGAS_library & ioArgument_lib,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLoadInstruction * object = (const cPtr_gtlLoadInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLoadInstruction) ;
  extensionMethod_loadCommandFile (object->mProperty_fileName, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1831)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLoadInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlLoadInstruction.mSlotID,
                                extensionMethod_gtlLoadInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLoadInstruction_execute (defineExtensionMethod_gtlLoadInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@gtlLoadInstruction display'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlLoadInstruction_display (const cPtr_gtlInstruction * inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlLoadInstruction * object = (const cPtr_gtlLoadInstruction *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLoadInstruction) ;
  inCompiler->printMessage (GALGAS_string ("load \"").add_operation (object->mProperty_fileName, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1836)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1836))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1836)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlLoadInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlLoadInstruction.mSlotID,
                                extensionMethod_gtlLoadInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlLoadInstruction_display (defineExtensionMethod_gtlLoadInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@gtlHelpInstruction execute'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlHelpInstruction_execute (const cPtr_gtlInstruction * /* inObject */,
                                                        GALGAS_gtlContext & /* ioArgument_context */,
                                                        GALGAS_gtlData & /* ioArgument_vars */,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("Available commands:\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1852)) ;
  inCompiler->printMessage (GALGAS_string ("  break <filename>:<line>        : set a breakpoint at <line> in file <filename>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1853)) ;
  inCompiler->printMessage (GALGAS_string ("  break <line>                   : set a breakpoint at <line> in the current file\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1854)) ;
  inCompiler->printMessage (GALGAS_string ("  break                          : lists the breakpoints\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1855)) ;
  inCompiler->printMessage (GALGAS_string ("  break not <num>                : delete breakpoint at index <num>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1856)) ;
  inCompiler->printMessage (GALGAS_string ("  break not all                  : delete all breakpoints\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1857)) ;
  inCompiler->printMessage (GALGAS_string ("  cont                           : continue execution until the next breakpoint or the end\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1858)) ;
  inCompiler->printMessage (GALGAS_string ("  display <variable>             : display variable <variable>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1859)) ;
  inCompiler->printMessage (GALGAS_string ("  do <command>                   : do a command each time a step is done\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1860)) ;
  inCompiler->printMessage (GALGAS_string ("  do                             : list the do commands\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1861)) ;
  inCompiler->printMessage (GALGAS_string ("  do not <num>                   : delete the do command at index <num>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1862)) ;
  inCompiler->printMessage (GALGAS_string ("  do not all                     : delete all the do commands\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1863)) ;
  inCompiler->printMessage (GALGAS_string ("  hist                           : display the command history\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1864)) ;
  inCompiler->printMessage (GALGAS_string ("  if <expression> then ...       : same as GTL if instruction. Must be on one line though\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1865)) ;
  inCompiler->printMessage (GALGAS_string ("  list                           : lists instructions +/- 5 around current one\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1866)) ;
  inCompiler->printMessage (GALGAS_string ("  list <num>                     : lists instructions +/- <num> around current one\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1867)) ;
  inCompiler->printMessage (GALGAS_string ("  let <variable> := <expression> : compute <expression> and set <variable> to the result\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1868)) ;
  inCompiler->printMessage (GALGAS_string ("  load <filename>                : load commands from file <filename>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1869)) ;
  inCompiler->printMessage (GALGAS_string ("  print <expression>             : prints the <expression>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1870)) ;
  inCompiler->printMessage (GALGAS_string ("  step                           : step one instruction\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1871)) ;
  inCompiler->printMessage (GALGAS_string ("  unlet <variable>               : delete <variable>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1872)) ;
  inCompiler->printMessage (GALGAS_string ("  variables                      : display all variables in scope\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1873)) ;
  inCompiler->printMessage (GALGAS_string ("  watch (<expression>)           : set a watchpoint matching the boolean <expression>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1874)) ;
  inCompiler->printMessage (GALGAS_string ("  watch                          : lists the watchpoints\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1875)) ;
  inCompiler->printMessage (GALGAS_string ("  watch not <num>                : delete watchpoint at index <num>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1876)) ;
  inCompiler->printMessage (GALGAS_string ("  watch not all                  : delete all watchpoints\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1877)) ;
  inCompiler->printMessage (GALGAS_string ("  <return>                       : step one instruction\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1878)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlHelpInstruction_execute (void) {
  enterExtensionMethod_execute (kTypeDescriptor_GALGAS_gtlHelpInstruction.mSlotID,
                                extensionMethod_gtlHelpInstruction_execute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlHelpInstruction_execute (defineExtensionMethod_gtlHelpInstruction_execute, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@gtlHelpInstruction display'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlHelpInstruction_display (const cPtr_gtlInstruction * /* inObject */,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("help")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1883)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlHelpInstruction_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_gtlHelpInstruction.mSlotID,
                                extensionMethod_gtlHelpInstruction_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlHelpInstruction_display (defineExtensionMethod_gtlHelpInstruction_display, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Bool options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_goil_5F_options_arxmlDisplayOil ("goil_options",
                                         "arxmlDisplayOil",
                                         0,
                                         "arxmlPrintOil",
                                         "Display an Oil version while parsing an arxml file") ;

C_BoolCommandLineOption gOption_goil_5F_options_generate_5F_log ("goil_options",
                                         "generate_log",
                                         108,
                                         "logfile",
                                         "generate a goil.log file containing the a log of the compilation") ;

C_BoolCommandLineOption gOption_goil_5F_options_pierreOption ("goil_options",
                                         "pierreOption",
                                         0,
                                         "pierre",
                                         "Special option to pass a galgas bug to Pierre") ;

C_BoolCommandLineOption gOption_goil_5F_options_warnMultiple ("goil_options",
                                         "warnMultiple",
                                         0,
                                         "warn-multiple",
                                         "Emit a warning if an object not defined for the first time in the implementation does not have the same multiple attribute as in the first definition") ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               UInt options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String options                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

C_StringCommandLineOption gOption_goil_5F_options_config ("goil_options",
                                         "config",
                                         99,
                                         "config",
                                         "Specifies the OIL config file used by goil",
                                         "config") ;

C_StringCommandLineOption gOption_goil_5F_options_passOption ("goil_options",
                                         "passOption",
                                         111,
                                         "option",
                                         "Pass options to the template root script",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_project_5F_dir ("goil_options",
                                         "project_dir",
                                         112,
                                         "project",
                                         "Specifies project directory (by default, the project directory is the name of the oil file, without the .oil extension)",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_root ("goil_options",
                                         "root",
                                         114,
                                         "root",
                                         "Specifies the root template file to use to generate the output files",
                                         "root") ;

C_StringCommandLineOption gOption_goil_5F_options_target_5F_platform ("goil_options",
                                         "target_platform",
                                         116,
                                         "target",
                                         "Specifies target platform. Available target platform are located in machines/ directory. Targets are specified using a path like avr/arduino.",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_template_5F_dir ("goil_options",
                                         "template_dir",
                                         0,
                                         "templates",
                                         "Specifies template directory (used by goil for code generation)",
                                         "") ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String List options                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'checkEnums'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_checkEnums (const GALGAS_impEnumType & constinArgument_previousEnum,
                                 const GALGAS_impEnumType & constinArgument_newEnum,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_inside ; // Returned variable
  GALGAS_stringset var_newValues_18418 = constinArgument_newEnum.getter_valuesMap (SOURCE_FILE ("implementation_parser.galgas", 665)).getter_keySet (SOURCE_FILE ("implementation_parser.galgas", 665)) ;
  GALGAS_stringset var_previousValues_18477 = constinArgument_previousEnum.getter_valuesMap (SOURCE_FILE ("implementation_parser.galgas", 666)).getter_keySet (SOURCE_FILE ("implementation_parser.galgas", 666)) ;
  result_inside = GALGAS_bool (kIsEqual, var_newValues_18418.operator_and (var_previousValues_18477 COMMA_SOURCE_FILE ("implementation_parser.galgas", 667)).objectCompare (var_newValues_18418)) ;
  const enumGalgasBool test_0 = result_inside.operator_not (SOURCE_FILE ("implementation_parser.galgas", 668)).boolEnum () ;
  if (kBoolTrue == test_0) {
    cEnumerator_locationList enumerator_18621 (constinArgument_newEnum.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 669)), kENUMERATION_UP) ;
    while (enumerator_18621.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (enumerator_18621.current_location (HERE), GALGAS_string ("ENUM is not within previous enum declaration"), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 670)) ;
      enumerator_18621.gotoNextObject () ;
    }
    cEnumerator_locationList enumerator_18740 (constinArgument_previousEnum.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 672)), kENUMERATION_UP) ;
    while (enumerator_18740.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (enumerator_18740.current_location (HERE), GALGAS_string ("previous ENUM declaration was here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 673)) ;
      enumerator_18740.gotoNextObject () ;
    }
  }
//---
  return result_inside ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkEnums [3] = {
  & kTypeDescriptor_GALGAS_impEnumType,
  & kTypeDescriptor_GALGAS_impEnumType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkEnums (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_impEnumType operand0 = GALGAS_impEnumType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_impEnumType operand1 = GALGAS_impEnumType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  return function_checkEnums (operand0,
                              operand1,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkEnums ("checkEnums",
                                                            functionWithGenericHeader_checkEnums,
                                                            & kTypeDescriptor_GALGAS_bool,
                                                            2,
                                                            functionArgs_checkEnums) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'checkRanged'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_checkRanged (const GALGAS_impRangedType & constinArgument_previousRanged,
                                  const GALGAS_impRangedType & constinArgument_newRanged,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_inside ; // Returned variable
  callExtensionMethod_enclose ((const cPtr_attributeRange *) constinArgument_previousRanged.getter_setOrRange (SOURCE_FILE ("implementation_parser.galgas", 686)).ptr (), result_inside, constinArgument_newRanged.getter_setOrRange (SOURCE_FILE ("implementation_parser.galgas", 686)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 686)) ;
  const enumGalgasBool test_0 = result_inside.operator_not (SOURCE_FILE ("implementation_parser.galgas", 687)).boolEnum () ;
  if (kBoolTrue == test_0) {
    cEnumerator_locationList enumerator_19103 (constinArgument_newRanged.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 688)), kENUMERATION_UP) ;
    while (enumerator_19103.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (enumerator_19103.current_location (HERE), GALGAS_string ("new range or set is not within previous range or set declaration"), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 689)) ;
      enumerator_19103.gotoNextObject () ;
    }
    cEnumerator_locationList enumerator_19244 (constinArgument_previousRanged.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 691)), kENUMERATION_UP) ;
    while (enumerator_19244.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (enumerator_19244.current_location (HERE), GALGAS_string ("previous range or set declaration was here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 692)) ;
      enumerator_19244.gotoNextObject () ;
    }
  }
//---
  return result_inside ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkRanged [3] = {
  & kTypeDescriptor_GALGAS_impRangedType,
  & kTypeDescriptor_GALGAS_impRangedType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkRanged (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_impRangedType operand0 = GALGAS_impRangedType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_impRangedType operand1 = GALGAS_impRangedType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  return function_checkRanged (operand0,
                               operand1,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkRanged ("checkRanged",
                                                             functionWithGenericHeader_checkRanged,
                                                             & kTypeDescriptor_GALGAS_bool,
                                                             2,
                                                             functionArgs_checkRanged) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Function 'checkNewTypeWithinPreviousType'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_checkNewTypeWithinPreviousType (const GALGAS_lstring & constinArgument_name,
                                                     const GALGAS_impType & constinArgument_previousType,
                                                     const GALGAS_impType & constinArgument_newType,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, constinArgument_newType.getter_type (SOURCE_FILE ("implementation_parser.galgas", 703)).objectCompare (constinArgument_previousType.getter_type (SOURCE_FILE ("implementation_parser.galgas", 703)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    cEnumerator_locationList enumerator_19559 (constinArgument_newType.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 704)), kENUMERATION_UP) ;
    while (enumerator_19559.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (enumerator_19559.current_location (HERE), constinArgument_name.getter_string (SOURCE_FILE ("implementation_parser.galgas", 705)).add_operation (GALGAS_string (" should be a "), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 705)).add_operation (extensionGetter_oilType (constinArgument_previousType.getter_type (SOURCE_FILE ("implementation_parser.galgas", 705)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 705)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 705)), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 705)) ;
      enumerator_19559.gotoNextObject () ;
    }
    cEnumerator_locationList enumerator_19691 (constinArgument_previousType.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 707)), kENUMERATION_UP) ;
    while (enumerator_19691.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (enumerator_19691.current_location (HERE), constinArgument_name.getter_string (SOURCE_FILE ("implementation_parser.galgas", 708)).add_operation (GALGAS_string (" was previouly defined here"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 708)), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 708)) ;
      enumerator_19691.gotoNextObject () ;
    }
    result_result = GALGAS_bool (false) ;
  }else if (kBoolFalse == test_0) {
    if (constinArgument_previousType.isValid ()) {
      if (constinArgument_previousType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
        GALGAS_impEnumType cast_19854_previousEnum ((cPtr_impEnumType *) constinArgument_previousType.ptr ()) ;
        if (constinArgument_newType.isValid ()) {
          if (constinArgument_newType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
            GALGAS_impEnumType cast_19910_newEnum ((cPtr_impEnumType *) constinArgument_newType.ptr ()) ;
            result_result = function_checkEnums (cast_19854_previousEnum, cast_19910_newEnum, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 716)) ;
          }
        }
      }else if (constinArgument_previousType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
        GALGAS_impRangedType cast_20021_previousRanged ((cPtr_impRangedType *) constinArgument_previousType.ptr ()) ;
        if (constinArgument_newType.isValid ()) {
          if (constinArgument_newType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
            GALGAS_impRangedType cast_20081_newRanged ((cPtr_impRangedType *) constinArgument_newType.ptr ()) ;
            result_result = function_checkRanged (cast_20021_previousRanged, cast_20081_newRanged, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 721)) ;
          }
        }
      }else{
        result_result = GALGAS_bool (true) ;
      }
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkNewTypeWithinPreviousType [4] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_impType,
  & kTypeDescriptor_GALGAS_impType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkNewTypeWithinPreviousType (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_impType operand1 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_impType operand2 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_checkNewTypeWithinPreviousType (operand0,
                                                  operand1,
                                                  operand2,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkNewTypeWithinPreviousType ("checkNewTypeWithinPreviousType",
                                                                                functionWithGenericHeader_checkNewTypeWithinPreviousType,
                                                                                & kTypeDescriptor_GALGAS_bool,
                                                                                3,
                                                                                functionArgs_checkNewTypeWithinPreviousType) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'buildRange'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange function_buildRange (const GALGAS_dataType & constinArgument_type,
                                           const GALGAS_object_5F_t & constinArgument_start,
                                           const GALGAS_object_5F_t & constinArgument_stop,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_attributeRange result_range ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 734)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_range = GALGAS_uint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 735)), function_uint_33__32_OrError (constinArgument_start, GALGAS_string ("UINT32 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 735)), function_uint_33__32_OrError (constinArgument_stop, GALGAS_string ("UINT32 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 735))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 735)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 736)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_range = GALGAS_sint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 737)), function_sint_33__32_OrError (constinArgument_start, GALGAS_string ("SINT32 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 737)), function_sint_33__32_OrError (constinArgument_stop, GALGAS_string ("SINT32 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 737))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 737)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 738)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_range = GALGAS_uint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 739)), function_uint_36__34_OrError (constinArgument_start, GALGAS_string ("UINT64 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 739)), function_uint_36__34_OrError (constinArgument_stop, GALGAS_string ("UINT64 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 739))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 739)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 740)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_range = GALGAS_sint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 741)), function_sint_36__34_OrError (constinArgument_start, GALGAS_string ("SINT64 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 741)), function_sint_36__34_OrError (constinArgument_stop, GALGAS_string ("SINT64 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 741))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 741)) ;
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_parser.galgas", 742)))).boolEnum () ;
          if (kBoolTrue == test_4) {
            result_range = GALGAS_floatAttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 743)), function_floatOrError (constinArgument_start, GALGAS_string ("FLOAT Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 743)), function_floatOrError (constinArgument_stop, GALGAS_string ("FLOAT Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 743))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 743)) ;
          }else if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 745)), GALGAS_string ("internal. Unknown number type"), fixItArray5  COMMA_SOURCE_FILE ("implementation_parser.galgas", 745)) ;
            result_range.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_range ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_buildRange [4] = {
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_object_5F_t,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_buildRange (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_dataType operand0 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_object_5F_t operand1 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_object_5F_t operand2 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  return function_buildRange (operand0,
                              operand1,
                              operand2,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_buildRange ("buildRange",
                                                            functionWithGenericHeader_buildRange,
                                                            & kTypeDescriptor_GALGAS_attributeRange,
                                                            3,
                                                            functionArgs_buildRange) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithUInt32List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithUInt_33__32_List (const GALGAS_uint_33__32_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_uint_33__32_List enumerator_2583 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_2583.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2583.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 85)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 85)) ;
    if (enumerator_2583.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 85)) ;
    }
    enumerator_2583.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_uint_33__32_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithUInt_33__32_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_uint_33__32_List operand0 = GALGAS_uint_33__32_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithUInt_33__32_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithUInt_33__32_List ("stringWithUInt32List",
                                                                            functionWithGenericHeader_stringWithUInt_33__32_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithUInt_33__32_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithUInt64List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithUInt_36__34_List (const GALGAS_uint_36__34_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_uint_36__34_List enumerator_2745 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_2745.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2745.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 90)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 90)) ;
    if (enumerator_2745.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 90)) ;
    }
    enumerator_2745.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithUInt_36__34_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_uint_36__34_List operand0 = GALGAS_uint_36__34_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithUInt_36__34_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithUInt_36__34_List ("stringWithUInt64List",
                                                                            functionWithGenericHeader_stringWithUInt_36__34_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithUInt_36__34_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithSInt32List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithSInt_33__32_List (const GALGAS_sint_33__32_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_sint_33__32_List enumerator_2907 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_2907.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2907.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 95)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 95)) ;
    if (enumerator_2907.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 95)) ;
    }
    enumerator_2907.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_sint_33__32_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithSInt_33__32_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_sint_33__32_List operand0 = GALGAS_sint_33__32_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithSInt_33__32_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithSInt_33__32_List ("stringWithSInt32List",
                                                                            functionWithGenericHeader_stringWithSInt_33__32_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithSInt_33__32_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithSInt64List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithSInt_36__34_List (const GALGAS_sint_36__34_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_sint_36__34_List enumerator_3069 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_3069.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_3069.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 100)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 100)) ;
    if (enumerator_3069.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 100)) ;
    }
    enumerator_3069.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_sint_36__34_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithSInt_36__34_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_sint_36__34_List operand0 = GALGAS_sint_36__34_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithSInt_36__34_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithSInt_36__34_List ("stringWithSInt64List",
                                                                            functionWithGenericHeader_stringWithSInt_36__34_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithSInt_36__34_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithFloatList'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithFloatList (const GALGAS_floatList & constinArgument_values,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_floatList enumerator_3229 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_3229.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_3229.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 105)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 105)) ;
    if (enumerator_3229.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 105)) ;
    }
    enumerator_3229.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithFloatList [2] = {
  & kTypeDescriptor_GALGAS_floatList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithFloatList (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_floatList operand0 = GALGAS_floatList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  return function_stringWithFloatList (operand0,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithFloatList ("stringWithFloatList",
                                                                     functionWithGenericHeader_stringWithFloatList,
                                                                     & kTypeDescriptor_GALGAS_string,
                                                                     1,
                                                                     functionArgs_stringWithFloatList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'uint32ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List function_uint_33__32_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_33__32_List result_result ; // Returned variable
  result_result = GALGAS_uint_33__32_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 109)) ;
  cEnumerator_numberList enumerator_3421 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_3421.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3421.current_location (HERE), function_uint_33__32_OrError (enumerator_3421.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 111))  COMMA_SOURCE_FILE ("implementation_types.galgas", 111)) ;
    enumerator_3421.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_33__32_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_uint_33__32_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_33__32_ListWithNumberList ("uint32ListWithNumberList",
                                                                                functionWithGenericHeader_uint_33__32_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_uint_33__32_List,
                                                                                1,
                                                                                functionArgs_uint_33__32_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'sint32ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List function_sint_33__32_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_33__32_List result_result ; // Returned variable
  result_result = GALGAS_sint_33__32_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 116)) ;
  cEnumerator_numberList enumerator_3619 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_3619.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3619.current_location (HERE), function_sint_33__32_OrError (enumerator_3619.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 118))  COMMA_SOURCE_FILE ("implementation_types.galgas", 118)) ;
    enumerator_3619.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_33__32_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_sint_33__32_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_33__32_ListWithNumberList ("sint32ListWithNumberList",
                                                                                functionWithGenericHeader_sint_33__32_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_sint_33__32_List,
                                                                                1,
                                                                                functionArgs_sint_33__32_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'uint64ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List function_uint_36__34_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_List result_result ; // Returned variable
  result_result = GALGAS_uint_36__34_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 123)) ;
  cEnumerator_numberList enumerator_3817 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_3817.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3817.current_location (HERE), function_uint_36__34_OrError (enumerator_3817.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 125))  COMMA_SOURCE_FILE ("implementation_types.galgas", 125)) ;
    enumerator_3817.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_36__34_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_uint_36__34_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_36__34_ListWithNumberList ("uint64ListWithNumberList",
                                                                                functionWithGenericHeader_uint_36__34_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_uint_36__34_List,
                                                                                1,
                                                                                functionArgs_uint_36__34_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'sint64ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List function_sint_36__34_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_List result_result ; // Returned variable
  result_result = GALGAS_sint_36__34_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 130)) ;
  cEnumerator_numberList enumerator_4015 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_4015.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_4015.current_location (HERE), function_sint_36__34_OrError (enumerator_4015.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 132))  COMMA_SOURCE_FILE ("implementation_types.galgas", 132)) ;
    enumerator_4015.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_36__34_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_sint_36__34_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_36__34_ListWithNumberList ("sint64ListWithNumberList",
                                                                                functionWithGenericHeader_sint_36__34_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_sint_36__34_List,
                                                                                1,
                                                                                functionArgs_sint_36__34_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'floatListWithNumberList'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList function_floatListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_floatList result_result ; // Returned variable
  result_result = GALGAS_floatList::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 137)) ;
  cEnumerator_numberList enumerator_4210 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_4210.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_4210.current_location (HERE), function_floatOrError (enumerator_4210.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 139))  COMMA_SOURCE_FILE ("implementation_types.galgas", 139)) ;
    enumerator_4210.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_floatListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_floatListWithNumberList (C_Compiler * inCompiler,
                                                                        const cObjectArray & inEffectiveParameterArray,
                                                                        const GALGAS_location & /* inErrorLocation */
                                                                        COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_floatListWithNumberList (operand0,
                                           inCompiler
                                           COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_floatListWithNumberList ("floatListWithNumberList",
                                                                         functionWithGenericHeader_floatListWithNumberList,
                                                                         & kTypeDescriptor_GALGAS_floatList,
                                                                         1,
                                                                         functionArgs_floatListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@noRange enclose'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_noRange_enclose (const cPtr_attributeRange * /* inObject */,
                                             GALGAS_bool & outArgument_isWithin,
                                             const GALGAS_attributeRange /* constinArgument_value */,
                                             C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (true) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_noRange_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_noRange.mSlotID,
                                extensionMethod_noRange_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_noRange_enclose (defineExtensionMethod_noRange_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@uint32AttributeSet enclose'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_33__32_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_33__32_AttributeSet * object = (const cPtr_uint_33__32_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_uint_33__32_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet) {
      GALGAS_uint_33__32_AttributeSet cast_4982_set ((cPtr_uint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_uint_33__32_List enumerator_5020 (cast_4982_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 172)), kENUMERATION_UP) ;
      while (enumerator_5020.hasCurrentObject ()) {
        GALGAS_bool var_ok_5038 = GALGAS_bool (false) ;
        cEnumerator_uint_33__32_List enumerator_5079 (object->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_5079.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_5020.current_value (HERE).objectCompare (enumerator_5079.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_5038 = GALGAS_bool (true) ;
          }
          enumerator_5079.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_5038 COMMA_SOURCE_FILE ("implementation_types.galgas", 179)) ;
        enumerator_5020.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 182)), GALGAS_string ("Incompatible set. Should be a UINT32 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 182)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 183)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_33__32_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_33__32_AttributeSet.mSlotID,
                                extensionMethod_uint_33__32_AttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_33__32_AttributeSet_enclose (defineExtensionMethod_uint_33__32_AttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@uint64AttributeSet enclose'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_36__34_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_36__34_AttributeSet * object = (const cPtr_uint_36__34_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_uint_36__34_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet) {
      GALGAS_uint_36__34_AttributeSet cast_5593_set ((cPtr_uint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_uint_36__34_List enumerator_5631 (cast_5593_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 196)), kENUMERATION_UP) ;
      while (enumerator_5631.hasCurrentObject ()) {
        GALGAS_bool var_ok_5649 = GALGAS_bool (false) ;
        cEnumerator_uint_36__34_List enumerator_5690 (object->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_5690.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_5631.current_value (HERE).objectCompare (enumerator_5690.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_5649 = GALGAS_bool (true) ;
          }
          enumerator_5690.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_5649 COMMA_SOURCE_FILE ("implementation_types.galgas", 203)) ;
        enumerator_5631.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 206)), GALGAS_string ("Incompatible set. Should be a UINT64 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 206)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 207)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_36__34_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_36__34_AttributeSet.mSlotID,
                                extensionMethod_uint_36__34_AttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_36__34_AttributeSet_enclose (defineExtensionMethod_uint_36__34_AttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@sint32AttributeSet enclose'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_33__32_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_33__32_AttributeSet * object = (const cPtr_sint_33__32_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_sint_33__32_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet) {
      GALGAS_sint_33__32_AttributeSet cast_6204_set ((cPtr_sint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_sint_33__32_List enumerator_6242 (cast_6204_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 220)), kENUMERATION_UP) ;
      while (enumerator_6242.hasCurrentObject ()) {
        GALGAS_bool var_ok_6260 = GALGAS_bool (false) ;
        cEnumerator_sint_33__32_List enumerator_6301 (object->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_6301.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_6242.current_value (HERE).objectCompare (enumerator_6301.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_6260 = GALGAS_bool (true) ;
          }
          enumerator_6301.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_6260 COMMA_SOURCE_FILE ("implementation_types.galgas", 227)) ;
        enumerator_6242.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 230)), GALGAS_string ("Incompatible set. Should be a INT32 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 230)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 231)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_33__32_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_33__32_AttributeSet.mSlotID,
                                extensionMethod_sint_33__32_AttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_33__32_AttributeSet_enclose (defineExtensionMethod_sint_33__32_AttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@sint64AttributeSet enclose'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_36__34_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_36__34_AttributeSet * object = (const cPtr_sint_36__34_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_sint_36__34_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet) {
      GALGAS_sint_36__34_AttributeSet cast_6814_set ((cPtr_sint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_sint_36__34_List enumerator_6852 (cast_6814_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 244)), kENUMERATION_UP) ;
      while (enumerator_6852.hasCurrentObject ()) {
        GALGAS_bool var_ok_6870 = GALGAS_bool (false) ;
        cEnumerator_sint_36__34_List enumerator_6911 (object->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_6911.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_6852.current_value (HERE).objectCompare (enumerator_6911.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_6870 = GALGAS_bool (true) ;
          }
          enumerator_6911.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_6870 COMMA_SOURCE_FILE ("implementation_types.galgas", 251)) ;
        enumerator_6852.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 254)), GALGAS_string ("Incompatible set. Should be a INT64 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 254)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 255)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_36__34_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_36__34_AttributeSet.mSlotID,
                                extensionMethod_sint_36__34_AttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_36__34_AttributeSet_enclose (defineExtensionMethod_sint_36__34_AttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@floatAttributeSet enclose'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_floatAttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                       GALGAS_bool & outArgument_isWithin,
                                                       const GALGAS_attributeRange constinArgument_value,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_floatAttributeSet * object = (const cPtr_floatAttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_floatAttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeSet) {
      GALGAS_floatAttributeSet cast_7422_set ((cPtr_floatAttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_floatList enumerator_7460 (cast_7422_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 268)), kENUMERATION_UP) ;
      while (enumerator_7460.hasCurrentObject ()) {
        GALGAS_bool var_ok_7478 = GALGAS_bool (false) ;
        cEnumerator_floatList enumerator_7519 (object->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_7519.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_7460.current_value (HERE).objectCompare (enumerator_7519.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_7478 = GALGAS_bool (true) ;
          }
          enumerator_7519.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_7478 COMMA_SOURCE_FILE ("implementation_types.galgas", 275)) ;
        enumerator_7460.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 278)), GALGAS_string ("Incompatible set. Should be a FLOAT set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 278)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 279)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_floatAttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_floatAttributeSet.mSlotID,
                                extensionMethod_floatAttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_floatAttributeSet_enclose (defineExtensionMethod_floatAttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@uint32AttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_33__32_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_33__32_AttributeMinMax * object = (const cPtr_uint_33__32_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_uint_33__32_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax) {
      GALGAS_uint_33__32_AttributeMinMax cast_8045_minmax ((cPtr_uint_33__32_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_8045_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 293)).objectCompare (object->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_8045_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 293)).objectCompare (object->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 293)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet) {
      GALGAS_uint_33__32_AttributeSet cast_8165_set ((cPtr_uint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_uint_33__32_List enumerator_8218 (cast_8165_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 298)), kENUMERATION_UP) ;
      while (enumerator_8218.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_8218.current_value (HERE).objectCompare (object->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_8218.current_value (HERE).objectCompare (object->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 299)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_8218.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 304)), GALGAS_string ("Incompatible set. Should be a UINT32 range or UINT32 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 304)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 305)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_33__32_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax.mSlotID,
                                extensionMethod_uint_33__32_AttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_33__32_AttributeMinMax_enclose (defineExtensionMethod_uint_33__32_AttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@uint64AttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_36__34_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_36__34_AttributeMinMax * object = (const cPtr_uint_36__34_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_uint_36__34_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax) {
      GALGAS_uint_36__34_AttributeMinMax cast_8704_minmax ((cPtr_uint_36__34_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_8704_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 318)).objectCompare (object->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_8704_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 318)).objectCompare (object->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 318)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet) {
      GALGAS_uint_36__34_AttributeSet cast_8824_set ((cPtr_uint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_uint_36__34_List enumerator_8877 (cast_8824_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 323)), kENUMERATION_UP) ;
      while (enumerator_8877.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_8877.current_value (HERE).objectCompare (object->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_8877.current_value (HERE).objectCompare (object->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 324)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_8877.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 329)), GALGAS_string ("Incompatible set. Should be a UINT64 range or UINT64 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 329)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 330)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_36__34_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax.mSlotID,
                                extensionMethod_uint_36__34_AttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_36__34_AttributeMinMax_enclose (defineExtensionMethod_uint_36__34_AttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@sint32AttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_33__32_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_33__32_AttributeMinMax * object = (const cPtr_sint_33__32_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_sint_33__32_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax) {
      GALGAS_sint_33__32_AttributeMinMax cast_9359_minmax ((cPtr_sint_33__32_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_9359_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 343)).objectCompare (object->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_9359_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 343)).objectCompare (object->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 343)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet) {
      GALGAS_sint_33__32_AttributeSet cast_9479_set ((cPtr_sint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_sint_33__32_List enumerator_9532 (cast_9479_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 348)), kENUMERATION_UP) ;
      while (enumerator_9532.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_9532.current_value (HERE).objectCompare (object->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_9532.current_value (HERE).objectCompare (object->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 349)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_9532.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 354)), GALGAS_string ("Incompatible set. Should be a INT32 range or INT32 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 354)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 355)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_33__32_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax.mSlotID,
                                extensionMethod_sint_33__32_AttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_33__32_AttributeMinMax_enclose (defineExtensionMethod_sint_33__32_AttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@sint64AttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_36__34_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_36__34_AttributeMinMax * object = (const cPtr_sint_36__34_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_sint_36__34_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax) {
      GALGAS_sint_36__34_AttributeMinMax cast_10016_minmax ((cPtr_sint_36__34_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_10016_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 368)).objectCompare (object->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_10016_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 368)).objectCompare (object->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 368)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet) {
      GALGAS_sint_36__34_AttributeSet cast_10136_set ((cPtr_sint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_sint_36__34_List enumerator_10189 (cast_10136_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 373)), kENUMERATION_UP) ;
      while (enumerator_10189.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_10189.current_value (HERE).objectCompare (object->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_10189.current_value (HERE).objectCompare (object->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 374)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_10189.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 379)), GALGAS_string ("Incompatible set. Should be a INT64 range or INT64 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 379)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 380)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_36__34_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax.mSlotID,
                                extensionMethod_sint_36__34_AttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_36__34_AttributeMinMax_enclose (defineExtensionMethod_sint_36__34_AttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@floatAttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_floatAttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                          GALGAS_bool & outArgument_isWithin,
                                                          const GALGAS_attributeRange constinArgument_value,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_floatAttributeMinMax * object = (const cPtr_floatAttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_floatAttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeMinMax) {
      GALGAS_floatAttributeMinMax cast_10671_minmax ((cPtr_floatAttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_10671_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 393)).objectCompare (object->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_10671_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 393)).objectCompare (object->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 393)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeSet) {
      GALGAS_floatAttributeSet cast_10790_set ((cPtr_floatAttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_floatList enumerator_10843 (cast_10790_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 398)), kENUMERATION_UP) ;
      while (enumerator_10843.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_10843.current_value (HERE).objectCompare (object->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_10843.current_value (HERE).objectCompare (object->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 399)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_10843.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 404)), GALGAS_string ("Incompatible set. Should be a FLOAT range or FLOAT set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 404)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 405)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_floatAttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_floatAttributeMinMax.mSlotID,
                                extensionMethod_floatAttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_floatAttributeMinMax_enclose (defineExtensionMethod_floatAttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Function 'attributeRangeWithNumberList'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange function_attributeRangeWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                             const GALGAS_dataType & constinArgument_type,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_attributeRange result_range ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 414)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_range = GALGAS_uint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 415)), function_uint_33__32_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 415))  COMMA_SOURCE_FILE ("implementation_types.galgas", 415)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 416)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_range = GALGAS_sint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 417)), function_sint_33__32_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 417))  COMMA_SOURCE_FILE ("implementation_types.galgas", 417)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 418)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_range = GALGAS_uint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 419)), function_uint_36__34_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 419))  COMMA_SOURCE_FILE ("implementation_types.galgas", 419)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 420)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_range = GALGAS_sint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 421)), function_sint_36__34_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 421))  COMMA_SOURCE_FILE ("implementation_types.galgas", 421)) ;
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 422)))).boolEnum () ;
          if (kBoolTrue == test_4) {
            result_range = GALGAS_floatAttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 423)), function_floatListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 423))  COMMA_SOURCE_FILE ("implementation_types.galgas", 423)) ;
          }else if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 425)), GALGAS_string ("internal. Unknown number type"), fixItArray5  COMMA_SOURCE_FILE ("implementation_types.galgas", 425)) ;
            result_range.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_range ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_attributeRangeWithNumberList [3] = {
  & kTypeDescriptor_GALGAS_numberList,
  & kTypeDescriptor_GALGAS_dataType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_attributeRangeWithNumberList (C_Compiler * inCompiler,
                                                                             const cObjectArray & inEffectiveParameterArray,
                                                                             const GALGAS_location & /* inErrorLocation */
                                                                             COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  return function_attributeRangeWithNumberList (operand0,
                                                operand1,
                                                inCompiler
                                                COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_attributeRangeWithNumberList ("attributeRangeWithNumberList",
                                                                              functionWithGenericHeader_attributeRangeWithNumberList,
                                                                              & kTypeDescriptor_GALGAS_attributeRange,
                                                                              2,
                                                                              functionArgs_attributeRangeWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@impStructType mergeWithType'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impStructType_mergeWithType (const cPtr_impType * inObject,
                                                                   GALGAS_impType inArgument_typeToMerge,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impStructType * object = (const cPtr_impStructType *) inObject ;
  macroValidSharedObject (object, cPtr_impStructType) ;
  GALGAS_impStructType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impStructType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impStructType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impStructType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 469)) ;
    }
  }
  GALGAS_impStructType var_castTypeToMerge_12923 = temp_0 ;
  GALGAS_implementationObjectMap var_mergedAttributes_12999 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 470)) ;
  cEnumerator_implementationObjectMap enumerator_13040 (object->mProperty_structAttributes, kENUMERATION_UP) ;
  while (enumerator_13040.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_13067 = enumerator_13040.current_type (HERE) ;
    const enumGalgasBool test_1 = var_castTypeToMerge_12923.getter_structAttributes (SOURCE_FILE ("implementation_types.galgas", 473)).getter_hasKey (enumerator_13040.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 473)) COMMA_SOURCE_FILE ("implementation_types.galgas", 473)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_impType var_subTypeToMerge_13222 ;
      var_castTypeToMerge_12923.getter_structAttributes (SOURCE_FILE ("implementation_types.galgas", 474)).method_get (enumerator_13040.current_lkey (HERE), var_subTypeToMerge_13222, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 474)) ;
      var_mergedAttr_13067 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_13040.current_type (HERE).ptr (), var_subTypeToMerge_13222, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 475)) ;
    }
    {
    var_mergedAttributes_12999.setter_put (enumerator_13040.current_lkey (HERE), var_mergedAttr_13067, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 477)) ;
    }
    enumerator_13040.gotoNextObject () ;
  }
  result_mergedType = GALGAS_impStructType::constructor_new (object->mProperty_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 480)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 480)), object->mProperty_type, object->mProperty_name, object->mProperty_multiple, object->mProperty_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 484)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 484)), var_mergedAttributes_12999  COMMA_SOURCE_FILE ("implementation_types.galgas", 479)) ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impStructType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impStructType.mSlotID,
                                      extensionGetter_impStructType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impStructType_mergeWithType (defineExtensionGetter_impStructType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@impVoid mergeWithType'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impVoid_mergeWithType (const cPtr_impType * /* inObject */,
                                                             GALGAS_impType inArgument_typeToMerge,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  result_mergedType = inArgument_typeToMerge ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impVoid_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impVoid.mSlotID,
                                      extensionGetter_impVoid_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impVoid_mergeWithType (defineExtensionGetter_impVoid_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension getter '@impAutoDefaultType getDefaultValue'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object_5F_t extensionGetter_impAutoDefaultType_getDefaultValue (const cPtr_impType * inObject,
                                                                              C_Compiler * /* inCompiler */
                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_outDefaultValue ; // Returned variable
  const cPtr_impAutoDefaultType * object = (const cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  result_outDefaultValue = object->mProperty_defaultValue ;
//---
  return result_outDefaultValue ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impAutoDefaultType_getDefaultValue (void) {
  enterExtensionGetter_getDefaultValue (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                        extensionGetter_impAutoDefaultType_getDefaultValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impAutoDefaultType_getDefaultValue (defineExtensionGetter_impAutoDefaultType_getDefaultValue, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension setter '@impAutoDefaultType setDefaultValue'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_impAutoDefaultType_setDefaultValue (cPtr_impType * inObject,
                                                                GALGAS_object_5F_t inArgument_inDefaultValue,
                                                                C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_impAutoDefaultType * object = (cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  object->mProperty_defaultValue = inArgument_inDefaultValue ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_impAutoDefaultType_setDefaultValue (void) {
  enterExtensionSetter_setDefaultValue (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                        extensionSetter_impAutoDefaultType_setDefaultValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_impAutoDefaultType_setDefaultValue (defineExtensionSetter_impAutoDefaultType_setDefaultValue, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension getter '@impAutoDefaultType mergeWithType'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impAutoDefaultType_mergeWithType (const cPtr_impType * /* inObject */,
                                                                        GALGAS_impType inArgument_typeToMerge,
                                                                        C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  result_mergedType = inArgument_typeToMerge ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impAutoDefaultType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                      extensionGetter_impAutoDefaultType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impAutoDefaultType_mergeWithType (defineExtensionGetter_impAutoDefaultType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@impAutoDefaultType autoAllowed'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_impAutoDefaultType_autoAllowed (const cPtr_impType * inObject,
                                                                   C_Compiler * /* inCompiler */
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_impAutoDefaultType * object = (const cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  result_result = object->mProperty_withAuto ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impAutoDefaultType_autoAllowed (void) {
  enterExtensionGetter_autoAllowed (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                    extensionGetter_impAutoDefaultType_autoAllowed) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impAutoDefaultType_autoAllowed (defineExtensionGetter_impAutoDefaultType_autoAllowed, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'multiError'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_multiError (GALGAS_locationList inArgument_locations,
                         GALGAS_string inArgument_errorMessage,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_locationList enumerator_14866 (inArgument_locations, kENUMERATION_UP) ;
  while (enumerator_14866.hasCurrentObject ()) {
    TC_Array <C_FixItDescription> fixItArray0 ;
    inCompiler->emitSemanticError (enumerator_14866.current_location (HERE), inArgument_errorMessage, fixItArray0  COMMA_SOURCE_FILE ("implementation_types.galgas", 547)) ;
    enumerator_14866.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@refType mergeWithType'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_refType_mergeWithType (const cPtr_impType * inObject,
                                                             GALGAS_impType inArgument_typeToMerge,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_refType * object = (const cPtr_refType *) inObject ;
  macroValidSharedObject (object, cPtr_refType) ;
  GALGAS_refType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_refType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_refType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("refType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 559)) ;
    }
  }
  GALGAS_refType var_castTypeToMerge_15099 = temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, object->mProperty_ref.getter_string (SOURCE_FILE ("implementation_types.galgas", 560)).objectCompare (var_castTypeToMerge_15099.getter_ref (SOURCE_FILE ("implementation_types.galgas", 560)).getter_string (SOURCE_FILE ("implementation_types.galgas", 560)))).boolEnum () ;
  if (kBoolTrue == test_1) {
    object->mProperty_ref.log ("ref"  COMMA_SOURCE_FILE ("implementation_types.galgas", 561)) ;
    GALGAS_lstring var_csatRef_15215 = var_castTypeToMerge_15099.getter_ref (SOURCE_FILE ("implementation_types.galgas", 562)) ;
    var_csatRef_15215.log ("csatRef"  COMMA_SOURCE_FILE ("implementation_types.galgas", 563)) ;
    {
    routine_multiError (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 564)), GALGAS_string ("Redefinition of ").add_operation (object->mProperty_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 564)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 564)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 564)) ;
    }
    {
    routine_multiError (object->mProperty_locations, GALGAS_string ("Was defined here"), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 565)) ;
    }
  }
  result_mergedType = GALGAS_refType::constructor_new (object->mProperty_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 568)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 568)), object->mProperty_type, object->mProperty_name, object->mProperty_multiple, object->mProperty_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 572)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 572)), var_castTypeToMerge_15099.getter_ref (SOURCE_FILE ("implementation_types.galgas", 573))  COMMA_SOURCE_FILE ("implementation_types.galgas", 567)) ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_refType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_refType.mSlotID,
                                      extensionGetter_refType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_refType_mergeWithType (defineExtensionGetter_refType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'valueList'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_valueList (const GALGAS_enumValues & constinArgument_values,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_enumValues enumerator_16209 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_16209.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_16209.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 601)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 601)) ;
    if (enumerator_16209.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 603)) ;
    }
    enumerator_16209.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueList [2] = {
  & kTypeDescriptor_GALGAS_enumValues,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueList (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_enumValues operand0 = GALGAS_enumValues::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_valueList (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueList ("valueList",
                                                           functionWithGenericHeader_valueList,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_valueList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@impRangedType mergeWithType'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impRangedType_mergeWithType (const cPtr_impType * inObject,
                                                                   GALGAS_impType inArgument_typeToMerge,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impRangedType * object = (const cPtr_impRangedType *) inObject ;
  macroValidSharedObject (object, cPtr_impRangedType) ;
  GALGAS_impRangedType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impRangedType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impRangedType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impRangedType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 615)) ;
    }
  }
  GALGAS_impRangedType var_castTypeToMerge_16483 = temp_0 ;
  const GALGAS_impRangedType temp_1 = object ;
  const enumGalgasBool test_2 = function_checkRanged (temp_1, var_castTypeToMerge_16483, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 616)).boolEnum () ;
  if (kBoolTrue == test_2) {
    result_mergedType = inArgument_typeToMerge ;
  }else if (kBoolFalse == test_2) {
    const GALGAS_impRangedType temp_3 = object ;
    result_mergedType = temp_3 ;
  }
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impRangedType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impRangedType.mSlotID,
                                      extensionGetter_impRangedType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impRangedType_mergeWithType (defineExtensionGetter_impRangedType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension getter '@impBoolType mergeWithType'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impBoolType_mergeWithType (const cPtr_impType * inObject,
                                                                 GALGAS_impType inArgument_typeToMerge,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  GALGAS_impBoolType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impBoolType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impBoolType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impBoolType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 632)) ;
    }
  }
  GALGAS_impBoolType var_castTypeToMerge_16889 = temp_0 ;
  GALGAS_implementationObjectMap var_mergedTrueAttributes_16967 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 633)) ;
  GALGAS_implementationObjectMap var_mergedFalseAttributes_17028 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 634)) ;
  cEnumerator_implementationObjectMap enumerator_17070 (object->mProperty_trueSubAttributes, kENUMERATION_UP) ;
  while (enumerator_17070.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_17097 = enumerator_17070.current_type (HERE) ;
    const enumGalgasBool test_1 = var_castTypeToMerge_16889.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 637)).getter_hasKey (enumerator_17070.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 637)) COMMA_SOURCE_FILE ("implementation_types.galgas", 637)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_impType var_subTypeToMerge_17254 ;
      var_castTypeToMerge_16889.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 638)).method_get (enumerator_17070.current_lkey (HERE), var_subTypeToMerge_17254, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 638)) ;
      var_mergedAttr_17097 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_17070.current_type (HERE).ptr (), var_subTypeToMerge_17254, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 639)) ;
    }
    {
    var_mergedTrueAttributes_16967.setter_put (enumerator_17070.current_lkey (HERE), var_mergedAttr_17097, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 641)) ;
    }
    enumerator_17070.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_17463 (var_castTypeToMerge_16889.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 644)), kENUMERATION_UP) ;
  while (enumerator_17463.hasCurrentObject ()) {
    const enumGalgasBool test_2 = object->mProperty_trueSubAttributes.getter_hasKey (enumerator_17463.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 645)) COMMA_SOURCE_FILE ("implementation_types.galgas", 645)).operator_not (SOURCE_FILE ("implementation_types.galgas", 645)).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      var_mergedTrueAttributes_16967.setter_put (enumerator_17463.current_lkey (HERE), enumerator_17463.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 646)) ;
      }
    }
    enumerator_17463.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_17619 (object->mProperty_falseSubAttributes, kENUMERATION_UP) ;
  while (enumerator_17619.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_17646 = enumerator_17619.current_type (HERE) ;
    const enumGalgasBool test_3 = var_castTypeToMerge_16889.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 652)).getter_hasKey (enumerator_17619.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 652)) COMMA_SOURCE_FILE ("implementation_types.galgas", 652)).boolEnum () ;
    if (kBoolTrue == test_3) {
      GALGAS_impType var_subTypeToMerge_17805 ;
      var_castTypeToMerge_16889.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 653)).method_get (enumerator_17619.current_lkey (HERE), var_subTypeToMerge_17805, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 653)) ;
      var_mergedAttr_17646 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_17619.current_type (HERE).ptr (), var_subTypeToMerge_17805, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 654)) ;
    }
    {
    var_mergedFalseAttributes_17028.setter_put (enumerator_17619.current_lkey (HERE), var_mergedAttr_17646, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 656)) ;
    }
    enumerator_17619.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_18016 (var_castTypeToMerge_16889.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 659)), kENUMERATION_UP) ;
  while (enumerator_18016.hasCurrentObject ()) {
    const enumGalgasBool test_4 = object->mProperty_falseSubAttributes.getter_hasKey (enumerator_18016.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 660)) COMMA_SOURCE_FILE ("implementation_types.galgas", 660)).operator_not (SOURCE_FILE ("implementation_types.galgas", 660)).boolEnum () ;
    if (kBoolTrue == test_4) {
      {
      var_mergedTrueAttributes_16967.setter_put (enumerator_18016.current_lkey (HERE), enumerator_18016.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 661)) ;
      }
    }
    enumerator_18016.gotoNextObject () ;
  }
  result_mergedType = GALGAS_impBoolType::constructor_new (object->mProperty_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 666)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 666)), object->mProperty_type, object->mProperty_name, object->mProperty_multiple, object->mProperty_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 670)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 670)), object->mProperty_withAuto, var_castTypeToMerge_16889.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 672)), var_mergedTrueAttributes_16967, var_mergedFalseAttributes_17028  COMMA_SOURCE_FILE ("implementation_types.galgas", 665)) ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impBoolType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                      extensionGetter_impBoolType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impBoolType_mergeWithType (defineExtensionGetter_impBoolType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@impBoolType setDefault'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impBoolType_setDefault (const cPtr_impAutoDefaultType * inObject,
                                                    GALGAS_objectAttributes & ioArgument_attributes,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  if (object->mProperty_defaultValue.isValid ()) {
    if (object->mProperty_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_void) {
    }else if (object->mProperty_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else if (object->mProperty_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_18624_b ((cPtr_boolAttribute *) object->mProperty_defaultValue.ptr ()) ;
      const enumGalgasBool test_0 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 686)).getter_hasKey (object->mProperty_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 686)) COMMA_SOURCE_FILE ("implementation_types.galgas", 686)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_identifierMap var_userAttributes_18900 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 689)) ;
        GALGAS_object_5F_t var_value_18952 ;
        var_userAttributes_18900.method_get (object->mProperty_name, var_value_18952, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 691)) ;
        if (var_value_18952.isValid ()) {
          if (var_value_18952.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
            GALGAS_boolAttribute cast_19054_boolValue ((cPtr_boolAttribute *) var_value_18952.ptr ()) ;
            GALGAS_implementationObjectMap var_subImpAttributes_19108 ;
            const enumGalgasBool test_1 = cast_19054_boolValue.getter_value (SOURCE_FILE ("implementation_types.galgas", 695)).boolEnum () ;
            if (kBoolTrue == test_1) {
              var_subImpAttributes_19108 = object->mProperty_trueSubAttributes ;
            }else if (kBoolFalse == test_1) {
              var_subImpAttributes_19108 = object->mProperty_falseSubAttributes ;
            }
            GALGAS_objectAttributes var_subAttributes_19314 = cast_19054_boolValue.getter_subAttributes (SOURCE_FILE ("implementation_types.galgas", 700)) ;
            {
            routine_setDefaultsForType (var_subImpAttributes_19108, var_subAttributes_19314, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 701)) ;
            }
            GALGAS_boolAttribute var_bv_19469 = cast_19054_boolValue ;
            {
            var_bv_19469.setter_setSubAttributes (var_subAttributes_19314 COMMA_SOURCE_FILE ("implementation_types.galgas", 704)) ;
            }
            {
            var_userAttributes_18900.setter_setValueForKey (var_bv_19469, object->mProperty_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 705)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 705)) ;
            }
            {
            ioArgument_attributes.setter_setObjectParams (var_userAttributes_18900 COMMA_SOURCE_FILE ("implementation_types.galgas", 706)) ;
            }
          }
        }
      }else if (kBoolFalse == test_0) {
        GALGAS_implementationObjectMap var_subImpAttributes_19728 ;
        const enumGalgasBool test_2 = cast_18624_b.getter_value (SOURCE_FILE ("implementation_types.galgas", 710)).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_subImpAttributes_19728 = object->mProperty_trueSubAttributes ;
        }else if (kBoolFalse == test_2) {
          var_subImpAttributes_19728 = object->mProperty_falseSubAttributes ;
        }
        GALGAS_objectAttributes var_subAttributes_19914 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 715)) ;
        {
        routine_setDefaultsForType (var_subImpAttributes_19728, var_subAttributes_19914, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 716)) ;
        }
        GALGAS_boolAttribute var_defaults_20026 = GALGAS_boolAttribute::constructor_new (cast_18624_b.getter_oil_5F_desc (SOURCE_FILE ("implementation_types.galgas", 717)), cast_18624_b.getter_location (SOURCE_FILE ("implementation_types.galgas", 717)), cast_18624_b.getter_value (SOURCE_FILE ("implementation_types.galgas", 717)), var_subAttributes_19914  COMMA_SOURCE_FILE ("implementation_types.galgas", 717)) ;
        GALGAS_identifierMap var_attr_20133 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 718)) ;
        {
        var_attr_20133.setter_put (object->mProperty_name, var_defaults_20026, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 719)) ;
        }
        {
        ioArgument_attributes.setter_setObjectParams (var_attr_20133 COMMA_SOURCE_FILE ("implementation_types.galgas", 720)) ;
        }
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impBoolType_setDefault (void) {
  enterExtensionMethod_setDefault (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                   extensionMethod_impBoolType_setDefault) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impBoolType_setDefault (defineExtensionMethod_impBoolType_setDefault, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension getter '@impEnumType mergeWithType'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impEnumType_mergeWithType (const cPtr_impType * inObject,
                                                                 GALGAS_impType inArgument_typeToMerge,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impEnumType * object = (const cPtr_impEnumType *) inObject ;
  macroValidSharedObject (object, cPtr_impEnumType) ;
  GALGAS_impEnumType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impEnumType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impEnumType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impEnumType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 755)) ;
    }
  }
  GALGAS_impEnumType var_castTypeToMerge_21075 = temp_0 ;
  result_mergedType = GALGAS_impEnumType::constructor_new (object->mProperty_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 757)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 757)), object->mProperty_type, object->mProperty_name, object->mProperty_multiple, object->mProperty_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 761)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 761)), object->mProperty_withAuto, var_castTypeToMerge_21075.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 763)), extensionGetter_mergeWithEnum (object->mProperty_valuesMap, var_castTypeToMerge_21075.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 764)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 764))  COMMA_SOURCE_FILE ("implementation_types.galgas", 756)) ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impEnumType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impEnumType.mSlotID,
                                      extensionGetter_impEnumType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impEnumType_mergeWithType (defineExtensionGetter_impEnumType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'verifyEnum'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyEnum (const GALGAS_impType constinArgument_anEnum,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_anEnum.isValid ()) {
    if (constinArgument_anEnum.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
      GALGAS_impEnumType cast_21541_realEnum ((cPtr_impEnumType *) constinArgument_anEnum.ptr ()) ;
      if (cast_21541_realEnum.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 776)).isValid ()) {
        if (cast_21541_realEnum.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 776)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_string_5F_class) {
          GALGAS_string_5F_class cast_21615_defaultValue ((cPtr_string_5F_class *) cast_21541_realEnum.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 776)).ptr ()) ;
          const enumGalgasBool test_0 = cast_21541_realEnum.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 778)).getter_hasKey (cast_21615_defaultValue.getter_value (SOURCE_FILE ("implementation_types.galgas", 778)) COMMA_SOURCE_FILE ("implementation_types.galgas", 778)).operator_not (SOURCE_FILE ("implementation_types.galgas", 778)).boolEnum () ;
          if (kBoolTrue == test_0) {
            TC_Array <C_FixItDescription> fixItArray1 ;
            inCompiler->emitSemanticError (cast_21615_defaultValue.getter_location (SOURCE_FILE ("implementation_types.galgas", 779)), GALGAS_string ("Default enum value does not match any enum value"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 779)) ;
          }
        }
      }
    }else{
      cEnumerator_locationList enumerator_21840 (constinArgument_anEnum.getter_locations (SOURCE_FILE ("implementation_types.galgas", 783)), kENUMERATION_UP) ;
      while (enumerator_21840.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_21840.current_location (HERE), GALGAS_string ("Internal, not an @impEnumType"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 784)) ;
        enumerator_21840.gotoNextObject () ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'checkAndGetIntegerNumber'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t function_checkAndGetIntegerNumber (const GALGAS_lstring & constinArgument_oil_5F_desc,
                                                      const GALGAS_dataType & constinArgument_type,
                                                      const GALGAS_luint_36__34_ & constinArgument_number,
                                                      const GALGAS_bool & constinArgument_signed,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_value ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_signed.boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 845)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_value = GALGAS_sint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 846)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 846)).getter_sint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 846)).multiply_operation (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 846)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 846))  COMMA_SOURCE_FILE ("implementation_types.galgas", 846)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 847)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_value = GALGAS_sint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 848)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 848)).getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848)).multiply_operation (GALGAS_sint_36__34_ ((int64_t) 1LL).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848))  COMMA_SOURCE_FILE ("implementation_types.galgas", 848)) ;
      }else if (kBoolFalse == test_2) {
        result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 850))  COMMA_SOURCE_FILE ("implementation_types.galgas", 850)) ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 851)), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 851)).add_operation (GALGAS_string (" expected, got a SINT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 851)), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 851)) ;
      }
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 854)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      result_value = GALGAS_sint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 855)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 855)).getter_sint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 855))  COMMA_SOURCE_FILE ("implementation_types.galgas", 855)) ;
    }else if (kBoolFalse == test_4) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 856)))).boolEnum () ;
      if (kBoolTrue == test_5) {
        result_value = GALGAS_sint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 857)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 857)).getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 857))  COMMA_SOURCE_FILE ("implementation_types.galgas", 857)) ;
      }else if (kBoolFalse == test_5) {
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 858)))).boolEnum () ;
        if (kBoolTrue == test_6) {
          result_value = GALGAS_uint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 859)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 859)).getter_uint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 859))  COMMA_SOURCE_FILE ("implementation_types.galgas", 859)) ;
        }else if (kBoolFalse == test_6) {
          const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 860)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            result_value = GALGAS_uint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 861)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 861))  COMMA_SOURCE_FILE ("implementation_types.galgas", 861)) ;
          }else if (kBoolFalse == test_7) {
            result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 863))  COMMA_SOURCE_FILE ("implementation_types.galgas", 863)) ;
            TC_Array <C_FixItDescription> fixItArray8 ;
            inCompiler->emitSemanticError (constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 864)), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 864)).add_operation (GALGAS_string (" expected, got a UINT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 864)), fixItArray8  COMMA_SOURCE_FILE ("implementation_types.galgas", 864)) ;
          }
        }
      }
    }
  }
//---
  return result_value ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkAndGetIntegerNumber [5] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_luint_36__34_,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkAndGetIntegerNumber (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_luint_36__34_ operand2 = GALGAS_luint_36__34_::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_bool operand3 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (3 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_checkAndGetIntegerNumber (operand0,
                                            operand1,
                                            operand2,
                                            operand3,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkAndGetIntegerNumber ("checkAndGetIntegerNumber",
                                                                          functionWithGenericHeader_checkAndGetIntegerNumber,
                                                                          & kTypeDescriptor_GALGAS_object_5F_t,
                                                                          4,
                                                                          functionArgs_checkAndGetIntegerNumber) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'checkAndGetFloatNumber'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t function_checkAndGetFloatNumber (const GALGAS_lstring & constinArgument_oil_5F_desc,
                                                    const GALGAS_dataType & constinArgument_type,
                                                    const GALGAS_ldouble & constinArgument_number,
                                                    const GALGAS_bool & constinArgument_signed,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_value ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_signed.boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 876)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_value = GALGAS_float_5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 877)), constinArgument_number.getter_double (SOURCE_FILE ("implementation_types.galgas", 877)).multiply_operation (GALGAS_double (1).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 877)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 877))  COMMA_SOURCE_FILE ("implementation_types.galgas", 877)) ;
    }else if (kBoolFalse == test_1) {
      result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 879))  COMMA_SOURCE_FILE ("implementation_types.galgas", 879)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 880)), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 880)).add_operation (GALGAS_string (" expected, got a FLOAT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 880)), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 880)) ;
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 883)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      result_value = GALGAS_float_5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 884)), constinArgument_number.getter_double (SOURCE_FILE ("implementation_types.galgas", 884))  COMMA_SOURCE_FILE ("implementation_types.galgas", 884)) ;
    }else if (kBoolFalse == test_3) {
      result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 886))  COMMA_SOURCE_FILE ("implementation_types.galgas", 886)) ;
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 887)), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 887)).add_operation (GALGAS_string (" expected, got a FLOAT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 887)), fixItArray4  COMMA_SOURCE_FILE ("implementation_types.galgas", 887)) ;
    }
  }
//---
  return result_value ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkAndGetFloatNumber [5] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_ldouble,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkAndGetFloatNumber (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_ldouble operand2 = GALGAS_ldouble::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_bool operand3 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (3 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_checkAndGetFloatNumber (operand0,
                                          operand1,
                                          operand2,
                                          operand3,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkAndGetFloatNumber ("checkAndGetFloatNumber",
                                                                        functionWithGenericHeader_checkAndGetFloatNumber,
                                                                        & kTypeDescriptor_GALGAS_object_5F_t,
                                                                        4,
                                                                        functionArgs_checkAndGetFloatNumber) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'checkTypeForAttribute'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkTypeForAttribute (const GALGAS_implementationObjectMap constinArgument_obj,
                                    const GALGAS_string constinArgument_attributeName,
                                    const GALGAS_dataType constinArgument_expectedType,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = constinArgument_obj.getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 896)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_type_25233 ;
    constinArgument_obj.method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 898)), var_type_25233, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 898)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_type_25233.getter_type (SOURCE_FILE ("implementation_types.galgas", 899)).objectCompare (constinArgument_expectedType)).boolEnum () ;
    if (kBoolTrue == test_1) {
      cEnumerator_locationList enumerator_25355 (var_type_25233.getter_locations (SOURCE_FILE ("implementation_types.galgas", 900)), kENUMERATION_UP) ;
      while (enumerator_25355.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_25355.current_location (HERE), constinArgument_attributeName.add_operation (GALGAS_string (" is a "), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)).add_operation (extensionGetter_oilType (var_type_25233.getter_type (SOURCE_FILE ("implementation_types.galgas", 901)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 901)) ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (enumerator_25355.current_location (HERE), constinArgument_attributeName.add_operation (GALGAS_string (" should be a "), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 902)).add_operation (extensionGetter_oilType (constinArgument_expectedType, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 902)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 902)), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 902)) ;
        enumerator_25355.gotoNextObject () ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'boolSubAttributes'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap function_boolSubAttributes (const GALGAS_implementationObject & constinArgument_obj,
                                                           const GALGAS_string & constinArgument_attributeName,
                                                           const GALGAS_bool & constinArgument_boolValue,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_subImplementation ; // Returned variable
  result_subImplementation = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 913)) ;
  const enumGalgasBool test_0 = constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 914)).getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 914)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_type_25814 ;
    constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 916)).method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 916)), var_type_25814, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 916)) ;
    if (var_type_25814.isValid ()) {
      if (var_type_25814.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impBoolType) {
        GALGAS_impBoolType cast_25924_boolType ((cPtr_impBoolType *) var_type_25814.ptr ()) ;
        const enumGalgasBool test_1 = constinArgument_boolValue.boolEnum () ;
        if (kBoolTrue == test_1) {
          result_subImplementation = cast_25924_boolType.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 920)) ;
        }else if (kBoolFalse == test_1) {
          result_subImplementation = cast_25924_boolType.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 922)) ;
        }
      }
    }
  }
//---
  return result_subImplementation ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_boolSubAttributes [4] = {
  & kTypeDescriptor_GALGAS_implementationObject,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_boolSubAttributes (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_implementationObject operand0 = GALGAS_implementationObject::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                           inCompiler
                                                                                           COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_bool operand2 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_boolSubAttributes (operand0,
                                     operand1,
                                     operand2,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_boolSubAttributes ("boolSubAttributes",
                                                                   functionWithGenericHeader_boolSubAttributes,
                                                                   & kTypeDescriptor_GALGAS_implementationObjectMap,
                                                                   3,
                                                                   functionArgs_boolSubAttributes) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'enumSubAttributes'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap function_enumSubAttributes (const GALGAS_implementationObject & constinArgument_obj,
                                                           const GALGAS_string & constinArgument_attributeName,
                                                           const GALGAS_string & constinArgument_enumValue,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_subImplementation ; // Returned variable
  result_subImplementation = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 933)) ;
  const enumGalgasBool test_0 = constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 934)).getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 934)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_type_26393 ;
    constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 936)).method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 936)), var_type_26393, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 936)) ;
    if (var_type_26393.isValid ()) {
      if (var_type_26393.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
        GALGAS_impEnumType cast_26503_enumType ((cPtr_impEnumType *) var_type_26393.ptr ()) ;
        const enumGalgasBool test_1 = cast_26503_enumType.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 939)).getter_hasKey (constinArgument_enumValue COMMA_SOURCE_FILE ("implementation_types.galgas", 939)).boolEnum () ;
        if (kBoolTrue == test_1) {
          cast_26503_enumType.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 940)).method_get (function_lstringWith (constinArgument_enumValue, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 940)), result_subImplementation, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 940)) ;
        }
      }
    }
  }
//---
  return result_subImplementation ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_enumSubAttributes [4] = {
  & kTypeDescriptor_GALGAS_implementationObject,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_enumSubAttributes (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_implementationObject operand0 = GALGAS_implementationObject::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                           inCompiler
                                                                                           COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_enumSubAttributes (operand0,
                                     operand1,
                                     operand2,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_enumSubAttributes ("enumSubAttributes",
                                                                   functionWithGenericHeader_enumSubAttributes,
                                                                   & kTypeDescriptor_GALGAS_implementationObjectMap,
                                                                   3,
                                                                   functionArgs_enumSubAttributes) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'checkFilters'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkFilters (const GALGAS_implementationObject constinArgument_messageProperty,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap var_filter_26789 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 951)) ;
  {
  routine_checkTypeForAttribute (var_filter_26789, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 952)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 952)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26789, GALGAS_string ("X"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 953)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 953)) ;
  }
  var_filter_26789 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWDIFFERSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 954)) ;
  {
  routine_checkTypeForAttribute (var_filter_26789, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 955)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 955)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26789, GALGAS_string ("X"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 956)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 956)) ;
  }
  var_filter_26789 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSMASKEDOLD"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 957)) ;
  {
  routine_checkTypeForAttribute (var_filter_26789, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 958)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 958)) ;
  }
  var_filter_26789 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISWITHIN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 959)) ;
  {
  routine_checkTypeForAttribute (var_filter_26789, GALGAS_string ("MIN"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 960)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 960)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26789, GALGAS_string ("MAX"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 961)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 961)) ;
  }
  var_filter_26789 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISOUTSIDE"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 962)) ;
  {
  routine_checkTypeForAttribute (var_filter_26789, GALGAS_string ("MIN"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 963)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 963)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26789, GALGAS_string ("MAX"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 964)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 964)) ;
  }
  var_filter_26789 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("ONEEVERYN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 965)) ;
  {
  routine_checkTypeForAttribute (var_filter_26789, GALGAS_string ("PERIOD"), GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 966)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 966)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_26789, GALGAS_string ("OFFSET"), GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 967)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 967)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@refType checkAttributeReferences'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_refType_checkAttributeReferences (const cPtr_impType * inObject,
                                                              const GALGAS_implementation constinArgument_imp,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_refType * object = (const cPtr_refType *) inObject ;
  macroValidSharedObject (object, cPtr_refType) ;
  const enumGalgasBool test_0 = callExtensionGetter_hasKey ((const cPtr_implementation *) constinArgument_imp.ptr (), object->mProperty_ref.getter_string (SOURCE_FILE ("implementation_types.galgas", 982)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 982)).operator_not (SOURCE_FILE ("implementation_types.galgas", 982)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_ref.getter_location (SOURCE_FILE ("implementation_types.galgas", 983)), object->mProperty_ref.getter_string (SOURCE_FILE ("implementation_types.galgas", 983)).add_operation (GALGAS_string (" object kind does not exist"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 983)), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 983)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_refType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_refType.mSlotID,
                                                 extensionMethod_refType_checkAttributeReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_refType_checkAttributeReferences (defineExtensionMethod_refType_checkAttributeReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@impBoolType checkAttributeReferences'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impBoolType_checkAttributeReferences (const cPtr_impType * inObject,
                                                                  const GALGAS_implementation constinArgument_imp,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  cEnumerator_implementationObjectMap enumerator_28679 (object->mProperty_trueSubAttributes, kENUMERATION_UP) ;
  while (enumerator_28679.hasCurrentObject ()) {
    callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_28679.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 991)) ;
    enumerator_28679.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_28762 (object->mProperty_falseSubAttributes, kENUMERATION_UP) ;
  while (enumerator_28762.hasCurrentObject ()) {
    callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_28762.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 994)) ;
    enumerator_28762.gotoNextObject () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impBoolType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                                 extensionMethod_impBoolType_checkAttributeReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impBoolType_checkAttributeReferences (defineExtensionMethod_impBoolType_checkAttributeReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@impEnumType checkAttributeReferences'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impEnumType_checkAttributeReferences (const cPtr_impType * inObject,
                                                                  const GALGAS_implementation constinArgument_imp,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impEnumType * object = (const cPtr_impEnumType *) inObject ;
  macroValidSharedObject (object, cPtr_impEnumType) ;
  cEnumerator_enumValues enumerator_28922 (object->mProperty_valuesMap, kENUMERATION_UP) ;
  while (enumerator_28922.hasCurrentObject ()) {
    cEnumerator_implementationObjectMap enumerator_28954 (enumerator_28922.current_subAttributes (HERE), kENUMERATION_UP) ;
    while (enumerator_28954.hasCurrentObject ()) {
      callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_28954.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1003)) ;
      enumerator_28954.gotoNextObject () ;
    }
    enumerator_28922.gotoNextObject () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impEnumType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_impEnumType.mSlotID,
                                                 extensionMethod_impEnumType_checkAttributeReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impEnumType_checkAttributeReferences (defineExtensionMethod_impEnumType_checkAttributeReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'setDefaultsForType'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setDefaultsForType (const GALGAS_implementationObjectMap constinArgument_impObject,
                                 GALGAS_objectAttributes & ioArgument_objectParams,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_implementationObjectMap enumerator_29146 (constinArgument_impObject, kENUMERATION_UP) ;
  while (enumerator_29146.hasCurrentObject ()) {
    if (enumerator_29146.current_type (HERE).isValid ()) {
      if (NULL != dynamic_cast <const cPtr_impAutoDefaultType *> (enumerator_29146.current_type (HERE).ptr ())) {
        GALGAS_impAutoDefaultType cast_29207_defaultType ((cPtr_impAutoDefaultType *) enumerator_29146.current_type (HERE).ptr ()) ;
        callExtensionMethod_setDefault ((const cPtr_impAutoDefaultType *) cast_29207_defaultType.ptr (), ioArgument_objectParams, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1015)) ;
      }
    }
    enumerator_29146.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Once function 'emptyLString'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring onceFunction_emptyLString (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_ls ; // Returned variable
  result_ls = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 29))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 29)) ;
//---
  return result_ls ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_emptyLString = false ;
static GALGAS_lstring gOnceFunctionResult_emptyLString ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_emptyLString (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_emptyLString) {
    gOnceFunctionResult_emptyLString = onceFunction_emptyLString (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_emptyLString = true ;
  }
  return gOnceFunctionResult_emptyLString ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_emptyLString (void) {
  gOnceFunctionResult_emptyLString.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_emptyLString (NULL,
                                                          releaseOnceFunctionResult_emptyLString) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyLString [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyLString (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_emptyLString (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyLString ("emptyLString",
                                                              functionWithGenericHeader_emptyLString,
                                                              & kTypeDescriptor_GALGAS_lstring,
                                                              0,
                                                              functionArgs_emptyLString) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'emptyObject'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_emptyObject (C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_result ; // Returned variable
  result_result = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_basic_types.galgas", 73))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 73)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyObject [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyObject (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_emptyObject (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyObject ("emptyObject",
                                                             functionWithGenericHeader_emptyObject,
                                                             & kTypeDescriptor_GALGAS_objectAttributes,
                                                             0,
                                                             functionArgs_emptyObject) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension setter '@multipleAttribute mergeSubAttributes'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_multipleAttribute_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                                                  GALGAS_object_5F_t inArgument_withObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_multipleAttribute * object = (cPtr_multipleAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_multipleAttribute) ;
  if (inArgument_withObject.isValid ()) {
    if (inArgument_withObject.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
      GALGAS_multipleAttribute cast_2255_multipleObject ((cPtr_multipleAttribute *) inArgument_withObject.ptr ()) ;
      object->mProperty_items.plusAssign_operation(cast_2255_multipleObject.getter_items (SOURCE_FILE ("goil_basic_types.galgas", 93)), inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 93)) ;
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_multipleAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_multipleAttribute.mSlotID,
                                           extensionSetter_multipleAttribute_mergeSubAttributes) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_multipleAttribute_mergeSubAttributes (defineExtensionSetter_multipleAttribute_mergeSubAttributes, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'multipleAttributeOrError'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList function_multipleAttributeOrError (const GALGAS_object_5F_t & constinArgument_t,
                                                         const GALGAS_string & constinArgument_att,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList result_v ; // Returned variable
  result_v = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("goil_basic_types.galgas", 101)) ;
  if (constinArgument_t.isValid ()) {
    if (constinArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
      GALGAS_multipleAttribute cast_2472_l ((cPtr_multipleAttribute *) constinArgument_t.ptr ()) ;
      result_v = cast_2472_l.getter_items (SOURCE_FILE ("goil_basic_types.galgas", 104)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 106)), GALGAS_string ("Internal error, ").add_operation (constinArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 106)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 106)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 106)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_multipleAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_multipleAttributeOrError (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_multipleAttributeOrError (operand0,
                                            operand1,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_multipleAttributeOrError ("multipleAttributeOrError",
                                                                          functionWithGenericHeader_multipleAttributeOrError,
                                                                          & kTypeDescriptor_GALGAS_identifierList,
                                                                          2,
                                                                          functionArgs_multipleAttributeOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension setter '@boolAttribute mergeSubAttributes'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_boolAttribute_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                                              GALGAS_object_5F_t inArgument_withObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_boolAttribute * object = (cPtr_boolAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_boolAttribute) ;
  if (inArgument_withObject.isValid ()) {
    if (inArgument_withObject.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_2802_boolObject ((cPtr_boolAttribute *) inArgument_withObject.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (cast_2802_boolObject.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 119)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        {
        object->mProperty_subAttributes.insulate (HERE) ;
        cPtr_objectAttributes * ptr_2867 = (cPtr_objectAttributes *) object->mProperty_subAttributes.ptr () ;
        callExtensionSetter_mergeAttributes ((cPtr_objectAttributes *) ptr_2867, cast_2802_boolObject.getter_subAttributes (SOURCE_FILE ("goil_basic_types.galgas", 120)), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 120)) ;
        }
      }
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_boolAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_boolAttribute.mSlotID,
                                           extensionSetter_boolAttribute_mergeSubAttributes) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_boolAttribute_mergeSubAttributes (defineExtensionSetter_boolAttribute_mergeSubAttributes, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'boolAttributeOrError'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_boolAttributeOrError (GALGAS_object_5F_t inArgument_t,
                                           GALGAS_string inArgument_att,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_v ; // Returned variable
  result_v = GALGAS_bool (false) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_3069_attribute ((cPtr_boolAttribute *) inArgument_t.ptr ()) ;
      result_v = cast_3069_attribute.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 132)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 134)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 134)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 134)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 134)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_boolAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_boolAttributeOrError (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_boolAttributeOrError (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_boolAttributeOrError ("boolAttributeOrError",
                                                                      functionWithGenericHeader_boolAttributeOrError,
                                                                      & kTypeDescriptor_GALGAS_bool,
                                                                      2,
                                                                      functionArgs_boolAttributeOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension setter '@enumAttribute mergeSubAttributes'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_enumAttribute_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                                              GALGAS_object_5F_t inArgument_withObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_enumAttribute * object = (cPtr_enumAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_enumAttribute) ;
  if (inArgument_withObject.isValid ()) {
    if (inArgument_withObject.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_enumAttribute) {
      GALGAS_enumAttribute cast_3401_enumObject ((cPtr_enumAttribute *) inArgument_withObject.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (cast_3401_enumObject.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 147)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        {
        object->mProperty_subAttributes.insulate (HERE) ;
        cPtr_objectAttributes * ptr_3466 = (cPtr_objectAttributes *) object->mProperty_subAttributes.ptr () ;
        callExtensionSetter_mergeAttributes ((cPtr_objectAttributes *) ptr_3466, cast_3401_enumObject.getter_subAttributes (SOURCE_FILE ("goil_basic_types.galgas", 148)), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 148)) ;
        }
      }
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_enumAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_enumAttribute.mSlotID,
                                           extensionSetter_enumAttribute_mergeSubAttributes) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_enumAttribute_mergeSubAttributes (defineExtensionSetter_enumAttribute_mergeSubAttributes, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'uint32_or_error'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint function_uint_33__32__5F_or_5F_error (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint result_v ; // Returned variable
  result_v = GALGAS_uint ((uint32_t) 0U) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      GALGAS_uint_33__32__5F_class cast_3851_ui ((cPtr_uint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_3851_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 173)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 175)), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 175)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 175)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_33__32__5F_or_5F_error [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_33__32__5F_or_5F_error (C_Compiler * inCompiler,
                                                                            const cObjectArray & inEffectiveParameterArray,
                                                                            const GALGAS_location & /* inErrorLocation */
                                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_33__32__5F_or_5F_error (operand0,
                                               operand1,
                                               inCompiler
                                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_33__32__5F_or_5F_error ("uint32_or_error",
                                                                             functionWithGenericHeader_uint_33__32__5F_or_5F_error,
                                                                             & kTypeDescriptor_GALGAS_uint,
                                                                             2,
                                                                             functionArgs_uint_33__32__5F_or_5F_error) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'uint32OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint function_uint_33__32_OrError (GALGAS_object_5F_t inArgument_t,
                                          GALGAS_string inArgument_att,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint result_v ; // Returned variable
  result_v = GALGAS_uint ((uint32_t) 0U) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      GALGAS_uint_33__32__5F_class cast_4050_ui ((cPtr_uint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4050_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 186)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 188)), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 188)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 188)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_33__32_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_33__32_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_33__32_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_33__32_OrError ("uint32OrError",
                                                                     functionWithGenericHeader_uint_33__32_OrError,
                                                                     & kTypeDescriptor_GALGAS_uint,
                                                                     2,
                                                                     functionArgs_uint_33__32_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'sint32OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint function_sint_33__32_OrError (GALGAS_object_5F_t inArgument_t,
                                          GALGAS_string inArgument_att,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint result_v ; // Returned variable
  result_v = GALGAS_sint ((int32_t) 0L) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      GALGAS_sint_33__32__5F_class cast_4388_ui ((cPtr_sint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4388_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 206)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 208)), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 208)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 208)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_33__32_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_33__32_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_sint_33__32_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_33__32_OrError ("sint32OrError",
                                                                     functionWithGenericHeader_sint_33__32_OrError,
                                                                     & kTypeDescriptor_GALGAS_sint,
                                                                     2,
                                                                     functionArgs_sint_33__32_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'uint64OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ function_uint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_uint_36__34_ ((uint64_t) 0ULL) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_4726_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4726_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 226)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 228)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 228)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 228)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 228)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_36__34_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_36__34_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_36__34_OrError ("uint64OrError",
                                                                     functionWithGenericHeader_uint_36__34_OrError,
                                                                     & kTypeDescriptor_GALGAS_uint_36__34_,
                                                                     2,
                                                                     functionArgs_uint_36__34_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'luint64OrError'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint_36__34_ function_luint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                    GALGAS_string inArgument_att,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result_v ; // Returned variable
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_4944_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = GALGAS_luint_36__34_::constructor_new (cast_4944_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 238)), cast_4944_ui.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 238))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 238)) ;
    }else{
      result_v = GALGAS_luint_36__34_::constructor_new (GALGAS_uint_36__34_ ((uint64_t) 0ULL), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 240))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 240)) ;
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 241)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 241)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 241)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 241)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_luint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_luint_36__34_OrError (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_luint_36__34_OrError (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_luint_36__34_OrError ("luint64OrError",
                                                                      functionWithGenericHeader_luint_36__34_OrError,
                                                                      & kTypeDescriptor_GALGAS_luint_36__34_,
                                                                      2,
                                                                      functionArgs_luint_36__34_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'sint64OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ function_sint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_sint_36__34_ ((int64_t) 0LL) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      GALGAS_sint_36__34__5F_class cast_5386_ui ((cPtr_sint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_5386_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 259)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 261)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 261)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 261)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 261)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_36__34_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_sint_36__34_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_36__34_OrError ("sint64OrError",
                                                                     functionWithGenericHeader_sint_36__34_OrError,
                                                                     & kTypeDescriptor_GALGAS_sint_36__34_,
                                                                     2,
                                                                     functionArgs_sint_36__34_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'floatOrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double function_floatOrError (GALGAS_object_5F_t inArgument_t,
                                     GALGAS_string inArgument_att,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_v ; // Returned variable
  result_v = GALGAS_double (0) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      GALGAS_float_5F_class cast_5736_ui ((cPtr_float_5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_5736_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 279)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 281)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 281)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 281)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 281)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_floatOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_floatOrError (C_Compiler * inCompiler,
                                                             const cObjectArray & inEffectiveParameterArray,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_floatOrError (operand0,
                                operand1,
                                inCompiler
                                COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_floatOrError ("floatOrError",
                                                              functionWithGenericHeader_floatOrError,
                                                              & kTypeDescriptor_GALGAS_double,
                                                              2,
                                                              functionArgs_floatOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'stringAttributeOrError'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_stringAttributeOrError (const GALGAS_object_5F_t & constinArgument_attribute,
                                                const GALGAS_string & constinArgument_attributeName,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  result_result = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 303)) ;
  if (constinArgument_attribute.isValid ()) {
    if (constinArgument_attribute.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_stringAttribute) {
      GALGAS_stringAttribute cast_6288_attribute ((cPtr_stringAttribute *) constinArgument_attribute.ptr ()) ;
      result_result = GALGAS_lstring::constructor_new (cast_6288_attribute.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 306)), cast_6288_attribute.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 306))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 306)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_attribute.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 308)), GALGAS_string ("Internal error ").add_operation (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 308)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 308)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 308)) ;
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringAttributeOrError (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_stringAttributeOrError (operand0,
                                          operand1,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringAttributeOrError ("stringAttributeOrError",
                                                                        functionWithGenericHeader_stringAttributeOrError,
                                                                        & kTypeDescriptor_GALGAS_lstring,
                                                                        2,
                                                                        functionArgs_stringAttributeOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension setter '@structAttribute mergeSubAttributes'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_structAttribute_mergeSubAttributes (cPtr_object_5F_t * inObject,
                                                                GALGAS_object_5F_t inArgument_withObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_structAttribute * object = (cPtr_structAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_structAttribute) ;
  if (inArgument_withObject.isValid ()) {
    if (inArgument_withObject.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
      GALGAS_structAttribute cast_6696_structObject ((cPtr_structAttribute *) inArgument_withObject.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, object->mProperty_structName.getter_string (SOURCE_FILE ("goil_basic_types.galgas", 321)).objectCompare (cast_6696_structObject.getter_structName (SOURCE_FILE ("goil_basic_types.galgas", 321)).getter_string (SOURCE_FILE ("goil_basic_types.galgas", 321)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        {
        object->mProperty_subAttributes.insulate (HERE) ;
        cPtr_objectAttributes * ptr_6791 = (cPtr_objectAttributes *) object->mProperty_subAttributes.ptr () ;
        callExtensionSetter_mergeAttributes ((cPtr_objectAttributes *) ptr_6791, cast_6696_structObject.getter_subAttributes (SOURCE_FILE ("goil_basic_types.galgas", 322)), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 322)) ;
        }
      }
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_structAttribute_mergeSubAttributes (void) {
  enterExtensionSetter_mergeSubAttributes (kTypeDescriptor_GALGAS_structAttribute.mSlotID,
                                           extensionSetter_structAttribute_mergeSubAttributes) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_structAttribute_mergeSubAttributes (defineExtensionSetter_structAttribute_mergeSubAttributes, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'empty_lstring'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_empty_5F_lstring (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_ls ; // Returned variable
  result_ls = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 487))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 487)) ;
//---
  return result_ls ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_empty_5F_lstring [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_empty_5F_lstring (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_empty_5F_lstring (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_empty_5F_lstring ("empty_lstring",
                                                                  functionWithGenericHeader_empty_5F_lstring,
                                                                  & kTypeDescriptor_GALGAS_lstring,
                                                                  0,
                                                                  functionArgs_empty_5F_lstring) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'void_obj'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t function_void_5F_obj (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_v ; // Returned variable
  result_v = GALGAS_void::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 492)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 492))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 492)) ;
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_void_5F_obj [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_void_5F_obj (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_void_5F_obj (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_void_5F_obj ("void_obj",
                                                             functionWithGenericHeader_void_5F_obj,
                                                             & kTypeDescriptor_GALGAS_object_5F_t,
                                                             0,
                                                             functionArgs_void_5F_obj) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'luint64_value'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint_36__34_ function_luint_36__34__5F_value (const GALGAS_uint_36__34__5F_class & constinArgument_c,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_luint_36__34_::constructor_new (constinArgument_c.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 686)), constinArgument_c.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 686))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 686)) ;
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_luint_36__34__5F_value [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34__5F_class,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_luint_36__34__5F_value (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_uint_36__34__5F_class operand0 = GALGAS_uint_36__34__5F_class::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                             inCompiler
                                                                                             COMMA_THERE) ;
  return function_luint_36__34__5F_value (operand0,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_luint_36__34__5F_value ("luint64_value",
                                                                        functionWithGenericHeader_luint_36__34__5F_value,
                                                                        & kTypeDescriptor_GALGAS_luint_36__34_,
                                                                        1,
                                                                        functionArgs_luint_36__34__5F_value) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'projectName'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_projectName (C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_directory ; // Returned variable
  result_directory = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 30)).getter_stringByDeletingPathExtension (SOURCE_FILE ("goil_routines.galgas", 30)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string (gOption_goil_5F_options_project_5F_dir.getter_value ()).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_directory = GALGAS_string (gOption_goil_5F_options_project_5F_dir.getter_value ()) ;
  }
//---
  return result_directory ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_projectName [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_projectName (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_projectName (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_projectName ("projectName",
                                                             functionWithGenericHeader_projectName,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             0,
                                                             functionArgs_projectName) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'oil_dir'                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_oil_5F_dir (C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_dir ; // Returned variable
  result_dir = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 37)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_routines.galgas", 37)) ;
//---
  return result_dir ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_oil_5F_dir [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_oil_5F_dir (C_Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_oil_5F_dir (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_oil_5F_dir ("oil_dir",
                                                            functionWithGenericHeader_oil_5F_dir,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_oil_5F_dir) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Function 'arch'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_arch (C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_arch_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1211 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 45)) ;
  var_components_1211.method_first (result_arch_5F_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 46)) ;
//---
  return result_arch_5F_name ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_arch [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_arch (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_arch (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_arch ("arch",
                                                      functionWithGenericHeader_arch,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_arch) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Function 'chip'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_chip (C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_chip_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1528 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 54)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_components_1528.getter_length (SOURCE_FILE ("goil_routines.galgas", 55)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_chip_5F_name = var_components_1528.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 56)) ;
  }else if (kBoolFalse == test_0) {
    result_chip_5F_name = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_chip_5F_name ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_chip [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_chip (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_chip (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_chip ("chip",
                                                      functionWithGenericHeader_chip,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_chip) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Function 'board'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_board (C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_board_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1946 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 68)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_components_1946.getter_length (SOURCE_FILE ("goil_routines.galgas", 69)).objectCompare (GALGAS_uint ((uint32_t) 2U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    GALGAS_string joker_2090 ; // Joker input parameter
    var_components_1946.setter_popFirst (joker_2090, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 70)) ;
    }
    {
    GALGAS_string joker_2121 ; // Joker input parameter
    var_components_1946.setter_popFirst (joker_2121, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 71)) ;
    }
    result_board_5F_name = GALGAS_string::constructor_componentsJoinedByString (var_components_1946, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 72)) ;
  }else if (kBoolFalse == test_0) {
    result_board_5F_name = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_board_5F_name ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_board [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_board (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_board (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_board ("board",
                                                       functionWithGenericHeader_board,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_board) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'targetPathList'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list function_targetPathList (C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_list result_pathList ; // Returned variable
  GALGAS_stringlist var_components_2360 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 82)) ;
  result_pathList = GALGAS_list::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 83)) ;
  cEnumerator_stringlist enumerator_2500 (var_components_2360, kENUMERATION_UP) ;
  while (enumerator_2500.hasCurrentObject ()) {
    GALGAS_gtlData var_cont_2521 = GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 85)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 85)), enumerator_2500.current_mValue (HERE)  COMMA_SOURCE_FILE ("goil_routines.galgas", 85)) ;
    result_pathList.addAssign_operation (var_cont_2521  COMMA_SOURCE_FILE ("goil_routines.galgas", 86)) ;
    enumerator_2500.gotoNextObject () ;
  }
//---
  return result_pathList ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_targetPathList [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_targetPathList (C_Compiler * inCompiler,
                                                               const cObjectArray & /* inEffectiveParameterArray */,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  return function_targetPathList (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_targetPathList ("targetPathList",
                                                                functionWithGenericHeader_targetPathList,
                                                                & kTypeDescriptor_GALGAS_list,
                                                                0,
                                                                functionArgs_targetPathList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'add_path_component'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_add_5F_path_5F_component (GALGAS_string inArgument_path,
                                                 GALGAS_string inArgument_component,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_new_5F_path ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_path.getter_characterAtIndex (inArgument_path.getter_length (SOURCE_FILE ("goil_routines.galgas", 97)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 97)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 97)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_new_5F_path = inArgument_path.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 98)).add_operation (inArgument_component, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 98)) ;
  }else if (kBoolFalse == test_0) {
    result_new_5F_path = inArgument_path.add_operation (inArgument_component, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 100)) ;
  }
//---
  return result_new_5F_path ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_add_5F_path_5F_component [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_add_5F_path_5F_component (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_add_5F_path_5F_component (operand0,
                                            operand1,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_add_5F_path_5F_component ("add_path_component",
                                                                          functionWithGenericHeader_add_5F_path_5F_component,
                                                                          & kTypeDescriptor_GALGAS_string,
                                                                          2,
                                                                          functionArgs_add_5F_path_5F_component) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'rootTemplatesDirectory'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_rootTemplatesDirectory (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_templateDirectory ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string (gOption_goil_5F_options_template_5F_dir.getter_value ()).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_templateDirectory = GALGAS_string (gOption_goil_5F_options_template_5F_dir.getter_value ()) ;
  }else if (kBoolFalse == test_0) {
    GALGAS_string var_env_3086 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_TEMPLATES")  COMMA_SOURCE_FILE ("goil_routines.galgas", 110)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_env_3086.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_templateDirectory = var_env_3086 ;
    }else if (kBoolFalse == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 114)), GALGAS_string ("The templates path is not set. Use --templates option or set the GOIL_TEMPLATES environment variable"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 114)) ;
      result_templateDirectory.drop () ; // Release error dropped variable
    }
  }
  result_templateDirectory = result_templateDirectory.getter_unixPathWithNativePath (SOURCE_FILE ("goil_routines.galgas", 118)) ;
  result_templateDirectory = result_templateDirectory.getter_stringByStandardizingPath (SOURCE_FILE ("goil_routines.galgas", 119)) ;
  const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, result_templateDirectory.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 121)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
  if (kBoolTrue == test_3) {
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, result_templateDirectory.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 122)).objectCompare (GALGAS_char (TO_UNICODE (126)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      GALGAS_string var_home_3651 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("HOME")  COMMA_SOURCE_FILE ("goil_routines.galgas", 123)) ;
      GALGAS_string var_relativeToHome_3738 = result_templateDirectory.getter_rightSubString (result_templateDirectory.getter_length (SOURCE_FILE ("goil_routines.galgas", 124)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 124)) COMMA_SOURCE_FILE ("goil_routines.galgas", 124)) ;
      result_templateDirectory = var_home_3651.add_operation (var_relativeToHome_3738, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 125)) ;
    }else if (kBoolFalse == test_4) {
      GALGAS_string var_currentDirectory_3895 = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 127)) ;
      result_templateDirectory = var_currentDirectory_3895.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 128)).add_operation (result_templateDirectory, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 128)) ;
    }
    result_templateDirectory = result_templateDirectory.getter_stringByStandardizingPath (SOURCE_FILE ("goil_routines.galgas", 130)) ;
  }
//---
  return result_templateDirectory ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_rootTemplatesDirectory [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_rootTemplatesDirectory (C_Compiler * inCompiler,
                                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  return function_rootTemplatesDirectory (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_rootTemplatesDirectory ("rootTemplatesDirectory",
                                                                        functionWithGenericHeader_rootTemplatesDirectory,
                                                                        & kTypeDescriptor_GALGAS_string,
                                                                        0,
                                                                        functionArgs_rootTemplatesDirectory) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'templates_directory'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_templates_5F_directory (GALGAS_string inArgument_prefix,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_temp_5F_dir ; // Returned variable
  result_temp_5F_dir = function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 135)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_temp_5F_dir = function_add_5F_path_5F_component (result_temp_5F_dir, inArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 137)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 139)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_string var_curdir_4402 = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 140)) ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).objectCompare (GALGAS_char (TO_UNICODE (46)))).operator_and (GALGAS_bool (kIsEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).objectCompare (GALGAS_char (TO_UNICODE (47)))) COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_temp_5F_dir = result_temp_5F_dir.getter_stringByRemovingCharacterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 142)).getter_stringByRemovingCharacterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 142)) ;
      }
      result_temp_5F_dir = var_curdir_4402.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 144)).add_operation (result_temp_5F_dir, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 144)) ;
    }
    const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.getter_characterAtIndex (result_temp_5F_dir.getter_length (SOURCE_FILE ("goil_routines.galgas", 146)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 146)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 146)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      result_temp_5F_dir.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 147)) ;
    }
  }
//---
  return result_temp_5F_dir ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_templates_5F_directory [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_templates_5F_directory (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_templates_5F_directory (operand0,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_templates_5F_directory ("templates_directory",
                                                                        functionWithGenericHeader_templates_5F_directory,
                                                                        & kTypeDescriptor_GALGAS_string,
                                                                        1,
                                                                        functionArgs_templates_5F_directory) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'templateFilePath'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_templateFilePath (const GALGAS_string & constinArgument_prefix,
                                         const GALGAS_string & constinArgument_file,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_path ; // Returned variable
  GALGAS_stringlist var_components_5004 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 158)) ;
  GALGAS_string var_templateDir_5107 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 159)) ;
  GALGAS_bool var_notFound_5155 = GALGAS_bool (true) ;
  GALGAS_bool var_notOver_5178 = GALGAS_bool (true) ;
  result_path = GALGAS_string::makeEmptyString () ;
  if (var_components_5004.getter_length (SOURCE_FILE ("goil_routines.galgas", 164)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 164)).isValid ()) {
    uint32_t variant_5207 = var_components_5004.getter_length (SOURCE_FILE ("goil_routines.galgas", 164)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 164)).uintValue () ;
    bool loop_5207 = true ;
    while (loop_5207) {
      loop_5207 = var_notFound_5155.operator_and (var_notOver_5178 COMMA_SOURCE_FILE ("goil_routines.galgas", 165)).isValid () ;
      if (loop_5207) {
        loop_5207 = var_notFound_5155.operator_and (var_notOver_5178 COMMA_SOURCE_FILE ("goil_routines.galgas", 165)).boolValue () ;
      }
      if (loop_5207 && (0 == variant_5207)) {
        loop_5207 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 164)) ;
      }
      if (loop_5207) {
        variant_5207 -- ;
        GALGAS_string var_targetPath_5284 = var_templateDir_5107.add_operation (GALGAS_string::constructor_componentsJoinedByString (var_components_5004, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 166)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)) ;
        const enumGalgasBool test_0 = var_targetPath_5284.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 168)).boolEnum () ;
        if (kBoolTrue == test_0) {
          var_notFound_5155 = GALGAS_bool (false) ;
          result_path = var_targetPath_5284 ;
        }
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, var_components_5004.getter_length (SOURCE_FILE ("goil_routines.galgas", 172)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          GALGAS_string joker_5560 ; // Joker input parameter
          var_components_5004.setter_popLast (joker_5560, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 173)) ;
          }
        }else if (kBoolFalse == test_1) {
          var_notOver_5178 = GALGAS_bool (false) ;
        }
      }
    }
  }
//---
  return result_path ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_templateFilePath [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_templateFilePath (C_Compiler * inCompiler,
                                                                 const cObjectArray & inEffectiveParameterArray,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_templateFilePath (operand0,
                                    operand1,
                                    inCompiler
                                    COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_templateFilePath ("templateFilePath",
                                                                  functionWithGenericHeader_templateFilePath,
                                                                  & kTypeDescriptor_GALGAS_string,
                                                                  2,
                                                                  functionArgs_templateFilePath) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'allTemplatePaths'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist function_allTemplatePaths (const GALGAS_string & constinArgument_prefix,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist result_paths ; // Returned variable
  GALGAS_stringlist var_components_5703 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 184)) ;
  GALGAS_string var_partialPath_5806 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 185)) ;
  result_paths = GALGAS_stringlist::constructor_listWithValue (var_partialPath_5806  COMMA_SOURCE_FILE ("goil_routines.galgas", 187)) ;
  cEnumerator_stringlist enumerator_5938 (var_components_5703, kENUMERATION_UP) ;
  while (enumerator_5938.hasCurrentObject ()) {
    var_partialPath_5806 = function_add_5F_path_5F_component (var_partialPath_5806, enumerator_5938.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 190)) ;
    {
    result_paths.setter_insertAtIndex (var_partialPath_5806, GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 191)) ;
    }
    enumerator_5938.gotoNextObject () ;
  }
//---
  return result_paths ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_allTemplatePaths [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_allTemplatePaths (C_Compiler * inCompiler,
                                                                 const cObjectArray & inEffectiveParameterArray,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_allTemplatePaths (operand0,
                                    inCompiler
                                    COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_allTemplatePaths ("allTemplatePaths",
                                                                  functionWithGenericHeader_allTemplatePaths,
                                                                  & kTypeDescriptor_GALGAS_stringlist,
                                                                  1,
                                                                  functionArgs_allTemplatePaths) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'checkTemplatesPath'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkTemplatesPath (C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_configDir_6102 = function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 197)).add_operation (GALGAS_string ("/config"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 197)) ;
  const enumGalgasBool test_0 = var_configDir_6102.getter_directoryExists (SOURCE_FILE ("goil_routines.galgas", 198)).operator_not (SOURCE_FILE ("goil_routines.galgas", 198)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)), GALGAS_string ("The templates path '").add_operation (var_configDir_6102, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 199)).add_operation (GALGAS_string ("' is not set to the templates directory"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 199)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)) ;
  }else if (kBoolFalse == test_0) {
    GALGAS_string var_partialPath_6319 = var_configDir_6102 ;
    GALGAS_bool var_continueIt_6352 = GALGAS_bool (true) ;
    GALGAS_stringlist var_components_6386 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 203)) ;
    cEnumerator_stringlist enumerator_6504 (var_components_6386, kENUMERATION_UP) ;
    while (enumerator_6504.hasCurrentObject ()) {
      var_partialPath_6319 = var_partialPath_6319.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 205)).add_operation (enumerator_6504.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 205)) ;
      GALGAS_bool test_2 = var_continueIt_6352 ;
      if (kBoolTrue == test_2.boolEnum ()) {
        test_2 = var_partialPath_6319.getter_directoryExists (SOURCE_FILE ("goil_routines.galgas", 206)).operator_not (SOURCE_FILE ("goil_routines.galgas", 206)) ;
      }
      const enumGalgasBool test_3 = test_2.boolEnum () ;
      if (kBoolTrue == test_3) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 207)), GALGAS_string ("The templates path '").add_operation (var_partialPath_6319, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 207)).add_operation (GALGAS_string ("' does not exist in the templates directory"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 207)), fixItArray4  COMMA_SOURCE_FILE ("goil_routines.galgas", 207)) ;
        var_continueIt_6352 = GALGAS_bool (false) ;
      }
      enumerator_6504.gotoNextObject () ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'allTemplateFilePaths'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist function_allTemplateFilePaths (const GALGAS_string & constinArgument_prefix,
                                                 const GALGAS_string & constinArgument_file,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist result_paths ; // Returned variable
  GALGAS_stringlist var_components_6901 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 220)) ;
  GALGAS_string var_templateDir_7004 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 221)) ;
  GALGAS_bool var_notOver_7051 = GALGAS_bool (true) ;
  result_paths = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 223)) ;
  if (var_components_6901.getter_length (SOURCE_FILE ("goil_routines.galgas", 225)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 225)).isValid ()) {
    uint32_t variant_7101 = var_components_6901.getter_length (SOURCE_FILE ("goil_routines.galgas", 225)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 225)).uintValue () ;
    bool loop_7101 = true ;
    while (loop_7101) {
      loop_7101 = var_notOver_7051.isValid () ;
      if (loop_7101) {
        loop_7101 = var_notOver_7051.boolValue () ;
      }
      if (loop_7101 && (0 == variant_7101)) {
        loop_7101 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 225)) ;
      }
      if (loop_7101) {
        variant_7101 -- ;
        GALGAS_string var_intermediatePath_7173 = GALGAS_string::constructor_componentsJoinedByString (var_components_6901, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 227)) ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_intermediatePath_7173.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          var_intermediatePath_7173.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 228)) ;
        }
        GALGAS_string var_targetPath_7315 = var_templateDir_7004.add_operation (var_intermediatePath_7173, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 229)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 229)) ;
        const enumGalgasBool test_1 = var_targetPath_7315.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 231)).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_paths.addAssign_operation (var_targetPath_7315  COMMA_SOURCE_FILE ("goil_routines.galgas", 232)) ;
        }
        const enumGalgasBool test_2 = GALGAS_bool (kIsStrictSup, var_components_6901.getter_length (SOURCE_FILE ("goil_routines.galgas", 234)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_2) {
          {
          GALGAS_string joker_7530 ; // Joker input parameter
          var_components_6901.setter_popLast (joker_7530, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 235)) ;
          }
        }else if (kBoolFalse == test_2) {
          var_notOver_7051 = GALGAS_bool (false) ;
        }
      }
    }
  }
//---
  return result_paths ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_allTemplateFilePaths [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_allTemplateFilePaths (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_allTemplateFilePaths (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_allTemplateFilePaths ("allTemplateFilePaths",
                                                                      functionWithGenericHeader_allTemplateFilePaths,
                                                                      & kTypeDescriptor_GALGAS_stringlist,
                                                                      2,
                                                                      functionArgs_allTemplateFilePaths) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Routine 'prefix'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_prefix (GALGAS_prefix_5F_map inArgument_p,
                     GALGAS_string inArgument_key,
                     GALGAS_string & outArgument_val,
                     C_Compiler * inCompiler
                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_val.drop () ; // Release 'out' argument
  GALGAS_lstring var_lkey_7653 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 243))  COMMA_SOURCE_FILE ("goil_routines.galgas", 243)) ;
  GALGAS_string joker_7720 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey_7653, outArgument_val, joker_7720, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 244)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'performReplace'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_performReplace (GALGAS_prefix_5F_map inArgument_p,
                             GALGAS_string inArgument_key,
                             GALGAS_string inArgument_name,
                             GALGAS_string & ioArgument_res,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkey_7821 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 248))  COMMA_SOURCE_FILE ("goil_routines.galgas", 248)) ;
  GALGAS_string var_prefix_7880 ;
  GALGAS_string var_tag_5F_to_5F_rep_7903 ;
  inArgument_p.method_prefix (var_lkey_7821, var_prefix_7880, var_tag_5F_to_5F_rep_7903, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 251)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep_7903, var_prefix_7880.add_operation (inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 252)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 252)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'doReplace'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_doReplace (GALGAS_string & ioArgument_s,
                        GALGAS_string inArgument_o,
                        GALGAS_string inArgument_n,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_n, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 256)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'do_replace_default'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_do_5F_replace_5F_default (GALGAS_string & ioArgument_s,
                                       GALGAS_string inArgument_o,
                                       GALGAS_string inArgument_n,
                                       GALGAS_string inArgument_d,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_n.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_n, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 261)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_d, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 263)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'replace_no_prefix'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_replace_5F_no_5F_prefix (GALGAS_prefix_5F_map inArgument_p,
                                      GALGAS_string inArgument_key,
                                      GALGAS_string inArgument_name,
                                      GALGAS_string & ioArgument_res,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkey_8426 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 268))  COMMA_SOURCE_FILE ("goil_routines.galgas", 268)) ;
  GALGAS_string var_tag_5F_to_5F_rep_8511 ;
  GALGAS_string joker_8533 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey_8426, joker_8533, var_tag_5F_to_5F_rep_8511, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 271)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep_8511, inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 272)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'table_core'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_table_5F_core (GALGAS_string inArgument_typename,
                            GALGAS_string inArgument_varname,
                            GALGAS_string inArgument_obj_5F_prefix,
                            GALGAS_stringset inArgument_names,
                            GALGAS_string & ioArgument_header,
                            GALGAS_string & ioArgument_implementation,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_n_8962 = GALGAS_uint ((uint32_t) 0U) ;
  cEnumerator_stringset enumerator_8999 (inArgument_names, kENUMERATION_UP) ;
  while (enumerator_8999.hasCurrentObject ()) {
    ioArgument_header = ioArgument_header.add_operation (GALGAS_string ("#define "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (inArgument_varname, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("_id_of_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (enumerator_8999.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("  "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (var_n_8962.getter_string (SOURCE_FILE ("goil_routines.galgas", 291)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)) ;
    ioArgument_header = ioArgument_header.add_operation (GALGAS_string ("#define "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (enumerator_8999.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("  "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (inArgument_varname, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("_id_of_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (enumerator_8999.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)) ;
    ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string ("    (tpl_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (inArgument_typename, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (GALGAS_string (" *)&"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (inArgument_obj_5F_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (enumerator_8999.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)) ;
    var_n_8962.increment_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 301)) ;
    const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_n_8962.objectCompare (inArgument_names.getter_count (SOURCE_FILE ("goil_routines.galgas", 302)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string (",\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 303)) ;
    }else if (kBoolFalse == test_0) {
      ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 304)) ;
    }
    enumerator_8999.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'add_to_stringset'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_to_5F_stringset (GALGAS_stringset & ioArgument_ss,
                                     GALGAS_string inArgument_new,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = ioArgument_ss.getter_hasKey (inArgument_new COMMA_SOURCE_FILE ("goil_routines.galgas", 409)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 410)), GALGAS_string ("'").add_operation (inArgument_new, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 410)).add_operation (GALGAS_string ("' is already declared before"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 410)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 410)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_ss.addAssign_operation (inArgument_new  COMMA_SOURCE_FILE ("goil_routines.galgas", 412)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'file_in_path'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_file_5F_in_5F_path (GALGAS_lstring & ioArgument_file_5F_name,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_include_5F_path_12819 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_INCLUDE_PATH")  COMMA_SOURCE_FILE ("goil_routines.galgas", 418)) ;
  GALGAS_stringlist var_systemPaths_13034 = function_allTemplatePaths (GALGAS_string ("config"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 422)) ;
  GALGAS_stringlist var_includePathList_13096 ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_include_5F_path_12819.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_includePathList_13096 = var_include_5F_path_12819.getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("goil_routines.galgas", 425)) ;
  }else if (kBoolFalse == test_0) {
    var_includePathList_13096 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 427)) ;
  }
  GALGAS_stringlist var_path_5F_list_13290 = var_includePathList_13096.add_operation (var_systemPaths_13034, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 429)) ;
  GALGAS_bool var_not_5F_found_13343 = GALGAS_bool (true) ;
  cEnumerator_stringlist enumerator_13387 (var_path_5F_list_13290, kENUMERATION_UP) ;
  while (enumerator_13387.hasCurrentObject ()) {
    GALGAS_string var_full_5F_file_5F_path_13421 = enumerator_13387.current_mValue (HERE) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_full_5F_file_5F_path_13421.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, var_full_5F_file_5F_path_13421.getter_characterAtIndex (var_full_5F_file_5F_path_13421.getter_length (SOURCE_FILE ("goil_routines.galgas", 435)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 435)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 435)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_full_5F_file_5F_path_13421.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 436)) ;
      }
    }
    var_full_5F_file_5F_path_13421.plusAssign_operation(ioArgument_file_5F_name.getter_string (SOURCE_FILE ("goil_routines.galgas", 439)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 439)) ;
    const enumGalgasBool test_3 = var_full_5F_file_5F_path_13421.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 440)).operator_and (var_not_5F_found_13343 COMMA_SOURCE_FILE ("goil_routines.galgas", 440)).boolEnum () ;
    if (kBoolTrue == test_3) {
      ioArgument_file_5F_name = GALGAS_lstring::constructor_new (var_full_5F_file_5F_path_13421, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 441))  COMMA_SOURCE_FILE ("goil_routines.galgas", 441)) ;
      var_not_5F_found_13343 = GALGAS_bool (false) ;
    }
    enumerator_13387.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'is_in_lstringlist'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_is_5F_in_5F_lstringlist (GALGAS_lstringlist inArgument_l,
                                      GALGAS_lstring inArgument_e,
                                      GALGAS_lstring & outArgument_f,
                                      GALGAS_bool & outArgument_p,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_f.drop () ; // Release 'out' argument
  outArgument_p.drop () ; // Release 'out' argument
  outArgument_p = GALGAS_bool (false) ;
  outArgument_f = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 453))  COMMA_SOURCE_FILE ("goil_routines.galgas", 453)) ;
  cEnumerator_lstringlist enumerator_14030 (inArgument_l, kENUMERATION_UP) ;
  while (enumerator_14030.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_14030.current_mValue (HERE).getter_string (SOURCE_FILE ("goil_routines.galgas", 455)).objectCompare (inArgument_e.getter_string (SOURCE_FILE ("goil_routines.galgas", 455)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_p = GALGAS_bool (true) ;
      outArgument_f = enumerator_14030.current_mValue (HERE) ;
    }
    enumerator_14030.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'isInLstringlist'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_isInLstringlist (GALGAS_lstringlist inArgument_l,
                                      GALGAS_lstring inArgument_e,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_p ; // Returned variable
  result_p = GALGAS_bool (false) ;
  cEnumerator_lstringlist enumerator_14228 (inArgument_l, kENUMERATION_UP) ;
  while (enumerator_14228.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_14228.current_mValue (HERE).getter_string (SOURCE_FILE ("goil_routines.galgas", 468)).objectCompare (inArgument_e.getter_string (SOURCE_FILE ("goil_routines.galgas", 468)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_p = GALGAS_bool (true) ;
    }
    enumerator_14228.gotoNextObject () ;
  }
//---
  return result_p ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_isInLstringlist [3] = {
  & kTypeDescriptor_GALGAS_lstringlist,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_isInLstringlist (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_lstringlist operand0 = GALGAS_lstringlist::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_isInLstringlist (operand0,
                                   operand1,
                                   inCompiler
                                   COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_isInLstringlist ("isInLstringlist",
                                                                 functionWithGenericHeader_isInLstringlist,
                                                                 & kTypeDescriptor_GALGAS_bool,
                                                                 2,
                                                                 functionArgs_isInLstringlist) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'add_lstring_unique'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_lstring_5F_unique (GALGAS_lstringlist & ioArgument_l,
                                       GALGAS_lstring inArgument_e,
                                       GALGAS_string inArgument_att,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool var_found_14388 ;
  GALGAS_lstring var_res_14403 ;
  {
  routine_is_5F_in_5F_lstringlist (ioArgument_l, inArgument_e, var_res_14403, var_found_14388, inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 480)) ;
  }
  const enumGalgasBool test_0 = var_found_14388.boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (inArgument_e.getter_location (SOURCE_FILE ("goil_routines.galgas", 482)), inArgument_att.add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)).add_operation (inArgument_e.getter_string (SOURCE_FILE ("goil_routines.galgas", 482)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)).add_operation (GALGAS_string (" has already be listed"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 482)) ;
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (var_res_14403.getter_location (SOURCE_FILE ("goil_routines.galgas", 483)), GALGAS_string ("was listed here"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 483)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_l.addAssign_operation (inArgument_e  COMMA_SOURCE_FILE ("goil_routines.galgas", 485)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'set_lstring_if_empty'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_set_5F_lstring_5F_if_5F_empty (GALGAS_lstring & ioArgument_s,
                                            GALGAS_lstring inArgument_ns,
                                            GALGAS_string inArgument_att,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, ioArgument_s.getter_string (SOURCE_FILE ("goil_routines.galgas", 493)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_s = inArgument_ns ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (inArgument_ns.getter_location (SOURCE_FILE ("goil_routines.galgas", 496)), inArgument_att.add_operation (GALGAS_string (" Redefinition"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 496)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 496)) ;
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (ioArgument_s.getter_location (SOURCE_FILE ("goil_routines.galgas", 497)), GALGAS_string ("was defined here"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 497)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Routine 'add_makefile_flag_if_not_empty'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_makefile_5F_flag_5F_if_5F_not_5F_empty (GALGAS_string & ioArgument_receiver,
                                                            GALGAS_string inArgument_flag_5F_name,
                                                            GALGAS_string inArgument_flag_5F_value,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_flag_5F_value.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_receiver.plusAssign_operation(inArgument_flag_5F_name.add_operation (GALGAS_string ("="), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)).add_operation (inArgument_flag_5F_value, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 506)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'lstringWith'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_lstringWith (GALGAS_string inArgument_s,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_r ; // Returned variable
  result_r = GALGAS_lstring::constructor_new (inArgument_s, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 511))  COMMA_SOURCE_FILE ("goil_routines.galgas", 511)) ;
//---
  return result_r ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_lstringWith [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_lstringWith (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_lstringWith (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_lstringWith ("lstringWith",
                                                             functionWithGenericHeader_lstringWith,
                                                             & kTypeDescriptor_GALGAS_lstring,
                                                             1,
                                                             functionArgs_lstringWith) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'stripString'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stripString (GALGAS_string inArgument_s,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_r ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 515)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_uint var_first_15136 = GALGAS_uint ((uint32_t) 0U) ;
    GALGAS_uint var_last_15155 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 517)) ;
    GALGAS_bool var_finished_15243 = GALGAS_bool (false) ;
    if (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 520)).isValid ()) {
      uint32_t variant_15260 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 520)).uintValue () ;
      bool loop_15260 = true ;
      while (loop_15260) {
        loop_15260 = var_finished_15243.operator_not (SOURCE_FILE ("goil_routines.galgas", 521)).isValid () ;
        if (loop_15260) {
          loop_15260 = var_finished_15243.operator_not (SOURCE_FILE ("goil_routines.galgas", 521)).boolValue () ;
        }
        if (loop_15260 && (0 == variant_15260)) {
          loop_15260 = false ;
          inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 520)) ;
        }
        if (loop_15260) {
          variant_15260 -- ;
          const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, inArgument_s.getter_characterAtIndex (var_first_15136, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 522)).objectCompare (GALGAS_char (TO_UNICODE (32)))).boolEnum () ;
          if (kBoolTrue == test_1) {
            var_first_15136.increment_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 523)) ;
            const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_first_15136.objectCompare (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 524)))).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_finished_15243 = GALGAS_bool (true) ;
            }
          }else if (kBoolFalse == test_1) {
            var_finished_15243 = GALGAS_bool (true) ;
          }
        }
      }
    }
    var_finished_15243 = GALGAS_bool (false) ;
    if (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 529)).isValid ()) {
      uint32_t variant_15545 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 529)).uintValue () ;
      bool loop_15545 = true ;
      while (loop_15545) {
        loop_15545 = var_finished_15243.operator_not (SOURCE_FILE ("goil_routines.galgas", 530)).isValid () ;
        if (loop_15545) {
          loop_15545 = var_finished_15243.operator_not (SOURCE_FILE ("goil_routines.galgas", 530)).boolValue () ;
        }
        if (loop_15545 && (0 == variant_15545)) {
          loop_15545 = false ;
          inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 529)) ;
        }
        if (loop_15545) {
          variant_15545 -- ;
          const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, inArgument_s.getter_characterAtIndex (var_last_15155.substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 531)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 531)).objectCompare (GALGAS_char (TO_UNICODE (32)))).boolEnum () ;
          if (kBoolTrue == test_3) {
            var_last_15155.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 532)) ;
            const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_last_15155.objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
            if (kBoolTrue == test_4) {
              var_finished_15243 = GALGAS_bool (true) ;
            }
          }else if (kBoolFalse == test_3) {
            var_finished_15243 = GALGAS_bool (true) ;
          }
        }
      }
    }
    const enumGalgasBool test_5 = GALGAS_bool (kIsStrictInf, var_first_15136.objectCompare (var_last_15155)).boolEnum () ;
    if (kBoolTrue == test_5) {
      result_r = inArgument_s.getter_subString (var_first_15136, var_last_15155.substract_operation (var_first_15136, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 538)) COMMA_SOURCE_FILE ("goil_routines.galgas", 538)) ;
    }else if (kBoolFalse == test_5) {
      result_r = GALGAS_string::makeEmptyString () ;
    }
  }else if (kBoolFalse == test_0) {
    result_r = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_r ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stripString [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stripString (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_stripString (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stripString ("stripString",
                                                             functionWithGenericHeader_stripString,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             1,
                                                             functionArgs_stripString) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'errorNoFileFound'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_errorNoFileFound (const GALGAS_stringlist constinArgument_searchedPaths,
                               const GALGAS_string constinArgument_kind,
                               const GALGAS_lstring constinArgument_file,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_m_16011 = GALGAS_string ("cannot find a valid path for the '").add_operation (constinArgument_file.getter_string (SOURCE_FILE ("goil_routines.galgas", 551)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)).add_operation (GALGAS_string ("' "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)).add_operation (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)).add_operation (GALGAS_string (" file. I have tried:"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)) ;
  cEnumerator_stringlist enumerator_16123 (constinArgument_searchedPaths, kENUMERATION_UP) ;
  while (enumerator_16123.hasCurrentObject ()) {
    var_m_16011.plusAssign_operation(GALGAS_string ("\n"
      "  - '").add_operation (enumerator_16123.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 553)).add_operation (GALGAS_string ("'"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 553)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 553)) ;
    enumerator_16123.gotoNextObject () ;
  }
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (constinArgument_file.getter_location (SOURCE_FILE ("goil_routines.galgas", 555)), var_m_16011, fixItArray0  COMMA_SOURCE_FILE ("goil_routines.galgas", 555)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'stringLBool'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringLBool (const GALGAS_lbool & constinArgument_boolValue,
                                    C_Compiler * /* inCompiler */
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_boolValue.getter_bool (SOURCE_FILE ("goil_routines.galgas", 561)).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_string ("TRUE") ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("FALSE") ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringLBool [2] = {
  & kTypeDescriptor_GALGAS_lbool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringLBool (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_lbool operand0 = GALGAS_lbool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                             inCompiler
                                                             COMMA_THERE) ;
  return function_stringLBool (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringLBool ("stringLBool",
                                                             functionWithGenericHeader_stringLBool,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             1,
                                                             functionArgs_stringLBool) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension method '@structAttribute set'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_structAttribute_set (const cPtr_object_5F_t * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_gtlData & ioArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structAttribute * object = (const cPtr_structAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_structAttribute) ;
  GALGAS_gtlData var_subAttrs_935 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) object->mProperty_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 33)) ;
  {
  var_subAttrs_935.insulate (HERE) ;
  cPtr_gtlData * ptr_976 = (cPtr_gtlData *) var_subAttrs_935.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_976, GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), object->mProperty_structName.getter_location (SOURCE_FILE ("systemConfig.galgas", 35))  COMMA_SOURCE_FILE ("systemConfig.galgas", 35)), GALGAS_gtlString::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, object->mProperty_structName.getter_string (SOURCE_FILE ("systemConfig.galgas", 36))  COMMA_SOURCE_FILE ("systemConfig.galgas", 36)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 34)) ;
  }
  {
  var_subAttrs_935.setter_setMeta (object->mProperty_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 38)) ;
  }
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_1129 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1129, constinArgument_name, var_subAttrs_935, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 39)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_structAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_structAttribute.mSlotID,
                            extensionMethod_structAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_structAttribute_set (defineExtensionMethod_structAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@boolAttribute set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_boolAttribute_set (const cPtr_object_5F_t * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               GALGAS_gtlData & ioArgument_result,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_boolAttribute * object = (const cPtr_boolAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_boolAttribute) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_1575 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1575, constinArgument_name, GALGAS_gtlBool::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, object->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 52)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 52)) ;
  }
  GALGAS_gtlData var_subAttrs_1662 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) object->mProperty_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 53)) ;
  GALGAS_gtlStruct temp_0 ;
  if (var_subAttrs_1662.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_1662.ptr ())) {
      temp_0 = (cPtr_gtlStruct *) var_subAttrs_1662.ptr () ;
    }else{
      inCompiler->castError ("gtlStruct", var_subAttrs_1662.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 54)) ;
    }
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_value (SOURCE_FILE ("systemConfig.galgas", 54)).getter_count (SOURCE_FILE ("systemConfig.galgas", 54)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_lstring var_structName_1766 = GALGAS_lstring::constructor_new (constinArgument_name.getter_string (SOURCE_FILE ("systemConfig.galgas", 55)).add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 55)), constinArgument_name.getter_location (SOURCE_FILE ("systemConfig.galgas", 55))  COMMA_SOURCE_FILE ("systemConfig.galgas", 55)) ;
    {
    var_subAttrs_1662.setter_setMeta (object->mProperty_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 56)) ;
    }
    {
    ioArgument_result.insulate (HERE) ;
    cPtr_gtlData * ptr_1872 = (cPtr_gtlData *) ioArgument_result.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1872, var_structName_1766, var_subAttrs_1662, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 57)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_boolAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_boolAttribute.mSlotID,
                            extensionMethod_boolAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_boolAttribute_set (defineExtensionMethod_boolAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@enumAttribute set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_enumAttribute_set (const cPtr_object_5F_t * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               GALGAS_gtlData & ioArgument_result,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_enumAttribute * object = (const cPtr_enumAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_enumAttribute) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2191 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2191, constinArgument_name, GALGAS_gtlString::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, object->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 66)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 66)) ;
  }
  GALGAS_gtlData var_subAttrs_2280 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) object->mProperty_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 67)) ;
  GALGAS_gtlStruct temp_0 ;
  if (var_subAttrs_2280.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_2280.ptr ())) {
      temp_0 = (cPtr_gtlStruct *) var_subAttrs_2280.ptr () ;
    }else{
      inCompiler->castError ("gtlStruct", var_subAttrs_2280.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 68)) ;
    }
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_value (SOURCE_FILE ("systemConfig.galgas", 68)).getter_count (SOURCE_FILE ("systemConfig.galgas", 68)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_lstring var_structName_2384 = GALGAS_lstring::constructor_new (constinArgument_name.getter_string (SOURCE_FILE ("systemConfig.galgas", 69)).add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 69)), constinArgument_name.getter_location (SOURCE_FILE ("systemConfig.galgas", 69))  COMMA_SOURCE_FILE ("systemConfig.galgas", 69)) ;
    {
    var_subAttrs_2280.setter_setMeta (object->mProperty_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 70)) ;
    }
    {
    ioArgument_result.insulate (HERE) ;
    cPtr_gtlData * ptr_2490 = (cPtr_gtlData *) ioArgument_result.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2490, var_structName_2384, var_subAttrs_2280, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 71)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_enumAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_enumAttribute.mSlotID,
                            extensionMethod_enumAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_enumAttribute_set (defineExtensionMethod_enumAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension method '@stringAttribute set'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_stringAttribute_set (const cPtr_object_5F_t * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_gtlData & ioArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_stringAttribute * object = (const cPtr_stringAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_stringAttribute) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2625 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2625, constinArgument_name, GALGAS_gtlString::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, object->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 76)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 76)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_stringAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_stringAttribute.mSlotID,
                            extensionMethod_stringAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_stringAttribute_set (defineExtensionMethod_stringAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@string_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_string_5F_class_set (const cPtr_object_5F_t * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_gtlData & ioArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_string_5F_class * object = (const cPtr_string_5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_string_5F_class) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2782 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2782, constinArgument_name, GALGAS_gtlString::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, object->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 80)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 80)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_string_5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_string_5F_class.mSlotID,
                            extensionMethod_string_5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_string_5F_class_set (defineExtensionMethod_string_5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@objectRefAttribute set'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_objectRefAttribute_set (const cPtr_object_5F_t * inObject,
                                                    const GALGAS_lstring constinArgument_name,
                                                    GALGAS_gtlData & ioArgument_result,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectRefAttribute * object = (const cPtr_objectRefAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_objectRefAttribute) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_2945 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2945, constinArgument_name, GALGAS_gtlString::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, object->mProperty_value.getter_string (SOURCE_FILE ("systemConfig.galgas", 84))  COMMA_SOURCE_FILE ("systemConfig.galgas", 84)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 84)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_objectRefAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_objectRefAttribute.mSlotID,
                            extensionMethod_objectRefAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_objectRefAttribute_set (defineExtensionMethod_objectRefAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@multipleAttribute set'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_multipleAttribute_set (const cPtr_object_5F_t * inObject,
                                                   const GALGAS_lstring constinArgument_name,
                                                   GALGAS_gtlData & ioArgument_result,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_multipleAttribute * object = (const cPtr_multipleAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_multipleAttribute) ;
  GALGAS_gtlList var_multiple_3115 = GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 88)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 88)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("systemConfig.galgas", 88))  COMMA_SOURCE_FILE ("systemConfig.galgas", 88)) ;
  cEnumerator_identifierList enumerator_3180 (object->mProperty_items, kENUMERATION_UP) ;
  while (enumerator_3180.hasCurrentObject ()) {
    GALGAS_gtlData var_multipleItem_3209 = GALGAS_gtlStruct::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 90))  COMMA_SOURCE_FILE ("systemConfig.galgas", 90)) ;
    if (enumerator_3180.current_item (HERE).isValid ()) {
      if (enumerator_3180.current_item (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
        GALGAS_structAttribute cast_3312_aStruct ((cPtr_structAttribute *) enumerator_3180.current_item (HERE).ptr ()) ;
        {
        var_multipleItem_3209.insulate (HERE) ;
        cPtr_gtlData * ptr_3336 = (cPtr_gtlData *) var_multipleItem_3209.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3336, GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), cast_3312_aStruct.getter_location (SOURCE_FILE ("systemConfig.galgas", 94))  COMMA_SOURCE_FILE ("systemConfig.galgas", 94)), GALGAS_gtlString::constructor_new (cast_3312_aStruct.getter_location (SOURCE_FILE ("systemConfig.galgas", 96)), cast_3312_aStruct.getter_oil_5F_desc (SOURCE_FILE ("systemConfig.galgas", 97)), cast_3312_aStruct.getter_structName (SOURCE_FILE ("systemConfig.galgas", 98)).getter_string (SOURCE_FILE ("systemConfig.galgas", 98))  COMMA_SOURCE_FILE ("systemConfig.galgas", 95)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 93)) ;
        }
        GALGAS_gtlData var_subAttrs_3566 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) cast_3312_aStruct.getter_subAttributes (SOURCE_FILE ("systemConfig.galgas", 101)).ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 101)) ;
        GALGAS_gtlStruct temp_0 ;
        if (var_subAttrs_3566.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_3566.ptr ())) {
            temp_0 = (cPtr_gtlStruct *) var_subAttrs_3566.ptr () ;
          }else{
            inCompiler->castError ("gtlStruct", var_subAttrs_3566.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 102)) ;
          }
        }
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_value (SOURCE_FILE ("systemConfig.galgas", 102)).getter_count (SOURCE_FILE ("systemConfig.galgas", 102)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlStruct temp_2 ;
          if (var_subAttrs_3566.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_3566.ptr ())) {
              temp_2 = (cPtr_gtlStruct *) var_subAttrs_3566.ptr () ;
            }else{
              inCompiler->castError ("gtlStruct", var_subAttrs_3566.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 103)) ;
            }
          }
          cEnumerator_gtlVarMap enumerator_3710 (temp_2.getter_value (SOURCE_FILE ("systemConfig.galgas", 103)), kENUMERATION_UP) ;
          while (enumerator_3710.hasCurrentObject ()) {
            {
            var_multipleItem_3209.insulate (HERE) ;
            cPtr_gtlData * ptr_3739 = (cPtr_gtlData *) var_multipleItem_3209.ptr () ;
            callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3739, enumerator_3710.current_lkey (HERE), enumerator_3710.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 104)) ;
            }
            enumerator_3710.gotoNextObject () ;
          }
        }
      }else{
        callExtensionMethod_set ((const cPtr_object_5F_t *) enumerator_3180.current_item (HERE).ptr (), GALGAS_lstring::constructor_new (GALGAS_string ("VALUE"), enumerator_3180.current_item (HERE).getter_location (SOURCE_FILE ("systemConfig.galgas", 108))  COMMA_SOURCE_FILE ("systemConfig.galgas", 108)), var_multipleItem_3209, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 108)) ;
      }
    }
    {
    var_multiple_3115.insulate (HERE) ;
    cPtr_gtlList * ptr_3899 = (cPtr_gtlList *) var_multiple_3115.ptr () ;
    callExtensionSetter_appendItem ((cPtr_gtlList *) ptr_3899, var_multipleItem_3209, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 110)) ;
    }
    enumerator_3180.gotoNextObject () ;
  }
  {
  var_multiple_3115.setter_setMeta (object->mProperty_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 112)) ;
  }
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_3976 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3976, constinArgument_name, var_multiple_3115, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 113)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_multipleAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_multipleAttribute.mSlotID,
                            extensionMethod_multipleAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_multipleAttribute_set (defineExtensionMethod_multipleAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@uint32_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_33__32__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_gtlData & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_33__32__5F_class * object = (const cPtr_uint_33__32__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_uint_33__32__5F_class) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4096 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4096, constinArgument_name, GALGAS_gtlInt::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, object->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 119))  COMMA_SOURCE_FILE ("systemConfig.galgas", 119)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 117)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_33__32__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_uint_33__32__5F_class.mSlotID,
                            extensionMethod_uint_33__32__5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_33__32__5F_class_set (defineExtensionMethod_uint_33__32__5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@sint32_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_33__32__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_gtlData & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_33__32__5F_class * object = (const cPtr_sint_33__32__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_sint_33__32__5F_class) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4270 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4270, constinArgument_name, GALGAS_gtlInt::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, object->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 126))  COMMA_SOURCE_FILE ("systemConfig.galgas", 126)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 124)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_33__32__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_sint_33__32__5F_class.mSlotID,
                            extensionMethod_sint_33__32__5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_33__32__5F_class_set (defineExtensionMethod_sint_33__32__5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@uint64_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_36__34__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_gtlData & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_36__34__5F_class * object = (const cPtr_uint_36__34__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_uint_36__34__5F_class) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4444 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4444, constinArgument_name, GALGAS_gtlInt::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, object->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 133))  COMMA_SOURCE_FILE ("systemConfig.galgas", 133)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 131)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_36__34__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_uint_36__34__5F_class.mSlotID,
                            extensionMethod_uint_36__34__5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_36__34__5F_class_set (defineExtensionMethod_uint_36__34__5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@sint64_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_36__34__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_gtlData & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_36__34__5F_class * object = (const cPtr_sint_36__34__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_sint_36__34__5F_class) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4618 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4618, constinArgument_name, GALGAS_gtlInt::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, object->mProperty_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 140))  COMMA_SOURCE_FILE ("systemConfig.galgas", 140)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 138)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_36__34__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_sint_36__34__5F_class.mSlotID,
                            extensionMethod_sint_36__34__5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_36__34__5F_class_set (defineExtensionMethod_sint_36__34__5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@float_class set'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_float_5F_class_set (const cPtr_object_5F_t * inObject,
                                                const GALGAS_lstring constinArgument_name,
                                                GALGAS_gtlData & ioArgument_result,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_float_5F_class * object = (const cPtr_float_5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_float_5F_class) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4791 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4791, constinArgument_name, GALGAS_gtlFloat::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, object->mProperty_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 147)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 145)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_float_5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_float_5F_class.mSlotID,
                            extensionMethod_float_5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_float_5F_class_set (defineExtensionMethod_float_5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Overriding extension method '@auto set'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_auto_set (const cPtr_object_5F_t * inObject,
                                      const GALGAS_lstring constinArgument_name,
                                      GALGAS_gtlData & ioArgument_result,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_auto * object = (const cPtr_auto *) inObject ;
  macroValidSharedObject (object, cPtr_auto) ;
  {
  ioArgument_result.insulate (HERE) ;
  cPtr_gtlData * ptr_4950 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4950, constinArgument_name, GALGAS_gtlEnum::constructor_new (object->mProperty_location, object->mProperty_oil_5F_desc, GALGAS_string ("auto")  COMMA_SOURCE_FILE ("systemConfig.galgas", 154)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 152)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_auto_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_auto.mSlotID,
                            extensionMethod_auto_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_auto_set (defineExtensionMethod_auto_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'setDefaults'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setDefaults (const GALGAS_implementation constinArgument_imp,
                          GALGAS_applicationDefinition & ioArgument_application,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectsMap var_objects_876 = ioArgument_application.getter_objects (SOURCE_FILE ("defaults.galgas", 32)) ;
  cEnumerator_lstringlist enumerator_980 (var_objects_876.getter_keyList (SOURCE_FILE ("defaults.galgas", 35)), kENUMERATION_UP) ;
  while (enumerator_980.hasCurrentObject ()) {
    cMapElement_objectsMap * objectArray_992 = (cMapElement_objectsMap *) var_objects_876.readWriteAccessForWithInstructionWithErrorMessage (inCompiler, enumerator_980.current_mValue (HERE), kSearchErrorMessage_objectsMap_get  COMMA_SOURCE_FILE ("defaults.galgas", 36)) ;
    if (NULL != objectArray_992) {
        macroValidSharedObject (objectArray_992, cMapElement_objectsMap) ;
      GALGAS_objectKindMap var_objOfKind_1069 = objectArray_992->mProperty_objectsOfKind.getter_objects (SOURCE_FILE ("defaults.galgas", 37)) ;
      cEnumerator_lstringlist enumerator_1151 (var_objOfKind_1069.getter_keyList (SOURCE_FILE ("defaults.galgas", 38)), kENUMERATION_UP) ;
      while (enumerator_1151.hasCurrentObject ()) {
        cMapElement_objectKindMap * objectArray_1167 = (cMapElement_objectKindMap *) var_objOfKind_1069.readWriteAccessForWithInstructionWithErrorMessage (inCompiler, enumerator_1151.current_mValue (HERE), kSearchErrorMessage_objectKindMap_get  COMMA_SOURCE_FILE ("defaults.galgas", 39)) ;
        if (NULL != objectArray_1167) {
            macroValidSharedObject (objectArray_1167, cMapElement_objectKindMap) ;
          GALGAS_implementationObject var_impObject_1257 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_980.current_mValue (HERE).getter_string (SOURCE_FILE ("defaults.galgas", 40)), inCompiler COMMA_SOURCE_FILE ("defaults.galgas", 40)) ;
          {
          routine_setDefaultsForType (var_impObject_1257.getter_attributes (SOURCE_FILE ("defaults.galgas", 41)), objectArray_1167->mProperty_attributes, inCompiler  COMMA_SOURCE_FILE ("defaults.galgas", 41)) ;
          }
        }
        enumerator_1151.gotoNextObject () ;
      }
      {
      objectArray_992->mProperty_objectsOfKind.setter_setObjects (var_objOfKind_1069 COMMA_SOURCE_FILE ("defaults.galgas", 44)) ;
      }
    }
    enumerator_980.gotoNextObject () ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_876 COMMA_SOURCE_FILE ("defaults.galgas", 48)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension method '@impStructType verifyType'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impStructType_verifyType (const cPtr_impType * inObject,
                                                      const GALGAS_object_5F_t constinArgument_attr,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impStructType * object = (const cPtr_impStructType *) inObject ;
  macroValidSharedObject (object, cPtr_impStructType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
      GALGAS_structAttribute cast_2379_sa ((cPtr_structAttribute *) constinArgument_attr.ptr ()) ;
      cEnumerator_implementationObjectMap enumerator_2413 (object->mProperty_structAttributes, kENUMERATION_UP) ;
      while (enumerator_2413.hasCurrentObject ()) {
        const enumGalgasBool test_0 = cast_2379_sa.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 88)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 88)).getter_hasKey (enumerator_2413.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 88)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 88)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_object_5F_t var_subAttr_2514 ;
          cast_2379_sa.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 90)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 90)).method_get (enumerator_2413.current_lkey (HERE), var_subAttr_2514, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 90)) ;
          callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_2413.current_type (HERE).ptr (), var_subAttr_2514, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 91)) ;
        }
        enumerator_2413.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 95)), GALGAS_string ("STRUCT expected"), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 95)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impStructType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impStructType.mSlotID,
                                   extensionMethod_impStructType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impStructType_verifyType (defineExtensionMethod_impStructType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@refType verifyType'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_refType_verifyType (const cPtr_impType * /* inObject */,
                                                const GALGAS_object_5F_t constinArgument_attr,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_objectRefAttribute) {
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 105)), GALGAS_string ("object reference expected"), fixItArray0  COMMA_SOURCE_FILE ("semantic_verification.galgas", 105)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_refType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_refType.mSlotID,
                                   extensionMethod_refType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_refType_verifyType (defineExtensionMethod_refType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@impBoolType verifyType'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impBoolType_verifyType (const cPtr_impType * inObject,
                                                    const GALGAS_object_5F_t constinArgument_attr,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_3136_b ((cPtr_boolAttribute *) constinArgument_attr.ptr ()) ;
      const enumGalgasBool test_0 = cast_3136_b.getter_value (SOURCE_FILE ("semantic_verification.galgas", 114)).boolEnum () ;
      if (kBoolTrue == test_0) {
        cEnumerator_implementationObjectMap enumerator_3195 (object->mProperty_trueSubAttributes, kENUMERATION_UP) ;
        while (enumerator_3195.hasCurrentObject ()) {
          const enumGalgasBool test_1 = cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 116)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 116)).getter_hasKey (enumerator_3195.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 116)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 116)).boolEnum () ;
          if (kBoolTrue == test_1) {
            GALGAS_object_5F_t var_subAttrs_3300 ;
            cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 118)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 118)).method_get (enumerator_3195.current_lkey (HERE), var_subAttrs_3300, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 118)) ;
            callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_3195.current_type (HERE).ptr (), var_subAttrs_3300, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 119)) ;
          }
          enumerator_3195.gotoNextObject () ;
        }
      }else if (kBoolFalse == test_0) {
        cEnumerator_implementationObjectMap enumerator_3478 (object->mProperty_falseSubAttributes, kENUMERATION_UP) ;
        while (enumerator_3478.hasCurrentObject ()) {
          const enumGalgasBool test_2 = cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 124)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 124)).getter_hasKey (enumerator_3478.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 124)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 124)).boolEnum () ;
          if (kBoolTrue == test_2) {
            GALGAS_object_5F_t var_subAttrs_3583 ;
            cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 126)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 126)).method_get (enumerator_3478.current_lkey (HERE), var_subAttrs_3583, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 126)) ;
            callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_3478.current_type (HERE).ptr (), var_subAttrs_3583, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 127)) ;
          }
          enumerator_3478.gotoNextObject () ;
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 132)), GALGAS_string ("BOOLEAN expected"), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 132)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impBoolType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                   extensionMethod_impBoolType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impBoolType_verifyType (defineExtensionMethod_impBoolType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@impEnumType verifyType'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impEnumType_verifyType (const cPtr_impType * inObject,
                                                    const GALGAS_object_5F_t constinArgument_attr,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impEnumType * object = (const cPtr_impEnumType *) inObject ;
  macroValidSharedObject (object, cPtr_impEnumType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_enumAttribute) {
      GALGAS_enumAttribute cast_3969_e ((cPtr_enumAttribute *) constinArgument_attr.ptr ()) ;
      const enumGalgasBool test_0 = object->mProperty_valuesMap.getter_hasKey (cast_3969_e.getter_value (SOURCE_FILE ("semantic_verification.galgas", 141)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 141)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_implementationObjectMap var_validVal_4053 ;
        object->mProperty_valuesMap.method_get (function_lstringWith (cast_3969_e.getter_value (SOURCE_FILE ("semantic_verification.galgas", 143)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 143)), var_validVal_4053, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 143)) ;
        cEnumerator_implementationObjectMap enumerator_4136 (var_validVal_4053, kENUMERATION_UP) ;
        while (enumerator_4136.hasCurrentObject ()) {
          const enumGalgasBool test_1 = cast_3969_e.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 145)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 145)).getter_hasKey (enumerator_4136.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 145)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 145)).boolEnum () ;
          if (kBoolTrue == test_1) {
            GALGAS_object_5F_t var_subAttrs_4241 ;
            cast_3969_e.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 147)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 147)).method_get (enumerator_4136.current_lkey (HERE), var_subAttrs_4241, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 147)) ;
            callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_4136.current_type (HERE).ptr (), var_subAttrs_4241, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 148)) ;
          }
          enumerator_4136.gotoNextObject () ;
        }
      }else if (kBoolFalse == test_0) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (cast_3969_e.getter_location (SOURCE_FILE ("semantic_verification.galgas", 152)), cast_3969_e.getter_value (SOURCE_FILE ("semantic_verification.galgas", 152)).add_operation (GALGAS_string (" is not a valid enum value"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 152)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 152)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else{
      inCompiler->printMessage (GALGAS_string ("**** @impEnumType ****\n")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 156)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 157)), GALGAS_string ("ENUM expected"), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 157)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impEnumType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impEnumType.mSlotID,
                                   extensionMethod_impEnumType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impEnumType_verifyType (defineExtensionMethod_impEnumType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@impAutoDefaultType verifyType'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impAutoDefaultType_verifyType (const cPtr_impType * inObject,
                                                           const GALGAS_object_5F_t constinArgument_attr,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impAutoDefaultType * object = (const cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_stringAttribute) {
      const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mProperty_type.objectCompare (GALGAS_dataType::constructor_string (SOURCE_FILE ("semantic_verification.galgas", 167)))).operator_and (GALGAS_bool (kIsNotEqual, object->mProperty_type.objectCompare (GALGAS_dataType::constructor_identifier (SOURCE_FILE ("semantic_verification.galgas", 167)))) COMMA_SOURCE_FILE ("semantic_verification.galgas", 167)).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 168)), GALGAS_string ("string of identifier expected"), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 168)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_string_5F_class) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, object->mProperty_type.objectCompare (GALGAS_dataType::constructor_identifier (SOURCE_FILE ("semantic_verification.galgas", 171)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 172)), extensionGetter_oilType (object->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else{
      inCompiler->printMessage (GALGAS_string ("*** @impAutoDefaultType ***\n")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 176)) ;
      constinArgument_attr.log ("attr"  COMMA_SOURCE_FILE ("semantic_verification.galgas", 177)) ;
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 178)), extensionGetter_oilType (object->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)), fixItArray4  COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impAutoDefaultType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                   extensionMethod_impAutoDefaultType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impAutoDefaultType_verifyType (defineExtensionMethod_impAutoDefaultType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension method '@impRangedType verifyType'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impRangedType_verifyType (const cPtr_impType * inObject,
                                                      const GALGAS_object_5F_t constinArgument_attr,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impRangedType * object = (const cPtr_impRangedType *) inObject ;
  macroValidSharedObject (object, cPtr_impRangedType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mProperty_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("semantic_verification.galgas", 188)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 189)), extensionGetter_oilType (object->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, object->mProperty_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("semantic_verification.galgas", 192)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 193)), extensionGetter_oilType (object->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      const enumGalgasBool test_4 = GALGAS_bool (kIsNotEqual, object->mProperty_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("semantic_verification.galgas", 196)))).boolEnum () ;
      if (kBoolTrue == test_4) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 197)), extensionGetter_oilType (object->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)), fixItArray5  COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      const enumGalgasBool test_6 = GALGAS_bool (kIsNotEqual, object->mProperty_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("semantic_verification.galgas", 200)))).boolEnum () ;
      if (kBoolTrue == test_6) {
        TC_Array <C_FixItDescription> fixItArray7 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 201)), extensionGetter_oilType (object->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)), fixItArray7  COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      const enumGalgasBool test_8 = GALGAS_bool (kIsNotEqual, object->mProperty_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("semantic_verification.galgas", 204)))).boolEnum () ;
      if (kBoolTrue == test_8) {
        TC_Array <C_FixItDescription> fixItArray9 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 205)), extensionGetter_oilType (object->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)), fixItArray9  COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
      const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, object->mProperty_withAuto.objectCompare (GALGAS_bool (false))).boolEnum () ;
      if (kBoolTrue == test_10) {
        TC_Array <C_FixItDescription> fixItArray11 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 209)), GALGAS_string ("AUTO is not allowed for ").add_operation (object->mProperty_name.getter_string (SOURCE_FILE ("semantic_verification.galgas", 209)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)), fixItArray11  COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)) ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray12 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 213)), extensionGetter_oilType (object->mProperty_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)), fixItArray12  COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impRangedType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impRangedType.mSlotID,
                                   extensionMethod_impRangedType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impRangedType_verifyType (defineExtensionMethod_impRangedType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'attributeAllowsAuto'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_attributeAllowsAuto (const GALGAS_impType & constinArgument_type,
                                          C_Compiler * /* inCompiler */
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_allowsAuto ; // Returned variable
  result_allowsAuto = GALGAS_bool (true) ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impAutoDefaultType *> (constinArgument_type.ptr ())) {
      GALGAS_impAutoDefaultType cast_6562_autoType ((cPtr_impAutoDefaultType *) constinArgument_type.ptr ()) ;
      const enumGalgasBool test_0 = cast_6562_autoType.getter_withAuto (SOURCE_FILE ("semantic_verification.galgas", 225)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 225)).boolEnum () ;
      if (kBoolTrue == test_0) {
        result_allowsAuto = GALGAS_bool (false) ;
      }
    }else{
      result_allowsAuto = GALGAS_bool (false) ;
    }
  }
//---
  return result_allowsAuto ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_attributeAllowsAuto [2] = {
  & kTypeDescriptor_GALGAS_impType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_attributeAllowsAuto (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_impType operand0 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_attributeAllowsAuto (operand0,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_attributeAllowsAuto ("attributeAllowsAuto",
                                                                     functionWithGenericHeader_attributeAllowsAuto,
                                                                     & kTypeDescriptor_GALGAS_bool,
                                                                     1,
                                                                     functionArgs_attributeAllowsAuto) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'verifyAllAttributes'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyAllAttributes (const GALGAS_implementation constinArgument_imp,
                                  const GALGAS_objectsMap constinArgument_objects,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_objectsMap enumerator_6874 (constinArgument_objects, kENUMERATION_UP) ;
  while (enumerator_6874.hasCurrentObject ()) {
    GALGAS_implementationObject var_impObj_6910 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 242)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 242)) ;
    cEnumerator_objectKindMap enumerator_7042 (enumerator_6874.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("semantic_verification.galgas", 244)), kENUMERATION_UP) ;
    while (enumerator_7042.hasCurrentObject ()) {
      cEnumerator_implementationObjectMap enumerator_7087 (var_impObj_6910.getter_attributes (SOURCE_FILE ("semantic_verification.galgas", 245)), kENUMERATION_UP) ;
      while (enumerator_7087.hasCurrentObject ()) {
        const enumGalgasBool test_0 = enumerator_7042.current_attributes (HERE).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 246)).getter_hasKey (enumerator_7087.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 246)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 246)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_object_5F_t var_value_7288 ;
          enumerator_7042.current_attributes (HERE).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 250)).method_get (enumerator_7087.current_lkey (HERE), var_value_7288, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 250)) ;
          if (var_value_7288.isValid ()) {
            if (var_value_7288.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
              const enumGalgasBool test_1 = function_attributeAllowsAuto (enumerator_7087.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 254)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 254)).boolEnum () ;
              if (kBoolTrue == test_1) {
                TC_Array <C_FixItDescription> fixItArray2 ;
                inCompiler->emitSemanticError (var_value_7288.getter_location (SOURCE_FILE ("semantic_verification.galgas", 255)), GALGAS_string ("AUTO value is not allowed for the ").add_operation (enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 255)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)) ;
              }
            }
          }
        }else if (kBoolFalse == test_0) {
          const enumGalgasBool test_3 = function_attributeAllowsAuto (enumerator_7087.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)).operator_and (enumerator_7087.current_type (HERE).getter_multiple (SOURCE_FILE ("semantic_verification.galgas", 260)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).boolEnum () ;
          if (kBoolTrue == test_3) {
            TC_Array <C_FixItDescription> fixItArray4 ;
            inCompiler->emitSemanticError (enumerator_7042.current_lkey (HERE).getter_location (SOURCE_FILE ("semantic_verification.galgas", 261)), GALGAS_string ("In ").add_operation (enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7042.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (", attribute "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7087.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" is not defined and is not AUTO"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)), fixItArray4  COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)) ;
          }
        }
        if (enumerator_7087.current_type (HERE).isValid ()) {
          if (enumerator_7087.current_type (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impAutoDefaultType) {
          }
        }
        enumerator_7087.gotoNextObject () ;
      }
      enumerator_7042.gotoNextObject () ;
    }
    enumerator_6874.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension method '@multipleAttribute verifyCrossReferences'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_multipleAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                     const GALGAS_objectsMap constinArgument_allObjects,
                                                                     const GALGAS_impType constinArgument_type,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_multipleAttribute * object = (const cPtr_multipleAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_multipleAttribute) ;
  cEnumerator_identifierList enumerator_19027 (object->mProperty_items, kENUMERATION_UP) ;
  while (enumerator_19027.hasCurrentObject ()) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_object_5F_t *) enumerator_19027.current_item (HERE).ptr (), constinArgument_allObjects, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 617)) ;
    enumerator_19027.gotoNextObject () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_multipleAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_multipleAttribute.mSlotID,
                                              extensionMethod_multipleAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_multipleAttribute_verifyCrossReferences (defineExtensionMethod_multipleAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@boolAttribute verifyCrossReferences'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_boolAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                 const GALGAS_objectsMap constinArgument_allObjects,
                                                                 const GALGAS_impType constinArgument_type,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_boolAttribute * object = (const cPtr_boolAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_boolAttribute) ;
  GALGAS_impBoolType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impBoolType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impBoolType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impBoolType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 625)) ;
    }
  }
  GALGAS_impBoolType var_boolType_19222 = temp_0 ;
  const enumGalgasBool test_1 = object->mProperty_value.boolEnum () ;
  if (kBoolTrue == test_1) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_boolType_19222.getter_trueSubAttributes (SOURCE_FILE ("semantic_verification.galgas", 627)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 627)) ;
  }else if (kBoolFalse == test_1) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_boolType_19222.getter_falseSubAttributes (SOURCE_FILE ("semantic_verification.galgas", 629)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 629)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_boolAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_boolAttribute.mSlotID,
                                              extensionMethod_boolAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_boolAttribute_verifyCrossReferences (defineExtensionMethod_boolAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@enumAttribute verifyCrossReferences'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_enumAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                 const GALGAS_objectsMap constinArgument_allObjects,
                                                                 const GALGAS_impType constinArgument_type,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_enumAttribute * object = (const cPtr_enumAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_enumAttribute) ;
  GALGAS_impEnumType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impEnumType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impEnumType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impEnumType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 637)) ;
    }
  }
  GALGAS_impEnumType var_enumType_19578 = temp_0 ;
  GALGAS_lstring var_key_19620 = GALGAS_lstring::constructor_new (object->mProperty_value, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638)) ;
  GALGAS_implementationObjectMap var_expectedAttributes_19729 ;
  var_enumType_19578.getter_valuesMap (SOURCE_FILE ("semantic_verification.galgas", 639)).method_get (var_key_19620, var_expectedAttributes_19729, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 639)) ;
  callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_expectedAttributes_19729, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 640)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_enumAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_enumAttribute.mSlotID,
                                              extensionMethod_enumAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_enumAttribute_verifyCrossReferences (defineExtensionMethod_enumAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@structAttribute verifyCrossReferences'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_structAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                   const GALGAS_objectsMap constinArgument_allObjects,
                                                                   const GALGAS_impType constinArgument_type,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structAttribute * object = (const cPtr_structAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_structAttribute) ;
  GALGAS_impStructType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impStructType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impStructType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impStructType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 647)) ;
    }
  }
  GALGAS_impStructType var_structType_19943 = temp_0 ;
  callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mProperty_subAttributes.ptr (), constinArgument_allObjects, var_structType_19943.getter_structAttributes (SOURCE_FILE ("semantic_verification.galgas", 648)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 648)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_structAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_structAttribute.mSlotID,
                                              extensionMethod_structAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_structAttribute_verifyCrossReferences (defineExtensionMethod_structAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension method '@objectRefAttribute verifyCrossReferences'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_objectRefAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                      const GALGAS_objectsMap constinArgument_allObjects,
                                                                      const GALGAS_impType constinArgument_type,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectRefAttribute * object = (const cPtr_objectRefAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_objectRefAttribute) ;
  GALGAS_refType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_refType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_refType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("refType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 655)) ;
    }
  }
  GALGAS_refType var_refType_20190 = temp_0 ;
  GALGAS_objectKind var_kindMap_20313 ;
  constinArgument_allObjects.method_get (var_refType_20190.getter_ref (SOURCE_FILE ("semantic_verification.galgas", 657)), var_kindMap_20313, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 657)) ;
  const enumGalgasBool test_1 = var_kindMap_20313.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 658)).getter_hasKey (object->mProperty_value.getter_string (SOURCE_FILE ("semantic_verification.galgas", 658)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 658)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 658)).boolEnum () ;
  if (kBoolTrue == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (object->mProperty_value.getter_location (SOURCE_FILE ("semantic_verification.galgas", 659)), GALGAS_string ("Referenced ").add_operation (var_refType_20190.getter_ref (SOURCE_FILE ("semantic_verification.galgas", 659)).getter_string (SOURCE_FILE ("semantic_verification.galgas", 659)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (object->mProperty_value.getter_string (SOURCE_FILE ("semantic_verification.galgas", 659)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (GALGAS_string (" does not exist"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_objectRefAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_objectRefAttribute.mSlotID,
                                              extensionMethod_objectRefAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_objectRefAttribute_verifyCrossReferences (defineExtensionMethod_objectRefAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'verifyAll'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyAll (const GALGAS_implementation constinArgument_imp,
                        const GALGAS_applicationDefinition constinArgument_application,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_verifyAllAttributes (constinArgument_imp, constinArgument_application.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 681)), inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 681)) ;
  }
  callExtensionMethod_verifyApplication ((const cPtr_implementation *) constinArgument_imp.ptr (), constinArgument_application, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 682)) ;
  callExtensionMethod_verifyCrossReferences ((const cPtr_applicationDefinition *) constinArgument_application.ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 685)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Function 'emptyApplicationDefinition'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition function_emptyApplicationDefinition (C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_applicationDefinition result_result ; // Returned variable
  result_result = GALGAS_applicationDefinition::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 56)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 57)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 58)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 59)), GALGAS_objectsMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 60))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 55)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyApplicationDefinition [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyApplicationDefinition (C_Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_emptyApplicationDefinition (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyApplicationDefinition ("emptyApplicationDefinition",
                                                                            functionWithGenericHeader_emptyApplicationDefinition,
                                                                            & kTypeDescriptor_GALGAS_applicationDefinition,
                                                                            0,
                                                                            functionArgs_emptyApplicationDefinition) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'osObject'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_osObject (const GALGAS_objectsMap & constinArgument_objects,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_os ; // Returned variable
  GALGAS_objectKind var_objectsForKind_1623 ;
  constinArgument_objects.method_get (function_lstringWith (GALGAS_string ("OS"), inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)), var_objectsForKind_1623, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)) ;
  GALGAS_lstringlist var_names_1696 = var_objectsForKind_1623.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 68)).getter_keyList (SOURCE_FILE ("goil_types_root.galgas", 68)) ;
  GALGAS_lstring var_name_1749 ;
  var_names_1696.method_first (var_name_1749, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 70)) ;
  var_objectsForKind_1623.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 71)).method_get (var_name_1749, result_os, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 71)) ;
//---
  return result_os ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_osObject [2] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_osObject (C_Compiler * inCompiler,
                                                         const cObjectArray & inEffectiveParameterArray,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_osObject (operand0,
                            inCompiler
                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_osObject ("osObject",
                                                          functionWithGenericHeader_osObject,
                                                          & kTypeDescriptor_GALGAS_objectAttributes,
                                                          1,
                                                          functionArgs_osObject) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'objectForKindAndName'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_objectForKindAndName (const GALGAS_objectsMap & constinArgument_objects,
                                                       const GALGAS_string & constinArgument_kind,
                                                       const GALGAS_string & constinArgument_name,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_object ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 79)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_objectKind var_kindObj_1998 ;
    constinArgument_objects.method_get (function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)), var_kindObj_1998, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)) ;
    const enumGalgasBool test_1 = var_kindObj_1998.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 82)).getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 82)).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_kindObj_1998.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 83)).method_get (function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)), result_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)) ;
    }else if (kBoolFalse == test_1) {
      result_object = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 85))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 85)) ;
    }
  }else if (kBoolFalse == test_0) {
    result_object = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 88))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 88)) ;
  }
//---
  return result_object ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_objectForKindAndName [4] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_objectForKindAndName (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_objectForKindAndName (operand0,
                                        operand1,
                                        operand2,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_objectForKindAndName ("objectForKindAndName",
                                                                      functionWithGenericHeader_objectForKindAndName,
                                                                      & kTypeDescriptor_GALGAS_objectAttributes,
                                                                      3,
                                                                      functionArgs_objectForKindAndName) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'setObjectForKindAndName'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setObjectForKindAndName (GALGAS_objectsMap & ioArgument_objects,
                                      const GALGAS_string constinArgument_kind,
                                      const GALGAS_string constinArgument_name,
                                      const GALGAS_objectAttributes constinArgument_object,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkind_2457 = function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 97)) ;
  GALGAS_lstring var_lname_2495 = function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 98)) ;
  GALGAS_objectKind var_kindObj_2538 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 99))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 99)) ;
  const enumGalgasBool test_0 = ioArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 100)).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    ioArgument_objects.setter_del (var_lkind_2457, var_kindObj_2538, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 101)) ;
    }
  }
  GALGAS_objectKindMap var_kindMap_2686 = var_kindObj_2538.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 103)) ;
  const enumGalgasBool test_1 = var_kindMap_2686.getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 104)).boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    GALGAS_objectAttributes joker_2767 ; // Joker input parameter
    var_kindMap_2686.setter_del (var_lname_2495, joker_2767, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 105)) ;
    }
  }
  {
  var_kindMap_2686.setter_put (var_lname_2495, constinArgument_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 107)) ;
  }
  {
  var_kindObj_2538.setter_setObjects (var_kindMap_2686 COMMA_SOURCE_FILE ("goil_types_root.galgas", 108)) ;
  }
  {
  ioArgument_objects.setter_put (var_lkind_2457, var_kindObj_2538, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 109)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'objectsForKind'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKind function_objectsForKind (const GALGAS_objectsMap & constinArgument_objects,
                                           const GALGAS_string & constinArgument_kind,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectKind result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 116)).boolEnum () ;
  if (kBoolTrue == test_0) {
    constinArgument_objects.method_get (function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 117)), result_result, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 117)) ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 119))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 119)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_objectsForKind [3] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_objectsForKind (C_Compiler * inCompiler,
                                                               const cObjectArray & inEffectiveParameterArray,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_objectsForKind (operand0,
                                  operand1,
                                  inCompiler
                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_objectsForKind ("objectsForKind",
                                                                functionWithGenericHeader_objectsForKind,
                                                                & kTypeDescriptor_GALGAS_objectKind,
                                                                2,
                                                                functionArgs_objectsForKind) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'listInOS'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList function_listInOS (const GALGAS_objectsMap & constinArgument_objects,
                                         const GALGAS_string & constinArgument_attributeName,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList result_items ; // Returned variable
  GALGAS_object_5F_t var_itemsContainer_3252 ;
  GALGAS_objectAttributes var_os_3275 = function_osObject (constinArgument_objects, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 128)) ;
  var_os_3275.getter_objectParams (SOURCE_FILE ("goil_types_root.galgas", 129)).method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 129)), var_itemsContainer_3252, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 129)) ;
  result_items = function_multipleAttributeOrError (var_itemsContainer_3252, constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 130)) ;
//---
  return result_items ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_listInOS [3] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_listInOS (C_Compiler * inCompiler,
                                                         const cObjectArray & inEffectiveParameterArray,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_listInOS (operand0,
                            operand1,
                            inCompiler
                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_listInOS ("listInOS",
                                                          functionWithGenericHeader_listInOS,
                                                          & kTypeDescriptor_GALGAS_identifierList,
                                                          2,
                                                          functionArgs_listInOS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'generate_signed_type'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_signed_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                         GALGAS_string inArgument_err,
                                         GALGAS_string & outArgument_type,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_s_38__1049 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 7U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 37)) ;
  GALGAS_uint_36__34_ var_max_5F_s_31__36__1078 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 15U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 38)) ;
  GALGAS_uint_36__34_ var_max_5F_s_33__32__1107 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 31U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 39)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_38__1049)).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_type = GALGAS_string ("s8") ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_31__36__1078)).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_type = GALGAS_string ("s16") ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_33__32__1107)).boolEnum () ;
      if (kBoolTrue == test_2) {
        outArgument_type = GALGAS_string ("s32") ;
      }else if (kBoolFalse == test_2) {
        outArgument_type = GALGAS_string::makeEmptyString () ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 51)), inArgument_err, fixItArray3  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 51)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'generate_unsigned_type'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_unsigned_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                           GALGAS_string inArgument_err,
                                           GALGAS_string & outArgument_type,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_u_38__1496 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 8U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 62)) ;
  GALGAS_uint_36__34_ var_max_5F_u_31__36__1525 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 16U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 63)) ;
  GALGAS_uint_36__34_ var_max_5F_u_33__32__1554 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 32U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 64)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_38__1496)).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_type = GALGAS_string ("u8") ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_31__36__1525)).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_type = GALGAS_string ("u16") ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_33__32__1554)).boolEnum () ;
      if (kBoolTrue == test_2) {
        outArgument_type = GALGAS_string ("u32") ;
      }else if (kBoolFalse == test_2) {
        outArgument_type = GALGAS_string::makeEmptyString () ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 76)), inArgument_err, fixItArray3  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 76)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'generate_mask_type'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_mask_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                       GALGAS_string inArgument_err,
                                       GALGAS_string & outArgument_type,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_u_38__1937 = GALGAS_uint_36__34_ ((uint64_t) 8ULL) ;
  GALGAS_uint_36__34_ var_max_5F_u_31__36__1961 = GALGAS_uint_36__34_ ((uint64_t) 16ULL) ;
  GALGAS_uint_36__34_ var_max_5F_u_33__32__1985 = GALGAS_uint_36__34_ ((uint64_t) 32ULL) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_38__1937)).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_type = GALGAS_string ("u8") ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_31__36__1961)).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_type = GALGAS_string ("u16") ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_33__32__1985)).boolEnum () ;
      if (kBoolTrue == test_2) {
        outArgument_type = GALGAS_string ("u32") ;
      }else if (kBoolFalse == test_2) {
        outArgument_type = GALGAS_string::makeEmptyString () ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 101)), inArgument_err, fixItArray3  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 101)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@goilContext fullPrefix'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_goilContext_fullPrefix (const cPtr_gtlContext * inObject,
                                                              const GALGAS_gtlData constinArgument_vars,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_full ; // Returned variable
  const cPtr_goilContext * object = (const cPtr_goilContext *) inObject ;
  macroValidSharedObject (object, cPtr_goilContext) ;
  GALGAS_string var_stringPrefix_22305 = object->mProperty_prefix.getter_string (SOURCE_FILE ("goil_code_generation.galgas", 689)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("compiler").objectCompare (var_stringPrefix_22305)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlData var_compiler_22414 ;
    GALGAS_bool joker_22416 ; // Joker input parameter
    callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("COMPILER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 691)), var_compiler_22414, joker_22416, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 691)) ;
    GALGAS_gtlString temp_1 ;
    if (var_compiler_22414.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlString *> (var_compiler_22414.ptr ())) {
        temp_1 = (cPtr_gtlString *) var_compiler_22414.ptr () ;
      }else{
        inCompiler->castError ("gtlString", var_compiler_22414.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)) ;
      }
    }
    var_stringPrefix_22305.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("linker").objectCompare (var_stringPrefix_22305)).boolEnum () ;
    if (kBoolTrue == test_2) {
      GALGAS_gtlData var_linker_22566 ;
      GALGAS_bool joker_22568 ; // Joker input parameter
      callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("LINKER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 694)), var_linker_22566, joker_22568, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 694)) ;
      GALGAS_gtlString temp_3 ;
      if (var_linker_22566.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (var_linker_22566.ptr ())) {
          temp_3 = (cPtr_gtlString *) var_linker_22566.ptr () ;
        }else{
          inCompiler->castError ("gtlString", var_linker_22566.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)) ;
        }
      }
      var_stringPrefix_22305.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_3.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("assembler").objectCompare (var_stringPrefix_22305)).boolEnum () ;
      if (kBoolTrue == test_4) {
        GALGAS_gtlData var_assembler_22725 ;
        GALGAS_bool joker_22727 ; // Joker input parameter
        callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("ASSEMBLER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 697)), var_assembler_22725, joker_22727, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 697)) ;
        GALGAS_gtlString temp_5 ;
        if (var_assembler_22725.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlString *> (var_assembler_22725.ptr ())) {
            temp_5 = (cPtr_gtlString *) var_assembler_22725.ptr () ;
          }else{
            inCompiler->castError ("gtlString", var_assembler_22725.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)) ;
          }
        }
        var_stringPrefix_22305.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_5.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)) ;
      }else if (kBoolFalse == test_4) {
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_stringPrefix_22305.objectCompare (GALGAS_string ("ROOT"))).boolEnum () ;
        if (kBoolTrue == test_6) {
          var_stringPrefix_22305 = GALGAS_string::makeEmptyString () ;
        }
      }
    }
  }
  result_full = GALGAS_lstring::constructor_new (var_stringPrefix_22305, object->mProperty_prefix.getter_location (SOURCE_FILE ("goil_code_generation.galgas", 702))  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 702)) ;
//---
  return result_full ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_goilContext_fullPrefix (void) {
  enterExtensionGetter_fullPrefix (kTypeDescriptor_GALGAS_goilContext.mSlotID,
                                   extensionGetter_goilContext_fullPrefix) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_goilContext_fullPrefix (defineExtensionGetter_goilContext_fullPrefix, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'emptyGoilContext'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_goilContext function_emptyGoilContext (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_goilContext result_context ; // Returned variable
  result_context = GALGAS_goilContext::constructor_new (function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 710)), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string (".gtl"), GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 714)), GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 715)), GALGAS_bool (true), function_defaultDebugSettings (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 717))  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 709)) ;
//---
  return result_context ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyGoilContext [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyGoilContext (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_emptyGoilContext (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyGoilContext ("emptyGoilContext",
                                                                  functionWithGenericHeader_emptyGoilContext,
                                                                  & kTypeDescriptor_GALGAS_goilContext,
                                                                  0,
                                                                  functionArgs_emptyGoilContext) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'generate_all'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_all (GALGAS_gtlData inArgument_cfg,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_temp_5F_dir_23403 = function_templates_5F_directory (GALGAS_string ("code"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 734)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_temp_5F_dir_23403.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_string var_target_23481 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_target_23481.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_gtlContext var_context_24233 = function_emptyGoilContext (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 759)) ;
      {
      var_context_24233.setter_setTemplateDirectory (function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 761)) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 760)) ;
      }
      {
      var_context_24233.setter_setTemplateExtension (GALGAS_string ("goilTemplate") COMMA_SOURCE_FILE ("goil_code_generation.galgas", 763)) ;
      }
      {
      var_context_24233.insulate (HERE) ;
      cPtr_gtlContext * ptr_24449 = (cPtr_gtlContext *) var_context_24233.ptr () ;
      callExtensionSetter_addModulePath ((cPtr_gtlContext *) ptr_24449, function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 767)), GALGAS_string ("lib"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 766)) ;
      }
      {
      var_context_24233.setter_setPath (GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 770)) ;
      }
      GALGAS_library var_lib_24677 = function_emptyLib (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 774)) ;
      GALGAS_string var_goilLog_24720 = function_invokeGTL (GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 777)), function_lstring (GALGAS_string ("root template filename"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 778)), GALGAS_string (gOption_goil_5F_options_root.getter_value ())  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 776)), var_context_24233, inArgument_cfg, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 775)) ;
      const enumGalgasBool test_2 = GALGAS_bool (gOption_goil_5F_options_generate_5F_log.getter_value ()).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_goilLog_24720.method_writeToFile (GALGAS_string ("goil.log"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 793)) ;
      }
    }else if (kBoolFalse == test_1) {
      inCompiler->printMessage (GALGAS_string ("No target platform given, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 813)) ;
    }
  }else if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("No template directory defined, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 816)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'getAutosarVersion'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_getAutosarVersion (GALGAS_arxmlNode inArgument_rootNode,
                                GALGAS_lstring & outArgument_iAutosarVersion,
                                GALGAS_lstring & outArgument_iAutosarDescription,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_iAutosarVersion.drop () ; // Release 'out' argument
  outArgument_iAutosarDescription.drop () ; // Release 'out' argument
  GALGAS_lstring var_autosarVersion_7850 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 273)) ;
  GALGAS_lstring var_autosarDescription_7899 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 274)) ;
  GALGAS_arxmlElementList var_autosarNodes_8018 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 277)) ;
  callExtensionMethod_getSubElementsFromName ((const cPtr_arxmlNode *) inArgument_rootNode.ptr (), GALGAS_string ("AUTOSAR"), var_autosarNodes_8018, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 278)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, var_autosarNodes_8018.getter_length (SOURCE_FILE ("arxml_parser.galgas", 279)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 280)), GALGAS_string ("[TPS_GST_00077] : Missing root AUTOSAR node."), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 280)) ;
  }
  GALGAS_arxmlElementList var_adminDataNodes_8237 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 283)) ;
  extensionMethod_getSubElementsFromName (var_autosarNodes_8018, GALGAS_string ("ADMIN-DATA"), var_adminDataNodes_8237, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 284)) ;
  const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_adminDataNodes_8237.getter_length (SOURCE_FILE ("arxml_parser.galgas", 285)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 286)), GALGAS_string ("[TPS_ECUC_06004] : Missing AUTOSAR's ADMIN-DATA node."), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 286)) ;
  }
  GALGAS_arxmlElementList var_revisions_8471 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 289)) ;
  extensionMethod_getElementsFromName (var_adminDataNodes_8237, GALGAS_string ("DOC-REVISION"), var_revisions_8471, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 290)) ;
  const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_adminDataNodes_8237.getter_length (SOURCE_FILE ("arxml_parser.galgas", 291)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_4) {
    TC_Array <C_FixItDescription> fixItArray5 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 292)), GALGAS_string ("Missing AUTOSAR'S ADMIN-DATA's DOC-REVISION NODE"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 292)) ;
  }
  GALGAS_bool var_version_5F_found_8688 = GALGAS_bool (false) ;
  GALGAS_bool var_issued_5F_by_5F_found_8720 = GALGAS_bool (false) ;
  GALGAS_lstring var_issued_5F_by_8749 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 297)) ;
  cEnumerator_arxmlElementList enumerator_8817 (var_revisions_8471, kENUMERATION_UP) ;
  bool bool_6 = var_version_5F_found_8688.operator_not (SOURCE_FILE ("arxml_parser.galgas", 300)).isValidAndTrue () ;
  if (enumerator_8817.hasCurrentObject () && bool_6) {
    while (enumerator_8817.hasCurrentObject () && bool_6) {
      var_issued_5F_by_5F_found_8720 = GALGAS_bool (false) ;
      callExtensionMethod_getProperty ((const cPtr_arxmlElementNode *) enumerator_8817.current_node (HERE).ptr (), GALGAS_string ("ISSUED-BY"), var_issued_5F_by_8749, var_issued_5F_by_5F_found_8720, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 302)) ;
      GALGAS_bool test_7 = var_issued_5F_by_5F_found_8720 ;
      if (kBoolTrue == test_7.boolEnum ()) {
        test_7 = GALGAS_bool (kIsEqual, var_issued_5F_by_8749.mProperty_string.objectCompare (GALGAS_string ("AUTOSAR"))) ;
      }
      const enumGalgasBool test_8 = test_7.boolEnum () ;
      if (kBoolTrue == test_8) {
        GALGAS_bool var_description_5F_found_9035 = GALGAS_bool (false) ;
        callExtensionMethod_getProperty ((const cPtr_arxmlElementNode *) enumerator_8817.current_node (HERE).ptr (), GALGAS_string ("REVISION-LABEL"), var_autosarVersion_7850, var_version_5F_found_8688, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 305)) ;
        callExtensionMethod_getProperty ((const cPtr_arxmlElementNode *) enumerator_8817.current_node (HERE).ptr (), GALGAS_string ("DATE"), var_autosarDescription_7899, var_description_5F_found_9035, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 306)) ;
      }
      enumerator_8817.gotoNextObject () ;
      if (enumerator_8817.hasCurrentObject ()) {
        bool_6 = var_version_5F_found_8688.operator_not (SOURCE_FILE ("arxml_parser.galgas", 300)).isValidAndTrue () ;
      }
    }
  }
  outArgument_iAutosarVersion = var_autosarVersion_7850 ;
  outArgument_iAutosarDescription = var_autosarDescription_7899 ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'includeConfigs'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_includeConfigs (GALGAS_implementation & ioArgument_imp,
                             GALGAS_applicationDefinition & ioArgument_application,
                             GALGAS_string & ioArgument_fileIncludeList,
                             GALGAS_lstring inArgument_version,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_config_5F_file_5F_name_9570 = GALGAS_string (gOption_goil_5F_options_config.getter_value ()) ;
  GALGAS_stringlist var_configFiles_9635 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_9570.add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 325)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 324)) ;
  cEnumerator_stringlist enumerator_9903 (var_configFiles_9635, kENUMERATION_DOWN) ;
  while (enumerator_9903.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_9903.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 330)), ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 330)) ;
    enumerator_9903.gotoNextObject () ;
  }
  GALGAS_stringlist var_configVersionFiles_10208 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_9570.add_operation (inArgument_version.getter_string (SOURCE_FILE ("arxml_parser.galgas", 337)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 337)).add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 337)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 336)) ;
  cEnumerator_stringlist enumerator_10369 (var_configVersionFiles_10208, kENUMERATION_DOWN) ;
  while (enumerator_10369.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_10369.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 340)), ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 340)) ;
    enumerator_10369.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'nodeToClass'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_nodeToClass (GALGAS_arxmlNode inArgument_rootNode,
                          GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                          GALGAS_arxmlElementValue & outArgument_rootValue,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_rootValue.drop () ; // Release 'out' argument
  GALGAS_arxmlElementList var_autosarNodes_10723 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 351)) ;
  callExtensionMethod_getSubElementsFromName ((const cPtr_arxmlNode *) inArgument_rootNode.ptr (), GALGAS_string ("AUTOSAR"), var_autosarNodes_10723, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 352)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, var_autosarNodes_10723.getter_length (SOURCE_FILE ("arxml_parser.galgas", 353)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 354)), GALGAS_string ("[TPS_GST_00077] : Missing root AUTOSAR node."), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 354)) ;
  }
  const enumGalgasBool test_2 = GALGAS_bool (kIsStrictSup, var_autosarNodes_10723.getter_length (SOURCE_FILE ("arxml_parser.galgas", 356)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
  if (kBoolTrue == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 357)), GALGAS_string ("[TPS_GST_00077] : Too many AUTOSAR nodes."), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 357)) ;
  }
  GALGAS_arxmlElementNode var_autosarNode_11078 ;
  var_autosarNodes_10723.method_first (var_autosarNode_11078, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 362)) ;
  {
  routine_nodeToClassRes (var_autosarNode_11078, ioArgument_classMap, outArgument_rootValue, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 363)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'nodeToClassRes'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_nodeToClassRes (GALGAS_arxmlElementNode inArgument_currentElement,
                             GALGAS_arxmlMetaClassMap inArgument_classMap,
                             GALGAS_arxmlElementValue & outArgument_elementValue,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_elementValue.drop () ; // Release 'out' argument
  GALGAS_arxmlMetaClass var_currentClass_11349 ;
  inArgument_classMap.method_searchKey (inArgument_currentElement.getter_name (SOURCE_FILE ("arxml_parser.galgas", 373)), var_currentClass_11349, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 373)) ;
  GALGAS_bool var_textFound_11455 = GALGAS_bool (false) ;
  GALGAS_lstring var_text_11479 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 377))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 377)) ;
  callExtensionMethod_getText ((const cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), var_text_11479, var_textFound_11455, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 378)) ;
  GALGAS_lstring var_type_11593 = var_currentClass_11349.getter_name (SOURCE_FILE ("arxml_parser.galgas", 381)) ;
  outArgument_elementValue = GALGAS_arxmlElementValue::constructor_new (var_type_11593, var_text_11479, GALGAS_arxmlElementValueMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 385)), inArgument_currentElement.getter_attributes (SOURCE_FILE ("arxml_parser.galgas", 386))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 382)) ;
  GALGAS_arxmlElementList var_subElements_12002 ;
  callExtensionMethod_getSubElements ((const cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), var_subElements_12002, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 390)) ;
  cEnumerator_arxmlElementList enumerator_12055 (var_subElements_12002, kENUMERATION_UP) ;
  while (enumerator_12055.hasCurrentObject ()) {
    const enumGalgasBool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlMetaClass *) var_currentClass_11349.ptr (), enumerator_12055.current_node (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 392)).mProperty_string, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 392)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 392)).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (enumerator_12055.current_node (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 393)).getter_location (SOURCE_FILE ("arxml_parser.galgas", 393)), GALGAS_string ("The element ").add_operation (enumerator_12055.current_node (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 393)).mProperty_string, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)).add_operation (GALGAS_string (" does not belong to the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)).add_operation (inArgument_currentElement.getter_name (SOURCE_FILE ("arxml_parser.galgas", 395)).mProperty_string, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 394)).add_operation (GALGAS_string (" element.\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 395)).add_operation (GALGAS_string ("Possible elements are :\n"
        " "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 395)).add_operation (extensionGetter_string (var_currentClass_11349.getter_lElementLegacy (SOURCE_FILE ("arxml_parser.galgas", 396)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 396)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 396)), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)) ;
    }
    enumerator_12055.gotoNextObject () ;
  }
  const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, inArgument_currentElement.getter_name (SOURCE_FILE ("arxml_parser.galgas", 402)).mProperty_string.objectCompare (GALGAS_string ("AUTOSAR"))).boolEnum () ;
  if (kBoolTrue == test_2) {
    cEnumerator_arxmlAttributeMap enumerator_12593 (inArgument_currentElement.getter_attributes (SOURCE_FILE ("arxml_parser.galgas", 403)), kENUMERATION_UP) ;
    while (enumerator_12593.hasCurrentObject ()) {
      const enumGalgasBool test_3 = callExtensionGetter_hasAttribute ((const cPtr_arxmlMetaClass *) var_currentClass_11349.ptr (), enumerator_12593.current_lkey (HERE).mProperty_string, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 404)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 404)).boolEnum () ;
      if (kBoolTrue == test_3) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (enumerator_12593.current_lkey (HERE).getter_location (SOURCE_FILE ("arxml_parser.galgas", 405)), GALGAS_string ("The attribute ").add_operation (enumerator_12593.current_lkey (HERE).mProperty_string, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (GALGAS_string (" does not belong to the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (inArgument_currentElement.getter_name (SOURCE_FILE ("arxml_parser.galgas", 406)).mProperty_string, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (GALGAS_string (" element.\n"
          "Possible "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 406)).add_operation (GALGAS_string ("attributes are :\n"
          " "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 406)).add_operation (extensionGetter_string (var_currentClass_11349.getter_lAttributeLegacy (SOURCE_FILE ("arxml_parser.galgas", 407)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 407)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 407)), fixItArray4  COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)) ;
      }
      enumerator_12593.gotoNextObject () ;
    }
  }
  cEnumerator_arxmlMetaElementList enumerator_13043 (var_currentClass_11349.getter_lElementLegacy (SOURCE_FILE ("arxml_parser.galgas", 413)), kENUMERATION_UP) ;
  while (enumerator_13043.hasCurrentObject ()) {
    GALGAS_arxmlElementList var_subElements_13080 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 414)) ;
    callExtensionMethod_getSubElementsFromName ((const cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), enumerator_13043.current_lElement (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 416)).mProperty_string, var_subElements_13080, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 416)) ;
    GALGAS_uint var_minOccurs_13297 = GALGAS_uint ((uint32_t) 1U) ;
    GALGAS_uint var_maxOccurs_13321 = GALGAS_uint ((uint32_t) 1U) ;
    GALGAS_bool test_5 = GALGAS_bool (kIsNotEqual, enumerator_13043.current_lElement (HERE).getter_minOccurs (SOURCE_FILE ("arxml_parser.galgas", 423)).mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())) ;
    if (kBoolTrue == test_5.boolEnum ()) {
      test_5 = enumerator_13043.current_lElement (HERE).getter_minOccurs (SOURCE_FILE ("arxml_parser.galgas", 424)).mProperty_string.getter_isDecimalUnsignedNumber (SOURCE_FILE ("arxml_parser.galgas", 424)) ;
    }
    const enumGalgasBool test_6 = test_5.boolEnum () ;
    if (kBoolTrue == test_6) {
      var_minOccurs_13297 = enumerator_13043.current_lElement (HERE).getter_minOccurs (SOURCE_FILE ("arxml_parser.galgas", 425)).mProperty_string.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 425)) ;
    }
    const enumGalgasBool test_7 = GALGAS_bool (kIsStrictInf, var_subElements_13080.getter_length (SOURCE_FILE ("arxml_parser.galgas", 428)).objectCompare (var_minOccurs_13297)).boolEnum () ;
    if (kBoolTrue == test_7) {
      TC_Array <C_FixItDescription> fixItArray8 ;
      inCompiler->emitSemanticError (inArgument_currentElement.getter_name (SOURCE_FILE ("arxml_parser.galgas", 429)).getter_location (SOURCE_FILE ("arxml_parser.galgas", 429)), GALGAS_string ("Missing element ").add_operation (enumerator_13043.current_lElement (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 429)).mProperty_string, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)).add_operation (GALGAS_string (". Minimum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)).add_operation (var_minOccurs_13297.getter_string (SOURCE_FILE ("arxml_parser.galgas", 430)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (GALGAS_string (" Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (var_subElements_13080.getter_length (SOURCE_FILE ("arxml_parser.galgas", 431)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 431)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 431)), fixItArray8  COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)) ;
    }
    GALGAS_bool test_9 = GALGAS_bool (kIsNotEqual, enumerator_13043.current_lElement (HERE).getter_maxOccurs (SOURCE_FILE ("arxml_parser.galgas", 435)).mProperty_string.objectCompare (GALGAS_string ("unbounded"))) ;
    if (kBoolTrue == test_9.boolEnum ()) {
      test_9 = GALGAS_bool (kIsNotEqual, enumerator_13043.current_lElement (HERE).getter_maxOccurs (SOURCE_FILE ("arxml_parser.galgas", 436)).mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())) ;
    }
    const enumGalgasBool test_10 = test_9.boolEnum () ;
    if (kBoolTrue == test_10) {
      GALGAS_bool test_11 = GALGAS_bool (kIsNotEqual, enumerator_13043.current_lElement (HERE).getter_maxOccurs (SOURCE_FILE ("arxml_parser.galgas", 438)).mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())) ;
      if (kBoolTrue == test_11.boolEnum ()) {
        test_11 = enumerator_13043.current_lElement (HERE).getter_maxOccurs (SOURCE_FILE ("arxml_parser.galgas", 439)).mProperty_string.getter_isDecimalUnsignedNumber (SOURCE_FILE ("arxml_parser.galgas", 439)) ;
      }
      const enumGalgasBool test_12 = test_11.boolEnum () ;
      if (kBoolTrue == test_12) {
        var_maxOccurs_13321 = enumerator_13043.current_lElement (HERE).getter_maxOccurs (SOURCE_FILE ("arxml_parser.galgas", 440)).mProperty_string.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 440)) ;
      }
      const enumGalgasBool test_13 = GALGAS_bool (kIsStrictSup, var_subElements_13080.getter_length (SOURCE_FILE ("arxml_parser.galgas", 443)).objectCompare (var_maxOccurs_13321)).boolEnum () ;
      if (kBoolTrue == test_13) {
        GALGAS_arxmlElementNode var_subElement_14334 ;
        var_subElements_13080.method_last (var_subElement_14334, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)) ;
        TC_Array <C_FixItDescription> fixItArray14 ;
        inCompiler->emitSemanticError (inArgument_currentElement.getter_name (SOURCE_FILE ("arxml_parser.galgas", 446)).getter_location (SOURCE_FILE ("arxml_parser.galgas", 446)), GALGAS_string ("Too many node ").add_operation (enumerator_13043.current_lElement (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 446)).mProperty_string, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 446)).add_operation (GALGAS_string (". Minimum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 446)).add_operation (var_minOccurs_13297.getter_string (SOURCE_FILE ("arxml_parser.galgas", 447)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 447)).add_operation (GALGAS_string (" ; Maximum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 447)).add_operation (var_maxOccurs_13321.getter_string (SOURCE_FILE ("arxml_parser.galgas", 447)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 447)).add_operation (GALGAS_string (". Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 447)).add_operation (var_subElements_13080.getter_length (SOURCE_FILE ("arxml_parser.galgas", 448)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 448)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 448)), fixItArray14  COMMA_SOURCE_FILE ("arxml_parser.galgas", 446)) ;
      }
    }
    cEnumerator_arxmlElementList enumerator_14691 (var_subElements_13080, kENUMERATION_UP) ;
    while (enumerator_14691.hasCurrentObject ()) {
      GALGAS_arxmlElementValue var_subElementValue_14735 ;
      {
      routine_nodeToClassRes (enumerator_14691.current_node (HERE), inArgument_classMap, var_subElementValue_14735, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 455)) ;
      }
      {
      outArgument_elementValue.insulate (HERE) ;
      cPtr_arxmlElementValue * ptr_14818 = (cPtr_arxmlElementValue *) outArgument_elementValue.ptr () ;
      callExtensionSetter_insertElement ((cPtr_arxmlElementValue *) ptr_14818, enumerator_14691.current_node (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 456)), var_subElementValue_14735, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 456)) ;
      }
      enumerator_14691.gotoNextObject () ;
    }
    enumerator_13043.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Routine 'addText'                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addText (GALGAS_arxmlNodeList & ioArgument_nodes,
                      const GALGAS_bool constinArgument_doNotCondenseWhiteSpaces,
                      C_Compiler * inCompiler
                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_s_14982 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 465)) ;
  GALGAS_string var_trimmedString_15040 = var_s_14982.getter_stringByTrimmingWhiteSpaces (SOURCE_FILE ("arxml_parser.galgas", 466)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_trimmedString_15040.getter_length (SOURCE_FILE ("arxml_parser.galgas", 467)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_ls_15127 ;
    const enumGalgasBool test_1 = constinArgument_doNotCondenseWhiteSpaces.boolEnum () ;
    if (kBoolTrue == test_1) {
      var_ls_15127 = GALGAS_lstring::constructor_new (var_s_14982, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 470))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 470)) ;
    }else if (kBoolFalse == test_1) {
      var_ls_15127 = GALGAS_lstring::constructor_new (var_trimmedString_15040, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 472))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 472)) ;
    }
    ioArgument_nodes.addAssign_operation (GALGAS_arxmlTextNode::constructor_new (var_ls_15127  COMMA_SOURCE_FILE ("arxml_parser.galgas", 475))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 475)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'convertToOil'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_convertToOil (GALGAS_implementation & ioArgument_imp,
                           GALGAS_applicationDefinition & ioArgument_application,
                           GALGAS_arxmlElementValue inArgument_rootValue,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_emptyPath_15444 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 484))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 484)) ;
  GALGAS_arxmlElementValueList var_packages_15530 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 487)) ;
  GALGAS_stringlist var_packagesPath_15562 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 488)) ;
  var_packagesPath_15562.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 489)) ;
  var_packagesPath_15562.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 490)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_rootValue.ptr (), var_packagesPath_15562, var_packages_15530, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 491)) ;
  cEnumerator_arxmlElementValueList enumerator_15759 (var_packages_15530, kENUMERATION_UP) ;
  while (enumerator_15759.hasCurrentObject ()) {
    {
    routine_arxmlImplementationPackage (ioArgument_imp, enumerator_15759.current_value (HERE), var_emptyPath_15444, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 495)) ;
    }
    enumerator_15759.gotoNextObject () ;
  }
  cEnumerator_arxmlElementValueList enumerator_15893 (var_packages_15530, kENUMERATION_UP) ;
  while (enumerator_15893.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionPackage (ioArgument_imp, ioArgument_application, enumerator_15893.current_value (HERE), var_emptyPath_15444, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 500)) ;
    }
    enumerator_15893.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'arxmlImplementationPackage'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlImplementationPackage (GALGAS_implementation & ioArgument_imp,
                                         GALGAS_arxmlElementValue inArgument_packageElement,
                                         GALGAS_lstring inArgument_parentPath,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_packageName_16253 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 514)) ;
  GALGAS_lstring var_currentPath_16362 = GALGAS_lstring::constructor_new (inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 517)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 517)).add_operation (var_packageName_16253.getter_string (SOURCE_FILE ("arxml_parser.galgas", 517)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 517)), var_packageName_16253.getter_location (SOURCE_FILE ("arxml_parser.galgas", 518))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 517)) ;
  GALGAS_arxmlElementValueList var_definitions_16588 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 521)) ;
  GALGAS_stringlist var_definitionPath_16622 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 522)) ;
  var_definitionPath_16622.addAssign_operation (GALGAS_string ("ELEMENTS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 523)) ;
  var_definitionPath_16622.addAssign_operation (GALGAS_string ("ECUC-MODULE-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 524)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_definitionPath_16622, var_definitions_16588, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 525)) ;
  cEnumerator_arxmlElementValueList enumerator_16817 (var_definitions_16588, kENUMERATION_UP) ;
  while (enumerator_16817.hasCurrentObject ()) {
    {
    routine_arxmlImplementationRoot (ioArgument_imp, enumerator_16817.current_value (HERE), var_currentPath_16362, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 527)) ;
    }
    enumerator_16817.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_packages_16975 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 531)) ;
  GALGAS_stringlist var_packagesPath_17007 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 532)) ;
  var_packagesPath_17007.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 533)) ;
  var_packagesPath_17007.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 534)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_packagesPath_17007, var_packages_16975, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 535)) ;
  cEnumerator_arxmlElementValueList enumerator_17185 (var_packages_16975, kENUMERATION_UP) ;
  while (enumerator_17185.hasCurrentObject ()) {
    {
    routine_arxmlImplementationPackage (ioArgument_imp, enumerator_17185.current_value (HERE), var_currentPath_16362, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 537)) ;
    }
    enumerator_17185.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'arxmlImplementationRoot'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlImplementationRoot (GALGAS_implementation & ioArgument_implementation,
                                      GALGAS_arxmlElementValue inArgument_packageElement,
                                      GALGAS_lstring inArgument_parentPath,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_objectName_17433 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 547)) ;
  {
  routine_displayOil (GALGAS_string ("\n"
    "IMPLEMENTATION ").add_operation (var_objectName_17433.getter_string (SOURCE_FILE ("arxml_parser.galgas", 548)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 548)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 548)) ;
  }
  GALGAS_lstring var_currentPath_17589 = GALGAS_lstring::constructor_new (inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 551)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 551)).add_operation (var_objectName_17433.getter_string (SOURCE_FILE ("arxml_parser.galgas", 551)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 551)), inArgument_parentPath.getter_location (SOURCE_FILE ("arxml_parser.galgas", 552))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 551)) ;
  GALGAS_lstring var_oil_5F_desc_17788 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_17788, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 555)) ;
  }
  GALGAS_lbool var_multiple_17879 ;
  {
  routine_arxmlGetMultiplicity (inArgument_packageElement, var_objectName_17433, var_multiple_17879, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 558)) ;
  }
  GALGAS_arxmlElementValueList var_subDefs_17941 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 561)) ;
  GALGAS_stringlist var_subDefsPath_17972 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 562)) ;
  var_subDefsPath_17972.addAssign_operation (GALGAS_string ("CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 563)) ;
  var_subDefsPath_17972.addAssign_operation (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 564)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_subDefsPath_17972, var_subDefs_17941, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 565)) ;
  {
  routine_displayOil (GALGAS_string ("\n"
    "{\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 567)) ;
  }
  cEnumerator_arxmlElementValueList enumerator_18230 (var_subDefs_17941, kENUMERATION_UP) ;
  while (enumerator_18230.hasCurrentObject ()) {
    {
    routine_arxmlImplementationObject (ioArgument_implementation, enumerator_18230.current_value (HERE), var_currentPath_17589, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 571)) ;
    }
    enumerator_18230.gotoNextObject () ;
  }
  {
  routine_displayOil (GALGAS_string ("}; /* END IMPLEMENTATION ").add_operation (var_objectName_17433.getter_string (SOURCE_FILE ("arxml_parser.galgas", 574)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 574)).add_operation (GALGAS_string (" : \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 574)).add_operation (var_oil_5F_desc_17788.getter_string (SOURCE_FILE ("arxml_parser.galgas", 575)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 575)).add_operation (GALGAS_string ("\" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 575)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 574)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Routine 'arxmlImplementationObject'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlImplementationObject (GALGAS_implementation & ioArgument_implementation,
                                        GALGAS_arxmlElementValue inArgument_packageElement,
                                        GALGAS_lstring inArgument_parentPath,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationMap var_imp_18584 = ioArgument_implementation.getter_imp (SOURCE_FILE ("arxml_parser.galgas", 583)) ;
  GALGAS_implementationObjectMap var_objectAttributes_18651 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 584)) ;
  GALGAS_lstring var_objectName_18803 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 588)) ;
  GALGAS_lstring var_currentPath_18911 = GALGAS_lstring::constructor_new (inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 591)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 591)).add_operation (var_objectName_18803.getter_string (SOURCE_FILE ("arxml_parser.galgas", 591)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 591)), inArgument_parentPath.getter_location (SOURCE_FILE ("arxml_parser.galgas", 592))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 591)) ;
  GALGAS_lstring var_objectKind_19159 = var_objectName_18803 ;
  var_objectKind_19159.mProperty_string = var_objectName_18803.getter_string (SOURCE_FILE ("arxml_parser.galgas", 596)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 596)) ;
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (var_objectKind_19159.getter_string (SOURCE_FILE ("arxml_parser.galgas", 598)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 598)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 598)) ;
  }
  GALGAS_lbool var_multiple_19377 ;
  {
  routine_arxmlGetMultiplicity (inArgument_packageElement, var_objectName_18803, var_multiple_19377, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 601)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    "  {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 602)) ;
  }
  GALGAS_lstring var_oil_5F_desc_19492 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_19492, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 605)) ;
  }
  {
  routine_arxmlImplementationContainer (var_objectAttributes_18651, inArgument_packageElement, var_currentPath_18911, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 608)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  }; /* \"").add_operation (var_oil_5F_desc_19492.getter_string (SOURCE_FILE ("arxml_parser.galgas", 612)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 612)).add_operation (GALGAS_string ("\"*/\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 612)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 612)) ;
  }
  GALGAS_implementationObject var_newObject_19794 = GALGAS_implementationObject::constructor_new (var_multiple_19377, var_objectAttributes_18651  COMMA_SOURCE_FILE ("arxml_parser.galgas", 616)) ;
  GALGAS_implementationObject var_object_19964 ;
  const enumGalgasBool test_0 = callExtensionGetter_hasKey ((const cPtr_implementation *) ioArgument_implementation.ptr (), var_objectName_18803.getter_string (SOURCE_FILE ("arxml_parser.galgas", 621)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 621)).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    var_imp_18584.setter_del (var_objectName_18803, var_object_19964, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 622)) ;
    }
    var_object_19964 = callExtensionGetter_mergeImplementationObjectWith ((const cPtr_implementationObject *) var_object_19964.ptr (), var_newObject_19794, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 623)) ;
  }else if (kBoolFalse == test_0) {
    var_object_19964 = var_newObject_19794 ;
  }
  {
  var_imp_18584.setter_put (var_objectName_18803, var_object_19964, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 629)) ;
  }
  {
  ioArgument_implementation.setter_setImp (var_imp_18584 COMMA_SOURCE_FILE ("arxml_parser.galgas", 630)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Routine 'arxmlImplementationContainer'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlImplementationContainer (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                           GALGAS_arxmlElementValue inArgument_currentElement,
                                           GALGAS_lstring inArgument_parentPath,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList var_intParameters_20623 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 641)) ;
  GALGAS_stringlist var_intParametersPath_20660 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 642)) ;
  var_intParametersPath_20660.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 643)) ;
  var_intParametersPath_20660.addAssign_operation (GALGAS_string ("ECUC-INTEGER-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 644)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_intParametersPath_20660, var_intParameters_20623, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 645)) ;
  cEnumerator_arxmlElementValueList enumerator_20877 (var_intParameters_20623, kENUMERATION_UP) ;
  while (enumerator_20877.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_20907 ;
    GALGAS_impType var_type_20925 ;
    {
    routine_arxmlImplementationContainerNumber (var_attributeName_20907, var_type_20925, GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 652)), enumerator_20877.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 650)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_20907, var_type_20925, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 655)) ;
    }
    enumerator_20877.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_floatParameters_21489 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 661)) ;
  GALGAS_stringlist var_floatParametersPath_21528 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 662)) ;
  var_floatParametersPath_21528.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 663)) ;
  var_floatParametersPath_21528.addAssign_operation (GALGAS_string ("ECUC-FLOAT-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 664)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_floatParametersPath_21528, var_floatParameters_21489, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 665)) ;
  cEnumerator_arxmlElementValueList enumerator_21753 (var_floatParameters_21489, kENUMERATION_UP) ;
  while (enumerator_21753.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_21783 ;
    GALGAS_impType var_type_21801 ;
    {
    routine_arxmlImplementationContainerNumber (var_attributeName_21783, var_type_21801, GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 672)), enumerator_21753.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 670)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_21783, var_type_21801, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 675)) ;
    }
    enumerator_21753.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_stringParameters_22353 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 681)) ;
  GALGAS_stringlist var_stringParametersPath_22393 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 682)) ;
  var_stringParametersPath_22393.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 683)) ;
  var_stringParametersPath_22393.addAssign_operation (GALGAS_string ("ECUC-STRING-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 684)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_stringParametersPath_22393, var_stringParameters_22353, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 685)) ;
  cEnumerator_arxmlElementValueList enumerator_22624 (var_stringParameters_22353, kENUMERATION_UP) ;
  while (enumerator_22624.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_22654 ;
    GALGAS_impType var_type_22672 ;
    {
    routine_arxmlImplementationContainerString (var_attributeName_22654, var_type_22672, GALGAS_dataType::constructor_string (SOURCE_FILE ("arxml_parser.galgas", 692)), enumerator_22624.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 690)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_22654, var_type_22672, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 695)) ;
    }
    enumerator_22624.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_booleanParameters_23221 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 701)) ;
  GALGAS_stringlist var_booleanParametersPath_23262 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 702)) ;
  var_booleanParametersPath_23262.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 703)) ;
  var_booleanParametersPath_23262.addAssign_operation (GALGAS_string ("ECUC-BOOLEAN-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 704)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_booleanParametersPath_23262, var_booleanParameters_23221, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 705)) ;
  cEnumerator_arxmlElementValueList enumerator_23499 (var_booleanParameters_23221, kENUMERATION_UP) ;
  while (enumerator_23499.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_23529 ;
    GALGAS_impType var_type_23547 ;
    {
    routine_arxmlImplementationContainerBoolean (var_attributeName_23529, var_type_23547, GALGAS_dataType::constructor_boolean (SOURCE_FILE ("arxml_parser.galgas", 712)), enumerator_23499.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 710)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_23529, var_type_23547, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 715)) ;
    }
    enumerator_23499.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_enumParameters_24096 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 721)) ;
  GALGAS_stringlist var_enumParametersPath_24134 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 722)) ;
  var_enumParametersPath_24134.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 723)) ;
  var_enumParametersPath_24134.addAssign_operation (GALGAS_string ("ECUC-ENUMERATION-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 724)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_enumParametersPath_24134, var_enumParameters_24096, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 725)) ;
  cEnumerator_arxmlElementValueList enumerator_24360 (var_enumParameters_24096, kENUMERATION_UP) ;
  while (enumerator_24360.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_24390 ;
    GALGAS_impType var_type_24408 ;
    {
    routine_arxmlImplementationContainerEnumeration (var_attributeName_24390, var_type_24408, GALGAS_dataType::constructor_enumeration (SOURCE_FILE ("arxml_parser.galgas", 732)), enumerator_24360.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 730)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_24390, var_type_24408, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 735)) ;
    }
    enumerator_24360.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_structParameters_24985 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 741)) ;
  GALGAS_stringlist var_structParametersPath_25025 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 742)) ;
  var_structParametersPath_25025.addAssign_operation (GALGAS_string ("SUB-CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 743)) ;
  var_structParametersPath_25025.addAssign_operation (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 744)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_structParametersPath_25025, var_structParameters_24985, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 745)) ;
  cEnumerator_arxmlElementValueList enumerator_25268 (var_structParameters_24985, kENUMERATION_UP) ;
  while (enumerator_25268.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_25298 ;
    GALGAS_impType var_type_25316 ;
    {
    routine_arxmlImplementationContainerStructure (var_attributeName_25298, var_type_25316, GALGAS_dataType::constructor_structType (SOURCE_FILE ("arxml_parser.galgas", 752)), enumerator_25268.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 750)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_25298, var_type_25316, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 755)) ;
    }
    enumerator_25268.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_identParameters_25885 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 761)) ;
  GALGAS_stringlist var_identParametersPath_25924 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 762)) ;
  var_identParametersPath_25924.addAssign_operation (GALGAS_string ("REFERENCES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 763)) ;
  var_identParametersPath_25924.addAssign_operation (GALGAS_string ("TPL-IDENTIFIER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 764)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_identParametersPath_25924, var_identParameters_25885, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 765)) ;
  cEnumerator_arxmlElementValueList enumerator_26147 (var_identParameters_25885, kENUMERATION_UP) ;
  while (enumerator_26147.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_26177 ;
    GALGAS_impType var_type_26195 ;
    {
    routine_arxmlImplementationContainerIdentifier (var_attributeName_26177, var_type_26195, GALGAS_dataType::constructor_identifier (SOURCE_FILE ("arxml_parser.galgas", 772)), enumerator_26147.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 770)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_26177, var_type_26195, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 775)) ;
    }
    enumerator_26147.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_refParameters_26766 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 781)) ;
  GALGAS_stringlist var_refParametersPath_26803 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 782)) ;
  var_refParametersPath_26803.addAssign_operation (GALGAS_string ("REFERENCES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 783)) ;
  var_refParametersPath_26803.addAssign_operation (GALGAS_string ("ECUC-REFERENCE-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 784)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_refParametersPath_26803, var_refParameters_26766, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 785)) ;
  cEnumerator_arxmlElementValueList enumerator_27016 (var_refParameters_26766, kENUMERATION_UP) ;
  while (enumerator_27016.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_27046 ;
    GALGAS_impType var_type_27064 ;
    {
    routine_arxmlImplementationContainerReference (var_attributeName_27046, var_type_27064, GALGAS_dataType::constructor_objectType (SOURCE_FILE ("arxml_parser.galgas", 792)), enumerator_27016.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 790)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_27046, var_type_27064, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 795)) ;
    }
    enumerator_27016.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Routine 'arxmlImplementationContainerNumber'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlImplementationContainerNumber (GALGAS_lstring & outArgument_objectName,
                                                 GALGAS_impType & outArgument_options,
                                                 const GALGAS_dataType constinArgument_iType,
                                                 GALGAS_arxmlElementValue inArgument_parameter,
                                                 GALGAS_lstring /* inArgument_parentPath */,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_dataType var_type_27689 = constinArgument_iType ;
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 811)) ;
  }
  GALGAS_lbool var_multiple_27843 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_27843, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 814)) ;
  }
  GALGAS_bool var_withAuto_27905 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_27905, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 817)) ;
  }
  GALGAS_lstring var_oil_5F_desc_27990 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_27990, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 820)) ;
  }
  GALGAS_attributeRange var_range_28140 ;
  GALGAS_bool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MIN"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 826)) ;
  if (kBoolTrue == test_0.boolEnum ()) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MAX"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 826)) ;
  }
  const enumGalgasBool test_1 = test_0.boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_lstring var_min_28230 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MIN"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 827)) ;
    GALGAS_lstring var_max_28287 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MAX"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 828)) ;
    GALGAS_string var_minSignString_28353 = GALGAS_string::makeEmptyString () ;
    GALGAS_string var_maxSignString_28384 = GALGAS_string::makeEmptyString () ;
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_max_28287.getter_string (SOURCE_FILE ("arxml_parser.galgas", 832)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 832)).objectCompare (GALGAS_string ("INF"))).boolEnum () ;
    if (kBoolTrue == test_2) {
      var_max_28287.mProperty_string = GALGAS_sint_36__34_::constructor_max (SOURCE_FILE ("arxml_parser.galgas", 833)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 833)) ;
    }
    GALGAS_bool var_minSign_28529 ;
    {
    routine_arxmlPopSign (var_min_28230, var_minSign_28529, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 836)) ;
    }
    GALGAS_bool var_maxSign_28568 ;
    {
    routine_arxmlPopSign (var_max_28287, var_maxSign_28568, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 837)) ;
    }
    const enumGalgasBool test_3 = var_minSign_28529.boolEnum () ;
    if (kBoolTrue == test_3) {
      var_minSignString_28353 = GALGAS_string ("-") ;
      var_type_27689 = GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 842)) ;
    }
    const enumGalgasBool test_4 = var_maxSign_28568.boolEnum () ;
    if (kBoolTrue == test_4) {
      var_maxSignString_28384 = GALGAS_string ("-") ;
      var_type_27689 = GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 846)) ;
    }
    {
    routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (var_type_27689, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 848)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 848)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 848)) ;
    }
    {
    routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 849)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 849)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 849)) ;
    }
    GALGAS_object_5F_t var_start_28911 ;
    GALGAS_object_5F_t var_stop_28930 ;
    GALGAS_bool test_5 = GALGAS_bool (kIsEqual, var_type_27689.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 854)))) ;
    if (kBoolTrue != test_5.boolEnum ()) {
      test_5 = GALGAS_bool (kIsEqual, var_type_27689.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 854)))) ;
    }
    const enumGalgasBool test_6 = test_5.boolEnum () ;
    if (kBoolTrue == test_6) {
      GALGAS_luint_36__34_ var_minVal_29030 = GALGAS_luint_36__34_::constructor_new (var_min_28230.getter_string (SOURCE_FILE ("arxml_parser.galgas", 856)).getter_decimalUnsigned_36__34_Number (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 856)), var_min_28230.getter_location (SOURCE_FILE ("arxml_parser.galgas", 857))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 855)) ;
      GALGAS_luint_36__34_ var_maxVal_29208 = GALGAS_luint_36__34_::constructor_new (var_max_28287.getter_string (SOURCE_FILE ("arxml_parser.galgas", 860)).getter_decimalUnsigned_36__34_Number (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 860)), var_max_28287.getter_location (SOURCE_FILE ("arxml_parser.galgas", 861))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 859)) ;
      {
      routine_displayOil (GALGAS_string ("[").add_operation (var_minSignString_28353, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 863)).add_operation (var_minVal_29030.mProperty_uint_36__34_.getter_string (SOURCE_FILE ("arxml_parser.galgas", 863)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 863)).add_operation (GALGAS_string (" .. "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 863)).add_operation (var_maxSignString_28384, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 864)).add_operation (var_maxVal_29208.mProperty_uint_36__34_.getter_string (SOURCE_FILE ("arxml_parser.galgas", 864)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 864)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 864)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 863)) ;
      }
      var_start_28911 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 865)), var_type_27689, var_minVal_29030, var_minSign_28529, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 865)) ;
      var_stop_28930 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 866)), var_type_27689, var_maxVal_29208, var_maxSign_28568, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 866)) ;
    }else if (kBoolFalse == test_6) {
      const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, var_type_27689.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 867)))).boolEnum () ;
      if (kBoolTrue == test_7) {
        GALGAS_ldouble var_minVal_29710 = GALGAS_ldouble::constructor_new (var_min_28230.getter_string (SOURCE_FILE ("arxml_parser.galgas", 869)).getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 869)), var_min_28230.getter_location (SOURCE_FILE ("arxml_parser.galgas", 870))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 868)) ;
        GALGAS_ldouble var_maxVal_29877 = GALGAS_ldouble::constructor_new (var_max_28287.getter_string (SOURCE_FILE ("arxml_parser.galgas", 873)).getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 873)), var_max_28287.getter_location (SOURCE_FILE ("arxml_parser.galgas", 874))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 872)) ;
        {
        routine_displayOil (GALGAS_string ("[").add_operation (var_minVal_29710.mProperty_double.getter_string (SOURCE_FILE ("arxml_parser.galgas", 876)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 876)).add_operation (GALGAS_string (" .. "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 876)).add_operation (var_maxVal_29877.mProperty_double.getter_string (SOURCE_FILE ("arxml_parser.galgas", 876)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 876)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 876)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 876)) ;
        }
        var_start_28911 = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 877)), var_type_27689, var_minVal_29710, var_minSign_28529, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 877)) ;
        var_stop_28930 = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 878)), var_type_27689, var_maxVal_29877, var_maxSign_28568, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 878)) ;
      }else if (kBoolFalse == test_7) {
        TC_Array <C_FixItDescription> fixItArray8 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 880)), GALGAS_string ("Internal error"), fixItArray8  COMMA_SOURCE_FILE ("arxml_parser.galgas", 880)) ;
        var_start_28911.drop () ; // Release error dropped variable
        var_stop_28930.drop () ; // Release error dropped variable
      }
    }
    var_range_28140 = function_buildRange (var_type_27689, var_start_28911, var_stop_28930, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 882)) ;
  }else if (kBoolFalse == test_1) {
    {
    routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (var_type_27689, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 884)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 884)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 884)) ;
    }
    {
    routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 885)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 885)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 885)) ;
    }
    var_range_28140 = GALGAS_noRange::constructor_new (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 886))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 886)) ;
  }
  GALGAS_object_5F_t var_defaultValue_30550 ;
  const enumGalgasBool test_9 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 891)).boolEnum () ;
  if (kBoolTrue == test_9) {
    GALGAS_lstring var_value_30619 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 892)) ;
    GALGAS_bool var_sign_30736 ;
    {
    routine_arxmlPopSign (var_value_30619, var_sign_30736, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 895)) ;
    }
    GALGAS_bool test_10 = GALGAS_bool (kIsEqual, var_type_27689.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 898)))) ;
    if (kBoolTrue != test_10.boolEnum ()) {
      test_10 = GALGAS_bool (kIsEqual, var_type_27689.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 898)))) ;
    }
    const enumGalgasBool test_11 = test_10.boolEnum () ;
    if (kBoolTrue == test_11) {
      GALGAS_luint_36__34_ var_integerValue_30914 = GALGAS_luint_36__34_::constructor_new (var_value_30619.getter_string (SOURCE_FILE ("arxml_parser.galgas", 900)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 900)).getter_uint_36__34_ (SOURCE_FILE ("arxml_parser.galgas", 900)), var_value_30619.getter_location (SOURCE_FILE ("arxml_parser.galgas", 901))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 899)) ;
      {
      routine_displayOil (GALGAS_string (" = ").add_operation (var_integerValue_30914.mProperty_uint_36__34_.getter_string (SOURCE_FILE ("arxml_parser.galgas", 902)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 902)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 902)) ;
      }
      var_defaultValue_30550 = function_checkAndGetIntegerNumber (var_oil_5F_desc_27990, var_type_27689, var_integerValue_30914, var_sign_30736, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 903)) ;
    }else if (kBoolFalse == test_11) {
      const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, var_type_27689.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 907)))).boolEnum () ;
      if (kBoolTrue == test_12) {
        GALGAS_ldouble var_floatValue_31389 = GALGAS_ldouble::constructor_new (var_value_30619.getter_string (SOURCE_FILE ("arxml_parser.galgas", 909)).getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 909)), var_value_30619.getter_location (SOURCE_FILE ("arxml_parser.galgas", 910))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 908)) ;
        {
        routine_displayOil (GALGAS_string (" = ").add_operation (var_floatValue_31389.mProperty_double.getter_string (SOURCE_FILE ("arxml_parser.galgas", 911)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 911)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 911)) ;
        }
        var_defaultValue_30550 = function_checkAndGetFloatNumber (var_oil_5F_desc_27990, var_type_27689, var_floatValue_31389, var_sign_30736, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 912)) ;
      }else if (kBoolFalse == test_12) {
        TC_Array <C_FixItDescription> fixItArray13 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 917)), GALGAS_string ("Internal error"), fixItArray13  COMMA_SOURCE_FILE ("arxml_parser.galgas", 917)) ;
        var_defaultValue_30550.drop () ; // Release error dropped variable
      }
    }
  }else if (kBoolFalse == test_9) {
    const enumGalgasBool test_14 = var_withAuto_27905.boolEnum () ;
    if (kBoolTrue == test_14) {
      var_defaultValue_30550 = GALGAS_auto::constructor_new (var_oil_5F_desc_27990, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 920))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 920)) ;
    }else if (kBoolFalse == test_14) {
      var_defaultValue_30550 = GALGAS_void::constructor_new (var_oil_5F_desc_27990, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 922))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 922)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_27990.getter_string (SOURCE_FILE ("arxml_parser.galgas", 924)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 924)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 924)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 924)) ;
  }
  GALGAS_locationList temp_15 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 927)) ;
  temp_15.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 927))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 927)) ;
  GALGAS_lstringlist temp_16 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 931)) ;
  temp_16.addAssign_operation (var_oil_5F_desc_27990  COMMA_SOURCE_FILE ("arxml_parser.galgas", 931)) ;
  outArgument_options = GALGAS_impRangedType::constructor_new (temp_15, var_type_27689, outArgument_objectName, var_multiple_27843.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 930)), temp_16, var_withAuto_27905, var_defaultValue_30550, var_range_28140  COMMA_SOURCE_FILE ("arxml_parser.galgas", 927)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Routine 'arxmlImplementationContainerString'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlImplementationContainerString (GALGAS_lstring & outArgument_objectName,
                                                 GALGAS_impType & outArgument_options,
                                                 const GALGAS_dataType constinArgument_type,
                                                 GALGAS_arxmlElementValue inArgument_parameter,
                                                 GALGAS_lstring /* inArgument_parentPath */,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 944)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 944)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 944)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 947)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 948)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 948)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 948)) ;
  }
  GALGAS_lbool var_multiple_32814 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_32814, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 951)) ;
  }
  GALGAS_bool var_withAuto_32876 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_32876, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 954)) ;
  }
  GALGAS_lstring var_oil_5F_desc_32961 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_32961, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 957)) ;
  }
  GALGAS_object_5F_t var_defaultValue_33007 ;
  const enumGalgasBool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 962)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_value_33076 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 963)) ;
    {
    routine_displayOil (GALGAS_string (" = \"").add_operation (var_value_33076.getter_string (SOURCE_FILE ("arxml_parser.galgas", 964)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 964)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 964)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 964)) ;
    }
    var_defaultValue_33007 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_32961, var_value_33076.getter_location (SOURCE_FILE ("arxml_parser.galgas", 967)), var_value_33076.getter_string (SOURCE_FILE ("arxml_parser.galgas", 968))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 965)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = var_withAuto_32876.boolEnum () ;
    if (kBoolTrue == test_1) {
      var_defaultValue_33007 = GALGAS_auto::constructor_new (var_oil_5F_desc_32961, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 971))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 971)) ;
    }else if (kBoolFalse == test_1) {
      var_defaultValue_33007 = GALGAS_void::constructor_new (var_oil_5F_desc_32961, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 973))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 973)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_32961.getter_string (SOURCE_FILE ("arxml_parser.galgas", 975)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 975)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 975)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 975)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 979)) ;
  temp_2.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 979))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 979)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 983)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_32961  COMMA_SOURCE_FILE ("arxml_parser.galgas", 983)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_32814.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 982)), temp_3, var_withAuto_32876, var_defaultValue_33007  COMMA_SOURCE_FILE ("arxml_parser.galgas", 978)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Routine 'arxmlImplementationContainerBoolean'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlImplementationContainerBoolean (GALGAS_lstring & outArgument_objectName,
                                                  GALGAS_impType & outArgument_options,
                                                  const GALGAS_dataType constinArgument_type,
                                                  GALGAS_arxmlElementValue inArgument_parameter,
                                                  GALGAS_lstring inArgument_parentPath,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 996)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 996)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 996)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 999)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1000)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1000)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1000)) ;
  }
  GALGAS_bool var_withAuto_34430 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_34430, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1003)) ;
  }
  GALGAS_lbool var_multiple_34520 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_34520, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1006)) ;
  }
  GALGAS_lstring var_oil_5F_desc_34605 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_34605, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1009)) ;
  }
  GALGAS_object_5F_t var_defaultValue_34650 ;
  const enumGalgasBool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1013)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_value_34719 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1014)) ;
    GALGAS_bool var_booleanValue_34792 ;
    GALGAS_bool test_1 = GALGAS_bool (kIsEqual, var_value_34719.mProperty_string.getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1016)).objectCompare (GALGAS_string ("TRUE"))) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      test_1 = GALGAS_bool (kIsEqual, var_value_34719.mProperty_string.objectCompare (GALGAS_string ("1"))) ;
    }
    const enumGalgasBool test_2 = test_1.boolEnum () ;
    if (kBoolTrue == test_2) {
      var_booleanValue_34792 = GALGAS_bool (true) ;
    }else if (kBoolFalse == test_2) {
      GALGAS_bool test_3 = GALGAS_bool (kIsEqual, var_value_34719.mProperty_string.getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1019)).objectCompare (GALGAS_string ("FALSE"))) ;
      if (kBoolTrue != test_3.boolEnum ()) {
        test_3 = GALGAS_bool (kIsEqual, var_value_34719.mProperty_string.objectCompare (GALGAS_string ("0"))) ;
      }
      const enumGalgasBool test_4 = test_3.boolEnum () ;
      if (kBoolTrue == test_4) {
        var_booleanValue_34792 = GALGAS_bool (false) ;
      }else if (kBoolFalse == test_4) {
        var_booleanValue_34792 = GALGAS_bool (false) ;
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (var_value_34719.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1024)), GALGAS_string ("A Boolean must be 'true', 'false', '0' or '1'"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1024)) ;
      }
    }
    {
    routine_displayOil (GALGAS_string (" = ").add_operation (var_booleanValue_34792.getter_cString (SOURCE_FILE ("arxml_parser.galgas", 1026)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1026)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1026)) ;
    }
    var_defaultValue_34650 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_34605, var_value_34719.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1029)), var_booleanValue_34792, GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1033))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1031))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1027)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_6 = var_withAuto_34430.boolEnum () ;
    if (kBoolTrue == test_6) {
      var_defaultValue_34650 = GALGAS_auto::constructor_new (var_oil_5F_desc_34605, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1037))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1037)) ;
    }else if (kBoolFalse == test_6) {
      var_defaultValue_34650 = GALGAS_void::constructor_new (var_oil_5F_desc_34605, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1039))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1039)) ;
    }
  }
  GALGAS_implementationObjectMap var_structAttributes_35912 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1045)) ;
  const enumGalgasBool test_7 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SUB-CONTAINERS"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1046)).boolEnum () ;
  if (kBoolTrue == test_7) {
    {
    routine_displayOil (GALGAS_string ("\n"
      "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1047)) ;
    }
    {
    routine_arxmlImplementationContainer (var_structAttributes_35912, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1048)) ;
    }
    {
    routine_displayOil (GALGAS_string ("\n"
      "    } : \"").add_operation (var_oil_5F_desc_34605.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1049)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1049)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1049)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1049)) ;
    }
  }else if (kBoolFalse == test_7) {
    {
    routine_displayOil (GALGAS_string (" : \"").add_operation (var_oil_5F_desc_34605.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1051)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1051)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1051)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1051)) ;
    }
  }
  GALGAS_locationList temp_8 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1056)) ;
  temp_8.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1056))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1056)) ;
  GALGAS_lstringlist temp_9 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1060)) ;
  temp_9.addAssign_operation (var_oil_5F_desc_34605  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1060)) ;
  outArgument_options = GALGAS_impBoolType::constructor_new (temp_8, constinArgument_type, outArgument_objectName, var_multiple_34520.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1059)), temp_9, var_withAuto_34430, var_defaultValue_34650, var_structAttributes_35912, var_structAttributes_35912  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1055)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Routine 'arxmlImplementationContainerEnumeration'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlImplementationContainerEnumeration (GALGAS_lstring & outArgument_objectName,
                                                      GALGAS_impType & outArgument_options,
                                                      const GALGAS_dataType constinArgument_type,
                                                      GALGAS_arxmlElementValue inArgument_parameter,
                                                      GALGAS_lstring /* inArgument_parentPath */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1075)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1075)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1075)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1078)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1079)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1079)).add_operation (GALGAS_string ("["), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1079)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1079)) ;
  }
  GALGAS_bool var_withAuto_37069 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_37069, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1082)) ;
  }
  GALGAS_lbool var_multiple_37159 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_37159, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1085)) ;
  }
  GALGAS_lstring var_oil_5F_desc_37244 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_37244, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1088)) ;
  }
  GALGAS_enumValues var_enumValues_37336 = GALGAS_enumValues::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1092)) ;
  GALGAS_arxmlElementValueList var_enumElementValues_37404 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1093)) ;
  GALGAS_stringlist var_enumElementValuesPath_37445 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1094)) ;
  var_enumElementValuesPath_37445.addAssign_operation (GALGAS_string ("LITERALS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1095)) ;
  var_enumElementValuesPath_37445.addAssign_operation (GALGAS_string ("ECUC-ENUMERATION-LITERAL-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1096)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), var_enumElementValuesPath_37445, var_enumElementValues_37404, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1097)) ;
  cEnumerator_arxmlElementValueList enumerator_37681 (var_enumElementValues_37404, kENUMERATION_UP) ;
  while (enumerator_37681.hasCurrentObject ()) {
    GALGAS_lstring var_enumValueName_37711 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) enumerator_37681.current_value (HERE).ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1099)) ;
    {
    var_enumValues_37336.setter_put (var_enumValueName_37711, GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1100)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1100)) ;
    }
    {
    routine_displayOil (var_enumValueName_37711.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1101)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1101)) ;
    }
    if (enumerator_37681.hasNextObject ()) {
      {
      routine_displayOil (GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1103)) ;
      }
    }
    enumerator_37681.gotoNextObject () ;
  }
  {
  routine_displayOil (GALGAS_string ("]"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1105)) ;
  }
  GALGAS_object_5F_t var_defaultValue_37974 ;
  const enumGalgasBool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1109)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_value_38043 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1110)) ;
    {
    routine_displayOil (GALGAS_string (" = ").add_operation (var_value_38043.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1111)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1111)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1111)) ;
    }
    var_defaultValue_37974 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_37244, var_value_38043.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1114)), var_value_38043.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1115)), GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1118))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1116))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1112)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = var_withAuto_37069.boolEnum () ;
    if (kBoolTrue == test_1) {
      var_defaultValue_37974 = GALGAS_auto::constructor_new (var_oil_5F_desc_37244, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1122))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1122)) ;
    }else if (kBoolFalse == test_1) {
      var_defaultValue_37974 = GALGAS_void::constructor_new (var_oil_5F_desc_37244, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1124))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1124)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    " : \"").add_operation (var_oil_5F_desc_37244.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1127)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1127)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1127)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1127)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1131)) ;
  temp_2.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1131))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1131)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1135)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_37244  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1135)) ;
  outArgument_options = GALGAS_impEnumType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_37159.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1134)), temp_3, var_withAuto_37069, var_defaultValue_37974, var_enumValues_37336  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1130)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Routine 'arxmlImplementationContainerStructure'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlImplementationContainerStructure (GALGAS_lstring & outArgument_objectName,
                                                    GALGAS_impType & outArgument_options,
                                                    const GALGAS_dataType constinArgument_type,
                                                    GALGAS_arxmlElementValue inArgument_parameter,
                                                    GALGAS_lstring inArgument_parentPath,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1150)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1150)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1150)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1153)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1154)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1154)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1154)) ;
  }
  GALGAS_lbool var_multiple_39596 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_39596, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1157)) ;
  }
  GALGAS_lstring var_oil_5F_desc_39681 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_39681, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1160)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1162)) ;
  }
  GALGAS_implementationObjectMap var_structAttributes_39756 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1165)) ;
  {
  routine_arxmlImplementationContainer (var_structAttributes_39756, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1166)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    "    } : \"").add_operation (var_oil_5F_desc_39681.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1168)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1168)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1168)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1168)) ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1172)) ;
  temp_0.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1172))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1172)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1176)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_39681  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1176)) ;
  outArgument_options = GALGAS_impStructType::constructor_new (temp_0, constinArgument_type, outArgument_objectName, var_multiple_39596.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1175)), temp_1, var_structAttributes_39756  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1171)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Routine 'arxmlImplementationContainerIdentifier'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlImplementationContainerIdentifier (GALGAS_lstring & outArgument_objectName,
                                                     GALGAS_impType & outArgument_options,
                                                     const GALGAS_dataType constinArgument_type,
                                                     GALGAS_arxmlElementValue inArgument_parameter,
                                                     GALGAS_lstring /* inArgument_parentPath */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1188)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1188)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1188)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1191)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1192)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1192)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1192)) ;
  }
  GALGAS_lbool var_multiple_40679 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_40679, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1195)) ;
  }
  GALGAS_bool var_withAuto_40741 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_40741, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1198)) ;
  }
  GALGAS_lstring var_oil_5F_desc_40826 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_40826, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1201)) ;
  }
  GALGAS_object_5F_t var_defaultValue_40871 ;
  const enumGalgasBool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1205)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_value_40940 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1206)) ;
    {
    routine_displayOil (GALGAS_string (" = ").add_operation (var_value_40940.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1207)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1207)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1207)) ;
    }
    var_defaultValue_40871 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_40826, var_value_40940.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1210)), var_value_40940.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1211))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1208)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = var_withAuto_40741.boolEnum () ;
    if (kBoolTrue == test_1) {
      var_defaultValue_40871 = GALGAS_auto::constructor_new (var_oil_5F_desc_40826, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1214))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1214)) ;
    }else if (kBoolFalse == test_1) {
      var_defaultValue_40871 = GALGAS_void::constructor_new (var_oil_5F_desc_40826, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1216))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1216)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_40826.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1218)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1218)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1218)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1218)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1222)) ;
  temp_2.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1222))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1222)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1226)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_40826  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1226)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_40679.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1225)), temp_3, var_withAuto_40741, var_defaultValue_40871  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1221)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Routine 'arxmlImplementationContainerReference'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlImplementationContainerReference (GALGAS_lstring & outArgument_objectName,
                                                    GALGAS_impType & outArgument_options,
                                                    const GALGAS_dataType constinArgument_type,
                                                    GALGAS_arxmlElementValue inArgument_parameter,
                                                    GALGAS_lstring /* inArgument_parentPath */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_lstring var_objectType_42134 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DESTINATION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1240)) ;
  var_objectType_42134.mProperty_string = var_objectType_42134.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1242)).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1242)) ;
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (var_objectType_42134.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1243)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1243)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1243)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1246)) ;
  }
  {
  routine_displayOil (GALGAS_string (" ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1247)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1247)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1247)) ;
  }
  GALGAS_lbool var_multiple_42552 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_42552, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1250)) ;
  }
  GALGAS_lstring var_oil_5F_desc_42637 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_42637, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1253)) ;
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_42637.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1255)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1255)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1255)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1255)) ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1259)) ;
  temp_0.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1259))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1259)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1263)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_42637  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1263)) ;
  outArgument_options = GALGAS_refType::constructor_new (temp_0, constinArgument_type, outArgument_objectName, var_multiple_42552.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1262)), temp_1, var_objectType_42134  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1258)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'arxmlDefinitionPackage'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlDefinitionPackage (GALGAS_implementation & ioArgument_imp,
                                     GALGAS_applicationDefinition & ioArgument_application,
                                     GALGAS_arxmlElementValue inArgument_packageElement,
                                     GALGAS_lstring inArgument_parentPath,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_packageName_43289 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1279)) ;
  GALGAS_lstring var_currentPath_43398 = GALGAS_lstring::constructor_new (inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1282)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1282)).add_operation (var_packageName_43289.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1282)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1282)), var_packageName_43289.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1283))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1282)) ;
  GALGAS_arxmlElementValueList var_definitions_43621 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1286)) ;
  GALGAS_stringlist var_definitionPath_43655 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1287)) ;
  var_definitionPath_43655.addAssign_operation (GALGAS_string ("ELEMENTS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1288)) ;
  var_definitionPath_43655.addAssign_operation (GALGAS_string ("ECUC-MODULE-CONFIGURATION-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1289)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_definitionPath_43655, var_definitions_43621, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1290)) ;
  cEnumerator_arxmlElementValueList enumerator_43867 (var_definitions_43621, kENUMERATION_UP) ;
  while (enumerator_43867.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionRoot (ioArgument_imp, ioArgument_application, enumerator_43867.current_value (HERE), var_currentPath_43398, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1292)) ;
    }
    enumerator_43867.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_packages_44035 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1296)) ;
  GALGAS_stringlist var_packagesPath_44067 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1297)) ;
  var_packagesPath_44067.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1298)) ;
  var_packagesPath_44067.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1299)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_packagesPath_44067, var_packages_44035, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1300)) ;
  cEnumerator_arxmlElementValueList enumerator_44245 (var_packages_44035, kENUMERATION_UP) ;
  while (enumerator_44245.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionPackage (ioArgument_imp, ioArgument_application, enumerator_44245.current_value (HERE), var_currentPath_43398, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1302)) ;
    }
    enumerator_44245.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'arxmlDefinitionRoot'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlDefinitionRoot (GALGAS_implementation & ioArgument_imp,
                                  GALGAS_applicationDefinition & ioArgument_application,
                                  GALGAS_arxmlElementValue inArgument_packageElement,
                                  GALGAS_lstring /* inArgument_parentPath */,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_cpuName_44520 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1313)) ;
  GALGAS_lstring var_currentPath_44630 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1316)) ;
  GALGAS_objectsMap var_objects_44745 = ioArgument_application.getter_objects (SOURCE_FILE ("arxml_parser.galgas", 1319)) ;
  GALGAS_lstring var_oil_5F_desc_44858 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_44858, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1322)) ;
  }
  GALGAS_arxmlElementValueList var_subDefs_44920 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1325)) ;
  GALGAS_stringlist var_subDefsPath_44951 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1326)) ;
  var_subDefsPath_44951.addAssign_operation (GALGAS_string ("CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1327)) ;
  var_subDefsPath_44951.addAssign_operation (GALGAS_string ("ECUC-CONTAINER-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1328)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_subDefsPath_44951, var_subDefs_44920, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1329)) ;
  {
  routine_displayOil (GALGAS_string ("\n"
    "CPU ").add_operation (var_cpuName_44520.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1331)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1331)).add_operation (GALGAS_string ("\n"
    "{\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1331)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1331)) ;
  }
  cEnumerator_arxmlElementValueList enumerator_45185 (var_subDefs_44920, kENUMERATION_UP) ;
  while (enumerator_45185.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionObject (ioArgument_imp, var_objects_44745, enumerator_45185.current_value (HERE), var_currentPath_44630, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1334)) ;
    }
    enumerator_45185.gotoNextObject () ;
  }
  {
  ioArgument_application.setter_setName (var_cpuName_44520 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1338)) ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_44745 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1339)) ;
  }
  {
  routine_displayOil (GALGAS_string ("}; /* END CPU ").add_operation (var_cpuName_44520.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1341)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1341)).add_operation (GALGAS_string (" : \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1341)).add_operation (var_oil_5F_desc_44858.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1342)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1342)).add_operation (GALGAS_string ("\" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1342)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1341)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'arxmlDefinitionObject'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlDefinitionObject (GALGAS_implementation & ioArgument_imp,
                                    GALGAS_objectsMap & ioArgument_objects,
                                    GALGAS_arxmlElementValue inArgument_currentElement,
                                    GALGAS_lstring inArgument_parentPath,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_currentPath_45657 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1352)) ;
  GALGAS_lstring var_objectKind_45779 ;
  {
  routine_oilEquivalentName (inArgument_parentPath, var_currentPath_45657, var_objectKind_45779, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1353)) ;
  }
  GALGAS_implementationObject var_impObjOfKind_45840 = callExtensionGetter_impObject ((const cPtr_implementation *) ioArgument_imp.ptr (), var_objectKind_45779.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1356)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1356)) ;
  GALGAS_objectKind var_objectsForKind_45908 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1357))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1357)) ;
  const enumGalgasBool test_0 = ioArgument_objects.getter_hasKey (var_objectKind_45779.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1358)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1358)).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    ioArgument_objects.setter_del (var_objectKind_45779, var_objectsForKind_45908, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1359)) ;
    }
  }
  GALGAS_lstring var_objectName_46101 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1363)) ;
  GALGAS_objectAttributes var_object_46213 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1366)) ;
  GALGAS_objectKindMap var_objectsKind_46258 = var_objectsForKind_45908.getter_objects (SOURCE_FILE ("arxml_parser.galgas", 1367)) ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_impObjOfKind_45840.getter_multiple (SOURCE_FILE ("arxml_parser.galgas", 1368)).getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1368)).objectCompare (GALGAS_bool (false))).boolEnum () ;
  if (kBoolTrue == test_1) {
    var_objectName_46101 = var_objectKind_45779 ;
  }
  const enumGalgasBool test_2 = var_objectsKind_46258.getter_hasKey (var_objectName_46101.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1376)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1376)).boolEnum () ;
  if (kBoolTrue == test_2) {
    {
    var_objectsKind_46258.setter_del (var_objectName_46101, var_object_46213, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1377)) ;
    }
  }
  GALGAS_lstring var_oil_5F_desc_46820 ;
  {
  routine_arxmlGetDescription (inArgument_currentElement, var_oil_5F_desc_46820, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1381)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (var_objectKind_45779.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1383)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)).add_operation (var_objectName_46101.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1383)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)).add_operation (GALGAS_string ("\n"
    "  {\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)) ;
  }
  {
  routine_arxmlDefinitionContainer (var_impObjOfKind_45840.getter_attributes (SOURCE_FILE ("arxml_parser.galgas", 1386)), var_object_46213, inArgument_currentElement, var_currentPath_45657, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1386)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  } : \"").add_operation (var_oil_5F_desc_46820.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1391)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)) ;
  }
  GALGAS_identifierMap var_attributes_47215 = var_object_46213.getter_objectParams (SOURCE_FILE ("arxml_parser.galgas", 1394)) ;
  const enumGalgasBool test_3 = var_attributes_47215.getter_hasKey (GALGAS_string ("NAME") COMMA_SOURCE_FILE ("arxml_parser.galgas", 1395)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 1395)).boolEnum () ;
  if (kBoolTrue == test_3) {
    {
    var_attributes_47215.setter_put (GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), var_objectName_46101.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1396))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1396)), GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_46820, var_objectName_46101.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1398)), var_objectName_46101.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1399))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1397)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1396)) ;
    }
    {
    var_object_46213.setter_setObjectParams (var_attributes_47215 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1400)) ;
    }
  }
  {
  var_objectsKind_46258.setter_put (var_objectName_46101, var_object_46213, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1402)) ;
  }
  {
  var_objectsForKind_45908.setter_setObjects (var_objectsKind_46258 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1403)) ;
  }
  {
  ioArgument_objects.setter_put (var_objectKind_45779, var_objectsForKind_45908, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1404)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Routine 'arxmlDefinitionContainer'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlDefinitionContainer (const GALGAS_implementationObjectMap constinArgument_types,
                                       GALGAS_objectAttributes & ioArgument_identifiers,
                                       GALGAS_arxmlElementValue inArgument_currentElement,
                                       GALGAS_lstring inArgument_currentPath,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList var_textParameters_48011 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1414)) ;
  GALGAS_stringlist var_textParametersPath_48049 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1415)) ;
  var_textParametersPath_48049.addAssign_operation (GALGAS_string ("PARAMETER-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1416)) ;
  var_textParametersPath_48049.addAssign_operation (GALGAS_string ("ECUC-TEXTUAL-PARAM-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1417)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_textParametersPath_48049, var_textParameters_48011, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1418)) ;
  GALGAS_arxmlElementValueList var_numParameters_48329 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1421)) ;
  GALGAS_stringlist var_numParametersPath_48366 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1422)) ;
  var_numParametersPath_48366.addAssign_operation (GALGAS_string ("PARAMETER-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1423)) ;
  var_numParametersPath_48366.addAssign_operation (GALGAS_string ("ECUC-NUMERICAL-PARAM-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1424)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_numParametersPath_48366, var_numParameters_48329, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1425)) ;
  GALGAS_arxmlElementValueList var_refParameters_48615 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1428)) ;
  GALGAS_stringlist var_refParametersPath_48652 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1429)) ;
  var_refParametersPath_48652.addAssign_operation (GALGAS_string ("REFERENCE-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1430)) ;
  var_refParametersPath_48652.addAssign_operation (GALGAS_string ("ECUC-REFERENCE-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1431)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_refParametersPath_48652, var_refParameters_48615, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1432)) ;
  GALGAS_arxmlElementValueList var_structParameters_48898 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1435)) ;
  GALGAS_stringlist var_structParametersPath_48938 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1436)) ;
  var_structParametersPath_48938.addAssign_operation (GALGAS_string ("SUB-CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1437)) ;
  var_structParametersPath_48938.addAssign_operation (GALGAS_string ("ECUC-CONTAINER-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1438)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_structParametersPath_48938, var_structParameters_48898, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1439)) ;
  GALGAS_arxmlElementValueList var_allParameters_49181 = var_numParameters_48329.add_operation (var_textParameters_48011, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1442)).add_operation (var_refParameters_48615, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1443)).add_operation (var_structParameters_48898, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1444)) ;
  cEnumerator_arxmlElementValueList enumerator_49447 (var_allParameters_49181, kENUMERATION_UP) ;
  while (enumerator_49447.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionParameter (constinArgument_types, ioArgument_identifiers, enumerator_49447.current_value (HERE), inArgument_currentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1449)) ;
    }
    enumerator_49447.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Routine 'arxmlDefinitionParameter'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlDefinitionParameter (const GALGAS_implementationObjectMap constinArgument_types,
                                       GALGAS_objectAttributes & ioArgument_identifiers,
                                       GALGAS_arxmlElementValue inArgument_parameter,
                                       GALGAS_lstring inArgument_parentPath,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t var_val_49732 ;
  GALGAS_lstring var_parameterPath_49757 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1461)) ;
  GALGAS_lstring var_parameterType_49879 ;
  {
  routine_oilEquivalentName (inArgument_parentPath, var_parameterPath_49757, var_parameterType_49879, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1462)) ;
  }
  GALGAS_bool var_typeOk_49920 = GALGAS_bool (false) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1466)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1466))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1466)) ;
  GALGAS_impType var_type_49944 = GALGAS_impVoid::constructor_new (temp_0, GALGAS_dataType::constructor_void (SOURCE_FILE ("arxml_parser.galgas", 1468)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1468)), GALGAS_bool (false), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1470))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1466)) ;
  GALGAS_lstring var_valueType_50216 = callExtensionGetter_getAttributeValueFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFINITION-REF"), GALGAS_string ("DEST"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1472)) ;
  GALGAS_lstring var_oil_5F_desc_50397 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1477))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1477)) ;
  GALGAS_bool var_isAuto_50553 = GALGAS_bool (false) ;
  GALGAS_lstring var_parameterValue_50587 ;
  const enumGalgasBool test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1484)).boolEnum () ;
  if (kBoolTrue == test_1) {
    var_parameterValue_50587 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1488)) ;
  }else if (kBoolFalse == test_1) {
    const enumGalgasBool test_2 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1489)).boolEnum () ;
    if (kBoolTrue == test_2) {
      var_parameterValue_50587 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1493)) ;
      var_parameterValue_50587.mProperty_string = var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1495)).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1495)) ;
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1497)).getter_rightSubString (GALGAS_uint ((uint32_t) 3U) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1497)).objectCompare (GALGAS_string ("REF"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        var_parameterType_49879.mProperty_string = var_parameterType_49879.mProperty_string.getter_leftSubString (var_parameterType_49879.mProperty_string.getter_length (SOURCE_FILE ("arxml_parser.galgas", 1499)).substract_operation (GALGAS_uint ((uint32_t) 3U), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1499)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1498)) ;
      }else if (kBoolFalse == test_3) {
        const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1500)).getter_rightSubString (GALGAS_uint ((uint32_t) 4U) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1500)).objectCompare (GALGAS_string ("REFS"))).boolEnum () ;
        if (kBoolTrue == test_4) {
          var_parameterType_49879.mProperty_string = var_parameterType_49879.mProperty_string.getter_leftSubString (var_parameterType_49879.mProperty_string.getter_length (SOURCE_FILE ("arxml_parser.galgas", 1502)).substract_operation (GALGAS_uint ((uint32_t) 4U), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1502)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1501)) ;
        }else if (kBoolFalse == test_4) {
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (var_parameterType_49879.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1504)), GALGAS_string ("An object reference must end with REF or REFS"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1504)) ;
        }
      }
    }else if (kBoolFalse == test_2) {
      GALGAS_bool test_6 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("PARAMETER-VALUES"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1506)) ;
      if (kBoolTrue != test_6.boolEnum ()) {
        test_6 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("REFERENCE-VALUES"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1507)) ;
      }
      const enumGalgasBool test_7 = test_6.boolEnum () ;
      if (kBoolTrue == test_7) {
        var_parameterValue_50587 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1511)) ;
      }else if (kBoolFalse == test_7) {
        const enumGalgasBool test_8 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("IS-AUTO-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1512)).boolEnum () ;
        if (kBoolTrue == test_8) {
          var_parameterValue_50587 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("IS-AUTO-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1516)) ;
          GALGAS_bool test_9 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1517)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1517)).objectCompare (GALGAS_string ("TRUE"))) ;
          if (kBoolTrue != test_9.boolEnum ()) {
            test_9 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1518)).objectCompare (GALGAS_string ("1"))) ;
          }
          const enumGalgasBool test_10 = test_9.boolEnum () ;
          if (kBoolTrue == test_10) {
            var_isAuto_50553 = GALGAS_bool (true) ;
          }
        }else if (kBoolFalse == test_8) {
          TC_Array <C_FixItDescription> fixItArray11 ;
          inCompiler->emitSemanticError (var_parameterType_49879.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1522)), GALGAS_string ("No value has been found."), fixItArray11  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1522)) ;
          var_parameterValue_50587.drop () ; // Release error dropped variable
        }
      }
    }
  }
  const enumGalgasBool test_12 = constinArgument_types.getter_hasKey (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1526)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1526)).boolEnum () ;
  if (kBoolTrue == test_12) {
    constinArgument_types.method_get (var_parameterType_49879, var_type_49944, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1527)) ;
    var_typeOk_49920 = GALGAS_bool (true) ;
    {
    routine_testTypeError (var_type_49944.getter_type (SOURCE_FILE ("arxml_parser.galgas", 1530)), var_valueType_50216, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1530)) ;
    }
  }else if (kBoolFalse == test_12) {
    TC_Array <C_FixItDescription> fixItArray13 ;
    inCompiler->emitSemanticError (var_parameterType_49879.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1532)), var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1532)).add_operation (GALGAS_string (" is not declared in the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1532)).add_operation (GALGAS_string ("IMPLEMENTATION."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1532)), fixItArray13  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1532)) ;
  }
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1536)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1536)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1536)) ;
  }
  GALGAS_implementationObjectMap var_subTypes_53173 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1538)) ;
  GALGAS_objectAttributes var_subAttributes_53246 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1539)) ;
  const enumGalgasBool test_14 = var_isAuto_50553.boolEnum () ;
  if (kBoolTrue == test_14) {
    {
    routine_displayOil (GALGAS_string (" = AUTO;"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1548)) ;
    }
    const enumGalgasBool test_15 = callExtensionGetter_autoAllowed ((const cPtr_impType *) var_type_49944.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1549)).boolEnum () ;
    if (kBoolTrue == test_15) {
      var_val_49732 = GALGAS_auto::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1550))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1550)) ;
    }else if (kBoolFalse == test_15) {
      TC_Array <C_FixItDescription> fixItArray16 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1552)), GALGAS_string ("AUTO is not allowed"), fixItArray16  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1552)) ;
      var_val_49732.drop () ; // Release error dropped variable
    }
  }else if (kBoolFalse == test_14) {
    const enumGalgasBool test_17 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1555)).objectCompare (GALGAS_string ("ECUC-ENUMERATION-PARAM-DEF"))).boolEnum () ;
    if (kBoolTrue == test_17) {
      GALGAS_impEnumType temp_18 ;
      if (var_type_49944.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_impEnumType *> (var_type_49944.ptr ())) {
          temp_18 = (cPtr_impEnumType *) var_type_49944.ptr () ;
        }else{
          inCompiler->castError ("impEnumType", var_type_49944.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1559)) ;
        }
      }
      GALGAS_impEnumType var_enumType_54049 = temp_18 ;
      const enumGalgasBool test_19 = var_enumType_54049.getter_valuesMap (SOURCE_FILE ("arxml_parser.galgas", 1560)).getter_hasKey (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1560)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1560)).boolEnum () ;
      if (kBoolTrue == test_19) {
        var_enumType_54049.getter_valuesMap (SOURCE_FILE ("arxml_parser.galgas", 1561)).method_get (var_parameterValue_50587, var_subTypes_53173, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1561)) ;
      }else if (kBoolFalse == test_19) {
        TC_Array <C_FixItDescription> fixItArray20 ;
        inCompiler->emitSemanticError (var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1563)), var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1563)).add_operation (GALGAS_string (" ENUM value "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)).add_operation (GALGAS_string ("for "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)).add_operation (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1564)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1564)).add_operation (GALGAS_string (" undeclared.\n"
          "One of the following"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1564)).add_operation (GALGAS_string ("values are expected :\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1564)).add_operation (function_valueList (var_enumType_54049.getter_valuesMap (SOURCE_FILE ("arxml_parser.galgas", 1565)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1565)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1565)), fixItArray20  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)) ;
      }
      {
      routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1568)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1568)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1568)) ;
      }
      const enumGalgasBool test_21 = GALGAS_bool (kIsNotEqual, var_subTypes_53173.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1569)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_21) {
        {
        routine_displayOil (GALGAS_string ("\n"
          "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1570)) ;
        }
        {
        routine_arxmlDefinitionContainer (var_subTypes_53173, var_subAttributes_53246, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1571)) ;
        }
        {
        routine_displayOil (GALGAS_string ("    }"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1573)) ;
        }
      }
      {
      routine_displayOil (GALGAS_string (";"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1575)) ;
      }
      var_val_49732 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1578)), var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1579)), var_subAttributes_53246  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1577)) ;
    }else if (kBoolFalse == test_17) {
      const enumGalgasBool test_22 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1582)).objectCompare (GALGAS_string ("ECUC-BOOLEAN-PARAM-DEF"))).boolEnum () ;
      if (kBoolTrue == test_22) {
        GALGAS_impBoolType temp_23 ;
        if (var_type_49944.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_impBoolType *> (var_type_49944.ptr ())) {
            temp_23 = (cPtr_impBoolType *) var_type_49944.ptr () ;
          }else{
            inCompiler->castError ("impBoolType", var_type_49944.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1586)) ;
          }
        }
        GALGAS_impBoolType var_boolType_55179 = temp_23 ;
        GALGAS_bool var_booleanValue_55225 ;
        GALGAS_bool test_24 = GALGAS_bool (kIsEqual, var_parameterValue_50587.mProperty_string.getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1588)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_24.boolEnum ()) {
          test_24 = GALGAS_bool (kIsEqual, var_parameterValue_50587.mProperty_string.objectCompare (GALGAS_string ("1"))) ;
        }
        const enumGalgasBool test_25 = test_24.boolEnum () ;
        if (kBoolTrue == test_25) {
          var_subTypes_53173 = var_boolType_55179.getter_trueSubAttributes (SOURCE_FILE ("arxml_parser.galgas", 1590)) ;
          var_booleanValue_55225 = GALGAS_bool (true) ;
        }else if (kBoolFalse == test_25) {
          GALGAS_bool test_26 = GALGAS_bool (kIsEqual, var_parameterValue_50587.mProperty_string.getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1592)).objectCompare (GALGAS_string ("FALSE"))) ;
          if (kBoolTrue != test_26.boolEnum ()) {
            test_26 = GALGAS_bool (kIsEqual, var_parameterValue_50587.mProperty_string.objectCompare (GALGAS_string ("0"))) ;
          }
          const enumGalgasBool test_27 = test_26.boolEnum () ;
          if (kBoolTrue == test_27) {
            var_subTypes_53173 = var_boolType_55179.getter_falseSubAttributes (SOURCE_FILE ("arxml_parser.galgas", 1594)) ;
            var_booleanValue_55225 = GALGAS_bool (false) ;
          }else if (kBoolFalse == test_27) {
            var_booleanValue_55225 = GALGAS_bool (false) ;
            TC_Array <C_FixItDescription> fixItArray28 ;
            inCompiler->emitSemanticError (var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1598)), GALGAS_string ("A Boolean must be 'true', 'false', '0' or '1'"), fixItArray28  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1598)) ;
          }
        }
        {
        routine_displayOil (GALGAS_string (" = ").add_operation (var_booleanValue_55225.getter_cString (SOURCE_FILE ("arxml_parser.galgas", 1601)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1601)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1601)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1601)) ;
        }
        const enumGalgasBool test_29 = GALGAS_bool (kIsNotEqual, var_subTypes_53173.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1602)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_29) {
          {
          routine_displayOil (GALGAS_string ("\n"
            "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1603)) ;
          }
          {
          routine_arxmlDefinitionContainer (var_subTypes_53173, var_subAttributes_53246, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1604)) ;
          }
          {
          routine_displayOil (GALGAS_string ("    }"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1606)) ;
          }
        }
        {
        routine_displayOil (GALGAS_string (";"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1608)) ;
        }
        var_val_49732 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterType_49879.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1611)), var_booleanValue_55225, var_subAttributes_53246  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1610)) ;
      }else if (kBoolFalse == test_22) {
        const enumGalgasBool test_30 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1615)).objectCompare (GALGAS_string ("ECUC-INTEGER-PARAM-DEF"))).boolEnum () ;
        if (kBoolTrue == test_30) {
          GALGAS_bool var_sign_56460 ;
          {
          routine_arxmlPopSign (var_parameterValue_50587, var_sign_56460, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1619)) ;
          }
          GALGAS_luint_36__34_ var_integerValue_56488 = GALGAS_luint_36__34_::constructor_new (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1622)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1622)).getter_uint_36__34_ (SOURCE_FILE ("arxml_parser.galgas", 1622)), var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1623))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1621)) ;
          {
          routine_displayOil (GALGAS_string (" = ").add_operation (var_integerValue_56488.mProperty_uint_36__34_.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1625)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1625)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1625)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1625)) ;
          }
          var_val_49732 = function_checkAndGetIntegerNumber (var_oil_5F_desc_50397, var_type_49944.getter_type (SOURCE_FILE ("arxml_parser.galgas", 1627)), var_integerValue_56488, var_sign_56460, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1627)) ;
        }else if (kBoolFalse == test_30) {
          const enumGalgasBool test_31 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1629)).objectCompare (GALGAS_string ("ECUC-FLOAT-PARAM-DEF"))).boolEnum () ;
          if (kBoolTrue == test_31) {
            GALGAS_bool var_sign_57047 ;
            {
            routine_arxmlPopSign (var_parameterValue_50587, var_sign_57047, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1633)) ;
            }
            GALGAS_ldouble var_floatValue_57073 = GALGAS_ldouble::constructor_new (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1636)).getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1636)), var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1637))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1635)) ;
            {
            routine_displayOil (GALGAS_string (" = ").add_operation (var_floatValue_57073.mProperty_double.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1639)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1639)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1639)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1639)) ;
            }
            var_val_49732 = function_checkAndGetFloatNumber (var_oil_5F_desc_50397, var_type_49944.getter_type (SOURCE_FILE ("arxml_parser.galgas", 1641)), var_floatValue_57073, var_sign_57047, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1641)) ;
          }else if (kBoolFalse == test_31) {
            const enumGalgasBool test_32 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1643)).objectCompare (GALGAS_string ("ECUC-STRING-PARAM-DEF"))).boolEnum () ;
            if (kBoolTrue == test_32) {
              {
              routine_displayOil (GALGAS_string (" = \"").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1647)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1647)).add_operation (GALGAS_string ("\";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1647)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1647)) ;
              }
              var_val_49732 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1650)), var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1651))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1649)) ;
            }else if (kBoolFalse == test_32) {
              const enumGalgasBool test_33 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1653)).objectCompare (GALGAS_string ("ECUC-REFERENCE-DEF"))).boolEnum () ;
              if (kBoolTrue == test_33) {
                {
                routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1657)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1657)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1657)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1657)) ;
                }
                var_val_49732 = GALGAS_objectRefAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1660)), var_parameterValue_50587  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1659)) ;
              }else if (kBoolFalse == test_33) {
                const enumGalgasBool test_34 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1663)).objectCompare (GALGAS_string ("TPL-IDENTIFIER-DEF"))).boolEnum () ;
                if (kBoolTrue == test_34) {
                  {
                  routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1667)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1667)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1667)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1667)) ;
                  }
                  var_val_49732 = GALGAS_string_5F_class::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1670)), var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1671))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1669)) ;
                }else if (kBoolFalse == test_34) {
                  const enumGalgasBool test_35 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1673)).objectCompare (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF"))).boolEnum () ;
                  if (kBoolTrue == test_35) {
                    GALGAS_impStructType temp_36 ;
                    if (var_type_49944.isValid ()) {
                      if (NULL != dynamic_cast <const cPtr_impStructType *> (var_type_49944.ptr ())) {
                        temp_36 = (cPtr_impStructType *) var_type_49944.ptr () ;
                      }else{
                        inCompiler->castError ("impStructType", var_type_49944.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1677)) ;
                      }
                    }
                    GALGAS_impStructType var_structType_58962 = temp_36 ;
                    var_subTypes_53173 = var_structType_58962.getter_structAttributes (SOURCE_FILE ("arxml_parser.galgas", 1678)) ;
                    {
                    routine_displayOil (GALGAS_string (" ").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1680)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1680)).add_operation (GALGAS_string ("\n"
                      "    {\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1680)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1680)) ;
                    }
                    {
                    routine_arxmlDefinitionContainer (var_subTypes_53173, var_subAttributes_53246, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1681)) ;
                    }
                    {
                    routine_displayOil (GALGAS_string ("    };"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1683)) ;
                    }
                    var_val_49732 = GALGAS_structAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1686)), var_parameterValue_50587, var_subAttributes_53246  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1685)) ;
                  }else if (kBoolFalse == test_35) {
                    TC_Array <C_FixItDescription> fixItArray37 ;
                    inCompiler->emitSemanticError (var_valueType_50216.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1693)), GALGAS_string ("Undefined valueType ").add_operation (var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1693)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1693)), fixItArray37  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1693)) ;
                    var_val_49732.drop () ; // Release error dropped variable
                    var_typeOk_49920 = GALGAS_bool (false) ;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  {
  routine_displayOil (GALGAS_string ("      /* ARXML Type :").add_operation (var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1697)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1697)).add_operation (GALGAS_string (" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1697)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1697)) ;
  }
  GALGAS_identifierMap var_idfs_59897 = ioArgument_identifiers.getter_objectParams (SOURCE_FILE ("arxml_parser.galgas", 1702)) ;
  const enumGalgasBool test_38 = var_type_49944.getter_multiple (SOURCE_FILE ("arxml_parser.galgas", 1703)).boolEnum () ;
  if (kBoolTrue == test_38) {
    const enumGalgasBool test_39 = var_idfs_59897.getter_hasKey (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1704)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1704)).boolEnum () ;
    if (kBoolTrue == test_39) {
      GALGAS_object_5F_t var_attributeList_60031 ;
      {
      var_idfs_59897.setter_del (var_parameterType_49879, var_attributeList_60031, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1708)) ;
      }
      if (var_attributeList_60031.isValid ()) {
        if (var_attributeList_60031.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
          GALGAS_multipleAttribute cast_60235_multiAttribute ((cPtr_multipleAttribute *) var_attributeList_60031.ptr ()) ;
          GALGAS_identifierList var_aList_60267 = cast_60235_multiAttribute.getter_items (SOURCE_FILE ("arxml_parser.galgas", 1711)) ;
          var_aList_60267.addAssign_operation (var_val_49732  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1712)) ;
          var_val_49732 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1713)), cast_60235_multiAttribute.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1714)), var_aList_60267  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1713)) ;
        }
      }
    }else if (kBoolFalse == test_39) {
      GALGAS_identifierList var_aList_60537 = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1718)) ;
      GALGAS_object_5F_t var_defaultValue_60616 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_type_49944.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1720)) ;
      if (var_defaultValue_60616.isValid ()) {
        if (var_defaultValue_60616.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
          GALGAS_multipleAttribute cast_60745_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_60616.ptr ()) ;
          var_aList_60537 = cast_60745_multiAttribute.getter_items (SOURCE_FILE ("arxml_parser.galgas", 1725)) ;
        }
      }
      var_aList_60537.addAssign_operation (var_val_49732  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1730)) ;
      var_val_49732 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1732)), var_val_49732.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1732)), var_aList_60537  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1732)) ;
    }
    const enumGalgasBool test_40 = var_idfs_59897.getter_hasKey (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1734)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1734)).boolEnum () ;
    if (kBoolTrue == test_40) {
      GALGAS_object_5F_t var_existingObject_61232 ;
      {
      var_idfs_59897.setter_del (var_parameterType_49879, var_existingObject_61232, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1738)) ;
      }
      {
      var_val_49732.insulate (HERE) ;
      cPtr_object_5F_t * ptr_61299 = (cPtr_object_5F_t *) var_val_49732.ptr () ;
      callExtensionSetter_mergeSubAttributes ((cPtr_object_5F_t *) ptr_61299, var_existingObject_61232, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1739)) ;
      }
    }
  }
  const enumGalgasBool test_41 = var_typeOk_49920.boolEnum () ;
  if (kBoolTrue == test_41) {
    {
    var_idfs_59897.setter_put (var_parameterType_49879, var_val_49732, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1745)) ;
    }
  }
  {
  ioArgument_identifiers.setter_setObjectParams (var_idfs_59897 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1747)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'testTypeError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_testTypeError (GALGAS_dataType inArgument_type,
                            GALGAS_lstring inArgument_valueType,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, extensionGetter_arxmlType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1758)).objectCompare (inArgument_valueType.mProperty_string)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (inArgument_valueType.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1759)), GALGAS_string ("Expected oil type ").add_operation (extensionGetter_oilType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)).add_operation (GALGAS_string (" Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)).add_operation (inArgument_valueType.mProperty_string, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1760)).add_operation (GALGAS_string (".\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1760)).add_operation (GALGAS_string (" Fix : Replace it with "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1760)).add_operation (extensionGetter_arxmlType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1761)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1761)), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'oilEquivalentName'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_oilEquivalentName (GALGAS_lstring inArgument_parentPath,
                                GALGAS_lstring inArgument_currentPath,
                                GALGAS_lstring & outArgument_outName,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outName.drop () ; // Release 'out' argument
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1770)).objectCompare (inArgument_currentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1770)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    inArgument_parentPath.mProperty_string = inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1771)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1771)) ;
  }
  GALGAS_lstring var_objectKind_62165 = GALGAS_lstring::constructor_new (inArgument_currentPath.mProperty_string.getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1774)), inArgument_currentPath.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1775))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1774)) ;
  GALGAS_string var_lastParent_62458 = inArgument_parentPath.mProperty_string.getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1779)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1779)) ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_lastParent_62458.objectCompare (GALGAS_string ("OSOS"))).boolEnum () ;
  if (kBoolTrue == test_1) {
    var_lastParent_62458 = GALGAS_string ("OS") ;
  }
  GALGAS_uint var_lastParentLength_62702 = var_lastParent_62458.getter_length (SOURCE_FILE ("arxml_parser.galgas", 1787)) ;
  const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_objectKind_62165.mProperty_string.getter_leftSubString (var_lastParentLength_62702 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1788)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1788)).objectCompare (var_lastParent_62458)).boolEnum () ;
  if (kBoolTrue == test_2) {
    var_objectKind_62165.mProperty_string = var_objectKind_62165.mProperty_string.getter_subStringFromIndex (var_lastParentLength_62702 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1790)) ;
    var_objectKind_62165.mProperty_string = var_objectKind_62165.mProperty_string.getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1791)) ;
    outArgument_outName = var_objectKind_62165 ;
  }else if (kBoolFalse == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (var_objectKind_62165.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1794)), GALGAS_string ("An object must be named by its Parent.\n"
      " ").add_operation (GALGAS_string ("Ex : If Task object has Os parent, then the DEFINITION-REF must be "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1794)).add_operation (GALGAS_string ("(...)/Os/OsTask.\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1795)).add_operation (GALGAS_string ("Fix : Add \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1796)).add_operation (var_lastParent_62458, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1797)).add_operation (GALGAS_string ("\" to the name of your property."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1797)), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1794)) ;
    outArgument_outName.drop () ; // Release error dropped variable
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'arxmlGetDescription'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlGetDescription (GALGAS_arxmlElementValue inArgument_packageElement,
                                  GALGAS_lstring & outArgument_description,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_description.drop () ; // Release 'out' argument
  outArgument_description = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1806))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1806)) ;
  const enumGalgasBool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DESC"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1809)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_arxmlElementValue var_desc_63571 ;
    callExtensionMethod_getElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DESC"), var_desc_63571, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1810)) ;
    callExtensionMethod_getAllTextsInSelf ((const cPtr_arxmlElementValue *) var_desc_63571.ptr (), GALGAS_string (" "), outArgument_description, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1811)) ;
  }
  const enumGalgasBool test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("INTRODUCTION"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1813)).boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_arxmlElementValue var_desc_63752 ;
    callExtensionMethod_getElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("INTRODUCTION"), var_desc_63752, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1814)) ;
    callExtensionMethod_getAllTextsInSelf ((const cPtr_arxmlElementValue *) var_desc_63752.ptr (), GALGAS_string (" "), outArgument_description, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1815)) ;
  }
  outArgument_description.mProperty_string = outArgument_description.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1819)).getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1819)) ;
  outArgument_description.mProperty_string = outArgument_description.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1822)).getter_stringByReplacingStringByString (GALGAS_string ("\r"), GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1822)) ;
  outArgument_description.mProperty_string = outArgument_description.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1825)).getter_stringByReplacingStringByString (GALGAS_string ("\\"), GALGAS_string ("\\\\"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1825)) ;
  outArgument_description.mProperty_string = outArgument_description.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1828)).getter_stringByReplacingStringByString (GALGAS_string ("\""), GALGAS_string ("\\\""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1828)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'displayOil'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_displayOil (GALGAS_string inArgument_string,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (gOption_goil_5F_options_arxmlDisplayOil.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    inCompiler->printMessage (inArgument_string  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1837)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'arxmlGetMultiplicity'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlGetMultiplicity (GALGAS_arxmlElementValue inArgument_element,
                                   GALGAS_lstring inArgument_objectName,
                                   GALGAS_lbool & outArgument_multiple,
                                   C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_multiple.drop () ; // Release 'out' argument
  const enumGalgasBool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_element.ptr (), GALGAS_string ("UPPER-MULTIPLICITY-INFINITE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1846)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_smultiple_64795 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_element.ptr (), GALGAS_string ("UPPER-MULTIPLICITY-INFINITE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1847)) ;
    GALGAS_bool test_1 = GALGAS_bool (kIsEqual, var_smultiple_64795.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1849)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1849)).objectCompare (GALGAS_string ("TRUE"))) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      test_1 = GALGAS_bool (kIsEqual, var_smultiple_64795.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1850)).objectCompare (GALGAS_string ("1"))) ;
    }
    const enumGalgasBool test_2 = test_1.boolEnum () ;
    if (kBoolTrue == test_2) {
      outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (true), var_smultiple_64795.mProperty_location  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1851)) ;
      {
      routine_displayOil (GALGAS_string ("[]"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1852)) ;
      }
    }else if (kBoolFalse == test_2) {
      outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (false), var_smultiple_64795.mProperty_location  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1854)) ;
    }
  }else if (kBoolFalse == test_0) {
    outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (false), inArgument_objectName.mProperty_location  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1857)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'arxmlPopSign'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlPopSign (GALGAS_lstring & ioArgument_value,
                           GALGAS_bool & outArgument_sign,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_sign.drop () ; // Release 'out' argument
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, ioArgument_value.mProperty_string.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1866)).objectCompare (GALGAS_char (TO_UNICODE (45)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_sign = GALGAS_bool (true) ;
    ioArgument_value.mProperty_string = ioArgument_value.mProperty_string.getter_subStringFromIndex (GALGAS_uint ((uint32_t) 1U) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1868)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, ioArgument_value.mProperty_string.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1869)).objectCompare (GALGAS_char (TO_UNICODE (43)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_sign = GALGAS_bool (false) ;
      ioArgument_value.mProperty_string = ioArgument_value.mProperty_string.getter_subStringFromIndex (GALGAS_uint ((uint32_t) 1U) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1871)) ;
    }else if (kBoolFalse == test_1) {
      outArgument_sign = GALGAS_bool (false) ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'arxmlGetWithAuto'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlGetWithAuto (GALGAS_arxmlElementValue inArgument_parameter,
                               GALGAS_bool & outArgument_withAuto,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_withAuto.drop () ; // Release 'out' argument
  outArgument_withAuto = GALGAS_bool (false) ;
  const enumGalgasBool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("WITH-AUTO"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1882)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_autoString_65700 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("WITH-AUTO"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1883)) ;
    GALGAS_bool test_1 = GALGAS_bool (kIsEqual, var_autoString_65700.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1884)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1884)).objectCompare (GALGAS_string ("TRUE"))) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      test_1 = GALGAS_bool (kIsEqual, var_autoString_65700.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1885)).objectCompare (GALGAS_string ("1"))) ;
    }
    const enumGalgasBool test_2 = test_1.boolEnum () ;
    if (kBoolTrue == test_2) {
      outArgument_withAuto = GALGAS_bool (true) ;
      {
      routine_displayOil (GALGAS_string (" WITH_AUTO"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1887)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'arxmlGetName'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlGetName (GALGAS_arxmlElementValue inArgument_parameter,
                           GALGAS_lstring & outArgument_objectName,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_objectName = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1897)) ;
  outArgument_objectName.mProperty_string = outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1898)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1898)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'arxmlInsertObjectAttribute'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlInsertObjectAttribute (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                         GALGAS_lstring inArgument_attributeName,
                                         GALGAS_impType inArgument_type,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = ioArgument_objectAttributes.getter_hasKey (inArgument_attributeName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1906)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1906)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_previousType_66335 ;
    ioArgument_objectAttributes.method_get (inArgument_attributeName, var_previousType_66335, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1908)) ;
    const enumGalgasBool test_1 = var_previousType_66335.getter_multiple (SOURCE_FILE ("arxml_parser.galgas", 1911)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_object_5F_t var_previousDefaultValue_66673 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_previousType_66335.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1914)) ;
      GALGAS_object_5F_t var_defaultValue_66735 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) inArgument_type.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1915)) ;
      GALGAS_bool var_oneIsMultiple_66786 = GALGAS_bool (false) ;
      const enumGalgasBool test_2 = GALGAS_bool (var_previousDefaultValue_66673.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_oneIsMultiple_66786 = GALGAS_bool (true) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (var_defaultValue_66735.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
        if (kBoolTrue == test_3) {
          var_oneIsMultiple_66786 = GALGAS_bool (true) ;
        }
      }
      const enumGalgasBool test_4 = var_oneIsMultiple_66786.boolEnum () ;
      if (kBoolTrue == test_4) {
        GALGAS_identifierList var_aList_67189 = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1926)) ;
        GALGAS_lstring var_desc_67224 = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1927)) ;
        GALGAS_location var_location_67268 = GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1928)) ;
        if (var_previousDefaultValue_66673.isValid ()) {
          if (var_previousDefaultValue_66673.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
            GALGAS_multipleAttribute cast_67394_multiAttribute ((cPtr_multipleAttribute *) var_previousDefaultValue_66673.ptr ()) ;
            var_aList_67189 = cast_67394_multiAttribute.getter_items (SOURCE_FILE ("arxml_parser.galgas", 1933)) ;
            var_desc_67224 = cast_67394_multiAttribute.getter_oil_5F_desc (SOURCE_FILE ("arxml_parser.galgas", 1934)) ;
            var_location_67268 = cast_67394_multiAttribute.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1935)) ;
          }
        }
        if (var_defaultValue_66735.isValid ()) {
          if (var_defaultValue_66735.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
            GALGAS_multipleAttribute cast_67654_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_66735.ptr ()) ;
            var_aList_67189.plusAssign_operation(cast_67654_multiAttribute.getter_items (SOURCE_FILE ("arxml_parser.galgas", 1941)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1941)) ;
            const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, var_desc_67224.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1942)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
            if (kBoolTrue == test_5) {
              var_desc_67224 = cast_67654_multiAttribute.getter_oil_5F_desc (SOURCE_FILE ("arxml_parser.galgas", 1943)) ;
            }
            const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_location_67268.objectCompare (GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1945)))).boolEnum () ;
            if (kBoolTrue == test_6) {
              var_location_67268 = cast_67654_multiAttribute.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1946)) ;
            }
          }
        }
        GALGAS_object_5F_t var_newDefault_67983 = GALGAS_multipleAttribute::constructor_new (var_desc_67224, var_location_67268, var_aList_67189  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1951)) ;
        {
        inArgument_type.insulate (HERE) ;
        cPtr_impType * ptr_68085 = (cPtr_impType *) inArgument_type.ptr () ;
        callExtensionSetter_setDefaultValue ((cPtr_impType *) ptr_68085, var_newDefault_67983, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1954)) ;
        }
        {
        GALGAS_impType joker_68164 ; // Joker input parameter
        ioArgument_objectAttributes.setter_del (inArgument_attributeName, joker_68164, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1956)) ;
        }
        {
        ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1957)) ;
        }
      }
    }
    const enumGalgasBool test_7 = function_checkNewTypeWithinPreviousType (inArgument_attributeName, var_previousType_66335, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1961)).boolEnum () ;
    if (kBoolTrue == test_7) {
      {
      GALGAS_impType joker_68448 ; // Joker input parameter
      ioArgument_objectAttributes.setter_del (inArgument_attributeName, joker_68448, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1964)) ;
      }
      {
      ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1965)) ;
      }
    }
  }else if (kBoolFalse == test_0) {
    {
    ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1968)) ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@arxmlElementNode print'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementNode_print (const cPtr_arxmlNode * inObject,
                                                    const GALGAS_uint constinArgument_indentation,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = (const cPtr_arxmlElementNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  GALGAS_string var_indent_3618 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 172)) ;
  inCompiler->printMessage (var_indent_3618  COMMA_SOURCE_FILE ("arxml_types.galgas", 173)) ;
  inCompiler->printMessage (GALGAS_string ("NODE \"").add_operation (object->mProperty_name.getter_string (SOURCE_FILE ("arxml_types.galgas", 174)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 174)).add_operation (GALGAS_string ("\" "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 174))  COMMA_SOURCE_FILE ("arxml_types.galgas", 174)) ;
  extensionMethod_print (object->mProperty_attributes, constinArgument_indentation, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 175)) ;
  inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("arxml_types.galgas", 176)) ;
  extensionMethod_print (object->mProperty_enclosedNodes, constinArgument_indentation, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 177)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementNode_print (void) {
  enterExtensionMethod_print (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                              extensionMethod_arxmlElementNode_print) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementNode_print (defineExtensionMethod_arxmlElementNode_print, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@arxmlElementNode getElementsFromName'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementNode_getElementsFromName (const cPtr_arxmlNode * inObject,
                                                                  const GALGAS_string constinArgument_nodeName,
                                                                  GALGAS_arxmlElementList & ioArgument_nodeList,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = (const cPtr_arxmlElementNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_nodeName.objectCompare (object->mProperty_name.getter_string (SOURCE_FILE ("arxml_types.galgas", 184)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    const GALGAS_arxmlElementNode temp_1 = object ;
    ioArgument_nodeList.addAssign_operation (temp_1  COMMA_SOURCE_FILE ("arxml_types.galgas", 185)) ;
  }
  extensionMethod_getElementsFromName (object->mProperty_enclosedNodes, constinArgument_nodeName, ioArgument_nodeList, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 188)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementNode_getElementsFromName (void) {
  enterExtensionMethod_getElementsFromName (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                            extensionMethod_arxmlElementNode_getElementsFromName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementNode_getElementsFromName (defineExtensionMethod_arxmlElementNode_getElementsFromName, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension method '@arxmlElementNode getSubElementsFromName'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementNode_getSubElementsFromName (const cPtr_arxmlNode * inObject,
                                                                     const GALGAS_string constinArgument_nodeName,
                                                                     GALGAS_arxmlElementList & ioArgument_nodeList,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = (const cPtr_arxmlElementNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  cEnumerator_arxmlNodeList enumerator_4206 (object->mProperty_enclosedNodes, kENUMERATION_UP) ;
  while (enumerator_4206.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (enumerator_4206.current_node (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_arxmlElementNode).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_arxmlElementNode temp_1 ;
      if (enumerator_4206.current_node (HERE).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_arxmlElementNode *> (enumerator_4206.current_node (HERE).ptr ())) {
          temp_1 = (cPtr_arxmlElementNode *) enumerator_4206.current_node (HERE).ptr () ;
        }else{
          inCompiler->castError ("arxmlElementNode", enumerator_4206.current_node (HERE).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_types.galgas", 197)) ;
        }
      }
      GALGAS_arxmlElementNode var_currentElement_4296 = temp_1 ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_currentElement_4296.getter_name (SOURCE_FILE ("arxml_types.galgas", 198)).mProperty_string.objectCompare (constinArgument_nodeName)).boolEnum () ;
      if (kBoolTrue == test_2) {
        ioArgument_nodeList.addAssign_operation (var_currentElement_4296  COMMA_SOURCE_FILE ("arxml_types.galgas", 199)) ;
      }
    }
    enumerator_4206.gotoNextObject () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementNode_getSubElementsFromName (void) {
  enterExtensionMethod_getSubElementsFromName (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                               extensionMethod_arxmlElementNode_getSubElementsFromName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementNode_getSubElementsFromName (defineExtensionMethod_arxmlElementNode_getSubElementsFromName, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@arxmlElementNode getProperty'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementNode_getProperty (const cPtr_arxmlNode * inObject,
                                                          const GALGAS_string constinArgument_nodeName,
                                                          GALGAS_lstring & ioArgument_value,
                                                          GALGAS_bool & ioArgument_found,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = (const cPtr_arxmlElementNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_nodeName.objectCompare (object->mProperty_name.getter_string (SOURCE_FILE ("arxml_types.galgas", 223)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    const GALGAS_arxmlElementNode temp_1 = object ;
    callExtensionMethod_getText ((const cPtr_arxmlElementNode *) temp_1.ptr (), ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 224)) ;
  }
  const enumGalgasBool test_2 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 227)).boolEnum () ;
  if (kBoolTrue == test_2) {
    cEnumerator_arxmlNodeList enumerator_4993 (object->mProperty_enclosedNodes, kENUMERATION_UP) ;
    bool bool_3 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 229)).isValidAndTrue () ;
    if (enumerator_4993.hasCurrentObject () && bool_3) {
      while (enumerator_4993.hasCurrentObject () && bool_3) {
        callExtensionMethod_getProperty ((const cPtr_arxmlNode *) enumerator_4993.current_node (HERE).ptr (), constinArgument_nodeName, ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 231)) ;
        enumerator_4993.gotoNextObject () ;
        if (enumerator_4993.hasCurrentObject ()) {
          bool_3 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 229)).isValidAndTrue () ;
        }
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementNode_getProperty (void) {
  enterExtensionMethod_getProperty (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                    extensionMethod_arxmlElementNode_getProperty) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementNode_getProperty (defineExtensionMethod_arxmlElementNode_getProperty, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@arxmlCommentNode print'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlCommentNode_print (const cPtr_arxmlNode * inObject,
                                                    const GALGAS_uint constinArgument_indentation,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlCommentNode * object = (const cPtr_arxmlCommentNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlCommentNode) ;
  GALGAS_string var_indent_5992 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 281)) ;
  inCompiler->printMessage (var_indent_5992  COMMA_SOURCE_FILE ("arxml_types.galgas", 282)) ;
  inCompiler->printMessage (GALGAS_string ("COMMENT \"").add_operation (object->mProperty_comment.getter_string (SOURCE_FILE ("arxml_types.galgas", 283)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 283)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 283))  COMMA_SOURCE_FILE ("arxml_types.galgas", 283)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlCommentNode_print (void) {
  enterExtensionMethod_print (kTypeDescriptor_GALGAS_arxmlCommentNode.mSlotID,
                              extensionMethod_arxmlCommentNode_print) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlCommentNode_print (defineExtensionMethod_arxmlCommentNode_print, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@arxmlCommentNode getElementsFromName'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlCommentNode_getElementsFromName (const cPtr_arxmlNode * /* inObject */,
                                                                  const GALGAS_string /* constinArgument_nodeName */,
                                                                  GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                                  C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlCommentNode_getElementsFromName (void) {
  enterExtensionMethod_getElementsFromName (kTypeDescriptor_GALGAS_arxmlCommentNode.mSlotID,
                                            extensionMethod_arxmlCommentNode_getElementsFromName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlCommentNode_getElementsFromName (defineExtensionMethod_arxmlCommentNode_getElementsFromName, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension method '@arxmlCommentNode getSubElementsFromName'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlCommentNode_getSubElementsFromName (const cPtr_arxmlNode * /* inObject */,
                                                                     const GALGAS_string /* constinArgument_nodeName */,
                                                                     GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                                     C_Compiler * /* inCompiler */
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlCommentNode_getSubElementsFromName (void) {
  enterExtensionMethod_getSubElementsFromName (kTypeDescriptor_GALGAS_arxmlCommentNode.mSlotID,
                                               extensionMethod_arxmlCommentNode_getSubElementsFromName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlCommentNode_getSubElementsFromName (defineExtensionMethod_arxmlCommentNode_getSubElementsFromName, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@arxmlCommentNode getProperty'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlCommentNode_getProperty (const cPtr_arxmlNode * /* inObject */,
                                                          const GALGAS_string /* constinArgument_nodeName */,
                                                          GALGAS_lstring & /* ioArgument_value */,
                                                          GALGAS_bool & /* ioArgument_found */,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlCommentNode_getProperty (void) {
  enterExtensionMethod_getProperty (kTypeDescriptor_GALGAS_arxmlCommentNode.mSlotID,
                                    extensionMethod_arxmlCommentNode_getProperty) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlCommentNode_getProperty (defineExtensionMethod_arxmlCommentNode_getProperty, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension method '@arxmlTextNode print'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlTextNode_print (const cPtr_arxmlNode * inObject,
                                                 const GALGAS_uint constinArgument_indentation,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlTextNode * object = (const cPtr_arxmlTextNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlTextNode) ;
  GALGAS_string var_indent_6749 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 316)) ;
  inCompiler->printMessage (var_indent_6749  COMMA_SOURCE_FILE ("arxml_types.galgas", 317)) ;
  inCompiler->printMessage (GALGAS_string ("TEXT \"").add_operation (object->mProperty_text.getter_string (SOURCE_FILE ("arxml_types.galgas", 318)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 318)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 318))  COMMA_SOURCE_FILE ("arxml_types.galgas", 318)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlTextNode_print (void) {
  enterExtensionMethod_print (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                              extensionMethod_arxmlTextNode_print) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlTextNode_print (defineExtensionMethod_arxmlTextNode_print, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@arxmlTextNode getElementsFromName'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlTextNode_getElementsFromName (const cPtr_arxmlNode * /* inObject */,
                                                               const GALGAS_string /* constinArgument_nodeName */,
                                                               GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                               C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlTextNode_getElementsFromName (void) {
  enterExtensionMethod_getElementsFromName (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                                            extensionMethod_arxmlTextNode_getElementsFromName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlTextNode_getElementsFromName (defineExtensionMethod_arxmlTextNode_getElementsFromName, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@arxmlTextNode getSubElementsFromName'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlTextNode_getSubElementsFromName (const cPtr_arxmlNode * /* inObject */,
                                                                  const GALGAS_string /* constinArgument_nodeName */,
                                                                  GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                                  C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlTextNode_getSubElementsFromName (void) {
  enterExtensionMethod_getSubElementsFromName (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                                               extensionMethod_arxmlTextNode_getSubElementsFromName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlTextNode_getSubElementsFromName (defineExtensionMethod_arxmlTextNode_getSubElementsFromName, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@arxmlTextNode getProperty'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlTextNode_getProperty (const cPtr_arxmlNode * /* inObject */,
                                                       const GALGAS_string /* constinArgument_nodeName */,
                                                       GALGAS_lstring & /* ioArgument_value */,
                                                       GALGAS_bool & /* ioArgument_found */,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlTextNode_getProperty (void) {
  enterExtensionMethod_getProperty (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                                    extensionMethod_arxmlTextNode_getProperty) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlTextNode_getProperty (defineExtensionMethod_arxmlTextNode_getProperty, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'lstringhere'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_lstringhere (GALGAS_lstring & outArgument_string,
                          GALGAS_string inArgument_value,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_string.drop () ; // Release 'out' argument
  outArgument_string = GALGAS_lstring::constructor_new (inArgument_value, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1193))  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1193)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'fillLegacy'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_fillLegacy (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                         GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist var_sortedInfoList_33628 = ioArgument_classGraph.getter_keyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1200)) ;
  cEnumerator_stringlist enumerator_33697 (var_sortedInfoList_33628, kENUMERATION_UP) ;
  while (enumerator_33697.hasCurrentObject ()) {
    GALGAS_lstring var_lClassName_33737 ;
    {
    routine_lstringhere (var_lClassName_33737, enumerator_33697.current_mValue (HERE), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1203)) ;
    }
    GALGAS_arxmlMetaClass var_lClass_33777 ;
    ioArgument_classMap.method_searchKey (var_lClassName_33737, var_lClass_33777, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1205)) ;
    GALGAS_lstringlist var_fromList_33870 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1208)) ;
    {
    var_fromList_33870.setter_insertAtIndex (var_lClass_33777.getter_name (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1209)), GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1209)) ;
    }
    GALGAS_stringset var_empty_33945 = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1210)) ;
    GALGAS_lstringlist var_successorList_33988 = ioArgument_classGraph.getter_accessibleNodesFrom (var_fromList_33870, var_empty_33945, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1211)) ;
    {
    var_lClass_33777.insulate (HERE) ;
    cPtr_arxmlMetaClass * ptr_34134 = (cPtr_arxmlMetaClass *) var_lClass_33777.ptr () ;
    callExtensionSetter_legacyAddParameters ((cPtr_arxmlMetaClass *) ptr_34134, ioArgument_classMap, var_successorList_33988, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1214)) ;
    }
    enumerator_33697.gotoNextObject () ;
  }
}


#include "project_header.h"
#include "command_line_interface/F_mainForLIBPM.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "utilities/F_DisplayException.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/F_verbose_output.h"
#include "galgas2/cLexiqueIntrospection.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      print_tool_help_message                                                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void print_tool_help_message (void) {
  co << "Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n" ;
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * kSourceFileExtensions [] = {
  "oil",
  "OIL",
  "goilTemplate",
  "arxml",
  NULL
} ;    

//---------------------------------------------------------------------------------------------------------------------*

static const char * kSourceFileHelpMessages [] = {
  "an '.oil' source file",
  "an '.OIL' source file",
  "a Goil template file",
  "an AUTOSAR arxml configuration file",
  NULL
} ;    

//---------------------------------------------------------------------------------------------------------------------*

const char * projectVersionString (void) {
  return "3.1.3" ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Routine 'before'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void routine_before (C_Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Routine 'after'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void routine_after (C_Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'programRule_0'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 33)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 34)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'programRule_1'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void routine_programRule_5F__31_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 38)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 39)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'programRule_2'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void routine_programRule_5F__32_ (const GALGAS_lstring /* constinArgument_inSourceFile */,
                                         C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'programRule_3'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void routine_programRule_5F__33_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 48)) ;
  }
  GALGAS_arxmlNode var_root_1353 ;
  var_root_1353.drop () ;
  cGrammar_arxml_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile, var_root_1353, GALGAS_bool (true), GALGAS_bool (true)  COMMA_SOURCE_FILE ("goil_program.galgas", 49)) ;
  callExtensionMethod_print ((const cPtr_arxmlNode *) var_root_1353.ptr (), GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_program.galgas", 53)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      M A I N    F O R    L I B P M                                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int mainForLIBPM (int inArgc, const char * inArgv []) {
//--- Analyze Command Line Options
  TC_UniqueArray <C_String> sourceFilesArray ;
  F_Analyze_CLI_Options (inArgc, inArgv,
                         sourceFilesArray,
                         kSourceFileExtensions,
                         kSourceFileHelpMessages,
                         print_tool_help_message) ;
//---
  int returnCode = 0 ; // No error
//--- Set Execution mode
  C_String executionModeOptionErrorMessage ;
  setExecutionMode (executionModeOptionErrorMessage) ;
  if (executionModeOptionErrorMessage.length () > 0) {
    co << executionModeOptionErrorMessage ;
    returnCode = 1 ;
  }else{
  //--- Common lexique object
    C_Compiler * commonLexique = NULL ;
    macroMyNew (commonLexique, C_Compiler (NULL COMMA_HERE)) ;
    try{
      routine_before (commonLexique COMMA_HERE) ;
      cLexiqueIntrospection::handleGetKeywordListOption (commonLexique) ;
      const bool verboseOptionOn = verboseOutput () ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        const C_String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
        const GALGAS_string sfp = GALGAS_string (sourceFilesArray (i COMMA_HERE)) ;
        const GALGAS_location location = commonLexique->here () ;
        const GALGAS_lstring sourceFilePath (sfp, location) ;
        int r = 0 ;
        if (fileExtension == "oil") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__30_ (sourceFilePath, commonLexique COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "OIL") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__31_ (sourceFilePath, commonLexique COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "goilTemplate") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__32_ (sourceFilePath, commonLexique COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "arxml") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__33_ (sourceFilePath, commonLexique COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else{
          printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString (HERE)) ;
          r = 1 ;
        }
        if (r != 0) {
          returnCode = r ;
        }
      }
    //--- Error or warnings ?
      if (totalErrorCount () > 0) {
        returnCode = 1 ; // Error code
      }else if (totalWarningCount () > 0) {
        if (gOption_galgas_5F_builtin_5F_options_treat_5F_warnings_5F_as_5F_error.mValue) {
          returnCode = 1 ; // Error code
          if (verboseOptionOn) {
            printf ("** Note: warnings are treated as errors. **\n") ;
          }
        }
      }
    //--- Epilogue
      routine_after (commonLexique COMMA_HERE) ;
    //--- Display error and warnings count
      if (verboseOptionOn || (totalWarningCount () > 0) || (totalErrorCount () > 0)) {
        C_String message ;
        if (totalWarningCount () == 0) {
          message << "No warning" ;
        }else if (totalWarningCount () == 1) {
          message << "1 warning" ;
        }else{
          message << cStringWithSigned (totalWarningCount ()) << " warnings" ;
        }
        message << ", " ;
        if (totalErrorCount () == 0) {
          message << "no error" ;
        }else if (totalErrorCount () == 1) {
          message << "1 error" ;
        }else{
          message << cStringWithSigned (totalErrorCount ()) << " errors" ;
        }
        message << ".\n" ;
        ggs_printMessage (message COMMA_HERE) ;
      }
    }catch (const ::std:: exception & e) {
      F_default_display_exception (e) ;
      returnCode = 1 ; // Error code
    }catch (...) {
      printf ("**** Unknow exception ****\n") ;
      throw ;
    }
    macroDetachSharedObject (commonLexique) ;
  }
  return returnCode ;
}

