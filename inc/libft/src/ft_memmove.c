/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:46:07 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:04:06 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pointer;
	const char	*source;
	const char	*lastsource;
	char		*lastpointer;

	source = src;
	pointer = dst;
	if (dst == NULL && src == NULL)
		return (0);
	if (pointer < source)
	{
		while (len--)
			*pointer++ = *source++;
	}
	else
	{
		lastsource = source + (len - 1);
		lastpointer = pointer + (len - 1);
		while (len--)
			*lastpointer-- = *lastsource--;
	}
	return (dst);
}
