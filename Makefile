# -*- Makefile -*-

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/push_swap.c src/error_check.c src/ft_split.c src/utilities.c src/operations_a.c src/operations_b.c src/operations_both.c src/sorting_stack.c src/initialize_values.c src/sort_3.c src/sort_turk.c
OBJS = $(SRCS:.c=.o)
HEADER = includes/push_swap.h

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@chmod +x $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
