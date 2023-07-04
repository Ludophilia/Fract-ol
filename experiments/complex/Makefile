# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 18:44:43 by jgermany          #+#    #+#              #
#    Updated: 2023/07/04 18:52:30 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := complex

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := complex.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)
	./$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
