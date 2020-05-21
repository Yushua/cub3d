# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/05 10:59:00 by ybakker       #+#    #+#                  #
#    Updated: 2020/05/21 22:57:04 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/cube_functions/main.c\
		./srcs/cube_functions/raycasting.c\
		./srcs/cube_functions/set_location.c\
		./srcs/cube_functions/texture.c\
		./srcs/cube_functions/keys.c\
		./srcs/cube_functions/error.c\
		./srcs/cube_functions/functions.c\
		./srcs/cube_functions/set_value.c\
		./srcs/cube_functions/raycasting_texture.c\
		./srcs/cube_functions/readmap/read_map.c\
		./srcs/cube_functions/readmap/get_map.c\
		./srcs/cube_functions/readmap/check_r.c\
		./srcs/cube_functions/readmap/check_no.c\
		./srcs/cube_functions/readmap/check_so.c\
		./srcs/cube_functions/readmap/check_s.c\
		./srcs/cube_functions/readmap/check_we.c\
		./srcs/cube_functions/readmap/check_ea.c\
		./srcs/cube_functions/readmap/check_f.c\
		./srcs/cube_functions/readmap/check_c.c\
		./srcs/cube_functions/readmap/space_cubemap.c\

GNL =	srcs/get_next_line/get_next_line_utils.c\
		srcs/get_next_line/get_next_line.c\

NAME =  cube
CC = gcc -g

OBJS = $(SRCS:.c=.o)
GETNL = $(GNL:.c=.o)

INC = ./srcs/cube_functions/cube.h ./srcs/get_next_line/get_next_line.h ./mlx/mlx.h

A = libmlx.a libft.a

$(%.o): $(%.c)
	$(CC) -I/usr/include libmlx.a -I -O3 -c $< -o $@

$(NAME): $(OBJS) $(GETNL)
		@make -C ./srcs/mlx
		@cp ./srcs/mlx/libmlx.a .
		@make -C ./srcs/libft
		@cp ./srcs/libft/libft.a .
	$(CC) $(OBJS) $(GETNL) $(A) -lm -lX11 -lXext -o $(NAME)

# $(MLX):
# 		@make -C ./mlx
# 		@cp mlx/libmlx.a .

clean:
		@make -C ./srcs/mlx clean
		@make -C ./srcs/libft clean
		rm -f ./srcs/cube_functions/$(OBJS)
		rm -f ./srcs/cube_functions/$(GETNL)


fclean:	clean
		rm -f $(NAME)
		rm -f $(A)

re:		fclean all