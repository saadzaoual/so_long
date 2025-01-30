#ifndef SO_LONG_H
#define SO_LONG_H

#define TITLE_SIZE 64

#define Q_KEY 113
#define ESC_KEY 65307

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
char **read_map(const char *file_name);
void render_map(void *mlx, void *window, char **map, void **textures);
void  free_map(char **map);
#endif
