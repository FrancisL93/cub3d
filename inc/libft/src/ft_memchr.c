/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:54:58 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:03:56 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*pointer;
	size_t		i;

	i = 0;
	pointer = (char *) s;
	while (i < n)
	{
		if (pointer[i] == (char) c)
			return (pointer + i);
		i++;
	}
	return (0);
}
