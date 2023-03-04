/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:22 by aoumad            #+#    #+#             */
/*   Updated: 2023/03/04 17:46:46 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_parse	ft_parse(char **arg, t_parse *parse)
{
	init_data(parse);
	ft_check_arg(arg, parse);
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
		ft_error("Error\nopen() failed\n", parse);
	line = get_next_line(fd);
	if (line == NULL)
		ft_error("Error\nInvalid file\n", parse);
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
	int	i;

	i = 0;
	ft_mark_texture_path(parse, map, flag, j);
	if (flag == NO || flag == SO || flag == WE || flag == EA)
	{
		i = ft_isspace(map, j);
		if (i == 0)
			ft_error("Error\nInvalid pattern\n", parse);
		ft_check_texture_path(parse, map, flag, i);
	}
	else if (flag == F_FLAG || flag == C_FLAG)
	{
		parse->s_index->i = ft_isspace_no_n(map, j);
		if (parse->s_index->i == 0)
			ft_error("Error\nInvalid pattern\n", parse);
		parse->s_index->j = j;
		ft_check_color(0, map, flag, parse);
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
		ft_error("Error\nInvalid pattern\n", parse);
}

void	ft_check_map(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (parse->map == NULL)
		ft_error("Error\nEmpty map\n", parse);
	ft_check_map_additional(parse, &i, &j);
	parse->s_cor->x = i;
	ft_half_done(parse);
	parse->s_cor->x = i;
	parse->s_cor->y = j;
	ft_second_half_checker(parse, i, j);
}
