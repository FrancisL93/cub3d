/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:25:28 by flahoud           #+#    #+#             */
/*   Updated: 2022/06/28 11:02:14 by flahoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newinput;

	newinput = malloc(sizeof(t_list));
	if (newinput == NULL)
		return (NULL);
	newinput->next = NULL;
	newinput->content = content;
	return (newinput);
}
