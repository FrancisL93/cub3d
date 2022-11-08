/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:30:19 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:02:08 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;

	pointer = malloc(size * count);
	if (pointer == NULL)
		return (0);
	ft_bzero(pointer, count * size);
	return ((void *)pointer);
}
