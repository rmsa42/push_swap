# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 10:56:36 by rumachad          #+#    #+#              #
#    Updated: 2023/09/25 11:31:03 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC_BONUS = src_bonus/checker.c src_bonus/movements_bonus.c src_bonus/movements2_bonus.c \
			src_bonus/movements3_bonus.c src_bonus/ps_errors_bonus.c src_bonus/ps_checks_bonus.c \
			src_bonus/ps_list_utils_bonus.c src_bonus/ps_sort_utils_bonus.c src_bonus/checker_utils.c
SRC = src/push_swap.c src/movements.c src/movements2.c \
		src/movements3.c src/ps_list_utils.c src/ps_sort_utils.c \
		src/ps_sort_five.c src/ps_sort_big.c src/ps_strat.c \
		src/ps_sort_three.c src/ps_strat2.c src/ps_errors.c \
		src/ps_sort_big2.c src/ps_sort_big3.c src/ps_checks.c
LIBFT_DIR = libft
LIBFT_PATH = ${LIBFT_DIR}/libft.a
OBJS_BONUS = ${SRC_BONUS:.c=.o}
OBJS = ${SRC:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I include
.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${LIBFT_DIR}
			cp ${LIBFT_PATH} push_swap.a
			ar rcs push_swap.a ${OBJS}
			${CC} ${CFLAGS} push_swap.a -o ${NAME}

all:	${NAME} bonus

clean:
		make clean -C ${LIBFT_DIR}
		${RM} ${OBJS}
		${RM} ${OBJS_BONUS}

fclean: clean
		make fclean -C ${LIBFT_DIR}
		${RM} ${NAME} push_swap.a
		${RM} checker

re:	clean all

bonus:	${OBJS_BONUS}
		make -C ${LIBFT_DIR}
		cp ${LIBFT_PATH} push_swap.a
		ar rcs push_swap.a ${OBJS_BONUS}
		${CC} ${CFLAGS} push_swap.a -o checker

test:	
		@shuf -i 1-100 > nbr.txt
		valgrind ./push_swap `cat nbr.txt`
		rm -f nbr.txt