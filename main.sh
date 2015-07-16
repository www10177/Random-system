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
		read -s -t $time clean &> /dev/null
		#if [[ $?  == 0 ]]; then
			#sleep $time

		#fi
	done
	echo 
} 
#to output intro quickly
#read -p "Input Anything RIGHT NOW to skip Intro...  " -t 1.5 intro
#echo
if [ ! -z "$1"  ]; then
	time=0
else
	time=0.05
fi

#intro
out Welcome\ \to\ \Random\ \System.\ \v0.1 $time 
out Don\'\t\ \know\ \what\ \to\ \eat? $time
out Just\ \use\ \the\ \system\ \to\ \decide\ \it\ \for\ \you. $time
echo "------------------------------------------------------------"
echo 'Instruction List:'
echo '1: Create list '
echo '2: Browse or add item in lists that were already created;'
echo '3: Enter random mode ( choose what to eat today)'
echo '4: Exit program'
echo "------------------------------------------------------------"

#selection
while [ "$ins" != "4" ] 
do
	read -p " Please Enter Instruction... " ins

	#open other application to finish the job
	if [ "$ins" == "1" ]; then
		out Enter\ \Create\ \List\ \System\ \... $time
		./Create out Exit\ \Create\ \List\ \System\ \and\ \Go\ \Back\ \to\ \Menu... $time
	elif [ "$ins" == "2" ]; then
		out Enter\ \Browse\ \List\ \System\ \... $time
		./Browse
		out Exit\ \Browse\ \List\ \System\ \and\ \Go\ \Back\ \to\ \Menu... $time
	elif [ "$ins" == "3" ]; then
		out Enter\ \Random\ \List\ \System\ \... $time
		./Random
		out Exit\ \Random\ \List\ \System\ \and\ \Go\ \Back\ \to\ \Menu... $time
	elif [ "$ins" == "4" ]; then
		exit 0
	else
		echo 'Please Enter Available Instruction...'
		sleep 1
	fi
done
exit 0  
