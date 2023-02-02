/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:14 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/02 12:32:56 by aoumad           ###   ########.fr       */
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