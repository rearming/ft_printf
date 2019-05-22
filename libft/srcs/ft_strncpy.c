/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:45:56 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;

	if (!dst || !src)
		return (NULL);
	if (len == 0)
		return (dst);
	if (!(dst = ft_memcpy(dst, src, len)))
		return (NULL);
	src_len = ft_strlen(src);
	if (src_len < len)
		ft_bzero((void*)(dst + src_len), len - src_len);
	return (dst);
}
