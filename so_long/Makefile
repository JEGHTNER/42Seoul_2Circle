# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:31:23 by jehelee           #+#    #+#              #
#    Updated: 2023/01/20 17:54:14 by jehelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRCS = main.c key_input_utils.c	image_utils.c error_utils.c map_utils.c\

LIB_DIR		= ./lib/

OBJ = ${SRCS:%.c=%.o}


CC = cc
CFLAGS = -Wextra -Werror -Wall
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx


#rules

all : ${NAME}

%.o : %.c
#	${CC} ${CFLAGS} $< -o $@
	$(CC) -o ${NAME} ${SRCS} -L ${LIB_DIR} -l_jehelee ${CLIB} -g

${NAME} : ${OBJ}
#	${CC} ${CFLAGS} ${CLIB} ${SRCS} -o ${NAME}
	make -C ./lib/
#	$(CC) -o main.o main.c -L ${LIB_DIR} -l_jehelee ${CLIB} -g
	$(CC) -o $(NAME) ${SRCS} -L ${LIB_DIR} -l_jehelee ${CLIB} -g
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	make -C ./lib/ clean
	rm -rf $(OBJ)

fclean	: clean
	rm -rf  ./lib/lib_jehelee.a
	rm -rf	$(NAME)

re		: fclean all