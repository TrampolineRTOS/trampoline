#!/bin/sh

######
# performs all the functional tests.
# args:
# (nothing): performs tests
# clean    : call make clean for each tests folders
#
# TODO : 
#		 delete testSequences file and do the loops for each directory (which contains defaultAppWorkstation.oil) #ls -d
######

if [ "$1" = "clean" ]
then
	#Delete results.log
	rm -rf GOIL_results.log
	
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
		
		#Go in the test sequence
		cd ./${i}
		
		#display running test sequence on the standard output for the user and in the log file to better understand failed tests
		echo "running $i" | tee -a ../GOIL_results.log 
		
		goil --target=$1 --templates=../../../goil/templates/ -g ${i}.oil $autosar_flag 2>> ../GOIL_results.log 1>> ../GOIL_results.log
		
		#Go out of the test sequence
		cd ..
	
	done
	
	#replace pwd by CHECKPATH in GOIL_results.log
	( cat ./GOIL_results.log | sed -e "s/`pwd | sed 's_\/_\\\/_g'`/CHECKPATH/g" > ./backup.txt ; mv ./backup.txt ./GOIL_results.log )
	
	echo "GOIL tests done."

fi