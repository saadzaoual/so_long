/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:54:52 by isel-kha          #+#    #+#             */
/*   Updated: 2025/03/25 23:54:55 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	has_valid_ber_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename) - 5;
	if (len < 5)
		return (0);
	if (ft_strncmp(filename + len + 5 - 4, ".ber", len) != 0)
		return (0);
	if (filename[0] == '.' && len == 4)
		return (0);
	return (1);
}

void	check_map_dimensions(t_game *game)
{
	game->map_width = ft_strlen(game->map[0]) - 1;
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	if (game->map_width <= 0 || game->map_height <= 0)
	{
		ft_printf("Error: Invalid map dimensions!\n");
		cleanup_game2(game);
		exit(1);
	}
}

int	is_key(int keycode)
{
	return (keycode == UP_KEY || keycode == DOWN_KEY
		|| keycode == LEFT_KEY || keycode == RIGHT_KEY);
}

void	handle_key_movement(int keycode, int *new_x, int *new_y)
{
	if (keycode == UP_KEY)
		(*new_y)--;
	else if (keycode == DOWN_KEY)
		(*new_y)++;
	else if (keycode == LEFT_KEY)
		(*new_x)--;
	else if (keycode == RIGHT_KEY)
		(*new_x)++;
}

void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->collectibles_total = 0;
	game->collectibles_collected = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == MONEY)
				game->collectibles_total++;
			x++;
		}
		y++;
	}
	ft_printf("Total collectibles: %d\n", game->collectibles_total);
}
