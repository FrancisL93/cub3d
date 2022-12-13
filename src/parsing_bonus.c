/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:21:52 by malord            #+#    #+#             */
/*   Updated: 2022/12/13 16:27:35 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	is_valid_char_bonus(char c, char *str)
{
	t_vars	*vars;

	vars = get_data();
	if (!ft_strchr("0 1NSEWD", c))
	{
		free(str);
		ft_putstr_fd("Error\nInvalid character in map\n", STDERR_FILENO);
		quit_game(11);
	}
	if (ft_strchr("NSEW", c))
	{
		if (vars->one_start == 0)
			vars->one_start = 1;
		else
		{
			free(str);
			ft_putstr_fd("Error\nMore than one start position\n", STDERR_FILENO);
			quit_game(12);
		}
	}
}
