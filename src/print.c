#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_img	*data, int x, int y, int color)
{
	int		i;
	char	*pixel;

	i = data->bpp - 8;
	pixel = data->screen_addr + (y * data->line_length + x * (data->bpp / 8));
	while (i >= 0)
	{
		if (data->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->bpp -8 - i)) & 0xFF;
		i -=8;
	}
}

void	render_floor(void)
{
	int		x;
	int		y;
	t_vars	*vars;

	y = 0;
	vars = get_data();
	while (y < vars->win_height / 2)
	{
		x = 0;
		while (x < vars->win_width)
			my_mlx_pixel_put(vars->img, x++, y, vars->img->floor_color);
		y++;
	}
	while (y < vars->win_height)
	{
		x = 0;
		while (x < vars->win_width)
			my_mlx_pixel_put(vars->img, x++, y, vars->img->ceiling_color);
		y++;
	}
}

void	draw_ray(int x, int wall_height)
{
	int	i;
	t_vars	*vars;

	i = 0;
	vars = get_data();
	while (i < (vars->win_height / 2 - wall_height))
		my_mlx_pixel_put(vars->img, x, i, vars->img->ceiling_color);
	while (i < (vars->win_height / 2 + wall_height))
		my_mlx_pixel_put(vars->img, x, i, vars->img->wall_color);
	while (i < vars->win_height)
		my_mlx_pixel_put(vars->img, x, i, vars->img->wall_color);
}

void	generate_img(void)
{
	t_vars	*vars;

	vars = get_data();
	mlx_clear_window(vars->mlx, vars->win);
	vars->img->screen_view = mlx_new_image(vars->mlx, vars->win_width, \
	vars->win_height);
	if (!vars->img->screen_view)
		quit_game(8);
	vars->img->screen_addr = mlx_get_data_addr(vars->img->screen_view, \
	&vars->img->bpp, &vars->img->line_length, &vars->img->endian);
	if (!vars->img->screen_addr)
		quit_game(9);
	//render_floor();
	raycasting();
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->screen_view, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img->screen_view);
}
