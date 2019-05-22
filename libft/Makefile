# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sselusa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 15:49:46 by sselusa           #+#    #+#              #
#    Updated: 2019/05/22 11:57:21 by sleonard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLGS = -Wall -Wextra -O2

SRCS_DIR = ./srcs/

OBJ_DIR = temp

INCL = ./includes

SOURCES = ft_atoi.c ft_bzero.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_memccpy.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c \
	ft_memset.c ft_strcat.c ft_strchr.c \
	ft_strcmp.c ft_strcpy.c ft_strdup.c \
	ft_strlcat.c ft_strlen.c ft_strncat.c \
	ft_strncmp.c ft_strncpy.c ft_strnstr.c \
	ft_strrchr.c ft_strstr.c ft_tolower.c \
	ft_toupper.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c \
	ft_strmapi.c ft_strequ.c ft_strnequ.c \
	ft_strsub.c ft_strjoin.c ft_strtrim.c \
	ft_strsplit.c ft_itoa.c ft_putchar.c \
	ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	get_next_line.c ft_lstaddback.c ft_power.c \
	ft_count_digits.c ft_count_digits_base.c \
	ft_atoll_base.c ft_ultoa.c ft_abs.c \
	ft_atoll.c ft_lltoa.c ft_lltoa_base.c \
	ft_atoull.c ft_ulltoa_base.c \
	ft_ulltoa.c \

SRCS = $(addprefix $(SRCS_DIR)/,$(SOURCES))

OBJS = $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -I $(INCL) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
