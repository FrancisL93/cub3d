/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:53:02 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:34:46 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Does the same as strjoin but also frees s1
char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	tlen;
	char	*nstr;
	int		i;

	i = 0;
	tlen = ft_strlen_until(s1, 0) + ft_strlen_until((char *)s2, 0) + 1;
	nstr = ft_calloc((tlen), sizeof(char));
	if (!nstr)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			*nstr++ = s1[i++];
		free (s1);
	}
	if (s2)
		while (*s2)
			*nstr++ = *s2++;
	*nstr++ = '\0';
	return (nstr - tlen);
}
