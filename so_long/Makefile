# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:31:23 by jehelee           #+#    #+#              #
#    Updated: 2023/01/07 16:31:23 by jehelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRCS = main.c	\

OBJ = ${SRCS:%.c =  %.o}


CC = cc
CFLAGS = -Wextra -Werror -Wall
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx


#rules

all : ${NAME}

%.o : %.c
	${CC} ${CFLAGS} $< -o $@

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${CLIB} ${SRCS} -o ${NAME}
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all