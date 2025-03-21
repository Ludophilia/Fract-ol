# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 18:44:43 by jgermany          #+#    #+#              #
#    Updated: 2023/07/08 15:48:08 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := 2d

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := 2d.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.SILENT: clean fclean
.PHONY: all re clean fclean
