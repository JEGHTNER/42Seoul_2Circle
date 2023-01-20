# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:31:23 by jehelee           #+#    #+#              #
#    Updated: 2023/01/20 23:53:34 by jehelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c move_utils.c image_utils.c error_utils.c map_utils.c key_hook_utils.c\
		error_utils2.c																\

INC_DIR		= ./lib/include/
LIB_DIR		= ./lib/
MLX_DIR		= ./mlx/

OBJS = ${SRCS:%.c=%.o}


CC = cc
CFLAGS = -Wextra -Werror -Wall
CLIB = -L ${MLX_DIR} -lmlx -framework OpenGL -framework Appkit -Imlx


#rules

all : libs ${NAME}

libs:
	make -C ./lib/
	make -C ./mlx/

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -Imlx -c -o $@ $<

${NAME} : ${OBJS}
	$(CC) -o $(NAME) ${OBJS} -L ${LIB_DIR} -l_jehelee ${CLIB} -g

clean	:
	make -C ./lib/ clean
	make -C ./mlx/ clean
	rm -rf $(OBJS)

fclean	: clean
	rm -rf  ./lib/lib_jehelee.a
	rm -rf	$(NAME)

re		: fclean all