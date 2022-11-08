/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:08:49 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:04:33 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (s1[len])
		len++;
	dup = ft_calloc(len + 1, sizeof(char));
	if (dup == NULL)
		return (0);
	while (s1[++i])
		dup[i] = s1[i];
	return (dup);
}
