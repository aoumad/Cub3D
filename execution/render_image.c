/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:58:21 by aelabid           #+#    #+#             */
/*   Updated: 2023/03/05 19:33:57 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	render_image(t_parse data)
{
	if (g_util.mlx.img)
	{
		mlx_destroy_image(g_util.mlx.mlx_ptr, g_util.mlx.img);
		mlx_clear_window(g_util.mlx.mlx_ptr, g_util.mlx.win_ptr);
	}
	g_util.mlx.img = mlx_new_image(g_util.mlx.mlx_ptr, g_util.win.win_w,
			g_util.win.win_h);
	g_util.img.addr = mlx_get_data_addr(g_util.mlx.img,
			&g_util.img.bits_per_pixel,
			&g_util.img.line_length, &g_util.img.endian);
	color_background(data);
	render_player(data);
	mlx_put_image_to_window(g_util.mlx.mlx_ptr, g_util.mlx.win_ptr,
		g_util.mlx.img, 0, 0);
}
