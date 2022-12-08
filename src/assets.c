/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:08:53 by malord            #+#    #+#             */
/*   Updated: 2022/12/08 16:02:21 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (num > 4)
		mlx_destroy_image(vars->mlx, vars->img->character);
	if (num > 5)
		mlx_destroy_image(vars->mlx, vars->img->floor);
	if (num > 6)
		mlx_destroy_image(vars->mlx, vars->img->ceiling);
}

void	*get_text(char *texture, int num)
{
	t_vars	*vars;
	void	*img;
	char	**texture_split;
	char	*tmp;

	vars = get_data();
	texture_split = ft_split(texture, ' ');
	tmp = ft_strtrim(texture_split[1], "\n");
	img = mlx_xpm_file_to_image(vars->mlx, tmp, &vars->img->text_width[num],
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

void	build_bonus_assets(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->img->floor = mlx_xpm_file_to_image(vars->mlx, "./img/floor1.xpm", \
		&vars->img->floor_size[0], &vars->img->floor_size[1]);
	if (!vars->img->floor)
	{
		ft_putstr_fd("Error\nXPM to image failure on textures\n", STDERR_FILENO);
		destroy_images(5);
		quit_game(33);
	}
	vars->img->ceiling = mlx_xpm_file_to_image(vars->mlx, "./img/nightsky.xpm", \
		&vars->img->ceiling_size[0], &vars->img->ceiling_size[1]);
	if (!vars->img->ceiling)
	{
		ft_putstr_fd("Error\nXPM to image failure on textures\n", STDERR_FILENO);
		destroy_images(6);
		quit_game(33);
	}
}

void	build_imgs(void)
{
	t_vars	*vars;
	int		size[2];

	vars = get_data();
	vars->img = malloc(sizeof(*vars->img));
	if (!vars->img)
		quit_game(31);
	vars->img->text[0] = get_text(vars->mapdata[0], 0);
	vars->img->text[1] = get_text(vars->mapdata[1], 1);
	vars->img->text[2] = get_text(vars->mapdata[2], 2);
	vars->img->text[3] = get_text(vars->mapdata[3], 3);
	vars->img->character = mlx_xpm_file_to_image(vars->mlx, "./img/panier.xpm",
			&size[0], &size[1]);
	if (!vars->img->character)
	{
		destroy_images(4);
		ft_putstr_fd("Error\nXPM to image failure on textures\n", STDERR_FILENO);
		quit_game(33);
	}
	if (vars->bonus)
		build_bonus_assets();
	vars->img->character_pos[0] = size[0];
	vars->img->character_pos[1] = size[1];
	return ;
}
