# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/05 10:59:00 by ybakker        #+#    #+#                 #
#    Updated: 2020/03/09 16:43:13 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS =	test.c\
		texture.c\
			# ./srcs/get_next_line/get_next_line.c \
			# ./srcs/get_next_line/get_next_line_utils.c \

NAME =  cub3D
CC = gcc -g

OBJS = $(SRCS:.c=.o)

all: libft minilibx $(NAME)

libft:
	make -C libft/

minilibx:
	make -C srcs/minilibx/
	cp srcs/minilibx/libmlx.dylib /Users/ybakker/cub3d

$(%.o): $(%.c)
	$(CC) -Lsrcs/minilibx/ -Iinc -Ilibft -c $< -o $@

$(NAME): $(OBJS)
	$(CC) -Lsrcs/minilibx/ -lmlx -framework OpenGL -framework AppKit -lz $(SRCS) -o $(NAME)