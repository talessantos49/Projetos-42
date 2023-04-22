# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 17:15:41 by tasantos          #+#    #+#              #
#    Updated: 2023/04/21 20:42:39 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
DOT_A		= ${NAME}.a

HEADERS_DIR		= ./includes/
SOURCES_DIR		= ./src/

HEADERS_LIST	= push_swap.h
SOURCES_LIST	= push_swap.c \
				checkers.c \
				movimentsA.c \
				movimentsB.c \
				movimentsGeneral.c \
				stacks.c \
				sort.c	\
				sort_five.c	\
				liners.c \
				stacksA.c \
				extras.c \
				quick_sort.c

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
# CFLAGS			= -g
CFLAGS			= -Wall -Werror -Wextra -g

RM 				= rm -f

# VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
# --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --verbose \
# --trace-children=yes --track-fds=yes --log-file=valgrind-out.txt

# VALGRIND 		= @valgrind --leak-check=full --show-leak-kinds=all \
# --track-origins=yes --trace-children=yes --log-file=valgrind-out.txt -s
# # #--track-origins=yes --trace-children=yes --log-file=valgrind-out.txt -s

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --verbose -s\
--log-file=valgrind-out.txt


all:			${NAME}
#				@clear
				@echo "$(GREEN)Push_Swap Was compiled!"
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

valgrind: ${NAME}
	$(VALGRIND) ./${NAME} 4 1 2 9 11 5 8 3 12 6 10 7 

teste:	${NAME}
	./${NAME} 2 5 6 1 0 8 4 7 9 3 | ./checker_linux 2 5 6 1 8

clean:
			make -sC ${LIBFT_DIR} clean
			rm -rf ${OBJECTS_DIR}

fclean:		clean
			${RM} ${LIBFT}
			${RM} ${NAME}
			${RM} ${DOT_A}

re:			fclean all

.PHONY:		all, clean, fclean, re
