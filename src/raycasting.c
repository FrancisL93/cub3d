#include "../include/cub3d.h"

void	ray(double angle, int i)
{
	t_vars	*vars;
	int		wall;
	double	distance;
	int		wall_height;

	wall = 0;
	vars = get_data();
	vars->game->ray_x = vars->game->posx;
	vars->game->ray_y = vars->game->posy;
	vars->game->raycos = cos((angle * (PI / 180)) / vars->ray_precision);
	vars->game->raysin = sin((angle * (PI / 180)) / vars->ray_precision);
	while (!wall)
	{
		vars->game->ray_x += vars->game->raycos;
		vars->game->ray_y += vars->game->raysin;
		wall = vars->map[(int) floor(vars->game->ray_y)][(int) floor(vars->game->ray_x)];
	}
	distance = sqrt(pow(vars->game->posx - vars->game->ray_x, 2) + \
	pow(vars->game->posy - vars->game->ray_y, 2));
	wall_height = floor((vars->win_height / 2) / distance);
	draw_ray(i, wall_height);
}

void	ray_loop(void)
{
	int		i;
	float	angle;
	t_vars	*vars;

	i = 0;
	vars = get_data();
	angle = vars->game->dirx - (vars->focal_length / 2);
	while (i < vars->win_width)
	{
		if (angle < 0)
			ray(360 + angle, i);
		else
			ray(angle, i);
		angle += vars->increment_angle;
		i++;
	}
}

void	raycasting(void)
{
	//t_vars	*vars;

	//vars = get_data();
	ray_loop();
}
