/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:22 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/02 12:38:21 by aoumad           ###   ########.fr       */
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

// void    ft_check_file(char *file, t_parse *parse)
// {
//     int fd;
//     char *line;
//     int ret;
//     char *buf;
//     int i;

//     i = 0;
//     fd = open(file, O_RDONLY);
//     if (fd == -1)
//         ft_error("Error\nopen() failed\n");
//     // get_next_line only take fd as a parameter
//     line = get_next_line(fd);
//     while (line)
//     {
//         if (line[0] == '\n')
//         {
//             line[0] = ' ';
//             line[1] = '\n';
//             line[2] = '\0';
//         }
//         if (line[0] == 'R')
//             ft_check_res(line, parse);
//         else if (line[0] == 'N' && line[1] == 'O')
//             ft_check_path(line, parse, 'N');
//         else if (line[0] == 'S' && line[1] == 'O')
//             ft_check_path(line, parse, 'S');
//         else if (line[0] == 'W' && line[1] == 'E')
//             ft_check_path(line, parse, 'W');
//         else if (line[0] == 'E' && line[1] == 'A')
//             ft_check_path(line, parse, 'E');
//         else if (line[0] == 'F')
//             ft_check_color(line, parse, 'F');
//         else if (line[0] == 'C')
//             ft_check_color(line, parse, 'C');
//         else if (line[0] == '1' || line[0] == '0')
//             ft_check_map(line, parse);
//         else if (line[0] == '\0')
//             ft_error("Error\nEmpty line\n");
//         else
//             ft_error("Error\nInvalid line\n");
//         free(line);
//         line = get_next_line(fd);
//     }
//     close(fd);
// }


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
    
    if (tab[(unsigned int)map[0]] == 0)
        tab[(unsigned int)map[0]] = 1;
    else
        ft_error("Error\nDuplicate pattern\n");
    
    if (flag == PATH_FLAG)
    {
        i = ft_isspace(map, 2);
        if (i == 0)
            ft_error("Error\nInvalid pattern\n");
        ft_check_texture_path(map, ++i);
    }
    else if (flag == FC_FLAG)
    {
        i = ft_isspace(map, 1);
        if (i == 0)
            ft_error("Error\nInvalid pattern\n");
        ft_check_color(map, ++i);
    }
}
void    ft_check_map2(int *tab, char *map)
{
    int i;
    int tab[256] = {};
    
    i = 0;
    if (map[0] == 'N' && map[1] == 'O')
        ft_duplicate_pattern(&tab, map, PATH_FLAG);
    else if (map[0] == 'S' && map[1] == 'O')
        ft_duplicate_pattern(&tab, map, PATH_FLAG);
    else if (map[0] == 'W' && map[1] == 'E')
        ft_duplicate_pattern(&tab, map, PATH_FLAG);
    else if (map[0] == 'E' && map[1] == 'A')
        ft_duplicate_pattern(&tab, map, PATH_FLAG);
    else if (map[0] == 'F')
    {
        ft_duplicate_pattern(&tab, map, FC_FLAG);
        // check if map[1] has isspace 
        // need to call a function to see the range of rgb and also `,` if exists between them
    }
    else if (map[0] == 'C')
    {
        ft_duplicate_pattern(&tab, map, FC_FLAG);
        // same here
    }
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
        if (parse->map[i][0] == 'N' || parse->map[i][0] == 'S' || parse->map[i][0] == 'W' ||
            parse->map[i][0] == 'C' || parse->map[i][0] == 'E' || parse->map[i][0] == 'F')
            {
                ft_check_map2(&tab, parse->map[i]);
                i++;
            }
        if (parse->map[i][j] == '1' || parse->map[i][j] == '0' || parse->map[i][j] == ' ')
            j++;
        
    }
}