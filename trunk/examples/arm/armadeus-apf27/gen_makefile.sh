if [ -z $1 ] ; then
  FILE=osap_0_task_4_isr_2_no_autosar_armadeus.oil
else
  FILE=$1
fi

goil --interrupts --generate-makefile --target=arm/armadeus-apf27 --templates=../../../goil/templates $FILE
