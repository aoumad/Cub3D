/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:39:48 by aelabid           #+#    #+#             */
/*   Updated: 2023/01/14 07:57:33 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

void	dda(int x0, int y0, int x1, int col)
{
	int	x;
	int	temp;

	x = x0 - 1;
	if (x0 > x1)
	{
		temp = x0;
		x0 = x1;
		x1 = temp;
	}
	while (++x <= x1)
		my_mlx_pixel_put(x, y0, col);
}
