# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 17:15:41 by tasantos          #+#    #+#              #
#    Updated: 2022/10/24 06:11:56 by tasantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

HEADERS_DIR		= ./includes/
SOURCES_DIR		= ./src/

HEADERS_LIST	= so_long.h
SOURCES_LIST	= so_long.c \
			render.c \
			movement.c \
			map_validator.c \
			free_all.c \
			route_validation.c

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
LIBRARIES		= -lmlx -lXext -lX11

RM 				= rm -f

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --verbose \
--log-file=valgrind-out.txt

all:			${NAME}
				@echo "$(GREEN)So_long Was compiled!"
				@echo "Lets Play!$(RESET_COLOR)"

${NAME}:		${LIBFT} ${OBJECTS_DIR} ${OBJECTS}
			${CC} ${CFLAGS} ${SOURCES} ${LIBFT} ${LIBRARIES} ${INCLUDES} -o ${NAME}

${OBJECTS_DIR}:
			mkdir -p ${OBJECTS_DIR}
			@echo Objects folder has been created!

${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.c ${HEADERS}
			${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@
			@echo Library created!

${LIBFT}:
			make -sC ${LIBFT_DIR}
			@echo Libft has been compiled!

valgrind:
		$(VALGRIND) ./so_long maps/map_error.ber

clean:
			make -sC ${LIBFT_DIR} clean
			rm -rf ${OBJECTS_DIR}

fclean:		clean
			${RM} ${LIBFT}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all, clean, fclean, re