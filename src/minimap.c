#include "../include/cub3d.h"

void test(void)
{
	t_vars		*vars;
	int			i;
	int			j;
	char		**minimap_color;
	int			color;

	i = 20;
	j = 20;
	vars = get_data();
	minimap_color = ft_split(ft_strdup("M 255,255,255"), ' ');
	color = retrieve_color(minimap_color);
	while (j < (vars->win_height / 7))
	{
		while (i < vars->win_height / 4)
		{
			if ()
		}
			my_mlx_pixel_put(vars->img, i++, j, color);
		i = 20;
		j++;
	}
}
