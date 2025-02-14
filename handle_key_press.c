/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:05:39 by szaoual           #+#    #+#             */
/*   Updated: 2025/02/12 15:07:14 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_key(int keycode)
{
    return (keycode == UP_KEY || keycode == DOWN_KEY ||
            keycode == LEFT_KEY || keycode == RIGHT_KEY);
}

int handle_key_press(int keycode, void *param)
{
    t_game *game = (t_game *)param;
    int new_x = game->player_x;
    int new_y = game->player_y;
    static int moves = 0;

    if (keycode == ESC_KEY || keycode == Q_KEY)
    {
        ft_printf("You quitted the game!\n");
        cleanup_game(game);
    }

    switch (keycode)
    {
        case UP_KEY:    new_y--; break;
        case DOWN_KEY:  new_y++; break;
        case LEFT_KEY:  new_x--; break;
        case RIGHT_KEY: new_x++; break;
        default:        return (0);
    }

    if (game->map[new_y][new_x] == '1')
        return (0);

    if (is_key(keycode))
    {
        moves++;
        printf("Moves: %d\n", moves);

        if (game->map[new_y][new_x] == 'C')
        {
            game->collectibles_collected++;
            game->map[new_y][new_x] = '0';
        }

        if (game->map[new_y][new_x] == 'X')
        {
            if (game->collectibles_collected == game->collectibles_total)
            {
                ft_printf("You collected all money! Game over.\n");
                cleanup_game(game);
            }
            else
            {
                ft_printf("Collect all money first!\n");
                return (0);
            }
        }

        mlx_put_image_to_window(game->mlx, game->window, game->textures[2],
                                game->player_x * TITLE_SIZE, game->player_y * TITLE_SIZE);

        game->player_x = new_x;
        game->player_y = new_y;

        mlx_put_image_to_window(game->mlx, game->window, game->textures[0],
                                game->player_x * TITLE_SIZE, game->player_y * TITLE_SIZE);
    }
    return (0);
}

