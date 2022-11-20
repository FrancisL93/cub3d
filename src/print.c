#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_img	*data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_result(void)
{
	t_vars	*vars;

	vars = get_data();
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->screen_view, 0, 0);
}
