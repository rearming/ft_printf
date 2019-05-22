/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:04:51 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src,
	int chr, size_t len)
{
	unsigned char	*src_ptr;
	unsigned char	*dst_ptr;
	unsigned char	symb;

	if (!dst)
		return (NULL);
	if (!src)
		return (dst);
	src_ptr = (unsigned char*)src;
	dst_ptr = (unsigned char*)dst;
	symb = (unsigned char)chr;
	while (len-- > 0)
	{
		*dst_ptr = *src_ptr;
		if (*dst_ptr == symb)
			return ((void*)(++dst_ptr));
		src_ptr++;
		dst_ptr++;
	}
	return (NULL);
}
