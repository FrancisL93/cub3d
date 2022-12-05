/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:30:48 by malord            #+#    #+#             */
/*   Updated: 2022/12/05 15:33:57 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	init_increment(int wall_height)
{
	double	text_increment;
	t_vars	*vars;

	vars = get_data();
	text_increment = (double) vars->img->text_height[vars->texture]
		/ (wall_height) / 2;
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
