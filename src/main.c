#include "../include/cub3d.h"

//LEAKS Faire une fonction pour quand sort avec la croix (x rouge)
//TODO Modifier les erreurs pour : "Error:\nRaison de l'erreur\n"
//TODO S'assurer qu'un zero ne peut pas voir un espace vide en diagonale entre 2 '1'
//TODO Réparer la start position

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
	t_vars	*vars;

	vars = get_data();
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
	spaces_handling();
	launch_game();
	quit_game(10);
}
