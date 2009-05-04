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
	for i in `cat testSequences.txt`
	do
		#remove make-rules, makefiles, defaultAppWorkstation/, build/, embUnit/*.o and lib/libembUnit.a
		rm -rf ./${i}/build
		rm -rf ./${i}/defaultAppWorkstation
		rm -rf ./${i}/Make-rules
		rm -rf ./${i}/Makefile
		rm -rf ./${i}/${i}
		rm -rf ./embUnit/*.o
		rm -rf ./lib/libembUnit.a
	done
	rm -rf results.log
else

	echo "Begin internal functional test procedure..."

	## Create an empty file
	> results.log

	# Make embUnit
	( cd ./embUnit ; make )

	# Build and execute all the tests
	for i in `cat testSequences.txt`
	do
		#the path to the result file is different from a functional test or a goil test, this if tests if the test sequence is a functional or a goil one and change the path according to.
		if [ "`echo ${i} | grep goil`" != "" ]
		then
			result_path="../../functional/"
		else
			result_path="../"
		fi
	
		cd ./${i}
		echo "running $i" | tee -a "${result_path}results.log" #display running test sequence on the standard output for the user and in the log file to better understand failed tests
		
		rm -rf ./${i} #remove the executable file in order to know if the make succeed.
		
		#if Makefile doesn't exist -> do goil
		if ! `test -f Makefile`
		then
			#check if target's name is among arguments (default=libpcl)
			if [ "$1" = "" ]
			then	
				goil --target=libpcl --templates=../../../goil/templates/ -g defaultAppWorkstation.oil 2>&1 | tee -a "${result_path}results.log"
			else 
				goil --target=$1 --templates=../../../goil/templates/ -g defaultAppWorkstation.oil 2>&1 | tee -a "${result_path}results.log" 
			fi
		fi
		
		#if goil succeed (Makefile has been created) -> do make and axecute file
		if `test -f Makefile`
		then
			make -s
			./${i} >> "${result_path}results.log"
		fi
		
		cd "${result_path}"
	
	done
	echo "Tests done."

	echo "Compare results with the expected ones..."
	if [ `diff results_expected.log results.log | wc -l` -eq 0 ] 
	then 
		echo "Success!!"
	else
		echo "Failed! Results are stored in `pwd`/results.log"
		#opendiff results_expected.log results.log
	fi
fi