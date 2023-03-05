/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_additional_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:20:45 by aoumad            #+#    #+#             */
/*   Updated: 2023/03/05 20:59:00 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_fill_sim_array(t_parse *parse)
{
	int	k;
	int	l;
	k = 0;
	while (k < parse->sim_height)
	{
		l = 0;
        while (l < parse->sim_width && parse->map[parse->s_cor->x][l])
        {
            parse->sim[k][l] = parse->map[parse->s_cor->x][l];
            l++;
        }
        while (l < parse->sim_width)
        {
            parse->sim[k][l] = ' ';
            l++;
        }
		parse->sim[k][l] = '\0';
		k++;
		parse->s_cor->x++;
	}
}

void	ft_malloc_sim(t_parse *parse)
{
	int	i;

	i = 0;
	parse->sim = (char **)malloc(sizeof(int *) * parse->sim_height + 1);
	if (parse->sim == NULL)
		ft_error("Error\nMalloc failed\n", parse);
	while (i < parse->sim_height)
	{
		parse->sim[i] = (char *)malloc(sizeof(int) * parse->sim_width);
		if (parse->sim[i] == NULL)
			ft_error("Error\nMalloc failed\n", parse);
		i++;
	}
}

void	ft_comma_checker(int row, char *map, t_parse *parse)
{
	if (row != 2)
	{
		while (map[parse->s_index->i] != ',')
			parse->s_index->i++;
		if (map[parse->s_index->i++] != ',')
			ft_error("Error\nno comma after color output\n", parse);
	}
	parse->s_index->i = ft_isspace_no_n(map, parse->s_index->i);
}
