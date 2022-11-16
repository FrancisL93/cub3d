/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:14:58 by malord            #+#    #+#             */
/*   Updated: 2022/10/20 19:15:02 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Prepends 's1' to 's2' and frees 's2'
char	*strjoin_free_last(char *s1, char *s2)
{
	char	*rtn;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s2[0] == '\0')
		return (s1);
	rtn = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	while (s1[++i])
		rtn[i] = s1[i];
	while (s2[++j])
		rtn[i + j] = s2[j];
	free(s2);
	return (rtn);
}
