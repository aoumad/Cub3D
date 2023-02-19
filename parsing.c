/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:22 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/19 15:43:02 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void    ft_print_map(t_parse *parse);

t_parse ft_parse(char **arg, t_parse *parse)
{
    init_data(parse);
    ft_check_arg(arg);
    ft_read_file(arg[1], parse);
    // ft_print_map(parse);
    ft_check_map(parse);
    return (*parse);
}

void    ft_print_map(t_parse *parse)
{
    int i = 0;
    
    while (parse->map[i])
    {
        printf("%s\n", parse->map[i]);
        i++;
    }
    return ;
}

void    ft_read_file(char *file, t_parse *parse)
{
    int fd;
    char *line;
    char *buf;
    int i;

    i = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        ft_error("Error\nopen() failed\n");
    line = get_next_line(fd);
    buf = ft_strdup("");
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
    free(buf);
}

void    ft_duplicate_pattern(int *tab, char *map, int flag, t_parse *parse)
{
    t_index index;
    int i;
    
    index.i = 0;
    index.j = 0;
    i = 0;
    if (tab[(unsigned int)map[0]] == 0)
        tab[(unsigned int)map[0]] = 1;
    else
        ft_error("Error\nDuplicate pattern\n");
    
    if (flag == NO || flag == SO || flag == WE || flag == EA)
    {
        i = ft_isspace(map, 2);
        if (i == 0)
            ft_error("Error\nInvalid pattern\n");
        ft_check_texture_path(parse, map, flag, i);
        // ft_read_texture_path(parse, flag);
    }
    else if (flag == F_FLAG || flag == C_FLAG)
    {
        // i should put this incrmeneting structure in an indepent function
        i = ft_isspace_no_n(map, 0); // to increment the spaces before 'F' or 'C'
        if (map[i] == 'F' || map[i] == 'C')
            index.i = ft_isspace_no_n(map, ++i); // to increment the spaces after the 'F' or 'C'
        if (index.i == 0)
            ft_error("Error\nInvalid pattern\n");
        ft_check_color(index, 0, map, flag, parse);
    }
}

void    ft_check_map2(int *tab, char *map, t_parse *parse, int j)
{
    if (map[j] == 'N' && map[j + 1] == 'O')
        ft_duplicate_pattern(tab, map, NO, parse);
    else if (map[j] == 'S' && map[j + 1] == 'O')
        ft_duplicate_pattern(tab, map, SO, parse);
    else if (map[j] == 'W' && map[j + 1] == 'E')
        ft_duplicate_pattern(tab, map, WE, parse);
    else if (map[j] == 'E' && map[j + 1] == 'A')
        ft_duplicate_pattern(tab, map, EA, parse);
    else if (map[j] == 'F')
        ft_duplicate_pattern(tab, map, F_FLAG, parse);
    else if (map[j] == 'C')
        ft_duplicate_pattern(tab, map, C_FLAG, parse);
}

void    ft_check_map(t_parse *parse)
{
    int tab[256] = {};
    int i;
    int j;

    i = 0;
    j = 0;
    if (parse->map == NULL)
        ft_error("Error\nEmpty map\n");
    // ft_print_map(parse);
    while (parse->map[i])
    {
        printf("%s\n", parse->map[i]);
        parse->s_cor->x = i;
        parse->s_cor->y = j;
        ft_isspace_2D(parse->map, parse->s_cor);
        i = parse->s_cor->x;
        j = parse->s_cor->y;
        if (parse->map[i][j] == 'N' || parse->map[i][j] == 'S' || parse->map[i][j] == 'W' ||
            parse->map[i][j] == 'C' || parse->map[i][j] == 'E' || parse->map[i][j] == 'F')
                ft_check_map2(tab, parse->map[i], parse, j);
        if (tab[(unsigned int)'N'] == 1 && tab[(unsigned int)'S'] == 1 && tab[(unsigned int)'W'] == 1 && 
            tab[(unsigned int)'E'] == 1 && tab[(unsigned int)'F'] == 1 && tab[(unsigned int)'C'] == 1)
                break;
        i++;
    }
    ft_half_done(tab, parse);
    ft_second_half_checker(parse, tab, i, j);
}


void    ft_second_half_checker(t_parse *parse, int *tab, int i, int j)
{
    ft_check_map_closed(parse);
    parse->s_cor->x = i;
    parse->s_cor->y = j;
    ft_isspace_2D(parse->map, parse->s_cor);
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
    if (tab[(unsigned int)'n'] == 0 && tab[(unsigned int)'s'] == 0 && tab[(unsigned int)'w'] == 0 && tab[(unsigned int)'e'] == 0)
        ft_error("Error\nNo player position\n");
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
    parse->map_height = ++parse->s_cor->x; // pass the `C` line
    parse->map_width = parse->s_cor->y;
    while (parse->map[parse->map_height])
    {
        parse->s_cor->y = 0;
        while (parse->map[parse->map_height][parse->s_cor->y++])
        {
            if ((parse->map_width < parse->s_cor->y))
                parse->map_width = parse->s_cor->y;
        }
        parse->map_height++;
    }
    // printf("hnaaaaaaaa\n");
    // printf("map height: %d\n", parse->map_height);
    // printf("map weight: %d\n", parse->map_width);
    // printf("s_cor x: %d\n", parse->s_cor->x);
    visited = (int **)malloc(sizeof(int *) * (parse->map_height - parse->s_cor->x)); // deja mzyod 3ndi wa7d donc dik `+1` blach mnha
    while (i < (parse->map_height - parse->s_cor->x))
    {
        visited[i] = (int *)malloc(sizeof(int) * parse->map_width);
        i++;
    }
    i = 0;
    while (i < (parse->map_height - parse->s_cor->x))
    {
        j = 0;
        while (j < parse->map_width)
        {
            visited[i][j] = 0;
            j++;
        }
        i++;
    }
    i = parse->s_cor->x;
    // printf("index i: %d\n", i);
    // printf("map in that index:%s\n", parse->map[i]);
    while (i < (parse->map_height - parse->s_cor->x))
    {
        printf("map string:%s\n", parse->map[i]);
        j = 0;
        while (j < parse->map_width)
        {
            // if (i == 15 && j == 15)
            // {
            //     printf("daaaaaaaaayza j: %d\n", j);
            //     printf("character: %c\n", parse->map[i][j]);
            // }
            if (parse->map[i][j] == '1' && (ft_edges_checker(parse->map, i, j) == 1))
            {
                visited[i][j] = 1;
                k = i;
                l = j;
                ft_dfs(parse, visited, &k, &l, &flag);
            }
            else if (parse->map[i][j] == '0' && (ft_edges_checker(parse->map, i, j) == 1))
            {
                ft_error("Error\nMap is not closed\n");
                printf("found it\n");
            }
            
            if (parse->map[i][j] == '\n' || parse->map[i][j] == '\0')
                break;
            j++;
        }
        i++;
    }
    if (flag == 1)
        ft_error("Error\nMap is not closed\n");
}

int ft_edges_checker(char **map, int i, int j)
{
    // printf("map[i][j]: %c ---- i:%d ----j:%d\n", map[i][j], i, j);
    // printf("hahahahah\n");
    if ((ft_standard_isspace(map[i][j + 1]) == 1) || (ft_standard_isspace(map[i][j - 1]) == 1) ||
        (ft_standard_isspace(map[i + 1][j]) == 1) || (ft_standard_isspace(map[i - 1][j]) == 1))
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