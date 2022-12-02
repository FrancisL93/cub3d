#include "../include/cub3d.h"

double	set_direction(char dir)
{
	if (dir == 'N')
		return (270);
	else if (dir == 'E')
		return (0);
	else if (dir == 'S')
		return (90);
	else if (dir == 'W')
		return (180);
	return (0);
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
				vars->game->posx = j + 0.5;
				vars->game->posy = i + 0.5;
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
