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
	#Delete results.log
	rm -rf results.log
	#Change in results_expected.log the check directory path to 'CHECKPATH'.
	( cd .. ; cat ./functional/results_expected.log | sed -e "s/`pwd | sed 's_\/_\\\/_g'`/CHECKPATH/g" > ./backup.txt ; mv ./backup.txt ./functional/results_expected.log )
else

	echo "Begin internal functional test procedure..."

	## Create an empty file
	> results.log

	# Make embUnit
	( cd ./embUnit ; make )

	#Change in results_expected.log 'CHECKPATH' to check directory Path : for goil tests
	( cd .. ; cat ./functional/results_expected.log | sed -e "s/CHECKPATH/`pwd | sed 's_\/_\\\/_g'`/g" > ./backup.txt ; mv ./backup.txt ./functional/results_expected.log )
		
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
			
		#Adding AUTOSAR flag if autosar test sequence
		if [ "`echo ${i} | grep autosar`" != "" ]
		then
			autosar_flag="-a"
		else
			autosar_flag=""
		fi	
		
		#Go in the test sequence
		cd ./${i}
		
		#display running test sequence on the standard output for the user and in the log file to better understand failed tests
		echo "running $i" | tee -a "${result_path}results.log" 
		
		#remove the executable file in order to know if the make succeed.
		rm -rf ./${i} 
		
		#if Makefile doesn't exist -> do goil
		if ! `test -f Makefile`
		then
			#check if target's name is among arguments (default=libpcl)
			if [ "$1" = "" ]
			then	
				goil --target=libpcl --templates=../../../goil/templates/ -g defaultAppWorkstation.oil $autosar_flag 2>&1 | tee -a "${result_path}results.log"
			else 
				goil --target=$1 --templates=../../../goil/templates/ -g defaultAppWorkstation.oil $autosar_flag 2>&1 | tee -a "${result_path}results.log" 
			fi
		fi
		
		#if goil succeed (Makefile has been created) -> do make and execute file
		if `test -f Makefile`
		then
			make -s
			./${i} >> "${result_path}results.log"
		fi
		
		#Go out of the test sequence
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