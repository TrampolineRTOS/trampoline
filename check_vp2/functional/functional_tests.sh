#!/bin/sh

######
# performs all the functional tests.
# args:
# (nothing): performs tests
# clean    : call make clean for each tests folders
# {goil's target} : if Makefile hasn't been created yet, a 'goil' command is needed with the target name (default=libpcl)
#
# TODO : 
#		 delete testSequences file and do the loops for each directory (which contains ${i}.oil) #ls -d
######

FUNCTIONALCHECK=`pwd`

if [ "$1" = "clean" ]
then
	for i in `cat functional_testSequences.txt`
	do
		echo "cleaning $i"

		rm -rf ${i}/${i}.desc
		
		cd ../../viper2/
		
		#change sequence name in config.py file
		sed "s/SEQUENCE/${i}/g" config-tests.tmp.py > config.py
		
		#clean
		python2.6 viper2.py --clean
		
		#come back to the functional_tests.sh file
		cd $FUNCTIONALCHECK

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
		
	# Clean Debug flag
	cd ../../viper2/
	sed "s/SEQUENCE/tasks_s1_full/g" config-tests.tmp.py > config.py
	export CFLAGS=
	python2.6 viper2.py --clean
	python2.6 viper2.py -g -c
	cd $FUNCTIONALCHECK
		
	# Build and execute all the tests
	for i in `cat functional_testSequences.txt` #tasks_s1_full tasks_s1_non tasks_s2 tasks_s3 tasks_s4 #
	do
		#Adding AUTOSAR flag if autosar test sequence
		if [ "`echo ${i} | grep autosar`" != "" ]
		then
			autosar_flag="-a"
		else
			autosar_flag=""
		fi	
		
		#display running test sequence on the standard output for the user and in the log file to better understand failed tests
		echo "running $i" | tee -a functional_results.log 
		
		#jump in viper2 directory
		cd ../../viper2/
		
		#change sequence name in config.py file
		sed "s/SEQUENCE/${i}/g" config-tests.tmp.py > config.py
		
		#compile
		python2.6 viper2.py -g -c -nodep $autosar_flag
		
		#launch viper2 and Trampoline
		python2.6 viper2.py >> ${FUNCTIONALCHECK}/functional_results.log
		
		#come back to the functional_tests.sh file
		cd $FUNCTIONALCHECK
			
	done
	echo "Functional tests done."

fi