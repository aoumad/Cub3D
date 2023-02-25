/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:33:58 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 11:23:14 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{	
	char	*dst;

	if (x > 0 && x < g_util.win.win_w && y > 0 && y < g_util.win.win_h)
	{
		dst = g_util.img.addr + (y * g_util.img.line_length + x
				* (g_util.img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
