NAME = libfdf.a

C_FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = fdf.c \
		ft_key_hook.c \
		ft_mouse_hook.c \
		ft_expose_hook.c

LIBDIR = ./libft

OBJ = $(SRC:.c=.o)

INCL = $(LIBDIR) \
		./
all: $(NAME)

$(LIBDIR)/libft.a:
	make -C $(LIBDIR)

%.o:%.c1
	gcc $(C_FLAGS) -c $< -o mlx $@ -g $(addprefix -I, $(INCL)) $(MLX_FLAGS)

$(NAME): $(OBJ) | $(LIBDIR)/libft.a
	cp $(LIBDIR)/libft.a $(NAME)
	ar -rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBDIR) clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBDIR)/libft.a

re: fclean all
