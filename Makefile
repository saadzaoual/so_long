NAME := so_long

SRC := so_long.c
OBJ := $(SRC:.c=.o)

CC := cc #-g3 -fsanitize=address

CFLAGS := -Wall -Wextra -Werror

LIBXFLAGS := -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf/
	make -C libft/
	$(CC) $(OBJ) $(LIBXFLAGS) ft_printf/libftprintf.a libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C ft_printf fclean
	make -C libft fclean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

