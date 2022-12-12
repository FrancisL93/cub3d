/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal <mal@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:34:09 by mal               #+#    #+#             */
/*   Updated: 2022/12/12 15:01:56 by mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	mouse_move(int x, int y, t_vars *vars)
{
	double	increment;

	(void)y;
	generate_img(1);
	increment = 0.1;
	vars->game->dirx += (x - WIN_WIDTH / 2) * increment;
	if (vars->game->dirx > 360)
		vars->game->dirx = increment;
	else if (vars->game->dirx < 0)
		vars->game->dirx = 360 - increment;
	mlx_mouse_move(vars->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
