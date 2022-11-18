#include "../include/cub3d.h"
#include <mlx.h>

int	key_hook(int keycode)
{
	t_vars	*vars;

	vars = get_data();
	if (keycode == ESC)
		quit_game(10);
	else
	{
		vars->img->screen_view = mlx_new_image(vars->mlx, vars->win_width, vars->win_height);
		vars->img->screen_data = mlx_get_data_addr(vars->img->screen_view, &vars->img->bits_per_pixel, 
			&vars->img->line_length, &vars->img->endian);
		//update vars->img->screen_view before reprinting
		print_result();
		mlx_destroy_image(vars->mlx, vars->img->screen_view);
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
}

void	launch_game(void)
{
	t_vars	*vars;
	
	vars = get_data();
	init_data();
	vars->win_width = 1920;
	vars->win_height = 1080;
	vars->win = mlx_new_window(vars->mlx, vars->win_width, vars->win_height, "Cub3d");
	vars->img->screen_view = mlx_new_image(vars->mlx, vars->win_width, vars->win_height);
	vars->img->screen_data = mlx_get_data_addr(vars->img->screen_view, &vars->img->bits_per_pixel, 
		&vars->img->line_length, &vars->img->endian);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, quit_game, vars);
	mlx_loop(vars->mlx);
}
