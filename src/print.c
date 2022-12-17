/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal <mal@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:10:11 by malord            #+#    #+#             */
/*   Updated: 2022/12/16 16:00:50 by mal              ###   ########.fr       */
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

void	print_character(void)
{
	t_vars	*vars;

	vars = get_data();
	if (vars->bonus == 0)
		return ;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->text[CHARACT], \
	(WIN_WIDTH / 2) - (vars->img->text_width[CHARACT] / 2), \
	WIN_HEIGHT - vars->img->text_height[CHARACT]);
}

void	draw_ray(t_ray *ray, t_vars *vars)
{
	int			i;
	double		j;
	char		*tmp;
	char		*text_tmp;

	i = 0;
	ray->text_increment = init_increment(ray);
	while (vars->bonus == 0 && i < (WIN_HEIGHT / 2 - ray->wall_height))
		my_mlx_pixel_put(vars->img, ray->pos, i++, vars->img->color[1]);
	while (vars->bonus == 1 && i < (WIN_HEIGHT / 2 - ray->wall_height))
		i++;
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
	print_floor(ray, i);
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
		quit_game(25);
	vars->img->screen_addr = mlx_get_data_addr(vars->img->screen_view, \
	&vars->img->bpp, &vars->img->line_length, &vars->img->endian);
	if (!vars->img->screen_addr)
		quit_game(26);
	raycasting();
	draw_minimap();
	replace_door();
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->screen_view, 0, 0);
	print_character();
}
