/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:10:16 by szaoual           #+#    #+#             */
/*   Updated: 2025/03/02 02:29:13 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_texture(t_game *game, char *path, int index)
{
    int img_width = 128;
    int img_height = 128;

    game->textures[index] = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
    if (!game->textures[index])
    {
        free_textures(game);
        cleanup_game(game);
    }
}

void load_textures(t_game *game)
{
    game->window = mlx_new_window(game->mlx, game->map_width * TITLE_SIZE,
                                  game->map_height * TITLE_SIZE, "so_long");
    if (!game->window)
    {
        ft_printf("Error: Failed to create window\n");
        cleanup_game(game);
    }

    load_texture(game, "textures/cj.xpm", 0);
    load_texture(game, "textures/wall.xpm", 1);
    load_texture(game, "textures/empty.xpm", 2);
    load_texture(game, "textures/money6.xpm", 3);
    load_texture(game, "textures/car.xpm", 4);
}

void free_textures(t_game *game)
{
    int i = 0;
    while (i < 5)
    {
        if (game->textures[i])
            mlx_destroy_image(game->mlx, game->textures[i]);
        i++;
    }
}

void cleanup_game(t_game *game)
{
    if (game)
    {
        free_textures(game);

        if (game->mlx && game->window)
            mlx_destroy_window(game->mlx, game->window);

        if (game->map)
            free_map(game->map);

        if (game->mlx)
        {
            mlx_destroy_display(game->mlx);
            free(game->mlx);
        }
    }
    exit(0);
}

int handle_close(t_game *game)
{
    cleanup_game(game);
    return (0);
}

void cleanup_game2(t_game *game)
{
    if (game)
    {
        if (game->map)
            free_map(game->map);

        if (game->mlx)
        {
            mlx_destroy_display(game->mlx);
            free(game->mlx);
        }
    }
    exit(0);
}