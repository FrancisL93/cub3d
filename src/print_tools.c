#include "../include/cub3d.h"



void	validate_rgb(char **color_line, char **rgb)
{
	int	i;
	int	tmp;

	i = 0;
	if (color_line[2] || rgb[3])
	{
		free_double_array((void **)color_line);
		free_double_array((void **)rgb);
		ft_putstr_fd("Error\nColor settings not valid\n", STDERR_FILENO);
		quit_game(34);
	}
	while (rgb[i])
	{
		if (ft_strlen(rgb[i]) < 4)
		{
			tmp = ft_atoi(rgb[i]);
			if (tmp < 0 || tmp > 255)
			{
				free_double_array((void **)color_line);
				free_double_array((void **)rgb);
				ft_putstr_fd("Error\nColor value not valid\n", STDERR_FILENO);
				quit_game(35);
			}
		}
		i++;
	}
}

int	retrieve_color(char **color_line)
{
	char	**rgb;
	int		color;

	rgb = NULL;
	if (ft_strchr(color_line[1], ','))
		rgb = ft_split(color_line[1], ',');
	else if (ft_strchr(color_line[1], '.'))
		rgb = ft_split(color_line[1], '.');
	validate_rgb(color_line, rgb);
	free_double_array((void **)color_line);
	color = (ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | \
	ft_atoi(rgb[2]));
	free_double_array((void **)rgb);
	return (color);
}

void	set_colors(void)
{
	char	**color_line;
	t_vars	*vars;

	vars = get_data();
	color_line = ft_split(vars->mapdata[4], ' ');
	vars->img->floor_color = retrieve_color(color_line);
	color_line = ft_split(vars->mapdata[5], ' ');
	vars->img->ceiling_color = retrieve_color(color_line);
}
