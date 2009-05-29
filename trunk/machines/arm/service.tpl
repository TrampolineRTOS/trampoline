.global $SYSCALLFCT
$SYSCALLFCT:
  mov r3, #OSServiceId_$SYSCALLNAME
  swi #OSServiceId_$SYSCALLNAME
  mov pc, lr

  