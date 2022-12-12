/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:20:33 by malord            #+#    #+#             */
/*   Updated: 2022/12/12 10:59:06 by flahoud          ###   ########.fr       */
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
	int			x_tmp;
	int			y_tmp;
	static int	color[3];

	x_tmp = x;
	y_tmp = y;
	if (color[0] == 0)
	{
		color[0] = retrieve_color(ft_split(get_color(0), ' '));
		color[1] = retrieve_color(ft_split(get_color(1), ' '));
		color[2] = retrieve_color(ft_split(get_color(2), ' '));
	}
	while (x < (x_tmp + 10))
	{
		while (y < (y_tmp + 10))
			my_mlx_pixel_put(vars->img, (y++ + 20), (x + 20), color[map_item]);
		y = y_tmp;
		x++;
	}
}

void	check_map_size(void)
{
	t_vars	*vars;
	int		size;
	int		max;

	max = 0;
	size = 0;
	vars = get_data();
	while (vars->map[size])
	{
		if (max < (int)ft_strlen(vars->map[size]))
			max = (int)ft_strlen(vars->map[size]);
		size++;
	}
	if ((size * 10) >= WIN_HEIGHT || (max * 10) >= WIN_WIDTH)
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
			j++;
		}
		i++;
	}
	sqmmap((vars->game->posy * 10) - 5, (vars->game->posx * 10) - 5, 2, vars);
}
