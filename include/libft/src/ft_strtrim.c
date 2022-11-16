/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:24:03 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:35:33 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Removes characters from set in the beginning or the end of s1. Returns
	the trimmed string. */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != NULL)
		s1++;
	end = ft_strlen(s1);
	while (end && ft_strchr(set, s1[end]) != NULL)
		end--;
	return (ft_substr(s1, 0, end + 1));
}
