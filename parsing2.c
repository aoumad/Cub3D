/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:26:16 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/20 16:15:40 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

    // ./../texture/NO.xpm (generate parsing that handles that)
void    ft_check_texture_path(t_parse *parse, char *map, int flag, int i)
{
    int j;
    int len;

    j = 0;
    if (map[i] == '.' && map[i + 1] == '/')
    {
        len = ft_strlen_mine(map, i);
        if (map[len - 1] == 'm' && map[len - 2] == 'p' &&
            map[len - 3] == 'x' && map[len - 4] == '.')
            {
                ft_insert_texture_path(parse, map, flag, i, len);
                return ;
            }
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
void    ft_check_color(t_index index, int row, char *map, int flag, t_parse *parse)
{
    int num;
    
    index.j = index.i;
    while (ft_isdigit(map[index.i]))
        index.i++;
    num = ft_atoi_color(map, index.j, index.i);
    if (num < 0 || num > 255)
        ft_error("Error\nInvalid color\n");
    ft_insert_color(row, parse, flag, num);
    if (row != 2)
    {
        while (map[index.i] != ',')
            index.i++;
        if (map[index.i++] != ',')
            ft_error("Error\nno comma after color output\n");
    }
    index.i = ft_isspace_no_n(map, index.i);
    if (++row != 3)
        ft_check_color(index, row, map, flag, parse);
    else
    {
        if (map[index.i] == '\0')
            return ;
        else
            ft_error("Error\nInvalid map\n");
    }
}

void    ft_insert_texture_path(t_parse *parse, char *map, int flag, int i, int len)
{
    if (flag == NO)
        parse->no = ft_substr(map, i, len);
    else if (flag == SO)
        parse->so = ft_substr(map, i, len);
    else if (flag == WE)
        parse->we = ft_substr(map, i, len);
    else if (flag == EA)
        parse->ea = ft_substr(map, i, len);
    else
        ft_error("Error\nInvalid texture path\n");
}