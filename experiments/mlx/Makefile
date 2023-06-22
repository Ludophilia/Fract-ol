# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:11:54 by jgermany          #+#    #+#              #
#    Updated: 2023/06/22 19:45:23 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= mlx_expr

MLX_DIR		:= ../../minilibx-linux

CC 			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CFLAGS		+= -I$(MLX_DIR)

MLXFLAGS	:= -lX11 -lXext -lmlx
MLXFLAGS	+= -L$(MLX_DIR)

SRCS 		:= main.c
SRCS 		+= hookmgr.c
SRCS 		+= scenemgr.c

OBJS		:= $(SRCS:.c=.o)

MLX			:= $(MLX_DIR)/libmmlx.a

all:		$(NAME)

$(NAME):	$(OBJS) | $(MLX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLXFLAGS)

$(MLX):
	@make -C $(MLX_DIR) all

%.o:		%.h mlx_common.h

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
