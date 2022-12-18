/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal <mal@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:02 by malord            #+#    #+#             */
/*   Updated: 2022/12/17 22:04:42 by mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_error_2(int error)
{
	if (error == 14)
		ft_putstr_fd("Error\nMap is not circled by walls.\n", STDERR_FILENO);
	if (error == 15)
		ft_putstr_fd("Error\nMap is not circled by walls.\n", STDERR_FILENO);
	if (error == 16)
		ft_putstr_fd("Error\nMlx init failure\n", STDERR_FILENO);
	if (error == 17)
		ft_putstr_fd("Error\nNot enough emory for images\n", STDERR_FILENO);
	if (error == 18 || error == 19)
		ft_putstr_fd("Error\nXPM file to image failure\n", STDERR_FILENO);
	if (error == 20)
		ft_putstr_fd("Error\nNot enough memory for game\n", STDERR_FILENO);
	if (error == 21)
		ft_putstr_fd("Error\nColor settings not valid\n", STDERR_FILENO);
	if (error == 22)
		ft_putstr_fd("Error\nColor value not valid\n", STDERR_FILENO);
	if (error == 23)
		ft_putstr_fd("Error\nMlx window creation failure\n", STDERR_FILENO);
	if (error == 24)
		ft_putstr_fd("Error\nMap is too large for window size.", STDERR_FILENO);
	if (error == 25)
		ft_putstr_fd("Error\nMLX new image failure", STDERR_FILENO);
	if (error == 26)
		ft_putstr_fd("Error\nMLX image address failure", STDERR_FILENO);
}

void	print_error_1(int error)
{
	if (error == 1)
		ft_putstr_fd("Error\nExecute as ./cub3d map.cub\n", STDERR_FILENO);
	if (error == 2)
		ft_putstr_fd("Error\nExecute as ./cub3d_bonus map.cub\n", STDERR_FILENO);
	if (error == 4)
		ft_putstr_fd("Error\nMapfile is empty\n", STDERR_FILENO);
	if (error == 5)
		ft_putstr_fd("Error\nInvalid character in map\n", STDERR_FILENO);
	if (error == 6)
		ft_putstr_fd("Error\nMore than one start position\n", STDERR_FILENO);
	if (error == 7)
		ft_putstr_fd("Error\nNo start position in map\n", STDERR_FILENO);
	if (error == 8)
		ft_putstr_fd("Error\nBad map file content\n", STDERR_FILENO);
	if (error == 9)
		ft_putstr_fd("Error\nNot enough memory for map\n", STDERR_FILENO);
	if (error == 10)
		ft_putstr_fd("Error\nBad configurations\n", STDERR_FILENO);
	if (error == 11)
		ft_putstr_fd("Error\nInvalid space or start in map\n", STDERR_FILENO);
	if (error == 12 || error == 13)
		ft_putstr_fd("Error\nMap is not closed everywhere\n", STDERR_FILENO);
	print_error_2(error);
}

static void	kill_sound(void)
{
	t_vars	*vars;

	vars = get_data();
	if (vars->bonus == 1)
		system("killall afplay");
}

int	quit_game(int error)
{
	t_vars	*vars;

	vars = get_data();
	print_error_1(error);
	if (error > 23)
		mlx_destroy_window(vars->mlx, vars->win);
	if (error > 25 && vars->game_start == true)
		mlx_destroy_image(vars->mlx, vars->img->screen_view);
	if (error > 20 && vars->game_start == true)
		free(vars->game);
	if (error > 17 && vars->game_start == true)
	{
		destroy_images();
		free(vars->img);
	}
	if (error > 9 && vars->game_start == true)
		free_double_array((void **) vars->map);
	if (error >= 4 && vars->game_start == true)
		free_double_array((void **) vars->full_config);
	if (error == 30)
	{
		kill_sound();
		exit(0);
	}
	exit(error);
}
