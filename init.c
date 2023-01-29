#include "cub3d.h"

void    init_data(t_parse *parse)
{
    parse->res_x = -1;
    parse->res_y = -1;
    parse->no = NULL;
    parse->so = NULL;
    parse->we = NULL;
    parse->ea = NULL;
    parse->s = NULL;
    parse->f[0] = -1;
    parse->f[1] = -1;
    parse->f[2] = -1;
    parse->c[0] = -1;
    parse->c[1] = -1;
    parse->c[2] = -1;
    parse->map = NULL;
    parse->map_width = 1000;
    parse->map_height = 1000;
    parse->player_x = -1;
    parse->player_y = -1;
    parse->player_dir = '\0';
    parse->save = 0;
}

/*
    parse->s_mlx->mlx = mlx_init();
    if (!parse->s_mlx->mlx)
        ft_error("Error\nmlx_init() failed\n");
    init_mlx(parse);
*/

void    ft_check_arg(char **arg)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(arg[1]);
    if (len < 4)
        ft_error("Error\nInvalid file name\n");
    if (arg[1][len - 1] != 'b' || arg[1][len - 2] != 'u' || arg[1][len - 3] != 'c' || arg[1][len - 4] != '.')
        ft_error("Error\nInvalid file name\n");
}