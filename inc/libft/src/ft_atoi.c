/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:16:09 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:01:42 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_atoi(const char *str)
{
	long	nbr;
	long	i;
	int		sign;

	sign = 1;
	i = 0;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		if ((nbr * 10 + (str[i] - '0')) > 2147483647
			&& (nbr * 10 + (str[i] - '0')) < -2147483648)
			return (nbr * sign);
		nbr = nbr * 10 + (str[i++] - '0');
	}
	return (nbr * sign);
}
