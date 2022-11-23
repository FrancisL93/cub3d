#include "../include/cub3d.h"

int	direction_hook(int keycode)
{
	t_vars	*vars;

	vars = get_data();
	if (keycode == LEFTA)
		vars->game->dirx -= 0.1;
	else if (keycode == RIGHTA)
		vars->game->dirx += 0.1;
	return (0);
}

int	key_hook(int keycode)
{
	t_vars	*vars;

	vars = get_data();
	if (keycode == ESC)
		quit_game(12);
	else
	{
		if (keycode == UP)
			vars->game->posy -= 1;
		else if (keycode == DOWN)
			vars->game->posy += 1;
		else if (keycode == LEFT)
			vars->game->posx -= 1;
		else if (keycode == RIGHT)
			vars->game->posx += 1;
		generate_img();
	}
	return (0);
}

void	init_data(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->game = malloc(sizeof(vars->game));
	if (!vars->game)
		quit_game(7);
	set_up_start();
	set_colors();
	vars->focal_length = 66;
	vars->win_width = 1900;
	vars->win_height = 1080;
	vars->increment_angle = vars->focal_length / vars->win_width;
	vars->ray_precision = 64;
	vars->img->wall_color = 255;
}

void	launch_game(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->mlx = mlx_init();
	build_imgs();
	init_data();
	vars->win = mlx_new_window(vars->mlx, vars->win_width, \
	vars->win_height, "Cub3d");
	generate_img();
	mlx_hook(vars->win, 2, 1L << 0, direction_hook, vars);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, quit_game, vars);
	mlx_loop(vars->mlx);
}
