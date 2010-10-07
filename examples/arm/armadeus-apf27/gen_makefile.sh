if [ -z $1 ] ; then
  FILE=app1_noisr_nomm_nomp.oil
else
  FILE=$1
fi

goil --autosar --interrupts --generate-makefile --target=arm/armadeus-apf27 --templates=../../../goil/templates $FILE
