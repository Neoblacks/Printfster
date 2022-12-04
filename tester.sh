#!/bin/bash

if [[ $1 == "-h" || $1 == "--help" ]]; then
	echo "Options:"
	echo "-h, --help		display this help and exit"
	echo "-b, --bonus		display bonus part and exit"
	echo "-m, --mandatory		display mandatory part and exit"
	echo "-c, --check		check norminette and exit"
elif [[ $1 == "-b" || $1 == "--bonus" ]]; then

	echo "Bonus part:"
elif [[ $1 == "-m" || $1 == "--mandatory" || $1 == "" ]]; then
	clear
	make re
	clear
	#Check if libftprintf.a exists else make
	if [ ! -f libftprintf.a ]; then
		make
		clear
	fi
	#compile the program

	cc -w main.c libftprintf.a -Wall -Wextra -Werror

	#Check if the program compiled correctly
	if [ $? -eq 0 ]; then
		rm my_input.txt
		touch my_input.txt

		#execute norminette on all files in the directory and don't print the output
		norminette | grep Error >norminette_error.txt
		#Write header ascii art to file and print it
		# echo -e "\033[31m           0000\033[0m_____________0000________0000000000000000__000000000000000000+\n\033[31m         00000000\033[0m_________00000000______000000000000000__0000000000000000000+\n\033[31m        000\033[0m____000_______000____000_____000_______0000__00______0+\n\033[31m       000\033[0m______000_____000______000_____________0000___00______0+\n\033[31m      0000\033[0m______0000___0000______0000___________0000_____0_____0+\n\033[31m      0000\033[0m______0000___0000______0000__________0000___________0+\n\033[31m      0000\033[0m______0000___0000______0000_________000___0000000000+\n\033[31m      0000\033[0m______0000___0000______0000________0000+\n\033[31m       000\033[0m______000_____000______000________0000+\n\033[31m        000\033[0m____000_______000____000_______00000+\n\033[31m         00000000\033[0m_________00000000_______0000000+\n\033[31m           0000\033[0m_____________0000________000000007;"
		# echo "Printf Tester by: amugnier"
		cat ascii_art.txt
		echo ""
		echo ""
		./a.out >test_input.txt

		printf "OUTPUT "
		printf "%-43s MY OUTPUT\n"
		echo ""
		while read line1 && read line2 <&3; do
			if [ "$line1" = "$line2" ]; then
				#Center the ok or ko in right column even whitespace and print what i want test and what it should be and color on green OUTPUT and red MY OUTPUT
				#Skip CHAR TEST, STRING TEST, POINTER TEST, ADDRESS TEST, INT TEST, UNSIGNED INT TEST, HEXADECIMAL TEST, NULL line and print it in green
				if [ "$line1" = "CHAR TEST" ] || [ "$line1" = "STRING TEST" ] || [ "$line1" = "POINTER TEST" ] || [ "$line1" = "ADDRESS TEST" ] || [ "$line1" = "INT TEST" ] || [ "$line1" = "UNSIGNED
INT TEST" ] || [ "$line1" = "HEXA Lower TEST" ] || [ "$line1" = "HEXA Upper TEST" ] || [ "$line1" = "-----------" ] || [ "$line1" = "" ]; then
					printf "%-50s %-50s\n" "$line1" "$line2"
				else
					printf "%-50s %-50s\e[32mOK\e[0m\n" "$line1" "$line2"
					sleep 0.02
				fi
			else
				printf "%-50s %-50s\e[31mKO\e[0m\n" "$line1" "$line2"
				sleep 0.02
			fi

		done <output.txt 3<test_input.txt
		echo ""
		#if norminette_error.txt is empty, then there are no errors and execute the program
		if [ ! -s norminette_error.txt ]; then
			#write norminette in center of screen
			printf "%-50s %-50s\e[32mOK\e[0m \n" "Norminette:" ""
			echo ""
			# ./a.out >test_input.txt
		else
			#write norminette in green and print ko in red
			printf "%-50s %-50s\e[31mKO\e[0m \n" "Norminette:" ""
			# printf "%-50s %-50s\e[31mKO\e[0m \n" "Norminette:" ""
			echo ""
			# ./a.out >test_input.txt
		fi
	else #if the program didn't compile correctly
		echo -e "\e[31mCompilation error\e[0m"
	fi
elif [[ $1 == "-c" || $1 == "--check" ]]; then
	norminette | grep Error >norminette_error.txt
	#if norminette_error.txt is empty, then there are no errors and execute the program
	if [ ! -s norminette_error.txt ]; then
		#write norminette OK on green
		echo -e "\e[32mNorminette OK\e[0m \n"
	else
		#write norminette KO on red
		echo -e "\e[31mNorminette KO\e[0m \n"
		cat norminette_error.txt
	fi
else

	echo "Error: option doesn't exist"
fi
