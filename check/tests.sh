#!/bin/sh

######
# performs all the functional tests.
# args:
# (nothing): performs tests
# clean    : call make clean for each tests folders
# {goil's target} : if Makefile hasn't been created yet, a 'goil' command is needed with the target name (default=libpcl)
#
# TODO : 
#		 delete testSequences file and do the loops for each directory (which contains defaultAppWorkstation.oil) #ls -d
######

#check target
parameters=false
while [ $# -gt 0 ]
do
    #echo "paramètres : $1"
	if [ "`echo $1 | grep -c =`" = "1" ]
	then
		#echo "paramètre with ="
		option=`echo $1 | awk -F"=" '{print $1}'`
		#echo "option : $option"
		case "$option" in
			-t) target=`echo $1 | awk -F"=" '{print $2}'`;
				echo "Target $target selected";;
		esac
	else
		case "$1" in
			clean) target="clean";;
			*) echo "Wrong parameters!";
			   echo "Waited :";
			   echo "   -t=[target],";
			   echo "   clean or";
			   echo "   NULL (posix target selected)"; exit 1;;
		esac
	fi    
	parameters=true
    shift
done
if [ "$parameters" = "false" ]
then
	#default target = posix
	target="posix"
	echo "Target $target selected"
fi


#GOIL tests
cd ./GOIL
./GOIL_tests.sh $target

#functional tests
cd ../functional
./functional_tests.sh $target


cd ..

if [ "$target" != "clean" ]
then
	#Compare results
	echo "Compare results with the expected ones..."
	if [ `diff functional/functional_results_expected.log functional/functional_results.log | wc -l` -eq 0 ]
	then
		echo "Functional tests Succeed!!"
	else
		echo "Functional tests Failed! Results are stored in `pwd`/functional/functional_results.log"
	fi
	if [ `diff GOIL/GOIL_results_expected.log GOIL/GOIL_results.log | wc -l` -eq 0 ]
	then
		echo "GOIL tests Succeed!!"
	else
		echo "GOIL tests Failed! Results are stored in `pwd`/GOIL/GOIL_results.log"
	fi
fi
	

