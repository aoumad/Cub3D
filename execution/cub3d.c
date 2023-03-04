/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:20:05 by aelabid           #+#    #+#             */
/*   Updated: 2023/03/04 15:10:32 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

int	release_key(int key)
{
	if (key == 13)
		g_util.key_press.w = 0;
	else if (key == 0)
		g_util.key_press.a = 0;
	else if (key == 1)
		g_util.key_press.s = 0;
	else if (key == 2)
		g_util.key_press.d = 0;
	else if (key == 123)
		g_util.key_press.left = 0;
	else if (key == 124)
		g_util.key_press.right = 0;
	else if (key == 53)
		exit(0);
	return (0);
}

int	press_key(int key)
{
	if (key == 13)
		g_util.key_press.w = 1;
	if (key == 0)
		g_util.key_press.a = 1;
	if (key == 1)
		g_util.key_press.s = 1;
	if (key == 2)
		g_util.key_press.d = 1;
	if (key == 123)
		g_util.key_press.left = 1;
	if (key == 124)
		g_util.key_press.right = 1;
	return (1);
}

int	quit(void)
{
	exit(0);
	return(0);
}



int	main(int ac, char **av)
{
	if (ac == 2)
	{
	t_parse	data;
	// t_map	map;
	data = ft_parse(av, &data);

	// init_data(&data);
	// parsing(ac, av, &data, &data);
	get_sizes(&data);
	init_info();
	open_window();
	init_player(&data);
	mlx_hook(g_util.mlx.win_ptr, 2, 0, press_key, NULL);
	mlx_hook(g_util.mlx.win_ptr, 3, 0, release_key, NULL);
	mlx_hook(g_util.mlx.win_ptr, 17, 0, quit, NULL);
	mlx_hook(g_util.mlx.win_ptr, 6, 0, mouse, NULL);;
	mlx_loop_hook(g_util.mlx.mlx_ptr, handle_keypress, &data);
	mlx_loop(g_util.mlx.mlx_ptr);
	// free(g_util.mlx.mlx_ptr);
	ft_free_parsing(&data);
	}
	else
		ft_helper();
}
