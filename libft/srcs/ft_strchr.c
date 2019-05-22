/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:01:00 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *src, int chr)
{
	size_t		pos;

	if (!src)
		return (NULL);
	pos = 0;
	while (src[pos] != '\0')
	{
		if (((unsigned char)src[pos]) == (unsigned char)chr)
			return ((char*)src + pos);
		pos++;
	}
	if (((unsigned char)src[pos]) == (unsigned char)chr)
		return ((char*)src + pos);
	return (NULL);
}
