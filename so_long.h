#ifndef SO_LONG_H
#define SO_LONG_H

#define TITLE_SIZE 128

#define Q_KEY 113
#define ESC_KEY 65307

#define PLAYER 'P'
#define WALL '1'
#define EMPTY '0'

#define UP_KEY 119
#define DOWN_KEY 115
#define RIGHT_KEY 100
#define LEFT_KEY 97

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
