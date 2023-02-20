/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:14 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/20 22:15:44 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_helper()
{
    printf("Error\n");
    printf("Usage: ./cub3d map.cub....\n");
    exit(1);
}

void    ft_error(char *str)
{
    // rememeber i need to call free here and pass struct to free it
    printf("%s", str);
    // free all malloced data
    exit(1);
}

int     ft_isspace(char *map, int index)
{
    // printf("index before %d\n", index);
    int i = index;
    while (map[index] == ' ' || map[index] == '\t' || map[index] == '\n' ||
        map[index] == '\v' || map[index] == '\f' || map[index] == '\r')
        {
            index++;
            // printf("hahahaha\n");
        }
    if (i == index)
        return (0);
    // printf("returned index %d\n", i);
    return (index);
}

int     ft_isspace_no_n(char *map, int index)
{
    // printf("index before %d\n", index);
    int i = index;
    while (map[index] == ' ' || map[index] == '\t')
        {
            index++;
            // printf("hahahaha\n");
        }
    if (i == index)
        return (0);
    // printf("returned index %d\n", i);
    return (index);
}

int	ft_atoi_color(const char *str, int begin, int end)
{
	int number;

	number = 0;
	while(begin < end)
	{
		if (str[begin] >= '0' && str[begin] <= '9')
			number = number * 10 + (str[begin++] - 48);
		else
            ft_error("Error\nInvalid color\n");
	}
	return (number);
}

void    ft_half_done(int *tab, t_parse *parse)
{
    if (tab[(unsigned int)'N'] == 0 || tab[(unsigned int)'S'] == 0 || tab[(unsigned int)'W'] == 0 || 
        tab[(unsigned int)'E'] == 0 || tab[(unsigned int)'F'] == 0 || tab[(unsigned int)'C'] == 0)
        ft_error("Error\nMissing pattern\n");
    if (parse->no == NULL || parse->so == NULL || parse->we == NULL || parse->ea == NULL)
        ft_error("Error\nMissing texture\n");
}

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