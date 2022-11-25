#include "../include/cub3d.h"

void	print_error(int error)
{
	if (error == 0)
		printf("Error\nExecute as ./cub3d map.cub\n");
	else if (error == 2)
		printf("Error\nFile is empty.\n");
	else if (error == 3)
		printf("Error\nNo map in file\n");
	else if (error == 4)
		printf("Error\nNot enough memory for map allocation\n");
	else if (error == 5)
		printf("Error\nBad map configuration settings\n");
	else if (error == 6)
		printf("Error\nNot enough memory for assets\n");
	else if (error == 7)
		printf("Error\nNot enough memory for game data\n");
	else if (error == 8)
		printf("Error\nMlx couldn't create new image\n");
	else if (error == 9)
		printf("Error\nMlx couldn't retrieve image address\n");
	else if (error == 10)
		printf("Error\nInvalid characters in map\n");
	else if (error == 11)
		printf("Error\nMore than one start position\n");
	else if (error == 13)
		printf("Error\nMap do not respect rules of a valid map.\n");
}
//TODO Verifier tous les free en plus d'ordonner les erreurs pour eviter les double free
//0-9 wrong execution & validate_map
//10-19 get_map errors
//20-29 spaces_handling
int	quit_game(int exit_num)
{
	t_vars	*vars;

	vars = get_data();
	print_error(exit_num);
	if (exit_num == 8 || exit_num == 9)
	{
		free(vars->game);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	if (exit_num >= 10)
		exit(0);
	if (exit_num > 6)
		free(vars->img);
	if (exit_num > 3)
		free(vars->map);
	if (exit_num > 2)
		free_double_array((void **)vars->full_config);
	if (exit_num == 2)
		free(vars->full_config);
	//20-29

	//10-19
	if (exit_num >= 10)
		free_double_array((void **) vars->full_config);
	// 0 - 9
	free(vars);

	//else
		exit(exit_num);
}
