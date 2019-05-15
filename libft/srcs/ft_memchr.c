/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:25:48 by sselusa           #+#    #+#             */
/*   Updated: 2019/04/30 17:27:25 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *src, int chr, size_t len)
{
	unsigned char	*src_ptr;
	unsigned char	symb;

	if (!src)
		return (NULL);
	src_ptr = (unsigned char*)src;
	symb = (unsigned char)chr;
	while (len-- > 0)
		if (*src_ptr++ == symb)
			return ((void*)--src_ptr);
	return (NULL);
}
