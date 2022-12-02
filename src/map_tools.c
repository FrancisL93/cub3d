#include "../include/cub3d.h"

double	set_direction(char dir)
{
	t_vars	*vars;

	vars = get_data();
	if (dir == 'N')
	{
		//printf("ICI\n");
		vars->game->dirx = 180;
	}
	else if (dir == 'E')
		vars->game->dirx = 90;
	else if (dir == 'S')
		vars->game->dirx = 0;
	else if (dir == 'W')
		vars->game->dirx = 270;
	return (vars->game->dirx);
}

void	set_up_start(void)
{
	int		i;
	int		j;
	t_vars	*vars;

	i = 1;
	vars = get_data();
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (ft_strchr("NSEW", vars->map[i][j]))
			{
				vars->game->posx = j;
				vars->game->posy = i;
				vars->game->dirx = set_direction(vars->map[i][j]);
				printf("%f\n", vars->game->dirx);
				vars->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
