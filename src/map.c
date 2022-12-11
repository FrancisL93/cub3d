/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:46 by malord            #+#    #+#             */
/*   Updated: 2022/12/11 16:20:32 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	is_valid_char(char c, char *str)
{
	t_vars	*vars;

	vars = get_data();
	if (!ft_strchr("0 1NSEW", c))
	{
		free(str);
		ft_putstr_fd("Error\nInvalid character in map\n", STDERR_FILENO);
		quit_game(11);
	}
	if (ft_strchr("NSEW", c))
	{
		if (vars->one_start == 0)
			vars->one_start = 1;
		else
		{
			free(str);
			ft_putstr_fd("Error\nMore than one start position\n", STDERR_FILENO);
			quit_game(12);
		}
	}
}

int	find_map(char **fullconfig)
{
	int		i;
	int		j;
	int		wall;
	char	*tmp;

	i = -1;
	while (fullconfig[++i])
	{
		tmp = ft_strtrim(fullconfig[i], "\n");
		j = 0;
		wall = 0;
		while (tmp[j] == '0' || tmp[j] == '1' || tmp[j] == ' ')
		{
			if (tmp[j] && tmp[j] == '1')
				wall = 1;
			if (tmp[j++ + 1] == '\0' && wall == 1)
			{
				free(tmp);
				return (i);
			}
		}
		free(tmp);
	}
	return (-1);
}

int	is_map(void)
{
	t_vars	*vars;
	int		i;
	int		j;
	int		map_start;
	char	*tmp;

	vars = get_data();
	map_start = find_map(vars->full_config);
	if (map_start < 5)
		return (-1);
	i = map_start - 1;
	while (vars->full_config[++i])
	{
		tmp = ft_strtrim(vars->full_config[i], "\n");
		j = 0;
		while (tmp[j] != '\0')
			is_valid_char(tmp[j++], tmp);
		free(tmp);
	}
	if (vars->one_start == 0)
	{
		ft_putstr_fd("Error\nNo start position in map\n", STDERR_FILENO);
		quit_game(13);
	}
	return (map_start);
}

void	get_map(void)
{
	int		i;
	int		index;
	t_vars	*vars;

	vars = get_data();
	index = is_map();
	if (index == -1)
	{
		ft_putstr_fd("Error\nBad map file content\n", STDERR_FILENO);
		quit_game(10);
	}
	i = index;
	while (vars->full_config[i])
		i++;
	vars->map = ft_calloc(sizeof(char *), i - index + 1);
	if (!vars->map)
		quit_game(14);
	i = 0;
	while (vars->full_config[index])
		vars->map[i++] = vars->full_config[index++];
	vars->map[i] = NULL;
}

void	validate_map(char *mapfile)
{
	int		fd;
	t_vars	*vars;

	vars = get_data();
	fd = ft_check_file_ext(mapfile, ".cub");
	if (fd < 0)
		quit_game(2);
	vars->full_config = ft_calloc(sizeof(char *), ft_file_size(fd) + 1);
	if (!vars->full_config)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Not enough memory for map allocation\n", STDERR_FILENO);
		quit_game(5);
	}
	fd = open(mapfile, O_RDONLY);
	ft_store_file(vars->full_config, fd);
	if (vars->full_config[0] == NULL)
	{
		ft_putstr_fd("Error\nMapfile is empty\n", STDERR_FILENO);
		free(vars->full_config);
		quit_game(6);
	}
}
