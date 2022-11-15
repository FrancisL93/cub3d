#include "../inc/cub3d.h"

//TODO Une texture par direction (NORTH, SOUTH, EAST, WEST)
void	build_imgs()
{
	t_vars	*vars;
	int		width;
	int		height;

	vars = get_data();
	vars->img = malloc(sizeof(*vars->img));
	vars->img->floor = mlx_xpm_file_to_image(vars->mlx, "./img/floor.xpm", \
	&width, &height);
	if (!vars->img->floor) 
	{
		printf("Error\nCouldn't open floor asset\n");
		exit(1);
	}
}
