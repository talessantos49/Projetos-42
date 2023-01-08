# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 17:15:41 by tasantos          #+#    #+#              #
#    Updated: 2023/01/08 05:39:28 by tasantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex
DOT_A		= ${NAME}.a

HEADERS_DIR		= ./includes/
SOURCES_DIR		= ./src/

HEADERS_LIST	= pipex.h
SOURCES_LIST	= pipex.c \
				pipex_utils.c \
				split_pipex.c

GREEN			= \033[0;32m

RESET_COLOR		= \033[0m

HEADERS			= ${addprefix ${HEADERS_DIR}, ${HEADERS_LIST}}
SOURCES			= ${addprefix ${SOURCES_DIR}, ${SOURCES_LIST}}
INCLUDES		= -I ${HEADERS_DIR} -I ${LIBFT_HEADERS}

OBJECTS_DIR		= ./objects/
OBJECTS_LIST	= ${patsubst %.c, %.o, ${SOURCES_LIST}}
OBJECTS			= ${addprefix ${OBJECTS_DIR}, ${OBJECTS_LIST}}

LIBFT_DIR		= ./libft/
LIBFT_HEADERS	= ${LIBFT_DIR}includes/
LIBFT			= ${LIBFT_DIR}libft.a

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g

RM 				= rm -f

#VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
#--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --verbose \
#--trace-children=yes --track-fds=yes \
#--log-file=valgrind-out.txt

VALGRIND 		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --trace-children=yes --log-file=valgrind-out.txt -s
#--track-origins=yes --trace-children=yes --log-file=valgrind-out.txt -s

all:			${NAME}
#				@clear
				@echo "$(GREEN)Pipex Was compiled!"
				@echo "Lets Use!$(RESET_COLOR)"

${NAME}:		${LIBFT} ${OBJECTS_DIR} ${OBJECTS}
			${CC} ${CFLAGS} ${SOURCES} ${LIBFT} ${INCLUDES} -o ${NAME}

${OBJECTS_DIR}:
			mkdir -p ${OBJECTS_DIR}
			@echo Objects folder has been created!

${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.c ${HEADERS}
			${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@
			@echo Library created!

${LIBFT}:
			make -sC ${LIBFT_DIR}
			@echo Libft has been compiled!

dance_duck:
			${CC} ${CFLAGS} ${SOURCES} ${DOT_A} ${LIBFT}

valgrind:
	$(VALGRIND) ./pipex file-in "ls" "ls" file-out

clean:
			make -sC ${LIBFT_DIR} clean
			rm -rf ${OBJECTS_DIR}

fclean:		clean
			${RM} ${LIBFT}
			${RM} ${NAME}
			${RM} ${DOT_A}

re:			fclean all

.PHONY:		all, clean, fclean, re
