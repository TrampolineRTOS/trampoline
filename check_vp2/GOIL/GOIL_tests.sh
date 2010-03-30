#!/bin/sh

######
# performs all the GOIL tests.
# args:
# (nothing): performs tests
# clean    : call make clean for each tests folders
#
# TODO : 
#		 delete testSequences file and do the loops for each directory (which contains defaultAppWorkstation.oil) #ls -d
######

GOILRESULT=`pwd`

if [ "$1" = "clean" ]
then
	for i in `cat GOIL_testSequences.txt`
	do
		#remove files built
		rm -rf ./${i}/target.cfg
		rm -rf ./${i}/vp_ipc_devices.c
		rm -rf ./${i}/vp_ipc_devices.h
	done

	#Delete results.log
	rm -rf GOIL_results.log
	
	#Change in results_expected.log the check directory path to 'CHECKPATH'.
	( cat ./GOIL_results_expected.log | sed -e "s/`pwd | sed 's_\/_\\\/_g'`/CHECKPATH/g" > ./backup.txt ; mv ./backup.txt ./GOIL_results_expected.log )
	
	#Delete embUnit's objects and librairy
	rm -rf ./../embUnit/*.o
	rm -rf ./../lib/libembUnit.a
	
else

	echo "Begin GOIL test procedure..."

	## Create an empty file
	> GOIL_results.log
	
	# Make embUnit if needed
	if ! `test -f ../lib/libembUnit.a`
	then
		echo "Make embunit"
		( cd ../embUnit ; make )
	fi
	
	#Change in results_expected.log 'CHECKPATH' to check directory Path : for goil tests
	( cat ./GOIL_results_expected.log | sed -e "s/CHECKPATH/`pwd | sed 's_\/_\\\/_g'`/g" > ./backup.txt ; mv ./backup.txt ./GOIL_results_expected.log )
		
	# Build and execute all the tests
	for i in `cat GOIL_testSequences.txt`
	do
	
		#Adding AUTOSAR flag if autosar test sequence
		if [ "`echo ${i} | grep autosar`" != "" ]
		then
			autosar_flag="-a"
		else
			autosar_flag=""
		fi	
		
#display running test sequence on the standard output for the user and in the log file to better understand failed tests
		echo "running $i" | tee -a GOIL_results.log 
		
		#jump in viper2 directory
		cd ../../viper2/
		
		#change sequence name in config.py file
		sed "s/SEQUENCE/${i}/g" config-tests.tmp.py | sed "s/functional/GOIL/g"  > config.py
		
		#compile
		python2.6 viper2.py --clean
		python2.6 viper2.py -g -c $autosar_flag >> ${GOILRESULT}/GOIL_results.log 
		
		#come back to the GOIL_tests.sh file
		cd $GOILRESULT
	
	done
	echo "GOIL tests done."

fi