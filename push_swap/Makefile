# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:31:23 by jehelee           #+#    #+#              #
#    Updated: 2023/02/12 13:47:42 by jehelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BN = checker

SRCS = main.c commands.c sort.c sort_util_find_max_min.c \
	   push_swap.c parse_utils.c error_utils.c stack_utils.c \
	   reverse_sort.c trim_cmd.c cmd_utils.c check_sorted.c \
	   quick_sort.c sort_3.c sort_3_utils.c rev_sort_utils.c \
	   rev_sort_utils2.c trim_cmd_utils.c
	   

SRCS_BN = commands_bonus.c parse_utils.c error_utils.c stack_utils.c \
	   check_sorted.c checker.c
	   
INC_DIR		= ./lib/include/
LIB_DIR		= ./lib/
BN_DIR		= ./bonus/

OBJS = ${SRCS:%.c=%.o}
OBJS_BN = ${SRCS_BN:%.c=%.o}

CC = cc
CFLAGS = -Wextra -Werror -Wall

#rules

all : libs ${NAME}

libs:
	make -C ./lib/

${NAME} : ${OBJS}
	$(CC) $(CFLAGS) -o $(NAME) ${OBJS} -I ${INC_DIR} -L ${LIB_DIR} -l_jehelee

clean	:
	make -C ./lib/ clean
	rm -rf $(OBJS)
	rm -rf $(OBJS_BN)

fclean	: 
	make -C ./lib/ fclean
	rm -rf $(OBJS)
	rm -rf $(OBJS_BN)
	rm -rf	$(NAME)
	rm -rf  $(NAME_BN)

re		: fclean all

bonus: all ${NAME_BN}

${NAME_BN} : ${OBJS_BN}
	$(CC) $(CFLAGS) -o $(NAME_BN) ${OBJS_BN} -I ${INC_DIR} -L ${LIB_DIR} -l_jehelee

.PHONY: all libs clean fclean re bonus