/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:48:51 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strcat(char *str1, const char *str2)
{
	size_t		len;
	char		*dst;

	if (!str1 || !str2)
		return (NULL);
	len = ft_strlen(str2);
	dst = str1 + ft_strlen(str1);
	dst = (char*)ft_memcpy(dst, str2, len);
	dst[len] = '\0';
	return (str1);
}
