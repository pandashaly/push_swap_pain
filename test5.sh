# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test5.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 15:53:08 by ssottori          #+#    #+#              #
#    Updated: 2024/03/18 18:49:40 by ssottori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

for i in $(seq 1 20); do 
    ARG=$(seq 1 5 | shuf -n 5);
    echo "=============="; 
    echo "Test $i:";
    echo "$ARG"; 
    operations=$(./push_swap $ARG | wc -l); 
    result=$(./push_swap $ARG | ./checker_linux $ARG);
    moves=$(./push_swap $ARG);
    if [ $operations -gt 12 ]; then
        echo -e "Moves: $operations \033[0;31mKO\033[0m";
    elif [ $operations -lt 13 ]; then
	echo -e "Moves: $operations \033[0;32mOK\033[0m";
    else
    	echo " $operations";	    
    fi
    if [ $result == "OK" ]; then
    	echo -e "Checker: \033[0;32m$result\033[0m";
    else
	echo -e "Checker: \033[0;31m$result\033[0m";
    fi
    echo "$moves";
done
