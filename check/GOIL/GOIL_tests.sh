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
		
		#Go in the test sequence
		cd ./${i}
		
		#display running test sequence on the standard output for the user and in the log file to better understand failed tests
		echo "running $i" | tee -a ../GOIL_results.log 
		
		#remove the executable file in order to know if the make succeed.
		#rm -rf ./${i}_exe
		
		#check if previous target compiled is the same as the one wanted. If not, clean all and compile
		#if [ "`cat Make-rules | grep GOIL_TARGET | grep -c $1`" = "0" ]
		#then
		#	echo "target changed in ${i}, modifying target compilation by $1" 
		#	rm -rf ./build
		#	rm -rf ./${i}
		#	rm -rf ./Make-rules
		#	rm -rf ./Makefile
		#fi
		
		#if Makefile doesn't exist -> do goil
		#if ! [ -f Makefile ]
		#then
			goil --target=$1 --templates=../../../goil/templates/ -g ${i}.oil $autosar_flag 2>> ../GOIL_results.log 1>> ../GOIL_results.log
		#fi
		
		#if goil succeed (Makefile has been created) -> do make and execute file
		#if `test -f Makefile`
		#then
		#	make -s
		#	./${i} >> ../GOIL_results.log
		#fi
		
		#Go out of the test sequence
		cd ..
	
	done
	echo "GOIL tests done."

fi