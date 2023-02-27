/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_additional_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:59:34 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/27 19:00:17 by aoumad           ###   ########.fr       */
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
	if (parse->sim[i][j] == '0' && (ft_edges_checker(parse, i, j) == 1))
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
	int	k;
	int	l;
	int	flag;

	k = 0;
	i = parse->s_cor->x;
	j = 0;
	flag = 0;
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
	i -= parse->s_cor->x;
	parse->sim = (char **)malloc(sizeof(char *) * i);
	while (k < i)
	{
		parse->sim[k] = (char *)malloc(sizeof(char) * j);
		k++;
	}
	k = 0;
	while (k < i)
	{
		l = 0;
		flag = 0;
		while (l < j)
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
	parse->sim_height = i;
	parse->sim_width = j;
}
