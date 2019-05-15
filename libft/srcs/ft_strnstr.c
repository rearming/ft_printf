/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:23:43 by sselusa           #+#    #+#             */
/*   Updated: 2019/04/30 18:25:44 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *haystack, const char *needle,
	size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!haystack || !needle)
		return (NULL);
	if (ft_strcmp(needle, "") == 0)
		return ((char*)(haystack));
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0' && (i + j) < len)
				return ((char*)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
