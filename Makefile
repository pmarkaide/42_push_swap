# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 13:54:02 by pmarkaid          #+#    #+#              #
#    Updated: 2024/07/27 16:01:37 by pmarkaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS_FILES = \
	main.c \
	input.c \
	utils.c \
	nbrs_are_valid.c \
	moves.c \
	list_utils.c \
	push_swap.c \
	stack_utils.c \
	costs.c \
	execute_moves.c \
	free.c

SRC_DIR = src/
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))

BONUS_NAME = checker

BONUS_FILES = \
	main_bonus.c \
	input_bonus.c \
	utils_bonus.c \
	nbrs_are_valid_bonus.c \
	moves_bonus.c \
	list_utils_bonus.c \
	execute_moves_bonus.c \
	free_bonus.c \
	checker_bonus.c

SRCS_BONUS = $(addprefix $(SRC_DIR), $(BONUS_FILES))

INCLUDE = -I ./include/

LIBFT_DIR = lib/libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_INCLUDE = -I $(LIBFT_DIR)

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

all: makelibft $(NAME)

makelibft:
	make -C $(LIBFT_DIR)

bonus: makelibft checker

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_INCLUDE) $(INCLUDE) $(LIBFT) -o $(NAME)

checker: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_INCLUDE) $(INCLUDE) $(LIBFT) -o $(BONUS_NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all makelibft bonus clean fclean re