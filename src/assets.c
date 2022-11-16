#include "../include/cub3d.h"

//TODO Une texture par direction (NORTH, SOUTH, EAST, WEST)
void	set_asset_color(void *asset, char *element)
{
	
}

void	set_asset_path(void *asset, char *element)
{
	int		width;
	int		height;
	char	*split_element;
	t_vars	*vars;

	vars = get_data();
	split_element = ft_split(element, ' ');
	if (split_element[1])
		asset = mlx_xpm_file_to_image(vars->mlx, split_element[1], &width, &height);
	else
		asset = NULL;
	free_double_array((void **)split_element);
}

void	build_imgs()
{
	t_vars	*vars;
	int		width;
	int		height;

	vars = get_data();
	vars->img = malloc(sizeof(*vars->img));
	set_asset_path(vars->img->north, vars->mapdata[0]);
	set_asset_path(vars->img->south, vars->mapdata[1]);
	set_asset_path(vars->img->west, vars->mapdata[2]);
	set_asset_path(vars->img->east, vars->mapdata[3]);
	set_asset_path(vars->img->floor, vars->mapdata[4]);
	set_asset_path(vars->img->ceiling, vars->mapdata[5]);
	if (!vars->img->north || !vars->img->south || !vars->img->west
		|| !vars->img->east || !vars->img->floor || !vars->img->ceiling) 
	{
		printf("Error\nCouldn't set all assets properly...\n");
		free_double_array((void **) vars->mapdata);
		exit(1);
	}
}
