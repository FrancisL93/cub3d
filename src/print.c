#include "../include/cub3d.h"

void	print_result()
{
	t_vars	*vars;

	vars = get_data();
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->screen_view, 0, 0);
}
