/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:26:00 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:05:33 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

void	clean(char *buf)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			break ;
		}
		buf[i] = '\0';
	}
	while (buf[++i])
	{
		buf[++j] = buf[i];
		buf[i] = '\0';
	}
}

int	check_line(char *buf, int x)
{
	int	i;

	i = 0;
	if (x == 0)
	{
		while (buf[i])
			if (buf[i++] == '\n')
				return (0);
		return (i);
	}
	else
	{
		i = -1;
		if (!buf)
			return (0);
		while (buf[++i])
			if (buf[i] == '\n')
				return (i + 1);
		return (i);
	}
	return (i);
}

char	*fix_build(char *line, char *buf, int i)
{
	char	*nl;
	int		j;
	int		k;

	k = 0;
	j = 0;
	nl = line;
	line = malloc((i) * sizeof(char) + 1);
	if (line == NULL)
		return (NULL);
	if (nl)
		while (nl[k])
			line[j++] = nl[k++];
	k = 0;
	while (buf[k])
	{
		line[j++] = buf[k++];
		if (buf[k - 1] == '\n')
			break ;
	}
	free(nl);
	line[j] = '\0';
	return (line);
}

char	*build_line(char *line, char *buf, int size)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (line)
		while (line[i])
			i++;
	while (buf[j++])
		if (buf[j - 1] == '\n')
			break ;
	if (size)
		tmp = fix_build(line, buf, j + i);
	else
		tmp = fix_build(NULL, buf, j + i);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*line;
	int			eof;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	eof = 1;
	line = NULL;
	while (eof)
	{
		if (!buf[0])
			eof = read(fd, buf, BUFFER_SIZE);
		if (eof >= 1)
			line = build_line(line, buf, check_line(line, 1));
		if (!check_line(buf, 0))
			eof = 0;
		clean(buf);
	}
	return (line);
}
