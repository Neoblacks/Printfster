#!/bin/bash

padding="%-35s %-35s"

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

		#execute norminette on all files in the directory
		norminette srcs/ includes/| grep Error >norminette_error.txt
		#Write header ascii art
		cat assets/ascii_art.txt
		echo ""
		echo ""
		./a.out >my_output.txt

		printf "%-35s %-35s" "TEST" "MY OUTPUT"
		echo ""
		echo ""
		while read line1 && read line2 <&3; do
			if [ "$line1" = "$line2" ]; then
				#Skip CHAR TEST, STRING TEST, POINTER TEST, ADDRESS TEST, INT TEST, UNSIGNED INT TEST, HEXADECIMAL TEST, NULL line and print it in green
				if [ "$line1" = "CHAR TEST" ] || [ "$line1" = "STRING TEST" ] || [ "$line1" = "POINTER TEST" ] || [ "$line1" = "ADDRESS TEST" ] || [ "$line1" = "INT TEST" ] || [ "$line1" = "UNSIGNED
INT TEST" ] || [ "$line1" = "HEXA Lower TEST" ] || [ "$line1" = "HEXA Upper TEST" ] || [ "$line1" = "-----------" ] || [ "$line1" = "" ] || [ "$line1" = "U_INT TEST" ] || [ "$line1" = "MIX TEST" ] || [ "$line1" = "VALUE RETURN TEST" ]; then
					printf "$padding\n" "$line1" "$line2"
				else
					printf "$padding\e[32mOK\e[0m\n" "$line1" "$line2"
					sleep 0.02
				fi
			else
				printf "$padding\e[31mKO\e[0m\n" "$line1" "$line2"
				sleep 0.02
			fi
		#Diff between my_output.txt and output.txt
		done <output.txt 3<my_output.txt
		echo ""
		#if norminette_error.txt is empty, then there are no errors and execute the program
		if [ ! -s norminette_error.txt ]; then
			#ok on green
			printf "$padding\e[32mOK\e[0m \n" "Norminette:" ""
			echo ""
		else
			#Ko on red
			printf "$padding\e[31mKO\e[0m \n" "Norminette:" ""
			echo ""
		fi
	else #if the program didn't compile correctly
		echo -e "\e[31mCompilation error\e[0m Please type make to check the error"
	fi
elif [[ $1 == "-c" || $1 == "--check" ]]; then
	norminette srcs/ includes/ | grep Error >norminette_error.txt
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
#make fclean silently
make fclean > /dev/null
rm -f a.out my_output.txt output.txt norminette_error.txt
