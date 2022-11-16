/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:42:31 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:51:12 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Converts in int value a string containing digits
int	ft_atoi(const char *str)
{
	int	nombre;
	int	neg;

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
