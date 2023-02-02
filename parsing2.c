/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:26:16 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/02 13:33:01 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// F 220,100,0
// C 225,30,0
void    ft_check_color(char *map, int i)
{
    int j;
    int num;

    j = i;
    while (ft_isdigit(map[i]))
        i++;
    num = ft_atoi(map, j, i);
    if (num < 0 || num > 255)
        ft_error("Error\nInvalid color\n");
    if (map[i] == ',')
        i++;
    else
        ft_error("Error\nInvalid color\n");
}

