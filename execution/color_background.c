/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:00:21 by aelabid           #+#    #+#             */
/*   Updated: 2023/02/25 20:52:43 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	color_background(t_parse data)
{
	int	i;

	i = 0;
	while (i < g_util.win.win_h / 2)
	{
		dda(0, i, g_util.win.win_w, data.c_rgb);
		i++;
	}
	while (i < g_util.win.win_h)
	{
		dda(0, i, g_util.win.win_w, data.f_rgb);
		i++;
	}
}
