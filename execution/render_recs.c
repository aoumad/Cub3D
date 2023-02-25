/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_recs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:25:22 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 11:24:47 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

int	render_wall(t_wall wall)
{
	double	i;
	int		x_textur;
	int		y_textur;
	float	h;

	i = wall.y;
	if (g_util.ray.is_horizontal)
		h = g_util.c_wall.x / REC_SIZE;
	else
		h = g_util.c_wall.y / REC_SIZE;
	x_textur = (h - (int)h) * g_util.right_text.width;
	while (i < wall.y + wall.height)
	{
		y_textur = (i - wall.y) * ((double)g_util.right_text.height
				/ wall.height);
		my_mlx_pixel_put(wall.x, i, g_util.right_text.addr
		[(g_util.right_text.width * y_textur) + x_textur]);
		++i;
	}
	return (0);
}
