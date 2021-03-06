NAME = fdf

C_FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

SRC = main.c \
		fdf.c \
		ft_init_var_and_center_screen.c \
		ft_get_input_dim_w_h.c \
		ft_get_pts_coordinate.c \
		ft_project.c \
		get_next_line.c \
		ft_draw_all_lines.c \
		ft_put_pixel_on_image.c \
		ft_key_hook.c

SRCS = $(addprefix ./src/, $(SRC))
OBJS = $(addprefix ./src/, $(SRC:.c=.o))

LIBFT = -L./libft -lft

LIBFT_PATH = ./libft

MLX_PATH = ./mlx

all: $(NAME)

$(OBJS): $(SRCS)
	gcc $(C_FLAGS) -c $< -o $@

$(NAME):$(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	gcc $(C_FLAGS) -o $(NAME) $(SRCS) $(MLX_FLAGS) $(LIBFT)

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
