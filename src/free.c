#include "../include/cub3d.h"

void	print_error(int error)
{
	if (error == 0)
		printf("Error: Execute as ./cub3d map.cub\n");
	else if (error == 2)
		printf("Error: File is empt.\n");
	else if (error == 3)
		printf("Error: No map in file\n");
	else if (error == 4)
		printf("Error: Not enough memory for map allocation\n");
	else if (error == 5)
		printf("Error: Bad map configuration settings\n");
	else if (error == 6)
		printf("Error: Not enough memory for assets\n");
	else if (error == 7)
		printf("Error: Not enough memory for game data\n");
	else if (error == 8)
		printf("Error: Mlx couldn't create new image\n");
	else if (error == 9)
		printf("Error: Mlx couldn't retrieve image address\n");
}

int	quit_game(int exit_num)
{
	t_vars	*vars;

	vars = get_data();
	print_error(exit_num);
	if (exit_num > 8)
	{
		free(vars->game);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	if (exit_num > 6)
		free(vars->img);
	if (exit_num > 3)
		free(vars->map);
	if (exit_num > 2)
		free_double_array((void **)vars->full_config);
	if (exit_num == 2)
		free_double_array((void **)vars->full_config);
	free(vars);
	if (exit_num >= 10)
		exit(0);
	else
		exit(exit_num);
}
