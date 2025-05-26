CC:= cc
CFLAGS:= -Wall -Werror -Wextra
NAME:= so_long

MLX_DIR:= minilibx_opengl
MLX_LIB := $(MLX_DIR)/libmlx.a
MLX_INC:= -I$(MLX_DIR)

LIBFT_DIR:= libft
LIBFT_A:= $(LIBFT_DIR)/libft.a
LIBFT_INC:= -I$(LIBFT_DIR)

SRCS:= so_long.c get_map.c check_map.c flood_fill.c utils.c \
		setup_hooks.c player.c render_map.c starfield.c enemy.c \
		gnl/get_next_line.c

OBJS:= $(SRCS:.c=.o)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_FLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
else
	MLX_FLAGS := -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) bonus -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(info SRCS: $(SRCS))
$(info OBJS: $(OBJS))

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)


debug: CFLAGS += -fsanitize=address -ggdb3
debug: all

%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(MLX_INC) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

re: fclean all

.PHONY: re fclean clean all debug