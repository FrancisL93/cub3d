/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:57:54 by chughes           #+#    #+#             */
/*   Updated: 2022/11/15 09:24:19 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// Converts a pointer to a hexidecimal str
char	*ft_ptoa(uintptr_t nbr)
{
	int		i;
	char	*hex_base;
	char	*temp;
	char	*rtn;

	hex_base = "0123456789abcdef";
	temp = ft_calloc(17, sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = -1;
	while (++i < 16)
		temp[i] = hex_base[((nbr >> (60 - (i * 4))) & 0xF)];
	i = 0;
	while (temp[i] == '0' && i < 15)
		i++;
	rtn = ft_substr(temp, i, (ft_strlen(temp) - i));
	free(temp);
	return (rtn);
}
