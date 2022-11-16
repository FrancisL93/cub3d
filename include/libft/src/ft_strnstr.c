/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:38:30 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:35:26 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Locates the first occurence of string to_find in string str, while n bytes
	are searched. Returns pointer to the first character if found, NULL if not
	found, or str if to_find is empty */
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	rlen;

	i = 0;
	j = 0;
	rlen = ft_strlen(str);
	if (len < rlen)
		rlen = len;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	while (str && i < rlen)
	{
		while (str[i + j] == to_find[j] && ((i + j) < rlen))
		{
			if (to_find[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
