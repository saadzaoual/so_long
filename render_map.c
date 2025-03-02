/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:06:25 by szaoual           #+#    #+#             */
/*   Updated: 2025/03/02 02:52:48 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *game, int x, int y, char tile)
{
	int	img_width;
	int	img_height;

	img_width = 128;
	img_height = 128;
	if (tile == WALL)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[1], x * img_width, y * img_height);
	else if (tile == PLAYER)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[0], x * img_width, y * img_height);
	else if (tile == EMPTY)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[2], x * img_width, y * img_height);
	else if (tile == MONEY)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[3], x * img_width, y * img_height);
	else if (tile == EXIT && game->collectibles_collected
		== game->collectibles_total)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures[4], x * img_width, y * img_height);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			render_tile(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
}
