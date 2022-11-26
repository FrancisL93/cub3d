#include "../include/cub3d.h"

//TODO Verifier tous les free en plus d'ordonner les erreurs pour eviter les double free
//0-9 wrong execution & validate_map
//10-19 get_map errors
//20-29 format_map
//30-39 build_imgs & init_data
//40+ in game errors
//50+ in game clean exit
int	quit_game(int exit_num)
{
	t_vars	*vars;

	vars = get_data();
	if (exit_num >= 40)
		mlx_destroy_window(vars->mlx, vars->win);
	//30-39
	if (exit_num > 33)
		free(vars->game);
	if (exit_num > 33)
		destroy_images(5);
	if (exit_num > 31)
		free(vars->img);
	//20-29
	//10-19
	if (exit_num > 14)
		free_double_array((void **) vars->map);
	if (exit_num >= 10)
		free_double_array((void **) vars->full_config);
	// 0 - 9
	free(vars);
	if (exit_num >= 50)
		exit(0);
	exit(exit_num);
}
