# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 15:53:54 by bkiziler          #+#    #+#              #
#    Updated: 2023/03/23 16:37:02 by bkiziler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = mapcheck.c \
		mapcheck2.c \
		moves.c \
		noidea.c \
		ft_strtrim.c

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a
MLX = ./minilibx/libmlx.a
GNL = ./Get_next_line/get_next_line.c \
		./Get_next_line/get_next_line_utils.c

all:	$(NAME)

$(NAME) : $(PRINTF) $(MLX)
		$(CC) $(CFLAGS) $(LFLAGS) $(SRC) $(GNL) $(PRINTF) $(MLX) -o $(NAME)

$(PRINTF) :
		make -C ./ft_printf


$(MLX) :
		make -C ./minilibx

clean:
	make -C ./ft_printf clean

fclean: clean
	$(RM) $(NAME)
	make -C ./ft_printf clean
	make -C clean ./minilibx

re: fclean all

.PHONY: clean fclean re
