/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:26 by aoumad            #+#    #+#             */
/*   Updated: 2023/03/06 12:35:27 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <limits.h>
# include "GNL_utils/get_next_line.h"

typedef enum e_flag
{
	NONE,
	PATH_FLAG,
	F_FLAG,
	C_FLAG,
	NO,
	SO,
	WE,
	EA
}	t_flag;

typedef struct s_cor
{
	int	x;
	int	y;
}	t_cor;

typedef struct s_index
{
	int	i;
	int	j;
}	t_index;

typedef struct s_parse
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	int		tab[256];
	int		f_rgb;
	int		c_rgb;
	char	**map;
	char	**sim;
	int		sim_height;
	int		sim_width;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	char	player_dir;
	int		**visited;
	t_cor	*s_cor;
	t_index	*s_index;
}	t_parse;

void	init_data(t_parse *parse);
void	ft_helper(void);
t_parse	ft_parse(char **argv, t_parse *parse);
void	ft_read_file(char *file, t_parse *parse);
void	ft_check_arg(char **arg, t_parse *parse);
void	init_tab(t_parse *parse);
void	ft_check_map(t_parse *parse);
void	ft_check_map2(char *map, t_parse *parse, int j);
void	ft_duplicate_pattern(char *map, int flag, t_parse *parse, int j);
void	ft_check_map_closed(t_parse *parse);
void	ft_insert_texture_path(t_parse *parse, char *map,
			int flag, t_index index);
void	ft_check_texture_path(t_parse *parse, char *map, int flag, int i);
void	ft_read_texture(char *map, int i, t_parse *parse);
void	ft_check_color(int row, char *map, int flag, t_parse *parse);
void	ft_generate_rgb(t_parse *parse, int flag);
int		ft_create_rgb(int r, int g, int b);
void	ft_second_half_checker(t_parse *parse, int i, int j);
void	ft_dfs(t_parse *parse, int i, int j, int *flag);
void	ft_insert_color(int row, t_parse *parse, int flag, int num);
void	ft_insert_simulation(t_parse *parse);
int		ft_isspace(char *map, int index);
void	ft_half_done(t_parse *parse);
int		ft_atoi_color(const char *str, int begin, int end, t_parse *parse);
int		ft_standard_isspace(char c);
int		ft_edges_checker(t_parse *parse, int i, int j);
void	ft_error(char *str, t_parse *parse);
size_t	ft_strlen_mine(const char *s, int j);
int		ft_isspace_no_n(char *map, int index);
void	ft_mark_texture_path(t_parse *parse, char *map, int flag, int j);
int		ft_check_texture_in_sim(char *map, int i);
void	ft_mark_second_texture(int *tab, char *map, int j, t_parse *parse);
void	ft_mark_first_texture(int *tab, char *map, int j, t_parse *parse);
void	ft_malloc_visited(t_parse *parse);
void	ft_initialize_visited(t_parse *parse);
int		ft_launch_dfs(t_parse *parse, int flag);
void	ft_flag_rtn(t_parse *parse, int flag);
void	ft_free_visited(t_parse *parse);
void	ft_fill_sim_array(t_parse *parse);
void	ft_find_max_width(t_parse *parse, int i, int j);
void	ft_malloc_sim(t_parse *parse);
void	ft_check_map_additional(t_parse *parse, int *i, int *j);
int		ft_rtn_tab(t_parse *parse);
void	ft_no_player_pos(t_parse *parse);
void	ft_player_checker(t_parse *parse, int *i, int *j);
void	ft_comma_checker(int row, char *map, t_parse *parse);
int		mouse(int x, int y);
int		ft_tolower(int c);
char	**ft_split(char const *s, char c);
char	**fill(char **split, char const *s, char c);
int		ft_wordcount(char const *s, char c);
int		wordlen(char const *s, char c);
void	freememory(char **mem);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
int		ft_isdigit(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_free_parsing(t_parse *parse);
void	ft_check_empty_line(t_parse *parse, int i);
void	ft_elemenate_empty_lines(t_parse *parse, int *i);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);

#endif