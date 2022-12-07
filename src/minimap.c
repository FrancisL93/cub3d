/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:20:33 by malord            #+#    #+#             */
/*   Updated: 2022/12/07 10:04:34 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	sqmmap(int x, int y, int map_item)
{
	t_vars	*vars;
	char	**minimap_color;
	int		color;
	int		x_tmp;
	int		y_tmp;
	char	*color_info;

	x_tmp = x;
	y_tmp = y;
	color_info = NULL;
	if (map_item == 0)
		color_info = ft_strdup("M 255,255,255");
	else if (map_item == 1)
		color_info = ft_strdup("M 0,0,0");
	else if (map_item == 2)
		color_info = ft_strdup("M 255,0,0");
	vars = get_data();
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

void	draw_minimap(void)
{
	t_vars		*vars;
	int			i;
	int			j;

	i = 0;
	j = 0;
	vars = get_data();
	if (vars->bonus == 0)
		return ;
	while (vars->map[i])
	{
		j = 0;
		while (vars->minimap[i][j])
		{
			if (vars->minimap[i][j] == '1')
				sqmmap(i * 10, j * 10, 1);
			else if (vars->minimap[i][j] == '0') 
				sqmmap(i * 10, j * 10, 0);
			else if (vars->minimap[i][j] == 'N' || vars->minimap[i][j] == 'S'
						|| vars->minimap[i][j] == 'W'
						|| vars->minimap[i][j] == 'E')
				sqmmap(i * 10, j * 10, 2);
			j++;
		}
		i++;
	}
}
