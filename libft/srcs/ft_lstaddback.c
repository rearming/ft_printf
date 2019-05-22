/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:56:05 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **list, void *content, size_t content_size)
{
	t_list *tmp;

	if (!list)
		return ;
	if (!(*list))
		*list = ft_lstnew(content, content_size);
	else if (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(content, content_size);
	}
}
