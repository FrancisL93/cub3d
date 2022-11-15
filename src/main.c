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
	//if (validate_map(argv[1]) == false)
		//return (1);
	while (vars->full_config[i])
	{
		printf("full_config[%d] = %s", i, vars->full_config[i]);
		i++;
	}
	//build_imgs(&vars);
	//init_data();
	//launch_game(&vars);
	return (0);
}

//TODO Une texture par direction (NORTH, SOUTH, EAST, WEST)
void	build_imgs(t_vars *vars)
{
	vars->img = malloc(sizeof(*vars->img));
	vars->imgsize = 64;
	vars->img->floor = mlx_xpm_file_to_image(vars->mlx, "./img/tile.xpm", \
	&vars->imgsize, &vars->imgsize);
	if (!vars->img->floor) 
	{
		printf("Error\nCouldn't open floor asset\n");
		exit(1);
	}
}
