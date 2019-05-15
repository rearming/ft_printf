/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:26:24 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/10 18:28:38 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*res;

	if (!(res = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	res->content = ft_memalloc(content ? content_size : 1);
	if (!res->content)
	{
		free(res);
		return (NULL);
	}
	if (!content)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		res->content = ft_memcpy(res->content, content, content_size);
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}
