/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:50:51 by chughes           #+#    #+#             */
/*   Updated: 2022/10/05 12:57:40 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Returns duplicate of str up to n number of chars
char	*ft_strndup(const char *str, int n)
{
	char	*outstr;
	int		i;

	if (str == NULL || ft_strlen(str) == 0)
		return (NULL);
	if ((int)ft_strlen(str) < n)
		n = (int)ft_strlen(str);
	outstr = ft_calloc((n + 1), sizeof(char));
	i = 0;
	while (outstr != NULL && i < n)
	{
		outstr[i] = str[i];
		i++;
	}
	return (outstr);
}
