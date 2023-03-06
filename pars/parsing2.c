/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:26:16 by aoumad            #+#    #+#             */
/*   Updated: 2023/03/06 18:26:02 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_check_texture_path(t_parse *parse, char *map, int flag, int i)
{
	t_index	index;
	char	*tmp;
	int		j;

	j = 0;
	tmp = ft_strtrim(map, " ");
	map = ft_strtrim(tmp, "\t");
	free(tmp);
	if (map[i] == '.' && map[i + 1] == '/')
	{
		index.j = ft_strlen_mine(map, i);
		if (map[index.j - 1] == 'm' && map[index.j - 2] == 'p'
			&& map[index.j - 3] == 'x' && map[index.j - 4] == '.')
		{
			ft_read_texture(map, i, parse);
			index.i = i;
			ft_insert_texture_path(parse, map, flag, index);
			free(map);
			return ;
		}
	}
	free(map);
	ft_error("Error\nInvalid texture path\n", parse);
}

void	ft_read_texture(char *map, int i, t_parse *parse)
{
	int		fd;

	fd = open(&map[i], O_RDONLY);
	if (fd == -1)
	{
		free(map);
		ft_error("Error\nInvalid texture path\n", parse);
	}
	return ;
}

void	ft_insert_color(int row, t_parse *parse, int flag, int num)
{
	if (flag == F_FLAG)
	{
		if (row == 0)
			parse->f[0] = num;
		else if (row == 1)
			parse->f[1] = num;
		else if (row == 2)
			parse->f[2] = num;
	}
	else if (flag == C_FLAG)
	{
		if (row == 0)
			parse->c[0] = num;
		else if (row == 1)
			parse->c[1] = num;
		else if (row == 2)
			parse->c[2] = num;
	}
}

void	ft_check_color(int row, char *map, int flag, t_parse *parse)
{
	int	num;

	parse->s_index->j = parse->s_index->i;
	while (ft_isdigit(map[parse->s_index->i]))
		parse->s_index->i++;
	num = ft_atoi_color(map, parse->s_index->j, parse->s_index->i, parse);
	if (num < 0 || num > 255)
		ft_error("Error\nInvalid color\n", parse);
	ft_insert_color(row, parse, flag, num);
	ft_comma_checker(row, map, parse);
	if (++row != 3)
		ft_check_color(row, map, flag, parse);
	else
	{
		if (map[parse->s_index->i] == '\0')
			return ;
		else
			ft_error("Error\nInvalid map\n", parse);
	}
}

void	ft_insert_texture_path(t_parse *parse, char *map,
		int flag, t_index index)
{
	if (flag == NO)
		parse->no = ft_substr(map, index.i, index.j);
	else if (flag == SO)
		parse->so = ft_substr(map, index.i, index.j);
	else if (flag == WE)
		parse->we = ft_substr(map, index.i, index.j);
	else if (flag == EA)
		parse->ea = ft_substr(map, index.i, index.j);
	else
	{
		free(map);
		ft_error("Error\nInvalid texture path\n", parse);
	}
}
