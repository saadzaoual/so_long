NAME = so_long

SRC = so_long.c read_map.c render_map.c ft_printf/ft_printf.c  ft_printf/ft_printf_functions.c \
			get_next_line.c get_next_line_utils.c handle_key_press.c load_textures.c validate_map.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

MLXFLAGS = -lmlx -lXext -lX11

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(LIBFT): FORCE
	@make -C libft --no-print-directory

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C libft --no-print-directory

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft --no-print-directory

re: fclean all

.PHONY: all clean fclean re FORCE
