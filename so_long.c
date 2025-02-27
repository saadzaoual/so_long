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

int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
        return (ft_printf("Error: Invalid arguments!\nUsage: ./so_long <map.ber>\n"), 1);

    game.mlx = mlx_init();
    if (!game.mlx)
        return (ft_printf("Error: Failed to initialize MLX\n"), 1);

    game.map = read_map(av[1]);
    if (!game.map)
        return (ft_printf("Error: Failed to read map\n"), cleanup_game(&game), 1);

    if (validate_map_contents(game.map))  // Validate map contents (player, exit, collectible)
        return (1);
    game.map_width = ft_strlen(game.map[0]) - 1;
    game.map_height = 0;
    while (game.map[game.map_height])
        game.map_height++;
    if(!ft_check_border(game.map,game.map_width, game.map_height))
        return 0;
    if (game.map_width > 1920 / TITLE_SIZE || game.map_height > 1080 / TITLE_SIZE)
        return (ft_printf("Error: Map size exceeds limit!\nWidth: %d | Height: %d\n", 
                          game.map_width, game.map_height), cleanup_game(&game), 1);
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
