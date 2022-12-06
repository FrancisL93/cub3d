/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:51:18 by flahoud           #+#    #+#             */
/*   Updated: 2022/12/06 14:41:46 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_floor_pixel(int y, int x, double tile_x, double tile_y)
{
	int		texture_x;
	int		texture_y;
	char	*tmp;
	char	*text_tmp;
	t_vars	*vars;

	vars = get_data();
	texture_x = (tile_x - floor(tile_x)) * vars->img->floor_size[0];
	texture_y = (tile_y - floor(tile_y)) * vars->img->floor_size[1];
	//texture_x = ((int)floor(vars->img->floor_size[0] * tile_x)) % vars->img->floor_size[0];
	//texture_y = ((int)floor(vars->img->floor_size[1] * tile_y)) % vars->img->floor_size[1];
	tmp = init_tmp(x, &y);
	text_tmp = get_texture_pixel(vars->img->floor, texture_x, texture_y);
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
}

void	floor_casting(int y, int x, double *directions, double angle)
{
	t_vars	*vars;
	double	distance;
	double	tile_x;
	double	tile_y;

	vars = get_data();
	distance = vars->win_height / (2 * y - vars->win_height);
	distance =  distance / cos(angle * (PI / 180) - vars->game->dirx * (PI / 180));
	tile_x = distance * directions[0];
	tile_y = distance * directions[1];
	tile_x += vars->game->posx;
	tile_y += vars->game->posy;
	put_floor_pixel(y, x, tile_x, tile_y);
	(void) angle;
}