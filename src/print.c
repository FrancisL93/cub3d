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
			*pixel++ = (color >> i);
		else
			*pixel++ = (color >> (data->bpp -8 - i));
		i -=8;
	}
}

char	*get_texture_pixel(void	*text, int x, int y)
{
	int		bpp;
	int		line_size;
	int		endian;
	char	*pixel;

	pixel = mlx_get_data_addr(text, &bpp, &line_size, &endian);
	pixel += (y * line_size + x * (bpp / 8));
	return (pixel);
}

void	draw_ray(int x, int wall_height, int text_pos, int texture)
{
	int			i;
	double		j;
	double		text_increment;
	char		*tmp;
	char		*text_tmp;
	t_vars		*vars;

	i = 0;
	vars = get_data();
	text_increment = (double) 64 / (wall_height) / 2;
	while (i < (vars->win_height / 2 - wall_height))
		my_mlx_pixel_put(vars->img, x, i++, vars->img->ceiling_color);
	j = 0;
	while (i < vars->win_height && i < (vars->win_height / 2 + wall_height))
	{
		tmp = vars->img->screen_addr + (i++ * vars->img->line_length + x * (vars->img->bpp / 8));
		text_tmp = get_texture_pixel(vars->img->text[texture], text_pos, (int) floor(j));
		*tmp++ = *text_tmp++;
		*tmp++ = *text_tmp++;
		*tmp++ = *text_tmp++;
		j += text_increment;
	}
	while (i < vars->win_height)
		my_mlx_pixel_put(vars->img, x, i++, vars->img->floor_color);
}

void	generate_img(void)
{
	t_vars	*vars;

	vars = get_data();
	mlx_clear_window(vars->mlx, vars->win);
	// if (vars->img->screen_view)
	// 	mlx_destroy_image(vars->mlx, vars->img->screen_view);
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
}
