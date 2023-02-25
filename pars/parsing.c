/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:22 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/25 21:44:11 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_parse ft_parse(char **arg, t_parse *parse)
{
    init_data(parse);
    ft_check_arg(arg);
    ft_read_file(arg[1], parse);
    ft_check_map(parse);
    printf("x cor:%d\n", parse->player_x);
    printf("y cor:%d\n", parse->player_y);
    printf("player dir:%c\n", parse->player_dir);
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
    if (line == NULL)
        ft_error("Error\nInvalid file\n");
    buf = ft_strdup("");
    while (line)
    {
        buf = ft_strjoin(buf, line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    parse->map = ft_split(buf, '\n');
    free(buf);
}

void    ft_duplicate_pattern(int *tab, char *map, int flag, t_parse *parse, int j)
{
    t_index index;
    int i;
    index.i = 0;
    index.j = 0;
    i = 0;
    ft_mark_texture_path(tab, map, flag, j);
    if (flag == NO || flag == SO || flag == WE || flag == EA)
    {
        i = ft_isspace(map, j);
        if (i == 0)
            ft_error("Error\nInvalid pattern\n");
        ft_check_texture_path(parse, map, flag, i);
    }
    else if (flag == F_FLAG || flag == C_FLAG)
    {
        index.i = ft_isspace_no_n(map, j); // to increment the spaces after 'F' or 'C'
        if (index.i == 0)
            ft_error("Error\nInvalid pattern\n");
        index.j = j;
        ft_check_color(index, 0, map, flag, parse);
        ft_generate_rgb(parse, flag);
        // printf("flor rgb color:%d\n", parse->f_rgb);
        // printf("ceil rgb color:%d\n", parse->c_rgb);
    }
}

void    ft_check_map2(int *tab, char *map, t_parse *parse, int j)
{
    if (map[j] == 'N' && map[j + 1] == 'O')
        ft_duplicate_pattern(tab, map, NO, parse, j + 2);
    else if (map[j] == 'S' && map[j + 1] == 'O')
        ft_duplicate_pattern(tab, map, SO, parse, j + 2);
    else if (map[j] == 'W' && map[j + 1] == 'E')
        ft_duplicate_pattern(tab, map, WE, parse, j + 2);
    else if (map[j] == 'E' && map[j + 1] == 'A')
        ft_duplicate_pattern(tab, map, EA, parse, j + 2);
    else if (map[j] == 'F')
        ft_duplicate_pattern(tab, map, F_FLAG, parse, j + 1);
    else if (map[j] == 'C')
        ft_duplicate_pattern(tab, map, C_FLAG, parse, j + 1);
    else
        ft_error("Error\nInvalid pattern\n");
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
    while (parse->map[i])
    {
        j = 0;
        j = ft_isspace_no_n(parse->map[i], j);
        if (parse->map[i][j] == '\0')
        {
            i++;
            continue;
        }
        if (parse->map[i][j] == 'N' || parse->map[i][j] == 'S' || parse->map[i][j] == 'W' ||
            parse->map[i][j] == 'C' || parse->map[i][j] == 'E' || parse->map[i][j] == 'F')
                ft_check_map2(tab, parse->map[i], parse, j);
        else if (tab[(unsigned int)'N'] == 1 && tab[(unsigned int)'S'] == 1 && tab[(unsigned int)'W'] == 1 && 
            tab[(unsigned int)'E'] == 1 && tab[(unsigned int)'F'] == 1 && tab[(unsigned int)'C'] == 1)
                break;
        else if (ft_check_texture_inSim(parse->map[i], j) == 1)
            ft_error("Error\ntexture inside the simulation\n");
        else
            ft_error("Error\nInvalid pattern\n");
        i++;
    }
    parse->s_cor->x = i;
    ft_half_done(tab, parse);
    ft_second_half_checker(parse, tab, ++i, j);
}

void    ft_second_half_checker(t_parse *parse, int *tab, int i, int j)
{
    parse->s_cor->x = i;
    parse->s_cor->y = j;
    ft_check_map_closed(parse);
    i = 0;
    while (i < parse->sim_height)
    {
        j = 0;
        while (j < parse->sim_width)
        {
            if (parse->sim[i][j] == '0' || parse->sim[i][j] == '1' || parse->sim[i][j] == ' ' || parse->sim[i][j] == '\t')
                j++;
            else if (parse->sim[i][j] == 'N' || parse->sim[i][j] == 'S' || parse->sim[i][j] == 'W' || parse->sim[i][j] == 'E')
            {
                if (tab[(unsigned int)'n'] == 1 || tab[(unsigned int)'s'] == 1 || tab[(unsigned int)'w'] == 1 ||
                    tab[(unsigned int)'e'] == 1)
                    ft_error("Error\nDuplicate player position\n");
                if (ft_edges_checker(parse, i, j) == 1 || i == 0 || i == parse->sim_height || j == 0 || j == parse->sim_width)
                {
                    ft_error("Error\nPlayer position on the edge\n");
                }
                else if (tab[(unsigned int)ft_tolower(parse->sim[i][j])] == 0)
                {
                    tab[(unsigned int)ft_tolower(parse->sim[i][j])] = 1;
                    parse->player_x = i;
                    parse->player_y = j;
                    parse->player_dir = parse->sim[i][j];
                    j++;
                }
            }
            else if (parse->sim[i][j] == '\0')
            {
                i++;
                j = 0;
            }
            else
                ft_error("Error\nInvalid map\n");
        }
        i++;
    }
    if (tab[(unsigned int)'n'] == 0 && tab[(unsigned int)'s'] == 0 && tab[(unsigned int)'w'] == 0 && tab[(unsigned int)'e'] == 0)
        ft_error("Error\nNo player position\n");
}

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
    ft_insert_simulation(parse);
    visited = (int **)malloc(sizeof(int *) * (parse->sim_height)); // deja mzyod 3ndi wa7d donc dik `+1` blach mnha
    if (visited == NULL)
        ft_error("Error\nMalloc failed\n");
    while (i < (parse->sim_height))
    {
        visited[i] = (int *)malloc(sizeof(int) * parse->sim_width);
        if (visited[i] == NULL)
            ft_error("Error\nMalloc failed\n");
        i++;
    }
    i = 0;
    while (i < parse->sim_height)
    {
        j = 0;
        while (j < parse->sim_width)
        {
            visited[i][j] = 0;
            j++;
        }
        i++;
    }
    i = 0;
    while (i < parse->sim_height)
    {
        j = 0;
        while (j < parse->sim_width)
        {
            if (parse->sim[i][j] == '1')
            {
                k = i;
                l = j;
                ft_dfs(parse, visited, k, l, &flag);
            }
            if (parse->sim[i][j] == '\n' || parse->sim[i][j] == '\0')
                break;
            if (parse->sim[i][j] == '0' && (ft_edges_checker(parse, i, j) == 1))
                ft_error("Error\nMap is not closed\n");
            j++;
        }
        i++;
    }
    if (flag == 1)
        ft_error("Error\nMap is not closed\n");
    i = 0;
    while (i < parse->sim_height)
    {
        j = 0;
        while (j < parse->sim_width)
        {
            if (visited[i][j] == 0 && parse->sim[i][j] == '1')
                ft_error("Error\nMap is not closed\n");
            j++;
        }
        i++;
    }
    i = 0;
    while (i < parse->sim_height)
    {
        free(visited[i]);
        i++;
    }
    free(visited);
}

int ft_edges_checker(t_parse *parse, int i, int j)
{
    if (i == 0 || i == parse->sim_height || j == 0 || j == parse->sim_width)
    {
        if (i > 0 && (ft_standard_isspace(parse->sim[i - 1][j]) == 1))
            return 1;
        if (j > 0 && (ft_standard_isspace(parse->sim[i][j - 1]) == 1))
            return 1;
        if (i < parse->sim_height && (ft_standard_isspace(parse->sim[i + 1][j]) == 1))
            return 1;
        if (j < parse->sim_width && (ft_standard_isspace(parse->sim[i][j + 1]) == 1))
            return 1;
        return 0;
    }
    else
    {
        if ((ft_standard_isspace(parse->sim[i - 1][j]) == 1) || (ft_standard_isspace(parse->sim[i][j - 1]) == 1) ||
            (ft_standard_isspace(parse->sim[i + 1][j]) == 1) || (ft_standard_isspace(parse->sim[i][j + 1]) == 1))
            return (1);
        return 0;
    }
}

void    ft_dfs(t_parse *parse, int **visited, int i, int j, int *flag)
{
    if (i < 0 || j < 0 || i >= parse->sim_height || j >= parse->sim_width)
        return ;
    if (visited[i][j] == 1)
        return ;
    if (parse->sim[i][j] == '0' && (ft_edges_checker(parse, i, j) == 1))
    {
        visited[i][j] = 1;
        *flag = 1;
        return ;
    }
    visited[i][j] = 1;
    ft_dfs(parse, visited, i + 1, j, flag);
    ft_dfs(parse, visited, i - 1, j, flag);
    ft_dfs(parse, visited, i, j + 1, flag);
    ft_dfs(parse, visited, i, j - 1, flag);
}

void    ft_insert_simulation(t_parse *parse)
{
    int i;
    int j;
    int k;
    int l;
    int flag = 0;

    k = 0;
    i = parse->s_cor->x;
    j = 0;
    while (parse->map[i])
    {
        parse->s_cor->y = 0;
        while (parse->map[i][parse->s_cor->y++])
        {
            if (j < parse->s_cor->y)
                j = parse->s_cor->y;
        }
        i++;
    }
    i -= parse->s_cor->x;
    parse->sim = (char **)malloc(sizeof(char *) * i);
    while (k < i)
    {
        parse->sim[k] = (char *)malloc(sizeof(char) * j);
        k++;
    }
    k = 0;
    while (k < i)
    {
        l = 0;
        flag = 0;
        while (l < j)
        {
            if (flag == 0)
                if (parse->map[parse->s_cor->x][l] == '\0')
                    flag = 1;
            if (flag == 1)
                parse->sim[k][l] = ' ';
            else
                parse->sim[k][l] = parse->map[parse->s_cor->x][l];
            l++;
        }
        k++;
        parse->s_cor->x++;
    }
    parse->sim_height = i;
    parse->sim_width = j;
}