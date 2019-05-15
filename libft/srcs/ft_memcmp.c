/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:29:24 by sselusa           #+#    #+#             */
/*   Updated: 2019/04/30 17:36:31 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *mem1, const void *mem2, size_t len)
{
	size_t			pos;
	unsigned char	*mem1_ptr;
	unsigned char	*mem2_ptr;

	if (!mem1 || !mem2)
		return (0);
	mem1_ptr = (unsigned char*)mem1;
	mem2_ptr = (unsigned char*)mem2;
	pos = -1;
	while (++pos < len)
		if (mem1_ptr[pos] != mem2_ptr[pos])
			return (mem1_ptr[pos] - mem2_ptr[pos]);
	return (0);
}
