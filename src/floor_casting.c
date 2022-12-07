/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:51:18 by flahoud           #+#    #+#             */
/*   Updated: 2022/12/07 15:47:01 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_ceiling_pixel(int y, int x, double tile_x, double tile_y)
{
	char	*tmp;
	char	*text_tmp;
	int		texture_x;
	int		texture_y;
	t_vars	*vars;

	vars = get_data();
	tmp = init_tmp(x, &y);
	texture_x = (int) floor(tile_x * vars->img->ceiling_size[0]) % vars->img->ceiling_size[0];
	texture_y = (int) floor(tile_y * vars->img->ceiling_size[1]) % vars->img->ceiling_size[1];
	text_tmp = get_texture_pixel(vars->img->ceiling, texture_x, texture_y);
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
}

void	put_floor_pixel(int y, int x, double tile_x, double tile_y)
{
	int		texture_x;
	int		texture_y;
	char	*tmp;
	char	*text_tmp;
	t_vars	*vars;

	vars = get_data();
	tmp = init_tmp(x, &y);
	texture_x = (int) (floor(tile_x * vars->img->floor_size[0])) % vars->img->floor_size[0];
	texture_y = (int) (floor(tile_y * vars->img->floor_size[1])) % vars->img->floor_size[1];
	text_tmp = get_texture_pixel(vars->img->floor, texture_x, texture_y);
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
	*tmp++ = *text_tmp++;
}

void	floor_casting(int y, int x, double *directions, double angle)
{
	t_vars	*vars;
	double	dist;
	// double	current_floor[2];
	double		tile_x;
	double		tile_y;

	vars = get_data();
	(void) angle;
	dist = vars->win_height / (2 * y - vars->win_height);
	dist = dist / cos(vars->game->dirx * (PI / 180));
	// current_floor[0] = weight * directions[0] + (1 - weight) * floor(vars->game->posx);
	// current_floor[1] = weight * directions[1] + (1 - weight) * floor(vars->game->posy);
	// tile_x = (int) (current_floor[0] * vars->img->ceiling_size[0]) % vars->img->ceiling_size[0];
	// tile_y = (int) (current_floor[1] * vars->img->ceiling_size[1]) % vars->img->ceiling_size[1];
	tile_x = dist * directions[0];
	tile_y = dist * directions[1];
	tile_x += vars->game->posx;
	tile_y += vars->game->posy;	
	put_floor_pixel(y, x, tile_x, tile_y);
	put_ceiling_pixel(vars->win_height - y, x, tile_x, tile_y);
}