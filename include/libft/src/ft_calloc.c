/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:23:06 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:32:32 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Allocate the necessary memory with malloc, then fills it with \0 
	characters for security*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
