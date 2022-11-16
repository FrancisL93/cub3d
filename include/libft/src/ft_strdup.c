/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:23:26 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:34:39 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Allocates memory for the copy of s1, returns a pointer to the copy
char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s1, ft_strlen(s1) + 1);
	return (copy);
}
