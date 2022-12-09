/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:51:18 by flahoud           #+#    #+#             */
/*   Updated: 2022/12/09 13:57:07 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_ceiling_pixel(int y, int x, double tile_x, double tile_y)
{
	char	*tmp;
	char	*text_tmp;
	t_vars	*vars;

	vars = get_data();
	tmp = init_tmp(x, &y);
	tile_x = abs((int) tile_x % vars->img->ceiling_size[0]);
	tile_y = abs((int) tile_y % vars->img->ceiling_size[1]);
	//tile_y = (int) floor(tile_y * vars->img->ceiling_size[1]) % vars->img->ceiling_size[1];
	text_tmp = get_texture_pixel(vars->img->ceiling, tile_x, tile_y);
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
}

void	put_floor_pixel(int y, int x, double tile_x, double tile_y)
{
	char	*tmp;
	char	*text_tmp;
	t_vars	*vars;

	vars = get_data();
	tmp = init_tmp(x, &y);
	tile_x = abs((int) (tile_x + vars->game->posx * (double) vars->img->floor_size[0]) % vars->img->floor_size[0]);
	tile_y = abs((int) (tile_y + vars->game->posy * (double) vars->img->floor_size[1]) % vars->img->floor_size[1]);
	text_tmp = get_texture_pixel(vars->img->floor, tile_x, tile_y);
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
}

void	floor_casting(int y, int x, double *directions, double angle)
{
	t_vars	*vars;
	double	angle_beta;
	double	r;
	double	straight_line_dist;
	double	player_height;
	double	d;
	double	floor_xy[2];

	vars = get_data();
	player_height = vars->win_height;
	angle_beta = fabs(angle - vars->game->dirx);
	r = y - vars->win_height / 2;
	straight_line_dist = (player_height * 277) / r;
	d = straight_line_dist / cos(angle * (PI / 180));
	floor_xy[0] = vars->game->posx + cos(angle * (PI / 180)) * d;
	floor_xy[1] = vars->game->posy - sin(angle * (PI / 180)) * d;
	put_floor_pixel(y, x, floor_xy[0], floor_xy[1]);
	put_ceiling_pixel(vars->win_height - y, x, floor_xy[0], floor_xy[1]);
	(void) directions;
	(void) x;
}
