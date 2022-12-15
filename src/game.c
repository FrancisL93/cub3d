/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal <mal@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:13 by malord            #+#    #+#             */
/*   Updated: 2022/12/14 20:42:11 by mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	door_handling(void)
{
	t_vars		*vars;
	//static int	tmpy = 0;
	//static int	tmpx = 0;;
	//static int	flag = 0;

	vars = get_data();
	if (vars->map[((int)vars->game->posy - 1)][(int) vars->game->posx] == 'D')
	{
		vars->map[(int) vars->game->posy - 1][(int) vars->game->posx] = '0';
		vars->tmpx = (int)vars->game->posx;
		vars->tmpy = (int)vars->game->posy - 1;
		vars->flag = 1;
	}
	else if (vars->map[((int)vars->game->posy + 1)][(int) vars->game->posx] == 'D')
	{
		vars->map[(int) vars->game->posy + 1][(int) vars->game->posx] = '0';
		vars->tmpx = (int)vars->game->posx;
		vars->tmpy = (int)vars->game->posy + 1;
		vars->flag = 2;
	}
	else if (vars->map[((int)vars->game->posy)][(int) vars->game->posx - 1] == 'D')
	{
		vars->map[(int) vars->game->posy][(int) vars->game->posx - 1] = '0';
		vars->tmpx = (int)vars->game->posx - 1;
		vars->tmpy = (int)vars->game->posy;
		vars->flag = 3;
	}
	else if (vars->map[((int)vars->game->posy)][(int) vars->game->posx + 1] == 'D')
	{
		vars->map[(int) vars->game->posy][(int) vars->game->posx + 1] = '0';
		vars->tmpx = (int)vars->game->posx + 1;
		vars->tmpy = (int)vars->game->posy;
		vars->flag = 4;
	}
	//if (vars->flag == 1 && (int)vars->game->posy - 1 != vars->tmpy)
	//	vars->map[vars->tmpy][vars->tmpx] = 'D';
	//else if (vars->flag == 2 && ((int)vars->game->posx != vars->tmpx
	//		|| (int)vars->game->posy + 1 != vars->tmpy))
	//			vars->map[vars->tmpy][vars->tmpx] = 'D';
	//else if (vars->flag == 3 && ((int)vars->game->posx - 1 != vars->tmpx
	//		|| (int)vars->game->posy != vars->tmpy))
	//			vars->map[vars->tmpy][vars->tmpx] = 'D';
	//else if (vars->flag == 4 && ((int)vars->game->posx + 1 != vars->tmpx
	//		|| (int)vars->game->posy != vars->tmpy))
	//		vars->map[vars->tmpy][vars->tmpx] = 'D';
}

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
			door_handling();
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
