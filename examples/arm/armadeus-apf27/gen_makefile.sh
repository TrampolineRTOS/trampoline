if [ -z $1 ] ; then
  FILE=app5_trusted_fct.oil
else
  FILE=$1
fi

goil --autosar --interrupts --generate-makefile --target=arm/arm926/armadeus-apf27 --templates=../../../goil/templates $FILE
