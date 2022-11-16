#include "../include/cub3d.h"

void	free_map()
{
	t_vars	*vars;

	vars = get_data();
	int	x;

	x = 0;
	while (vars->map[x])
		free(vars->map[x++]);
	free(vars->map);
}

int	quit_game()
{
	t_vars	*vars;

	vars = get_data();
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
