/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:10:11 by malord            #+#    #+#             */
/*   Updated: 2022/12/05 15:41:58 by malord           ###   ########.fr       */
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

void	draw_ray(int x, int wall_height, t_vars *vars)
{
	int			i;
	double		j;
	double		text_increment;
	char		*tmp;
	char		*text_tmp;

	i = 0;
	text_increment = init_increment(wall_height);
	while (i < (vars->win_height / 2 - wall_height))
		my_mlx_pixel_put(vars->img, x, i++, vars->img->ceiling_color);
	j = 0;
	if (wall_height > vars->win_height / 2)
		j += text_increment * (wall_height - (vars->win_height / 2));
	while (i < vars->win_height && i < (vars->win_height / 2 + wall_height))
	{
		tmp = init_tmp(x, &i);
		text_tmp = get_texture_pixel(vars->img->text[vars->texture],
				vars->text_pos, (int)floor(j));
		*tmp++ = *text_tmp++;
		*tmp++ = *text_tmp++;
		*tmp++ = *text_tmp++;
		j += text_increment;
	}
	while (i < vars->win_height)
		my_mlx_pixel_put(vars->img, x, i++, vars->img->floor_color);
}

void	generate_img(int win)
{
	t_vars	*vars;

	vars = get_data();
	if (win)
		mlx_clear_window(vars->mlx, vars->win);
	if (!vars->img->screen_view)
		vars->img->screen_view = mlx_new_image(vars->mlx, vars->win_width, \
		vars->win_height);
	if (!vars->img->screen_view)
		quit_game(41);
	vars->img->screen_addr = mlx_get_data_addr(vars->img->screen_view, \
	&vars->img->bpp, &vars->img->line_length, &vars->img->endian);
	if (!vars->img->screen_addr)
		quit_game(42);
	raycasting();
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->screen_view, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->character, \
	(vars->win_width / 2) - (vars->img->character_pos[0] / 2), \
	vars->win_height - vars->img->character_pos[1]);
}
