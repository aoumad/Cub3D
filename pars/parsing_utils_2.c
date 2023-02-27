/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:05:00 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/27 18:10:05 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_half_done(t_parse *parse)
{
	if (parse->tab[(unsigned int) 'N'] == 0 || parse->tab[(unsigned int) 'S'] == 0
		|| parse->tab[(unsigned int) 'W'] == 0 || parse->tab[(unsigned int) 'E'] == 0
		|| parse->tab[(unsigned int) 'F'] == 0 || parse->tab[(unsigned int) 'C'] == 0)
		ft_error("Error\nMissing pattern\n");
	if (parse->no == NULL || parse->so == NULL
		|| parse->we == NULL || parse->ea == NULL)
		ft_error("Error\nMissing texture\n");
}

int ft_standard_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

size_t  ft_strlen_mine(const char *s, int j)
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

void    ft_mark_second_texture(int *tab, char *map, int j)
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

// void    ft_error(t_parse *parse, char *str)
// {
//     int i;

//     // rememeber i need to call free here and pass struct to free it
//     printf("%s", str);
//     // free map
//     i = 0;
//     while (i < parse->map_height)
//         free(parse->map[i++]);
//     free(parse->map);

//     // free textures
//     free(parse->no);
//     free(parse->so);
//     free(parse->we);
//     free(parse->ea);
//     free(parse->f);
//     free(parse->c);
//     free(parse->s_mlx);
//     free(parse->s_fd);
//     free(parse->s_cor);
//     free(parse->s_index);
//     free(parse);
//     exit(1);
// }