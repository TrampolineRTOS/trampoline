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
		#remove make-rules, makefiles, defaultAppWorkstation/ and build/
		rm -rf ./${i}/build
		rm -rf ./${i}/defaultAppWorkstation
		rm -rf ./${i}/Make-rules
		rm -rf ./${i}/Makefile
		rm -rf ./${i}/${i}
	done
	rm -rf results.log
else

	echo "Begin internal functional test procedure..."

	## Create an empty file
	> results.log

	# Build and execute all the tests
	for i in `cat testSequences.txt`
	do
		cd ./${i}
		rm -rf ./${i} #remove the executable file in order to know if the make succeed.
		echo "running $i"
		#if Makefile doesn't exist -> do goil
		if ! `test -f Makefile`
		then
			#check if target's name is among arguments (default=libpcl)
			if [ "$1" = "" ]
			then	
				goil --target=libpcl --templates=../../../goil/templates/ -g defaultAppWorkstation.oil
			else 
				goil --target=$1 --templates=../../../goil/templates/ -g defaultAppWorkstation.oil	
			fi
		fi
		
		make -s
		./${i} >> ../results.log
		cd ..
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