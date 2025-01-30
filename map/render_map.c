#include "../so_long.h"
#include <mlx.h>

void render_map(void *mlx, void *window, char **map, void **textures)
{
    int x, y;
    int img_width = 64;  // Assuming the image size is 64x64 for each tile
    int img_height = 64;

    for (y = 0; map[y] != NULL; y++)
    {
        for (x = 0; map[y][x] != '\0'; x++)
        {
            if (map[y][x] == '1')
                mlx_put_image_to_window(mlx, window, textures[2], x * img_width, y * img_height); // Wall
            else if (map[y][x] == '0')
                mlx_put_image_to_window(mlx, window, textures[1], x * img_width, y * img_height); // Empty space
            else if (map[y][x] == 'P')
                mlx_put_image_to_window(mlx, window, textures[0], x * img_width, y * img_height); // Player
        }
    }
}

