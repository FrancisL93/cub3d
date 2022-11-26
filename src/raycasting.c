#include "../include/cub3d.h"

int	get_texture(int wall_x, int wall_y)
{
	int		x;
	int		y;
	double	ray_x;
	double	ray_y;
	t_vars	*vars;

	vars = get_data();
	ray_x = vars->game->ray_x - vars->game->raycos;
	ray_y = vars->game->ray_y - vars->game->raysin;
	x = (int) floor(ray_y);
	y = (int) floor(ray_x);
	if (x < wall_x)
		return (3);
	else if (x > wall_x)
		return (2);
	else if (y < wall_y)
		return (1);
	else if (y > wall_y)
		return (0);
	return (-1);
}

void	ray(double angle, int i)
{
	int		wall_height;
	int		texture;
	double	distance;
	t_vars	*vars;

	vars = get_data();
	vars->game->ray_x = vars->game->posx;
	vars->game->ray_y = vars->game->posy;
	vars->game->raycos = cos(angle * (PI / 180)) / vars->ray_precision;
	vars->game->raysin = sin(angle * (PI / 180)) / vars->ray_precision;
	while (vars->map[(int) floor(vars->game->ray_y)][(int) floor(vars->game->ray_x)] != '1')
	{
		vars->game->ray_x += vars->game->raycos;
		vars->game->ray_y += vars->game->raysin;
	}
	texture = get_texture((int) floor(vars->game->ray_y), (int) floor(vars->game->ray_x));
	if (texture < 0)
		quit_game(43);
	distance = sqrt(pow(vars->game->posx - vars->game->ray_x, 2) + \
	pow(vars->game->posy - vars->game->ray_y, 2));
	distance = distance * cos(angle * (PI / 180) - vars->game->dirx * (PI / 180));
	wall_height = floor((vars->win_height / 2) / distance);
	draw_ray(i, wall_height, floor((int)((int)64 * \
	(vars->game->ray_x + vars->game->ray_y)) % 64), texture);
}

void	raycasting(void)
{
	int		i;
	float	angle;
	t_vars	*vars;

	i = 0;
	vars = get_data();
	angle = vars->game->dirx - (vars->focal_length / 2);
	while (i < vars->win_width)
	{
		ray(angle, i);
		angle += vars->increment_angle;
		i++;
	}
}

