# -*- Makefile -*-

NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/checker.c src/error_check.c src/initialize_values.c src_ft_split.c src/utilities.c src/operations_a.c src/operations_b.c src/operations_both.c gnl/get_next_line.c gnl/get_next_line_utilities.c
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

