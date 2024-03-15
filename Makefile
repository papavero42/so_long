# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 18:41:36 by pdi-pint          #+#    #+#              #
#    Updated: 2024/03/11 15:40:02 by pdi-pint         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wextra -Werror -Wall -g
RM = rm -f
LINKS_LINUX = -lX11 -lm -lXext

MINILIBX = mlx/libmlx.a
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
GET_NEXT_LINE = get_next_line/get_next_line.a

SRC = ft_render.c \
	ft_movement.c \
	ft_map_gen.c \
	ft_enemy_movement.c \
	ft_exit.c \
	ft_parsing.c \
	ft_control.c \
	main.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C mlx/
	make -C ft_printf/
	make -C get_next_line/
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MINILIBX) $(PRINTF) $(GET_NEXT_LINE) $(LINKS_LINUX) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean -C mlx/
	make clean -C libft/
	make clean -C ft_printf/
	make clean -C get_next_line/
	$(RM) $(NAME)

re: fclean all
