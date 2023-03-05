/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:11:14 by aelabid           #+#    #+#             */
/*   Updated: 2023/03/05 20:20:26 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

int	is_wall(double x, double y)
{
	int	nx;
	int	ny;

	nx = floor(x / REC_SIZE);
	ny = floor(y / REC_SIZE);

	if (nx >= g_util.win.nb_col)
		nx = g_util.win.nb_col - 1;
	if (ny >= g_util.win.nb_row)
		ny = g_util.win.nb_row - 1;
	return (g_util.matrice[ny][nx] != '0');
}
