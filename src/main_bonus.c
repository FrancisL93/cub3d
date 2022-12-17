/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal <mal@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:17 by malord            #+#    #+#             */
/*   Updated: 2022/12/17 12:36:42 by mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_vars	*get_data(void)
{
	static t_vars	*data = NULL;

	if (data == NULL)
		data = (t_vars *)ft_calloc(sizeof(t_vars), 1);
	return (data);
}

int	main(int argc, char **argv)
{	
	t_vars	*vars;

	vars = get_data();
	if (argc != 2)
		quit_game(1);
	vars->bonus = 1;
	validate_map(argv[1]);
	get_map();
	get_mapdata();
	format_map();
	start_screen();
	mlx_loop(vars->mlx);
}
