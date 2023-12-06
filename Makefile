# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caunhach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 00:48:45 by caunhach          #+#    #+#              #
#    Updated: 2023/06/22 01:06:52 by caunhach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall -g
NAME=cub3d
SRC= src/main.c \
	 src/execution/draw.c \
	 src/execution/handle_key.c \
	 src/execution/handle_key2.c \
	 src/execution/ray_casting.c \
	 src/execution/ray_casting2.c \
	 src/execution/start_game.c \
	 src/parsing/map_parse.c \
	 src/utils/error.c \
	 src/utils/free.c
INCLUDES=lib/libft/libft.a lib/minilibx_opengl/libmlx.a

all:
	@make -C lib/libft/ all
	@make -C lib/minilibx_opengl/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C lib/libft/ clean
	@make -C lib/minilibx_opengl/ clean

fclean: clean
	rm -f $(NAME)
	@make -C lib/libft/ fclean
	rm -rf cub3d.dSYM

re: fclean all

.PHONY: all clean fclean re
