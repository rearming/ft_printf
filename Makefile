# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sselusa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 20:11:30 by sselusa           #+#    #+#              #
#    Updated: 2019/05/20 11:12:24 by sleonard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLGS = -Wall -Wextra -Werror -O2
SRCS = $(wildcard srcs/*.c)
SRCS_LIB = $(wildcard libft/srcs/*.c)
INCL = ./includes
LBFT = -lft
LFTD = ./libft
OBJS = $(wildcard *.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc $(FLGS) $(SRCS_LIB) $(SRCS) -c -I $(INCL) -I $(LFTD)/includes
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
