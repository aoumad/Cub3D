/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:26 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/22 12:50:27 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include "libft/libft.h"
#include "GNL/get_next_line.h"


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

#define S 4
#define F 5
#define C 6

#define MAX_INT 2147483647
// typedef struct s_parse;

// enum struct
typedef enum e_flag
{
    NONE,
    PATH_FLAG,
    F_FLAG,
    C_FLAG,
    NO,
    SO,
    WE,
    EA
}   t_flag;

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

// file descriptor struct
typedef struct s_fd
{
    int     fd;
    char    *line;
}               t_fd;

typedef struct s_cor
{
    int     x;
    int     y;
}               t_cor;

typedef struct s_index
{
    int i;
    int j;
}           t_index;

// parsing struct
typedef struct s_parse
{
    int     res_x;
    int     res_y;
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    // char    *s;
    int     f[3];
    int     c[3];
    char    **map;
    char    **sim;
    int     sim_height;
    int     sim_width;
    int     map_width;
    int     map_height;
    int     player_x;
    int     player_y;
    char    player_dir;
    t_mlx   *s_mlx;
    t_fd    *s_fd;
    t_cor   *s_cor;
    t_index *s_index;
}               t_parse;


// parsing functions //
void    init_data(t_parse *parse);
void    ft_helper();
t_parse ft_parse(char **argv, t_parse *parse);
void    ft_read_file(char *file, t_parse *parse);
void    ft_check_arg(char **arg);
// void    ft_check_file(char *file, t_parse *parse);
void    ft_check_map(t_parse *parse);
void    ft_check_map2(int *tab, char *map, t_parse *parse, int j);
void    ft_duplicate_pattern(int *tab, char *map, int flag, t_parse *parse, int j);
void    ft_check_map_chars(char **map, t_parse *parse);
void    ft_check_map_walls(char **map, t_parse *parse);
void    ft_check_map_player(char **map, t_parse *parse);
void    ft_check_map_surrounded(char **map, t_parse *parse);
void    ft_check_map_closed(t_parse *parse);
void    ft_check_map_valid(char **map, t_parse *parse);
void    ft_check_map_valid_helper(char **map, int x, int y, int *visited);
void    ft_insert_texture_path(t_parse *parse, char *map, int flag, int i, int len);

void    ft_check_texture_path(t_parse *parse, char *map, int flag, int i);
void    ft_check_color(t_index index, int row, char *map, int flag, t_parse *parse);
void    ft_second_half_checker(t_parse *parse, int *tab, int i, int j);
void    ft_dfs(t_parse *parse, int **visited, int i, int j, int *flag);
void    ft_insert_color(int row, t_parse *parse, int flag, int num);
void    ft_insert_simulation(t_parse *parse);

// utils functions //
int     ft_isspace(char *map, int index);
void    ft_half_done(int *tab, t_parse *parse);
int	    ft_atoi_color(const char *str, int begin, int end);
void    ft_isspace_2D(char **map, t_cor *s_cor);
int     ft_standard_isspace(char c);
int     ft_edges_checker(t_parse *parse, int i, int j);
void    ft_error(char *str);
size_t	ft_strlen_mine(const char *s, int j);
int     ft_isspace_no_n(char *map, int index);
void    ft_mark_texture_path(int *tab, char *map, int flag, int j);
#endif