/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:28:34 by sleonard          #+#    #+#             */
/*   Updated: 2019/10/22 16:28:34 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback_p(t_list **begin, void *content, size_t content_size)
{
	t_list	*tmp;

	if (!begin)
		return ;
	if (!*begin)
	{
		*begin = ft_lstnew_p(content, content_size);
		return ;
	}
	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_lstnew_p(content, content_size);
}
