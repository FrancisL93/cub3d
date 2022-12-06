/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:10:18 by malord            #+#    #+#             */
/*   Updated: 2022/12/06 12:52:56 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_texture(int wall_x, int wall_y)
{
	int			x;
	int			y;
	static int	texture = 0;
	t_vars		*vars;

	vars = get_data();
	x = (int) floor(vars->game->ray_x - vars->game->raycos);
	y = (int) floor(vars->game->ray_y - vars->game->raysin);
	if (x < wall_x && y == wall_y)
		texture = 1;
	else if (x > wall_x && y == wall_y)
		texture = 0;
	else if (y < wall_y && x == wall_x)
		texture = 3;
	else if (y > wall_y && x == wall_x)
		texture = 2;
	return (texture);
}

void	init_ray(double angle)
{
	t_vars	*vars;

	vars = get_data();
	vars->game->ray_x = vars->game->posx;
	vars->game->ray_y = vars->game->posy;
	vars->game->raycos = cos(angle * (PI / 180)) / vars->ray_precision;
	vars->game->raysin = sin(angle * (PI / 180)) / vars->ray_precision;
	while (vars->map[(int) floor(vars->game->ray_y)]
		[(int) floor(vars->game->ray_x)] != '1')
	{
		vars->game->ray_x += vars->game->raycos;
		vars->game->ray_y += vars->game->raysin;
	}
}

void	ray(double angle, int i)
{
	int		wall_height;
	double	distance;
	t_vars	*vars;

	vars = get_data();
	init_ray(angle);
	vars->texture = get_texture((int) floor(vars->game->ray_x),
			(int)floor(vars->game->ray_y));
	if (vars->texture < 0)
		quit_game(43);
	distance = sqrt(pow(vars->game->posx - vars->game->ray_x, 2) + \
	pow(vars->game->posy - vars->game->ray_y, 2));
	distance = distance * cos(angle * (PI / 180) - vars->game->dirx
			* (PI / 180));
	wall_height = floor((vars->win_height / 2) / distance);
	vars->text_pos = floor((int)((int) vars->img->text_height[vars->texture] * \
	(vars->game->ray_x + vars->game->ray_y))
			% vars->img->text_width[vars->texture]);
	if (vars->texture == 3 || vars->texture == 0)
		vars->text_pos = vars->img->text_width[vars->texture] - vars->text_pos;
	draw_ray(i, wall_height, angle, vars);
}

void	raycasting(void)
{
	int		i;
	float	angle;
	t_vars	*vars;

	i = 0;
	vars = get_data();
	angle = vars->game->dirx - (vars->focal_length / 2);
	while (i < vars->win_width)
	{
		ray(angle, i);
		angle += vars->increment_angle;
		i++;
	}
}
