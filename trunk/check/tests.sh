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

if [ "$1" = "clean" ]
then
	#Delete embUnit's objects and librairy
	rm -rf ./embUnit/*.o
	rm -rf ./lib/libembUnit.a
		
else
	# Make embUnit
	( cd ./embUnit ; make )
	
fi

#functional tests
cd ./functional
./functional_tests.sh $1

#GOIL tests
cd ../GOIL
./GOIL_tests.sh $1

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
	

