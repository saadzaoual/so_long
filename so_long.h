/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:51:37 by szaoual           #+#    #+#             */
/*   Updated: 2025/03/01 22:22:57 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TITLE_SIZE 128
# define Q_KEY 113
# define ESC_KEY 65307
# define PLAYER 'P'
# define WALL '1'
# define EMPTY '0'
# define MONEY 'C'
# define EXIT 'E'
# define UP_KEY 119
# define DOWN_KEY 115
# define RIGHT_KEY 100
# define LEFT_KEY 97
# define MAX_WIDTH 100
# define MAX_HEIGHT 100
# define BUFFER_SIZE 1

# include "./minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "./ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	int		player_x;
	int		player_y;
	void	*textures[5];
	int		map_height;
	int		map_width;
  int   collectibles_collected;
  int   collectibles_total;
}	t_game;
void cleanup_game(t_game *game);
int		is_key(int keycode);
int		handle_key_press(int keycode, void *param);
char	*get_next_line(int fd);
char	*ft_extract_line(char **str);
char	**read_map(const char *file_name);
void	render_map(t_game *game, void *mlx, void *window, char **map, void **textures);
void	free_map(char **map);
void load_textures(t_game *game);
void free_textures(t_game *game);
void move_player(t_game *game);
int handle_close(t_game *game);
void count_collectibles(t_game *game);
int validate_map_contents(char **map);
int    ft_check_border(char **map, int width, int height);
void cleanup_game2(t_game *game);
int is_valid_path(char **map);
#endif
