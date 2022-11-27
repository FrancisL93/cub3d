#include "../include/cub3d.h"

void	destroy_images(int num)
{
	t_vars	*vars;

	vars = get_data();
	if (num > 0)
		mlx_destroy_image(vars->mlx, vars->img->text[0]);
	if (num > 1)
		mlx_destroy_image(vars->mlx, vars->img->text[1]);
	if (num > 2)
		mlx_destroy_image(vars->mlx, vars->img->text[2]);
	if (num > 3)
		mlx_destroy_image(vars->mlx, vars->img->text[3]);
}

void	*get_text(void *mlx, char *texture, int num)
{
	t_vars	*vars;
	void	*img;
	char	**texture_split;
	char	*tmp;

	vars = get_data();
	texture_split = ft_split(texture, ' ');
	tmp = ft_strtrim(texture_split[1], "\n");
	img = mlx_xpm_file_to_image(mlx, tmp, &vars->img->text_width[num], \
		&vars->img->text_height[num]);
	free(tmp);
	free_double_array((void **) texture_split);
	if (!img)
	{
		ft_putstr_fd("Error\nXPM to image failure on textures\n", STDERR_FILENO);
		destroy_images(num);
		quit_game(32);
	}
	return (img);
}

void	build_imgs(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->img = malloc(sizeof(*vars->img));
	if (!vars->img)
		quit_game(31);
	vars->img->text[0] = get_text(vars->mlx, vars->mapdata[0], 0);
	vars->img->text[1] = get_text(vars->mlx, vars->mapdata[1], 1);
	vars->img->text[2] = get_text(vars->mlx, vars->mapdata[2], 2);
	vars->img->text[3] = get_text(vars->mlx, vars->mapdata[3], 3);
	return ;
}
