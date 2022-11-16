/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:00:34 by chughes           #+#    #+#             */
/*   Updated: 2022/10/20 14:49:16 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Appends 's2' to 's1' and frees both
char	*join_free_both(char *s1, char *s2)
{
	char	*rtn;
	int		i;
	int		j;

	if (s1 == NULL)
		return (s2);
	else if (s2 == NULL)
		return (s1);
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = -1;
	j = -1;
	rtn = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (rtn == NULL)
		return (NULL);
	while (s1[++i])
		rtn[i] = s1[i];
	while (s2[++j])
		rtn[i + j] = s2[j];
	xfree(s1);
	xfree(s2);
	return (rtn);
}
