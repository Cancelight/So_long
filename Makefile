# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 15:53:54 by bkiziler          #+#    #+#              #
#    Updated: 2023/03/31 15:09:28 by bkiziler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./Sources/mapcheck.c \
		./Sources/mapcheck2.c \
		./Sources/moves.c \
		./Sources/so_long.c \
		./Sources/ft_strtrim.c \
		./Sources/validPath.c

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
PRINTF = ft_printf/libftprintf.a
MLX = ./minilibx/libmlx.a
GNL = ./Get_next_line/get_next_line.c \
		./Get_next_line/get_next_line_utils.c

all:	$(NAME) $(MLX)

$(NAME) : $(SRC) $(PRINTF) $(MLX)
		$(CC) $(CFLAGS) $(LFLAGS) $(SRC) $(GNL) $(PRINTF) $(MLX) -o $(NAME)

$(PRINTF) :
		make -C ./ft_printf

$(MLX) :
		make -C ./minilibx

clean:

fclean: clean
	$(RM) $(NAME)
	make clean -C ./minilibx
	make fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re
