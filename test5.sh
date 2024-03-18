# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test5.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 15:53:08 by ssottori          #+#    #+#              #
#    Updated: 2024/03/18 16:20:40 by ssottori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

for i in $(seq 1 50); do 
    ARG=$(seq 0 5 | shuf -n 5);
    echo "=============="; 
    echo "Test $i:";
    echo "$ARG"; 
    operations=$(./push_swap $ARG | wc -l); 
    result=$(./push_swap $ARG | ./checker_linux $ARG);
    if [ $operations -gt 12 ]; then
        echo -e "Moves: $operations \033[0;31mKO\033[0m";
    elif [ $operations -lt 12 ]; then
	echo -e "Moves: $operations \033[0;32mOK\033[0m"; 
    fi
    echo "Checker: $result";
done
