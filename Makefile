# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 20:24:27 by jgermany          #+#    #+#              #
#    Updated: 2023/07/25 21:22:06 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME								:= fractol

FT									:= ./libs/libft
MLX									:= ./libs/mlx
SRCS_DIRM							:= ./srcs
INCL_DIRM							:= ./includes

SRCS_DIRB							:= ./srcs_bonus
INCL_DIRB							:= ./includes_bonus

CC 									:= cc
CFLAGS 								:= -Wall -Wextra -Werror -I$(FT) -I$(MLX)
all: CFLAGS 						+= -I$(INCL_DIRM)
bonus: CFLAGS						+= -I$(INCL_DIRB)
LIBFLAGS 							:= -lm -lft -L$(FT) -lmlx -L$(MLX)
LIBFLAGS 							+= -lX11 -lXext

SRCS_MAN 							:= $(SRCS_DIRM)/fractol.c
SRCS_MAN 							+= $(SRCS_DIRM)/scenemgr.c
SRCS_MAN 							+= $(SRCS_DIRM)/hookmgr.c
SRCS_MAN 							+= $(SRCS_DIRM)/imgmgr.c
SRCS_MAN 							+= $(SRCS_DIRM)/plotter.c
SRCS_MAN 							+= $(SRCS_DIRM)/clichecker.c
SRCS_MAN 							+= $(SRCS_DIRM)/colormgr.c

SRCS_BON 							:= $(SRCS_DIRB)/fractol_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/scenemgr_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/hookmgr_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/imgmgr_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/plotter_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/clichecker_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/colormgr_bonus.c
SRCS_BON 							+= $(SRCS_DIRB)/viewmgr_bonus.c

OBJS_MAN 							:= $(SRCS_MAN:.c=.o)
OBJS_BON 							:= $(SRCS_BON:.c=.o)

all									:$(NAME)

bonus								:$(OBJS_BON)
									make -sC $(FT)
									make -C $(MLX) >/dev/null 2>&1
									$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBFLAGS)

$(NAME)								:$(OBJS_MAN)
									make -sC $(FT)
									make -C $(MLX) >/dev/null 2>&1
									$(CC) $(CFLAGS) -o $@ $^ $(LIBFLAGS)

%.o									:%.c
									$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_MAN)							:$(INCL_DIRM)/fractol_common.h
$(SRCS)/fractol.o					:$(INCL_DIRM)/fractol.h
$(SRCS)/scenemgr.o					:$(INCL_DIRM)/scenemgr.h
$(SRCS)/hookmgr.o					:$(INCL_DIRM)/hookmgr.h
$(SRCS)/imgmgr.o					:$(INCL_DIRM)/imgmgr.h
$(SRCS)/plotter.o					:$(INCL_DIRM)/plotter.h
$(SRCS)/clichecker.o				:$(INCL_DIRM)/clichecker.h
$(SRCS)/colormgr.o					:$(INCL_DIRM)/colormgr.h

$(OBJS_BON)							:$(INCL_DIRB)/fractol_common_bonus.h
$(SRCS_BON)/fractol_bonus.o			:$(INCL_DIRB)/fractol_bonus.h
$(SRCS_BON)/scenemgr_bonus.o		:$(INCL_DIRB)/scenemgr_bonus.h
$(SRCS_BON)/hookmgr_bonus.o			:$(INCL_DIRB)/hookmgr_bonus.h
$(SRCS_BON)/imgmgr_bonus.o			:$(INCL_DIRB)/imgmgr_bonus.h
$(SRCS_BON)/plotter_bonus.o			:$(INCL_DIRB)/plotter_bonus.h
$(SRCS_BON)/clichecker_bonus.o		:$(INCL_DIRB)/clichecker_bonus.h
$(SRCS_BON)/colormgr_bonus.o		:$(INCL_DIRB)/colormgr_bonus.h

clean:
									make -sC $(FT) $@
									make -C $(MLX) $@ >/dev/null 2>&1
									rm -f $(OBJS_MAN)
									rm -f $(OBJS_BON)

fclean:								clean
									make -sC $(FT) $@
									rm -f $(NAME)

re:
									make fclean
									make all

.SILENT:							clean fclean
.PHONY:								all re clean fclean
