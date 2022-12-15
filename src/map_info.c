/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:21 by malord            #+#    #+#             */
/*   Updated: 2022/12/15 13:20:40 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	get_element_index(char *element, char **tmp)
{
	char	*elem_list[6];
	int		i;
	t_vars	*vars;

	i = -1;
	vars = get_data();
	elem_list[0] = "NO";
	elem_list[1] = "SO";
	elem_list[2] = "WE";
	elem_list[3] = "EA";
	elem_list[4] = "F";
	elem_list[5] = "C";
	while (element && ++i < 6)
	{
		if (ft_strncmp(element, elem_list[i], ft_strlen(tmp[0])) == 0)
		{
			if (vars->mapdata[i])
			{
				free_double_array((void **)tmp);
				quit_game(10);
			}
			return (i);
		}
	}
	return (-1);
}

bool	check_full_config(t_vars *vars)
{
	int	j;

	j = 0;
	while (vars->mapdata[j++])
	{
		if (j == 6)
			return (true);
	}
	return (false);
}

void	get_mapdata(void)
{
	int		i;
	int		map_start;
	char	**tmp;
	t_vars	*vars;

	i = -1;
	vars = get_data();
	map_start = find_map(vars->full_config);
	while (++i < map_start)
	{
		tmp = ft_split(vars->full_config[i], ' ');
		if (tmp && tmp[0][0] != '\n')
		{
			if (tmp[1] && get_element_index(tmp[0], tmp) >= 0 \
			&& check_full_config(vars) == false)
				vars->mapdata[get_element_index(tmp[0], tmp)]
					= vars->full_config[i];
			else
			{
				free_double_array((void **) tmp);
				quit_game(10);
			}
		}
		free_double_array((void **)tmp);
	}
}
