/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:06:30 by aelabid           #+#    #+#             */
/*   Updated: 2023/02/25 21:28:25 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	get_first_intersection_v(double ray_angle)
{
	g_util.first_intersection.x = floor(g_util.p.x / REC_SIZE) * REC_SIZE;
	if (g_util.ray.is_right)
		g_util.first_intersection.x += REC_SIZE;
	g_util.first_intersection.y = g_util.p.y
		+ (g_util.first_intersection.x - g_util.p.x)
		* tan(ray_angle);
}

void	init_step_v(double ray_angle)
{
	g_util.step.x = REC_SIZE;
	if (!g_util.ray.is_right)
		g_util.step.x *= -1;
	g_util.step.y = REC_SIZE * tan(ray_angle);
	if (g_util.ray.is_up && g_util.step.y > 0)
		g_util.step.y *= -1;
	if (!g_util.ray.is_up && g_util.step.y < 0)
		g_util.step.y *= -1;
}

void	vertical_check(double ray_angle)
{
	get_first_intersection_v(ray_angle);
	init_step_v(ray_angle);
	g_util.wall_v.x = g_util.first_intersection.x;
	g_util.wall_v.y = g_util.first_intersection.y;
	if (!g_util.ray.is_right)
		g_util.wall_v.x--;
	while (g_util.wall_v.x <= g_util.win.win_w && g_util.wall_v.x >= 0
		&& g_util.wall_v.y <= g_util.win.win_h && g_util.wall_v.y >= 0)
	{
		if (is_wall(g_util.wall_v.x, g_util.wall_v.y))
			break ;
		else
		{
			g_util.wall_v.x += g_util.step.x;
			g_util.wall_v.y += g_util.step.y;
		}
	}
}

double	get_distance(double x, double y)
{
	double	dis;
	double	x0;
	double	y0;

	x0 = g_util.p.x;
	y0 = g_util.p.y;
	dis = sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
	return (dis);
}

void	get_wall_util(double distance_h, double distance_v)
{
	if (distance_h < distance_v)
	{
		g_util.c_wall.x = g_util.wall_h.x;
		g_util.c_wall.y = g_util.wall_h.y;
		g_util.ray.is_horizontal = 1;
	}
	else
	{
		g_util.c_wall.x = g_util.wall_v.x;
		g_util.c_wall.y = g_util.wall_v.y;
		g_util.ray.is_horizontal = 0;
	}
}
