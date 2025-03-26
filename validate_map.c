/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:55:53 by isel-kha          #+#    #+#             */
/*   Updated: 2025/03/25 23:55:58 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map_elements(char **map, int *player_count, int *exit_count,
	int *collectible_count)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'P')
				(*player_count)++;
			else if (map[row][col] == 'E')
				(*exit_count)++;
			else if (map[row][col] == 'C')
				(*collectible_count)++;
			col++;
		}
		row++;
	}
}

int	check_invalid_chars(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] != 'P' && map[row][col] != 'E' &&
				map[row][col] != 'C' && map[row][col] != '1' &&
				map[row][col] != '0' && map[row][col] != '\n')
			{
				ft_printf("Invalid character '%c' in map\n", map[row][col]);
				return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	validate_map_contents(char **map)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	if (check_invalid_chars(map))
		return (1);
	count_map_elements(map, &player_count, &exit_count, &collectible_count);
	if (player_count != 1 || exit_count != 1 || collectible_count < 1)
	{
		if (player_count != 1)
			ft_printf("Error: There must be exactly one player (P)\n");
		if (exit_count != 1)
			ft_printf("Error: There must be exactly one exit (E)\n");
		if (collectible_count < 1)
			ft_printf("Error: There must be at least one collectible (C)\n");
		return (1);
	}
	return (0);
}

int	ft_check_border(char **map, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if ((y == 0 || y == height - 1 || x == 0 || x == width - 1)
				&& map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
