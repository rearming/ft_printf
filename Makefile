# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sselusa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 20:11:30 by sselusa           #+#    #+#              #
#    Updated: 2019/05/20 14:37:29 by sleonard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -02

LIBFT = ./libft

LIBFT_INCL = ./libft/includes

PRINTF_INCL = ./includes

DIR_S = ./srcs

DIR_O = temp

SOURCES =				\
		debug.c			\
		error.c			\
		format_filler.c	\
		format_parser.c	\
		ft_atoll.c		\
		ft_lltoa.c		\
		ft_lltoa_base.c	\
		ft_u_putstr_fd.c\
		int.c			\
		ft_printf.c		\
		split_flags.c	\
		string.c		\
		int.c			\

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	gcc $(FLAGS) -I $(PRINTF_INCL) -I $(LIBFT_INCL) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

re: fclean all