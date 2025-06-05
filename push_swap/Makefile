CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT = ./libft/libft.a
INCLUDE = -I./include
SRC = ./src/check.c\
./src/main.c\
./src/op_push.c\
./src/op_rotate.c\
./src/op_rrotate.c\
./src/op_swap.c\
./src/parsing.c\
./src/parsing2.c\
./src/radix_sort.c\
./src/sorting.c

OBJS = $(SRC:.c=.o)

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus