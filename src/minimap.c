/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:20:33 by malord            #+#    #+#             */
/*   Updated: 2022/12/06 15:20:34 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void draw_minimap(void)
{
	t_vars		*vars;
	int			i;
	int			j;
	char		**minimap_color;
	int			color;

	i = 20;
	j = 20;
	vars = get_data();
	if (vars->bonus == 0)
		return ;
	minimap_color = ft_split(ft_strdup("M 255,255,255"), ' ');
	color = retrieve_color(minimap_color);
	while (j < (vars->win_height / 7))
	{
		while (i < vars->win_height / 4)
			my_mlx_pixel_put(vars->img, i++, j, color);
		i = 20;
		j++;
	}
}
