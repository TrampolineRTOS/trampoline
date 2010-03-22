#!/bin/sh

if [ $# -ne 2 ]
then
  echo "Usage: ./duplicate_dir.sh [directory_name] [number]"
  echo "\t directory_name is the directory name you would like to duplicate"
  echo "\t number is the directory number you want"
  echo "\t"
  echo "\t example : ./duplicate_dir.sh test 3"
  echo "\t \t cp test test1; cp test test2; cp test test3;"
else

config_path=../../viper2/config.py
cp ../../viper2/config-StressTesting.py $config_path
echo "allEcus = [" >> $config_path

	for (( i=1; i<=$2; i++ ))
	do
  		#duplicate application
  		echo "cp -r $1 ${1}$i"
  		cp -r $1 ${1}$i
  		
  		#deuplicate Ecus in config file
  		echo "  Ecu(" >> $config_path
        echo "    \"../examples/viper2/StressTesting${i}/trampoline\","  >> $config_path
 		echo "    scheduler," >> $config_path
 		echo "    [" >> $config_path
 		echo "      Timer(\"TIMER0\", 1, type = timer.AUTO, delay = 10)," >> $config_path
 		echo "      LCD(\"LCD1\", 4)," >> $config_path
 		echo "      Power(\"POWER\", 9)," >> $config_path
 		echo "    ]" >> $config_path
 		echo "  )," >> $config_path
  
	done
	
echo "]" >> $config_path
	
fi





