#include "../include/cub3d.h"

//LEAKS Faire une fonction pour quand sort avec la croix (x rouge)
//TODO Réparer la start position
//TODO regarder si les int de raycasting aux limites son en dehors window à cause de floor
//TODO vérifier la validité des double, est-ce que des floats serait mieux?

void	print_map_data(char **mapdata)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		printf("mapdata[i] = %s", mapdata[i]);
		i++;
	}
	printf("\n");
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("map[i] = %s", map[i]);
		i++;
	}
	printf("\n");
}

t_vars	*get_data(void)
{
	static t_vars	*data = NULL;

	if (data == NULL)
		data = (t_vars *)ft_calloc(sizeof(t_vars), 1);
	return (data);
}

int	main(int argc, char **argv)
{	
	//t_vars	*vars;

	//vars = get_data();
	if (argc != 2)
	{
		ft_putstr_fd("Error\nExecute as ./cub3d map.cub\n", STDERR_FILENO);
		quit_game(1);
	}
	validate_map(argv[1]);
	get_map();
	// print_map(vars->map);
	get_mapdata();
	// print_map_data(vars->mapdata);
	format_map();
	launch_game();
}
