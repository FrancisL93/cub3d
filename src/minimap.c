/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:20:33 by malord            #+#    #+#             */
/*   Updated: 2022/12/07 14:52:41 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_color(int map_item)
{
	char	*color_info;

	if (map_item == 0)
		color_info = ft_strdup("M 255,255,255");
	else if (map_item == 1)
		color_info = ft_strdup("M 0,0,0");
	else
		color_info = ft_strdup("M 255,0,0");
	return (color_info);
}

void	sqmmap(int x, int y, int map_item, t_vars *vars)
{
	char	**minimap_color;
	int		color;
	int		x_tmp;
	int		y_tmp;
	char	*color_info;

	x_tmp = x;
	y_tmp = y;
	color_info = get_color(map_item);
	minimap_color = ft_split(color_info, ' ');
	color = retrieve_color(minimap_color);
	while (x < (x_tmp + 10))
	{
		while (y < (y_tmp + 10))
			my_mlx_pixel_put(vars->img, (y++ + 20), (x + 20), color);
		y = y_tmp;
		x++;
	}
}

void	check_map_size(void)
{
	t_vars	*vars;
	int		size;
	int		max;

	vars = get_data();
	size = 0;
	max = 0;
	while (vars->map[size])
	{
		if (max < (int)ft_strlen(vars->map[size]))
			max = (int)ft_strlen(vars->map[size]);
		size++;
	}
	if ((size * 10) >= vars->win_height || (max * 10) >= vars->win_width)
	{
		ft_putstr_fd("Error\nMap is too large for window size.", STDERR_FILENO);
		quit_game(51);
	}
}

void	draw_minimap(void)
{
	t_vars		*vars;
	int			i;
	int			j;

	i = 0;
	vars = get_data();
	if (vars->bonus == 0)
		return ;
	check_map_size();
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == '1')
				sqmmap(i * 10, j * 10, 1, vars);
			else if (vars->map[i][j] == '0')
				sqmmap(i * 10, j * 10, 0, vars);
			sqmmap((vars->game->posy * 10) - 5,
				(vars->game->posx * 10) - 5, 2, vars);
			j++;
		}
		i++;
	}
}
