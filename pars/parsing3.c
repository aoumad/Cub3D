/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:40:01 by aoumad            #+#    #+#             */
/*   Updated: 2023/03/01 13:11:06 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_check_texture_in_sim(char *map, int i)
{
	int	cnt;
	int	cons;

	cnt = 0;
	cons = 0;
	while (map[i])
	{
		if (map[i] == '1' || map[i] == '0')
		{
			cnt++;
			if (map[i - 1] == '1' || map[i - 1] == '0')
				cons++;
			if (cons >= 4)
				return (1);
			else
				cons = 0;
		}
		i++;
	}
	if (cnt >= 1)
		return (1);
	return (0);
}

void	ft_generate_rgb(t_parse *parse, int flag)
{
	if (flag == F_FLAG)
		parse->f_rgb = ft_create_rgb(parse->f[0], parse->f[1], parse->f[2]);
	else if (flag == C_FLAG)
		parse->c_rgb = ft_create_rgb(parse->c[0], parse->c[1], parse->c[2]);
}

int	ft_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_check_map_additional(t_parse *parse, int *i, int *j)
{
	while (parse->map[*i])
	{
		*j = 0;
		*j = ft_isspace_no_n(parse->map[*i], *j);
		if (parse->map[*i][*j] == '\0')
		{
			(*i)++;
			continue ;
		}
		if (parse->map[*i][*j] == 'N' || parse->map[*i][*j] == 'S' ||
			parse->map[*i][*j] == 'W' || parse->map[*i][*j] == 'C' ||
			parse->map[*i][*j] == 'E' || parse->map[*i][*j] == 'F')
			ft_check_map2(parse->map[*i], parse, *j);
		else if (ft_rtn_tab(parse) == 1)
			break ;
		else if (ft_check_texture_in_sim(parse->map[*i], *j) == 1)
			ft_error("Error\ntexture inside the simulation\n");
		else
			ft_error("Error\nInvalid pattern\n");
		(*i)++;
	}
}

int	ft_rtn_tab(t_parse *parse)
{
	if (parse->tab[(unsigned int) 'N'] == 1
		&& parse->tab[(unsigned int) 'S'] == 1
		&& parse->tab[(unsigned int) 'W'] == 1
		&& parse->tab[(unsigned int) 'E'] == 1
		&& parse->tab[(unsigned int) 'F'] == 1
		&& parse->tab[(unsigned int) 'C'] == 1)
		return (1);
	return (0);
}
