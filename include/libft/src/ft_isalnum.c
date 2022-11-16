/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:58:11 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:32:40 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//Checks if the int in parameter is alphanumeric
int	ft_isalnum(int n)
{
	if ((n >= '0' && n <= '9') || (n >= 'A' && n <= 'Z')
		|| (n >= 'a' && n <= 'z'))
		return (1);
	return (0);
}
