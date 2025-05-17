CC:= cc
CFLAGS:= -Wall -Werror -Wextra
NAME:= so_long

MLX_DIR:= mlx
MLX_INC:= I$(MLX_DIR)

LIBFT_DIR:= libft
LIBFT_A:= $(LIBFT_DIR)/libft.a
LIBFT_INC:= -I$(LIBFT_DIR)

SRCS:= so_long.c get_map.c check_map.c flood_fill.c utils.c \
		gnl/get_next_line.c

OBJS:= $(SRCS:.c=.o)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

all: $(NAME)

debug: CFLAGS += -fsanitize=address -ggdb3
debug: all

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all debug