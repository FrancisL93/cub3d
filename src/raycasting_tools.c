/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:46:17 by flahoud           #+#    #+#             */
/*   Updated: 2022/12/12 15:13:16 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	init_increment(t_ray *ray)
{
	double	text_increment;
	t_vars	*vars;

	vars = get_data();
	text_increment = (double) vars->img->text_height[ray->texture]
		/ (ray->wall_height) / 2;
	return (text_increment);
}

char	*init_tmp(int x, int *i)
{
	t_vars	*vars;
	char	*tmp;

	vars = get_data();
	tmp = vars->img->screen_addr + ((vars->img->line_length) * (*i)++
			+ x * (vars->img->bpp / 8));
	return (tmp);
}
