#!/bin/bash
# Program: Random system menu
# Aruthor: Rist
# Email: www10177@gmail.com

#To output data by character 
out(){
	s=$1
	time=$2
	for ((i=0; i<${#s} ; i++)) ; do 
		echo -n "${s:i:1}"
		sleep $time 
	done
	echo
}

#to output intro quickly
if [ "$1" == "1" ]; then
	time=0
else
	time=0.05
fi

#intro
out Welcome\ \to\ \Random\ \System. $time 
out Don\'\t\ \know\ \what\ \to\ \eat? $time
out Just\ \use\ \the\ \system\ \to\ \decide\ \it\ \for\ \you. $time
while [ "$ins" != "4" ] 
do
	echo "------------------------------------------------------------"
	echo 'Instruction List:'
	echo '1: Create list '
	echo '2: Browse lists that were already created;'
	echo '3: Enter random mode ( choose what to eat today)'
	echo '4: Exit program' 

	read -p " Please Enter Instruction... " ins

	#open other application to finish the job
	if [ "$ins" == "1" ]; then
		echo 'enter1'
	elif [ "$ins" == "2" ]; then
		echo 'enter2'	
	elif [ "$ins" == "3" ]; then
		echo 'enter3'	
	elif [ "$ins" == "4" ]; then
		exit 
	else
		echo 'Please Enter Available Instruction...'
		sleep 1
	fi
done
