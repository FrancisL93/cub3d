/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:51 by malord            #+#    #+#             */
/*   Updated: 2022/12/19 09:21:16 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	free_n_quit(char **color_line, char **rgb)
{
	free_double_array((void **)color_line);
	free_double_array((void **)rgb);
	quit_game(22);
}

static void	check_letters(char **rgb, char **color_line)
{
	int	i;
	int	j;

	i = 0;
	while (rgb && rgb[i])
	{
		j = 0;
		rgb[i] = ft_strtrim_free(rgb[i], "\n");
		if (!rgb[i][0])
			free_n_quit(color_line, rgb);
		while (rgb[i][j])
		{
			if (ft_isdigit(rgb[i][j]) == 0)
				free_n_quit(color_line, rgb);
			j++;
		}
		i++;
	}
}

void	validate_rgb(char **color_line, char **rgb)
{
	int	i;
	int	tmp;

	i = 0;
	check_letters(rgb, color_line);
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3] || color_line[2])
	{
		free_double_array((void **)color_line);
		free_double_array((void **)rgb);
		quit_game(21);
	}
	while (rgb[i])
	{
		rgb[i] = ft_strtrim_free(rgb[i], "\n");
		if (ft_strlen(rgb[i]) < 4)
		{
			tmp = ft_atoi(rgb[i]);
			if (tmp < 0 || tmp > 255)
				free_n_quit(color_line, rgb);
		}
		else
			free_n_quit(color_line, rgb);
		i++;
	}
}

int	retrieve_color(char **color_line)
{
	char	**rgb;
	int		color;

	rgb = NULL;
	if (ft_strchr(color_line[1], ','))
		rgb = ft_split(color_line[1], ',');
	else if (ft_strchr(color_line[1], '.'))
		rgb = ft_split(color_line[1], '.');
	validate_rgb(color_line, rgb);
	free_double_array((void **)color_line);
	color = (ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | \
	ft_atoi(rgb[2]));
	free_double_array((void **)rgb);
	return (color);
}

void	set_colors(void)
{
	char	**color_line;
	t_vars	*vars;

	vars = get_data();
	color_line = ft_split(vars->mapdata[4], ' ');
	vars->img->color[0] = retrieve_color(color_line);
	color_line = ft_split(vars->mapdata[5], ' ');
	vars->img->color[1] = retrieve_color(color_line);
}
