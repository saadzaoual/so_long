/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:08:01 by szaoual           #+#    #+#             */
/*   Updated: 2025/03/01 22:22:36 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int has_valid_ber_extension(char *filename)
{
    int len = ft_strlen(filename) - 5;

    if(len < 5)
    {
        return 0;
    }

    // Check if the filename has at least 5 characters (name + ".ber")

    // Check if the file ends with ".ber"
    if (ft_strncmp(filename + len + 5 - 4, ".ber",len) != 0)
        return 0;

    // Ensure that the filename isn't just ".ber"
    if (filename[0] == '.' && len == 4)
        return 0;

    // If the filename is only ".ber", return false
    if (filename[0] == '.' && len == 4)
        return 0;

    return 1; // Valid filename with a name and the ".ber" extension
}


int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
        return (ft_printf("Error: Invalid arguments!\nUsage: ./so_long <map.ber>\n"), 1);

    if (!has_valid_ber_extension(av[1]))
        return (ft_printf("Error: Map file must have a '.ber' extension!\n"), 1);
    game.mlx = mlx_init();
    if (!game.mlx)
        return (ft_printf("Error: Failed to initialize MLX\n"), 1);

    game.map = read_map(av[1]);
    if (!game.map || !game.map[0])
        return (ft_printf("Error: Failed to read map or the map is empty\n"), cleanup_game2(&game), 1);

    if (validate_map_contents(game.map))
        return (1);
    game.map_width = ft_strlen(game.map[0]) - 1;
    game.map_height = 0;
    while (game.map[game.map_height])
        game.map_height++;
    if (game.map_width <= 0 || game.map_height <= 0)
        return (ft_printf("Error: Invalid map dimensions!\n"), cleanup_game2(&game), 1);
        
    if(!ft_check_border(game.map,game.map_width, game.map_height))
    return (ft_printf("Error: invalid borders ;)\n"), cleanup_game2(&game), 1);
    
    if (game.map_width > 1920 / TITLE_SIZE || game.map_height > 1080 / TITLE_SIZE)
        return (ft_printf("Error: Map size exceeds limit!\nWidth: %d | Height: %d\n", 
                          game.map_width, game.map_height), cleanup_game2(&game), 1);
    if (!is_valid_path(game.map))
        return (cleanup_game2(&game), 1);

    load_textures(&game);
    count_collectibles(&game);
    move_player(&game);
    render_map(&game, game.mlx, game.window, game.map, game.textures);
    mlx_hook(game.window, 17, 0, handle_close, &game);
    mlx_key_hook(game.window, handle_key_press, &game);
    mlx_loop(game.mlx);
    cleanup_game(&game);
    return (0);
}