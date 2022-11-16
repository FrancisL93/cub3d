/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:13:25 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:35:46 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Puts the lowercase letter in parameter in uppercase. Does nothing if the 
	parameter is not a lowercase  letter. */
int	ft_toupper(int n)
{
	if (n >= 97 && n <= 122)
		return (n - 32);
	return (n);
}
