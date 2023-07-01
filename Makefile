# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 13:57:02 by jgermany          #+#    #+#              #
#    Updated: 2023/07/01 17:35:10 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

CC := cc
CFLAGS := -Wall -Wextra -Werror

FT	:= ./libft
MLX	:= ./minilibx-linux
LIBFLAGS := -lft -L$(FT) -lmlx -L$(MLX) -lX11 -lXext

SRCS_MAN := fractol.c
OBJS_MAN := $(SRCS_MAN:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_MAN)
	make -sC $(FT)
	make -C $(MLX) > /dev/null
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

clean:
	make -sC $(FT) $@
	make -C $(MLX) $@ > /dev/null
	rm -f $(OBJS_MAN)

fclean: clean
	make -sC $(FT) $@
	rm -f $(NAME)

re:
	make fclean
	make all

.SILENT: clean fclean
.PHONY: all re clean fclean
