# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 10:56:36 by rumachad          #+#    #+#              #
#    Updated: 2023/07/27 11:29:34 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
SRC_BONUS = checker.c movements.c movements2.c \
			movements3.c ps_errors.c ps_checks.c \
			ps_list_utils.c ps_sort_utils.c
SRC = push_swap.c movements.c movements2.c \
		movements3.c ps_list_utils.c ps_sort_utils.c \
		ps_sort_five.c ps_sort_big.c ps_strat.c \
		ps_sort_three.c ps_strat2.c ps_errors.c \
		ps_sort_big2.c ps_sort_big3.c ps_checks.c
LIBFT_DIR = libft
LIBFT_PATH = ${LIBFT_DIR}/libft.a
OBJS_BONUS = ${SRC_BONUS:.c=.o}
OBJS = ${SRC:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${LIBFT_DIR}
			cp ${LIBFT_PATH} ${NAME}
			ar rcs ${NAME} ${OBJS}
			${CC} ${CFLAGS} ${NAME} -o push_swap

all:	${NAME} bonus

clean:
		make clean -C ${LIBFT_DIR}
		${RM} ${OBJS}
		${RM} ${OBJS_BONUS}

fclean: clean
		make fclean -C ${LIBFT_DIR}
		${RM} ${NAME} push_swap
		${RM} checker

re:	clean all

bonus:	${OBJS_BONUS}
		make -C ${LIBFT_DIR}
		cp ${LIBFT_PATH} ${NAME}
		ar rcs ${NAME} ${OBJS_BONUS}
		${CC} ${CFLAGS} ${OBJS_BONUS} ${NAME} -o checker

.SILENT: