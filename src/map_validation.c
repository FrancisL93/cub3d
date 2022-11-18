#include "../include/cub3d.h"

//? Pas trouvé de edge cases qui font failer ce parsing. Qui dit mieux ? 
bool	gap_til_map(t_vars *vars, int i)
{
	int	j;

	while (i < vars->map_start)
	{
		j = 0;
		while (j < (int)ft_strlen(vars->full_config[i])
			&& ft_strchr(" \n", vars->full_config[i][j]))
			j++;
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
		quit_game(1);
	}
	fd = open(map, O_DIRECTORY);
	if (fd > -1)
	{
		printf("Error: Map is a directory...\n");
		close(fd);
		quit_game(1);
	}
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Couldn't read map...\n");
		quit_game(1);
	}
	return (fd);
}

void	read_map_file(int fd)
{
	int		i;
	t_vars	*vars;

	i = 0;
	vars = get_data();
	vars->full_config[i] = get_next_line(fd);
	while (vars->full_config[i++])
		vars->full_config[i] = get_next_line(fd);
	close(fd);
	if (i == 1)
		quit_game(2);
}

//TODO Check if init_struct a des malloc pour ajouter free en cas d'erreur si applicable

void	validate_map(char *mapfile)
{
	int		fd;
	int		size;
	char	*temp;
	t_vars	*vars;

	vars = get_data();
	size = 0;
	fd = check_file(mapfile);
	temp = get_next_line(fd);
	while (temp)
	{
		size++;
		free(temp);
		temp = get_next_line(fd);
	}
	close (fd);
	vars->full_config = ft_calloc(sizeof(char *), size + 1);
	if(!vars->full_config)
		quit_game(1);
	fd = open(mapfile, O_RDONLY);
	read_map_file(fd);
}
