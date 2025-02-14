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

    game->textures[0] = mlx_xpm_file_to_image(game->mlx, "assets/cj.xpm",
                                              &img_width, &img_height);
    if (!game->textures[0])
        cleanup_game(game);

    game->textures[1] = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
                                              &img_width, &img_height);
    if (!game->textures[1])
    {
        free_textures(game);
        cleanup_game(game);
    }

    game->textures[2] = mlx_xpm_file_to_image(game->mlx, "assets/empty.xpm",
                                              &img_width, &img_height);
    if (!game->textures[2])
    {
        free_textures(game);
        cleanup_game(game);
    }

    game->textures[3] = mlx_xpm_file_to_image(game->mlx, "assets/money6.xpm",
                                              &img_width, &img_height);
    if (!game->textures[3])
    {
        free_textures(game);
        cleanup_game(game);
    }

    game->textures[4] = mlx_xpm_file_to_image(game->mlx, "assets/car.xpm",
                                              &img_width, &img_height);
    if (!game->textures[4])
    {
        free_textures(game);
        cleanup_game(game);
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
            if (game->map[y][x] == 'C')
                game->collectibles_total++;
            x++;
        }
        y++;
    }
    printf("Total collectibles: %d\n", game->collectibles_total);
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

int handle_close(t_game *game)
{
    cleanup_game(game);
    return (0);
}

int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
    {
        ft_printf("You got a bloodclat error my youth!\n");
        return (1);
    }

    game.mlx = mlx_init();
    if (!game.mlx)
    {
        ft_printf("Error: Failed to initialize mlx\n");
        return (1);
    }

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

    if (game.map_width > 1920 / TITLE_SIZE || game.map_height > 1080 / TITLE_SIZE)
    {
        ft_printf("Map is invalid!\n");
        ft_printf("Map width: %d\nMap height: %d\n", game.map_width, game.map_height);
        cleanup_game(&game);
    }

    load_textures(&game);
    count_collectibles(&game);
    move_player(&game);
    render_map(game.mlx, game.window, game.map, game.textures);

    mlx_hook(game.window, 17, 0, handle_close, &game);
    mlx_key_hook(game.window, handle_key_press, &game);
    mlx_loop(game.mlx);

    cleanup_game(&game);
    return (0);
}

