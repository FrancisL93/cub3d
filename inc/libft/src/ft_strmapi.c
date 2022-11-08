/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:43:10 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:04:57 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;
	int				len;

	if (s == NULL || f == NULL)
		return (0);
	i = 0;
	len = (int) ft_strlen(s);
	newstr = ft_calloc(len + 1, sizeof(char));
	if (newstr == NULL)
		return (0);
	while (s[i])
	{
		newstr[i] = f(i, (char)s[i]);
		i++;
	}
	return (newstr);
}
