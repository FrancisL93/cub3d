/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:01:16 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:32:52 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Checks if the character of value n in ASCII is printable
int	ft_isprint(int n)
{
	if (n >= 32 && n < 127)
		return (1);
	return (0);
}
