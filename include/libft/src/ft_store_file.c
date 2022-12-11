/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:12:41 by flahoud           #+#    #+#             */
/*   Updated: 2022/12/11 15:33:06 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Receives a fd, read the file line by line and places it in storage, 
which is already allocated. Close the fd.*/
void	ft_store_file(char **storage, int fd)
{
	int	i;

	i = 0;
	storage[i] = get_next_line(fd);
	while (storage[i++])
	{
		storage[i] = get_next_line(fd);
	}
	storage[i] = NULL;
	close(fd);
	return ;
}