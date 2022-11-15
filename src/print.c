#include "../inc/cub3d.h"

void	print_floor()
{
	int	x;
	int	y;
	int		color;
	t_vars	*vars;

	y = 9;
	vars = get_data();
	while (vars->full_config[y])
	{
		x = 0;
		while (vars->full_config[y][x])
		{
			if (vars->full_config[y][x] == '0')
				color = 111000;
			else
				color = 434324;
			mlx_pixel_put(vars->mlx, vars->win, x, y, color);
			x++;
		}
		y++;
	}
	return ;
}

void	print_result()
{
	t_vars	*vars;

	vars = get_data();
	mlx_clear_window(vars->mlx, vars->win);
	print_floor();
	mlx_pixel_put(vars->mlx, vars->win, vars->posx, vars->posy, 111000);
}