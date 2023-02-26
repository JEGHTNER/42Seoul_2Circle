# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:31:23 by jehelee           #+#    #+#              #
#    Updated: 2023/02/26 22:35:53 by jehelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BN = pipex_bonus

INC_DIR		= ./lib/include/
LIB_DIR		= ./lib/
BN_DIR		= ./bonus/
SRCS_DIR	= ./src/

SRCS = error_utils.c error_utils2.c fork_utils.c free_utils.c init_pipex.c \
		main.c ft_split_pipex_utils.c ft_split_pipex_utils2.c ft_split_pipex_utils_awk.c  \
		ft_split_pipex.c 

	   

#SRCS_BN = error_utils.c error_utils2.c fork_utils.c free_utils.c init_pipex.c \
		main.c ft_split_pipex_utils.c ft_split_pipex_utils2.c ft_split_pipex_utils_awk.c  \
		ft_split_pipex.c 

OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))
OBJS_BN = $(addprefix $(BN_DIR)/, $(SRCS_BN:.c=.o))
CC = cc
CFLAGS = -Wextra -Werror -Wall

#rules

	
all : libs ${NAME}

%.o : %.c
	$(CC) -c -o $@ $^ -g

libs:
	make -C ./lib/

${NAME} : ${OBJS}
	$(CC) -o $(NAME) ${OBJS} -L. -l_jehelee -g


clean	:
	make -C ./lib/ clean
	rm -rf $(OBJS)
#	rm -rf $(OBJS_BN)

fclean	: 
	make -C ./lib/ fclean
	rm -rf $(OBJS)
#	rm -rf $(OBJS_BN)
	rm -rf	$(NAME)
#	rm -rf  $(NAME_BN)

re		: fclean all

#bonus: all ${NAME_BN}

#${NAME_BN} : ${OBJS_BN}
#	$(CC) $(CFLAGS) -o $(NAME_BN) ${OBJS_BN} -I ${INC_DIR} -L ${LIB_DIR} -l_jehelee

.PHONY: all libs clean fclean re bonus