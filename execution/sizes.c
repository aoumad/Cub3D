/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:02:35 by aelabid           #+#    #+#             */
/*   Updated: 2023/03/05 19:47:45 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	get_sizes(t_parse *map)
{
	g_util.matrice = map->sim;
	g_util.win.nb_row = map->sim_height;
	g_util.win.nb_col = map->sim_width;
	g_util.win.win_h = 1024;
	g_util.win.win_w = 1024;
}
