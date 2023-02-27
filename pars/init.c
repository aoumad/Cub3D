/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:30 by aoumad            #+#    #+#             */
/*   Updated: 2023/02/27 18:35:48 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_data(t_parse *parse)
{
	init_tab(parse);
	parse->no = NULL;
	parse->so = NULL;
	parse->we = NULL;
	parse->ea = NULL;
	parse->f[0] = -1;
	parse->f[1] = -1;
	parse->f[2] = -1;
	parse->c[0] = -1;
	parse->c[1] = -1;
	parse->c[2] = -1;
	parse->map = NULL;
	parse->player_x = -1;
	parse->player_y = -1;
	parse->player_dir = '\0';
	parse->s_cor = malloc(sizeof(t_cor));
	parse->s_cor->x = 0;
	parse->s_cor->y = 0;
	parse->s_index = malloc(sizeof(t_index));
	parse->s_index->i = 0;
	parse->s_index->j = 0;
	parse->f_rgb = 0;
	parse->c_rgb = 0;
}

void	init_tab(t_parse *parse)
{
	int	i;

	i = 0;
	while (i < 256)
		parse->tab[i++] = 0;
}

void	ft_check_arg(char **arg)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(arg[1]);
	if (len < 4)
		ft_error("Error\nInvalid file name\n");
	if (arg[1][len - 1] != 'b' || arg[1][len - 2] != 'u'
		|| arg[1][len - 3] != 'c' || arg[1][len - 4] != '.')
		ft_error("Error\nInvalid file name\n");
	if (arg[2])
		ft_error("Error\nToo many arguments\n");
}
