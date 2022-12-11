/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:10:11 by malord            #+#    #+#             */
/*   Updated: 2022/12/11 16:14:39 by flahoud          ###   ########.fr       */
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

void	print_floor(int x, int i, int wall_height, double angle)
{
	t_vars	*vars;
	double	directions[2];

	vars = get_data();
	if (vars->bonus == 0)
		while (i < vars->win_size[1])
			my_mlx_pixel_put(vars->img, x, i++, vars->img->floor_color);
	else
	{
		directions[0] = cos(angle * (PI / 180));
		directions[1] = sin(angle * (PI / 180));
		while (i < vars->win_size[1])
			floor_casting(i++, x, directions, angle);
	}
	(void) wall_height;
}

void	draw_ray(int x, int wall_height, double angle, t_vars *vars)
{
	int			i;
	double		j;
	double		text_increment;
	char		*tmp;
	char		*text_tmp;

	i = 0;
	text_increment = init_increment(wall_height);
	while (i < (vars->win_size[1] / 2 - wall_height))
		my_mlx_pixel_put(vars->img, x, i++, vars->img->ceiling_color);
	j = 0;
	if (wall_height > vars->win_size[1] / 2)
		j += text_increment * (wall_height - (vars->win_size[1] / 2));
	while (i < vars->win_size[1] && i < (vars->win_size[1] / 2 + wall_height))
	{
		tmp = init_tmp(x, &i);
		text_tmp = get_texture_pixel(vars->img->text[vars->texture],
				vars->text_pos, (int)floor(j));
		*tmp++ = *text_tmp++;
		*tmp++ = *text_tmp++;
		*tmp++ = *text_tmp++;
		j += text_increment;
	}
	print_floor(x, i, wall_height, angle);
}

void	generate_img(int win)
{
	t_vars	*vars;

	vars = get_data();
	if (win)
		mlx_clear_window(vars->mlx, vars->win);
	if (!vars->img->screen_view)
		vars->img->screen_view = mlx_new_image(vars->mlx, vars->win_size[0], \
		vars->win_size[1]);
	if (!vars->img->screen_view)
		quit_game(41);
	vars->img->screen_addr = mlx_get_data_addr(vars->img->screen_view, \
	&vars->img->bpp, &vars->img->line_length, &vars->img->endian);
	if (!vars->img->screen_addr)
		quit_game(42);
	raycasting();
	draw_minimap();
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->screen_view, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->character, \
	(vars->win_size[0] / 2) - (vars->img->character_pos[0] / 2), \
	vars->win_size[1] - vars->img->character_pos[1]);
}
