#include "../include/cub3d.h"

void	print_error(error)
{
	if (error == 0)
		printf("Error: Execute as ./cub3d map.cub...\n");

}

int	quit_game(int exit_num)
{
	t_vars	*vars;

	vars = get_data();
	print_error(exit_num);
	if (exit_num > 1)
		free(vars->full_config);
	//mlx_destroy_window(vars->mlx, vars->win);
	free(vars);
	if (exit_num > 10)
		exit(0);
	else
		exit(exit_num);
}
