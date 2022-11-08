/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:41:33 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:03:19 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_size(int n)
{
	int	size;

	size = 1;
	while (n < -9 || n > 9)
	{
		n /= 10;
		size++;
	}
	if (n < 0)
		size++;
	return (size);
}

char	*ft_itoa(int n)
{
	char		*number;
	int			size;
	long int	nb;

	nb = n;
	size = ft_size(nb);
	number = ft_calloc((size + 1), sizeof(char));
	if (number == NULL)
		return (0);
	if (nb == 0)
		number[0] = '0';
	if (nb < 0)
	{
		number[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		number[size - 1] = (nb % 10) + '0';
		nb /= 10;
		size--;
	}
	return (number);
}
