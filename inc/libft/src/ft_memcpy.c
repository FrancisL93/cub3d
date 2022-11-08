/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:20:43 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:04:03 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*pointer;
	const char	*source;

	source = src;
	pointer = dst;
	if (dst == NULL && src == NULL)
		return (0);
	while (n-- > 0)
		*pointer++ = *source++;
	return (dst);
}
