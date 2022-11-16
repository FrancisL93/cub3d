#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{	
	t_vars	*vars;

	vars = get_data();
	int i = 0;
	if (argc != 2)
	{
		printf("Error: Execute as ./cub3d map.cub...\n");
		return (1);
	}
	if (validate_map(argv[1]) == false)
		return (1);
	while (vars->full_config[i])
	{
		printf("%s", vars->full_config[i]);
		i++;
	}
	get_mapdata();
	i = 0;
	while (vars->mapdata[i])
	{
		printf("mapdata[i] = %s", vars->mapdata[i]);
		i++;
	}
	//vars->mlx = mlx_init();
	//build_imgs();
	//init_data();
	//launch_game();
	return (0);
}
