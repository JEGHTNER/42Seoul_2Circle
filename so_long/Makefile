# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:31:23 by jehelee           #+#    #+#              #
#    Updated: 2023/01/12 15:45:29 by jehelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRCS = main.c	\

LIB_DIR		= ./lib/

OBJ = ${SRCS:%.c=%.o}


CC = cc
CFLAGS = -Wextra -Werror -Wall
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx


#rules

all : ${NAME}

%.o : %.c
#	${CC} ${CFLAGS} $< -o $@
	$(CC) -o ${NAME} main.c -L ${LIB_DIR} -l_jehelee ${CLIB} -g

${NAME} : ${OBJ}
#	${CC} ${CFLAGS} ${CLIB} ${SRCS} -o ${NAME}
	make -C ./lib/
#	$(CC) -o main.o main.c -L ${LIB_DIR} -l_jehelee ${CLIB} -g
	$(CC) -o $(NAME) main.c -L ${LIB_DIR} -l_jehelee ${CLIB} -g
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	make -C ./lib/ clean
	rm -rf $(OBJ)

fclean	: clean
	rm -rf  lib_jehelee.a
	rm -rf	$(NAME)

re		: fclean all