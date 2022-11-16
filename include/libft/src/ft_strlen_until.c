/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:51:53 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:35:05 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Returns the length of a string until a certain character. Length includes
that character.*/
size_t	ft_strlen_until(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	if (!c)
		return (i);
	if (s[i] != c)
		return (0);
	else
		return (i + 1);
}
