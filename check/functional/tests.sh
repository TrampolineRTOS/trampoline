#!/bin/sh

######
# performs all the functional tests.
# args:
# (nothing): performs tests
# clean    : call make clean for each tests folders
#
# TODO : commit test task_management and change their names
#		 finish hook_s4
#		 finish interrupts_s4
######ichat-balloon-style://left-thought

if [ "$1" = "clean" ]
then
	for i in `cat testSequences.txt`
	do
		rm -rf ./${i}/build #do not call make mrproper.
		#touch ./${i}/defaultAppWorkstation.oil
		#remove make-rules, makefiles, defaultAppWorkstation too
				
	done
else

	echo "Begin internal Functionnal Test Procedure.."

	## Create an empty file
	> results.log

	# Build and execute all the tests
	for i in `cat testSequences.txt`
	do
		cd ./${i}
		#if all files are deleted when 'clean' a goil is needed (with goil's templates url) and the target librarie (here libpcl) :
		goil --target=libpcl --templates=../../../goil/templates/ -g defaultAppWorkstation.oil
		make
		./${i} >> ../results.log
		cd ..
	done
	echo "Tests done."

	#echo "Compare results with the expected ones..."
	if [ `diff results_expected.log results.log | wc -l` -eq 0 ] 
	then 
		echo "Success!!"
	else
		echo "Failed! Results are stored in `pwd`/results.log"
		opendiff results_expected.log results.log
	fi
fi