/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:53:03 by mal               #+#    #+#             */
/*   Updated: 2022/12/19 09:38:51 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int	launch_game_bonus(void)
{
	t_vars	*vars;

	vars = get_data();
	mlx_clear_window(vars->mlx, vars->win);
	system("afplay sounds/storemusic.mp3&");
	if (!vars->mlx)
		quit_game(16);
	if (!vars->win)
		quit_game(23);
	generate_img(0);
	launch_bonus();
	mlx_hook(vars->win, 17, 0, quit_game, (void *) 30);
	return (0);
}

void	launch_game(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->mlx = mlx_init();
	if (!vars->mlx)
		quit_game(16);
	build_imgs();
	init_data();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH,
			WIN_HEIGHT, GAME_NAME);
	if (!vars->win)
		quit_game(23);
	generate_img(0);
	launch_bonus();
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, quit_game, (void *) 30);
	mlx_loop(vars->mlx);
}
