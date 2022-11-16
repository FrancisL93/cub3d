/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:23:50 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:34:50 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Allocates memory for the combination of s1 and s2, then returns pointer
	to the new string containing the two*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	nstr = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!nstr)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strlcpy(nstr, s1, len);
	ft_strlcat(nstr, s2, len);
	return (nstr);
}
