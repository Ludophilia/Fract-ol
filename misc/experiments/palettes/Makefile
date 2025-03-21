# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegerman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 18:44:43 by jgermany          #+#    #+#              #
#    Updated: 2025/03/21 18:21:16 by jegerman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := palettes

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := color.c
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
