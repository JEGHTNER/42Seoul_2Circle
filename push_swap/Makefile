# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:31:23 by jehelee           #+#    #+#              #
#    Updated: 2023/02/08 16:37:15 by jehelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c commands.c sort.c sort_util_find_max_min.c \
	   push_swap.c parse_utils.c error_utils.c stack_utils.c \
	   reverse_sort.c trim_cmd.c cmd_utils.c check_sorted.c
	   

INC_DIR		= ./lib/include/
LIB_DIR		= ./lib/
MLX_DIR		= ./mlx/

OBJS = ${SRCS:%.c=%.o}


CC = cc
CFLAGS = -Wextra -Werror -Wall

#rules

all : libs ${NAME}

libs:
	make -C ./lib/

%.o : %.c
	$(CC) -g -fsanitize=address $(CFLAGS) -I $(INC_DIR) -c -o $@ $<

${NAME} : ${OBJS}
	$(CC) -g -fsanitize=address -o $(NAME) ${OBJS} -L ${LIB_DIR} -l_jehelee

clean	:
	make -C ./lib/ clean
	rm -rf $(OBJS)

fclean	: clean
	rm -rf  ./lib/lib_jehelee.a
	rm -rf	$(NAME)

re		: fclean all

phony: all libs clean fclean re