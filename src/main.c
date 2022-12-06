/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:17 by malord            #+#    #+#             */
/*   Updated: 2022/12/06 15:06:49 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{	
	if (argc != 2)
	{
		ft_putstr_fd("Error\nExecute as ./cub3d map.cub\n", STDERR_FILENO);
		quit_game(1);
	}
	validate_map(argv[1]);
	get_map();
	get_mapdata();
	format_map();
	launch_game();
}
