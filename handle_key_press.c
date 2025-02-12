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

int   is_key(int keycode)
{
  if (keycode == UP_KEY)
    return (1);
  else if (keycode == DOWN_KEY)
      return (1);
  else if (keycode == LEFT_KEY)
      return (1);
  else if (keycode == RIGHT_KEY)
      return (1);
  return (0);
}
int handle_key_press(int keycode, void *param)
{
    t_game *game = (t_game *)param;

    int new_x = game->player_x;
    int new_y = game->player_y;

    if (keycode == ESC_KEY || keycode == Q_KEY)
    {
        ft_printf("You quitted the game!");
        mlx_destroy_window(game->mlx, game->window);
        exit(0);
    }
    else if (keycode == UP_KEY)
        new_y--;
    else if (keycode == DOWN_KEY)
        new_y++;
    else if (keycode == LEFT_KEY)
        new_x--;
    else if (keycode == RIGHT_KEY)
        new_x++;
    if (game->map[new_y][new_x] != '1' && is_key(keycode))
    {
      static  int moves;
        moves++;
        printf("Moves %d\n",moves);
        mlx_put_image_to_window(game->mlx, game->window, game->textures[2], game->player_x * TITLE_SIZE, game->player_y * TITLE_SIZE);
        game->player_x = new_x;
        game->player_y = new_y;
        mlx_put_image_to_window(game->mlx, game->window, game->textures[0], game->player_x * TITLE_SIZE, game->player_y * TITLE_SIZE);
    }
    return (0);
}
