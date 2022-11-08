/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:41:23 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:02:36 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	max;

	max = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		max = 0;
	else if (start < ft_strlen(s))
		max = ft_strlen(s) - start;
	if (max > len)
		max = len;
	ret = (char *) ft_calloc(max + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s + start, max + 1);
	return (ret);
}
