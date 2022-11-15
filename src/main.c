#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{	
	t_vars	vars;

	if (argc != 2)
	{
		printf("Error: Execute as ./cub3d map.cub...\n");
		return (1);
	}
	if (validate_map(&vars, argv[1]) == false)
		return (1);
	build_imgs(&vars);
	init_data(&vars);
	launch_game(&vars);
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

void	init_data(t_vars *vars)
{
	vars->x = 0;
	vars->y = 0;
}