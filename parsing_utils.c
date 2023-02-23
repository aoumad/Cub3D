/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:14 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/23 18:37:53 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_helper()
{
    printf("Error\n");
    printf("Usage: ./cub3d map.cub....\n");
    exit(1);
}

void    ft_error(t_parse *parse, char *str)
{
    int i;

    // rememeber i need to call free here and pass struct to free it
    printf("%s", str);
    // free map
    i = 0;
    while (i < parse->map_height)
        free(parse->map[i++]);
    free(parse->map);

    // free textures
    free(parse->no);
    free(parse->so);
    free(parse->we);
    free(parse->ea);
    free(parse->f);
    free(parse->c);
    free(parse->s_mlx);
    free(parse->s_fd);
    free(parse->s_cor);
    free(parse->s_index);
    free(parse);
    exit(1);
}

int     ft_isspace(char *map, int index)
{
    int i = index;
    while (map[index] == ' ' || map[index] == '\t' || map[index] == '\n' ||
        map[index] == '\v' || map[index] == '\f' || map[index] == '\r')
            index++;
    if (i == index)
        return (0);
    return (index);
}

int     ft_isspace_no_n(char *map, int index)
{
    while (map[index] == ' ' || map[index] == '\t')
        index++;
    return (index);
}

int	ft_atoi_color(t_parse *parse, const char *str, int begin, int end)
{
	int number;

	number = 0;
	while(begin < end)
	{
		if (str[begin] >= '0' && str[begin] <= '9')
			number = number * 10 + (str[begin++] - 48);
		else
            ft_error(parse, "Error\nInvalid color\n");
	}
	return (number);
}

void    ft_half_done(int *tab, t_parse *parse)
{
    if (tab[(unsigned int)'N'] == 0 || tab[(unsigned int)'S'] == 0 || tab[(unsigned int)'W'] == 0 || 
        tab[(unsigned int)'E'] == 0 || tab[(unsigned int)'F'] == 0 || tab[(unsigned int)'C'] == 0)
            ft_error(parse, "Error\nMissing pattern\n");
    // printf("--------------------___--------\n");
    // printf("parse->no = %s\n", parse->no);
    // printf("parse->so = %s\n", parse->so);
    // printf("parse->we = %s\n", parse->we);
    // printf("parse->ea = %s\n", parse->ea);
    // printf("--------------------___--------\n");
    if (parse->no == NULL || parse->so == NULL || parse->we == NULL || parse->ea == NULL)
        ft_error(parse, "Error\nMissing texture\n");
}

// void   ft_isspace_2D(char **map, t_cor *s_cor)
// {
//     while (map[s_cor->x][s_cor->y] == ' ' || map[s_cor->x][s_cor->y] == '\t' || map[s_cor->x][s_cor->y] == '\0' ||
//             map[s_cor->x] == '\0')
//     {
//         if (map[s_cor->x][s_cor->y] == '\0' || map[s_cor->x] == '\0')
//         {
//             printf("the string happened here, s_cor x:%d\n", s_cor->x);
//             s_cor->x++;
//             s_cor->y = 0;
//         }
//         else
//             s_cor->y++;
//     }
//     return ;
// }

// void    ft_isspace_2D(char **map, t_cor *s_cor)
// {
//     while (map[s_cor->y][s_cor->x] == ' ' || map[s_cor->y][s_cor->x] == '\t' || map[s_cor->y][s_cor->x] == '\n' ||
//         map[s_cor->y][s_cor->x] == '\v' || map[s_cor->y][s_cor->x] == '\f' || map[s_cor->y][s_cor->x] == '\r')
//     {
//         if (map[s_cor->y][s_cor->x] == '\n')
//         {
//             s_cor->y++;
//             s_cor->x = 0;
//         }
//         else
//             s_cor->x++;
//     }
//     return ;
// }

int     ft_standard_isspace(char c)
{
    // printf("character: %c\n", c);
    if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
        return (1);
    return (0);
}

size_t	ft_strlen_mine(const char *s, int j)
{
	size_t	i;

	i = (size_t)j;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
		i++;
	return (i);
}

void    ft_mark_texture_path(t_parse *parse, int *tab, char *map, int flag, int j)
{
    if (flag == WE || flag == SO || flag == EA || flag == NO)
    {
        if (j == 0)
        {
            if (tab[(unsigned int)map[j]] == 0)
                tab[(unsigned int)map[j]] = 1;
            else
                ft_error(parse, "Error\nDuplicate texture\n");
        }
        else if (j >= 2)
        {
            if (tab[(unsigned int)map[j - 2]] == 0) // index of j always holds the index after the "WE|SO...etc"
                tab[(unsigned int)map[j - 2]] = 1;
            else
                ft_error(parse, "Error\nDuplicate texture\n");
        }
    }
    if (flag == F_FLAG || flag == C_FLAG)
    {
        if (j == 0)
        {
            if (tab[(unsigned int)map[j]] == 0)
                tab[(unsigned int)map[j]] = 1;
            else
                ft_error(parse, "Error\nDuplicate texture\n");
        }
        else if (j >= 1)
        {
            if (tab[(unsigned int)map[j - 1]] == 0)
                tab[(unsigned int)map[j - 1]] = 1;
            else
                ft_error(parse, "Error\nDuplicate texture\n");
        }
    }
}