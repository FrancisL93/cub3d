/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:39:31 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:33:05 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Returns the necessary length to write the number
static int	tab_length(int nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

// Converts an int to a string or array of chars
char	*ft_itoa(int n)
{
	char	*conv;
	long	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	conv = (char *)ft_calloc((tab_length(n)) + 1, sizeof(char));
	i = tab_length(n) - 1;
	if (!conv)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		conv[0] = '-';
	}
	while (i > 0)
	{
		conv[i] = (n % 10) + 48;
		i--;
		n /= 10;
	}
	if (conv[i] == 0)
			conv[i] = n % 10 + 48;
	return (conv);
}
