#include "../include/cub3d.h"

//TODO Une texture par direction (NORTH, SOUTH, EAST, WEST)
void	build_imgs()
{
	t_vars	*vars;

	vars = get_data();
	vars->img = malloc(sizeof(*vars->img));
	if (!vars->img)
		quit_game(6);
	return ;
}
