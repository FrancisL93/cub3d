/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:27 by malord            #+#    #+#             */
/*   Updated: 2022/12/05 10:09:28 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//! Probably useless - Still error checking to do
/*void	check_first_line(int column)
{
	t_vars	*vars;

	vars = get_data();
	while (vars->map[0][column] && column < (int)ft_strlen(vars->map[0]) - 1)
	{
		if (vars->map[0][column] != '1')
		{
			ft_putstr_fd("Error\nMap is not circled by walls.", STDERR_FILENO);
			quit_game(13);
		}
		column++;
	}
}*/

void	check_ones(int line, int column)
{
	t_vars	*vars;

	vars = get_data();
	if (vars->map[line][0] != '1'
		|| vars->map[line][ft_strlen(vars->map[line]) - 2] != '1')
	{
		ft_putstr_fd("Error\nMap is not circled by walls.\n", STDERR_FILENO);
		quit_game(13);
	}
	if (!vars->map[line + 1])
	{
		column = 0;
		while (vars->map[line][column] && column
			< (int)ft_strlen(vars->map[line]))
		{
			if (vars->map[line][column] != '1')
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				ft_putstr_fd("Map is not circled by walls.\n", STDERR_FILENO);
				quit_game(13);
			}
			column++;
		}
	}
}

void	check_walls(void)
{
	t_vars	*vars;
	int		line;
	int		column;

	vars = get_data();
	line = 0;
	column = 0;
	while (vars->map[line])
	{
		check_ones(line, column);
		line++;
	}
}

void	check_spaces(int line, int column)
{
	t_vars	*vars;

	vars = get_data();
	if ((column >= 0 && vars->map[line][column + 1]
		&& vars->map[line][column + 1] == '0')
		|| (column >= 0 && vars->map[line][column - 1]
		&& vars->map[line][column - 1] == '0')
			|| (line >= 0 && vars->map[line + 1]
			&& vars->map[line + 1][column] == '0')
				|| (line > 0 && vars->map[line - 1][column]
				&& vars->map[line - 1][column] == '0'))
	{
		ft_putstr_fd("Error\nInvalid space in map\n", STDERR_FILENO);
		quit_game(20);
	}
	else
		vars->map[line][column] = '1';
}

void	check_zeros(int line, int column)
{
	t_vars	*vars;

	vars = get_data();
	if (line == 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Map is not properly closed everywhere\n", STDERR_FILENO);
		quit_game(21);
	}
	if (!vars->map[line + 1][column] || !(vars->map[line - 1][column])
		|| vars->map[line - 1][column] == '\n'
		|| vars->map[line + 1][column] == '\n')
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Map is not properly closed everywhere\n", STDERR_FILENO);
		quit_game(21);
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
