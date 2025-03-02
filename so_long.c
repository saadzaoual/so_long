/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:08:01 by szaoual           #+#    #+#             */
/*   Updated: 2025/03/02 02:55:19 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_borders(t_game *game)
{
	if (!ft_check_border(game->map, game->map_width, game->map_height))
	{
		ft_printf("Error: invalid borders ;)\n");
		cleanup_game2(game);
		exit(1);
	}
}

void	check_map_size(t_game *game)
{
	if (game->map_width > 1920 / TITLE_SIZE
		|| game->map_height > 1080 / TITLE_SIZE)
	{
		ft_printf("Error: Map size exceeds limit!\nWidth: %d | Height: %d\n",
			game->map_width, game->map_height);
		cleanup_game2(game);
		exit(1);
	}
}

void	initialize_game(t_game *game, char *map_file)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: Failed to initialize MLX\n");
		exit(1);
	}
	game->map = read_map(map_file);
	if (!game->map || !game->map[0])
	{
		ft_printf("Error: Failed to read map or the map is empty\n");
		cleanup_game2(game);
		exit(1);
	}
	if (validate_map_contents(game->map))
		exit(1);
	check_map_dimensions(game);
	check_map_borders(game);
	check_map_size(game);
	if (!is_valid_path(game->map))
	{
		cleanup_game2(game);
		exit(1);
	}
}

void	set_exit_coordinates(t_game *game)
{
	int	y;
	int	x;

	game->exit_x = -1;
	game->exit_y = -1;
	y = 0;
	while (y < game->map_height && game->exit_x == -1 && game->exit_y == -1)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == EXIT)
			{
				game->exit_x = x;
				game->exit_y = y;
				break ;
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
		return (ft_printf("Error: Invalid arguments!\n"), 1);
	if (!has_valid_ber_extension(av[1]))
		return (ft_printf("Error: Map file must have a '.ber' extension!\n"), 1);
	initialize_game(&game, av[1]);
	set_exit_coordinates(&game);
	load_textures(&game);
	count_collectibles(&game);
	move_player(&game);
	render_map(&game);
	mlx_hook(game.window, 17, 0, handle_close, &game);
	mlx_key_hook(game.window, handle_key_press, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
