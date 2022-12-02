#include "../include/cub3d.h"

int	key_hook(int keycode)
{
	t_vars	*vars;
	int		increment;

	increment = 5;
	vars = get_data();
	if (keycode == ESC)
		quit_game(50);
	else
	{
		set_movement(keycode);
		if (keycode == LEFTA)
			vars->game->dirx -= increment;
		else if (keycode == RIGHTA)
			vars->game->dirx += increment;
		if (vars->game->dirx > 360)
			vars->game->dirx = increment;
		else if (vars->game->dirx < 0)
			vars->game->dirx = 360 - increment;
		generate_img(1);
	}
	return (0);
}

void	init_data(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->game = malloc(sizeof(*vars->game));
	if (!vars->game)
		quit_game(33);
	vars->img->screen_view = NULL;
	vars->focal_length = 60;
	vars->win_width = 1920;
	vars->win_height = 1080;
	vars->increment_angle = vars->focal_length / vars->win_width;
	vars->ray_precision = vars->win_width / 4;
	vars->game->movement = 3;
	vars->game->posx = 0;
	vars->game->posy = 0;
	vars->game->diry = 0;
	vars->game->ray_x = 0;
	vars->game->ray_y = 0;
	vars->game->raycos = 0;
	vars->game->raysin = 0;
	set_up_start();
	set_colors();
}

void	launch_game(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_putstr_fd("Error\nMlx init failure\n", STDERR_FILENO);
		quit_game(30);
	}
	build_imgs();
	init_data();
	printf("Apres init = %f\n", vars->game->dirx);
	if (vars->mlx != NULL)
		vars->win = mlx_new_window(vars->mlx, vars->win_width,
				vars->win_height, "Cub3d");
	if (!vars->win)
	{
		ft_putstr_fd("Error\nMlx window creation failure\n", STDERR_FILENO);
		quit_game(40);
	}
	generate_img(0);
	mlx_hook(vars->win, 2, 0, key_hook, 0);
	mlx_hook(vars->win, 17, 0, quit_game, 0);
	mlx_loop(vars->mlx);
}
