#include "../includes/cub3d.h"

int	mouse(int x, int y, t_parse *parse)
{
	static int rot;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (0);
	if (x > WIDTH / 2) // or if (x > rot)
	{
		g_util.p.turn_dir = 1;
		g_util.p.rotate_angle += g_util.p.turn_dir * g_util.p.rotat_speed;
		g_util.p.rotate_angle = norm_angle(g_util.p.rotate_angle);
	}
	else if (x < WIDTH / 2) // or if (x < rot)
	{
		g_util.p.turn_dir = -1;
		g_util.p.rotate_angle += g_util.p.turn_dir * g_util.p.rotat_speed;
		g_util.p.rotate_angle = norm_angle(g_util.p.rotate_angle);
	}
    return (0);
}