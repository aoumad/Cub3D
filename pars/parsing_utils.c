/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:14 by aoumad            #+#    #+#             */
/*   Updated: 2023/03/05 15:08:10 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_helper(void)
{
	printf("Error\n");
	printf("Usage: ./cub3d map.cub....\n");
	exit(1);
}

void	ft_error(char *str, t_parse *parse)
{
	ft_free_parsing(parse);
	printf("%s", str);
	exit(1);
}

int	ft_isspace(char *map, int index)
{
	int	i;

	i = index;
	while (map[index] == ' ' || map[index] == '\t'
		|| map[index] == '\n' || map[index] == '\v'
		|| map[index] == '\f' || map[index] == '\r')
			index++;
	if (i == index)
		return (0);
	return (index);
}

int	ft_isspace_no_n(char *map, int index)
{
	while (map[index] == ' ' || map[index] == '\t')
		index++;
	return (index);
}

int	ft_atoi_color(const char *str, int begin, int end, t_parse *parse)
{
	int	number;

	number = 0;
	if (begin == end)
		ft_error("Error\nInvalid color\n", parse);
	while (begin < end)
	{
		if (str[begin] >= '0' && str[begin] <= '9')
			number = number * 10 + (str[begin++] - 48);
		else
			ft_error("Error\nInvalid color\n", parse);
	}
	return (number);
}
