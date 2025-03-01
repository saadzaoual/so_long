/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:05:39 by szaoual           #+#    #+#             */
/*   Updated: 2025/03/01 22:54:05 by szaoual          ###   ########.fr       */
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

    if (game->map[new_y][new_x] == WALL)
        return (0);

    if (is_key(keycode))
    {
        moves++;
        printf("Moves: %d\n", moves);

        if (game->map[new_y][new_x] == MONEY)
        {
            game->collectibles_collected++;
            game->map[new_y][new_x] = EMPTY;
        }

        if (game->map[new_y][new_x] == EXIT)
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

        // Render the exit if all collectibles are collected
        if (game->collectibles_collected == game->collectibles_total)
        {
            int exit_x = game->exit_x;
            int exit_y = game->exit_y;
            mlx_put_image_to_window(game->mlx, game->window, game->textures[4],
                                    exit_x * TITLE_SIZE, exit_y * TITLE_SIZE);
        }
    }
    return (0);
}

void move_player(t_game *game)
{
    int x, y;

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
                return;
            }
            x++;
        }
        y++;
    }
}

void count_collectibles(t_game *game)
{
    int x, y;

    game->collectibles_total = 0;
    game->collectibles_collected = 0;
    y = 0;
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
    printf("Total collectibles: %d\n", game->collectibles_total);
}
