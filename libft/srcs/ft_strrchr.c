/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:07:00 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *src, int chr)
{
	size_t		pos;

	if (!src)
		return (NULL);
	pos = ft_strlen(src);
	while (pos > 0)
	{
		if (((unsigned char)src[pos]) == (unsigned char)chr)
			return ((char*)src + pos);
		pos--;
	}
	if (((unsigned char)src[pos]) == (unsigned char)chr)
		return ((char*)src + pos);
	return (NULL);
}
