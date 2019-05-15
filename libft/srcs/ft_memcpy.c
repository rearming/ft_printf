/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:57:48 by sselusa           #+#    #+#             */
/*   Updated: 2019/04/30 17:01:39 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			pos;
	unsigned char	*src_ptr;
	unsigned char	*dst_ptr;

	if (!dst || !src)
		return (NULL);
	src_ptr = (unsigned char*)src;
	dst_ptr = (unsigned char*)dst;
	pos = 0;
	while (pos < len)
	{
		dst_ptr[pos] = src_ptr[pos];
		pos++;
	}
	return (dst);
}
