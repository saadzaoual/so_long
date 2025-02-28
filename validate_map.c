/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:49:40 by szaoual           #+#    #+#             */
/*   Updated: 2025/02/27 13:49:42 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int validate_map_contents(char **map)
{
    int player_count = 0;
    int exit_count = 0;
    int collectible_count = 0;
    int row = 0;
    int col;

    while (map[row] != NULL) {
        col = 0;
        while (map[row][col] != '\0')
        {
            if (map[row][col] == 'P')  
                player_count++;
            else if (map[row][col] == 'E') 
                exit_count++;
            else if (map[row][col] == 'C') 
                collectible_count++;
            col++;
        }
        row++;
    }

    if (player_count != 1) {
        ft_printf("Error: There must be exactly one player (P)\n");
        return (1);
    }
    if (exit_count != 1) {
        ft_printf("Error: There must be exactly one exit (E)\n");
        return (1);
    }
    if (collectible_count < 1) {
        ft_printf("Error: There must be at least one collectible (C)\n");
        return (1);
    }

    return (0);
}
int ft_check_border(char **map, int width, int height)
{
    int x, y;
    y = 0;
    
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            // Check top row (y == 0)
            if (y == 0 || y == height - 1)
            {
                if (map[y][x] != '1')
                {
                    //ft_putstr_fd("Error: Map is not surrounded by walls\n", 2);
                    return (0);
                }
            }
            // Check left and right columns (x == 0 || x == width - 1)
            if (x == 0 || x == width - 1)
            {
                if (map[y][x] != '1')
                {
                    //ft_putstr_fd("Error: Map is not surrounded by walls\n", 2);
                    return (0);
                }
            }
            x++;
        }
        y++;
    }
    return (1);
}
