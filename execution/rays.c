/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:33:24 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 11:28:08 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	init_ray(double ray_angle)
{
	if ((ray_angle < 2 * M_PI) && (ray_angle > M_PI))
		g_util.ray.is_up = 1;
	else
		g_util.ray.is_up = 0;
	if ((ray_angle < M_PI / 2) || (ray_angle > 3 * (M_PI / 2)))
		g_util.ray.is_right = 1;
	else
		g_util.ray.is_right = 0;
}

double	norm_angle(double angle)
{
	if (angle >= 0)
		angle = fmod(angle, (2 * M_PI));
	else
		angle += (2 * M_PI);
	return (angle);
}

void	get_first_intersection_h(double ray_angle)
{
	g_util.first_intersection.y = floor(g_util.p.y / REC_SIZE) * REC_SIZE;
	if (!g_util.ray.is_up)
		g_util.first_intersection.y += REC_SIZE;
	g_util.first_intersection.x = g_util.p.x
		+ (g_util.first_intersection.y - g_util.p.y) / tan(ray_angle);
}

void	init_step_h(double ray_angle)
{
	g_util.step.y = REC_SIZE;
	if (g_util.ray.is_up)
		g_util.step.y *= -1;
	g_util.step.x = REC_SIZE / tan(ray_angle);
	if (!g_util.ray.is_right && g_util.step.x > 0)
		g_util.step.x *= -1;
	if (g_util.ray.is_right && g_util.step.x < 0)
		g_util.step.x *= -1;
}

void	horiz_check(double ray_angle)
{
	get_first_intersection_h(ray_angle);
	init_step_h(ray_angle);
	g_util.wall_h.x = g_util.first_intersection.x;
	g_util.wall_h.y = g_util.first_intersection.y;
	if (g_util.ray.is_up)
		g_util.wall_h.y--;
	while (g_util.wall_h.x <= g_util.win.win_w && g_util.wall_h.x >= 0
		&& g_util.wall_h.y <= g_util.win.win_h && g_util.wall_h.y >= 0)
	{
		if (is_wall(g_util.wall_h.x, g_util.wall_h.y))
			break ;
		else
		{
			g_util.wall_h.x += g_util.step.x;
			g_util.wall_h.y += g_util.step.y;
		}
	}
}
