#!/bin/sh

######
# performs all the functional tests.
# args:
# (nothing): performs tests
# clean    : call make clean for each tests folders
#
######

if [ "$1" != "clean" ] && [ "$1" != "" ] 
then
	echo "Wrong parameters!"
	echo "Waited :"
	echo "   clean or null"
	exit 1
fi

#GOIL tests
cd ./GOIL
./GOIL_tests.sh $1

#functional tests
cd ../functional
./functional_tests.sh $1

cd ..

if [ "$1" != "clean" ]
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
	

