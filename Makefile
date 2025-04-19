# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 20:24:27 by jgermany          #+#    #+#              #
#    Updated: 2025/04/19 13:33:16 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME								:= fractol
NAME_BON							:= fractol_bonus

FT									:= ./libs/libft
MLX									:= ./libs/mlx
SRCS_DIRM							:= ./srcs
INCL_DIRM							:= ./includes

SRCS_DIRB							:= ./srcs_bonus
INCL_DIRB							:= ./includes_bonus

CC 									:= cc
CFLAGS 								:= -Wall -Wextra -Werror -I$(FT) -I$(MLX)

all: CFLAGS 						+= -I$(INCL_DIRM)
bonus: CFLAGS						+= -I$(INCL_DIRM) -I$(INCL_DIRB)
LIBFLAGS 							:= -lm -lft -L$(FT) -lmlx -L$(MLX)
LIBFLAGS 							+= -lX11 -lXext

SRCS_MAN 							:= $(SRCS_DIRM)/main.c
SRCS_MAN 							+= $(SRCS_DIRM)/climgr.c
SRCS_MAN 							+= $(SRCS_DIRM)/viewmgr.c
SRCS_MAN 							+= $(SRCS_DIRM)/uimgr.c
SRCS_MAN 							+= $(SRCS_DIRM)/imgmgr.c
SRCS_MAN 							+= $(SRCS_DIRM)/plotter.c
SRCS_MAN 							+= $(SRCS_DIRM)/hookmgr.c

SRCS_BON							:= $(SRCS_DIRB)/main_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/climgr_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/uimgr_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/hookmgr_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/imgmgr_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/viewmgr_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/plotter_bonus.c

OBJS_MAN 							:= $(SRCS_MAN:.c=.o)
OBJS_BON 							:= $(SRCS_BON:.c=.o)

all									:$(NAME)

bonus								:$(NAME_BON)

$(NAME_BON)							:$(OBJS_BON)
									make -sC $(FT)
									make -C $(MLX) >/dev/null 2>&1
									$(CC) $(CFLAGS) -o $(NAME_BON) $^ $(LIBFLAGS)

$(NAME)								:$(OBJS_MAN)
									make -sC $(FT)
									make -C $(MLX) >/dev/null 2>&1
									$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

%.o									:%.c
									$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_MAN)							:$(INCL_DIRM)/fractol.h

$(OBJS_BON)							:$(INCL_DIRM)/fractol.h \
									$(INCL_DIRB)/fractol_bonus.h

clean:
									make -sC $(FT) $@
									make -C $(MLX) $@ >/dev/null 2>&1
									rm -f $(OBJS_MAN)
									rm -f $(OBJS_BON)

fclean:								clean
									make -sC $(FT) $@
									rm -f $(NAME)
									rm -f $(NAME_BON)

re:
									make fclean
									make all

.SILENT:							clean fclean
.PHONY:								all re clean fclean
