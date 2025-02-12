/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:08:01 by szaoual           #+#    #+#             */
/*   Updated: 2025/02/12 15:51:17 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	int	img_width;
	int	img_height;

	img_width = 128;
	img_height = 128;
	game->window = mlx_new_window(game->mlx, game->map_width * TITLE_SIZE,
			game->map_height * TITLE_SIZE, "so_long");
	game->textures[0] = mlx_xpm_file_to_image(game->mlx, "assets/cj.xpm",
			&img_width, &img_height);
	game->textures[1] = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&img_width, &img_height);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx, "assets/empty.xpm",
			&img_width, &img_height);
	if (!game->textures[0] || !game->textures[1] || !game->textures[2]
		|| !game->textures[3])
	{
		printf("Error loading textures\n");
		exit(1);
	}
}

void	move_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == PLAYER)
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("You got a bloodclat error my youth!\n");
		return (1);
	}
	game.mlx = mlx_init();
	game.map = read_map(av[1]);
	if (!game.map)
	{
		ft_printf("Error: Failed to read map\n");
		return (1);
	}
	game.map_width = strlen(game.map[0]) - 1;
	game.map_height = 0;
	while (game.map[game.map_height])
		game.map_height++;
	if (game.map_width > 1920 / TITLE_SIZE
		|| game.map_height > 1080 / TITLE_SIZE)
	{
		ft_printf ("map is unvalid!\n");
		ft_printf ("map width: %d\nmap_height: %d\n", game.map_width,
			game.map_height);
		return (0);
	}
	load_textures(&game);
	move_player(&game);
	render_map(game.mlx, game.window, game.map, game.textures);
	mlx_key_hook(game.window, handle_key_press, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	return (0);
}
