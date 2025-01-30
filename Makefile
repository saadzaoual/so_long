NAME = so_long

SRC = so_long.c
OBJ = $(SRC:.c=.o)

CC = cc #-g3 -fsanitize=address

LiBFT = libft.a
LIBPRINTF = libftprintf.a
LIBFTDIR = libft
FT_PRINTFDIR = ft_printf
CFLAGS = -Wall -Wextra -Werror   # Include path for mlx.h

MLXFLAGS = -L/usr/lib -lmlx -lXext -lX11

all: $(NAME)

$(LiBFT):
	make -C $(LIBFTDIR)
$(LIBPRINTF):
	make -C $(FT_PRINTFDIR)

$(NAME): $(LiBFT) $(OBJ)
	$(CC) $(OBJ) $(MLXFLAGS) -L$(LIBFTDIR) -lft -I$(LIBFTDIR) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFTDIR) fclean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
