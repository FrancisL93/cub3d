/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:10:18 by malord            #+#    #+#             */
/*   Updated: 2022/12/14 16:18:35 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_texture(t_ray *ray)
{
	int			x;
	int			y;
	static int	texture = 0;
	t_vars		*vars;

	vars = get_data();
	x = (int) floor(ray->x - ray->cos);
	y = (int) floor(ray->y - ray->sin);
	if (vars->map[(int)ray->y][(int)ray->x] == 'D')
	{
		texture = 4;
		return (texture);
	}
	if (x < floor(ray->x) && y == floor(ray->y))
		texture = 1;
	else if (x > floor(ray->x) && y == floor(ray->y))
		texture = 0;
	else if (y < floor(ray->y) && x == floor(ray->x))
		texture = 3;
	else if (y > floor(ray->y) && x == floor(ray->x))
		texture = 2;
	return (texture);
}

void	calculate_ray(t_ray *ray)
{
	t_vars	*vars;

	vars = get_data();
	ray->texture = get_texture(ray);
	if (ray->texture < 0)
		quit_game(43);
	ray->distance = sqrt(pow(vars->game->posx - ray->x, 2) + \
	pow(vars->game->posy - ray->y, 2));
	ray->distance = ray->distance * cos(ray->angle * (PI / 180) - \
	vars->game->dirx * (PI / 180));
	ray->wall_height = floor((WIN_HEIGHT / 2) / ray->distance);
	ray->text_pos = floor((int)((int) vars->img->text_width[ray->texture] * \
	(ray->x + ray->y))
			% vars->img->text_width[ray->texture]);
	if (ray->texture == 3 || ray->texture == 0)
		ray->text_pos = vars->img->text_width[ray->texture] - ray->text_pos;
	draw_ray(ray, vars);
}

void	raycasting(void)
{
	int		i;
	t_vars	*vars;
	t_ray	ray;

	i = 0;
	vars = get_data();
	ray.angle = vars->game->dirx - (FOCAL_LENGTH / 2);
	while (i < WIN_WIDTH)
	{
		ray.pos = i;
		ray.x = vars->game->posx;
		ray.y = vars->game->posy;
		ray.cos = cos(ray.angle * (PI / 180)) / (double) RAY_PRECISION;
		ray.sin = sin(ray.angle * (PI / 180)) / (double) RAY_PRECISION;
		while (vars->map[(int) floor(ray.y)][(int) floor(ray.x)] == '0')
		{
			ray.x += ray.cos;
			ray.y += ray.sin;
		}
		calculate_ray(&ray);
		ray.angle += (double) FOCAL_LENGTH / WIN_WIDTH;
		i++;
	}
}
