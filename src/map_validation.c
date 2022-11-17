#include "../include/cub3d.h"
//REFACTOR remove functions for Norminette

bool	get_mapdata(void)
//REFACTOR for norminette
{
	t_vars	*vars;
	int		i;
	int		index;
	char	*elem_name;

	vars = get_data();
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
			return (true);
		elem_name = get_element_name(&i);
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
