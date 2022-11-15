/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:57:54 by chughes           #+#    #+#             */
/*   Updated: 2022/11/15 09:23:17 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// Converts 'nbr' into str in hexidecimal format 
char	*ft_itox(int nbr)
{
	int		i;
	char	*hex_base;
	char	*temp;
	char	*rtn;

	hex_base = "0123456789abcdef";
	temp = ft_calloc(9, sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = -1;
	while (++i < 8)
		temp[i] = hex_base[((nbr >> (28 - (i * 4))) & 0xF)];
	i = 0;
	while (temp[i] == '0' && i < 7)
		i++;
	rtn = ft_substr(temp, i, (ft_strlen(temp) - i));
	free(temp);
	return (rtn);
}
