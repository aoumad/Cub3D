/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_additional_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:20:45 by aoumad            #+#    #+#             */
/*   Updated: 2023/03/06 09:13:23 by aoumad           ###   ########.fr       */
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

void	ft_elemenate_empty_lines(t_parse *parse, int *i)
{
	int	j;

	j = 0;
	j = ft_isspace_no_n(parse->map[*i - 1], j);
	if (parse->map[*i - 1][j] == '\0' && j != 0)
	{
		(*i)--;
		ft_elemenate_empty_lines(parse, i);
	}
}

void	ft_check_empty_line(t_parse *parse, int i)
{
	int	j;

	j = 0;
	while (parse->sim[i][j] == ' ' || parse->sim[i][j] == '\t')
			j++;
	if (j == parse->sim_width)
		ft_error("Error\nEmpty line\n", parse);
}
