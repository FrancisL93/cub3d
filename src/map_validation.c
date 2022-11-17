#include "../include/cub3d.h"

bool	gap_til_map(t_vars *vars, int i)
{
	//TODO Autres tests sur fichiers config a faire
	int	j;

	while (i < vars->map_start)
	{
		j = 0;
		while (j < (int)ft_strlen(vars->full_config[i])
			&& ft_strchr(" \n", vars->full_config[i][j]))
		{
			printf("%d\n", vars->full_config[i][j]);
			j++;
		}
		if (vars->full_config[i][j])
			return (false);
		i++;
	}
	return (true);
}

bool	get_mapdata(void)
{
	t_vars	*vars;
	int		i;
	int		index;
	char	*elem_name;

	vars = get_data();
	vars->map_start = find_map(vars->full_config);
	i = 0;
	index = -1;
	elem_name = get_element_name(&i);
	while (elem_name != NULL)
	{
		index = get_element_index(elem_name);
		fill_mapdata(vars, index, i);
		free(elem_name);
		i++;
		if (check_full_config(vars) == true)
			return (gap_til_map(vars, i));
		elem_name = get_element_name(&i);
		if (elem_name == NULL)
			break ;
	}
	free(elem_name);
	return (false);
}

int	check_file(char *map)
{
	int	fd;

	if (ft_strncmp(&map[ft_strlen(map) - 4], ".cub", 4))
	{
		printf("Error: Map not a .cub file...\n");
		exit (1);
	}
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
	return (fd);
}

bool	read_map_file(int fd)
{
	t_vars	*vars;
	int		i;

	vars = get_data();
	i = 0;
	vars->full_config[i] = get_next_line(fd);
	if (!vars->full_config)
	{
		free_double_array((void **)vars->full_config);
		close (fd);
		printf("Error: File is empty\n");
		return (false);
	}
	while (vars->full_config[i])
	{
		i++;
		vars->full_config[i] = get_next_line(fd);
	}
	close(fd);
	return (true);
}

//TODO Check if init_struct a des malloc pour ajouter free en cas d'erreur si applicable

bool	validate_map(char *mapfile)
{
	t_vars	*vars;
	int		fd;
	int		size;
	char	*temp;

	vars = get_data();
	size = 0;
	fd = check_file(mapfile);
	if (fd < 0)
		return (false);
	temp = get_next_line(fd);
	while (temp)
	{
		size++;
		free(temp);
		temp = get_next_line(fd);
	}
	close (fd);
	vars->full_config = ft_calloc(sizeof(char *), size + 1);
	fd = open(mapfile, O_RDONLY);
	if (read_map_file(fd) == false)
		return (false);
	return (true);
}
