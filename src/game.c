/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:13 by malord            #+#    #+#             */
/*   Updated: 2022/12/15 10:22:44 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_hook(int keycode, t_vars *vars)
{
	int			increment;

	increment = 5;
	if (keycode == ESC)
		quit_game(50);
	else
	{
		set_movement(keycode);
		if (keycode == SPACE)
			door_handling(vars);
		if (keycode == LEFTA)
			vars->game->dirx -= increment;
		else if (keycode == RIGHTA)
			vars->game->dirx += increment;
		if (vars->game->dirx > 360)
			vars->game->dirx = increment;
		else if (vars->game->dirx < 0)
			vars->game->dirx = 360 - increment;
		generate_img(1);
	}
	return (0);
}

void	init_data(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->game = malloc(sizeof(*vars->game));
	if (!vars->game)
		quit_game(34);
	vars->img->screen_view = NULL;
	vars->increment_angle = (double) FOCAL_LENGTH / WIN_WIDTH;
	vars->game->movement = 3;
	vars->game->posx = 0;
	vars->game->posy = 0;
	vars->game->diry = 0;
	set_up_start();
	set_colors();
}

static void	launch_bonus(void)
{
	t_vars	*vars;

	vars = get_data();
	if (vars->bonus == 1)
	{
		mlx_mouse_hide();
		mlx_hook(vars->win, 6, 0, mouse_move, vars);
	}
	return ;
}

void	launch_game(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_putstr_fd("Error\nMlx init failure\n", STDERR_FILENO);
		quit_game(30);
	}
	build_imgs();
	init_data();
	if (vars->mlx != NULL)
		vars->win = mlx_new_window(vars->mlx, WIN_WIDTH,
				WIN_HEIGHT, GAME_NAME);
	if (!vars->win)
	{
		ft_putstr_fd("Error\nMlx window creation failure\n", STDERR_FILENO);
		quit_game(40);
	}
	generate_img(0);
	launch_bonus();
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, closewin, vars);
	mlx_loop(vars->mlx);
}
