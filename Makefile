# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 20:24:27 by jgermany          #+#    #+#              #
#    Updated: 2023/07/23 20:47:43 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						:= fractol

FT							:= ./libs/libft
MLX							:= ./libs/mlx
SRCS						:= ./srcs
INCL						:= ./includes

CC 							:= cc
CFLAGS 						:= -Wall -Wextra -Werror 
CFLAGS 						+= -I$(INCL) -I$(FT) -I$(MLX)
LIBFLAGS 					:= -lm -lft -L$(FT) -lmlx -L$(MLX) -lX11 -lXext

SRCS_MAN 					:= fractol.c
SRCS_MAN 					+= scenemgr.c
SRCS_MAN 					+= hookmgr.c
SRCS_MAN 					+= imgmgr.c
SRCS_MAN 					+= plotter.c
SRCS_MAN 					+= clichecker.c
SRCS_MAN 					+= colormgr.c

OBJS_MAN 					:= $(addprefix $(SRCS)/, $(SRCS_MAN:.c=.o))

all							:$(NAME)

bonus:

$(NAME)						:$(OBJS_MAN)
							make -sC $(FT)
							make -C $(MLX) >/dev/null 2>&1
							$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

%.o							:%.c
							$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_MAN)					:$(INCL)/fractol_common.h
$(SRCS)/fractol.o			:$(INCL)/fractol.h
$(SRCS)/scenemgr.o			:$(INCL)/scenemgr.h
$(SRCS)/hookmgr.o			:$(INCL)/hookmgr.h
$(SRCS)/imgmgr.o			:$(INCL)/imgmgr.h
$(SRCS)/plotter.o			:$(INCL)/plotter.h
$(SRCS)/clichecker.o		:$(INCL)/clichecker.h
$(SRCS)/colormgr.o			:$(INCL)/colormgr.h

clean:
							make -sC $(FT) $@
							make -C $(MLX) $@ >/dev/null 2>&1
							rm -f $(OBJS_MAN)

fclean:						clean
							make -sC $(FT) $@
							rm -f $(NAME)

re:
							make fclean
							make all

.SILENT:					clean fclean
.PHONY:						all re clean fclean
