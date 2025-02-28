/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:04:28 by szaoual           #+#    #+#             */
/*   Updated: 2025/02/28 23:22:06 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO: Copy map dlkhra!$@!$@#%

char **copy_map(char **map)
{
    int y = 0, x;
    char **map_copy;

    while (map[y])
        y++;
    map_copy = (char **)malloc((y + 1) * sizeof(char *));
    if (!map_copy)
        return (NULL);
    map_copy[y] = NULL;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
            x++;
        map_copy[y] = (char *)malloc((x + 1) * sizeof(char));
        if (!map_copy[y])
            return (NULL);
        x = 0;
        while (map[y][x])
        {
            map_copy[y][x] = map[y][x];
            x++;
        }
        map_copy[y][x] = '\0';
        y++;
    }
    return (map_copy);
}


// Flood fill function
void flood_fill(char **map, int x, int y)
{
    if (!map || x < 0 || y < 0 || !map[y] || map[y][x] == '1' || map[y][x] == 'F')
        return;

    map[y][x] = 'F'; // Mark as visited

    flood_fill(map, x + 1, y); // Right
    flood_fill(map, x - 1, y); // Left
    flood_fill(map, x, y + 1); // Down
    flood_fill(map, x, y - 1); // Up
}
int is_valid_path(char **map)
{
    int x = 0, y = 0, player_x = -1, player_y = -1;
    char **map_copy;

    while (map[y]) // Find player position
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                player_x = x;
                player_y = y;
            }
            x++;
        }
        y++;
    }
    if (player_x == -1 || player_y == -1)
        return (printf("Error: No player found!\n"), 0);

    map_copy = copy_map(map);
    if (!map_copy)
        return (printf("Error: Memory allocation failed!\n"), 0);

    flood_fill(map_copy, player_x, player_y);

    y = 0;
    while (map_copy[y]) // Check if any 'C' or 'E' remains
    {
        x = 0;
        while (map_copy[y][x])
        {
            if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
            {
                printf("Error: Unreachable collectibles or exit!\n");
                free_map(map_copy);
                return (0);
            }
            x++;
        }
        y++;
    }

    free_map(map_copy); // Free memory before returning
    return (1);
}
