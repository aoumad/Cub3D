/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:05:00 by aoumad            #+#    #+#             */
/*   Updated: 2023/03/01 11:28:11 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_half_done(t_parse *parse)
{
	if (parse->tab[(unsigned int) 'N'] == 0
		|| parse->tab[(unsigned int) 'S'] == 0
		|| parse->tab[(unsigned int) 'W'] == 0
		|| parse->tab[(unsigned int) 'E'] == 0
		|| parse->tab[(unsigned int) 'F'] == 0
		|| parse->tab[(unsigned int) 'C'] == 0)
		ft_error("Error\nMissing pattern\n");
	if (parse->no == NULL || parse->so == NULL
		|| parse->we == NULL || parse->ea == NULL)
		ft_error("Error\nMissing texture\n");
}

int	ft_standard_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

size_t	ft_strlen_mine(const char *s, int j)
{
	size_t	i;

	i = (size_t)j;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
		i++;
	return (i);
}

void	ft_mark_first_texture(int *tab, char *map, int j)
{
	if (j == 0)
	{
		if (tab[(unsigned int)map[j]] == 0)
			tab[(unsigned int)map[j]] = 1;
		else
			ft_error("Error\nDuplicate texture\n");
	}
	else if (j >= 2)
	{
		if (tab[(unsigned int)map[j - 2]] == 0)
			tab[(unsigned int)map[j - 2]] = 1;
		else
			ft_error("Error\nDuplicate texture\n");
	}
}
