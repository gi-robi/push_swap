# -*- Makefile -*-

NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/checker.c src/error_check.c src/initialize_values.c src/ft_split.c src/utilities.c src/operations_a.c src/operations_b.c src/operations_both.c src/gnl/get_next_line.c src/gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
HEADER = includes/checker.h

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

