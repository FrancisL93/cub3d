/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:55:00 by mal               #+#    #+#             */
/*   Updated: 2022/12/19 12:59:40 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ingame_controls(int keycode)
{
	t_vars	*vars;
	int		increment;

	increment = 5;
	vars = get_data();
	if (vars->game_start == true)
	{
		set_movement(keycode);
		if (keycode == SPACE)
			door_handling(vars);
		if (keycode == LEFTA)
			vars->game->dirx -= increment;
		else if (keycode == RIGHTA)
			vars->game->dirx += increment;
		if (vars->game->dirx > 360)
			vars->game->dirx = increment;
		else if (vars->game->dirx < 0)
			vars->game->dirx = 360 - increment;
		generate_img(1);
	}
}

int	key_hook_bonus(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		quit_game(30);
	else
	{
		if (keycode == Y_KEY && vars->game_start == false)
		{
			vars->game_start = true;
			launch_game_bonus();
		}
		ingame_controls(keycode);
	}
	return (0);
}
