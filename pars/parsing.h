/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:26 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/25 16:12:07 by aoumad           ###   ########.fr       */
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
#include "libft_utils/libft.h"
#include "GNL_utils/get_next_line.h"

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
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    // char    *s;
    int     f[3];
    int     c[3];
    // merging rgb colors of `f` and `c`
    int     f_rgb;
    int     c_rgb;
    char    **map;
    char    **sim;
    int     sim_height;
    int     sim_width;
    int     map_width;
    int     map_height;
    int     player_x;
    int     player_y;
    char    player_dir;
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
void    ft_check_map_closed(t_parse *parse);
void    ft_insert_texture_path(t_parse *parse, char *map, int flag, int i, int len);

void    ft_check_texture_path(t_parse *parse, char *map, int flag, int i);
void    ft_read_texture(char *map, int i);
void    ft_check_color(t_index index, int row, char *map, int flag, t_parse *parse);
void    ft_generate_rgb(t_parse *parse, int flag);
int     ft_create_rgb(int r, int g, int b);
void    ft_second_half_checker(t_parse *parse, int *tab, int i, int j);
void    ft_dfs(t_parse *parse, int **visited, int i, int j, int *flag);
void    ft_insert_color(int row, t_parse *parse, int flag, int num);
void    ft_insert_simulation(t_parse *parse);

// utils functions //
int     ft_isspace(char *map, int index);
void    ft_half_done(int *tab, t_parse *parse);
int     ft_atoi_color(const char *str, int begin, int end);
int     ft_standard_isspace(char c);
int     ft_edges_checker(t_parse *parse, int i, int j);
// void    ft_error(t_parse *parse, char *str);
void    ft_error(char *str);
size_t	ft_strlen_mine(const char *s, int j);
int     ft_isspace_no_n(char *map, int index);
void    ft_mark_texture_path(int *tab, char *map, int flag, int j);
int    ft_check_texture_inSim(char *map, int i);
#endif