/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:10:47 by aelabid           #+#    #+#             */
/*   Updated: 2023/02/25 21:33:55 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	get_closest_wall(double ray_angle)
{
	double	distance_h;
	double	distance_v;

	vertical_check(ray_angle);
	horiz_check(ray_angle);
	distance_h = get_distance(g_util.wall_h.x, g_util.wall_h.y);
	distance_v = get_distance(g_util.wall_v.x, g_util.wall_v.y);
	get_wall_util(distance_h, distance_v);
	if ((int) g_util.wall_v.y == (int) g_util.wall_h.y)
	{
		g_util.c_wall.x = g_util.wall_h.x;
		g_util.c_wall.y = g_util.wall_h.y;
		g_util.ray.is_horizontal = 1;
	}
	else if ((int) g_util.wall_v.x == (int) g_util.wall_h.x)
	{
		g_util.ray.is_horizontal = 0;
		g_util.c_wall.x = g_util.wall_v.x;
		g_util.c_wall.y = g_util.wall_v.y;
	}
	g_util.ray.distance = get_distance(g_util.c_wall.x, g_util.c_wall.y);
}

void	projected(int i)
{
	double	distance_to_window;
	double	wall_projected_height;

	distance_to_window = (g_util.win.win_w / 2) / tan(g_util.info.fov / 2);
	wall_projected_height = REC_SIZE / g_util.ray.finale_distance
		* distance_to_window;
	render_wall((t_wall){i, (g_util.win.win_h / 2)
		- ((int)wall_projected_height / 2),
		wall_projected_height, g_util.info.ray_strip});
}

t_texture	get_right_wall(double ray_angle)
{
	if (g_util.ray.is_horizontal)
	{
		if ((ray_angle <= (2 * M_PI) && ray_angle >= M_PI))
			return (g_util.texture[1]);
		else
			return (g_util.texture[0]);
	}
	else
	{
		if ((ray_angle <= 3 * M_PI / 2 && ray_angle >= M_PI / 2))
			return (g_util.texture[2]);
		else
			return (g_util.texture[3]);
	}
}

void	render_lines(t_parse data)
{
	double	ray_angle;
	int		i;

	i = 1;
	ray_angle = (g_util.p.rotate_angle - (g_util.info.fov / 2));
	get_images(data);
	while (i < g_util.info.num_ray)
	{
		ray_angle = norm_angle(ray_angle);
		init_ray(ray_angle);
		get_closest_wall(ray_angle);
		g_util.ray.finale_distance = g_util.ray.distance
			* cos(ray_angle - g_util.p.rotate_angle);
		g_util.right_text = get_right_wall(ray_angle);
		projected(i);
		i++;
		ray_angle += (g_util.info.fov / g_util.info.num_ray);
	}
}
