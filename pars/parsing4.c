/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:15:50 by aoumad            #+#    #+#             */
/*   Updated: 2023/03/01 11:22:56 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_second_half_checker(t_parse *parse, int i, int j)
{
	ft_check_map_closed(parse);
	i = 0;
	while (i < parse->sim_height)
	{
		j = 0;
		while (j < parse->sim_width)
		{
			if (parse->sim[i][j] == '0' || parse->sim[i][j] == '1'
				|| parse->sim[i][j] == ' ' || parse->sim[i][j] == '\t')
				j++;
			else if (parse->sim[i][j] == 'N' || parse->sim[i][j] == 'S'
				|| parse->sim[i][j] == 'W' || parse->sim[i][j] == 'E')
				ft_player_checker(parse, &i, &j);
			else if (parse->sim[i][j] == '\0')
			{
				i++;
				j = 0;
			}
			else
				ft_error("Error\nInvalid map\n");
		}
		i++;
	}
	ft_no_player_pos(parse);
}

void	ft_no_player_pos(t_parse *parse)
{
	if (parse->tab[(unsigned int) 'n'] == 0
		&& parse->tab[(unsigned int) 's'] == 0
		&& parse->tab[(unsigned int) 'w'] == 0
		&& parse->tab[(unsigned int) 'e'] == 0)
		ft_error("Error\nNo player position\n");
}

void	ft_player_checker(t_parse *parse, int *i, int *j)
{
	if (parse->tab[(unsigned int) 'n'] == 1
		|| parse->tab[(unsigned int) 's'] == 1
		|| parse->tab[(unsigned int ) 'w'] == 1
		|| parse->tab[(unsigned int ) 'e'] == 1)
		ft_error("Error\nDuplicate player position\n");
	if (ft_edges_checker(parse, *i, *j) == 1 || i == 0
		|| *i == parse->sim_height || j == 0
		|| *j == parse->sim_width)
		ft_error("Error\nPlayer position on the edge\n");
	else if (parse->tab[(unsigned int)ft_tolower(parse->sim[*i][*j])] == 0)
	{
		parse->tab[(unsigned int)ft_tolower(parse->sim[*i][*j])] = 1;
		parse->player_x = *i;
		parse->player_y = *j;
		(*j)++;
	}
}

void	ft_mark_second_texture(int *tab, char *map, int j)
{
	if (j == 0)
	{
		if (tab[(unsigned int)map[j]] == 0)
			tab[(unsigned int)map[j]] = 1;
		else
			ft_error("Error\nDuplicate texture\n");
	}
	else if (j >= 1)
	{
		if (tab[(unsigned int)map[j - 1]] == 0)
			tab[(unsigned int)map[j - 1]] = 1;
		else
			ft_error("Error\nDuplicate texture\n");
	}
}

void	ft_mark_texture_path(int *tab, char *map, int flag, int j)
{
	if (flag == WE || flag == SO || flag == EA || flag == NO)
		ft_mark_first_texture(tab, map, j);
	if (flag == F_FLAG || flag == C_FLAG)
		ft_mark_second_texture(tab, map, j);
}
