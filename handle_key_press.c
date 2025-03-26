/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:55:14 by isel-kha          #+#    #+#             */
/*   Updated: 2025/03/25 23:55:16 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_position(t_game *game, int new_x, int new_y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->textures[2],
		game->player_x * TITLE_SIZE, game->player_y * TITLE_SIZE);
	game->player_x = new_x;
	game->player_y = new_y;
	mlx_put_image_to_window(game->mlx, game->window, game->textures[0],
		game->player_x * TITLE_SIZE, game->player_y * TITLE_SIZE);
	if (game->collectibles_collected == game->collectibles_total)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->textures[4],
			game->exit_x * TITLE_SIZE, game->exit_y * TITLE_SIZE);
	}
}

void	handle_collectibles_and_exit(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == MONEY)
	{
		game->collectibles_collected++;
		game->map[new_y][new_x] = EMPTY;
	}
	if (game->map[new_y][new_x] == EXIT
		&& game->collectibles_collected == game->collectibles_total)
	{
		ft_printf("You collected all money! Game over.\n");
		cleanup_game(game);
	}
	else if (game->map[new_y][new_x] == EXIT)
	{
		ft_printf("Collect all money first!\n");
	}
}

int	handle_key_press(int keycode, void *param)
{
	t_game		*game;
	int			new_x;
	int			new_y;
	static int	moves = 0;

	game = (t_game *)param;
	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == ESC_KEY || keycode == Q_KEY)
	{
		ft_printf("You quitted the game!\n");
		cleanup_game(game);
	}
	handle_key_movement(keycode, &new_x, &new_y);
	if (game->map[new_y][new_x] == WALL)
		return (0);
	if (is_key(keycode))
	{
		moves++;
		ft_printf("Moves: %d\n", moves);
		handle_collectibles_and_exit(game, new_x, new_y);
		update_player_position(game, new_x, new_y);
	}
	return (0);
}

void	move_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == PLAYER)
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
