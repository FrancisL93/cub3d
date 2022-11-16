/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:23:40 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:35:36 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Allocates memory to return the string starting at start, size of len bytes
	Returns a pointer to the new string. */
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*nstr;
	unsigned int	i;

	if (!str)
		return (NULL);
	i = 0;
	if (len > ft_strlen(str))
	len = ft_strlen(str);
	nstr = (char *)ft_calloc((len + 1), sizeof(char));
	if (!nstr)
		return (NULL);
	if (start > ft_strlen(str))
		return (nstr);
	while (str && len > 0 && i <= (len - 1))
	{
		nstr[i] = str[start];
		i++;
		start++;
	}
	return (nstr);
}
