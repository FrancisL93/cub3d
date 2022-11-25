#include "../include/cub3d.h"

//? Pas trouvé de edge cases qui font failer ce parsing. Qui dit mieux ? 

int	check_file(char *map)
{
	int	fd;
	int	len;

	len = ft_strlen(map);
	if (len < 5 || ft_strncmp(&map[len - 4], ".cub", 4))
	{
		ft_putstr_fd("Error\nMapfile is not a .cub\n", STDERR_FILENO);
		quit_game(2);
	}
	fd = open(map, O_DIRECTORY);
	if (fd > -1)
	{
		ft_putstr_fd("Error\nMapfile is a directory\n", STDERR_FILENO);
		close(fd);
		quit_game(3);
	}
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCouldn't read mapfile\n", STDERR_FILENO);
		quit_game(4);
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
	{
		ft_putstr_fd("Error\nMapfile is empty\n", STDERR_FILENO);
		free(vars->full_config);
		quit_game(6);
	}
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
	if (!vars->full_config)
	{
		ft_putstr_fd("Error\nNot enough memory for map allocation\n", STDERR_FILENO);
		quit_game(5);
	}
	fd = open(mapfile, O_RDONLY);
	read_map_file(fd);
}
