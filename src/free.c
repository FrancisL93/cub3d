/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:02 by malord            #+#    #+#             */
/*   Updated: 2022/12/08 16:19:39 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//TODO S'assurer que toutes les erreurs sont gerees
//0-9 wrong execution & validate_map
//10-19 get_map errors
//20-29 format_map
//30-39 build_imgs & init_data
//40+ in game errors
//50+ in game clean exit
void	free_bonus(void)
{
	t_vars	*vars;

	vars = get_data();
	(void) vars;
}

int	closewin(void)
{
	quit_game(50);
	return (0);
}

int	quit_game(int exit_num)
{
	t_vars	*vars;

	vars = get_data();
	if (exit_num >= 40)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->bonus)
		free_bonus();
	if (exit_num > 34)
		free(vars->game);
	if (exit_num > 33)
		destroy_images(5 + vars->bonus * 2);
	if (exit_num > 31)
		free(vars->img);
	if (exit_num > 14)
		free_double_array((void **) vars->map);
	if (exit_num >= 10)
		free_double_array((void **) vars->full_config);
	free(vars);
	if (exit_num >= 50)
		exit(0);
	exit(exit_num);
}
