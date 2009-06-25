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
	for i in `cat functional_testSequences.txt`
	do
		#remove make-rules, makefiles, defaultAppWorkstation/, build/, embUnit/*.o and lib/libembUnit.a
		rm -rf ./${i}/build
		rm -rf ./${i}/defaultAppWorkstation
		rm -rf ./${i}/Make-rules
		rm -rf ./${i}/Makefile
		rm -rf ./${i}/${i}
	done

	#Delete results.log
	rm -rf functional_results.log
	
	#Delete embUnit's objects and librairy
	rm -rf ./../embUnit/*.o
	rm -rf ./../lib/libembUnit.a
	
else

	echo "Begin functional test procedure..."

	## Create an empty file
	> functional_results.log
	
	# Make embUnit if needed
	if ! `test -f ../lib/libembUnit.a`
	then
		echo "Make embunit"
		( cd ../embUnit ; make )
	fi
		
	# Build and execute all the tests
	for i in `cat functional_testSequences.txt`
	do
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
		echo "running $i" | tee -a ../functional_results.log 
		
		#remove the executable file in order to know if the make succeed.
		rm -rf ./${i} 

		#if Makefile doesn't exist -> do goil
		if ! `test -f Makefile`
		then
			#check if target's name is among arguments (default=libpcl). If "no_results" is sent by test.sh, do goil with libpcl.
			if [ "$1" = "" ] || [ "$1" = "no_results" ]
			then	
				goil --target=posix --templates=../../../goil/templates/ -g defaultAppWorkstation.oil $autosar_flag 2>&1 | tee -a ../functional_results.log
			else 
				goil --target=$1 --templates=../../../goil/templates/ -g defaultAppWorkstation.oil $autosar_flag 2>&1 | tee -a ../functional_results.log
			fi
		fi
		
		#if goil succeed (Makefile has been created) -> do make and execute file
		if `test -f Makefile`
		then
			make -s
			./${i} >> ../functional_results.log
		fi
		
		#Go out of the test sequence
		cd ..
	
	done
	echo "Functional tests done."

	if [ "$1" != "no_results" ] && [ "$2" != "no_results" ]
	then
		#Compare results
		echo "Compare functional results with the expected ones..."
		if [ `diff functional_results_expected.log functional_results.log | wc -l` -eq 0 ]
		then
			echo "functional tests Succeed!!"
		else
			echo "functional tests Failed! Results are stored in `pwd`/functional_results.log"
		fi
	fi

fi