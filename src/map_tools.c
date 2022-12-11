/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:33 by malord            #+#    #+#             */
/*   Updated: 2022/12/11 16:38:10 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	set_direction(char dir)
{
	if (dir == 'E')
		return (0);
	else if (dir == 'S')
		return (90);
	else if (dir == 'W')
		return (180);
	else if (dir == 'N')
		return (270);
	return (0);
}

void	set_up_start(void)
{
	int		i;
	int		j;
	t_vars	*vars;

	i = 1;
	vars = get_data();
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (ft_strchr("NSEW", vars->map[i][j]))
			{
				vars->game->posx = j + 0.5;
				vars->game->posy = i + 0.5;
				vars->game->dirx = set_direction(vars->map[i][j]);
				vars->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	format_map(void)
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
			if (vars->map[i][j] == ' ')
				check_spaces(i, j);
			if (vars->map[i][j] == '0' && vars->map[i + 1])
				check_zeros(i, j);
			j++;
		}
		i++;
	}
	check_walls();
	map_square();
}
