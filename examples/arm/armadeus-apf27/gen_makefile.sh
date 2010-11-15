if [ -z $1 ] ; then
  FILE=app4_isr_mm_mp.oil
else
  FILE=$1
fi

goil --autosar --interrupts --generate-makefile --target=arm/armadeus-apf27 --templates=../../../goil/templates $FILE
