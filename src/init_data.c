/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal <mal@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:13 by malord            #+#    #+#             */
/*   Updated: 2022/12/16 18:56:57 by mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_data(void)
{
	t_vars	*vars;

	vars = get_data();
	vars->game = malloc(sizeof(*vars->game));
	if (!vars->game)
		quit_game(20);
	vars->img->screen_view = NULL;
	vars->increment_angle = (double) FOCAL_LENGTH / WIN_WIDTH;
	vars->game->movement = 3;
	vars->game->posx = 0;
	vars->game->posy = 0;
	vars->game->diry = 0;
	set_up_start();
	set_colors();
}
