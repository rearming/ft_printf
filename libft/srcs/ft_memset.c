/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:49:21 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *src, int chr, size_t len)
{
	unsigned char	*dst;
	unsigned char	symb;

	if (!src)
		return (NULL);
	symb = (unsigned char)chr;
	dst = (unsigned char*)src;
	while (len--)
		*dst++ = symb;
	return (src);
}
