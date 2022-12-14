/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:03:33 by malord            #+#    #+#             */
/*   Updated: 2022/12/14 11:22:45 by malord           ###   ########.fr       */
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

t_ray	*get_ray(void)
{
	static t_ray	*ray = NULL;

	if (ray == NULL)
		ray = (t_ray *)ft_calloc(sizeof(t_ray), 1);
	return (ray);
}
