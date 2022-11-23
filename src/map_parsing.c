#include "../include/cub3d.h"

//TODO Verifier les contours 
//TODO Remplacer les espaces par des 1

void	spaces_handling(void)
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
			if (vars->map[i][j] == ' ')
			{
				if ((j >= 0 && vars->map[i][j + 1]
					&& vars->map[i][j + 1] == '0')
					|| (j >= 0 && vars->map[i][j - 1]
					&& vars->map[i][j - 1] == '0')
						|| (i >= 0 && vars->map[i + 1][j]
						&& vars->map[i + 1][j] == '0')
							|| (i > 0 && vars->map[i - 1][j]
							&& vars->map[i - 1][j] == '0'))
					quit_game(13);
				else
					vars->map[i][j] = '1';
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	printf("NOUVELLE MAP ------------------\n");
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			printf("%c", vars->map[i][j]);
			j++;
		}
		i++;
	}
}
