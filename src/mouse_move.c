/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal <mal@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:34:09 by mal               #+#    #+#             */
/*   Updated: 2022/12/09 13:37:49 by mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	mouse_move(t_vars *vars)
{
	int	pos_x;
	int	pos_y;
	int	result;

	pos_x = (int)vars->game->posx;
	pos_y = (int)vars->game->posy;
	result = mlx_mouse_get_pos(vars->win, &pos_x, &pos_y);
	return (result);
}
