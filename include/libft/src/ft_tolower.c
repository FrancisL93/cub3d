/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:18:54 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:35:43 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Returns the capital letter in parameter in lowercase. Does nothing if not
	an uppercase letter */
int	ft_tolower(int n)
{
	if (n >= 65 && n <= 90)
		return (n + 32);
	return (n);
}
