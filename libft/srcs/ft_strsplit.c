/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:35:06 by sselusa           #+#    #+#             */
/*   Updated: 2019/05/22 11:56:22 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			wordcount(char *s, char c, size_t *a, int *b)
{
	int		qt;

	*a = 0;
	*b = 0;
	qt = 0;
	if (*s != c)
		qt++;
	while (*++s)
		if (*s != c && *(s - 1) == c)
			qt++;
	return (qt);
}

static char			**ft_clear(char **s, int num)
{
	while (num)
		free(s[num--]);
	free(s);
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**res;
	size_t		start;
	size_t		end;
	int			words;
	int			qt;

	if (!s || !*s)
		return (ft_memalloc(0));
	words = wordcount((char*)s, c, &start, &qt);
	if (!(res = malloc(sizeof(char**) * (words + 1))))
		return (NULL);
	res[words] = 0;
	while (qt < words)
	{
		end = 0;
		while (s[start] == c)
			start++;
		while (s[start + end] != c && s[start + end])
			end++;
		res[qt++] = ft_strsub(s, start, end);
		if (!res[qt - 1])
			return (ft_clear(res, qt - 1));
		start += end;
	}
	return (res);
}
