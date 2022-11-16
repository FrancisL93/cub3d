/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:09:33 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 14:49:03 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Trims 'set' char from either side of 's1', frees s1
char	*ft_strtrim_free(char *s1, char const *set)
{
	char			*rtn;
	unsigned int	start;
	size_t			len;

	start = 0;
	len = ft_strlen(s1) - 1;
	if (s1[0] == '\0')
		return (ft_strdup(s1));
	while (ft_strchr(set, (int)s1[start]) != NULL && start <= len)
		start++;
	while (ft_strchr(set, (int)s1[len]) != NULL && start <= len)
		len--;
	rtn = ft_substr(s1, start, (len - start + 1));
	free((void *)s1);
	return (rtn);
}
