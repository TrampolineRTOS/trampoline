#!/bin/sh

######
# performs all the functional tests.
# args:
# (nothing): performs tests
# clean    : call make clean for each tests folders
#
# TODO : 
#		 delete testSequences file and do the loops for each directory (which contains ${i}.oil) #ls -d
######

if [ "$1" = "clean" ]
then
	for i in `cat functional_testSequences.txt`
	do
		#remove make-rules, makefiles, ${i}/, build/ and exe file
		rm -rf ./${i}/build
		rm -rf ./${i}/${i}
		rm -rf ./${i}/Makefile
		rm -rf ./${i}/${i}_exe
		rm -rf ./${i}/goil.log
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
                ( cd ../embUnit ; make CC=/usr/local/bin/gcc )
	fi
		
	# Build and execute all the tests
	for i in `cat functional_testSequences.txt`
	do
		withmp="`echo ${i} | grep -c mp`"
		withtp="`echo ${i} | grep -c tp`"
		if [ $withmp -ne 1 ] && [ $withtp -ne 1 ] 
		then
		
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
			rm -rf ./${i}_exe
	
			#check if previous target compiled is the same as the one wanted. If not, clean all and compile
			if [ -f Make-rules ] && [ "`cat Make-rules | grep GOIL_TARGET | grep -c $1`" = "0" ]
			then
				echo "(previous target different than $1 -> Recompilation...)" 
				rm -rf ./build
				rm -rf ./${i}
				rm -rf ./Make-rules
				rm -rf ./Makefile
			fi
			
			#if Makefile doesn't exist -> do goil
			if ! [ -f Makefile ]
			then
				goil --target=$1 --templates=../../../goil/templates/ -g ${i}.oil $autosar_flag 2>&1 | tee -a ../functional_results.log
			fi
			
			#if goil succeed (Makefile has been created) -> do make and execute file
			if `test -f Makefile`
			then
				make -s
				./${i}_exe >> ../functional_results.log
			fi
			
			#Go out of the test sequence
			cd ..
		else
			echo "$i is not tested because it's a memory or timing protection test"
		fi
	
	done
	echo "Functional tests done."

fi


