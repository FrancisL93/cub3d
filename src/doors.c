/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal <mal@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:55:56 by malord            #+#    #+#             */
/*   Updated: 2022/12/15 23:25:43 by mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	consecutive_doors(void)
{
	t_vars	*vars;
	int		i;
	int		j;

	vars = get_data();
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'O')
				vars->map[i][j] = 'D';
			j++;
		}
		i++;
	}
}

static void	close_doors(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->map[vars->tmpy][vars->tmpx] = 'D';
	consecutive_doors();
}

void	replace_door(void)
{
	t_vars	*vars;

	vars = get_data();
	if (vars->flag == 1 && ((int)vars->game->posy - 1 != vars->tmpy
			|| (int)vars->game->posx != vars->tmpx)
		&& vars->map[(int)vars->game->posy][(int)vars->game->posx] != 'O')
		close_doors();
	else if (vars->flag == 2 && ((int)vars->game->posx != vars->tmpx
			|| (int)vars->game->posy + 1 != vars->tmpy)
		&& vars->map[(int)vars->game->posy][(int)vars->game->posx] != 'O')
		close_doors();
	else if (vars->flag == 3 && ((int)vars->game->posx - 1 != vars->tmpx
			|| (int)vars->game->posy != vars->tmpy)
		&& vars->map[(int)vars->game->posy][(int)vars->game->posx] != 'O')
		close_doors();
	else if (vars->flag == 4 && ((int)vars->game->posx + 1 != vars->tmpx
			|| (int)vars->game->posy != vars->tmpy)
		&& vars->map[(int)vars->game->posy][(int)vars->game->posx] != 'O')
		close_doors();
}

static void	position_door(double posy, double posx)
{
	t_vars	*vars;

	vars = get_data();
	vars->map[(int) posy][(int) posx] = 'O';
	vars->tmpx = (int)posx;
	vars->tmpy = (int)posy;
}

void	door_handling(t_vars *vars)
{
	if (vars->map[((int)vars->game->posy - 1)][(int) vars->game->posx] == 'D')
	{
		position_door(vars->game->posy - 1, vars->game->posx);
		vars->flag = 1;
	}
	else if (vars->map[((int)vars->game->posy + 1)]
		[(int)vars->game->posx] == 'D')
	{
		position_door(vars->game->posy + 1, vars->game->posx);
		vars->flag = 2;
	}
	else if (vars->map[((int)vars->game->posy)]
		[(int) vars->game->posx - 1] == 'D')
	{
		position_door(vars->game->posy, vars->game->posx - 1);
		vars->flag = 3;
	}
	else if (vars->map[((int)vars->game->posy)]
		[(int) vars->game->posx + 1] == 'D')
	{
		position_door(vars->game->posy, vars->game->posx + 1);
		vars->flag = 4;
	}
}
