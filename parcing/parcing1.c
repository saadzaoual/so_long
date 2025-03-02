/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 02:33:25 by szaoual           #+#    #+#             */
/*   Updated: 2025/03/02 02:33:47 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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