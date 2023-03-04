/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:14:53 by aelabid           #+#    #+#             */
/*   Updated: 2023/03/04 11:19:37 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../pars/parsing.h"
# include"mlx.h"
# include<stdlib.h>
# include<math.h>
# include<stdio.h>
# include <unistd.h>
# include <math.h>
# define REC_SIZE 16
# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_mlx
{
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
}		t_mlx;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_img;

typedef struct s_texture {
	void	*img;
	int		height;
	int		width;
	char	*path;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_texture;

typedef struct s_rect
{
	int	x;
	int	y;
	int	rec_size;
	int	color;
}		t_rect;

typedef struct s_wall
{
	double	x;
	double	y;
	double	height;
	double	width;
}		t_wall;

typedef struct s_player
{
	double	x;
	double	y;
	double	rotate_angle;
	double	rotat_speed;
	int		size;
	int		turn_dir;
	int		walk_dir;
	int		move_speed;
}		t_player;

typedef struct s_winSizes
{
	int	nb_row;
	int	nb_col;
	int	win_h;
	int	win_w;
}		t_winSizes;

typedef struct s_point
{
	double	x;
	double	y;
}		t_point;

typedef struct s_info
{
	double	fov;
	double	ray_strip;
	int		num_ray;
}		t_info;

typedef struct s_ray
{
	double	ray_angle;
	int		is_up;
	int		is_right;
	double	distance;
	double	finale_distance;
	int		is_horizontal;
}		t_ray;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}		t_key;

typedef struct s_util
{
	t_point		first_intersection;
	t_point		step;
	t_point		wall_h;
	t_point		wall_v;
	t_point		c_wall;
	t_player	p;
	t_mlx		mlx;
	t_img		img;
	t_winSizes	win;
	char		**matrice;
	t_info		info;
	t_ray		ray;
	t_texture	texture[4];
	t_texture	right_text;
	t_key		key_press;
}		t_util;
t_util	g_util;
int		handle_keypress(t_parse *data);
void	my_mlx_pixel_put(int x, int y, int color);
void	init_player(t_parse *map);
void	open_window(void);
void	render_image(t_parse data);
void	render_player(t_parse data);
void	move_player(void);
void	move_sides(void);
int		is_wall(double x, double y);
void	init_info(void);
void	render_lines(t_parse data);
double	norm_angle(double ray_angle);
void	color_background(t_parse data);
void	get_images(t_parse data);
void	get_sizes(t_parse *map);
void	dda(int x0, int y0, int x1, int col);
int		render_wall(t_wall wall);
void	horiz_check(double ray_angle);
void	init_ray(double ray_angle);
void	vertical_check(double ray_angle);
double	get_distance(double x, double y);
void	get_wall_util(double distance_h, double distance_v);
void	init_data(t_parse *data);
void	image_check(t_parse *data);
#endif