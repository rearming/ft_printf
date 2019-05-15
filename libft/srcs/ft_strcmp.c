/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:26:36 by sselusa           #+#    #+#             */
/*   Updated: 2019/04/30 18:28:40 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *str1, const char *str2)
{
	size_t	pos;

	if (!str1 || !str2)
		return (0);
	pos = 0;
	while ((unsigned char)str1[pos] != '\0' || (unsigned char)str2[pos] != '\0')
	{
		if ((unsigned char)str1[pos] != (unsigned char)str2[pos])
			return ((int)((unsigned char)str1[pos] - (unsigned char)str2[pos]));
		pos++;
	}
	return (0);
}
