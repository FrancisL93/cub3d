#include "../inc/cub3d.h"
#include <mlx.h>

void	playgame(int keycode)
{
	t_vars	*vars;
	int	move_size;

	move_size = 5;
	vars = get_data();
	if (keycode == UP && vars->posy > 0)
		vars->posy -= move_size;
	else if (keycode == DOWN && vars->posy < 1080)
		vars->posy += move_size;
	else if (keycode == LEFT && vars->posx > 0)
		vars->posx -= move_size;
	else if (keycode == RIGHT && vars->posx < 1920)
		vars->posx += move_size;
	print_result();
}

int	key_hook(int keycode)
{
	if (keycode == ESC)
		quit_game();
	else
		playgame(keycode);
	return (0);
}

void	launch_game()
{
	t_vars	*vars;
	
	vars = get_data();
	vars->win_width = 1920;
	vars->win_height = 1080;
	vars->win = mlx_new_window(vars->mlx, vars->win_width, vars->win_height, "cub3d");
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, quit_game, vars);
	mlx_loop(vars->mlx);
}
