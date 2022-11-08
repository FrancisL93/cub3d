#include "../inc/cub3d.h"
#include <mlx.h>

int	playgame(int keycode, t_vars *vars)
{
	if (keycode == UP && vars->y > 0)
		vars->y -= 1;
	else if (keycode == DOWN && vars->y < 1080)
		vars->y += 1;
	else if (keycode == LEFT && vars->x > 0)
		vars->x -= 1;
	else if (keycode == RIGHT && vars->x < 1920)
		vars->x += 1;
	print_result(vars);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	static int	restart;

	if (restart == 1)
	{
		return (1);
	}
	if (keycode == ESC)
		quit_game(vars);
	else
		restart = playgame(keycode, vars);
	return (0);
}

void	launch_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "cub3d");
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, quit_game, vars);
	mlx_loop(vars->mlx);
}
