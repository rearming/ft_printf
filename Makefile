# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sselusa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 20:11:30 by sselusa           #+#    #+#              #
#    Updated: 2019/05/15 12:01:04 by sselusa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLGS = -Wall -Wextra -O2
SRCS = $(wildcard srcs/*.c)
INCL = ./includes
LBFT = -lft
LFTD = ./libft
OBJS = $(wildcard *.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LFTD)
	@gcc -c $(FLGS) $(SRCS) -I $(INCL) -I $(LFTD)/includes
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@make -C $(LFTD) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LFTD) fclean
	@rm -f $(NAME)

re: fclean all
