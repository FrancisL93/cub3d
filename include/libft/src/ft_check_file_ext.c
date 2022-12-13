/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:12:41 by flahoud           #+#    #+#             */
/*   Updated: 2022/12/13 16:36:41 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Receives a file name, verify the extension, and returns the fd, or -1
in case of error.*/
int	ft_check_file_ext(char *file, char *ext)
{
	int	fd;
	int	len;

	len = ft_strlen(file);
	if (len < (int) ft_strlen(ext) || \
	ft_strncmp(&file[len - ft_strlen(ext)], ext, ft_strlen(ext)))
	{
		ft_putstr_fd("Error\nFile is not a .cub\n", STDERR_FILENO);
		return (-1);
	}
	fd = open(file, O_DIRECTORY);
	if (fd > -1)
	{
		ft_putstr_fd("Error\nFile is a directory\n", STDERR_FILENO);
		close(fd);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCouldn't read mapfile\n", STDERR_FILENO);
		return (-1);
	}
	return (fd);
}
