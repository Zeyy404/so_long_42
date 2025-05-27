CC:= cc
CFLAGS:= -Wall -Wextra -Werror
SRCS:= ft_printf.c ft_putint.c ft_putuint.c ft_putchr.c \
		ft_putstr.c ft_puthex.c ft_putptr.c ft_putpct.c \
		util_printf.c util_libft.c util_flags.c
OBJS:= $(SRCS:.c=.o)

HEADER = ft_printf.h

NAME:= libftprintf.a

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

debug: CFLAGS += -ggdb3
debug: all

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all bonus debug
