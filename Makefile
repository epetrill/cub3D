# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 17:48:42 by epetrill          #+#    #+#              #
#    Updated: 2020/12/07 03:26:53 by epetrill         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D
CC = clang

# FLAGS = -g3 -fsanitize=address -Wall -Wextra -Werror -I include/
FLAGS = -g3 -Wall -Wextra -Werror -I include/

MLXFLAGS = -lm -lXext -lX11

INC = include/cub.h
HEADER = include
FILES = srcs/cub.c \
		srcs/error.c \
		srcs/error2.c \
		srcs/filetotab.c \
		srcs/ftbasic.c \
		srcs/ftbasic2.c \
		srcs/ftbasic3.c \
		srcs/get_next_line_utils.c \
		srcs/get_next_line.c \
		srcs/mapprep.c \
		srcs/mlxbasics.c \
		srcs/param.c \
		srcs/img_init.c \
		srcs/setter.c \
		srcs/show.c \
		srcs/move.c
		
MLX = minilibx-linux/libmlx.a
MLX2 = minilibx-linux/libmlx_Linux.a

OBJ = $(FILES:.c=.o)

all: draw $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(MLXFLAGS) $(FILES) $(MLX) $(MLX2) -o $(NAME)

bonus: all

clean:
	@rm -rf $(OBJ)
	@make clean -C minilibx-linux

fclean: clean
	@rm -f $(NAME)
	@make clean
	
re: fclean all

draw:
	@make -C minilibx-linux