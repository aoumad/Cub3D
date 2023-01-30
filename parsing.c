/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:22 by aoumad            #+#    #+#             */
/*   Updated: 2023/01/30 19:16:49 by aoumad           ###   ########.fr       */
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

void    ft_check_map(t_parse *parse)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (parse->map[i][j])
    {
        if (parse->map == NULL)
            ft_error("Error\nEmpty map\n");
        if (parse->map[i][j] == '1' || parse->map[i][j] == '0' || parse->map[i][j] == ' ')
            j++;
    }
}

/*
function check duplicate
    
    int tab[256] = {};
        while (parse->map[i][j])
        {
            if (parse->map[i][0] == 'W' && parse->map[i][1] == 'E')
            {
                if (tab[(unsigned int)parse->map[i][0]] == 1)
                    ft_error("Error\nDuplicate path\n");
                tab[(unsigned int)parse->map[i][0]] = 1;
                j++;
            }
            else if (parse->map[i][0] == 'E' && parse->map[i][1] == 'A')
            {
                if (tab[(unsigned int)parse->map[i][0]] == 1)
                    ft_error("Error\nDuplicate path\n");
                tab[(unsigned int)parse->map[i][0]] = 1;
            }
            else if (parse->map[i][0] == 'N' && parse->map[i][1] == 'O')
            {
                if (tab[(unsigned int)parse->map[i][0]] == 1)
                    ft_error("Error\nDuplicate path\n");
                tab[(unsigned int)parse->map[i][0]] = 1;
            }
            else if (parse->map[i][0] == 'S' && parse->map[i][1] == 'O')
            {
                if (tab[(unsigned int)parse->map[i][0]] == 1)
                    ft_error("Error\nDuplicate path\n");
                tab[(unsigned int)parse->map[i][0]] = 1;
            }
            else if (parse->map[i][0] == 'R')
            {
                if (tab[(unsigned int)parse->map[i][0]] == 1)
                    ft_error("Error\nDuplicate resolution\n");
                tab[(unsigned int)parse->map[i][0]] = 1;
            }
            else if (parse->map[i][0] == 'F')
            {
                if (tab[(unsigned int)parse->map[i][0]] == 1)
                    ft_error("Error\nDuplicate floor color\n");
                tab[(unsigned int)parse->map[i][0]] = 1;
            }
            else if (parse->map[i][0] == 'C')
            {
                if (tab[(unsigned int)parse->map[i][0]] == 1)
                    ft_error("Error\nDuplicate ceiling color\n");
                tab[(unsigned int)parse->map[i][0]] = 1;
            }*/