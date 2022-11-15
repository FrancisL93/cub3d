#include "../inc/cub3d.h"

int	check_file(char *map)
{
	int	fd;

	if (ft_strcmp(&map[ft_strlen(map - 4)], ".cub", 4))
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

int	readMap()
{
	t_vars *vars;

	vars = get_data();
	
}

int	validate_map(t_vars *vars, char *mapfile)
{
	t_vars	*vars = get_data();
	int	fd;
	int	i;
	int	j;

	j = -1;
	fd = check_file(mapfile);
	if (fd < 0)
		return (1);
	if (readMap(mapfile, fd))
	{
		printf("Error: Map is strange...\n");
		return (1);
	}
	else
	{

	}
	return (0);
}
