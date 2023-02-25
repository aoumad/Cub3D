/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:14:34 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 11:23:22 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	open_window(void)
{
	g_util.mlx.mlx_ptr = mlx_init();
	g_util.mlx.win_ptr = mlx_new_window(g_util.mlx.mlx_ptr, g_util.win.win_w,
			g_util.win.win_h, "CUB3D");
	g_util.mlx.img = NULL;
}
