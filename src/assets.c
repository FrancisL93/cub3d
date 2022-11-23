#include "../include/cub3d.h"

//TODO Une texture par direction (NORTH, SOUTH, EAST, WEST)
//TODO Mettre le bon exit code
//TODO Faire sure dans le parsing data que texture[1] exist
void	*get_text(void	*mlx, char *texture)
{
	int		img_size;
	void	*img;
	char	**texture_split;
	char	*tmp;

	img_size = 64;
	texture_split = ft_split(texture, ' ');
	tmp = ft_strtrim(texture_split[1], "\n");
	img = mlx_xpm_file_to_image(mlx, tmp, &img_size, &img_size);
	free(tmp);
	free(texture_split);
	if (!img)
		quit_game(7);
	return (img);
}

void	build_imgs(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->img = malloc(sizeof(*vars->img));
	if (!vars->img)
		quit_game(6);
	vars->img->north_text = get_text(vars->mlx, vars->mapdata[0]);
	vars->img->south_text = get_text(vars->mlx, vars->mapdata[1]);
	vars->img->west_text = get_text(vars->mlx, vars->mapdata[2]);
	vars->img->east_text = get_text(vars->mlx, vars->mapdata[3]);
	return ;
}
