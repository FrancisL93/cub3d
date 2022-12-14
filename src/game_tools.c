/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:08 by malord            #+#    #+#             */
/*   Updated: 2022/12/14 17:04:21 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_up(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->game->posx += cos(vars->game->dirx * (PI / 180))
		/ vars->game->movement;
	vars->game->posy += sin(vars->game->dirx * (PI / 180))
		/ vars->game->movement;
	return ;
}

void	move_down(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->game->posx -= cos(vars->game->dirx * (PI / 180))
		/ vars->game->movement;
	vars->game->posy -= sin(vars->game->dirx * (PI / 180))
		/ vars->game->movement;
	return ;
}

void	move_left(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->game->posx += cos((vars->game->dirx - 90) * (PI / 180))
		/ vars->game->movement;
	vars->game->posy += sin((vars->game->dirx - 90) * (PI / 180))
		/ vars->game->movement;
	return ;
}

void	move_right(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->game->posx += cos((vars->game->dirx + 90) * (PI / 180))
		/ vars->game->movement;
	vars->game->posy += sin((vars->game->dirx + 90) * (PI / 180))
		/ vars->game->movement;
	return ;
}

void	set_movement(int keycode)
{
	double	x;
	double	y;
	t_vars	*vars;

	vars = get_data();
	x = vars->game->posx;
	y = vars->game->posy;
	if (keycode == UP)
		move_up();
	else if (keycode == DOWN)
		move_down();
	else if (keycode == LEFT)
		move_left();
	else if (keycode == RIGHT)
		move_right();
	if (vars->map[(int) floor(vars->game->posy)]
		[(int) floor(vars->game->posx)] == '1'
		|| vars->map[(int) floor(vars->game->posy)]
		[(int) floor(vars->game->posx)] == 'D')
	{
		vars->game->posx = x;
		vars->game->posy = y;
	}
}
