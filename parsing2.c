/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:26:16 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/17 09:40:40 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

    // ./../texture/NO.xpm (generate parsing that handles that)
void    ft_check_texture_path(char *map, int i)
{
    int j;
    int len;

    j = 0;
    if (map[i] == '.' && map[i + 1] == '/')
    {
        len = ft_strlen(map);
        if (map[len - 1] == 'm' && map[len - 2] == 'p' &&
            map[len - 3] == 'x' && map[len - 4] == '.')
            return ;
    }
    ft_error("Error\nInvalid texture path\n");
}

void    ft_insert_color(int row, t_parse *parse, int flag, int num)
{
    if (flag == 0)
    {
        if (row == 0)
            parse->f[0] = num;
        else if (row == 1)
            parse->f[1] = num;
        else if (row == 2)
            parse->f[2] = num;
    }
    else if (flag == 1)
    {
        if (row == 0)
            parse->c[0] = num;
        else if (row == 1)
            parse->c[1] = num;
        else if (row == 2)
            parse->c[2] = num;
    }
}

// F 220,100,0
// C 225,30,0
void    ft_check_color(int i, int row, t_parse *parse, int j, int flag)
{
    int j;
    int num;

    j = i;
    while (ft_isdigit(parse->map[i]))
        i++;
    num = ft_atoi_color(parse->map, j, i);
    if (num < 0 || num > 255)
        ft_error("Error\nInvalid color\n");
    ft_insert_color(row, parse, flag, num);
    while (parse->map[i] != ',')
        i++;
    if (parse->map[i] != ',')
        ft_error("Error\nno comma after color output\n");
    i++;
    if (++row != 3)
        ft_check_color(i, row, &parse, j, flag);
    if (row == 3)
    {
        while (parse->map[i] == ' ' || parse->map[i] == '\t')
            i++;
        if (parse->map[i] == '\n')
            return ;
        else
            ft_error("Error\nInvalid map\n");
    }
}

void    ft_insert_texture_path(t_parse *parse, char *map, int flag)
{
    if (flag == NO)
        parse->no = map;
    else if (flag == SO)
        parse->so = map;
    else if (flag == WE)
        parse->we = map;
    else if (flag == EA)
        parse->ea = map;
    else
        ft_error("Error\nInvalid texture path\n");
}