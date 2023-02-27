/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:22 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/27 18:26:45 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_parse	ft_parse(char **arg, t_parse *parse)
{
	init_data(parse);
	ft_check_arg(arg);
	ft_read_file(arg[1], parse);
	ft_check_map(parse);
	return (*parse);
}

void	ft_read_file(char *file, t_parse *parse)
{
	int		fd;
	char	*line;
	char	*buf;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nopen() failed\n");
	line = get_next_line(fd);
	if (line == NULL)
		ft_error("Error\nInvalid file\n");
	buf = ft_strdup("");
	while (line)
	{
		buf = ft_strjoin(buf, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	parse->map = ft_split(buf, '\n');
	free(buf);
}

void	ft_duplicate_pattern(char *map, int flag, t_parse *parse, int j)
{
	t_index	index;
	int		i;

	index.i = 0;
	index.j = 0;
	i = 0;
	ft_mark_texture_path(parse->tab, map, flag, j);
	if (flag == NO || flag == SO || flag == WE || flag == EA)
	{
		i = ft_isspace(map, j);
		if (i == 0)
			ft_error("Error\nInvalid pattern\n");
		ft_check_texture_path(parse, map, flag, i);
	}
	else if (flag == F_FLAG || flag == C_FLAG)
	{
		index.i = ft_isspace_no_n(map, j);
		if (index.i == 0)
			ft_error("Error\nInvalid pattern\n");
		index.j = j;
		ft_check_color(index, 0, map, flag, parse);
		ft_generate_rgb(parse, flag);
	}
}

void	ft_check_map2(char *map, t_parse *parse, int j)
{
	if (map[j] == 'N' && map[j + 1] == 'O')
		ft_duplicate_pattern(map, NO, parse, j + 2);
	else if (map[j] == 'S' && map[j + 1] == 'O')
		ft_duplicate_pattern(map, SO, parse, j + 2);
	else if (map[j] == 'W' && map[j + 1] == 'E')
		ft_duplicate_pattern(map, WE, parse, j + 2);
	else if (map[j] == 'E' && map[j + 1] == 'A')
		ft_duplicate_pattern(map, EA, parse, j + 2);
	else if (map[j] == 'F')
		ft_duplicate_pattern(map, F_FLAG, parse, j + 1);
	else if (map[j] == 'C')
		ft_duplicate_pattern(map, C_FLAG, parse, j + 1);
	else
		ft_error("Error\nInvalid pattern\n");
}

void	ft_check_map(t_parse *parse)
{
    int	i;
	int	j;

	i = 0;
	j = 0;
	if (parse->map == NULL)
		ft_error("Error\nEmpty map\n");
	// ------------
	while (parse->map[i])
	{
		j = 0;
		j = ft_isspace_no_n(parse->map[i], j);
		if (parse->map[i][j] == '\0')
		{
			i++;
			continue ;
		}
		if (parse->map[i][j] == 'N' || parse->map[i][j] == 'S' ||
			parse->map[i][j] == 'W' || parse->map[i][j] == 'C' ||
			parse->map[i][j] == 'E' || parse->map[i][j] == 'F')
			ft_check_map2(parse->map[i], parse, j);
		else if (parse->tab[(unsigned int) 'N'] == 1 && parse->tab[(unsigned int) 'S'] == 1
			&& parse->tab[(unsigned int) 'W'] == 1 && parse->tab[(unsigned int) 'E'] == 1
			&& parse->tab[(unsigned int) 'F'] == 1 && parse->tab[(unsigned int) 'C'] == 1)
			break ;
		else if (ft_check_texture_inSim(parse->map[i], j) == 1)
			ft_error("Error\ntexture inside the simulation\n");
		else
			ft_error("Error\nInvalid pattern\n");
		i++;
	}
	parse->s_cor->x = i;
	ft_half_done(parse);
	ft_second_half_checker(parse, i, j);
}

void	ft_second_half_checker(t_parse *parse, int i, int j)
{
	parse->s_cor->x = i;
	parse->s_cor->y = j;
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
			{
				if (parse->tab[(unsigned int) 'n'] == 1
					|| parse->tab[(unsigned int) 's'] == 1 
					|| parse->tab[(unsigned int ) 'w'] == 1
					|| parse->tab[(unsigned int ) 'e'] == 1)
						ft_error("Error\nDuplicate player position\n");
				if (ft_edges_checker(parse, i, j) == 1 || i == 0
					|| i == parse->sim_height || j == 0
					|| j == parse->sim_width)
					ft_error("Error\nPlayer position on the edge\n");
				else if (parse->tab[(unsigned int)ft_tolower(parse->sim[i][j])] == 0)
				{
					parse->tab[(unsigned int)ft_tolower(parse->sim[i][j])] = 1;
					parse->player_x = i;
					parse->player_y = j;
					j++;
				}
			}
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
	if (parse->tab[(unsigned int) 'n'] == 0
		&& parse->tab[(unsigned int) 's'] == 0
		&& parse->tab[(unsigned int) 'w'] == 0
		&& parse->tab[(unsigned int) 'e'] == 0)
		ft_error("Error\nNo player position\n");
}