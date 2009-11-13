  .global $SYSCALLFCT
$SYSCALLFCT:
  subi r1,r1,4
  stw  r0,0(r1)
  li   r0,OSServiceId_$SYSCALLNAME
  sc
  lwz  r0,0(r1)
  addi r1,r1,4
  blr
  
  .type $SYSCALLFCT,@function
  .size $SYSCALLFCT,$$-$SYSCALLFCT

