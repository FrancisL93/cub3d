/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_string_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:33:15 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 18:33:23 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Adds 'c' to end of 'str' and frees 'str'
char	*add_string_last(int c, char *str)
{
	char	*rtn;
	int		i;

	if (str == NULL)
		return (NULL);
	rtn = ft_calloc((ft_strlen(str) + 2), sizeof(char));
	i = -1;
	while (str[++i])
		rtn[i] = str[i];
	rtn[i] = c;
	free(str);
	return (rtn);
}
