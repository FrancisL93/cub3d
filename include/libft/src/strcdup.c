/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:44:50 by chughes           #+#    #+#             */
/*   Updated: 2022/10/20 14:49:43 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Returns dupe of basestring until first char in match or \0
char	*strcdup(char *basestr, char *matchchrs)
{
	char	*dupstr;
	int		i;

	i = 0;
	while (ft_strchr(matchchrs, basestr[i]) == NULL)
		++i;
	dupstr = (char *)ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(dupstr, basestr, i + 1);
	return (dupstr);
}
