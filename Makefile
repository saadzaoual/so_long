
NAME = so_long

# Sources and objects
SRC = so_long.c map/read_map.c map/render_map.c
OBJ = $(SRC:.c=.o)

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.  # Include current directory

# MLX libraries
MLXFLAGS = -lmlx -lXext -lX11

# Build the final executable
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLXFLAGS) -o $(NAME)  # Linking with object files

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean object files and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

