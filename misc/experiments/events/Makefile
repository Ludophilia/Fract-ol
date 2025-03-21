# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:11:54 by jgermany          #+#    #+#              #
#    Updated: 2025/03/21 18:20:02 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= events

ROOT		:= ../../..

MLX_DIR		:= $(ROOT)/libs/mlx

CC 			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CFLAGS		+= -I$(MLX_DIR)

MLXFLAGS	:= -lmlx -lX11 -lXext 
MLXFLAGS	+= -L$(MLX_DIR)

SRCS 		:= main.c
SRCS 		+= hookmgr.c

OBJS		:= $(SRCS:.c=.o)

MLX			:= $(MLX_DIR)/libmmlx.a

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(MLX_DIR) all
			$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLXFLAGS)

%.o:		hooks.h

clean:
			make -C $(MLX_DIR) clean
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:
			make fclean
			make all

.SILENT: clean fclean $(MLX)
.PHONY: all clean fclean re
