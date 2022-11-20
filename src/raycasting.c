#include "../include/cub3d.h"

void	ray_angle(t_vars *vars, int column)
{
	float	x;
	float	angle;
	float	ray;

	x = (float) column / (vars->resolution - 0.5);
	angle = athan2(x, vars->game->focal_length);
	ray = 
}