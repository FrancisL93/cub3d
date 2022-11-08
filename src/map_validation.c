/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:48:10 by flahoud           #+#    #+#             */
/*   Updated: 2022/08/16 14:51:27 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	validate_cub(char *map)
{
	char	*cub;
	int		i;
	int		j;

	cub = "buc.";
	i = 0;
	j = -1;
	while (map[i])
		i++;
	while (++j < 4)
	{
		if (i < 4 || (map[i - j - 1] != cub[j]))
		{
			printf("Error: Map not a .cub file...\n");
			return (1);
		}
	}
	return (0);
}

int	check_file(char *map)
{
	int	fd;

	fd = open(map, O_DIRECTORY);
	if (fd > -1)
	{
		printf("Error: Map is a directory...\n");
		close(fd);
		return (-1);
	}
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Couldn't read map...\n");
		return (-1);
	}
	if (validate_cub(map))
	{
		close(fd);
		return (-1);
	}
	return (fd);
}

int	read_map(t_vars *vars, char *mapfile, int fd)
{
	int		size;
	int		fd2;
	int		i;
	char	buf[1];

	i = 0;
	size = 0;
	while (read(fd, &buf, 1))
		if (buf[0] == '\n')
			size++;
	vars->height = size;
	if (size < 2)
		return (1);
	close(fd);
	fd2 = open(mapfile, O_RDONLY);
	vars->mapdata = malloc(sizeof(char **) * (size + 1));
	if (!vars->mapdata)
		return (1);
	vars->mapdata[i] = get_next_line(fd2);
	while (vars->mapdata[i++])
		vars->mapdata[i] = get_next_line(fd2);
	close(fd2);
	return (0);
}

int	validate_map(t_vars *vars, char *mapfile)
{
	int	fd;
	int	i;
	int	j;

	j = -1;
	fd = check_file(mapfile);
	if (fd < 0)
		return (1);
	if (read_map(vars, mapfile, fd))
	{
		printf("Error: Map is strange...\n");
		return (1);
	}
	else
	{
		i = vars->height;
		while (vars->mapdata[i][0] != '\n')
			i--;
		vars->map = malloc(sizeof(char **) * i);
		if (!vars->map)
			return (1);
		while (++i <= vars->height)
			vars->map[++j] = vars->mapdata[i]; 
	}
	return (0);
}
