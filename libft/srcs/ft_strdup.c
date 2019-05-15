/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:39:48 by sselusa           #+#    #+#             */
/*   Updated: 2019/04/30 17:42:17 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *src)
{
	char		*dst;
	size_t		len;

	if (!src)
		return (NULL);
	len = ft_strlen(src) + 1;
	if (!(dst = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	dst = (char*)ft_memcpy(dst, src, len);
	return (dst);
}
