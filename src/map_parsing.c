#include "../include/cub3d.h"

//TODO Verifier les contours 
//TODO Remplacer les espaces par des 1

void	check_walls(void)
{
	t_vars	*vars;
	int		i;
	int		j;

	vars = get_data();
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '0' && vars->map[i][j + 1] == ' ')
				quit_game(13);
		}
	}
}
