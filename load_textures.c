/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:10:16 by szaoual           #+#    #+#             */
/*   Updated: 2025/02/28 23:19:24 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_textures(t_game *game)
{
    int img_width = 128;
    int img_height = 128;

    game->window = mlx_new_window(game->mlx, game->map_width * TITLE_SIZE,
                                  game->map_height * TITLE_SIZE, "so_long");
    if (!game->window)
    {
        ft_printf("Error: Failed to create window\n");
        cleanup_game(game);
    }

    game->textures[0] = mlx_xpm_file_to_image(game->mlx, "textures/cj.xpm",
                                              &img_width, &img_height);
    if (!game->textures[0])
        cleanup_game(game);

    game->textures[1] = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
                                              &img_width, &img_height);
    if (!game->textures[1])
    {
        free_textures(game);
        cleanup_game(game);
    }

    game->textures[2] = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm",
                                              &img_width, &img_height);
    if (!game->textures[2])
    {
        free_textures(game);
        cleanup_game(game);
    }

    game->textures[3] = mlx_xpm_file_to_image(game->mlx, "textures/money6.xpm",
                                              &img_width, &img_height);
    if (!game->textures[3])
    {
        free_textures(game);
        cleanup_game(game);
    }

    game->textures[4] = mlx_xpm_file_to_image(game->mlx, "textures/car.xpm",
                                              &img_width, &img_height);
    if (!game->textures[4])
    {
        free_textures(game);
        cleanup_game(game);
    }
}
void free_textures(t_game *game)
{
    if (game->mlx)
    {
        if (game->textures[0])
            mlx_destroy_image(game->mlx, game->textures[0]);
        if (game->textures[1])
            mlx_destroy_image(game->mlx, game->textures[1]);
        if (game->textures[2])
            mlx_destroy_image(game->mlx, game->textures[2]);
        if (game->textures[3])
            mlx_destroy_image(game->mlx, game->textures[3]);
        if (game->textures[4])
            mlx_destroy_image(game->mlx, game->textures[4]);
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