/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:42:57 by mal               #+#    #+#             */
/*   Updated: 2022/12/19 12:59:26 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	background_screen(void)
{
	int		y;
	int		x;
	t_vars	*vars;

	y = 0;
	vars = get_data();
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, y, 0x000080);
			x++;
		}
		y++;
	}
	system("afplay sounds/storeopen.wav&");
}

static int	get_file_size(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("maps/start_screen", O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

static char	**fill_array(void)
{
	char	**file;
	int		size;
	int		i;
	int		fd;

	size = get_file_size();
	file = ft_calloc(sizeof(char *), size + 1);
	i = 0;
	fd = open("maps/start_screen", O_RDONLY);
	file[i] = get_next_line(fd);
	while (file[i] != NULL)
	{
		i++;
		file[i] = get_next_line(fd);
	}
	close (fd);
	return (file);
}

void	start_screen(void)
{
	t_vars	*vars;
	int		height;
	int		i;
	char	**start_file;

	vars = get_data();
	vars->game_start = false;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH,
			WIN_HEIGHT, GAME_NAME);
	height = (WIN_WIDTH / 2) - 560;
	build_imgs();
	init_data();
	background_screen();
	start_file = fill_array();
	i = 0;
	while (start_file[i])
	{
		mlx_string_put(vars->mlx, vars->win, WIN_HEIGHT / 2 - 5,
			height, 0xff10f0, start_file[i]);
		i++;
		height += 12;
	}
	free_double_array((void **)start_file);
	mlx_hook(vars->win, 2, 0, key_hook_bonus, vars);
}
