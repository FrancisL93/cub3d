/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:40:07 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:04:26 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	str_len(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (i >= 0 && s[i] != c)
	{
		j++;
		i--;
	}
	return (j);
}

static char	*new_string(char const *s, char c, int i)
{
	char	*newstring;
	int		j;
	int		start;
	int		len;

	j = 0;
	len = str_len(s, c, i);
	start = i - len + 1;
	newstring = (char *) ft_calloc(len + 1, sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (j < len)
		newstring[j++] = s[start++];
	return (newstring);
}

static int	count_sep(char const *s, char c)
{
	int	i;
	int	sep;

	i = 0;
	sep = 0;
	if (!s[0])
		return (0);
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			sep++;
		i++;
	}
	return (sep);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		sep;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	sep = count_sep(s, c);
	split = (char **) ft_calloc(sep + 1, sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			split[j++] = new_string(s, c, i);
		i++;
	}
	return (split);
}
