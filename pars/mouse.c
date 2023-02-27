/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:14:04 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/27 18:31:46 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse(int x, int y)
{
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (0);
	if (x > WIDTH / 2)
	{
		g_util.p.turn_dir = 1;
		g_util.p.rotate_angle += g_util.p.turn_dir * g_util.p.rotat_speed;
		g_util.p.rotate_angle = norm_angle(g_util.p.rotate_angle);
	}
	else if (x < WIDTH / 2)
	{
		g_util.p.turn_dir = -1;
		g_util.p.rotate_angle += g_util.p.turn_dir * g_util.p.rotat_speed;
		g_util.p.rotate_angle = norm_angle(g_util.p.rotate_angle);
	}
	return (0);
}
