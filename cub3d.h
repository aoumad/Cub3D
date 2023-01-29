#ifndef CUB3D_HPP
#define CUB3D_HPP

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>

#include "mlx.h"
#include "libft.h"
#include "get_next_line.h"


#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_SHIFT 257
#define KEY_CTRL 256

#define KEY_PRESS 2
#define KEY_RELEASE 3
#define KEY_EXIT 17

#define TEX_WIDTH 64
#define TEX_HEIGHT 64

#define FOV 60
#define FOV_RAD (FOV * M_PI / 180)
#define HALF_FOV (FOV / 2)
#define HALF_FOV_RAD (FOV_RAD / 2)
#define NUM_RAYS 1200
#define DIST_PROJ_PLANE ((NUM_RAYS / 2) / tan(HALF_FOV_RAD))
#define DIST_PROJ_PLANE_SQ (DIST_PROJ_PLANE * DIST_PROJ_PLANE)
#define TILE_SIZE 64
#define TILE_SIZE_SQ (TILE_SIZE * TILE_SIZE)
#define NUM_TILES 8
#define NUM_TILES_SQ (NUM_TILES * NUM_TILES)
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define MAP_SIZE (MAP_WIDTH * MAP_HEIGHT)
#define MINIMAP_SCALE_FACTOR 0.2

#define NUM_SPRITES 10

#define PLAYER_SPEED 5
#define ROT_SPEED 3

#define ERROR 0
#define SUCCESS 1

#define NORTH 0
#define SOUTH 1
#define WEST 2
#define EAST 3

#define NO 0
#define SO 1
#define WE 2
#define EA 3
#define S 4
#define F 5
#define C 6

#define MAX_INT 2147483647

// mlx struct
typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_mlx;

// parsing struct
typedef struct s_parse
{
    int     res_x;
    int     res_y;
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *s;
    int     f[3];
    int     c[3];
    char    **map;
    int     map_width;
    int     map_height;
    int     player_x;
    int     player_y;
    char    player_dir;
    int     save;
    t_mlx   *s_mlx;
}               t_parse;

