# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 20:24:27 by jgermany          #+#    #+#              #
#    Updated: 2025/03/18 17:44:04 by jegerman         ###   ########.fr        #
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
SRCS_BON 							+= $(SRCS_DIRB)/colormgr_utils_bonus.c
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

$(OBJS_MAN)							:$(INCL_DIRM)/fractol.h

$(OBJS_BON)							:$(INCL_DIRB)/fractol_bonus.h

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
