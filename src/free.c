#include "../inc/cub3d.h"

void	free_map(t_vars *vars)
{
	int	x;

	x = 0;
	while (vars->map[x])
		free(vars->map[x++]);
}

int	quit_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
