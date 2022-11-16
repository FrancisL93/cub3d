/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:34:25 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:47:27 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Reallocate memory to add one element to an array of int
int	*int_realloc(int *old_array, int old_size, int size)
{
	int		*new_array;
	int		i;

	new_array = ft_calloc(size, sizeof(int));
	i = 0;
	while (i < old_size)
	{
		new_array[i] = old_array[i];
		i++;
	}
	old_array = xfree(old_array);
	return (new_array);
}
