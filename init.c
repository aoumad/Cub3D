/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:30 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/20 16:09:19 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_data(t_parse *parse)
{
    parse->res_x = -1;
    parse->res_y = -1;
    parse->no = NULL;
    parse->so = NULL;
    parse->we = NULL;
    parse->ea = NULL;
    // parse->s = NULL;
    parse->f[0] = -1;
    parse->f[1] = -1;
    parse->f[2] = -1;
    parse->c[0] = -1;
    parse->c[1] = -1;
    parse->c[2] = -1;
    parse->map = NULL;
    parse->map_width = 1000;
    parse->map_height = 1000;
    parse->player_x = -1;
    parse->player_y = -1;
    parse->player_dir = '\0';
    parse->s_mlx = malloc(sizeof(t_mlx));
    parse->s_mlx->mlx = NULL;
    parse->s_mlx->win = NULL;
    parse->s_mlx->img = NULL;
    parse->s_mlx->addr = NULL;
    parse->s_mlx->bits_per_pixel = 0;
    parse->s_mlx->line_length = 0;
    parse->s_mlx->endian = 0;
    parse->s_fd = malloc(sizeof(t_fd));
    parse->s_fd->fd = 0;
    parse->s_fd->line = NULL;
    parse->s_cor = malloc(sizeof(t_cor));
    parse->s_cor->x = 0;
    parse->s_cor->y = 0;
}

/*
    parse->s_mlx->mlx = mlx_init();
    if (!parse->s_mlx->mlx)
        ft_error("Error\nmlx_init() failed\n");
    init_mlx(parse);
*/

void    ft_check_arg(char **arg)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(arg[1]);
    if (len < 4)
        ft_error("Error\nInvalid file name\n");
    if (arg[1][len - 1] != 'b' || arg[1][len - 2] != 'u' || arg[1][len - 3] != 'c' || arg[1][len - 4] != '.')
        ft_error("Error\nInvalid file name\n");
    if (arg[2])
        ft_error("Error\nToo many arguments\n");
}