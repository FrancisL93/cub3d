/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:26:33 by francislaho       #+#    #+#             */
/*   Updated: 2022/12/15 11:35:47 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	mouse_move(int x, int y, t_vars *vars)
{
	double	increment;

	(void)y;
	generate_img(1);
	increment = 0.1;
	vars->game->dirx += (x - WIN_WIDTH / 2) * increment;
	if (vars->game->dirx > 360)
		vars->game->dirx = increment;
	else if (vars->game->dirx < 0)
		vars->game->dirx = 360 - increment;
	mlx_mouse_move(vars->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}

void	sqmmap(int x, int y, int map_item, t_vars *vars)
{
	int			x_tmp;
	int			y_tmp;
	static int	color[4];

	x_tmp = x;
	y_tmp = y;
	if (color[0] == 0)
	{
		color[0] = retrieve_color(ft_split("M 255,255,255", ' '));
		color[1] = retrieve_color(ft_split("M 0,0,0", ' '));
		color[2] = retrieve_color(ft_split("M 255,0,0", ' '));
		color[3] = retrieve_color(ft_split("M 68,214,44", ' '));
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
		quit_game(24);
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
			else if (vars->map[i][j] == '0' || vars->map[i][j] == 'O')
				sqmmap(i * 10, j * 10, 0, vars);
			else if (vars->map[i][j] == 'D')
				sqmmap(i * 10, j * 10, 3, vars);
			j++;
		}
		i++;
	}
	sqmmap((vars->game->posy * 10) - 5, (vars->game->posx * 10) - 5, 2, vars);
}
