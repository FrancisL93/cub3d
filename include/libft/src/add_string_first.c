/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_string_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:33:44 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 18:33:46 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Adds 'c' to start of 'str' and frees 'str'
char	*add_string_first(int c, char *str)
{
	char	*rtn;

	if (str == NULL)
		return (NULL);
	rtn = ft_calloc((ft_strlen(str) + 2), sizeof(char));
	rtn[0] = c;
	if (str[1])
		ft_strlcpy(&rtn[1], str, ft_strlen(str));
	free(str);
	return (rtn);
}
