#include "../include/cub3d.h"

int	main(int argc, char **argv)
{	
	t_vars	*vars;

	vars = get_data();
	int i = 0;
	if (argc != 2)
		quit_game(0);
	validate_map(argv[1]);
	get_mapdata();
	if (get_map() == false || get_mapdata() == false)
	{
		printf("Error fucker\n");
		return (1);
	}
	i = 0;
	while (i < 6)
	{
		printf("mapdata[i] = %s", vars->mapdata[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (vars->map[i])
	{
		printf("map[i] = %s", vars->map[i]);
		i++;
	}
	//vars->mlx = mlx_init();
	//build_imgs();
	//init_data();
	//launch_game();
	return (0);
}
