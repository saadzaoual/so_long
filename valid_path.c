/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:55:46 by isel-kha          #+#    #+#             */
/*   Updated: 2025/03/25 23:55:51 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	int		y;
	int		x;
	char	**map_copy;

	y = 0;
	while (map[y])
		y++;
	map_copy = (char **)malloc((y + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	map_copy[y] = NULL;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		map_copy[y] = (char *)malloc((x + 1) * sizeof(char));
		if (!map_copy[y])
			return (NULL);
		ft_strlcpy(map_copy[y], map[y], x + 1);
		y++;
	}
	return (map_copy);
}

void	flood_fill(char **map, int x, int y)
{
	if (!map || x < 0 || y < 0 || !map[y]
		|| map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	find_player_position(char **map, int *player_x, int *player_y)
{
	int	x;
	int	y;

	*player_x = -1;
	*player_y = -1;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*player_x = x;
				*player_y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_unreachable(char **map_copy)
{
	int	x;
	int	y;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
			{
				printf("Error: Unreachable collectibles or exit!\n");
				free_map(map_copy);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	is_valid_path(char **map)
{
	int		player_x;
	int		player_y;
	char	**map_copy;

	if (!find_player_position(map, &player_x, &player_y))
		return (printf("Error: No player found!\n"), 0);
	map_copy = copy_map(map);
	if (!map_copy)
		return (printf("Error: Memory allocation failed!\n"), 0);
	flood_fill(map_copy, player_x, player_y);
	if (!check_unreachable(map_copy))
		return (0);
	free_map(map_copy);
	return (1);
}
