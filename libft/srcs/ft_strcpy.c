/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:43:15 by sselusa           #+#    #+#             */
/*   Updated: 2019/04/30 17:44:42 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strcpy(char *dst, const char *src)
{
	size_t		len;

	if (!dst)
		return (NULL);
	if (!src)
		return (dst);
	len = ft_strlen(src) + 1;
	if (!(dst = (char*)ft_memcpy(dst, src, len)))
		return (NULL);
	return (dst);
}
