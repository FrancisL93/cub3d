/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:31:51 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:35:15 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Compares n bytes of strings s1 and s2, returns 0 if equal or not zero
	with the ASCII values of the first different character */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && n > i + 1)
	{
		if (!(s1[i] == s2[i]))
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - s2[i]);
}
