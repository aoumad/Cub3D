/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_additional_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:59:34 by aoumad            #+#    #+#             */
/*   Updated: 2023/03/06 09:08:44 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_free_visited(t_parse *parse)
{
	int	i;

	i = 0;
	while (i < parse->sim_height)
	{
		free(parse->visited[i]);
		i++;
	}
	free(parse->visited);
}

int	ft_edges_checker(t_parse *parse, int i, int j)
{
	if (i == 0 || i == parse->sim_height || j == 0 || j == parse->sim_width)
	{
		if (i > 0 && (ft_standard_isspace(parse->sim[i - 1][j]) == 1))
			return (1);
		if (j > 0 && (ft_standard_isspace(parse->sim[i][j - 1]) == 1))
			return (1);
		if (i < parse->sim_height
			&& (ft_standard_isspace(parse->sim[i + 1][j]) == 1))
			return (1);
		if (j < parse->sim_width
			&& (ft_standard_isspace(parse->sim[i][j + 1]) == 1))
			return (1);
		return (0);
	}
	else
	{
		if ((ft_standard_isspace(parse->sim[i - 1][j]) == 1)
			|| (ft_standard_isspace(parse->sim[i][j - 1]) == 1)
			|| (ft_standard_isspace(parse->sim[i + 1][j]) == 1)
			|| (ft_standard_isspace(parse->sim[i][j + 1]) == 1))
			return (1);
		return (0);
	}
}

void	ft_dfs(t_parse *parse, int i, int j, int *flag)
{
	if (i < 0 || j < 0 || i >= parse->sim_height || j >= parse->sim_width)
		return ;
	if (parse->visited[i][j] == 1)
		return ;
	if (parse->sim[i][j] == '0' && (i == 0 || i == parse->sim_height - 1
		|| (ft_edges_checker(parse, i, j) == 1)))
	{
		parse->visited[i][j] = 1;
		*flag = 1;
		return ;
	}
	parse->visited[i][j] = 1;
	ft_dfs(parse, i + 1, j, flag);
	ft_dfs(parse, i - 1, j, flag);
	ft_dfs(parse, i, j + 1, flag);
	ft_dfs(parse, i, j - 1, flag);
}

void	ft_insert_simulation(t_parse *parse)
{
	int	i;
	int	j;

	i = parse->s_cor->x;
	j = 0;
	ft_find_max_width(parse, i, j);
	ft_fill_sim_array(parse);
}

void	ft_find_max_width(t_parse *parse, int i, int j)
{
	while (parse->map[i])
	{
		parse->s_cor->y = 0;
		while (parse->map[i][parse->s_cor->y++])
		{
			if (j < parse->s_cor->y)
				j = parse->s_cor->y;
		}
		i++;
	}
	ft_elemenate_empty_lines(parse, &i);
	i -= parse->s_cor->x;
	parse->sim_height = i;
	parse->sim_width = j;
	ft_malloc_sim(parse);
}
