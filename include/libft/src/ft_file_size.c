/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:04:40 by flahoud           #+#    #+#             */
/*   Updated: 2022/12/11 16:18:41 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Read the file line by line, close the file fd and returns number of lines*/
int	ft_file_size(int fd)
{
	int		size;
	char	*temp;
	
	size = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		size++;
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
	return (size);
}