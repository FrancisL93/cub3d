#include "../include/cub3d.h"

void	set_movement(int keycode)
{
	double	x;
	double	y;
	t_vars	*vars;


	vars = get_data();
	x = vars->game->posx;
	y = vars->game->posy;
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
		vars->game->posx += cos((vars->game->dirx - 90) * (PI / 180)) / vars->game->movement;
		vars->game->posy += sin((vars->game->dirx - 90) * (PI / 180)) / vars->game->movement;
	}
	else if (keycode == RIGHT)
	{	
		vars->game->posx += cos((vars->game->dirx + 90)* (PI / 180)) / vars->game->movement;
		vars->game->posy += sin((vars->game->dirx + 90)* (PI / 180)) / vars->game->movement;
	}
	if (vars->map[(int) floor(vars->game->posy)][(int) floor(vars->game->posx)] == '1')
	{
		vars->game->posx = x;
		vars->game->posy = y;
	}
}