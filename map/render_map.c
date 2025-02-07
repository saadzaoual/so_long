#include "../so_long.h"
#include <mlx.h>

void render_map(void *mlx, void *window, char **map, void **textures)
{
    int x;
    int y;
    int img_width = 128;
    int img_height = 128;
    
    y = 0;
    while (map[y] != NULL)
    {
      x = 0;
        while(map[y][x] != '\0')
        {
            if (map[y][x] == WALL)
                mlx_put_image_to_window(mlx, window, textures[1], x * img_width, y * img_height);
            else if (map[y][x] == PLAYER)
                mlx_put_image_to_window(mlx, window, textures[0], x * img_width, y * img_height);
            else if(map[y][x] == EMPTY)
                mlx_put_image_to_window(mlx,window, textures[2], x * img_width, y * img_height);
          x++;
        }
        y++;
    }
}

