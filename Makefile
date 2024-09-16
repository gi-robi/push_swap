# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 16:20:38 by rgiambon          #+#    #+#              #
#    Updated: 2024/09/16 16:55:17 by rgiambon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAME = push_swap

NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/push_swap.c src/error_check.c src/ft_split.c src/utilities.c src/operations_a.c src/operations_b.c src/operations_both.c src/sorting_stack.c src/initialize_values.c src/sort_3.c src/sort_all.c src/free_memory.c src/list_utils.c src/get_values.c

BONUS_SRC = bonus/src/checker.c bonus/src/error_check.c bonus/src/initialize_values.c bonus/src/ft_split.c bonus/src/utilities.c bonus/src/operations_a.c bonus/src/operations_b.c bonus/src/operations_both.c bonus/src/gnl/get_next_line.c bonus/src/gnl/get_next_line_utils.c bonus/src/free_memory.c

OBJS = $(SRC:.c=.o)

BONUS_OBJS = ${BONUS_SRC:.c=.o}

HEADER = includes/push_swap.h

HEADER_BONUS = bonus/includes/checker.h

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@chmod +x $(NAME)

$(NAME_BONUS) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJS)

%.o: %.c Makefile $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
