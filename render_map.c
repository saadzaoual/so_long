/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:06:25 by szaoual           #+#    #+#             */
/*   Updated: 2025/03/01 22:22:32 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	render_map(t_game *game, void *mlx, void *window, char **map, void **textures)
{
	int	x;
	int	y;
    int img_width;
    int img_height;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		img_height = 128;
        img_width = 128;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == WALL)
				mlx_put_image_to_window(mlx, window,
					textures[1], x * img_width, y * img_height);
			else if (map[y][x] == PLAYER)
				mlx_put_image_to_window(mlx, window,
					textures[0], x * img_width, y * img_height);
			else if (map[y][x] == EMPTY)
				mlx_put_image_to_window(mlx, window,
					textures[2], x * img_width, y * img_height);
            else if(map[y][x] == MONEY)
                mlx_put_image_to_window(mlx,window,
                    textures[3],x * img_width, y * img_height);
            else if(map[y][x] == EXIT && game->collectibles_collected == game->collectibles_total)
                mlx_put_image_to_window(mlx,window,
                    textures[4],x *img_width, y * img_height);
			x++;
		}
		y++;
	}
}
