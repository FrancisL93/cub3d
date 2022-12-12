/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:10:11 by malord            #+#    #+#             */
/*   Updated: 2022/12/12 16:38:30 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		i -= 8;
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

void	print_floor(int x, int i, double angle)
{
	t_vars	*vars;
	double	directions[2];

	vars = get_data();
	if (vars->bonus == 0)
		while (i < WIN_HEIGHT)
			my_mlx_pixel_put(vars->img, x, i++, vars->img->floor_color);
	else
	{
		directions[0] = cos(angle * (PI / 180));
		directions[1] = sin(angle * (PI / 180));
		while (i < WIN_HEIGHT)
			floor_casting(i++, x, angle);
	}
}

void	draw_ray(t_ray *ray, t_vars *vars)
{
	int			i;
	double		j;
	char		*tmp;
	char		*text_tmp;

	i = 0;
	ray->text_increment = init_increment(ray);
	while (i < (WIN_HEIGHT / 2 - ray->wall_height))
		my_mlx_pixel_put(vars->img, ray->pos, i++, vars->img->ceiling_color);
	j = 0;
	if (ray->wall_height > WIN_HEIGHT / 2)
		j += ray->text_increment * (ray->wall_height - (WIN_HEIGHT / 2));
	while (i < WIN_HEIGHT && i < (WIN_HEIGHT / 2 + ray->wall_height))
	{
		tmp = init_tmp(ray->pos, &i);
		text_tmp = get_texture_pixel(vars->img->text[ray->texture],
				ray->text_pos, (int)floor(j));
		*tmp++ = *text_tmp++;
		*tmp++ = *text_tmp++;
		*tmp++ = *text_tmp++;
		j += ray->text_increment;
	}
	print_floor(ray->pos, i, ray->angle);
}

void	generate_img(int win)
{
	t_vars	*vars;

	vars = get_data();
	if (win)
		mlx_clear_window(vars->mlx, vars->win);
	if (!vars->img->screen_view)
		vars->img->screen_view = mlx_new_image(vars->mlx, WIN_WIDTH, \
		WIN_HEIGHT);
	if (!vars->img->screen_view)
		quit_game(41);
	vars->img->screen_addr = mlx_get_data_addr(vars->img->screen_view, \
	&vars->img->bpp, &vars->img->line_length, &vars->img->endian);
	if (!vars->img->screen_addr)
		quit_game(42);
	raycasting();
	// if (vars->bonus)
	// 	floor_casting();
	draw_minimap();
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->screen_view, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->character, \
	(WIN_WIDTH / 2) - (vars->img->character_pos[0] / 2), \
	WIN_HEIGHT - vars->img->character_pos[1]);
}
