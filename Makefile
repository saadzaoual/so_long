NAME = so_long

SRC = so_long.c map/read_map.c map/render_map.c ft_printf/ft_printf.c  ft_printf/ft_printf_functions.c \
			get_next_line.c get_next_line_utils.c handle_key_press.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

MLXFLAGS = -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

