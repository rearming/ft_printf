# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sselusa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 20:11:30 by sselusa           #+#    #+#              #
#    Updated: 2019/05/13 20:17:57 by sselusa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLGS = -Wall -Wextra -Werror -O2
SRCS = $(wildcard srcs/*.c)
INCL = ./includes
LBFT = -lft
LFTD = ./libft
OBJS = $(wildcard *.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LFTD)
	@gcc $(FLGS) -c $(SRCS) -I $(INCL) -I $(LFTD)/includes -L$(LFTD) $(LBFT)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@make -C $(LFTD) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LFTD) fclean
	@rm -f $(NAME)

re: fclean all
