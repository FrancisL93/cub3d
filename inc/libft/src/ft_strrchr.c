/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:42:07 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:05:05 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*ptr;
	int			i;

	i = 0;
	ptr = (char *) s;
	while (*ptr != '\0')
	{
		i++;
		ptr++;
	}
	while (i-- >= 0)
	{
		if (*ptr == (char) c)
			return (ptr);
		ptr--;
	}
	return (0);
}
