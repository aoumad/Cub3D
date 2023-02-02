/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:14 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/02 18:47:31 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int main(int argc, char **argv)
// {
//     t_parse  parse;
    
//     if (argc != 2)
//         ft_helper();
//     else
//     {
//         parse = ft_parse(argv[1]);
//         ft_check_parse(parse);
//         ft_init_mlx(&parse);
//         ft_init_player(&parse);
//         ft_init_textures(&parse);
//         ft_init_sprites(&parse);
//         ft_init_rays(&parse);
//         ft_init_minimap(&parse);
//         ft_init_img(&parse);
//         ft_init_window(&parse);
//         ft_init_hooks(&parse);
//         ft_init_game(&parse);
//     }
//     return (0);
// }

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
    return (i);
}

int	ft_atoi_color(const char *str, int begin, int end)
{
	int number;

	number = 0;
	while(begin <= end)
	{
		if (str[begin] >= '0' && str[begin] <= '9')
			number = number * 10 + (str[begin++] - 48);
		else
            ft_error("Error\nInvalid color\n");
	}
	return (number);
}

int    ft_half_done(int *tab)
{
    if (tab[(unsigned int)'N'] == 0 || tab[(unsigned int)'S'] == 0 || tab[(unsigned int)'W'] == 0 || 
        tab[(unsigned int)'E'] == 0 || tab[(unsigned int)'F'] == 0 || tab[(unsigned int)'C'] == 0)
        ft_error("Error\nMissing pattern\n");
}

void    ft_isspace_2D(char **map, t_cor *s_cor)
{
    int i = s_cor->x;
    int j = s_cor->y;
    while (map[s_cor->y][s_cor->x] == ' ' || map[s_cor->y][s_cor->x] == '\t' || map[s_cor->y][s_cor->x] == '\n' ||
        map[s_cor->y][s_cor->x] == '\v' || map[s_cor->y][s_cor->x] == '\f' || map[s_cor->y][s_cor->x] == '\r')
    {
        if (map[s_cor->y][s_cor->x] == '\n')
        {
            s_cor->y++;
            s_cor->x = 0;
        }
        else
            s_cor->x++;
    }
    return ;
}

int     ft_standard_isspace(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}