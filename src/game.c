#include "../include/cub3d.h"

int	key_hook(int keycode)
{
	t_vars	*vars;
	int		increment;

	increment = 1;

	vars = get_data();
	if (keycode == ESC)
		quit_game(12);
	else
	{
		if (keycode == UP)
			vars->game->posy -= 0.25;
		else if (keycode == DOWN)
			vars->game->posy += 0.25;
		else if (keycode == LEFT)
			vars->game->posx -= 0.25;
		else if (keycode == RIGHT)
			vars->game->posx += 0.25;
		else if (keycode == LEFTA)
			vars->game->dirx -= increment;
		else if (keycode == RIGHTA)
			vars->game->dirx += increment;
		if (vars->game->dirx > 360)
			vars->game->dirx = increment;
		else if (vars->game->dirx < 0)
			vars->game->dirx = 360 - increment;
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
	vars->focal_length = 60;
	vars->win_width = 1920;
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
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, quit_game, vars);
	mlx_loop(vars->mlx);
}
