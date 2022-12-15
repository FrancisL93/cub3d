/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:51:18 by flahoud           #+#    #+#             */
/*   Updated: 2022/12/15 11:28:09 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	put_ceiling_pixel(t_vars *vars, t_ray *ray, int y)
{
	int		text_x;
	int		text_y;
	char	*tmp;
	char	*text_tmp;

	y = WIN_HEIGHT - y;
	tmp = init_tmp(ray->pos, &y);
	text_x = ((int) floor(ray->x * vars->img->text_width[CEILING])) \
	% vars->img->text_width[CEILING];
	text_y = ((int) floor(ray->y * vars->img->text_height[CEILING])) \
	% vars->img->text_height[CEILING];
	text_tmp = get_texture_pixel(vars->img->text[CEILING], \
	vars->img->text_width[CEILING] - text_x, text_y);
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
}

static void	put_floor_pixel(t_vars *vars, t_ray *ray, int y)
{
	int		text_x;
	int		text_y;
	char	*tmp;
	char	*text_tmp;

	tmp = init_tmp(ray->pos, &y);
	text_x = ((int) floor(ray->x * vars->img->text_width[FLOOR])) \
	% vars->img->text_width[FLOOR];
	text_y = ((int) floor(ray->y * vars->img->text_height[FLOOR])) \
	% vars->img->text_height[FLOOR];
	text_tmp = get_texture_pixel(vars->img->text[FLOOR], text_x, text_y);
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
}

void	floor_casting(t_ray *ray, int y)
{
	t_vars	*vars;

	vars = get_data();
	ray->distance = (double) WIN_HEIGHT / (2 * y - WIN_HEIGHT);
	ray->distance = ray->distance / cos(vars->game->dirx * (PI / 180) - \
	ray->angle * (PI / 180));
	ray->x = ray->distance * ray->cos + vars->game->posx;
	ray->y = ray->distance * ray->sin + vars->game->posy;
	put_floor_pixel(vars, ray, y);
	put_ceiling_pixel(vars, ray, y);
}

void	print_floor(t_ray *ray, int i)
{
	t_vars	*vars;

	vars = get_data();
	if (vars->bonus == 0)
		while (i < WIN_HEIGHT)
			my_mlx_pixel_put(vars->img, ray->pos, i++, vars->img->color[0]);
	else
	{
		ray->cos = cos(ray->angle * (PI / 180));
		ray->sin = sin(ray->angle * (PI / 180));
		while (i < WIN_HEIGHT)
			floor_casting(ray, i++);
	}
}
