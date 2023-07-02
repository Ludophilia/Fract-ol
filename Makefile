# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 20:24:27 by jgermany          #+#    #+#              #
#    Updated: 2023/07/02 20:20:54 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

CC := cc
CFLAGS := -Wall -Wextra -Werror

FT	:= ./libft
MLX	:= ./mlx
LIBFLAGS := -lft -L$(FT) -lmlx -L$(MLX) -lX11 -lXext

SRCS_MAN := fractol.c
SRCS_MAN += scenemgr.c
SRCS_MAN += hookmgr.c

OBJS_MAN := $(SRCS_MAN:.c=.o)

all: $(NAME)

bonus:
	echo "What are you waiting for??"

$(NAME): $(OBJS_MAN)
	make -sC $(FT)
	make -C $(MLX) >/dev/null 2>&1
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

%.o: %.c fractol_common.h %.h
	$(CC) $(CFLAGS) -c $<

clean:
	make -sC $(FT) $@
	make -C $(MLX) $@ >/dev/null 2>&1
	rm -f $(OBJS_MAN)

fclean: clean
	make -sC $(FT) $@
	rm -f $(NAME)

re:
	make fclean
	make all

.SILENT: clean fclean
.PHONY: all re clean fclean
