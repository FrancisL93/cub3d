/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:34:09 by mal               #+#    #+#             */
/*   Updated: 2022/12/12 12:23:30 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	mouse_move(t_vars *vars)
{
	int	increment;
	int	pos_x;
	int	pos_y;

	pos_x = (int)vars->game->posx;
	pos_y = (int)vars->game->posy;
	increment = 5;
	mlx_mouse_get_pos(vars->win, &pos_x, &pos_y);
	vars->game->dirx += increment;
	pos_x += increment;
	pos_y += increment;
	mlx_mouse_get_pos(vars->win, &pos_x, &pos_y);
	return (0);
}
