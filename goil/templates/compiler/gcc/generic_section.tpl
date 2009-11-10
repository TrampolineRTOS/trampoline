/*
 * $OBJ$ $NAME$ section for type $KIND$$SUBKIND$ of size $SIZE$
 */
#ifdef APP_$OBJ$_$NAME$_START_$CONT$_$KIND$$SUBKIND$_$SIZE$
  #ifdef CURRENT_LINKER_SECTION_NAME
    #error "Starting a new section while section $OBJ$_$NAME$$CONT$$KIND$$SUBKIND$$SIZE$ is already started"
  #else
    #undef APP_$OBJ$_$NAME$_START_$CONT$_$KIND$$SUBKIND$_$SIZE$
    #define CURRENT_LINKER_SECTION_NAME ".$OBJ$_$NAME$$CONT$$KIND$$SUBKIND$$SIZE$"
  #endif
#endif
#ifdef APP_$OBJ$_$NAME$_STOP_$CONT$_$KIND$$SUBKIND$_$SIZE$
	#undef APP_$OBJ$_$NAME$_STOP_$CONT$_$KIND$$SUBKIND$_$SIZE$
  #undef CURRENT_LINKER_SECTION_NAME
#endif

