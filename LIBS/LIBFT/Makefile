# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 21:27:13 by corin             #+#    #+#              #
#    Updated: 2024/04/05 16:17:21 by ccraciun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h

SRC = ft_atoi.c \
      ft_bzero.c \
      ft_isalnum.c \
      ft_isalpha.c \
      ft_isascii.c \
      ft_isdigit.c \
      ft_isprint.c \
      ft_itoa.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_memcpy.c \
      ft_memmove.c \
      ft_memset.c \
      ft_split.c \
      ft_strchr.c \
      ft_strjoin.c \
      ft_strlcat.c \
      ft_strlcpy.c \
      ft_strlen.c \
      ft_strmapi.c \
      ft_strncmp.c \
      ft_strnstr.c \
      ft_strrchr.c \
      ft_strtrim.c \
      ft_substr.c \
      ft_tolower.c \
      ft_toupper.c \
      ft_calloc.c \
      ft_strdup.c \
      ft_putchar_fd.c \
      ft_putnbr_fd.c \
      ft_putstr_fd.c \
      ft_putendl_fd.c \
      ft_striteri.c \
	  ft_free_2d.c \
	  ft_line_len.c

OBJS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
