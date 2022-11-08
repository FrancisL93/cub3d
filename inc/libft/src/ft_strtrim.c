/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:04:08 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:05:08 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	check_set(char const *set, char a)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == a)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	while (s1[i])
		i++;
	while (check_set(set, s1[j]) && s1[j])
			j++;
	while (check_set(set, s1[i - 1]) && j < i)
		i--;
	trim = ft_calloc(i - j + 1, sizeof(char));
	if (trim == NULL)
		return (0);
	while (j < i)
		trim[k++] = s1[j++];
	return (trim);
}
