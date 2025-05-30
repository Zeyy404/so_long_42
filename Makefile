CC:= cc
CFLAGS:= -Wall -Werror -Wextra
NAME:= so_long
NAME_BONUS := so_long_bonus
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX_DIR:= minilibx-linux
else
	MLX_DIR:= minilibx_opengl
endif
MLX_LIB := $(MLX_DIR)/libmlx.a
MLX_INC:= -I$(MLX_DIR)

LIBFT_DIR:= libft
LIBFT_A:= $(LIBFT_DIR)/libft.a
LIBFT_INC:= -I$(LIBFT_DIR)

FT_PRINTF_DIR:= ft_printf
FT_PRINTF_A:= $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_INC:= -I$(FT_PRINTF_DIR)

SRCS:= src/so_long.c src/get_map.c src/check_map.c src/flood_fill.c src/utils.c \
		src/setup_hooks.c src/player.c src/render_map.c src/starfield.c \
		gnl/get_next_line.c

OBJS:= $(SRCS:.c=.o)

BONUS:= src/so_long.c src/get_map.c bonus/check_map.c src/flood_fill.c bonus/utils.c \
		src/setup_hooks.c bonus/player.c bonus/render_map.c src/starfield.c bonus/enemy.c \
		gnl/get_next_line.c

OBJSB:= $(BONUS:.c=.o)

ifeq ($(UNAME_S),Linux)
	MLX_FLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
else
	MLX_FLAGS := -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) bonus -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(FT_PRINTF_A):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(info SRCS: $(SRCS))
$(info OBJS: $(OBJS))

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_LIB) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJSB) $(LIBFT_A) $(MLX_LIB) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) $(OBJSB) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf \
		$(MLX_FLAGS) -o $(NAME_BONUS)

debug: CFLAGS += -fsanitize=address -ggdb3
debug: all

%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(MLX_INC) $(FT_PRINTF_INC) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJSB)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: re fclean clean all debug bonus