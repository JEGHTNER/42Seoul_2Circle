# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:31:23 by jehelee           #+#    #+#              #
#    Updated: 2023/02/18 20:56:43 by jehelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex


INC_DIR		= ./lib/include/
LIB_DIR		= ./lib/
BN_DIR		= ./bonus/

SRCS = main.c
	   

#SRCS_BN = ${BN_DIR}commands_bonus.c ${BN_DIR}parse_utils_bonus.c ${BN_DIR}error_utils_bonus.c \
		  ${BN_DIR}stack_utils_bonus.c ${BN_DIR}check_sorted_bonus.c ${BN_DIR}checker.c
	   


OBJS = ${SRCS:%.c=%.o}
#OBJS_BN = ${SRCS_BN:%.c=%.o}

CC = cc
CFLAGS = -Wextra -Werror -Wall

#rules

	
all : ${NAME}

%.o : %.c
	$(CC) -c -o $@ $^ -g

# libs:
# 	make -C ./lib/

${NAME} : ${OBJS}
	$(CC) -o $(NAME) ${OBJS} -L. -l_jehelee


clean	:
	# make -C ./lib/ clean
	rm -rf $(OBJS)
#	rm -rf $(OBJS_BN)

fclean	: 
	# make -C ./lib/ fclean
	rm -rf $(OBJS)
#	rm -rf $(OBJS_BN)
	rm -rf	$(NAME)
#	rm -rf  $(NAME_BN)

re		: fclean all

#bonus: all ${NAME_BN}

#${NAME_BN} : ${OBJS_BN}
#	$(CC) $(CFLAGS) -o $(NAME_BN) ${OBJS_BN} -I ${INC_DIR} -L ${LIB_DIR} -l_jehelee

.PHONY: all libs clean fclean re bonus