# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 17:15:41 by tasantos          #+#    #+#              #
#    Updated: 2023/04/22 16:13:57 by marvin           ###   ########.fr        #
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
				radix.c

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
	$(VALGRIND) ./${NAME} 51 72 55 6 50 65 8 93 70 48 45 32 47 46 39 27 79 58 52 44 63 31 22 34 33 30 18 53 61 98 100 5 76 17 40 88 42 97 16 3 12 26 85 86 36 66 29 68 41 84 92 13 94 64 81 1 67 37 57 49 56 10 14 77 43 2 11 89 71 20 75 90 95 23 21 82 99 24 35 96 59 7 19 73 87 62 54 74 83 60 78 15 80 69 28 25 4 38 91 9
teste:	${NAME}
	./${NAME} 51 72 55 6 50 65 8 93 70 48 45 32 47 46 39 27 79 58 52 44 63 31 22 34 33 30 18 53 61 98 100 5 76 17 40 88 42 97 16 3 12 26 85 86 36 66 29 68 41 84 92 13 94 64 81 1 67 37 57 49 56 10 14 77 43 2 11 89 71 20 75 90 95 23 21 82 99 24 35 96 59 7 19 73 87 62 54 74 83 60 78 15 80 69 28 25 4 38 91 9  
	
	# | ./checker_linux 51 72 55 6 50 65 8 93 70 48 45 32 47 46 39 27 79 58 52 44 63 31 22 34 33 30 18 53 61 98 100 5 76 17 40 88 42 97 16 3 12 26 85 86 36 66 29 68 41 84 92  13 94 64 81 1 67 37 57 49 56 10 14 77 43 2 11 89 71 20 75 90 95 23 21 82 99 24 35 96 59 7 19 73 87 62 54 74 83 60 78 15 80 69 28 25 4 38 91 9 
clean:
			make -sC ${LIBFT_DIR} clean
			rm -rf ${OBJECTS_DIR}

fclean:		clean
			${RM} ${LIBFT}
			${RM} ${NAME}
			${RM} ${DOT_A}

re:			fclean all

.PHONY:		all, clean, fclean, re


VALGRIND1		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --verbose \
--log-file=valgrind-out1.txt

VALGRIND2		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --verbose \
--log-file=valgrind-out2.txt

VALGRIND3		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --verbose \
--log-file=valgrind-out3.txt

VALGRIND4		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --verbose \
--log-file=valgrind-out4.txt

full_test: $(NAME)
	@clear
	@echo -n "  2 args     [1] = "
	@./push_swap $(shell shuf -i 0-10000 -n 2) | wc -l
	@echo -n "  3 args     [3] = "
	@$(VALGRIND1) ./push_swap $(shell shuf -i 0-10000 -n 3) | wc -l
	@echo -n "  5 args    [12] = "
	@$(VALGRIND2) ./push_swap $(shell shuf -i 0-10000 -n 5) | wc -l
	@echo -n "100 args  [1099] = "
	@$(VALGRIND3) ./push_swap $(shell shuf -i 0-10000 -n 100) | wc -l
	@echo -n "500 args  [8499] = "
	@$(VALGRIND4) ./push_swap $(shell shuf -i 0-10000 -n 500) | wc -l