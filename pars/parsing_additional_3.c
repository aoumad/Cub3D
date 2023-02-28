/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_additional_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:20:45 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/28 09:12:32 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_fill_sim_array(t_parse *parse)
{
	int	k;
	int	l;
	int	flag;

	k = 0;
	while (k < parse->sim_height)
	{
		l = 0;
		flag = 0;
		while (l < parse->sim_width)
		{
			if (flag == 0)
				if (parse->map[parse->s_cor->x][l] == '\0')
					flag = 1;
			if (flag == 1)
				parse->sim[k][l] = ' ';
			else
				parse->sim[k][l] = parse->map[parse->s_cor->x][l];
			l++;
		}
		k++;
		parse->s_cor->x++;
	}
}

void	ft_malloc_sim(t_parse *parse)
{
	int	i;

	i = 0;
	parse->sim = (char **)malloc(sizeof(int *) * parse->sim_height);
	while (i < parse->sim_height)
	{
		parse->sim[i] = (char *)malloc(sizeof(int) * parse->sim_width);
		i++;
	}
}
