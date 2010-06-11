#!/bin/sh

plan=0
proc=0
impl=0
oil=0

#check if user wants to compile just the plan or the procedure
if [ "$1" = "plan" ] 
then
	plan=1
elif [ "$1" = "proc" ] 
then
	proc=1
elif [ "$1" = "impl" ] 
then
	impl=1
elif [ "$1" = "oil" ] 
then
	oil=1
elif [ "$1" = "clean" ] 
then
	echo "Cleaning temporary TeX files..."
	#Trash Aux Files
	rm Trampolinetest*.aux
	rm Trampolinetest*.blg
	rm Trampolinetest*.log
	rm Trampolinetest*.out
	rm Trampolinetest*.toc
	
	rm Trampolinetest*.bbl
	rm Trampolinetest*.ent
	rm Trampolinetest*.gz
	
elif [ "$1" = "cleanall" ] 
then
	echo "Cleaning all temporary files..."
	#Trash Aux Files
	rm Trampolinetest*.aux
	rm Trampolinetest*.blg
	rm Trampolinetest*.log
	rm Trampolinetest*.out
	rm Trampolinetest*.toc
	
	rm Trampolinetest*.bbl
	rm Trampolinetest*.ent
	rm Trampolinetest*.gz
	
	rm OIL_to_TXT/*.txt
else
	plan=1
	proc=1
	impl=1
	oil=1
fi

#generate sequences description files from OIL files
if [ $oil = 1 ]
then
	cd OIL_to_TXT
	./OIL_to_TXT.sh
	cd ..
fi

#compile what the user want (or all)
if [ $plan = 1 ]
then
	echo "Generating Trampolinetestplan10.pdf..."
	pdflatex Trampolinetestplan10
	bibtex Trampolinetestplan10
	pdflatex Trampolinetestplan10
	pdflatex Trampolinetestplan10
fi

if [ $proc = 1 ]
then
	echo "Generating Trampolinetestproc10.pdf..."
	pdflatex Trampolinetestproc10
	bibtex Trampolinetestproc10
	pdflatex Trampolinetestproc10
	pdflatex Trampolinetestproc10
fi

if [ $impl = 1 ]
then
	echo "Generating Trampolinetestimplementation10.pdf..."
	pdflatex Trampolinetestimplementation10
	bibtex Trampolinetestimplementation10
	pdflatex Trampolinetestimplementation10
	pdflatex Trampolinetestimplementation10
fi

