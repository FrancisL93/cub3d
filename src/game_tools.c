#include "../include/cub3d.h"

void	set_movement(int keycode)
{
	t_vars	*vars;

	vars = get_data();
	if (keycode == UP)
	{
		vars->game->posx += cos(vars->game->dirx * (PI / 180)) / vars->game->movement;
		vars->game->posy += sin(vars->game->dirx * (PI / 180)) / vars->game->movement;
	}
	else if (keycode == DOWN)
	{	
		vars->game->posx -= cos(vars->game->dirx * (PI / 180)) / vars->game->movement;
		vars->game->posy -= sin(vars->game->dirx * (PI / 180)) / vars->game->movement;
	}
	else if (keycode == LEFT)
	{	
		vars->game->posx -= cos(vars->game->dirx * (PI / 180)) / vars->game->movement;
		vars->game->posy += sin(vars->game->dirx * (PI / 180)) / vars->game->movement;
	}
	else if (keycode == RIGHT)
	{	
		vars->game->posx += cos(vars->game->dirx * (PI / 180)) / vars->game->movement;
		vars->game->posy -= sin(vars->game->dirx * (PI / 180)) / vars->game->movement;
	}
}