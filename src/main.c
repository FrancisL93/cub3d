/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:17 by malord            #+#    #+#             */
/*   Updated: 2022/12/05 12:51:27 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//LEAKS Faire une fonction pour quand sort avec la croix (x rouge)
//TODO raycasting int aux limites sont en dehors window a cause de floor? 

//void	print_map_data(char **mapdata)
//{
//	int	i;
//
//	i = 0;
//	while (i < 6)
//	{
//		printf("mapdata[i] = %s", mapdata[i]);
//		i++;
//	}
//	printf("\n");
//}
//
//void	print_map(char **map)
//{
//	int	i;
//
//	i = 0;
//	while (map[i])
//	{
//		printf("map[i] = %s", map[i]);
//		i++;
//	}
//	printf("\n");
//}

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
