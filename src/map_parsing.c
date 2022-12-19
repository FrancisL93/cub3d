/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:27 by malord            #+#    #+#             */
/*   Updated: 2022/12/19 11:17:42 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	check_ones(int line, int column)
{
	t_vars	*vars;

	vars = get_data();
	if (vars->map[line][0] != '1'
		|| vars->map[line][ft_strlen(vars->map[line]) - 2] != '1')
		quit_game(14);
	if (!vars->map[line + 1])
	{
		column = 0;
		while (vars->map[line][column] && column
			< (int)ft_strlen(vars->map[line]))
		{
			if (vars->map[line][column] != '1')
				quit_game(15);
			column++;
		}
	}
}

static void	check_walls(void)
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

static void	check_spaces(int line, int column)
{
	t_vars	*vars;

	vars = get_data();
	if (column >= 0 && vars->map[line][column + 1]
		&& vars->map[line][column + 1] == '0')
		quit_game(11);
	if (column >= 0 && vars->map[line][column - 1]
		&& vars->map[line][column - 1] == '0')
		quit_game(11);
	if (line >= 0 && vars->map[line + 1]
		&& vars->map[line + 1][column] == '0')
		quit_game(11);
	if (line > 0 && vars->map[line - 1][column]
		&& vars->map[line - 1][column] == '0')
		quit_game(11);
	vars->map[line][column] = '1';
}

static void	check_zeros(int line, int column)
{
	t_vars	*vars;

	vars = get_data();
	if (line == 0)
		quit_game(12);
	if (!vars->map[line + 1][column] || !vars->map[line - 1][column])
		quit_game(13);
	if ((int) ft_strlen(vars->map[line - 1]) <= column + 1)
		quit_game(13);
	if ((int) ft_strlen(vars->map[line + 1]) < column)
		quit_game(13);
	if (!vars->map[line + 1][column] || vars->map[line + 1][column] == '\n')
		quit_game(13);
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
			if ((vars->map[i][j] == '0' || ft_strchr("NSEWD", vars->map[i][j]))
				&& vars->map[i + 1])
				check_zeros(i, j);
			j++;
		}
		i++;
	}
	check_walls();
	map_square();
}
