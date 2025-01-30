#include "so_long.h"
#include <stdio.h>
#include <string.h>  // For strlen

int handle_key_press(int keycode, void *param)
{
    void **mlx_data = (void **)param;

    printf("Key_pressed : %d \n", keycode);

    if (keycode == ESC_KEY || keycode == Q_KEY)
    {
        mlx_destroy_window(mlx_data[0], mlx_data[1]);
        exit(0);
    }

    return (0);
}

int main(void)
{
    void *mlx;
    void *window;
    int img_width, img_height;
    void *mlx_data[2];
    char **map;
    void *textures[3];
    int map_width, map_height;

    mlx = mlx_init();

    // Read the map and calculate its dimensions
    map = read_map("map/map.ber");
    if (!map)
    {
        printf("Error: Failed to read map\n");
        return 1;
    }

    // Calculate map dimensions
    map_height = 0;
    while (map[map_height])
        map_height++;
    map_width = strlen(map[0]); // Assuming all rows have the same length

    // Set the window size based on the map size
    window = mlx_new_window(mlx, map_width * TITLE_SIZE, map_height * TITLE_SIZE,"so_long");

    mlx_data[0] = mlx;
    mlx_data[1] = window;

    // Load textures
    textures[0] = mlx_xpm_file_to_image(mlx, "assets/player.xpm", &img_width, &img_height);
    textures[1] = mlx_xpm_file_to_image(mlx, "assets/empty.xpm", &img_width, &img_height);
    textures[2] = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", &img_width, &img_height);

    // Render the map
    render_map(mlx, window, map, textures);

    mlx_key_hook(window, handle_key_press, mlx_data);
    mlx_loop(mlx);

    // Free memory after the loop ends
    free_map(map);

    return 0;
}

