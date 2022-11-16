/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:22:32 by chughes           #+#    #+#             */
/*   Updated: 2022/05/17 15:22:35 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Converts an unsigned int to a string
char	*ft_utoa(unsigned int nbr)
{
	int		i;
	char	*temp;
	char	*rtn;

	temp = ft_calloc(11, sizeof(int));
	if (temp == NULL)
		return (NULL);
	i = 10;
	while (--i >= 0)
	{
		temp[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	i = 0;
	while (temp[i] == '0' && i < 9)
		i++;
	rtn = ft_substr(temp, i, (ft_strlen(temp) - i));
	free(temp);
	return (rtn);
}
