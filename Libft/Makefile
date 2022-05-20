# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 21:03:40 by tasantos          #+#    #+#              #
#    Updated: 2022/05/10 19:00:05 by tasantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
HEADERFILES := libft.h
OBJFILES := ft_atoi.o \
			ft_bzero.o \
			ft_calloc.o \
			ft_substr.o \
			ft_strjoin.o \
			ft_strtrim.o \
			ft_putchar_fd.o \
			ft_putstr_fd.o \
			ft_putendl_fd.o \
			ft_putnbr_fd.o \
			ft_memchr.o \
			ft_memcmp.o \
			ft_memcpy.o \
			ft_memmove.o \
			ft_memset.o \
			ft_strchr.o \
			ft_strlcat.o \
			ft_strlcpy.o \
			ft_strlen.o \
			ft_strncmp.o \
			ft_strnstr.o \
			ft_strrchr.o \
			ft_isalnum.o \
			ft_isalpha.o \
			ft_isascii.o \
			ft_isdigit.o \
			ft_isprint.o \
			ft_tolower.o \
			ft_toupper.o \
			ft_strdup.o \
			ft_strmapi.o \
			ft_split.o \
			ft_itoa.o \
			ft_striteri.o
			
CFLAGS ?= -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJFILES)
	ar -rcs $(NAME) $(OBJFILES)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(NAME) $(OBJFILES)

fclean: clean
		rm -f $(NAME)
		
re : fclean all

.PHONY: all clean fclean re
