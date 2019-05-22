/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:31:38 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_space(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char				*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;
	char		*res;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] && is_space(s[start]))
		start++;
	while (s[end] && is_space(s[end]))
		end--;
	end++;
	if (start >= end)
		return (ft_strnew(0));
	if (!(res = ft_strsub(s, start, end - start)))
		return (NULL);
	return (res);
}
