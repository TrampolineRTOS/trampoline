#!/bin/sh

echo "Generate sequence description files from OIL files..."

if [ "$1" = "-f" ]
then
	force=1
else
	force=0
fi

for first_path in "GOIL" "functional"
do
	echo "${first_path} tests sequences"

	PAT="../../../tests/$first_path/"

	for name in `cat ${PAT}${first_path}_testSequences.txt`
	do

		bracket=1
		full=0
		end=0
		date_oil=0
		date_file=0
		appmode_passed=0
		go_to_copy_the_oil_file=0

		#if full, do the txt file, otherwise, do nothing
		if [ "`echo $name | grep -c non`" = "0" ]
		then
			if [ "`echo $name | grep -c full`" != "0" ]
			then
				full=1
				file=`echo $name | sed -e "s/_full//g"`
				#echo "full - modified : $name"
			else
				#echo "normal : $name"
				file=${name}
			fi	#[ "`echo $name | grep -c full`" != "0" ]

			#if no modifications since last time, don't create again the file
			if ( `test -f ${file}.txt` )
			then
				#echo "file exists here `pwd`"
				date_oil=`stat -s ${PAT}${name}/${name}.oil | awk '{print $10}' | awk -F"=" '{print $2}'`
				date_file=`stat -s ${file}.txt | awk '{print $10}' | awk -F"=" '{print $2}'`
			#else
				#echo "file doesn't exist here `pwd`"
			fi

			if [ $date_oil -gt $date_file ] || ( ! `test -f ${file}.txt` ) || [ "$force" = "1" ]
			then
				#create a new file
				> ${file}.txt

				#copy in the old file the paragraph needed
				old_IFS=$IFS
				IFS=$'\n'     # nouveau séparateur de champ, le caractère fin de ligne
				line_number=0
				for ligne in $(cat ${PAT}${name}/${name}.oil)
				do
					line_number=`expr $line_number + 1`
					#echo "line_number:$line_number"

					#if TASK has elapsed, count the { and } and copy until } has one more than {
					if [ "`echo $go_to_copy_the_oil_file`" = "1" ]
					then
						open_bracket_number=`echo $ligne | grep -c "{"`
						#echo "open_bracket_number=$open_bracket_number"
						bracket=`expr $bracket + $open_bracket_number`
						close_bracket_number=`echo $ligne | grep -c "}"`
						#echo "close_bracket_number=$close_bracket_number"
						bracket=`expr $bracket - $close_bracket_number`
						#echo "bracket=$bracket"
						if [ "`echo $bracket`" != "-1" ]
						then
							echo "$ligne" >> ${file}.txt
						else
							if [ "`echo $end`" = "0" ]
							then
								end=1
								echo "${PAT}${name} - added"
								if [ "`echo $full`" = "1" ]
								then
									#if full replace "FULL" by "NON, FULL"
									#echo "FULL -> NON, FULL"
									cat ${file}.txt | sed -e "s_FULL_NON,FULL_g" > ${file_backup}.txt
									mv ${file_backup}.txt ${file}.txt
								fi
							fi
						fi
					else
						if [ "`echo $ligne | grep -c 'APPMODE '`" != "0" ]
						then
							appmode_passed=1
							#echo "APPMODE appears at line:$line_number"
						fi

						if [ "`echo $ligne | grep -c 'TASK '`" != "0" ]
						then
						    #echo "TASK appears at line:$line_number - check if APPMODE appeared before or not. If yes set copy to 2 (or another flag)"
						    if [ "`echo $appmode_passed`" = "1" ]
						    then
						    	go_to_copy_the_oil_file=1
								echo "$ligne" >> ${file}.txt
							fi #[ "`echo $appmode_passed`" = "1" ]
						fi #[ "`echo $ligne | grep -c 'TASK '`" != "0" ]
					fi
				done
				IFS=$old_IFS

			fi # [ $date_oil -gt $date_file ] || ( ! `test -f ${file}.txt` )

		fi # [ "`echo $name | grep -c non`" = "0" ]

	done

done
