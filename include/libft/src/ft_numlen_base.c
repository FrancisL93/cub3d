/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 07:51:24 by malord            #+#    #+#             */
/*   Updated: 2022/10/03 07:51:43 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Returns the length of a number, including the '-' sign if necessary. 
Takes the base in parameter. */
int	ft_numlen_base(long nbr, long base)
{
	long	i;

	i = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}
