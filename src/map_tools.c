/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:33 by malord            #+#    #+#             */
/*   Updated: 2022/12/15 11:22:06 by flahoud          ###   ########.fr       */
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

void	map_square(void)
{
	int		i;
	int		j;
	int		max_len;
	t_vars	*vars;

	i = -1;
	vars = get_data();
	max_len = ft_strlen(vars->map[0]);
	while (vars->map[++i])
	{
		if ((int)ft_strlen(vars->map[i]) > max_len)
			max_len = ft_strlen(vars->map[i]);
	}
	i = -1;
	while (vars->map[++i])
	{
		vars->map[i][ft_strlen(vars->map[i]) - 1] = '\0';
		j = 0;
		while (vars->map[i][j])
			j++;
		while (j++ < max_len)
			vars->map[i] = add_string_last('1', vars->map[i]);
		vars->map[i] = add_string_last('\n', vars->map[i]);
	}
}
