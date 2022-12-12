/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:12:41 by flahoud           #+#    #+#             */
/*   Updated: 2022/12/12 12:22:03 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Receives a fd, read the file line by line and places it in storage, 
which is already allocated. Close the fd.*/
char	**ft_store_file(int fd, int size)
{
	int		i;
	char	**storage;

	i = 0;
	storage = ft_calloc(sizeof(char *), size + 1);
	storage[i] = get_next_line(fd);
	while (storage[i] != NULL)
	{
		i++;
		storage[i] = get_next_line(fd);
	}
	close(fd);
	return (storage);
}
