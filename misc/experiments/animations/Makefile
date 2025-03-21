# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 12:50:43 by jegerman          #+#    #+#              #
#    Updated: 2025/03/20 14:34:24 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := animations

CC := cc

ROOT := ../../..

MLXD := $(ROOT)/libs/mlx

CFLAGS += -I$(MLXD)

LMLXFL := -lmlx -L$(MLXD)
LX11FL := -lX11 -lXext

SRCS := mlx_anims.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -sC$(MLXD) 2> /dev/null 1>&2 
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LMLXFL) $(LX11FL)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SILENT: clean fclean
