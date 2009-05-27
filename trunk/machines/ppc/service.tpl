  .global $SYSCALLFCT
$SYSCALLFCT:
  subi r1,r1,16
  stw  r0,4(r1)
  mflr r0
  stw  r0,0(r1)
  stw  r11,8(r1)
  stw  r12,12(r1)
  li   r0,OSServiceId_$SYSCALLNAME
  sc
  lwz  r12,12(r1)
  lwz  r11,8(r1)
  lwz  r0,0(r1)
  mtlr r0
  lwz  r0,4(r1)
  addi r1,r1,16
  blr
  
  .type $SYSCALLFCT,@function
  .size $SYSCALLFCT,$$-$SYSCALLFCT

