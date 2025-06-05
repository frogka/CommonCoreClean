NAME = libftprintf.a
PRINTF = ft_printf.c\
	ft_putstr_len.c\
	ft_putchar_len.c\
	ft_putnbr_len.c\
	ft_unsigned_len.c\
	ft_hexa_lower.c\
	ft_hexa_upper.c\
	ft_putptr_len.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(PRINTF:.c=.o)

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJECTS)
		$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re