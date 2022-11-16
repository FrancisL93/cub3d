/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:10:38 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 20:40:35 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Converts in long value a string containing digits
long	ft_atol(const char *str)
{
	long	nombre;
	int		neg;

	nombre = 0;
	neg = 1;
	if (!*str)
		return (0);
	while (*str && (ft_isspace(*str) == 1))
		str++;
	if (*str == '-')
	{
		neg = -neg;
		str++;
	}
	else if (*str == '+')
		str++;
	while (str && ft_isdigit(*str) == 1)
	{
		nombre = nombre * 10 + (*str - '0');
		str++;
	}
	return (nombre * neg);
}
