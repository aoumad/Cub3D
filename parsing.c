/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:22 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/13 12:57:22 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parse ft_parse(char **arg, t_parse *parse)
{
    init_data(&parse);
    ft_check_arg(arg);
    ft_read_file(arg[1], &parse);
    ft_check_map(&parse);
}

void    ft_read_file(char *file, t_parse *parse)
{
    int fd;
    char *line;
    int ret;
    char *buf;
    int i;

    i = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        ft_error("Error\nopen() failed\n");
    line = get_next_line(fd);
    while (line)
    {
        if (line[0] == '\n')
        {
            line[0] = ' ';
            line[1] = '\n';
            line[2] = '\0';
        }
        buf = ft_strjoin(buf, line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    parse->map = ft_split(buf, '\n');
}

void    ft_duplicate_pattern(int *tab, char *map, int flag)
{
    int i;
    
    i = 0;
    if (tab[(unsigned int)map[0]] == 0)
        tab[(unsigned int)map[0]] = 1;
    else
        ft_error("Error\nDuplicate pattern\n");
    
    if (flag == PATH_FLAG)
    {
        i = ft_isspace(map, 2);
        if (i == 0)
            ft_error("Error\nInvalid pattern\n");
        ft_check_texture_path(map, i);
    }
    else if (flag == FC_FLAG)
    {
        i = ft_isspace(map, 1);
        if (i == 0)
            ft_error("Error\nInvalid pattern\n");
        ft_check_color(map, i, 0, &parse, flag);
    }
}

void    ft_check_map2(int *tab, char *map)
{
    int tab[256] = {};
    
    if (map[0] == 'N' && map[1] == 'O')
        ft_duplicate_pattern(&tab, map, PATH_FLAG);
    else if (map[0] == 'S' && map[1] == 'O')
        ft_duplicate_pattern(&tab, map, PATH_FLAG);
    else if (map[0] == 'W' && map[1] == 'E')
        ft_duplicate_pattern(&tab, map, PATH_FLAG);
    else if (map[0] == 'E' && map[1] == 'A')
        ft_duplicate_pattern(&tab, map, PATH_FLAG);
    else if (map[0] == 'F')
        ft_duplicate_pattern(&tab, map, F_FLAG);
    else if (map[0] == 'C')
        ft_duplicate_pattern(&tab, map, C_FLAG);
}

void    ft_check_map(t_parse *parse)
{
    int tab[256] = {};
    int i;
    int j;

    i = 0;
    j = 0;
    while (parse->map[i][j])
    {
        if (parse->map == NULL)
            ft_error("Error\nEmpty map\n");
        parse->s_cor->x = i;
        parse->s_cor->y = j;
        ft_isspace_2D(parse->map, &parse->s_cor);
        i = parse->s_cor->x;
        j = parse->s_cor->y;
        if (parse->map[i][0] == 'N' || parse->map[i][0] == 'S' || parse->map[i][0] == 'W' ||
            parse->map[i][0] == 'C' || parse->map[i][0] == 'E' || parse->map[i][0] == 'F')
            {
                ft_check_map2(&tab, parse->map[i]);
                i++;
            }
        if (tab[(unsigned int)'N'] == 1 && tab[(unsigned int)'S'] == 1 && tab[(unsigned int)'W'] == 1 && 
            tab[(unsigned int)'E'] == 1 && tab[(unsigned int)'F'] == 1 && tab[(unsigned int)'C'] == 1)
            break;
    }
    ft_half_done(&tab);
    ft_second_half_checker(&parse, &tab, i, j);
}


void    ft_second_half_checker(t_parse *parse, int *tab, int i, int j)
{
    ft_check_map_closed(parse, i, j);
    parse->s_cor->x = i;
    parse->s_cor->y = j;
    ft_isspace_2D(parse->map, &parse->s_cor);
    i = parse->s_cor->x;
    j = parse->s_cor->y;
    while (parse->map[i][j])
    {
        if (parse->map[i][j] == '0' || parse->map[i][j] == '1' || parse->map[i][j] == ' ' || parse->map[i][j] == '\t')
            j++;
        if (parse->map[i][j] == '\n')
        {
            i++;
            j = 0;
        }
        if (parse->map[i][j] == 'N' || parse->map[i][j] == 'S' || parse->map[i][j] == 'W' || parse->map[i][j] == 'E')
        {
            if (tab[(unsigned int)ft_tolower(parse->map[i][j])] == 1)
                ft_error("Error\nDuplicate player position\n");
            else if (tab[(unsigned int)ft_tolower(parse->map[i][j])] == 0)
            {
                tab[(unsigned int)ft_tolower(parse->map[i][j])] = 1;
                parse->player_x = i;
                parse->player_y = j;
                parse->player_dir = parse->map[i][j];
                j++;
            }
        }
    }
}

    // check that map walls is surrounded by 1 ==> walls using dfs
void    ft_check_map_closed(t_parse *parse)
{
    int i;
    int j;
    int k;
    int l;
    int flag;
    int **visited;
    
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    flag = 0;
    visited = (int **)malloc(sizeof(int *) * parse->s_cor->x);
    while (i < parse->s_cor->x)
    {
        visited[i] = (int *)malloc(sizeof(int) * parse->s_cor->y);
        i++;
    }
    i = 0;
    while (i < parse->s_cor->x)
    {
        j = 0;
        while (j < parse->s_cor->y)
        {
            visited[i][j] = 0;
            j++;
        }
        i++;
    }
    i = 0;
    while (i < parse->s_cor->x)
    {
        j = 0;
        while (j < parse->s_cor->y)
        {
            if (parse->map[i][j] == '1' && (ft_edges_checker(parse->map, i, j) == 1))
            {
                visited[i][j] = 1;
                k = i;
                l = j;
                ft_dfs(parse, visited, &k, &l, &flag);
            }
            else if (parse->map[i][j] == '0' && (ft_edges_checker(parse->map, i, j) == 1))
                ft_error("Error\nMap is not closed\n");
            j++;
        }
        i++;
    }
    if (flag == 1)
        ft_error("Error\nMap is not closed\n");
}

int ft_edges_checker(char **map, int i, int j)
{
    if (ft_standard_isspace(map[i][j + 1] == 1) || ft_standard_isspace(map[i][j - 1] == 1) ||
        ft_standard_isspace(map[i + 1][j] == 1) || ft_standard_isspace(map[i - 1][j] == 1))
        return (1);
    return (0);
}

void    ft_dfs(t_parse *parse, int **visited, int *i, int *j, int *flag)
{
    if (parse->map[*i][*j] == '1' && (ft_edges_checker(parse->map, *i, *j) == 1))
    {
        visited[*i][*j] = 1;
        if (parse->map[*i][*j + 1] == '1' && visited[*i][*j + 1] == 0)
        {
            *j = *j + 1;
            ft_dfs(parse, visited, i, j, flag);
        }
        if (parse->map[*i][*j - 1] == '1' && visited[*i][*j - 1] == 0)
        {
            *j = *j - 1;
            ft_dfs(parse, visited, i, j, flag);
        }
        if (parse->map[*i + 1][*j] == '1' && visited[*i + 1][*j] == 0)
        {
            *i = *i + 1;
            ft_dfs(parse, visited, i, j, flag);
        }
        if (parse->map[*i - 1][*j] == '1' && visited[*i - 1][*j] == 0)
        {
            *i = *i - 1;
            ft_dfs(parse, visited, i, j, flag);
        }
    }
    else if (parse->map[*i][*j] == '0' && (ft_edges_checker(parse->map, *i, *j) == 1))
        *flag = 1;
}