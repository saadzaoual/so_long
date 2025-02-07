#include "so_long.h"
#include <stdio.h>
#include <string.h>

// add libft;
// fix norminette;
typedef struct s_game
{
    void *mlx;
    void *window;
    char **map;
    int player_x;
    int player_y;
    void *textures[3];
} t_game;

int handle_key_press(int keycode, void *param)
{
    t_game *game = (t_game *)param;

    int new_x = game->player_x;
    int new_y = game->player_y;
    static int moves = 0;

    if (keycode == ESC_KEY || keycode == Q_KEY)
    {
        printf("You quitted the game!");
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
    if (game->map[new_y][new_x] != '1')
    {
        moves++;
        printf("Moves %d\n",moves);
        mlx_put_image_to_window(game->mlx, game->window, game->textures[2], game->player_x * TITLE_SIZE, game->player_y * TITLE_SIZE);
        game->player_x = new_x;
        game->player_y = new_y;
        mlx_put_image_to_window(game->mlx, game->window, game->textures[0], game->player_x * TITLE_SIZE, game->player_y * TITLE_SIZE);
    }
    //correct moves error;
    return (0);
}
int main(int ac, char **av)
{
    t_game game;
    int img_width;
    int img_height;
    int y;
    int map_width;
    int map_height;

    if(ac != 2)
    {
        printf("You got a bloodclat error my youth!\n");
        return (1);
    }
    game.mlx = mlx_init();
    game.map = read_map(av[1]);
    if (!game.map)
    {
        printf("Error: Failed to read map\n");
        return 1;
    }
    map_width = strlen(game.map[0]);
    map_height = 0;
    while (game.map[map_height])
        map_height++;
    if (map_width > 1920 / TITLE_SIZE * 2 || map_height > 1080 / TITLE_SIZE * 2)
    {
        printf("map is unvalid!\n");
        printf("map width: %d\nmap_height: %d\n", map_width,map_height);
        return 0;
    }
    game.window = mlx_new_window(game.mlx, map_width * TITLE_SIZE, map_height * TITLE_SIZE, "so_long");
    game.textures[0] = mlx_xpm_file_to_image(game.mlx, "assets/cj.xpm", &img_width, &img_height);
    game.textures[1] = mlx_xpm_file_to_image(game.mlx, "assets/wall.xpm", &img_width, &img_height);
    game.textures[2] = mlx_xpm_file_to_image(game.mlx, "assets/empty.xpm",&img_width, &img_height);
    y = 0;
    while (y < map_height)
    {
        int x = 0;
        while (game.map[y][x])
        {
            if (game.map[y][x] == PLAYER)
            {
                game.player_x = x;
                game.player_y = y;
            }
            x++;
        }
        y++;
    }
    render_map(game.mlx, game.window, game.map, game.textures);
    mlx_key_hook(game.window, (int (*)(int, void *))handle_key_press, &game);
    mlx_loop(game.mlx);
    free_map(game.map);

    return (0);
}

