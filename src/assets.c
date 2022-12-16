/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:08:53 by malord            #+#    #+#             */
/*   Updated: 2022/12/16 13:55:33 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	destroy_images(void)
{
	int		i;
	t_vars	*vars;

	i = 0;
	vars = get_data();
	while (i < 8)
	{
		if (vars->img->text[i] && i < 4)
			mlx_destroy_image(vars->mlx, vars->img->text[i]);
		else if (vars->img->text[i] && vars->bonus)
			mlx_destroy_image(vars->mlx, vars->img->text[i]);
		i++;
	}
}

static void	*get_image(t_vars *vars, char *file, int num)
{
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, file, &vars->img->text_width[num], \
	&vars->img->text_height[num]);
	return (img);
}

static void	*get_text(char *texture, int num)
{
	t_vars	*vars;
	void	*img;
	char	**texture_split;
	char	*tmp;

	vars = get_data();
	texture_split = ft_split(texture, ' ');
	tmp = ft_strtrim(texture_split[1], "\n");
	img = get_image(vars, tmp, num);
	free(tmp);
	if ((texture_split[2] && ft_strncmp(texture_split[2], "\n", 1)) || !img)
	{
		free_double_array((void **) texture_split);
		quit_game(18);
	}
	free_double_array((void **) texture_split);
	return (img);
}

static void	build_bonus_assets(void)
{
	int		i;
	t_vars	*vars;

	i = 4;
	vars = get_data();
	vars->img->text[CHARACT] = get_image(vars, CHARACTER_ASSET, CHARACT);
	vars->img->text[FLOOR] = get_image(vars, FLOOR_TEXT, FLOOR);
	vars->img->text[CEILING] = get_image(vars, CEIL_TEXT, CEILING);
	vars->img->text[DOOR] = get_image(vars, DOOR_TEXT, DOOR);
	while (i < 8)
	{
		if (!vars->img->text[i])
			quit_game(19);
		i++;
	}
}

void	build_imgs(void)
{
	int		i;
	t_vars	*vars;

	i = 0;
	vars = get_data();
	vars->img = malloc(sizeof(*vars->img));
	if (!vars->img)
		quit_game(17);
	while (i < 8)
		vars->img->text[i++] = NULL;
	i = 0;
	while (i < 8)
	{
		if (i < 4)
			vars->img->text[i] = get_text(vars->mapdata[i], i);
		i++;
	}
	if (vars->bonus)
		build_bonus_assets();
	return ;
}
