/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:05 by aelabid           #+#    #+#             */
/*   Updated: 2023/02/25 21:21:38 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	check_more_key(void)
{
	if (g_util.key_press.right)
	{
		g_util.p.turn_dir = 1;
		g_util.p.rotate_angle += g_util.p.turn_dir * g_util.p.rotat_speed;
		g_util.p.rotate_angle = norm_angle(g_util.p.rotate_angle);
	}
	else if (g_util.key_press.left)
	{
		g_util.p.turn_dir = -1;
		g_util.p.rotate_angle += g_util.p.turn_dir * g_util.p.rotat_speed;
		g_util.p.rotate_angle = norm_angle(g_util.p.rotate_angle);
	}
}

void	check_key(void)
{
	if (g_util.key_press.w)
	{
		g_util.p.walk_dir = 1;
		move_player();
	}
	else if (g_util.key_press.s)
	{
		g_util.p.walk_dir = -1;
		move_player();
	}
	else if (g_util.key_press.d)
	{
		g_util.p.walk_dir = -1;
		move_sides();
	}
	else if (g_util.key_press.a)
	{
		g_util.p.walk_dir = 1;
		move_sides();
	}
}

int	handle_keypress(t_parse *data)
{
	check_key();
	check_more_key();
	render_image(*data);
	return (0);
}
