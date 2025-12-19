#!/bin/bash

red='\033[0;31m'
green='\033[0;32m'
nc='\033[0m' 

function utest( ){

    if [ "$1" == "$2" ]
    then
		echo -ne "$green pass $nc"
    else
		echo -ne "$red FAIL $nc" 
    	echo -e "\t  Result: '$1'"
    	echo -e "\tExpected: '$2'"
    fi
    echo -ne "\t "
    echo "$3"
}

if [ -f part1.cpp ]; then

	echo -e "PART 1\n   -- compile --    \n"
		
	g++ -o temp part1.cpp

	if [ -e temp ];then
		echo -e "$green pass $nc compilation success"
		
		echo -e "\n   -- run --   "

        cmd='cat input61.txt | ./temp'
		res=$(cat input61.txt | ./temp 2>&1 | tr "\n" " " | sed 's/ *$//g')
		expect="1 2 3 4 12 20 21 22 23 24 29 30"
		utest "$res" "$expect" "($cmd)" 
		
		rm temp
	else
		echo -e "$red FAIL $nc compilation error"
	fi 

	
	echo -e "-------------------------------------------------------------------------"
fi

if [ -f part2.cpp ]; then

	echo -e "PART 2\n   -- compile --    \n"
		
	g++ -o temp part2.cpp

	if [ -e temp ];then
		echo -e "$green pass $nc compilation success"
		
		echo -e "\n   -- run --   "

		start=`date +%s`
		
        cmd='cat input61.txt | ./temp'
		res=$(cat input61.txt | ./temp 2>&1 | tr "\n" " " | sed 's/ *$//g')
		expect="Midshipman arrived at 1 Midshipman arrived at 2 Midshipman arrived at 3 Midshipman arrived at 4 Midshipman arrived at 12 Midshipman arrived at 20 Midshipman arrived at 21 Midshipman arrived at 22 Midshipman arrived at 23 Midshipman arrived at 24 Midshipman arrived at 29 Midshipman arrived at 30"
		utest "$res" "$expect" "($cmd)" 
		
		end=`date +%s`
		runtime=$((end-start))
		if [ "$runtime" -lt 28 ]; then
			echo -e "$red FAIL $nc program too fast (expected ~30 seconds, actual $runtime)"
		elif [ "$runtime" -gt 32 ]; then
			echo -e "$red FAIL $nc program too slow (expected ~30 seconds, actual $runtime)"
		else
			echo -e "$green pass $nc program running time good ($runtime sec)"
		fi
		rm temp
	else
		echo -e "$red FAIL $nc compilation error"
	fi 

	
	echo -e "-------------------------------------------------------------------------"
fi

if [ -f part3.cpp ]; then

	echo -e "PART 3\n   -- compile --    \n"
		
	g++ -o temp part3.cpp

	if [ -e temp ];then
		echo -e "$green pass $nc compilation success"
		
		echo -e "\n   -- run --   "
		
		start=`date +%s`

        cmd='cat input62.txt | ./temp'
		res=$(cat input62.txt | ./temp 2>&1 | tr "\n" " " | sed 's/ *$//g')
		expect="Midshipman arrived at 1 with duration 4 Midshipman arrived at 2 with duration 4 Midshipman arrived at 3 with duration 2 Midshipman arrived at 4 with duration 2 Midshipman arrived at 12 with duration 3 Midshipman arrived at 20 with duration 2 Midshipman arrived at 21 with duration 4 Midshipman arrived at 22 with duration 3 Midshipman arrived at 23 with duration 2 Midshipman arrived at 24 with duration 4 Midshipman arrived at 29 with duration 2 Midshipman arrived at 30 with duration 2"
		utest "$res" "$expect" "($cmd)" 
		
		end=`date +%s`
		runtime=$((end-start))
		if [ "$runtime" -lt 28 ]; then
			echo -e "$red FAIL $nc program too fast (expected ~30 seconds, actual $runtime)"
		elif [ "$runtime" -gt 32 ]; then
			echo -e "$red FAIL $nc program too slow (expected ~30 seconds, actual $runtime)"
		else
			echo -e "$green pass $nc program running time good ($runtime sec)"
		fi
		
		rm temp
	else
		echo -e "$red FAIL $nc compilation error"
	fi 

	
	echo -e "-------------------------------------------------------------------------"
fi

if [ -f part4.cpp ]; then

	echo -e "PART 4\n   -- compile --    \n"
		
	g++ -o temp part4.cpp
	
	if [ -e temp ];then
		echo -e "$green pass $nc compilation success"
		
		echo -e "\n   -- run --   "

		start=`date +%s`
		
        cmd='cat input62.txt | ./temp'
		res=$(cat input62.txt | ./temp 2>&1 | tr "\n" " " | sed 's/ *$//g')
		expect="Midshipman arrived at 1 and waited 0 Midshipman arrived at 2 and waited 3 Midshipman arrived at 3 and waited 6 Midshipman arrived at 4 and waited 7 Midshipman arrived at 12 and waited 1 Midshipman arrived at 20 and waited 0 Midshipman arrived at 21 and waited 1 Midshipman arrived at 22 and waited 4 Midshipman arrived at 23 and waited 6 Midshipman arrived at 24 and waited 7 Midshipman arrived at 29 and waited 6 Midshipman arrived at 30 and waited 7"
		utest "$res" "$expect" "($cmd)" 
		
		end=`date +%s`
		runtime=$((end-start))
		if [ "$runtime" -lt 36 ]; then
			echo -e "$red FAIL $nc program too fast (expected ~38 seconds, actual $runtime)"
		elif [ "$runtime" -gt 40 ]; then
			echo -e "$red FAIL $nc program too slow (expected ~38 seconds, actual $runtime)"
		else
			echo -e "$green pass $nc program running time good ($runtime sec)"
		fi
		
		rm temp
	else
		echo -e "$red FAIL $nc compilation error"
	fi 

	
	echo -e "-------------------------------------------------------------------------"
fi


