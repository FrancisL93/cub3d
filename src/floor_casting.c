/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:51:18 by flahoud           #+#    #+#             */
/*   Updated: 2022/12/13 15:11:00 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_ceiling_pixel(t_vars *vars, t_ray *ray, int y)
{
	int		text_x;
	int		text_y;
	char	*tmp;
	char	*text_tmp;

	y = WIN_HEIGHT - y;
	tmp = init_tmp(ray->pos, &y);
	text_x = ((int) floor(ray->x * vars->img->ceiling_size[0])) \
	% vars->img->ceiling_size[0];
	text_y = ((int) floor(ray->y * vars->img->ceiling_size[1])) \
	% vars->img->ceiling_size[1];
	text_tmp = get_texture_pixel(vars->img->ceiling, text_x, text_y);
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
}

void	put_floor_pixel(t_vars *vars, t_ray *ray, int y)
{
	int		text_x;
	int		text_y;
	char	*tmp;
	char	*text_tmp;

	tmp = init_tmp(ray->pos, &y);
	text_x = ((int) floor(ray->x * vars->img->floor_size[0])) \
	% vars->img->floor_size[0];
	text_y = ((int) floor(ray->y * vars->img->floor_size[1])) \
	% vars->img->floor_size[1];
	text_tmp = get_texture_pixel(vars->img->floor, text_x, text_y);
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
