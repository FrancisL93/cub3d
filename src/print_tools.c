#include "../include/cub3d.h"

void	set_colors(void)
{
	char	**color_line;
	char	**rgb;
	t_vars	*vars;

	vars = get_data();
	color_line = ft_split(vars->mapdata[4], ' ');
	rgb = NULL;
	if (ft_strchr(color_line[1], ','))
		rgb = ft_split(color_line[1], ',');
	else if (ft_strchr(color_line[1], '.'))
		rgb = ft_split(color_line[1], '.');
	vars->img->floor_color = ft_atoi(rgb[0]) << 24 | ft_atoi(rgb[1]) << 16 | \
	ft_atoi(rgb[2]) << 8;
	printf("%d", vars->img->floor_color);
	free_double_array((void **)color_line);
	free_double_array((void **)rgb);
}
