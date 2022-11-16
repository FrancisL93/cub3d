#include "../include/cub3d.h"

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

bool	read_map(int fd)
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
		exit (1);
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
	if (read_map(fd) == false)
		return (false);
	return (true);
}

int	get_element_index(char *element)
{
	char	*elem_list[6];
	int		index;
	int		i;

	index = 0;
	i = 0;
	elem_list[0] = "NO";
	elem_list[1] = "SO";
	elem_list[2] = "WE";
	elem_list[3] = "EA";
	elem_list[4] = "F";
	elem_list[5] = "C";

	while (i < 6)
	{
		if (ft_strncmp(element, elem_list[i], ft_strlen(element)) == 0)
			return (index = i);
		i++;
	}
	return (-1);
}

char	*get_element_name(void)
{
	t_vars	*vars;
	char	**temp;
	int		i;
	char	*element_name;

	vars = get_data();
	i = 0;
	while (vars->full_config[i])
	{
		temp = ft_split(vars->full_config[i], ' ');
		if (get_element_index(temp[0] == -1 || !temp[1])
		{
			free_double_array((void **)temp);
			i++;
		}
		else
		{
			element_name = ft_strdup(temp[0]);
			free_double_array((void **)temp);
			return (element_name);
		}
	}
	free_double_array((void **)temp);
	return (NULL);
}

void	get_mapdata(void)
{
	t_vars	*vars;
	int		i;
	int		j;

	vars = get_data();
	i = 0;
	if (!(vars->full_config))
		return ;
	while (i < 7)
	{
		j = 0;
		while (vars->full_config[j])
		{
			if (ft_strncmp("NO", vars->full_config[j], 2) == 0)
				vars->mapdata[i] = ft_strdup(vars->full_config[j]);
			else if (ft_strncmp("SO", vars->full_config[j], 2) == 0)
			j++;
		}
		i++;
	}
}
