/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:26:16 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/25 13:43:24 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_texture_path(t_parse *parse, char *map, int flag, int i)
{
	int	j;
	int	len;

	j = 0;
	if (map[i] == '.' && map[i + 1] == '/')
	{
		len = ft_strlen_mine(map, i);
		if (map[len - 1] == 'm' && map[len - 2] == 'p'
			&& map[len - 3] == 'x' && map[len - 4] == '.')
		{
			// ft_read_texture(map, i);
			ft_insert_texture_path(parse, map, flag, i, len);
			return ;
		}
	}
	ft_error("Error\nInvalid texture path\n");
}

void	ft_read_texture(char *map, int i)
{
	int		fd;
	char	*line;

	fd = open(&map[i], O_RDONLY);
	if (fd == -1)
		ft_error("Error\nInvalid texture path\n");
	line = get_next_line(fd);
	if (line == NULL)
		ft_error("Error\nInvalid texture path\n");
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

void	ft_check_color(t_index index, int row, char *map, int flag, t_parse *parse)
{
	int num;

	index.j = index.i;
	while (ft_isdigit(map[index.i]))
        index.i++;
	num = ft_atoi_color(map, index.j, index.i);
	if (num <= 0 || num > 255)
		ft_error("Error\nInvalid color\n");
	ft_insert_color(row, parse, flag, num);
	if (row != 2)
	{
		while (map[index.i] != ',')
			index.i++;
		if (map[index.i++] != ',')
			ft_error("Error\nno comma after color output\n");
	}
	index.i = ft_isspace_no_n(map, index.i);
	if (++row != 3)
	ft_check_color(index, row, map, flag, parse);
	else
	{
		if (map[index.i] == '\0')
			return ;
		else
			ft_error("Error\nInvalid map\n");
	}
}

void	ft_insert_texture_path(t_parse *parse, char *map, int flag, int i, int len)
{
	if (flag == NO)
		parse->no = ft_substr(map, i, len);
	else if (flag == SO)
		parse->so = ft_substr(map, i, len);
	else if (flag == WE)
		parse->we = ft_substr(map, i, len);
	else if (flag == EA)
		parse->ea = ft_substr(map, i, len);
	else
		ft_error("Error\nInvalid texture path\n");
}

int	ft_check_texture_inSim(char *map, int i)
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
