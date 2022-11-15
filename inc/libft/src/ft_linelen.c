/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:43:23 by chughes           #+#    #+#             */
/*   Updated: 2022/11/15 09:24:11 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// Returns len to first \n or \0
int	ft_linelen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		++i;
	return (i);
}
