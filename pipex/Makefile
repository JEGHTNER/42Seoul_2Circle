# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:31:23 by jehelee           #+#    #+#              #
#    Updated: 2023/03/04 19:22:03 by jehelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

INC_DIR		= ./lib/include/
LIB_DIR		= ./lib/
BN_DIR		= ./bonus/
SRCS_DIR	= ./src/

SRCS = error_utils.c error_utils2.c fork_utils2.c fork_utils.c  \
		free_utils.c init_pipex.c main.c ft_split_pipex_utils.c \
		ft_split_pipex_utils2.c ft_split_pipex_utils_awk.c  \
		ft_split_pipex.c here_doc.c

SRCS_BN = error_utils_bonus.c error_utils2_bonus.c fork_utils2_bonus.c fork_utils_bonus.c  \
		free_utils_bonus.c init_pipex_bonus.c main_bonus.c ft_split_pipex_utils_bonus.c \
		ft_split_pipex_utils2_bonus.c ft_split_pipex_utils_awk_bonus.c  \
		ft_split_pipex_bonus.c here_doc.c 

OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
OBJS_BN = $(addprefix $(BN_DIR), $(SRCS_BN:.c=.o))

CC = cc
CFLAGS = -Wextra -Werror -Wall

ifdef WITH_BONUS
	OBJ = $(OBJS_BN)
else
	OBJ = $(OBJS)
endif

#rules

	
all : libs ${NAME}

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -g

libs:
	make -C ./lib/

${NAME} : ${OBJ}
	$(CC) -o $(NAME) ${OBJ} -L$(LIB_DIR) -l_jehelee -g


clean	:
	make -C ./lib/ clean
	rm -rf $(OBJS)
	rm -rf $(OBJS_BN)

fclean	: 
	make -C ./lib/ fclean
	rm -rf $(OBJS)
	rm -rf $(OBJS_BN)
	rm -rf	$(NAME)

re		: fclean all

bonus: 
	make WITH_BONUS=1 all

.PHONY: all libs clean fclean re bonus