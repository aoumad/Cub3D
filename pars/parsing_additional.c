/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_additional.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:56:46 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/27 19:00:02 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_check_map_closed(t_parse *parse)
{
	int	flag;

	flag = 0;
	ft_insert_simulation(parse);
	ft_malloc_visited(parse);
	ft_initialize_visited(parse);
	flag = ft_launch_dfs(parse, flag);
	ft_flag_rtn(parse, flag);
	ft_free_visited(parse);
}

void	ft_malloc_visited(t_parse *parse)
{
	int	i;

	i = 0;
	parse->visited = (int **)malloc(sizeof(int *) * (parse->sim_height));
	if (parse->visited == NULL)
		ft_error("Error\nMalloc failed\n");
	while (i < (parse->sim_height))
	{
		parse->visited[i] = (int *)malloc(sizeof(int) * parse->sim_width);
		if (parse->visited[i] == NULL)
			ft_error("Error\nMalloc failed\n");
		i++;
	}
}

void	ft_initialize_visited(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (i < parse->sim_height)
	{
		j = 0;
		while (j < parse->sim_width)
		{
			parse->visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	ft_launch_dfs(t_parse *parse, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < parse->sim_height)
	{
		j = 0;
		while (j < parse->sim_width)
		{
			if (parse->sim[i][j] == '1')
				ft_dfs(parse, i, j, &flag);
			if (parse->sim[i][j] == '\n' || parse->sim[i][j] == '\0')
				break ;
			if (parse->sim[i][j] == '0' && (ft_edges_checker(parse, i, j) == 1))
				ft_error("Error\nMap is not closed\n");
			j++;
		}
		i++;
	}
	return (flag);
}

void	ft_flag_rtn(t_parse *parse, int flag)
{
	int	i;
	int	j;

	i = 0;
	if (flag == 1)
		ft_error("Error\nMap is not closed\n");
	while (i < parse->sim_height)
	{
		j = 0;
		while (j < parse->sim_width)
		{
			if (parse->visited[i][j] == 0 && parse->sim[i][j] == '1')
				ft_error("Error\nMap is not closed\n");
			j++;
		}
		i++;
	}
}
