# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:29:37 by ssottori          #+#    #+#              #
#    Updated: 2024/02/09 23:34:13 by ssottori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

CCFLAGS = cc -Wall -Wextra -Werror -g
RM = rm -rf
NAME = push_swap

SRC_DIR = src
OBJ_DIR = obj
LIBFT_D = libft
INC_DIR = push_swap.h

SRCS = main.c \

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_D)/libft.a
LIBS = -L$(LIBFT_D) -lft

HEADERS = -I$(INC_DIR) -I$(LIBFT_D)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_D)

$(NAME): $(OBJS)
	$(CCFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)
	echo "[$(GREEN)PUSH_SWAP$(NC)] Building $@..."

#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h
%.o: %.c
	@mkdir -p $(OBJ_DIR)
	echo "[$(GREEN)PUSH_SWAP$(NC)] Compiling $< --> $@"
	@cc -Wall -Wextra -Werror -g $(HEADERS) -c $< -o $@

clean:
	@echo "[$(RED)PUSH_SWAP$(NC)] Cleaning object files..."
	$(MAKE) -C $(LIBFT_D) clean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "[$(RED)PUSH_SWAP$(NC)] Cleaning executable file..."
	$(MAKE) -C $(LIBFT_D) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
